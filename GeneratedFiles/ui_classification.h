/********************************************************************************
** Form generated from reading UI file 'classification.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSIFICATION_H
#define UI_CLASSIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Classification
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit_deploy;
    QPushButton *pushButton_Browser2;
    QPushButton *pushButton_Browser3;
    QPushButton *pushButton_Browser4;
    QPushButton *pushButton_Browser5;
    QLineEdit *lineEdit_caffemodel;
    QLineEdit *lineEdit_binaryproto;
    QLineEdit *lineEdit_labels;
    QLineEdit *lineEdit_img;
    QSlider *horizontalSlider;
    QPushButton *pushButton_DoClassification;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *pushButton_Browser1;
    QFrame *line;

    void setupUi(QWidget *Classification)
    {
        if (Classification->objectName().isEmpty())
            Classification->setObjectName(QStringLiteral("Classification"));
        Classification->resize(734, 415);
        gridLayout = new QGridLayout(Classification);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(Classification);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 2, 2);

        groupBox = new QGroupBox(Classification);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/FusionStudio/Resources/Dropbox_FUSION_128px_1060231_easyicon.net.ico")));

        gridLayout_2->addWidget(label_8, 14, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 13, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 13, 3, 1, 1);

        lineEdit_deploy = new QLineEdit(groupBox);
        lineEdit_deploy->setObjectName(QStringLiteral("lineEdit_deploy"));

        gridLayout_2->addWidget(lineEdit_deploy, 0, 2, 1, 2);

        pushButton_Browser2 = new QPushButton(groupBox);
        pushButton_Browser2->setObjectName(QStringLiteral("pushButton_Browser2"));

        gridLayout_2->addWidget(pushButton_Browser2, 2, 4, 1, 1);

        pushButton_Browser3 = new QPushButton(groupBox);
        pushButton_Browser3->setObjectName(QStringLiteral("pushButton_Browser3"));

        gridLayout_2->addWidget(pushButton_Browser3, 3, 4, 1, 1);

        pushButton_Browser4 = new QPushButton(groupBox);
        pushButton_Browser4->setObjectName(QStringLiteral("pushButton_Browser4"));

        gridLayout_2->addWidget(pushButton_Browser4, 5, 4, 1, 1);

        pushButton_Browser5 = new QPushButton(groupBox);
        pushButton_Browser5->setObjectName(QStringLiteral("pushButton_Browser5"));

        gridLayout_2->addWidget(pushButton_Browser5, 6, 4, 1, 1);

        lineEdit_caffemodel = new QLineEdit(groupBox);
        lineEdit_caffemodel->setObjectName(QStringLiteral("lineEdit_caffemodel"));

        gridLayout_2->addWidget(lineEdit_caffemodel, 2, 2, 1, 2);

        lineEdit_binaryproto = new QLineEdit(groupBox);
        lineEdit_binaryproto->setObjectName(QStringLiteral("lineEdit_binaryproto"));

        gridLayout_2->addWidget(lineEdit_binaryproto, 3, 2, 1, 2);

        lineEdit_labels = new QLineEdit(groupBox);
        lineEdit_labels->setObjectName(QStringLiteral("lineEdit_labels"));

        gridLayout_2->addWidget(lineEdit_labels, 5, 2, 1, 2);

        lineEdit_img = new QLineEdit(groupBox);
        lineEdit_img->setObjectName(QStringLiteral("lineEdit_img"));

        gridLayout_2->addWidget(lineEdit_img, 6, 2, 1, 2);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 9, 2, 1, 3);

        pushButton_DoClassification = new QPushButton(groupBox);
        pushButton_DoClassification->setObjectName(QStringLiteral("pushButton_DoClassification"));

        gridLayout_2->addWidget(pushButton_DoClassification, 12, 4, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 5, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 6, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 9, 1, 1, 1);

        pushButton_Browser1 = new QPushButton(groupBox);
        pushButton_Browser1->setObjectName(QStringLiteral("pushButton_Browser1"));

        gridLayout_2->addWidget(pushButton_Browser1, 0, 4, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 12, 0, 1, 4);


        gridLayout->addWidget(groupBox, 0, 3, 2, 2);


        retranslateUi(Classification);
        QObject::connect(pushButton_Browser1, SIGNAL(clicked()), Classification, SLOT(Browser1()));
        QObject::connect(pushButton_Browser2, SIGNAL(clicked()), Classification, SLOT(Browser2()));
        QObject::connect(pushButton_Browser3, SIGNAL(clicked()), Classification, SLOT(Browser3()));
        QObject::connect(pushButton_Browser4, SIGNAL(clicked()), Classification, SLOT(Browser4()));
        QObject::connect(pushButton_Browser5, SIGNAL(clicked()), Classification, SLOT(Browser5()));
        QObject::connect(pushButton_DoClassification, SIGNAL(clicked()), Classification, SLOT(DoClassification()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), Classification, SLOT(ZoomImage()));

        QMetaObject::connectSlotsByName(Classification);
    } // setupUi

    void retranslateUi(QWidget *Classification)
    {
        Classification->setWindowTitle(QApplication::translate("Classification", "\345\210\206\347\261\273\346\265\213\350\257\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Classification", "\345\217\202\346\225\260\351\200\211\346\213\251", Q_NULLPTR));
        label_8->setText(QString());
        pushButton_Browser2->setText(QApplication::translate("Classification", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_Browser3->setText(QApplication::translate("Classification", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_Browser4->setText(QApplication::translate("Classification", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_Browser5->setText(QApplication::translate("Classification", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_DoClassification->setText(QApplication::translate("Classification", "\346\211\247\350\241\214", Q_NULLPTR));
        label->setText(QApplication::translate("Classification", "\351\203\250\347\275\262\346\217\217\350\277\260:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Classification", "\351\242\204\350\256\255\347\273\203\347\275\221\347\273\234:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Classification", "\345\233\276\347\211\207\345\235\207\345\200\274\346\226\207\344\273\266:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Classification", "\346\240\207\347\255\276\350\276\236\345\205\270:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Classification", "\351\200\211\346\213\251\345\233\276\347\211\207:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Classification", "\347\274\251\346\224\276:", Q_NULLPTR));
        pushButton_Browser1->setText(QApplication::translate("Classification", "\346\265\217\350\247\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Classification: public Ui_Classification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSIFICATION_H
