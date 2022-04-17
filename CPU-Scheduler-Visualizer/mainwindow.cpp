#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GanntChart.h"
#include "metrics.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "RoundRobin.h"

static void drawGanntChart(const GanntChart &chart, Ui::MainWindow* ui);

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
    }
    drawGanntChart(chart, ui);
    metrics calculated = calculateMetrics(chart, processes);
    ui->AverageResponseTimeOutputLabel->setText(QString::number(calculated.averageResponseTime, 'g', 2));
    ui->MaximumResponseTimeOutputLabel->setText(QString::number(calculated.maximumResponseTime, 'g', 2));
    ui->AverageTurnArounTimeOutputLabel->setText(QString::number(calculated.averageTurnAroundTime, 'g', 2));
    ui->MaximumTurnArounTimeOutputLabel->setText(QString::number(calculated.maximumTurnAroundTime, 'g', 2));
    ui->AverageWaitingTimeOutputLabel->setText(QString::number(calculated.averageWaitingTime, 'g', 2));
    ui->MaximumWaitingTimeOutputLabel->setText(QString::number(calculated.maximumWaitingTime, 'g', 2));
}


void MainWindow::on_RemoveButton_clicked()
{
    ui->ProcessesTable->setRowCount(ui->ProcessesTable->rowCount()-1);
    processes.pop_back();
    currentProcessID--;
}

static void drawGanntChart(const GanntChart &chart, Ui::MainWindow* ui) {
    unsigned int start = 0 + ui->centralwidget->width()*0.1;
    unsigned int end = ui->centralwidget->width()*0.9;
    unsigned int chartLength = end - start;
    unsigned int totalTime = 0;
    for (GanntChartSection section: chart) {
        totalTime += section.end - section.start;
    }
    QPainter painter;
    for (GanntChartSection section: chart) {
        painter.drawRect(start, 330, ((section.end - section.start)*chartLength) / totalTime, 50);
    }
}
