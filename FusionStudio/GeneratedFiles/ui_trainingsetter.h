/********************************************************************************
** Form generated from reading UI file 'trainingsetter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININGSETTER_H
#define UI_TRAININGSETTER_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainingSetter
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Execute;
    QPushButton *pushButton_SaveToSolver;
    QPushButton *pushButton_SolverBrowser;
    QPushButton *pushButton_ReadFormSolver;
    QLabel *label;
    QLineEdit *lineEdit_solverFilePath;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_momentum;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_test_iter;
    QLineEdit *lineEdit_test_interval;
    QLabel *label_12;
    QLineEdit *lineEdit_snapshot_prefix;
    QLineEdit *lineEdit_weight_decay;
    QLabel *label_7;
    QLabel *label_15;
    QLineEdit *lineEdit_net;
    QLabel *label_16;
    QComboBox *comboBox_solver_mode;
    QLabel *label_14;
    QPushButton *pushButton_NetBrowser;
    QPushButton *pushButton_SnapBrowser;
    QLineEdit *lineEdit_snapshot;
    QLineEdit *lineEdit_max_iter;
    QLineEdit *lineEdit_display;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit_stepsize;
    QComboBox *comboBox_lr_policy;
    QLineEdit *lineEdit_gamma;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *lineEdit_base_lr;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *lineEdit_stepvalue;
    QLineEdit *lineEdit_power;
    QLabel *label_5;

    void setupUi(QWidget *TrainingSetter)
    {
        if (TrainingSetter->objectName().isEmpty())
            TrainingSetter->setObjectName(QStringLiteral("TrainingSetter"));
        TrainingSetter->resize(735, 442);
        gridLayout = new QGridLayout(TrainingSetter);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Execute = new QPushButton(TrainingSetter);
        pushButton_Execute->setObjectName(QStringLiteral("pushButton_Execute"));

        gridLayout->addWidget(pushButton_Execute, 3, 5, 1, 1);

        pushButton_SaveToSolver = new QPushButton(TrainingSetter);
        pushButton_SaveToSolver->setObjectName(QStringLiteral("pushButton_SaveToSolver"));

        gridLayout->addWidget(pushButton_SaveToSolver, 3, 4, 1, 1);

        pushButton_SolverBrowser = new QPushButton(TrainingSetter);
        pushButton_SolverBrowser->setObjectName(QStringLiteral("pushButton_SolverBrowser"));

        gridLayout->addWidget(pushButton_SolverBrowser, 3, 2, 1, 1);

        pushButton_ReadFormSolver = new QPushButton(TrainingSetter);
        pushButton_ReadFormSolver->setObjectName(QStringLiteral("pushButton_ReadFormSolver"));

        gridLayout->addWidget(pushButton_ReadFormSolver, 3, 3, 1, 1);

        label = new QLabel(TrainingSetter);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        lineEdit_solverFilePath = new QLineEdit(TrainingSetter);
        lineEdit_solverFilePath->setObjectName(QStringLiteral("lineEdit_solverFilePath"));

        gridLayout->addWidget(lineEdit_solverFilePath, 3, 1, 1, 1);

        groupBox = new QGroupBox(TrainingSetter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_momentum = new QLineEdit(groupBox);
        lineEdit_momentum->setObjectName(QStringLiteral("lineEdit_momentum"));

        gridLayout_2->addWidget(lineEdit_momentum, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 2, 2, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_test_iter = new QLineEdit(groupBox);
        lineEdit_test_iter->setObjectName(QStringLiteral("lineEdit_test_iter"));

        gridLayout_2->addWidget(lineEdit_test_iter, 0, 1, 1, 1);

        lineEdit_test_interval = new QLineEdit(groupBox);
        lineEdit_test_interval->setObjectName(QStringLiteral("lineEdit_test_interval"));

        gridLayout_2->addWidget(lineEdit_test_interval, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_12, 1, 2, 1, 1);

        lineEdit_snapshot_prefix = new QLineEdit(groupBox);
        lineEdit_snapshot_prefix->setObjectName(QStringLiteral("lineEdit_snapshot_prefix"));

        gridLayout_2->addWidget(lineEdit_snapshot_prefix, 3, 3, 1, 1);

        lineEdit_weight_decay = new QLineEdit(groupBox);
        lineEdit_weight_decay->setObjectName(QStringLiteral("lineEdit_weight_decay"));

        gridLayout_2->addWidget(lineEdit_weight_decay, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_15, 4, 0, 1, 1);

        lineEdit_net = new QLineEdit(groupBox);
        lineEdit_net->setObjectName(QStringLiteral("lineEdit_net"));

        gridLayout_2->addWidget(lineEdit_net, 4, 3, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_16, 4, 2, 1, 1);

        comboBox_solver_mode = new QComboBox(groupBox);
        comboBox_solver_mode->setObjectName(QStringLiteral("comboBox_solver_mode"));

        gridLayout_2->addWidget(comboBox_solver_mode, 4, 1, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_14, 3, 2, 1, 1);

        pushButton_NetBrowser = new QPushButton(groupBox);
        pushButton_NetBrowser->setObjectName(QStringLiteral("pushButton_NetBrowser"));

        gridLayout_2->addWidget(pushButton_NetBrowser, 4, 4, 1, 1);

        pushButton_SnapBrowser = new QPushButton(groupBox);
        pushButton_SnapBrowser->setObjectName(QStringLiteral("pushButton_SnapBrowser"));

        gridLayout_2->addWidget(pushButton_SnapBrowser, 3, 4, 1, 1);

        lineEdit_snapshot = new QLineEdit(groupBox);
        lineEdit_snapshot->setObjectName(QStringLiteral("lineEdit_snapshot"));

        gridLayout_2->addWidget(lineEdit_snapshot, 2, 3, 1, 2);

        lineEdit_max_iter = new QLineEdit(groupBox);
        lineEdit_max_iter->setObjectName(QStringLiteral("lineEdit_max_iter"));

        gridLayout_2->addWidget(lineEdit_max_iter, 1, 3, 1, 2);

        lineEdit_display = new QLineEdit(groupBox);
        lineEdit_display->setObjectName(QStringLiteral("lineEdit_display"));

        gridLayout_2->addWidget(lineEdit_display, 0, 3, 1, 2);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_stepsize = new QLineEdit(groupBox_2);
        lineEdit_stepsize->setObjectName(QStringLiteral("lineEdit_stepsize"));

        gridLayout_3->addWidget(lineEdit_stepsize, 3, 1, 1, 1);

        comboBox_lr_policy = new QComboBox(groupBox_2);
        comboBox_lr_policy->setObjectName(QStringLiteral("comboBox_lr_policy"));

        gridLayout_3->addWidget(comboBox_lr_policy, 0, 1, 1, 5);

        lineEdit_gamma = new QLineEdit(groupBox_2);
        lineEdit_gamma->setObjectName(QStringLiteral("lineEdit_gamma"));

        gridLayout_3->addWidget(lineEdit_gamma, 2, 3, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 2, 4, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 2, 2, 1, 1);

        lineEdit_base_lr = new QLineEdit(groupBox_2);
        lineEdit_base_lr->setObjectName(QStringLiteral("lineEdit_base_lr"));

        gridLayout_3->addWidget(lineEdit_base_lr, 2, 1, 1, 1);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 3, 0, 1, 1);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_18, 3, 2, 1, 1);

        lineEdit_stepvalue = new QLineEdit(groupBox_2);
        lineEdit_stepvalue->setObjectName(QStringLiteral("lineEdit_stepvalue"));

        gridLayout_3->addWidget(lineEdit_stepvalue, 3, 3, 1, 1);

        lineEdit_power = new QLineEdit(groupBox_2);
        lineEdit_power->setObjectName(QStringLiteral("lineEdit_power"));

        gridLayout_3->addWidget(lineEdit_power, 2, 5, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 5, 0, 1, 5);


        gridLayout->addWidget(groupBox, 7, 0, 1, 7);


        retranslateUi(TrainingSetter);
        QObject::connect(pushButton_SolverBrowser, SIGNAL(clicked()), TrainingSetter, SLOT(BrowseSolver()));
        QObject::connect(pushButton_SnapBrowser, SIGNAL(clicked()), TrainingSetter, SLOT(BrowseSnapPath()));
        QObject::connect(pushButton_NetBrowser, SIGNAL(clicked()), TrainingSetter, SLOT(BrowseNet()));
        QObject::connect(pushButton_ReadFormSolver, SIGNAL(clicked()), TrainingSetter, SLOT(ReadSolver()));
        QObject::connect(comboBox_lr_policy, SIGNAL(currentIndexChanged(int)), TrainingSetter, SLOT(policyChange()));
        QObject::connect(pushButton_Execute, SIGNAL(clicked()), TrainingSetter, SLOT(ExecuteTraining()));
        QObject::connect(pushButton_SaveToSolver, SIGNAL(clicked()), TrainingSetter, SLOT(SaveSolver()));

        QMetaObject::connectSlotsByName(TrainingSetter);
    } // setupUi

    void retranslateUi(QWidget *TrainingSetter)
    {
        TrainingSetter->setWindowTitle(QApplication::translate("TrainingSetter", "\350\256\255\347\273\203\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_Execute->setText(QApplication::translate("TrainingSetter", "\346\211\247\350\241\214", Q_NULLPTR));
        pushButton_SaveToSolver->setText(QApplication::translate("TrainingSetter", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_SolverBrowser->setText(QApplication::translate("TrainingSetter", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_ReadFormSolver->setText(QApplication::translate("TrainingSetter", "\350\257\273\345\217\226", Q_NULLPTR));
        label->setText(QApplication::translate("TrainingSetter", "\350\256\255\347\273\203\351\205\215\347\275\256;", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TrainingSetter", "\350\256\255\347\273\203\351\205\215\347\275\256\350\257\246\346\203\205", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("TrainingSetter", "\344\270\212\344\270\200\346\254\241\347\232\204\346\242\257\345\272\246\345\200\274\345\234\250\346\234\254\346\254\241\346\242\257\345\272\246\344\270\213\351\231\215\344\270\255\347\232\204\346\235\203\351\207\215", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("TrainingSetter", "momentum: ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("TrainingSetter", "\346\257\217\350\256\255\347\273\203\345\244\232\345\260\221\346\254\241\350\277\233\350\241\214\344\270\200\346\254\241\347\275\221\347\273\234\345\277\253\347\205\247", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("TrainingSetter", "snapshot:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("TrainingSetter", "\346\257\217\350\256\255\347\273\203\345\244\232\345\260\221\346\254\241\345\234\250\347\273\210\347\253\257\346\230\276\347\244\272\344\270\200\346\254\241\344\277\241\346\201\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("TrainingSetter", "display:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("TrainingSetter", "\346\265\213\350\257\225\346\225\260\346\215\256\351\234\200\350\246\201\345\244\232\345\260\221\346\254\241\350\277\255\344\273\243\350\203\275\345\244\237\347\224\250\345\256\214,\344\270\216batch_size\344\271\213\347\247\257\346\230\257\346\265\213\350\257\225\346\240\267\346\234\254\347\232\204\346\200\273\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("TrainingSetter", "test_iter:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("TrainingSetter", "\346\257\217\350\256\255\347\273\203\345\244\232\345\260\221\345\274\240\345\233\276\347\211\207\350\277\233\350\241\214\344\270\200\346\254\241\346\265\213\350\257\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("TrainingSetter", "test_interval:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("TrainingSetter", "\346\234\200\345\244\247\350\277\255\344\273\243\346\254\241\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("TrainingSetter", "max_iter:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("TrainingSetter", "\346\235\203\351\207\215\350\241\260\345\207\217(\351\230\262\346\255\242\350\277\207\346\213\237\345\220\210)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("TrainingSetter", "weight_decay:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("TrainingSetter", "\350\277\220\350\241\214\346\250\241\345\274\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("TrainingSetter", "solver_mode:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("TrainingSetter", "\347\275\221\347\273\234\347\273\223\346\236\204\345\256\232\344\271\211\346\226\207\344\273\266\344\275\215\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("TrainingSetter", "net: ", Q_NULLPTR));
        comboBox_solver_mode->clear();
        comboBox_solver_mode->insertItems(0, QStringList()
         << QApplication::translate("TrainingSetter", "CPU", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "GPU", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("TrainingSetter", "\347\275\221\347\273\234\345\277\253\347\205\247\347\232\204\344\277\235\345\255\230\344\275\215\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("TrainingSetter", "snapshot_prefix:", Q_NULLPTR));
        pushButton_NetBrowser->setText(QApplication::translate("TrainingSetter", "\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_SnapBrowser->setText(QApplication::translate("TrainingSetter", "\346\265\217\350\247\210", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TrainingSetter", "\345\255\246\344\271\240\347\216\207\347\255\226\347\225\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("TrainingSetter", "\345\255\246\344\271\240\347\216\207\350\241\260\345\207\217\347\255\226\347\225\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("TrainingSetter", "lr_policy:", Q_NULLPTR));
        comboBox_lr_policy->clear();
        comboBox_lr_policy->insertItems(0, QStringList()
         << QApplication::translate("TrainingSetter", "fixed(\346\201\222\345\256\232\345\255\246\344\271\240\347\216\207)", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "step(base_lr * gamma ^ (floor(iter / stepsize)))", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "exp(base_lr * gamma ^ iter)", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "inv(base_lr * (1 + gamma * iter) ^ (- power))", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "multistep(\346\240\271\346\215\256stepvalue\346\233\264\346\226\260\347\232\204step\346\226\271\346\263\225)", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "poly(base_lr (1 - iter/max_iter) ^ (power))", Q_NULLPTR)
         << QApplication::translate("TrainingSetter", "sigmoid(base_lr ( 1/(1 + exp(-gamma * (iter - stepsize)))))", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("TrainingSetter", "power:", Q_NULLPTR));
        label_9->setText(QApplication::translate("TrainingSetter", "gamma:", Q_NULLPTR));
        label_17->setText(QApplication::translate("TrainingSetter", "stepsize:", Q_NULLPTR));
        label_18->setText(QApplication::translate("TrainingSetter", "stepvalue:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("TrainingSetter", "\345\237\272\347\241\200\345\255\246\344\271\240\347\216\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("TrainingSetter", "base_lr: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrainingSetter: public Ui_TrainingSetter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININGSETTER_H
