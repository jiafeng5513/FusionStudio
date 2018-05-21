/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Save;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_InstallPath;
    QLineEdit *lineEdit_BinPath;
    QLineEdit *lineEdit_LibPath;
    QPushButton *pushButton_Browser1;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_Browser2;
    QPushButton *pushButton_Browser3;
    QPushButton *pushButton_ComponemtCheck;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_ComponentState;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_PathSetDefault;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_ScriptsSetDefault;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;

    void setupUi(QWidget *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QStringLiteral("Preferences"));
        Preferences->setWindowModality(Qt::ApplicationModal);
        Preferences->resize(624, 396);
        QIcon icon;
        icon.addFile(QStringLiteral(":/FusionStudio/Resources/System_Preferences_128px_1175167_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Preferences->setWindowIcon(icon);
        gridLayout = new QGridLayout(Preferences);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButton_Save = new QPushButton(Preferences);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        gridLayout->addWidget(pushButton_Save, 3, 1, 1, 1);

        tabWidget = new QTabWidget(Preferences);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_InstallPath = new QLineEdit(tab);
        lineEdit_InstallPath->setObjectName(QStringLiteral("lineEdit_InstallPath"));

        gridLayout_2->addWidget(lineEdit_InstallPath, 0, 2, 1, 3);

        lineEdit_BinPath = new QLineEdit(tab);
        lineEdit_BinPath->setObjectName(QStringLiteral("lineEdit_BinPath"));

        gridLayout_2->addWidget(lineEdit_BinPath, 1, 2, 1, 3);

        lineEdit_LibPath = new QLineEdit(tab);
        lineEdit_LibPath->setObjectName(QStringLiteral("lineEdit_LibPath"));

        gridLayout_2->addWidget(lineEdit_LibPath, 3, 2, 1, 3);

        pushButton_Browser1 = new QPushButton(tab);
        pushButton_Browser1->setObjectName(QStringLiteral("pushButton_Browser1"));

        gridLayout_2->addWidget(pushButton_Browser1, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 7, 2, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        pushButton_Browser2 = new QPushButton(tab);
        pushButton_Browser2->setObjectName(QStringLiteral("pushButton_Browser2"));

        gridLayout_2->addWidget(pushButton_Browser2, 1, 5, 1, 1);

        pushButton_Browser3 = new QPushButton(tab);
        pushButton_Browser3->setObjectName(QStringLiteral("pushButton_Browser3"));

        gridLayout_2->addWidget(pushButton_Browser3, 3, 5, 1, 1);

        pushButton_ComponemtCheck = new QPushButton(tab);
        pushButton_ComponemtCheck->setObjectName(QStringLiteral("pushButton_ComponemtCheck"));

        gridLayout_2->addWidget(pushButton_ComponemtCheck, 7, 3, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        plainTextEdit_ComponentState = new QPlainTextEdit(tab);
        plainTextEdit_ComponentState->setObjectName(QStringLiteral("plainTextEdit_ComponentState"));
        plainTextEdit_ComponentState->setReadOnly(true);

        gridLayout_2->addWidget(plainTextEdit_ComponentState, 4, 2, 3, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 0, 1, 1);

        pushButton_PathSetDefault = new QPushButton(tab);
        pushButton_PathSetDefault->setObjectName(QStringLiteral("pushButton_PathSetDefault"));

        gridLayout_2->addWidget(pushButton_PathSetDefault, 7, 5, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_ScriptsSetDefault = new QPushButton(tab_3);
        pushButton_ScriptsSetDefault->setObjectName(QStringLiteral("pushButton_ScriptsSetDefault"));

        gridLayout_4->addWidget(pushButton_ScriptsSetDefault, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setCascadingSectionResizes(true);

        gridLayout_4->addWidget(tableView, 0, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 3);


        retranslateUi(Preferences);
        QObject::connect(pushButton_Browser1, SIGNAL(clicked()), Preferences, SLOT(Browser1()));
        QObject::connect(pushButton_Browser2, SIGNAL(clicked()), Preferences, SLOT(Browser2()));
        QObject::connect(pushButton_Browser3, SIGNAL(clicked()), Preferences, SLOT(Browser3()));
        QObject::connect(pushButton_ComponemtCheck, SIGNAL(clicked()), Preferences, SLOT(checkComponent()));
        QObject::connect(pushButton_PathSetDefault, SIGNAL(clicked()), Preferences, SLOT(setDefaultPath()));
        QObject::connect(pushButton_Save, SIGNAL(clicked()), Preferences, SLOT(save()));
        QObject::connect(pushButton_ScriptsSetDefault, SIGNAL(clicked()), Preferences, SLOT(setDefaultScripts()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QWidget *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "\351\246\226\351\200\211\351\241\271", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("Preferences", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_Browser1->setText(QApplication::translate("Preferences", "\346\265\217\350\247\210", Q_NULLPTR));
        label_5->setText(QApplication::translate("Preferences", "Lib\347\233\256\345\275\225:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Preferences", "Install\347\233\256\345\275\225:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Preferences", "Bin\347\233\256\345\275\225:", Q_NULLPTR));
        pushButton_Browser2->setText(QApplication::translate("Preferences", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_Browser3->setText(QApplication::translate("Preferences", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_ComponemtCheck->setText(QApplication::translate("Preferences", "\347\273\204\344\273\266\346\240\241\351\252\214", Q_NULLPTR));
        label->setText(QApplication::translate("Preferences", "\347\273\204\344\273\266\347\212\266\346\200\201:", Q_NULLPTR));
        pushButton_PathSetDefault->setText(QApplication::translate("Preferences", "\351\273\230\350\256\244\347\233\256\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Preferences", "\350\267\257\345\276\204\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_ScriptsSetDefault->setText(QApplication::translate("Preferences", "\346\201\242\345\244\215\351\273\230\350\256\244", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Preferences", "\345\221\275\344\273\244\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
