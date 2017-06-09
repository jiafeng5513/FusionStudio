/********************************************************************************
** Form generated from reading UI file 'convertmnist.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTMNIST_H
#define UI_CONVERTMNIST_H

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

class Ui_ConvertMnist
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_ResultName;
    QLineEdit *lineEdit_MnistResult;
    QLineEdit *lineEdit_MnistlabelSet;
    QProgressBar *progressBar;
    QRadioButton *radioButton_Lmdb;
    QRadioButton *radioButton_LevelDb;
    QPushButton *pushButton_Convert;
    QPushButton *pushButton_Browser3;
    QPushButton *pushButton_Browser2;
    QPushButton *pushButton_Browser1;
    QLineEdit *lineEdit_MnistImageSet;
    QLabel *label_5;

    void setupUi(QWidget *ConvertMnist)
    {
        if (ConvertMnist->objectName().isEmpty())
            ConvertMnist->setObjectName(QStringLiteral("ConvertMnist"));
        ConvertMnist->resize(483, 230);
        gridLayout = new QGridLayout(ConvertMnist);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(ConvertMnist);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(ConvertMnist);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ConvertMnist);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(ConvertMnist);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_ResultName = new QLineEdit(ConvertMnist);
        lineEdit_ResultName->setObjectName(QStringLiteral("lineEdit_ResultName"));

        gridLayout->addWidget(lineEdit_ResultName, 3, 1, 1, 2);

        lineEdit_MnistResult = new QLineEdit(ConvertMnist);
        lineEdit_MnistResult->setObjectName(QStringLiteral("lineEdit_MnistResult"));

        gridLayout->addWidget(lineEdit_MnistResult, 2, 1, 1, 2);

        lineEdit_MnistlabelSet = new QLineEdit(ConvertMnist);
        lineEdit_MnistlabelSet->setObjectName(QStringLiteral("lineEdit_MnistlabelSet"));

        gridLayout->addWidget(lineEdit_MnistlabelSet, 1, 1, 1, 2);

        progressBar = new QProgressBar(ConvertMnist);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);

        gridLayout->addWidget(progressBar, 5, 2, 1, 1);

        radioButton_Lmdb = new QRadioButton(ConvertMnist);
        radioButton_Lmdb->setObjectName(QStringLiteral("radioButton_Lmdb"));

        gridLayout->addWidget(radioButton_Lmdb, 5, 4, 1, 1);

        radioButton_LevelDb = new QRadioButton(ConvertMnist);
        radioButton_LevelDb->setObjectName(QStringLiteral("radioButton_LevelDb"));

        gridLayout->addWidget(radioButton_LevelDb, 5, 5, 1, 1);

        pushButton_Convert = new QPushButton(ConvertMnist);
        pushButton_Convert->setObjectName(QStringLiteral("pushButton_Convert"));

        gridLayout->addWidget(pushButton_Convert, 3, 5, 1, 1);

        pushButton_Browser3 = new QPushButton(ConvertMnist);
        pushButton_Browser3->setObjectName(QStringLiteral("pushButton_Browser3"));

        gridLayout->addWidget(pushButton_Browser3, 2, 5, 1, 1);

        pushButton_Browser2 = new QPushButton(ConvertMnist);
        pushButton_Browser2->setObjectName(QStringLiteral("pushButton_Browser2"));

        gridLayout->addWidget(pushButton_Browser2, 1, 5, 1, 1);

        pushButton_Browser1 = new QPushButton(ConvertMnist);
        pushButton_Browser1->setObjectName(QStringLiteral("pushButton_Browser1"));

        gridLayout->addWidget(pushButton_Browser1, 0, 5, 1, 1);

        lineEdit_MnistImageSet = new QLineEdit(ConvertMnist);
        lineEdit_MnistImageSet->setObjectName(QStringLiteral("lineEdit_MnistImageSet"));

        gridLayout->addWidget(lineEdit_MnistImageSet, 0, 1, 1, 2);

        label_5 = new QLabel(ConvertMnist);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);


        retranslateUi(ConvertMnist);
        QObject::connect(pushButton_Browser1, SIGNAL(clicked()), ConvertMnist, SLOT(Browser1()));
        QObject::connect(pushButton_Browser2, SIGNAL(clicked()), ConvertMnist, SLOT(Browser2()));
        QObject::connect(pushButton_Browser3, SIGNAL(clicked()), ConvertMnist, SLOT(Browser3()));
        QObject::connect(pushButton_Convert, SIGNAL(clicked()), ConvertMnist, SLOT(DoConvert_Mnist_Data()));

        QMetaObject::connectSlotsByName(ConvertMnist);
    } // setupUi

    void retranslateUi(QWidget *ConvertMnist)
    {
        ConvertMnist->setWindowTitle(QApplication::translate("ConvertMnist", "\346\225\260\346\215\256\346\240\274\345\274\217\350\275\254\346\215\242-Mnist", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConvertMnist", "\347\273\223\346\236\234\345\220\215:", Q_NULLPTR));
        label->setText(QApplication::translate("ConvertMnist", "\345\233\276\347\211\207\351\233\206:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConvertMnist", "\346\240\207\347\255\276\351\233\206:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConvertMnist", "\347\273\223\346\236\234\345\234\260\345\235\200:", Q_NULLPTR));
        radioButton_Lmdb->setText(QApplication::translate("ConvertMnist", "Lmdb", Q_NULLPTR));
        radioButton_LevelDb->setText(QApplication::translate("ConvertMnist", "Leveldb", Q_NULLPTR));
        pushButton_Convert->setText(QApplication::translate("ConvertMnist", "\350\275\254\346\215\242", Q_NULLPTR));
        pushButton_Browser3->setText(QApplication::translate("ConvertMnist", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_Browser2->setText(QApplication::translate("ConvertMnist", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_Browser1->setText(QApplication::translate("ConvertMnist", "\346\265\217\350\247\210", Q_NULLPTR));
        label_5->setText(QApplication::translate("ConvertMnist", "\350\277\233\345\272\246:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConvertMnist: public Ui_ConvertMnist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTMNIST_H
