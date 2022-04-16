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
    ui->ProcessesTable->setItem(currentProcessID, 0, new QTableWidgetItem(QString::number(currentProcessID)));
    ui->ProcessesTable->setItem(currentProcessID, 1, new QTableWidgetItem(ui->BurstLengthSpinBox->text()));
    ui->ProcessesTable->setItem(currentProcessID, 2, new QTableWidgetItem(ui->ArrivalTimeSpinBox->text()));
    if (ui->SchedulerComboBox->currentIndex() == 2) ui->ProcessesTable->setItem(currentProcessID, 3, new QTableWidgetItem(ui->PrioritySpinBox->text()));
    else ui->ProcessesTable->setItem(currentProcessID, 3, new QTableWidgetItem(1));
    currentProcessID++;
}


void MainWindow::on_SubmitButton_clicked()
{
    std::vector<FCFS_process>FCFS_processes;
    std::vector<SJF_process>SJF_processes;
    std::vector<Priority_process>Priority_processes;
    std::vector<RoundRobin_process>RoundRobin_processes;
    GanntChart chart;
    switch(ui->SchedulerComboBox->currentIndex()) {
    case 0:
        //Extract Processes from table;
        chart = FCFS(FCFS_processes);
        break;
    case 1:
        //Extract Processes from table;
        //chart = SJF(SJF_processes, false);
        break;
    case 2:
        //Extract Processes from table;
        chart = Priority(Priority_processes, false);
        break;
    case 3:
        //Extract Processes from table;
        chart = RoundRobin(RoundRobin_processes, 10);
        break;
    }
    drawGanntChart(chart, ui->Chart);
}


void MainWindow::on_RemoveButton_clicked()
{
    ui->ProcessesTable->setRowCount(ui->ProcessesTable->rowCount()-1);
    currentProcessID--;
}

void drawGanntChart(GanntChart chart, QGraphicsView* drawingArea) {

}
