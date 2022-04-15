#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GanntChart.h"
#include "metrics.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "RoundRobin.h"

static void drawGanntChart(GanntChart chart, QGraphicsView* drawingArea);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SchedulerComboBox_currentIndexChanged(int index)
{
    switch(index) {
    case 0: //First Come First Serve
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumSpinBox->setEnabled(false);
        ui->PreemptiveCheckBox->setEnabled(false);
        ui->PriorityLabel->setEnabled(false);
        ui->PrioritySpinBox->setEnabled(false);
        break;
    case 1: //Shortest Job First
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumSpinBox->setEnabled(false);
        ui->PreemptiveCheckBox->setEnabled(true);
        ui->PriorityLabel->setEnabled(false);
        ui->PrioritySpinBox->setEnabled(false);
        break;
    case 2: //Priority
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumSpinBox->setEnabled(false);
        ui->PreemptiveCheckBox->setEnabled(true);
        ui->PriorityLabel->setEnabled(true);
        ui->PrioritySpinBox->setEnabled(true);
        break;
    case 3: //Round Robin
        ui->QuantumLabel->setEnabled(true);
        ui->QuantumSpinBox->setEnabled(true);
        ui->PreemptiveCheckBox->setEnabled(false);
        ui->PriorityLabel->setEnabled(false);
        ui->PrioritySpinBox->setEnabled(false);
        break;
    }
}


void MainWindow::on_InesrtButton_clicked()
{
    ui->ProcessesTable->setRowCount(ui->ProcessesTable->rowCount()+1);
    ui->ProcessesTable->itemAt(0 ,currentProcessID)->setText(QString::number(currentProcessID));
    ui->ProcessesTable->itemAt(1 ,currentProcessID)->setText(ui->PrioritySpinBox->text());
    ui->ProcessesTable->itemAt(2 ,currentProcessID)->setText(ui->BurstLengthSpinBox->text());
    if (ui->SchedulerComboBox->currentIndex() == 2) ui->ProcessesTable->itemAt(3 ,currentProcessID)->setText(ui->PrioritySpinBox->text());
    else ui->ProcessesTable->itemAt(3 ,currentProcessID)->setText("Not Applicable");
}


void MainWindow::on_SubmitButton_clicked()
{
    std::list<FCFS_process>FCFS_processes;
    std::list<SJF_process>SJF_processes;
    std::list<Priority_process>Priority_processes;
    std::list<RoundRobin_process>RoundRobin_processes;
    GanntChart chart;
    switch(ui->SchedulerComboBox->currentIndex()) {
    case 0:
        //Extract Processes from table;
        chart = FCFS(&FCFS_processes);
        break;
    case 1:
        //Extract Processes from table;
        chart = SJF(&SJF_processes);
        break;
    case 2:
        //Extract Processes from table;
        chart = Priority(&Priority_processes);
    case 3:
        //Extract Processes from table;
        chart = RoundRobin(&RoundRobin_processes);
    }
    drawGanntChart(chart, ui->Chart);
}


void MainWindow::on_RemoveButton_clicked()
{
    ui->ProcessesTable->setRowCount(ui->ProcessesTable->rowCount()-1);
}

void drawGanntChart(GanntChart chart, QGraphicsView* drawingArea) {

}
