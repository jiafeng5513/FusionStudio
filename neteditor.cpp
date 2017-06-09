#include "neteditor.h"
#include <QToolButton>
#include <QLabel>
#include <QGraphicsView>
#include <QComboBox>
#include <Arrow.h>

//构造函数
NetEditor::NetEditor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//启动格式文本编辑器,未来应该传入文件名用来进行初始化和作为文档的标题
	MyTextEditor = new Editor();
	MyTextEditor->newFile();
	ui.gridLayout_Text->addWidget(MyTextEditor);

	//启动蓝图编辑器
	createToolBox();//左侧工具箱的创建
	scene = new DiagramScene(this);
	scene->setSceneRect(QRectF(0, 0, 5000, 5000));
	//连接信号槽
	connect(scene, SIGNAL(itemInserted(DiagramItem*)), this, SLOT(itemInserted(DiagramItem*)));
	//connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)),this, SLOT(textInserted(QGraphicsTextItem*)));
	//connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),this, SLOT(itemSelected(QGraphicsItem*)));
	createToolbars();//创建额外的工具条
	view = new QGraphicsView(scene);
	ui.horizontalLayout_Blueprint->addWidget(toolBox);
	ui.horizontalLayout_Blueprint->addWidget(view);
}
//析构函数
NetEditor::~NetEditor()
{
}

/*==============================================================================*/
/*                                     类方法                                   */
/*==============================================================================*/

//创建工具箱
void NetEditor::createToolBox()
{
	buttonGroup = new QButtonGroup(this);
	buttonGroup->setExclusive(false);
	connect(buttonGroup, SIGNAL(buttonClicked(int)),this, SLOT(buttonGroupClicked(int)));
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(createCellWidget(QStringLiteral("数据源"), DiagramItem::DataSource), 0, 0);
	layout->addWidget(createCellWidget(QStringLiteral("输入层"), DiagramItem::InputLayer), 0, 1);
	layout->addWidget(createCellWidget(QStringLiteral("卷积层"), DiagramItem::ConvLayer), 1, 0);
	layout->addWidget(createCellWidget(QStringLiteral("池化层"), DiagramItem::PoolingLayer), 1, 1);

	layout->setRowStretch(3, 10);
	layout->setColumnStretch(2, 10);

	QWidget *itemWidget = new QWidget;
	itemWidget->setLayout(layout);

	backgroundButtonGroup = new QButtonGroup(this);
	connect(backgroundButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)),
		this, SLOT(backgroundButtonGroupClicked(QAbstractButton*)));

	QGridLayout *backgroundLayout = new QGridLayout;
	backgroundLayout->addWidget(createBackgroundCellWidget(tr("Blue Grid"),
		                        "./Resources/background1.png"), 0, 0);
	backgroundLayout->addWidget(createBackgroundCellWidget(tr("White Grid"),
		                        "./Resources/background2.png"), 0, 1);
	backgroundLayout->addWidget(createBackgroundCellWidget(tr("Gray Grid"),
		                        "./Resources/background3.png"), 1, 0);
	backgroundLayout->addWidget(createBackgroundCellWidget(tr("No Grid"),
		                        "./Resources/background4.png"), 1, 1);

	backgroundLayout->setRowStretch(2, 10);
	backgroundLayout->setColumnStretch(2, 10);

	QWidget *backgroundWidget = new QWidget;
	backgroundWidget->setLayout(backgroundLayout);


	//! [22]
	toolBox = new QToolBox;
	toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
	toolBox->setMinimumWidth(itemWidget->sizeHint().width());
	toolBox->addItem(itemWidget, QStringLiteral("图元"));
	toolBox->addItem(backgroundWidget, QStringLiteral("背景"));
}
//创建额外的工具条
void NetEditor::createToolbars()
{
	QToolButton *pointerButton = new QToolButton;
	pointerButton->setCheckable(true);
	pointerButton->setChecked(true);
	pointerButton->setIcon(QIcon("./Resources/pointer.png"));
	QToolButton *linePointerButton = new QToolButton;
	linePointerButton->setCheckable(true);
	linePointerButton->setIcon(QIcon("./Resources/linepointer.png"));

	pointerTypeGroup = new QButtonGroup(this);
	pointerTypeGroup->addButton(pointerButton, int(DiagramScene::MoveItem));
	pointerTypeGroup->addButton(linePointerButton, int(DiagramScene::InsertLine));
	connect(pointerTypeGroup, SIGNAL(buttonClicked(int)),
		this, SLOT(pointerGroupClicked(int)));

	sceneScaleCombo = new QComboBox;
	QStringList scales;
	scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
	sceneScaleCombo->addItems(scales);
	sceneScaleCombo->setCurrentIndex(2);
	connect(sceneScaleCombo, SIGNAL(currentIndexChanged(QString)),
		this, SLOT(sceneScaleChanged(QString)));

	pointerToolbar = addToolBar(tr("Pointer type"));
	pointerToolbar->addWidget(pointerButton);
	pointerToolbar->addWidget(linePointerButton);
	pointerToolbar->addWidget(sceneScaleCombo);
}
//创建图元画刷按钮
QWidget * NetEditor::createCellWidget(const QString & text, DiagramItem::DiagramType type)
{
	DiagramItem item(type);
	QIcon icon(item.image());

	QToolButton *button = new QToolButton;
	button->setIcon(icon);
	button->setIconSize(QSize(50, 50));
	button->setCheckable(true);
	buttonGroup->addButton(button, int(type));

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(button, 0, 0, Qt::AlignHCenter);
	layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

	QWidget *widget = new QWidget;
	widget->setLayout(layout);

	return widget;
}
//创建背景切换按钮
QWidget * NetEditor::createBackgroundCellWidget(const QString & text, const QString & image)
{
	QToolButton *button = new QToolButton;
	button->setText(text);
	button->setIcon(QIcon(image));
	button->setIconSize(QSize(50, 50));
	button->setCheckable(true);
	backgroundButtonGroup->addButton(button);

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(button, 0, 0, Qt::AlignHCenter);
	layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

	QWidget *widget = new QWidget;
	widget->setLayout(layout);

	return widget;
}

