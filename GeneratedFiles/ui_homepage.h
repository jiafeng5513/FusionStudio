/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QCommandLinkButton *commandLinkButton_3;
    QLabel *label_3;
    QLabel *label;
    QCommandLinkButton *commandLinkButton_4;
    QLabel *label_2;
    QCommandLinkButton *commandLinkButton;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButton_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->resize(477, 298);
        gridLayout = new QGridLayout(HomePage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 5, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 6, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        commandLinkButton_3 = new QCommandLinkButton(HomePage);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));

        gridLayout->addWidget(commandLinkButton_3, 5, 2, 1, 1);

        label_3 = new QLabel(HomePage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/FusionStudio/Resources/Angel_Smiley_128px_1177055_easyicon.net.png")));

        gridLayout->addWidget(label_3, 4, 1, 3, 1);

        label = new QLabel(HomePage);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/FusionStudio/Resources/Dropbox_FUSION_128px_1060231_easyicon.net.ico")));

        gridLayout->addWidget(label, 1, 1, 3, 1);

        commandLinkButton_4 = new QCommandLinkButton(HomePage);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));

        gridLayout->addWidget(commandLinkButton_4, 6, 2, 1, 1);

        label_2 = new QLabel(HomePage);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAutoFillBackground(false);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        commandLinkButton = new QCommandLinkButton(HomePage);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));

        gridLayout->addWidget(commandLinkButton, 3, 2, 1, 1);

        label_4 = new QLabel(HomePage);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        commandLinkButton_2 = new QCommandLinkButton(HomePage);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));

        gridLayout->addWidget(commandLinkButton_2, 4, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 2, 1, 1);


        retranslateUi(HomePage);
        QObject::connect(commandLinkButton, SIGNAL(clicked()), HomePage, SLOT(LinkToAuthor()));
        QObject::connect(commandLinkButton_2, SIGNAL(clicked()), HomePage, SLOT(LinkToCaffe()));
        QObject::connect(commandLinkButton_3, SIGNAL(clicked()), HomePage, SLOT(HelpViewer()));
        QObject::connect(commandLinkButton_4, SIGNAL(clicked()), HomePage, SLOT(About()));

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "\345\274\200\345\247\213", Q_NULLPTR));
        commandLinkButton_3->setText(QApplication::translate("HomePage", "\346\237\245\347\234\213\345\270\256\345\212\251", Q_NULLPTR));
        label_3->setText(QString());
        label->setText(QString());
        commandLinkButton_4->setText(QApplication::translate("HomePage", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("HomePage", "By-\345\244\251\344\275\277\345\276\256\347\247\257\345\210\206\345\267\245\344\275\234\345\256\244", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("HomePage", "\350\201\224\347\263\273\344\275\234\350\200\205", Q_NULLPTR));
        label_4->setText(QApplication::translate("HomePage", "\344\270\200\344\270\252\344\270\215\347\237\245\346\211\200\344\272\221\347\232\204\345\245\207\346\200\252\347\250\213\345\272\217", Q_NULLPTR));
        commandLinkButton_2->setText(QApplication::translate("HomePage", "Caffe\345\256\230\346\226\271\347\275\221\347\253\231", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
