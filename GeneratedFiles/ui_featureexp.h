/********************************************************************************
** Form generated from reading UI file 'featureexp.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATUREEXP_H
#define UI_FEATUREEXP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeatureExp
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_4;
    QPushButton *pushButton_DoExp;
    QPushButton *pushButton_BrowserPath;
    QLabel *label_3;
    QPushButton *pushButton_Verify;
    QLabel *label_5;
    QPushButton *pushButton_BrowserModel;
    QPushButton *pushButton_BrowserProto;
    QRadioButton *radioButton_leveldb;
    QRadioButton *radioButton_lmdb;
    QComboBox *comboBox_cupgpu;
    QLineEdit *lineEdit_MiniBatches;
    QLineEdit *lineEdit_LayerID;
    QLineEdit *lineEdit_DbName;
    QLineEdit *lineEdit_ExpPath;
    QLineEdit *lineEdit_Prototxt;
    QLineEdit *lineEdit_Model;
    QLabel *label;

    void setupUi(QWidget *FeatureExp)
    {
        if (FeatureExp->objectName().isEmpty())
            FeatureExp->setObjectName(QStringLiteral("FeatureExp"));
        FeatureExp->resize(478, 237);
        gridLayout_2 = new QGridLayout(FeatureExp);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(FeatureExp);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        pushButton_DoExp = new QPushButton(groupBox);
        pushButton_DoExp->setObjectName(QStringLiteral("pushButton_DoExp"));

        gridLayout->addWidget(pushButton_DoExp, 7, 4, 1, 1);

        pushButton_BrowserPath = new QPushButton(groupBox);
        pushButton_BrowserPath->setObjectName(QStringLiteral("pushButton_BrowserPath"));

        gridLayout->addWidget(pushButton_BrowserPath, 3, 4, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pushButton_Verify = new QPushButton(groupBox);
        pushButton_Verify->setObjectName(QStringLiteral("pushButton_Verify"));

        gridLayout->addWidget(pushButton_Verify, 5, 4, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        pushButton_BrowserModel = new QPushButton(groupBox);
        pushButton_BrowserModel->setObjectName(QStringLiteral("pushButton_BrowserModel"));

        gridLayout->addWidget(pushButton_BrowserModel, 0, 4, 1, 1);

        pushButton_BrowserProto = new QPushButton(groupBox);
        pushButton_BrowserProto->setObjectName(QStringLiteral("pushButton_BrowserProto"));

        gridLayout->addWidget(pushButton_BrowserProto, 2, 4, 1, 1);

        radioButton_leveldb = new QRadioButton(groupBox);
        radioButton_leveldb->setObjectName(QStringLiteral("radioButton_leveldb"));

        gridLayout->addWidget(radioButton_leveldb, 8, 4, 1, 1);

        radioButton_lmdb = new QRadioButton(groupBox);
        radioButton_lmdb->setObjectName(QStringLiteral("radioButton_lmdb"));

        gridLayout->addWidget(radioButton_lmdb, 8, 3, 1, 1);

        comboBox_cupgpu = new QComboBox(groupBox);
        comboBox_cupgpu->setObjectName(QStringLiteral("comboBox_cupgpu"));

        gridLayout->addWidget(comboBox_cupgpu, 8, 1, 1, 2);

        lineEdit_MiniBatches = new QLineEdit(groupBox);
        lineEdit_MiniBatches->setObjectName(QStringLiteral("lineEdit_MiniBatches"));

        gridLayout->addWidget(lineEdit_MiniBatches, 7, 1, 1, 3);

        lineEdit_LayerID = new QLineEdit(groupBox);
        lineEdit_LayerID->setObjectName(QStringLiteral("lineEdit_LayerID"));

        gridLayout->addWidget(lineEdit_LayerID, 5, 1, 1, 3);

        lineEdit_DbName = new QLineEdit(groupBox);
        lineEdit_DbName->setObjectName(QStringLiteral("lineEdit_DbName"));

        gridLayout->addWidget(lineEdit_DbName, 4, 1, 1, 3);

        lineEdit_ExpPath = new QLineEdit(groupBox);
        lineEdit_ExpPath->setObjectName(QStringLiteral("lineEdit_ExpPath"));

        gridLayout->addWidget(lineEdit_ExpPath, 3, 1, 1, 3);

        lineEdit_Prototxt = new QLineEdit(groupBox);
        lineEdit_Prototxt->setObjectName(QStringLiteral("lineEdit_Prototxt"));

        gridLayout->addWidget(lineEdit_Prototxt, 2, 1, 1, 3);

        lineEdit_Model = new QLineEdit(groupBox);
        lineEdit_Model->setObjectName(QStringLiteral("lineEdit_Model"));

        gridLayout->addWidget(lineEdit_Model, 0, 1, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 8, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(FeatureExp);
        QObject::connect(pushButton_BrowserModel, SIGNAL(clicked()), FeatureExp, SLOT(Browser1()));
        QObject::connect(pushButton_BrowserProto, SIGNAL(clicked()), FeatureExp, SLOT(Browser2()));
        QObject::connect(pushButton_BrowserPath, SIGNAL(clicked()), FeatureExp, SLOT(Browser3()));
        QObject::connect(pushButton_Verify, SIGNAL(clicked()), FeatureExp, SLOT(Verification()));
        QObject::connect(pushButton_DoExp, SIGNAL(clicked()), FeatureExp, SLOT(DoFeatureExp()));

        QMetaObject::connectSlotsByName(FeatureExp);
    } // setupUi

    void retranslateUi(QWidget *FeatureExp)
    {
        FeatureExp->setWindowTitle(QApplication::translate("FeatureExp", "\347\211\271\345\276\201\345\257\274\345\207\272", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FeatureExp", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        label_8->setText(QApplication::translate("FeatureExp", "\346\225\260\346\215\256\345\272\223\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("FeatureExp", "\351\242\204\350\256\255\347\273\203\347\275\221\347\273\234:", Q_NULLPTR));
        label_6->setText(QApplication::translate("FeatureExp", "mini_batches:", Q_NULLPTR));
        label_4->setText(QApplication::translate("FeatureExp", "\351\242\204\345\257\274\345\207\272\347\232\204\345\261\202:", Q_NULLPTR));
        pushButton_DoExp->setText(QApplication::translate("FeatureExp", "\346\211\247\350\241\214", Q_NULLPTR));
        pushButton_BrowserPath->setText(QApplication::translate("FeatureExp", "\346\265\217\350\247\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("FeatureExp", "\347\275\221\347\273\234\347\273\223\346\236\204\351\203\250\347\275\262\346\217\217\350\277\260:", Q_NULLPTR));
        pushButton_Verify->setText(QApplication::translate("FeatureExp", "\351\252\214\350\257\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("FeatureExp", "\345\257\274\345\207\272\344\275\215\347\275\256:", Q_NULLPTR));
        pushButton_BrowserModel->setText(QApplication::translate("FeatureExp", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_BrowserProto->setText(QApplication::translate("FeatureExp", "\346\265\217\350\247\210", Q_NULLPTR));
        radioButton_leveldb->setText(QApplication::translate("FeatureExp", "leveldb", Q_NULLPTR));
        radioButton_lmdb->setText(QApplication::translate("FeatureExp", "lmdb", Q_NULLPTR));
        comboBox_cupgpu->clear();
        comboBox_cupgpu->insertItems(0, QStringList()
         << QApplication::translate("FeatureExp", "CPU", Q_NULLPTR)
         << QApplication::translate("FeatureExp", "GPU", Q_NULLPTR)
        );
        label->setText(QApplication::translate("FeatureExp", "\350\277\220\350\241\214\351\200\211\351\241\271:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FeatureExp: public Ui_FeatureExp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATUREEXP_H
