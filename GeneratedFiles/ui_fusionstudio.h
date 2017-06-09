/********************************************************************************
** Form generated from reading UI file 'fusionstudio.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUSIONSTUDIO_H
#define UI_FUSIONSTUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FusionStudioClass
{
public:
    QAction *action_view_Console;
    QAction *action_help_About;
    QAction *action_view_Explorer;
    QAction *action_view_Preferences;
    QAction *action_file_New;
    QAction *action_file_Open;
    QAction *action_file_Close;
    QAction *action_Scan_WorkingDir;
    QAction *action_Training;
    QAction *action_Classification;
    QAction *action_Convert_Mnist;
    QAction *action_Convert_Cifar;
    QAction *action_Convert_Image;
    QAction *action_help_Home;
    QAction *action_DatabaseBrowser;
    QAction *action_FeaturesExp;
    QAction *action_Editor;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_view;
    QMenu *menu_help;
    QMenu *menu_menu;
    QMenu *menu_file;
    QMenu *menu_project;
    QMenu *menu_build;
    QMenu *menu_tools;
    QMenu *menu_converter;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_Explorer;
    QWidget *dockWidgetContents_Explorer;
    QGridLayout *gridLayout_3;
    QTreeView *treeView;
    QDockWidget *dockWidget_Console;
    QWidget *dockWidgetContents_4;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *FusionStudioClass)
    {
        if (FusionStudioClass->objectName().isEmpty())
            FusionStudioClass->setObjectName(QStringLiteral("FusionStudioClass"));
        FusionStudioClass->resize(1177, 733);
        QIcon icon;
        icon.addFile(QStringLiteral(":/FusionStudio/Resources/Dropbox_FUSION_128px_1060231_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FusionStudioClass->setWindowIcon(icon);
        FusionStudioClass->setStyleSheet(QStringLiteral(""));
        action_view_Console = new QAction(FusionStudioClass);
        action_view_Console->setObjectName(QStringLiteral("action_view_Console"));
        action_view_Console->setCheckable(true);
        action_help_About = new QAction(FusionStudioClass);
        action_help_About->setObjectName(QStringLiteral("action_help_About"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/FusionStudio/Resources/help_72px_558008_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_help_About->setIcon(icon1);
        action_view_Explorer = new QAction(FusionStudioClass);
        action_view_Explorer->setObjectName(QStringLiteral("action_view_Explorer"));
        action_view_Explorer->setCheckable(true);
        action_view_Preferences = new QAction(FusionStudioClass);
        action_view_Preferences->setObjectName(QStringLiteral("action_view_Preferences"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/FusionStudio/Resources/System_Preferences_128px_1175167_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_view_Preferences->setIcon(icon2);
        action_file_New = new QAction(FusionStudioClass);
        action_file_New->setObjectName(QStringLiteral("action_file_New"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/FusionStudio/Resources/Folder_Add_128px_1072490_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_New->setIcon(icon3);
        action_file_Open = new QAction(FusionStudioClass);
        action_file_Open->setObjectName(QStringLiteral("action_file_Open"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/FusionStudio/Resources/Folder_Open_128px_1072492_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_Open->setIcon(icon4);
        action_file_Close = new QAction(FusionStudioClass);
        action_file_Close->setObjectName(QStringLiteral("action_file_Close"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/FusionStudio/Resources/Folder_Delete_128px_1072491_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_file_Close->setIcon(icon5);
        action_Scan_WorkingDir = new QAction(FusionStudioClass);
        action_Scan_WorkingDir->setObjectName(QStringLiteral("action_Scan_WorkingDir"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/FusionStudio/Resources/Fingerprint_Scan_128px_1191479_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Scan_WorkingDir->setIcon(icon6);
        action_Training = new QAction(FusionStudioClass);
        action_Training->setObjectName(QStringLiteral("action_Training"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/FusionStudio/Resources/Run_prompt_128px_1121549_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Training->setIcon(icon7);
        action_Classification = new QAction(FusionStudioClass);
        action_Classification->setObjectName(QStringLiteral("action_Classification"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/FusionStudio/Resources/measure_units_silver_32px_1099530_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Classification->setIcon(icon8);
        action_Convert_Mnist = new QAction(FusionStudioClass);
        action_Convert_Mnist->setObjectName(QStringLiteral("action_Convert_Mnist"));
        action_Convert_Cifar = new QAction(FusionStudioClass);
        action_Convert_Cifar->setObjectName(QStringLiteral("action_Convert_Cifar"));
        action_Convert_Image = new QAction(FusionStudioClass);
        action_Convert_Image->setObjectName(QStringLiteral("action_Convert_Image"));
        action_help_Home = new QAction(FusionStudioClass);
        action_help_Home->setObjectName(QStringLiteral("action_help_Home"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/FusionStudio/Resources/home_128px_1110050_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_help_Home->setIcon(icon9);
        action_DatabaseBrowser = new QAction(FusionStudioClass);
        action_DatabaseBrowser->setObjectName(QStringLiteral("action_DatabaseBrowser"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/FusionStudio/Resources/data_128px_1101024_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_DatabaseBrowser->setIcon(icon10);
        action_FeaturesExp = new QAction(FusionStudioClass);
        action_FeaturesExp->setObjectName(QStringLiteral("action_FeaturesExp"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/FusionStudio/Resources/Camera_128px_1198140_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_FeaturesExp->setIcon(icon11);
        action_Editor = new QAction(FusionStudioClass);
        action_Editor->setObjectName(QStringLiteral("action_Editor"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/FusionStudio/Resources/edit_128px_1158388_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Editor->setIcon(icon12);
        centralWidget = new QWidget(FusionStudioClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 4, 4, 0);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setAutoFillBackground(true);
        mdiArea->setStyleSheet(QStringLiteral(""));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(false);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);
        mdiArea->setTabShape(QTabWidget::Triangular);
        mdiArea->setTabPosition(QTabWidget::North);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        FusionStudioClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FusionStudioClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1177, 23));
        menu_view = new QMenu(menuBar);
        menu_view->setObjectName(QStringLiteral("menu_view"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QStringLiteral("menu_help"));
        menu_help->setStyleSheet(QStringLiteral(""));
        menu_help->setTearOffEnabled(false);
        menu_help->setSeparatorsCollapsible(false);
        menu_help->setToolTipsVisible(false);
        menu_menu = new QMenu(menuBar);
        menu_menu->setObjectName(QStringLiteral("menu_menu"));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_project = new QMenu(menuBar);
        menu_project->setObjectName(QStringLiteral("menu_project"));
        menu_build = new QMenu(menuBar);
        menu_build->setObjectName(QStringLiteral("menu_build"));
        menu_tools = new QMenu(menuBar);
        menu_tools->setObjectName(QStringLiteral("menu_tools"));
        menu_converter = new QMenu(menu_tools);
        menu_converter->setObjectName(QStringLiteral("menu_converter"));
        FusionStudioClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FusionStudioClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FusionStudioClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FusionStudioClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FusionStudioClass->setStatusBar(statusBar);
        dockWidget_Explorer = new QDockWidget(FusionStudioClass);
        dockWidget_Explorer->setObjectName(QStringLiteral("dockWidget_Explorer"));
        dockWidget_Explorer->setContextMenuPolicy(Qt::NoContextMenu);
        dockWidget_Explorer->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_Explorer = new QWidget();
        dockWidgetContents_Explorer->setObjectName(QStringLiteral("dockWidgetContents_Explorer"));
        dockWidgetContents_Explorer->setContextMenuPolicy(Qt::NoContextMenu);
        gridLayout_3 = new QGridLayout(dockWidgetContents_Explorer);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(dockWidgetContents_Explorer);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMouseTracking(true);
        treeView->setFocusPolicy(Qt::ClickFocus);
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_3->addWidget(treeView, 0, 0, 1, 1);

        dockWidget_Explorer->setWidget(dockWidgetContents_Explorer);
        FusionStudioClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_Explorer);
        dockWidget_Console = new QDockWidget(FusionStudioClass);
        dockWidget_Console->setObjectName(QStringLiteral("dockWidget_Console"));
        dockWidget_Console->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(dockWidgetContents_4);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setTabStopWidth(80);

        horizontalLayout->addWidget(plainTextEdit);

        dockWidget_Console->setWidget(dockWidgetContents_4);
        FusionStudioClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_Console);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_view->menuAction());
        menuBar->addAction(menu_project->menuAction());
        menuBar->addAction(menu_build->menuAction());
        menuBar->addAction(menu_tools->menuAction());
        menuBar->addAction(menu_menu->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_view->addAction(action_view_Explorer);
        menu_view->addAction(action_view_Console);
        menu_help->addAction(action_help_Home);
        menu_help->addAction(action_help_About);
        menu_menu->addAction(action_view_Preferences);
        menu_file->addAction(action_file_New);
        menu_file->addAction(action_file_Open);
        menu_file->addAction(action_file_Close);
        menu_project->addAction(action_Scan_WorkingDir);
        menu_build->addAction(action_Editor);
        menu_build->addAction(action_Training);
        menu_build->addAction(action_Classification);
        menu_build->addAction(action_FeaturesExp);
        menu_tools->addAction(menu_converter->menuAction());
        menu_tools->addAction(action_DatabaseBrowser);
        menu_converter->addAction(action_Convert_Mnist);
        menu_converter->addAction(action_Convert_Cifar);
        menu_converter->addAction(action_Convert_Image);
        mainToolBar->addAction(action_file_New);
        mainToolBar->addAction(action_file_Open);
        mainToolBar->addAction(action_file_Close);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Scan_WorkingDir);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Editor);
        mainToolBar->addAction(action_Training);
        mainToolBar->addAction(action_Classification);
        mainToolBar->addAction(action_FeaturesExp);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_DatabaseBrowser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_view_Preferences);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_help_Home);
        mainToolBar->addAction(action_help_About);

        retranslateUi(FusionStudioClass);
        QObject::connect(treeView, SIGNAL(customContextMenuRequested(QPoint)), FusionStudioClass, SLOT(on_treeView_customContextMenuRequested(QPoint)));
        QObject::connect(action_view_Preferences, SIGNAL(triggered()), FusionStudioClass, SLOT(PreferencesSetter()));
        QObject::connect(action_view_Explorer, SIGNAL(triggered()), FusionStudioClass, SLOT(changeVisible_Explorer()));
        QObject::connect(action_view_Console, SIGNAL(triggered()), FusionStudioClass, SLOT(changeVisible_Console()));
        QObject::connect(action_file_Open, SIGNAL(triggered()), FusionStudioClass, SLOT(FolderUnfolder()));
        QObject::connect(action_file_New, SIGNAL(triggered()), FusionStudioClass, SLOT(FolderCreater()));
        QObject::connect(action_file_Close, SIGNAL(triggered()), FusionStudioClass, SLOT(FolderCloser()));
        QObject::connect(action_Scan_WorkingDir, SIGNAL(triggered()), FusionStudioClass, SLOT(WorkingDirScanner()));
        QObject::connect(action_DatabaseBrowser, SIGNAL(triggered()), FusionStudioClass, SLOT(DatabaseBrowser()));
        QObject::connect(action_Convert_Mnist, SIGNAL(triggered()), FusionStudioClass, SLOT(MnistConverter()));
        QObject::connect(action_Convert_Image, SIGNAL(triggered()), FusionStudioClass, SLOT(ImageConverter()));
        QObject::connect(action_Convert_Cifar, SIGNAL(triggered()), FusionStudioClass, SLOT(CifarConverter()));
        QObject::connect(action_Classification, SIGNAL(triggered()), FusionStudioClass, SLOT(DoClassification()));
        QObject::connect(action_Training, SIGNAL(triggered()), FusionStudioClass, SLOT(Train()));
        QObject::connect(action_Editor, SIGNAL(triggered()), FusionStudioClass, SLOT(ShowEditor()));
        QObject::connect(action_help_Home, SIGNAL(triggered()), FusionStudioClass, SLOT(ShowHome()));
        QObject::connect(action_FeaturesExp, SIGNAL(triggered()), FusionStudioClass, SLOT(DoFeaturesExp()));
        QObject::connect(action_help_About, SIGNAL(triggered()), FusionStudioClass, SLOT(ShowAbout()));

        QMetaObject::connectSlotsByName(FusionStudioClass);
    } // setupUi

    void retranslateUi(QMainWindow *FusionStudioClass)
    {
        FusionStudioClass->setWindowTitle(QApplication::translate("FusionStudioClass", "FusionStudio", Q_NULLPTR));
        action_view_Console->setText(QApplication::translate("FusionStudioClass", "\346\216\247\345\210\266\345\217\260", Q_NULLPTR));
        action_help_About->setText(QApplication::translate("FusionStudioClass", "\345\205\263\344\272\216", Q_NULLPTR));
        action_view_Explorer->setText(QApplication::translate("FusionStudioClass", "\350\265\204\346\272\220\347\256\241\347\220\206\345\231\250", Q_NULLPTR));
        action_view_Preferences->setText(QApplication::translate("FusionStudioClass", "\351\246\226\351\200\211\351\241\271", Q_NULLPTR));
        action_file_New->setText(QApplication::translate("FusionStudioClass", "\346\226\260\345\273\272\345\267\245\344\275\234\347\233\256\345\275\225", Q_NULLPTR));
        action_file_Open->setText(QApplication::translate("FusionStudioClass", "\346\211\223\345\274\200\345\267\245\344\275\234\347\233\256\345\275\225", Q_NULLPTR));
        action_file_Close->setText(QApplication::translate("FusionStudioClass", "\345\205\263\351\227\255\345\267\245\344\275\234\347\233\256\345\275\225", Q_NULLPTR));
        action_Scan_WorkingDir->setText(QApplication::translate("FusionStudioClass", "\346\211\253\346\217\217\345\267\245\344\275\234\347\233\256\345\275\225", Q_NULLPTR));
        action_Training->setText(QApplication::translate("FusionStudioClass", "\350\256\255\347\273\203", Q_NULLPTR));
        action_Classification->setText(QApplication::translate("FusionStudioClass", "\346\265\213\350\257\225", Q_NULLPTR));
        action_Convert_Mnist->setText(QApplication::translate("FusionStudioClass", "Mnist", Q_NULLPTR));
        action_Convert_Cifar->setText(QApplication::translate("FusionStudioClass", "cifar", Q_NULLPTR));
        action_Convert_Image->setText(QApplication::translate("FusionStudioClass", "\345\233\276\347\211\207", Q_NULLPTR));
        action_help_Home->setText(QApplication::translate("FusionStudioClass", "\345\274\200\345\247\213\351\241\265\351\235\242", Q_NULLPTR));
        action_DatabaseBrowser->setText(QApplication::translate("FusionStudioClass", "\346\225\260\346\215\256\351\233\206\346\265\217\350\247\210", Q_NULLPTR));
        action_FeaturesExp->setText(QApplication::translate("FusionStudioClass", "\347\211\271\345\276\201\345\257\274\345\207\272", Q_NULLPTR));
        action_Editor->setText(QApplication::translate("FusionStudioClass", "\347\274\226\350\276\221", Q_NULLPTR));
        menu_view->setTitle(QApplication::translate("FusionStudioClass", "\350\247\206\345\233\276", Q_NULLPTR));
        menu_help->setTitle(QApplication::translate("FusionStudioClass", "\345\270\256\345\212\251", Q_NULLPTR));
        menu_menu->setTitle(QApplication::translate("FusionStudioClass", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_file->setTitle(QApplication::translate("FusionStudioClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_project->setTitle(QApplication::translate("FusionStudioClass", "\351\241\271\347\233\256", Q_NULLPTR));
        menu_build->setTitle(QApplication::translate("FusionStudioClass", "\347\224\237\346\210\220", Q_NULLPTR));
        menu_tools->setTitle(QApplication::translate("FusionStudioClass", "\345\267\245\345\205\267", Q_NULLPTR));
        menu_converter->setTitle(QApplication::translate("FusionStudioClass", "\346\225\260\346\215\256\350\275\254\346\215\242", Q_NULLPTR));
        dockWidget_Explorer->setWindowTitle(QApplication::translate("FusionStudioClass", "\350\265\204\346\272\220\347\256\241\347\220\206\345\231\250", Q_NULLPTR));
        dockWidget_Console->setWindowTitle(QApplication::translate("FusionStudioClass", "\346\216\247\345\210\266\345\217\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FusionStudioClass: public Ui_FusionStudioClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUSIONSTUDIO_H
