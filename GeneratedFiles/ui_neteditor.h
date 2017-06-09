/********************************************************************************
** Form generated from reading UI file 'neteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETEDITOR_H
#define UI_NETEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetEditor
{
public:
    QAction *action_Delete;
    QAction *action_BringToFront;
    QAction *action_SendToBack;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_TextEditor;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_Text;
    QWidget *tab_BlueprintEditor;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_Blueprint;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *NetEditor)
    {
        if (NetEditor->objectName().isEmpty())
            NetEditor->setObjectName(QStringLiteral("NetEditor"));
        NetEditor->resize(635, 400);
        action_Delete = new QAction(NetEditor);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/BlueprintEditor/Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete->setIcon(icon);
        action_BringToFront = new QAction(NetEditor);
        action_BringToFront->setObjectName(QStringLiteral("action_BringToFront"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/BlueprintEditor/Resources/bringtofront.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_BringToFront->setIcon(icon1);
        action_SendToBack = new QAction(NetEditor);
        action_SendToBack->setObjectName(QStringLiteral("action_SendToBack"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/BlueprintEditor/Resources/sendtoback.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SendToBack->setIcon(icon2);
        centralWidget = new QWidget(NetEditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        tab_TextEditor = new QWidget();
        tab_TextEditor->setObjectName(QStringLiteral("tab_TextEditor"));
        gridLayout_3 = new QGridLayout(tab_TextEditor);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_Text = new QGridLayout();
        gridLayout_Text->setSpacing(0);
        gridLayout_Text->setObjectName(QStringLiteral("gridLayout_Text"));

        gridLayout_3->addLayout(gridLayout_Text, 0, 0, 1, 1);

        tabWidget->addTab(tab_TextEditor, QString());
        tab_BlueprintEditor = new QWidget();
        tab_BlueprintEditor->setObjectName(QStringLiteral("tab_BlueprintEditor"));
        gridLayout_5 = new QGridLayout(tab_BlueprintEditor);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_Blueprint = new QHBoxLayout();
        horizontalLayout_Blueprint->setSpacing(6);
        horizontalLayout_Blueprint->setObjectName(QStringLiteral("horizontalLayout_Blueprint"));

        gridLayout_5->addLayout(horizontalLayout_Blueprint, 0, 0, 1, 1);

        tabWidget->addTab(tab_BlueprintEditor, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        NetEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NetEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 635, 23));
        NetEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NetEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NetEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(action_Delete);
        mainToolBar->addAction(action_BringToFront);
        mainToolBar->addAction(action_SendToBack);
        mainToolBar->addSeparator();

        retranslateUi(NetEditor);
        QObject::connect(action_Delete, SIGNAL(triggered()), NetEditor, SLOT(deleteItem()));
        QObject::connect(action_BringToFront, SIGNAL(triggered()), NetEditor, SLOT(bringToFront()));
        QObject::connect(action_SendToBack, SIGNAL(triggered()), NetEditor, SLOT(sendToBack()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NetEditor);
    } // setupUi

    void retranslateUi(QMainWindow *NetEditor)
    {
        NetEditor->setWindowTitle(QApplication::translate("NetEditor", "NetEditor", Q_NULLPTR));
        action_Delete->setText(QApplication::translate("NetEditor", "\345\210\240\351\231\244", Q_NULLPTR));
        action_BringToFront->setText(QApplication::translate("NetEditor", "\347\275\256\344\272\216\351\241\266\345\261\202", Q_NULLPTR));
        action_SendToBack->setText(QApplication::translate("NetEditor", "\347\275\256\344\272\216\345\272\225\345\261\202", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_TextEditor), QApplication::translate("NetEditor", "\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_BlueprintEditor), QApplication::translate("NetEditor", "\350\223\235\345\233\276\347\274\226\350\276\221\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NetEditor: public Ui_NetEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETEDITOR_H