/*==============================================================================*/
/*                                     槽函数                                   */
/*==============================================================================*/

//槽函数:图元插入
void NetEditor::itemInserted(DiagramItem *item)
{
	pointerTypeGroup->button(int(DiagramScene::MoveItem))->setChecked(true);
	scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
	buttonGroup->button(int(item->diagramType()))->setChecked(false);
}
//蛤?
void NetEditor::itemSelected(QGraphicsItem * item)
{
	//DiagramTextItem *textItem =
	//	qgraphicsitem_cast<DiagramTextItem *>(item);

	//QFont font = textItem->font();
	//fontCombo->setCurrentFont(font);
	//fontSizeCombo->setEditText(QString().setNum(font.pointSize()));
	//boldAction->setChecked(font.weight() == QFont::Bold);
	//italicAction->setChecked(font.italic());
	//underlineAction->setChecked(font.underline());
}
//槽函数:置于顶层
void NetEditor::bringToFront()
{
	if (scene->selectedItems().isEmpty())
		return;

	QGraphicsItem *selectedItem = scene->selectedItems().first();
	QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

	qreal zValue = 0;
	foreach(QGraphicsItem *item, overlapItems) {
		if (item->zValue() >= zValue && item->type() == DiagramItem::Type)
			zValue = item->zValue() + 0.1;
	}
	selectedItem->setZValue(zValue);
}
//槽函数:置于底层
void NetEditor::sendToBack()
{
	if (scene->selectedItems().isEmpty())
		return;

	QGraphicsItem *selectedItem = scene->selectedItems().first();
	QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

	qreal zValue = 0;
	foreach(QGraphicsItem *item, overlapItems) {
		if (item->zValue() <= zValue && item->type() == DiagramItem::Type)
			zValue = item->zValue() - 0.1;
	}
	selectedItem->setZValue(zValue);
}
//槽函数:删除元素
void NetEditor::deleteItem()
{
	foreach(QGraphicsItem *item, scene->selectedItems()) {
		if (item->type() == Arrow::Type) {
			scene->removeItem(item);
			Arrow *arrow = qgraphicsitem_cast<Arrow *>(item);
			arrow->startItem()->removeArrow(arrow);
			arrow->endItem()->removeArrow(arrow);
			delete item;
		}
	}

	foreach(QGraphicsItem *item, scene->selectedItems()) {
		if (item->type() == DiagramItem::Type)
			qgraphicsitem_cast<DiagramItem *>(item)->removeArrows();
		scene->removeItem(item);
		delete item;
	}
}
//槽函数:鼠标指针变更
void NetEditor::pointerGroupClicked(int id)
{
	scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}
//槽函数:缩放
void NetEditor::sceneScaleChanged(const QString & scale)
{
	double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
	QMatrix oldMatrix = view->matrix();
	view->resetMatrix();
	view->translate(oldMatrix.dx(), oldMatrix.dy());
	view->scale(newScale, newScale);
}
//槽函数:点击切换背景
void NetEditor::backgroundButtonGroupClicked(QAbstractButton * button)
{
	QList<QAbstractButton *> buttons = backgroundButtonGroup->buttons();
	foreach(QAbstractButton *myButton, buttons) {
		if (myButton != button)
			button->setChecked(false);
	}
	QString text = button->text();
	if (text == tr("Blue Grid"))
		scene->setBackgroundBrush(QPixmap("./Resources/background1.png"));
	else if (text == tr("White Grid"))
		scene->setBackgroundBrush(QPixmap("./Resources/background2.png"));
	else if (text == tr("Gray Grid"))
		scene->setBackgroundBrush(QPixmap("./Resources/background3.png"));
	else
		scene->setBackgroundBrush(QPixmap("./Resources/background4.png"));

	scene->update();
	view->update();
}
//槽函数:选中图元,点击画图
void NetEditor::buttonGroupClicked(int id)
{
	QList<QAbstractButton *> buttons = buttonGroup->buttons();
	foreach(QAbstractButton *button, buttons) {
		if (buttonGroup->button(id) != button)
			button->setChecked(false);
	}
/*	if (id == InsertTextButton) {
		scene->setMode(DiagramScene::InsertText);
	}
	else {*/
		scene->setItemType(DiagramItem::DiagramType(id));
		scene->setMode(DiagramScene::InsertItem);
	//}
}
