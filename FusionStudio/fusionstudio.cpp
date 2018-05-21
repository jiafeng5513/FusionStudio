#include "fusionstudio.h"
#include "QDebug"
#include <QFileDialog>
#include <QSplitter>
#include <QDirModel>
#include <QMessageBox>
#include <QInputDialog>
#include <QClipboard>
#include <QFileInfo>
#include <QProcess>

//=====================================================
//=====================类方法==========================
//=====================================================
//构造和初始化
FusionStudio::FusionStudio(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->configureUI();

	//显示起始页面
	HomePage *_homePage = new HomePage();
	ui.mdiArea->addSubWindow(_homePage);
	_homePage->showMaximized();

	m_project = new Project();//当前工程初始化
	m_PreferencesManager = new Preferences();//首选项管理器
	
							  //控制台标准输出重定向
	p2 = new QProcess();
	p2->setProcessChannelMode(QProcess::MergedChannels);
	connect(p2, SIGNAL(readyRead()), this, SLOT(start_read_output()));
	connect(m_project, SIGNAL(ValueChanged()), this, SLOT(Refresh()));
}

//自定义UI设置
void FusionStudio::configureUI()
{
	QAction* action_New_Working_Dir = new QAction(QStringLiteral("&新建工作目录"), ui.treeView);
	connect(action_New_Working_Dir, SIGNAL(triggered()), this, SLOT(FolderCreater()));

	QAction* action_Open_Working_Dir = new QAction(QStringLiteral("&打开工作目录"), ui.treeView);
	connect(action_Open_Working_Dir, SIGNAL(triggered()), this, SLOT(FolderUnfolder()));

	QAction* action_New_File = new QAction(QStringLiteral("&新建文件"), this);
	connect(action_New_File, SIGNAL(triggered()), this, SLOT(newFile()));

	QAction* action_New_Folder = new QAction(QStringLiteral("&新建文件夹"), this);
	connect(action_New_Folder, SIGNAL(triggered()), this, SLOT(newFolder()));

	QAction* action_Open_In_Explorer = new QAction(QStringLiteral("&在资源管理器中打开"), this);
	connect(action_Open_In_Explorer, SIGNAL(triggered()), this, SLOT(openInSystemResourceManager()));

	QAction* action_Open_Father_Dir = new QAction(QStringLiteral("&打开所在目录"), ui.treeView);
	connect(action_Open_Father_Dir, SIGNAL(triggered()), this, SLOT(openInSystemResourceManager()));

	QAction* action_Get_Abs_Path = new QAction(QStringLiteral("&复制绝对路径"), this);
	connect(action_Get_Abs_Path, SIGNAL(triggered()), this, SLOT(getAbsolutePath()));

	QAction* action_Delete_File = new QAction(QStringLiteral("&删除文件"), this);
	connect(action_Delete_File, SIGNAL(triggered()), this, SLOT(deleteFileOrPath()));

	QAction* action_Delete_Path = new QAction(QStringLiteral("&删除文件夹"), this);
	connect(action_Delete_Path, SIGNAL(triggered()), this, SLOT(deleteFileOrPath()));

	//================右键菜单的定义======================
	//文件树为空时发生的右键事件菜单
	TreeViewMenu_Empty = new QMenu(ui.treeView);
	TreeViewMenu_Empty->addAction(action_New_Working_Dir);
	TreeViewMenu_Empty->addAction(action_Open_Working_Dir);
	//发生在文件节点上的右键事件菜单
	TreeViewMenu_File = new QMenu(ui.treeView);
	TreeViewMenu_File->addAction(action_Open_Father_Dir);
	TreeViewMenu_File->addAction(action_Get_Abs_Path);
	TreeViewMenu_File->addSeparator();
	TreeViewMenu_File->addAction(action_Delete_File);
	//发生在文件夹节点生的右键事件菜单
	TreeViewMenu_Path = new QMenu(ui.treeView);
	//TreeViewMenu_Path->addAction(action_New_File);
	TreeViewMenu_Path->addAction(action_New_Folder);
	TreeViewMenu_Path->addSeparator();
	TreeViewMenu_Path->addAction(action_Open_In_Explorer);
	TreeViewMenu_Path->addAction(action_Get_Abs_Path);
	TreeViewMenu_Path->addSeparator();
	TreeViewMenu_Path->addAction(action_Delete_Path);
	//================其他ui设置===========================
	ui.action_view_Console->setChecked(true);
	ui.action_view_Explorer->setChecked(true);
}

