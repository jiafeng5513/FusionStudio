/********************************************************************************
** Form generated from reading UI file 'convertimage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTIMAGE_H
#define UI_CONVERTIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertImage
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBox_isCheck_size;
    QPushButton *pushButton_Default;
    QLabel *label_1;
    QLabel *label_4;
    QCheckBox *checkBox_isGray;
    QCheckBox *checkBox_isShuffle;
    QLabel *label_2;
    QPushButton *pushButton_BrowserRootDir;
    QLabel *label_3;
    QPushButton *pushButton_BrowserFileList;
    QLabel *label_6;
    QCheckBox *checkBox_isEncoded;
    QPushButton *pushButton_BrowserOutputDir;
    QPushButton *pushButton_DoConvert;
    QLabel *label_5;
    QLineEdit *lineEdit_resize_width;
    QLineEdit *lineEdit_RootDir;
    QLineEdit *lineEdit_ImgFileList;
    QLineEdit *lineEdit_OutputDir;
    QLineEdit *lineEdit_DBName;
    QLineEdit *lineEdit_resize_height;
    QRadioButton *radioButton_Leveldb;
    QRadioButton *radioButton_Lmdb;
    QLineEdit *lineEdit_encode_type;
    QLabel *label_7;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QWidget *ConvertImage)
    {
        if (ConvertImage->objectName().isEmpty())
            ConvertImage->setObjectName(QStringLiteral("ConvertImage"));
        ConvertImage->resize(737, 356);
        gridLayout = new QGridLayout(ConvertImage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox_isCheck_size = new QCheckBox(ConvertImage);
        checkBox_isCheck_size->setObjectName(QStringLiteral("checkBox_isCheck_size"));

        gridLayout->addWidget(checkBox_isCheck_size, 5, 5, 1, 1);

        pushButton_Default = new QPushButton(ConvertImage);
        pushButton_Default->setObjectName(QStringLiteral("pushButton_Default"));

        gridLayout->addWidget(pushButton_Default, 7, 5, 1, 1);

        label_1 = new QLabel(ConvertImage);
        label_1->setObjectName(QStringLiteral("label_1"));

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_4 = new QLabel(ConvertImage);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        checkBox_isGray = new QCheckBox(ConvertImage);
        checkBox_isGray->setObjectName(QStringLiteral("checkBox_isGray"));

        gridLayout->addWidget(checkBox_isGray, 4, 7, 1, 1);

        checkBox_isShuffle = new QCheckBox(ConvertImage);
        checkBox_isShuffle->setObjectName(QStringLiteral("checkBox_isShuffle"));

        gridLayout->addWidget(checkBox_isShuffle, 4, 5, 1, 1);

        label_2 = new QLabel(ConvertImage);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton_BrowserRootDir = new QPushButton(ConvertImage);
        pushButton_BrowserRootDir->setObjectName(QStringLiteral("pushButton_BrowserRootDir"));

        gridLayout->addWidget(pushButton_BrowserRootDir, 1, 7, 1, 1);

        label_3 = new QLabel(ConvertImage);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pushButton_BrowserFileList = new QPushButton(ConvertImage);
        pushButton_BrowserFileList->setObjectName(QStringLiteral("pushButton_BrowserFileList"));

        gridLayout->addWidget(pushButton_BrowserFileList, 0, 7, 1, 1);

        label_6 = new QLabel(ConvertImage);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        checkBox_isEncoded = new QCheckBox(ConvertImage);
        checkBox_isEncoded->setObjectName(QStringLiteral("checkBox_isEncoded"));

        gridLayout->addWidget(checkBox_isEncoded, 5, 7, 1, 1);

        pushButton_BrowserOutputDir = new QPushButton(ConvertImage);
        pushButton_BrowserOutputDir->setObjectName(QStringLiteral("pushButton_BrowserOutputDir"));

        gridLayout->addWidget(pushButton_BrowserOutputDir, 2, 7, 1, 1);

        pushButton_DoConvert = new QPushButton(ConvertImage);
        pushButton_DoConvert->setObjectName(QStringLiteral("pushButton_DoConvert"));

        gridLayout->addWidget(pushButton_DoConvert, 7, 7, 1, 1);

        label_5 = new QLabel(ConvertImage);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_resize_width = new QLineEdit(ConvertImage);
        lineEdit_resize_width->setObjectName(QStringLiteral("lineEdit_resize_width"));
        lineEdit_resize_width->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_resize_width, 4, 4, 1, 1);

        lineEdit_RootDir = new QLineEdit(ConvertImage);
        lineEdit_RootDir->setObjectName(QStringLiteral("lineEdit_RootDir"));

        gridLayout->addWidget(lineEdit_RootDir, 1, 4, 1, 2);

        lineEdit_ImgFileList = new QLineEdit(ConvertImage);
        lineEdit_ImgFileList->setObjectName(QStringLiteral("lineEdit_ImgFileList"));

        gridLayout->addWidget(lineEdit_ImgFileList, 0, 4, 1, 2);

        lineEdit_OutputDir = new QLineEdit(ConvertImage);
        lineEdit_OutputDir->setObjectName(QStringLiteral("lineEdit_OutputDir"));

        gridLayout->addWidget(lineEdit_OutputDir, 2, 4, 1, 2);

        lineEdit_DBName = new QLineEdit(ConvertImage);
        lineEdit_DBName->setObjectName(QStringLiteral("lineEdit_DBName"));

        gridLayout->addWidget(lineEdit_DBName, 3, 4, 1, 2);

        lineEdit_resize_height = new QLineEdit(ConvertImage);
        lineEdit_resize_height->setObjectName(QStringLiteral("lineEdit_resize_height"));

        gridLayout->addWidget(lineEdit_resize_height, 5, 4, 1, 1);

        radioButton_Leveldb = new QRadioButton(ConvertImage);
        radioButton_Leveldb->setObjectName(QStringLiteral("radioButton_Leveldb"));

        gridLayout->addWidget(radioButton_Leveldb, 6, 7, 1, 1);

        radioButton_Lmdb = new QRadioButton(ConvertImage);
        radioButton_Lmdb->setObjectName(QStringLiteral("radioButton_Lmdb"));

        gridLayout->addWidget(radioButton_Lmdb, 6, 5, 1, 1);

        lineEdit_encode_type = new QLineEdit(ConvertImage);
        lineEdit_encode_type->setObjectName(QStringLiteral("lineEdit_encode_type"));

        gridLayout->addWidget(lineEdit_encode_type, 6, 4, 1, 1);

        label_7 = new QLabel(ConvertImage);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        progressBar = new QProgressBar(ConvertImage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 7, 4, 1, 1);

        label = new QLabel(ConvertImage);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 7, 0, 1, 1);


        retranslateUi(ConvertImage);
        QObject::connect(pushButton_BrowserFileList, SIGNAL(clicked()), ConvertImage, SLOT(Browser1()));
        QObject::connect(pushButton_BrowserRootDir, SIGNAL(clicked()), ConvertImage, SLOT(Browser2()));
        QObject::connect(pushButton_BrowserOutputDir, SIGNAL(clicked()), ConvertImage, SLOT(Browser3()));
        QObject::connect(pushButton_Default, SIGNAL(clicked()), ConvertImage, SLOT(SetDefault()));
        QObject::connect(pushButton_DoConvert, SIGNAL(clicked()), ConvertImage, SLOT(DoConvert()));

        QMetaObject::connectSlotsByName(ConvertImage);
    } // setupUi

    void retranslateUi(QWidget *ConvertImage)
    {
        ConvertImage->setWindowTitle(QApplication::translate("ConvertImage", "ConvertImage", Q_NULLPTR));
        checkBox_isCheck_size->setText(QApplication::translate("ConvertImage", "\345\260\272\345\257\270\345\275\222\344\270\200\346\243\200\346\237\245", Q_NULLPTR));
        pushButton_Default->setText(QApplication::translate("ConvertImage", "\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        label_1->setText(QApplication::translate("ConvertImage", "\346\226\207\344\273\266\345\210\227\350\241\250:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConvertImage", "\350\276\223\345\207\272\346\225\260\346\215\256\345\272\223\345\220\215:", Q_NULLPTR));
        checkBox_isGray->setText(QApplication::translate("ConvertImage", "\350\275\254\346\215\242\344\270\272\347\201\260\345\272\246\345\233\276", Q_NULLPTR));
        checkBox_isShuffle->setText(QApplication::translate("ConvertImage", "\351\232\217\346\234\272\350\260\203\346\225\264\351\241\272\345\272\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConvertImage", "\345\233\276\347\211\207\351\233\206\346\240\271\347\233\256\345\275\225:", Q_NULLPTR));
        pushButton_BrowserRootDir->setText(QApplication::translate("ConvertImage", "\346\265\217\350\247\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConvertImage", "\350\276\223\345\207\272\347\233\256\345\275\225:", Q_NULLPTR));
        pushButton_BrowserFileList->setText(QApplication::translate("ConvertImage", "\346\265\217\350\247\210", Q_NULLPTR));
        label_6->setText(QApplication::translate("ConvertImage", "\350\260\203\346\225\264\345\233\276\347\211\207\351\253\230\345\272\246\344\270\272:", Q_NULLPTR));
        checkBox_isEncoded->setText(QApplication::translate("ConvertImage", "\347\275\256\345\205\245\345\233\276\347\211\207\347\274\226\347\240\201", Q_NULLPTR));
        pushButton_BrowserOutputDir->setText(QApplication::translate("ConvertImage", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_DoConvert->setText(QApplication::translate("ConvertImage", "\350\275\254\346\215\242", Q_NULLPTR));
        label_5->setText(QApplication::translate("ConvertImage", "\350\260\203\346\225\264\345\233\276\347\211\207\345\256\275\345\272\246\344\270\272:", Q_NULLPTR));
        radioButton_Leveldb->setText(QApplication::translate("ConvertImage", "LevelDb", Q_NULLPTR));
        radioButton_Lmdb->setText(QApplication::translate("ConvertImage", "LmDb", Q_NULLPTR));
        label_7->setText(QApplication::translate("ConvertImage", "\347\274\226\347\240\201\347\261\273\345\236\213:", Q_NULLPTR));
        label->setText(QApplication::translate("ConvertImage", "\350\277\233\345\272\246:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConvertImage: public Ui_ConvertImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTIMAGE_H
