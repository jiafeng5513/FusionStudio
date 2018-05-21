#include "trainingsetter.h"
//#include "caffe/proto/caffe.pb.h"//无法引用这个文件,需要借助中间层
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

/*==========================================================================*/
/*                            构造和析构函数                                */
/*==========================================================================*/
TrainingSetter::TrainingSetter(QString coredir, QProcess *addprocess, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	CoreDir = coredir;
	_AdditionalProcess = addprocess;
}

TrainingSetter::~TrainingSetter()
{
}
/*==========================================================================*/
/*                                 槽函数                                   */
/*==========================================================================*/
//选择求解器文件
void TrainingSetter::BrowseSolver()
{
	/*
	参数1：父窗口
	参数2：对话框的标题
	参数3：默认的打开的位置，如”我的文档“等
	参数4：文件的过滤器，注意文件类型之间用  ；；  分开
	*/
	ui.lineEdit_solverFilePath->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("求解器"),
			" ",
			QStringLiteral("求解器定义文件(*.prototxt);;所有类型(*.*)")));
}
//选择网络快照的输出位置
void TrainingSetter::BrowseSnapPath()
{
	ui.lineEdit_snapshot_prefix->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择快照的输出目录"), QDir::currentPath()));
}
//选择网络结构定义文件
void TrainingSetter::BrowseNet()
{
	ui.lineEdit_net->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("网络结构定义文件"),
			" ",
			QStringLiteral("网络结构定义文件(*.prototxt);;所有类型(*.*)")));
}
//将界面的相关参数保存在求解器文件中
void TrainingSetter::SaveSolver()
{
	QFile file(ui.lineEdit_solverFilePath->text());
	if (file.open(QFile::WriteOnly | QFile::Text)) {
		QTextStream out(&file);
		QString _target, target;
		if (ui.lineEdit_net->text()!="")
		{
			out << "net: " << "\"" << ui.lineEdit_net->text() << "\""<<"\n";
		}
		if (ui.lineEdit_test_iter->text()!="")
		{
			out << "test_iter: " << ui.lineEdit_test_iter->text() << "\n";
		}
		if (ui.lineEdit_test_interval->text() != "") {
			out << "test_interval: " << ui.lineEdit_test_interval->text() << "\n";
		}
		if (ui.lineEdit_base_lr->text() != "") {
			out << "base_lr: " << ui.lineEdit_base_lr->text() << "\n";
		}
		if (ui.lineEdit_momentum->text() != "") {
			out << "momentum: " << ui.lineEdit_momentum->text() << "\n";
		}
		if (ui.lineEdit_weight_decay->text() != "") {
			out << "weight_decay: " << ui.lineEdit_weight_decay->text() << "\n";
		}
		
		QString _temp;//lr_policy
		switch (ui.comboBox_lr_policy->currentIndex())
		{
		case 0:
			_temp = "fixed";
			break;
		case 1:
			_temp = "step";
			break;
		case 2:
			_temp = "exp";
			break;
		case 3:
			_temp = "inv";
			break;
		case 4:
			_temp = "multistep";
			break;
		case 5:
			_temp = "poly";
			break;
		case 6:
			_temp = "sigmoid";
			break;
		default:
			break;
		}
		out << "lr_policy: " << "\""<<_temp << "\""<<"\n";
				
		if (ui.lineEdit_gamma->text() != "") {
			out << "gamma: " << ui.lineEdit_gamma->text() << "\n";
		}
		if (ui.lineEdit_power->text() != "") {
			out << "power: " << ui.lineEdit_power->text() << "\n";
		}
		if (ui.lineEdit_display->text() != "") {
			out << "display: " << ui.lineEdit_display->text() << "\n";
		}
		if (ui.lineEdit_max_iter->text() != "") {
			out << "max_iter: " << ui.lineEdit_max_iter->text() << "\n";
		}
		if (ui.lineEdit_snapshot->text() != "") {
			out << "snapshot: " << ui.lineEdit_snapshot->text() << "\n";
		}
		if (ui.lineEdit_snapshot_prefix->text() != "") {
			out << "snapshot_prefix: " << "\"" << ui.lineEdit_snapshot_prefix->text() << "\"" << "\n";
		}
		if (ui.comboBox_solver_mode->currentIndex()==0)
		{
			out << "solver_mode: " << "CPU" << "\n";
		}
		else
		{
			out << "solver_mode: " << "GPU" << "\n";
		}
	}//end of if (file.open)
	else 
	{
		//文件打开失败
		QMessageBox::information(this, QStringLiteral("训练"), QStringLiteral("文件打开失败!"));
	}
	
}
//从求解器文件中读取参数写入界面的相应控件中
void TrainingSetter::ReadSolver()
{
	QFile file(ui.lineEdit_solverFilePath->text());
	if (file.open(QFile::ReadOnly | QFile::Text)) {
		QTextStream QTS(&file);
		while (QTS.atEnd() == false)
		{
			QString _temp = QTS.readLine();
			if (!_temp.startsWith("#"))//注释不处理
			{
				int sat = _temp.indexOf(" ");
				QString target = _temp.mid(sat + 1, _temp.length() - (1 + sat));
				if (_temp.startsWith("net"))
				{
					//处理引号
					QString _target = target.mid(1, target.length() - 2);
					ui.lineEdit_net->setText(_target);
				}
				if (_temp.startsWith("test_iter"))
				{
					ui.lineEdit_test_iter->setText(target);
				}
				if (_temp.startsWith("test_interval"))
				{
					ui.lineEdit_test_interval->setText(target);
				}
				if (_temp.startsWith("base_lr"))
				{
					ui.lineEdit_base_lr->setText(target);
				}
				if (_temp.startsWith("momentum"))
				{
					ui.lineEdit_momentum->setText(target);
				}
				if (_temp.startsWith("weight_decay"))
				{
					ui.lineEdit_weight_decay->setText(target);
				}
				if (_temp.startsWith("lr_policy:"))//lr_policy
				{
					QString _target = target.mid(1, target.length() - 2);//处理掉引号
					if (_target == "fixed")
					{
						ui.comboBox_lr_policy->setCurrentIndex(0);
					}
					if (_target == "step")
					{
						ui.comboBox_lr_policy->setCurrentIndex(1);
					}
					if (_target == "exp")
					{
						ui.comboBox_lr_policy->setCurrentIndex(2);
					}
					if (_target == "inv")
					{
						ui.comboBox_lr_policy->setCurrentIndex(3);
					}
					if (_target == "multistep")
					{
						ui.comboBox_lr_policy->setCurrentIndex(4);
					}
					if (_target == "poly")
					{
						ui.comboBox_lr_policy->setCurrentIndex(5);
					}
					if (_target == "sigmoid")
					{
						ui.comboBox_lr_policy->setCurrentIndex(6);
					}
				}

				if (_temp.startsWith("gamma"))
				{
					ui.lineEdit_gamma->setText(target);
				}
				if (_temp.startsWith("power"))
				{
					ui.lineEdit_power->setText(target);
				}
				if (_temp.startsWith("display"))
				{
					ui.lineEdit_display->setText(target);
				}
				if (_temp.startsWith("max_iter"))
				{
					ui.lineEdit_max_iter->setText(target);
				}
				if (_temp.startsWith("snapshot:"))
				{
					ui.lineEdit_snapshot->setText(target);
				}
				if (_temp.startsWith("snapshot_prefix"))
				{
					//处理引号
					QString _target = target.mid(1, target.length() - 2);
					ui.lineEdit_snapshot_prefix->setText(_target);
				}
				if (_temp.startsWith("solver_mode"))//CPU&GPU
				{
					if (target == "GPU")
					{
						ui.comboBox_solver_mode->setCurrentIndex(1);
					}
					else {
						ui.comboBox_solver_mode->setCurrentIndex(0);
					}
				}
			}
		}//end of while (QTS.atEnd() == false)
	}//end of if (file.open)
	else
	{
		//文件打开失败
		QMessageBox::information(this, QStringLiteral("训练"), QStringLiteral("文件打开失败!"));
	}
}
//执行训练
void TrainingSetter::ExecuteTraining()
{
	//校验参数
	if (ui.lineEdit_solverFilePath->text() != "") {
		//构造命令
		QString cmd = "";
		cmd.append(CoreDir);
		cmd.append("/caffe.exe"); cmd.append(" ");
		cmd.append("train"); cmd.append(" ");
		cmd.append("--solver"); cmd.append("=");
		cmd.append(ui.lineEdit_solverFilePath->text());
		//启动额外线程
		_AdditionalProcess->start(cmd);
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("训练"), QStringLiteral("参数有误!"));
		return;
	}
}
//学习率策略变更
void TrainingSetter::policyChange()
{
	switch (ui.comboBox_lr_policy->currentIndex())
	{
	case 0://fix
		ui.lineEdit_gamma->setEnabled(false);
		ui.lineEdit_power->setEnabled(false);
		ui.lineEdit_stepsize->setEnabled(false);
		ui.lineEdit_stepvalue->setEnabled(false);
		break;
	case 1://step(base_lr * gamma ^ (floor(iter / stepsize)))
		ui.lineEdit_gamma->setEnabled(true);
		ui.lineEdit_power->setEnabled(false);
		ui.lineEdit_stepsize->setEnabled(true);
		ui.lineEdit_stepvalue->setEnabled(false);
		break;
	case 2://exp(base_lr * gamma ^ iter)
		ui.lineEdit_gamma->setEnabled(true);
		ui.lineEdit_power->setEnabled(false);
		ui.lineEdit_stepsize->setEnabled(false);
		ui.lineEdit_stepvalue->setEnabled(false);
		break;
	case 3://inv(base_lr * (1 + gamma * iter) ^ (- power))
		ui.lineEdit_gamma->setEnabled(true);
		ui.lineEdit_power->setEnabled(true);
		ui.lineEdit_stepsize->setEnabled(false);
		ui.lineEdit_stepvalue->setEnabled(false);
		break;
	case 4://multistep(根据stepvalue更新的step方法)
		ui.lineEdit_gamma->setEnabled(true);
		ui.lineEdit_power->setEnabled(false);
		ui.lineEdit_stepsize->setEnabled(true);
		ui.lineEdit_stepvalue->setEnabled(true);
		break;
	case 5://poly(base_lr (1 - iter/max_iter) ^ (power))
		ui.lineEdit_gamma->setEnabled(false);
		ui.lineEdit_power->setEnabled(true);
		ui.lineEdit_stepsize->setEnabled(false);
		ui.lineEdit_stepvalue->setEnabled(false);
		break;
	case 6://sigmoid(base_lr ( 1/(1 + exp(-gamma * (iter - stepsize)))))
		ui.lineEdit_gamma->setEnabled(true);
		ui.lineEdit_power->setEnabled(false);
		ui.lineEdit_stepsize->setEnabled(true);
		ui.lineEdit_stepvalue->setEnabled(false);
		break;
	default:
		break;
	}
}