//=====================================================
//=====================槽函数==========================
//=====================================================
//文件树的右键菜单响应
void FusionStudio::on_treeView_customContextMenuRequested(QPoint pos)
{
	//qDebug() << "右键触发"<<pos.x() << "," << pos.y();
	//通过测试发现,连续发生的两次调用的触发点是一样的
	//暂时通过检测这次触发是否和上一次发生在同一个位置来规避该问题

	if (PrePosition != pos) {//这次触发是正常触发
		PrePosition = pos;
		if (ui.treeView->model() == NULL) {
			//此时文件树是空的
			TreeViewMenu_Empty->exec(QCursor::pos());//显示右键菜单
		}
		else//文件树非空的时候才能启动这个
		{
			QModelIndex indexSelect = ui.treeView->indexAt(pos);//当前节点索引
			QString AbsPath = indexSelect.data().toString();       //当前节点数据
			if (AbsPath != "")//如果当前右击发生在树形节点上
			{
				//迭代出当前节点的绝对路径
				QString temp;
				QModelIndex indexParent;
				do {
					indexParent = indexSelect.parent();//当前节点的父节点
					temp = indexParent.data().toString();
					if (temp == "")
					{
						break;
					}
					AbsPath = temp.append("\\" + AbsPath);
					indexSelect = indexParent;
				} while (true);
				CurrentTreeViewSelectedPath = AbsPath;//把这个路径通过全局传出去
				//分辨一下点到了什么
				QFileInfo _fio(AbsPath);
				if (_fio.isFile()==true)//文件
				{
					TreeViewMenu_File->exec(QCursor::pos());
				}
				if (_fio.isDir()==true)//文件夹
				{
					TreeViewMenu_Path->exec(QCursor::pos());
				}
			}
		}
	}
	else
	{
		//这次触发是非正常触发
		PrePosition.setX(-1);
		PrePosition.setY(-1);
	}
}

//控制台标准输出重定向
void FusionStudio::start_read_output()
{
	QString result = QString::fromLocal8Bit(p2->readAll());
	ui.plainTextEdit->appendPlainText(result);
	//ui.plainTextEdit->appendPlainText("Ok,i am working...");
}
//刷新文件树
void FusionStudio::Refresh()
{
	//QMessageBox::warning(this, QStringLiteral("安娜学姐的问候"), QStringLiteral("收到了值更改消息"));
	if (m_project->getWorkingDir().isEmpty()) {
		//目录是空的,可能是误操作,也可能是执行了关闭工作目录,统一处理为清空文件树
		ui.treeView->setModel(NULL);
	}
	else
	{
		QDirModel *model = new QDirModel();
		ui.treeView->setModel(model);
		ui.treeView->setColumnHidden(1, true);
		ui.treeView->setColumnHidden(2, true);
		ui.treeView->setColumnHidden(3, true);
		ui.treeView->setRootIndex(model->index(m_project->getWorkingDir()));
		ui.treeView->expandAll();//全部展开
	}
}
//==================文件树右键菜单=====================
//文件树右键菜单->新建文件
void FusionStudio::newFile()
{

}

//文件树右键菜单->新建文件夹
void FusionStudio::newFolder()
{
	//弹出对话框询问新文件夹的名字
	bool isOK;
	QString FolderName = QInputDialog::getText(NULL, QStringLiteral("新建文件夹"),
		QStringLiteral("请为即将新建的文件夹命名:"),
		QLineEdit::Normal, QStringLiteral("新建文件夹"), &isOK);
	if (isOK)//点击确定
	{
		QString _temppath = CurrentTreeViewSelectedPath;
		_temppath.append("/");
		_temppath.append(FolderName);

		QDir *_tempdir = new QDir;
		if (_tempdir->exists(_temppath))
		{
			QMessageBox::warning(this, QStringLiteral("新建文件夹"), QStringLiteral("文件夹已经存在！"));
		}
		else
		{
			if (_tempdir->mkdir(_temppath))
			{
				QMessageBox::warning(this, QStringLiteral("创建文件夹"), QStringLiteral("文件夹创建成功！"));
				Refresh();
			}
			else
			{
				QMessageBox::warning(this, QStringLiteral("新建文件夹"), QStringLiteral("未知错误导致的创建失败!"));
			}
		}
	}
}

