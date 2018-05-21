/********************************************************************************
** Form generated from reading UI file 'browsedatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEDATABASE_H
#define UI_BROWSEDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrowseDatabase
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButton_lmdb;
    QRadioButton *radioButton_leveldb;
    QSlider *zoomSlider;
    QLineEdit *lineEdit;
    QPushButton *pushButton_NextImage;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QCheckBox *checkBox_ForcedDecoding;

    void setupUi(QWidget *BrowseDatabase)
    {
        if (BrowseDatabase->objectName().isEmpty())
            BrowseDatabase->setObjectName(QStringLiteral("BrowseDatabase"));
        BrowseDatabase->resize(572, 398);
        gridLayout = new QGridLayout(BrowseDatabase);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_lmdb = new QRadioButton(BrowseDatabase);
        radioButton_lmdb->setObjectName(QStringLiteral("radioButton_lmdb"));

        gridLayout->addWidget(radioButton_lmdb, 0, 1, 1, 1);

        radioButton_leveldb = new QRadioButton(BrowseDatabase);
        radioButton_leveldb->setObjectName(QStringLiteral("radioButton_leveldb"));

        gridLayout->addWidget(radioButton_leveldb, 0, 4, 1, 1);

        zoomSlider = new QSlider(BrowseDatabase);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        zoomSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(zoomSlider, 0, 8, 1, 1);

        lineEdit = new QLineEdit(BrowseDatabase);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 2, 8, 1, 1);

        pushButton_NextImage = new QPushButton(BrowseDatabase);
        pushButton_NextImage->setObjectName(QStringLiteral("pushButton_NextImage"));

        gridLayout->addWidget(pushButton_NextImage, 2, 7, 1, 1);

        pushButton = new QPushButton(BrowseDatabase);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 7, 1, 1);

        graphicsView = new QGraphicsView(BrowseDatabase);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 5, 0, 1, 14);

        checkBox_ForcedDecoding = new QCheckBox(BrowseDatabase);
        checkBox_ForcedDecoding->setObjectName(QStringLiteral("checkBox_ForcedDecoding"));

        gridLayout->addWidget(checkBox_ForcedDecoding, 2, 1, 1, 1);


        retranslateUi(BrowseDatabase);
        QObject::connect(pushButton, SIGNAL(clicked()), BrowseDatabase, SLOT(LoadDatabase()));
        QObject::connect(pushButton_NextImage, SIGNAL(clicked()), BrowseDatabase, SLOT(Nextimage()));
        QObject::connect(zoomSlider, SIGNAL(valueChanged(int)), BrowseDatabase, SLOT(ZoomImage()));
        QObject::connect(checkBox_ForcedDecoding, SIGNAL(clicked()), BrowseDatabase, SLOT(CrashWarning()));

        QMetaObject::connectSlotsByName(BrowseDatabase);
    } // setupUi

    void retranslateUi(QWidget *BrowseDatabase)
    {
        BrowseDatabase->setWindowTitle(QApplication::translate("BrowseDatabase", "BrowseDatabase", Q_NULLPTR));
        radioButton_lmdb->setText(QApplication::translate("BrowseDatabase", "lmdb", Q_NULLPTR));
        radioButton_leveldb->setText(QApplication::translate("BrowseDatabase", "leveldb", Q_NULLPTR));
        pushButton_NextImage->setText(QApplication::translate("BrowseDatabase", "\344\270\213\344\270\200\345\274\240", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BrowseDatabase", "\345\212\240\350\275\275\346\225\260\346\215\256\351\233\206", Q_NULLPTR));
        checkBox_ForcedDecoding->setText(QApplication::translate("BrowseDatabase", "\345\274\272\345\210\266\350\247\243\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrowseDatabase: public Ui_BrowseDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEDATABASE_H
