/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *SchedulerComboBox;
    QSpinBox *QuantumSpinBox;
    QLabel *QuantumLabel;
    QSpinBox *BurstLengthSpinBox;
    QSpinBox *ArrivalTimeSpinBox;
    QSpinBox *PrioritySpinBox;
    QTableWidget *ProcessesTable;
    QLabel *AverageWaitingTimeLabel;
    QLabel *MaximumWaitingTimeLabel;
    QLabel *AverageTurnArounTimeLabel;
    QLabel *MaximumTurnArounTimeLabel;
    QLabel *AverageTurnArounTimeOutputLabel;
    QLabel *MaximumTurnArounTimeOutputLabel;
    QCheckBox *PreemptiveCheckBox;
    QPushButton *InesrtButton;
    QLabel *BurstLengthLabel;
    QLabel *ArrivalTimeLabel;
    QLabel *PriorityLabel;
    QLabel *AverageWaitingTimeOutputLabel;
    QLabel *MaximumWaitingTimeOutputLabel;
    QLabel *AverageResponseTimeLabel;
    QLabel *MaximumResponseTimeLabel;
    QLabel *AverageResponseTimeOutputLabel;
    QLabel *MaximumResponseTimeOutputLabel;
    QPushButton *SubmitButton;
    QPushButton *RemoveButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SchedulerComboBox = new QComboBox(centralwidget);
        SchedulerComboBox->addItem(QString());
        SchedulerComboBox->addItem(QString());
        SchedulerComboBox->addItem(QString());
        SchedulerComboBox->addItem(QString());
        SchedulerComboBox->setObjectName(QString::fromUtf8("SchedulerComboBox"));
        SchedulerComboBox->setGeometry(QRect(40, 40, 200, 30));
        QuantumSpinBox = new QSpinBox(centralwidget);
        QuantumSpinBox->setObjectName(QString::fromUtf8("QuantumSpinBox"));
        QuantumSpinBox->setEnabled(false);
        QuantumSpinBox->setGeometry(QRect(340, 40, 50, 30));
        QuantumSpinBox->setMinimum(1);
        QuantumSpinBox->setMaximum(9999);
        QuantumLabel = new QLabel(centralwidget);
        QuantumLabel->setObjectName(QString::fromUtf8("QuantumLabel"));
        QuantumLabel->setEnabled(false);
        QuantumLabel->setGeometry(QRect(270, 40, 60, 30));
        BurstLengthSpinBox = new QSpinBox(centralwidget);
        BurstLengthSpinBox->setObjectName(QString::fromUtf8("BurstLengthSpinBox"));
        BurstLengthSpinBox->setGeometry(QRect(130, 110, 50, 30));
        BurstLengthSpinBox->setMinimum(1);
        BurstLengthSpinBox->setMaximum(9999);
        ArrivalTimeSpinBox = new QSpinBox(centralwidget);
        ArrivalTimeSpinBox->setObjectName(QString::fromUtf8("ArrivalTimeSpinBox"));
        ArrivalTimeSpinBox->setGeometry(QRect(280, 110, 50, 30));
        ArrivalTimeSpinBox->setMinimum(0);
        ArrivalTimeSpinBox->setMaximum(9999);
        PrioritySpinBox = new QSpinBox(centralwidget);
        PrioritySpinBox->setObjectName(QString::fromUtf8("PrioritySpinBox"));
        PrioritySpinBox->setEnabled(true);
        PrioritySpinBox->setGeometry(QRect(430, 110, 50, 30));
        PrioritySpinBox->setMinimum(1);
        PrioritySpinBox->setMaximum(9999);
        ProcessesTable = new QTableWidget(centralwidget);
        if (ProcessesTable->columnCount() < 4)
            ProcessesTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ProcessesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ProcessesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ProcessesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ProcessesTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        ProcessesTable->setObjectName(QString::fromUtf8("ProcessesTable"));
        ProcessesTable->setGeometry(QRect(20, 160, 760, 150));
        ProcessesTable->setColumnCount(4);
        AverageWaitingTimeLabel = new QLabel(centralwidget);
        AverageWaitingTimeLabel->setObjectName(QString::fromUtf8("AverageWaitingTimeLabel"));
        AverageWaitingTimeLabel->setGeometry(QRect(50, 480, 140, 20));
        MaximumWaitingTimeLabel = new QLabel(centralwidget);
        MaximumWaitingTimeLabel->setObjectName(QString::fromUtf8("MaximumWaitingTimeLabel"));
        MaximumWaitingTimeLabel->setGeometry(QRect(50, 520, 140, 20));
        AverageTurnArounTimeLabel = new QLabel(centralwidget);
        AverageTurnArounTimeLabel->setObjectName(QString::fromUtf8("AverageTurnArounTimeLabel"));
        AverageTurnArounTimeLabel->setGeometry(QRect(300, 480, 160, 20));
        MaximumTurnArounTimeLabel = new QLabel(centralwidget);
        MaximumTurnArounTimeLabel->setObjectName(QString::fromUtf8("MaximumTurnArounTimeLabel"));
        MaximumTurnArounTimeLabel->setGeometry(QRect(300, 520, 160, 20));
        AverageTurnArounTimeOutputLabel = new QLabel(centralwidget);
        AverageTurnArounTimeOutputLabel->setObjectName(QString::fromUtf8("AverageTurnArounTimeOutputLabel"));
        AverageTurnArounTimeOutputLabel->setGeometry(QRect(470, 480, 63, 20));
        MaximumTurnArounTimeOutputLabel = new QLabel(centralwidget);
        MaximumTurnArounTimeOutputLabel->setObjectName(QString::fromUtf8("MaximumTurnArounTimeOutputLabel"));
        MaximumTurnArounTimeOutputLabel->setGeometry(QRect(470, 520, 63, 20));
        PreemptiveCheckBox = new QCheckBox(centralwidget);
        PreemptiveCheckBox->setObjectName(QString::fromUtf8("PreemptiveCheckBox"));
        PreemptiveCheckBox->setEnabled(false);
        PreemptiveCheckBox->setGeometry(QRect(270, 40, 100, 30));
        InesrtButton = new QPushButton(centralwidget);
        InesrtButton->setObjectName(QString::fromUtf8("InesrtButton"));
        InesrtButton->setGeometry(QRect(500, 110, 80, 30));
        BurstLengthLabel = new QLabel(centralwidget);
        BurstLengthLabel->setObjectName(QString::fromUtf8("BurstLengthLabel"));
        BurstLengthLabel->setGeometry(QRect(50, 110, 71, 30));
        ArrivalTimeLabel = new QLabel(centralwidget);
        ArrivalTimeLabel->setObjectName(QString::fromUtf8("ArrivalTimeLabel"));
        ArrivalTimeLabel->setGeometry(QRect(200, 110, 71, 30));
        PriorityLabel = new QLabel(centralwidget);
        PriorityLabel->setObjectName(QString::fromUtf8("PriorityLabel"));
        PriorityLabel->setEnabled(true);
        PriorityLabel->setGeometry(QRect(370, 110, 50, 30));
        AverageWaitingTimeOutputLabel = new QLabel(centralwidget);
        AverageWaitingTimeOutputLabel->setObjectName(QString::fromUtf8("AverageWaitingTimeOutputLabel"));
        AverageWaitingTimeOutputLabel->setGeometry(QRect(200, 480, 40, 20));
        MaximumWaitingTimeOutputLabel = new QLabel(centralwidget);
        MaximumWaitingTimeOutputLabel->setObjectName(QString::fromUtf8("MaximumWaitingTimeOutputLabel"));
        MaximumWaitingTimeOutputLabel->setGeometry(QRect(200, 520, 40, 20));
        AverageResponseTimeLabel = new QLabel(centralwidget);
        AverageResponseTimeLabel->setObjectName(QString::fromUtf8("AverageResponseTimeLabel"));
        AverageResponseTimeLabel->setGeometry(QRect(560, 480, 140, 16));
        MaximumResponseTimeLabel = new QLabel(centralwidget);
        MaximumResponseTimeLabel->setObjectName(QString::fromUtf8("MaximumResponseTimeLabel"));
        MaximumResponseTimeLabel->setGeometry(QRect(560, 520, 140, 16));
        AverageResponseTimeOutputLabel = new QLabel(centralwidget);
        AverageResponseTimeOutputLabel->setObjectName(QString::fromUtf8("AverageResponseTimeOutputLabel"));
        AverageResponseTimeOutputLabel->setGeometry(QRect(710, 480, 49, 16));
        MaximumResponseTimeOutputLabel = new QLabel(centralwidget);
        MaximumResponseTimeOutputLabel->setObjectName(QString::fromUtf8("MaximumResponseTimeOutputLabel"));
        MaximumResponseTimeOutputLabel->setGeometry(QRect(710, 520, 49, 16));
        SubmitButton = new QPushButton(centralwidget);
        SubmitButton->setObjectName(QString::fromUtf8("SubmitButton"));
        SubmitButton->setGeometry(QRect(700, 110, 80, 30));
        RemoveButton = new QPushButton(centralwidget);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));
        RemoveButton->setGeometry(QRect(600, 110, 80, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        SchedulerComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SchedulerComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "First Come First Serve", nullptr));
        SchedulerComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Shortest Job First", nullptr));
        SchedulerComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Priority", nullptr));
        SchedulerComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));

        QuantumLabel->setText(QCoreApplication::translate("MainWindow", "Quantum", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ProcessesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Process ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ProcessesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Burst Length", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ProcessesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Arrival Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = ProcessesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        AverageWaitingTimeLabel->setText(QCoreApplication::translate("MainWindow", "Average Waiting Time", nullptr));
        MaximumWaitingTimeLabel->setText(QCoreApplication::translate("MainWindow", "Maximum Waiting Time", nullptr));
        AverageTurnArounTimeLabel->setText(QCoreApplication::translate("MainWindow", "Average Turn Around Time", nullptr));
        MaximumTurnArounTimeLabel->setText(QCoreApplication::translate("MainWindow", "Maximum Turn Around Time", nullptr));
        AverageTurnArounTimeOutputLabel->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        MaximumTurnArounTimeOutputLabel->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        PreemptiveCheckBox->setText(QCoreApplication::translate("MainWindow", "Preemptive", nullptr));
        InesrtButton->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        BurstLengthLabel->setText(QCoreApplication::translate("MainWindow", "Burst Length", nullptr));
        ArrivalTimeLabel->setText(QCoreApplication::translate("MainWindow", "Arrival Time", nullptr));
        PriorityLabel->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        AverageWaitingTimeOutputLabel->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        MaximumWaitingTimeOutputLabel->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        AverageResponseTimeLabel->setText(QCoreApplication::translate("MainWindow", "Average Response Time", nullptr));
        MaximumResponseTimeLabel->setText(QCoreApplication::translate("MainWindow", "Maximum Response Time", nullptr));
        AverageResponseTimeOutputLabel->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        MaximumResponseTimeOutputLabel->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        SubmitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        RemoveButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
