#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    case 1: //Shortest Job First
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumSpinBox->setEnabled(false);
        ui->PreemptiveCheckBox->setEnabled(true);
        ui->PriorityLabel->setEnabled(false);
        ui->PrioritySpinBox->setEnabled(false);
    case 2: //Priority
        ui->QuantumLabel->setEnabled(false);
        ui->QuantumSpinBox->setEnabled(false);
        ui->PreemptiveCheckBox->setEnabled(true);
        ui->PriorityLabel->setEnabled(true);
        ui->PrioritySpinBox->setEnabled(true);
    case 3: //Round Robin
        ui->QuantumLabel->setEnabled(true);
        ui->QuantumSpinBox->setEnabled(true);
        ui->PreemptiveCheckBox->setEnabled(false);
        ui->PriorityLabel->setEnabled(false);
        ui->PrioritySpinBox->setEnabled(false);
    }
}


void MainWindow::on_InesrtButton_clicked()
{

}


void MainWindow::on_SubmitButton_clicked()
{

}