//文件树右键菜单->获取绝对路径到剪贴板
void FusionStudio::getAbsolutePath()
{
	//QMessageBox::warning(this, QStringLiteral("节点数据"), CurrentTreeViewSelectedPath);
	//使用 QApplication::clipboard() 函数获得系统剪贴板对象。这个函数的返回值是 QClipboard 指针。  
	QClipboard *board = QApplication::clipboard();
	//通过 setText()，setImage() 或者 setPixmap() 函数可以将数据放置到剪贴板内，也就是通常所说的剪贴或者复制的操作；  
	board->setText(CurrentTreeViewSelectedPath);
	//使用text()，image() 或者 pixmap() 函数则可以从剪贴板获得数据，也就是粘贴。  
	//QString str = board->text(); 
}

//文件树右键菜单->在在系统文件资源管理器中打开路径
void FusionStudio::openInSystemResourceManager()
{
	QFileInfo _fio(CurrentTreeViewSelectedPath);
	if (_fio.isFile() == true)//文件
	{//文件打开父目录
		QString cmd = "explorer.exe ";
		cmd.append(_fio.canonicalPath());
		cmd = cmd.replace(QRegExp("\\/"), "\\");//正则替换将"撇"换称"捺"
		QProcess::execute(cmd);
	}
	if (_fio.isDir() == true)//文件夹
	{//文件夹直接打开
		QString cmd = "explorer ";
		cmd.append(CurrentTreeViewSelectedPath);
		QProcess::execute(cmd);
	}
}
//递归删除文件夹及其中全部文件
bool FusionStudio::DelDir(const QString & path)
{
	if (path.isEmpty()) {
		return false;
	}
	QDir dir(path);
	if (!dir.exists()) {
		return true;
	}
	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤  
	QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息  
	foreach(QFileInfo file, fileList) { //遍历文件信息  
		if (file.isFile()) { // 是文件，删除  
			file.dir().remove(file.fileName());
		}
		else { // 递归删除  
			DelDir(file.absoluteFilePath());
		}
	}
	return dir.rmpath(dir.absolutePath()); // 删除文件夹  
}
//文件树右键菜单->删除路径或文件
void FusionStudio::deleteFileOrPath()
{
	//判断是路径还是文件,以弹出不同的删除确认框
	QFileInfo _fio(CurrentTreeViewSelectedPath);
	if (_fio.isFile() == true)//文件
	{//文件直接删除
		QMessageBox::StandardButton rb = QMessageBox::question(NULL, QStringLiteral("确认删除?"), QStringLiteral("所选文件将会从磁盘上消失!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		if (rb == QMessageBox::Yes) 
		{
			_fio.dir().remove(_fio.fileName());
			Refresh();
		}
	}
	if (_fio.isDir() == true)//文件夹
	{//文件夹递归删除全部内容
		QMessageBox::StandardButton rb = QMessageBox::question(NULL, QStringLiteral("确认删除?"), QStringLiteral("删除文件夹将会删除其中所有的文件!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		if (rb == QMessageBox::Yes) 
		{//已经确认删除
			DelDir(CurrentTreeViewSelectedPath);
			Refresh();
		}
	}
}

//================菜单->文件===========================

//文件->创建目录
void FusionStudio::FolderCreater()
{
	//1.选择父目录
	QString ParentDir = QFileDialog::getExistingDirectory(this,
		QStringLiteral("选择新文件夹的父目录"),
		QDir::currentPath());
	if (ParentDir.isEmpty() == false)//父目录非空
	{
		//2.询问目录名
		bool isOK;
		QString FolderName = QInputDialog::getText(NULL, QStringLiteral("新建工作目录"),
			QStringLiteral("请为即将新建的工作目录命名:"),
			QLineEdit::Normal, "NewFolder", &isOK);
		if (isOK) {//点击了确认
			if (FolderName.isEmpty() == false)//目录名非空
			{
				//3.创建
				QString CompleteDir;
				CompleteDir.append(ParentDir);
				CompleteDir.append("\\");
				CompleteDir.append(FolderName);
				QDir *DirManager = new QDir;
				if (DirManager->exists(CompleteDir) == true)//已经存在同名目录
				{
					QMessageBox::warning(this, QStringLiteral("创建失败"), QStringLiteral("文件夹已经存在！"));
				}
				else
				{
					if (DirManager->mkdir(CompleteDir) == true)//创建成功
					{
						QMessageBox::warning(this, QStringLiteral("创建文件夹"), QStringLiteral("文件夹创建成功！"));
						//4.设置工作目录
						//setWorkingDir(CompleteDir);
						m_project->setWorkingDir(CompleteDir);
					}
					else
					{
						QMessageBox::warning(this, QStringLiteral("创建失败"), QStringLiteral("未知错误!"));
					}
				}
			}
		}
	}
	else
	{
		//父目录为空
		QMessageBox::warning(this, QStringLiteral("创建失败"), QStringLiteral("父目录为空！"));
	}


}

//文件->开启目录
void FusionStudio::FolderUnfolder()
{
	/*
	打开一个已经存在的目录,作为当前的工作目录
	*/
	//1.打开文件管理窗口
	QString ExistedDir = QFileDialog::getExistingDirectory(this,
		QStringLiteral("选择目录作为工作目录"),
		QDir::currentPath());
	if (ExistedDir.isEmpty() == false)//工作目录非空
	{
		//将这个目录设置为当前工作目录,触发值更改事件
		//setWorkingDir(ExistedDir);
		m_project->setWorkingDir(ExistedDir);
	}

}

//文件->关闭目录
void FusionStudio::FolderCloser()
{
	//setWorkingDir(NULL);//工作路径设为空
	m_project->setWorkingDir(NULL);
}

//================菜单->视图===========================

//变更资源浏览器视图的可见性
void FusionStudio::changeVisible_Explorer()
{
	if (ui.dockWidget_Explorer->isHidden() == true) {
		ui.dockWidget_Explorer->show();//隐藏实用工具
		ui.action_view_Explorer->setChecked(true);
	}
	else
	{
		ui.dockWidget_Explorer->hide();//隐藏实用工具
		ui.action_view_Explorer->setChecked(false);
	}
}

//变更控制台视图的可见性
void FusionStudio::changeVisible_Console()
{
	if (ui.dockWidget_Console->isHidden() == true) {
		ui.dockWidget_Console->show();//隐藏实用工具
		ui.action_view_Console->setChecked(true);
	}
	else
	{
		ui.dockWidget_Console->hide();//隐藏实用工具
		ui.action_view_Console->setChecked(false);
	}
}

//================菜单->项目============================

//项目->扫描工作目录
void FusionStudio::WorkingDirScanner()
{
	Refresh();
}

//================菜单->生成============================

//新建编辑器
void FusionStudio::ShowEditor()
{
	NetEditor *child = new NetEditor();
	ui.mdiArea->addSubWindow(child);
	child->show();
	//暂时用一下
}

//训练
void FusionStudio::Train()
{
	TrainingSetter *w = new TrainingSetter(m_PreferencesManager->getBinPath(), p2);
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//分类
void FusionStudio::DoClassification()
{
	Classification*w = new Classification(m_PreferencesManager->getBinPath(),p2);
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//生成->特征导出
void FusionStudio::DoFeaturesExp()
{
	FeatureExp*w = new FeatureExp(m_PreferencesManager->getBinPath(), p2);
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//================菜单->工具============================

//工具->启动Mnist数据转换工具
void FusionStudio::MnistConverter()
{
	ConvertMnist *w = new ConvertMnist();
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//工具->启动Cifar转换工具
void FusionStudio::CifarConverter()
{
	ConvertCifar *w = new ConvertCifar();
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//工具->启动图片转换工具
void FusionStudio::ImageConverter()
{
	ConvertImage *w = new ConvertImage();
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//工具->启动数据集浏览工具
void FusionStudio::DatabaseBrowser()
{
	BrowseDatabase *w = new BrowseDatabase();
	ui.mdiArea->addSubWindow(w);
	w->show();
}

//================菜单->设置============================

//设置->启动首选项管理器
void FusionStudio::PreferencesSetter()
{
	m_PreferencesManager->awakenPreferencesManager();//唤醒
	//ui.mdiArea->addSubWindow(m_PreferencesManager);//作为模态对话框使用
	m_PreferencesManager->show();
}

//================菜单->帮助============================

//帮助->显示开始页面
void FusionStudio::ShowHome()
{
	HomePage *_homePage = new HomePage();
	ui.mdiArea->addSubWindow(_homePage);
	_homePage->showMaximized();
}
//帮助->显示关于页面
void FusionStudio::ShowAbout()
{
	About *_aboutPage = new About();
	//ui.mdiArea->addSubWindow(_aboutPage);
	_aboutPage->show();
}

