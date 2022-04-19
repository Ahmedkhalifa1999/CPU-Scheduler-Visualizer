#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GanntChart.h"
#include "metrics.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "RoundRobin.h"
#include "altPriority.h"
#include "altSJF.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->QuantumLabel->setEnabled(false);
    ui->QuantumLabel->hide();
    ui->QuantumSpinBox->setEnabled(false);
    ui->QuantumSpinBox->hide();
    ui->PreemptiveCheckBox->setEnabled(false);
    ui->PreemptiveCheckBox->hide();
    ui->PriorityLabel->setEnabled(false);
    ui->PriorityLabel->hide();
    ui->PrioritySpinBox->setEnabled(false);
    ui->PrioritySpinBox->hide();
    ui->ProcessesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Chart = new ChartArea(this);
    Chart->setGeometry(40, 330, 700, 120);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Chart;
}


void MainWindow::on_SchedulerComboBox_currentIndexChanged(int index)
{
    switch(index) {
    case 0: //First Come First Serve
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumLabel->hide();
        ui->QuantumSpinBox->setEnabled(false);
        ui->QuantumSpinBox->hide();
        ui->PreemptiveCheckBox->setEnabled(false);
        ui->PreemptiveCheckBox->hide();
        ui->PriorityLabel->setEnabled(false);
        ui->PriorityLabel->hide();
        ui->PrioritySpinBox->setEnabled(false);
        ui->PrioritySpinBox->hide();
        break;
    case 1: //Shortest Job First
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumLabel->hide();
        ui->QuantumSpinBox->setEnabled(false);
        ui->QuantumSpinBox->hide();
        ui->PreemptiveCheckBox->setEnabled(true);
        ui->PreemptiveCheckBox->show();
        ui->PriorityLabel->setEnabled(false);
        ui->PriorityLabel->hide();
        ui->PrioritySpinBox->setEnabled(false);
        ui->PrioritySpinBox->hide();
        break;
    case 2: //Priority
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumLabel->hide();
        ui->QuantumSpinBox->setEnabled(false);
        ui->QuantumSpinBox->hide();
        ui->PreemptiveCheckBox->setEnabled(true);
        ui->PreemptiveCheckBox->show();
        ui->PriorityLabel->setEnabled(true);
        ui->PriorityLabel->show();
        ui->PrioritySpinBox->setEnabled(true);
        ui->PrioritySpinBox->show();
        break;
    case 3: //Round Robin
        ui->QuantumLabel->setEnabled(true);
        ui->QuantumLabel->show();
        ui->QuantumSpinBox->setEnabled(true);
        ui->QuantumSpinBox->show();
        ui->PreemptiveCheckBox->setEnabled(false);
        ui->PreemptiveCheckBox->hide();
        ui->PriorityLabel->setEnabled(false);
        ui->PriorityLabel->hide();
        ui->PrioritySpinBox->setEnabled(false);
        ui->PrioritySpinBox->hide();
        break;
    }
}


void MainWindow::on_InesrtButton_clicked()
{
    ui->ProcessesTable->setRowCount(ui->ProcessesTable->rowCount()+1);
    ui->ProcessesTable->setItem(currentProcessID-1, 0, new QTableWidgetItem(QString::number(currentProcessID)));
    ui->ProcessesTable->setItem(currentProcessID-1, 1, new QTableWidgetItem(ui->BurstLengthSpinBox->text()));
    ui->ProcessesTable->setItem(currentProcessID-1, 2, new QTableWidgetItem(ui->ArrivalTimeSpinBox->text()));
    ui->ProcessesTable->setItem(currentProcessID-1, 3, new QTableWidgetItem(ui->PrioritySpinBox->text()));
    if (ui->SchedulerComboBox->currentIndex() == 2) ui->ProcessesTable->setItem(currentProcessID-1, 3, new QTableWidgetItem(ui->PrioritySpinBox->text()));
    processes.push_back({currentProcessID,
                         static_cast<unsigned int>(ui->ArrivalTimeSpinBox->value()),
                         static_cast<unsigned int>(ui->BurstLengthSpinBox->value()),
                         static_cast<unsigned int>(ui->PrioritySpinBox->value())});
    currentProcessID++;
}


void MainWindow::on_SubmitButton_clicked()
{
    GanntChart chart;
    switch(ui->SchedulerComboBox->currentIndex()) {
    case 0:
        chart = FCFS(processes);
        break;
    case 1:
        chart = SJF(processes, ui->PreemptiveCheckBox->isChecked());
        break;
    case 2:
        chart = Priority(processes, ui->PreemptiveCheckBox->isChecked());
        break;
    case 3:
        chart = RoundRobin(processes, ui->QuantumSpinBox->value());
        break;
    case 4:
        chart = altPriority(processes, ui->PreemptiveCheckBox->isChecked());
        break;
    case 5:
        chart = altSJF(processes, ui->PreemptiveCheckBox->isChecked());
        break;
    }
    Chart->timeline = chart;
    Chart->repaint();
    metrics calculated = calculateMetrics(chart, processes);
    ui->AverageResponseTimeOutputLabel->setText(QString::number(calculated.averageResponseTime, 'f', 4));
    ui->MaximumResponseTimeOutputLabel->setText(QString::number(calculated.maximumResponseTime, 'f', 4));
    ui->AverageTurnArounTimeOutputLabel->setText(QString::number(calculated.averageTurnAroundTime, 'f', 4));
    ui->MaximumTurnArounTimeOutputLabel->setText(QString::number(calculated.maximumTurnAroundTime, 'f', 4));
    ui->AverageWaitingTimeOutputLabel->setText(QString::number(calculated.averageWaitingTime, 'f', 4));
    ui->MaximumWaitingTimeOutputLabel->setText(QString::number(calculated.maximumWaitingTime, 'f', 4));
}


void MainWindow::on_RemoveButton_clicked()
{
    if (currentProcessID > 1){
        ui->ProcessesTable->setRowCount(ui->ProcessesTable->rowCount()-1);
        processes.pop_back();
        currentProcessID--;
    }
}

