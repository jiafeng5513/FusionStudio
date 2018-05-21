/********************************************************************************
** Form generated from reading UI file 'convertcifar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTCIFAR_H
#define UI_CONVERTCIFAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertCifar
{
public:
    QGridLayout *gridLayout;
    QRadioButton *LevelDbButton;
    QPushButton *pushButton_BrowserOutput;
    QLabel *label_9;
    QLabel *label_8;
    QPushButton *pushButton_BrowserInput;
    QPushButton *pushButton_DoConvert;
    QProgressBar *progressBar;
    QRadioButton *LmDbButton;
    QLineEdit *lineEdit_outputfolder;
    QLineEdit *lineEdit_Inputfolder;

    void setupUi(QWidget *ConvertCifar)
    {
        if (ConvertCifar->objectName().isEmpty())
            ConvertCifar->setObjectName(QStringLiteral("ConvertCifar"));
        ConvertCifar->resize(474, 166);
        gridLayout = new QGridLayout(ConvertCifar);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LevelDbButton = new QRadioButton(ConvertCifar);
        LevelDbButton->setObjectName(QStringLiteral("LevelDbButton"));

        gridLayout->addWidget(LevelDbButton, 4, 0, 1, 1);

        pushButton_BrowserOutput = new QPushButton(ConvertCifar);
        pushButton_BrowserOutput->setObjectName(QStringLiteral("pushButton_BrowserOutput"));

        gridLayout->addWidget(pushButton_BrowserOutput, 3, 4, 1, 1);

        label_9 = new QLabel(ConvertCifar);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        label_8 = new QLabel(ConvertCifar);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        pushButton_BrowserInput = new QPushButton(ConvertCifar);
        pushButton_BrowserInput->setObjectName(QStringLiteral("pushButton_BrowserInput"));

        gridLayout->addWidget(pushButton_BrowserInput, 2, 4, 1, 1);

        pushButton_DoConvert = new QPushButton(ConvertCifar);
        pushButton_DoConvert->setObjectName(QStringLiteral("pushButton_DoConvert"));

        gridLayout->addWidget(pushButton_DoConvert, 4, 4, 1, 1);

        progressBar = new QProgressBar(ConvertCifar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 4, 2, 1, 1);

        LmDbButton = new QRadioButton(ConvertCifar);
        LmDbButton->setObjectName(QStringLiteral("LmDbButton"));

        gridLayout->addWidget(LmDbButton, 4, 1, 1, 1);

        lineEdit_outputfolder = new QLineEdit(ConvertCifar);
        lineEdit_outputfolder->setObjectName(QStringLiteral("lineEdit_outputfolder"));

        gridLayout->addWidget(lineEdit_outputfolder, 3, 1, 1, 3);

        lineEdit_Inputfolder = new QLineEdit(ConvertCifar);
        lineEdit_Inputfolder->setObjectName(QStringLiteral("lineEdit_Inputfolder"));

        gridLayout->addWidget(lineEdit_Inputfolder, 2, 1, 1, 3);


        retranslateUi(ConvertCifar);
        QObject::connect(pushButton_BrowserInput, SIGNAL(clicked()), ConvertCifar, SLOT(Browser1()));
        QObject::connect(pushButton_BrowserOutput, SIGNAL(clicked()), ConvertCifar, SLOT(Browser2()));
        QObject::connect(pushButton_DoConvert, SIGNAL(clicked()), ConvertCifar, SLOT(DoConvert()));

        QMetaObject::connectSlotsByName(ConvertCifar);
    } // setupUi

    void retranslateUi(QWidget *ConvertCifar)
    {
        ConvertCifar->setWindowTitle(QApplication::translate("ConvertCifar", "\346\225\260\346\215\256\350\275\254\346\215\242-Cifar", Q_NULLPTR));
        LevelDbButton->setText(QApplication::translate("ConvertCifar", "LevelDB", Q_NULLPTR));
        pushButton_BrowserOutput->setText(QApplication::translate("ConvertCifar", "\346\265\217\350\247\210", Q_NULLPTR));
        label_9->setText(QApplication::translate("ConvertCifar", "\350\276\223\345\207\272\346\226\207\344\273\266\345\244\271:", Q_NULLPTR));
        label_8->setText(QApplication::translate("ConvertCifar", "cifar\346\225\260\346\215\256\346\226\207\344\273\266\345\244\271:", Q_NULLPTR));
        pushButton_BrowserInput->setText(QApplication::translate("ConvertCifar", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_DoConvert->setText(QApplication::translate("ConvertCifar", "\350\275\254\346\215\242", Q_NULLPTR));
        LmDbButton->setText(QApplication::translate("ConvertCifar", "LMDB", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConvertCifar: public Ui_ConvertCifar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTCIFAR_H
