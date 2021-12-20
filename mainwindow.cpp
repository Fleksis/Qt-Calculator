#include "mainwindow.h"
#include "ui_mainwindow.h"

double IevadesSkaitlis;
bool SaskaitisanasTrigger = false;
bool AtnemsanasTrigger = false;
bool ReizinasanasTrigger = false;
bool DalisanasTrigger = false;
bool Summastrigger = false;
bool komatatrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(343,403);
    ui->setupUi(this);

    connect(ui->Poga_0, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_1, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_2, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_3, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_4, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_5, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_6, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_7, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_8, SIGNAL(clicked()),this,SLOT(Skaitli()));
    connect(ui->Poga_9, SIGNAL(clicked()),this,SLOT(Skaitli()));

    connect(ui->Poga_saskaitisana, SIGNAL(clicked()),this,SLOT(OperatoruDarbibas()));
    connect(ui->Poga_atnemsana, SIGNAL(clicked()),this,SLOT(OperatoruDarbibas()));
    connect(ui->Poga_reizinasana, SIGNAL(clicked()),this,SLOT(OperatoruDarbibas()));
    connect(ui->Poga_Dalisana, SIGNAL(clicked()),this,SLOT(OperatoruDarbibas()));

    connect(ui->Poga_komats, SIGNAL(clicked()),this,SLOT(on_Poga_komats_clicked()));

    ui->Poga_saskaitisana->setCheckable(true);
    ui->Poga_atnemsana->setCheckable(true);
    ui->Poga_reizinasana->setCheckable(true);
    ui->Poga_Dalisana->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Skaitli(){
    QPushButton *button = (QPushButton *)sender();
    double cipari, cipars2;
    QString Izvade;
    if(Summastrigger && SaskaitisanasTrigger || AtnemsanasTrigger || ReizinasanasTrigger || DalisanasTrigger){
        cipars2 = (ui->IevadesSkaitlis->text()).toDouble();
        Izvade = QString::number(cipars2,'g',15);
        ui->IevadesSkaitlis->setText(Izvade);
    }else if(Summastrigger){
        ui->Rezultats->setText("");
        ui->OperatoraRaditajs->setText("");
        ui->IevadesSkaitlis->setText("");
        Summastrigger = false;
    }

    if (ui->Rezultats->text().contains(".") && button->text() == "0"){
        Izvade = ui->Rezultats->text() + button->text();
    } else {
        cipari = (ui->Rezultats->text() + button->text()).toDouble();
        Izvade = QString::number(cipari, 'g', 15);
    }

    cipari = (ui->Rezultats->text() + button->text()).toDouble();
    if(cipari >= 1000000000000000){
        QMessageBox::warning(this, tr("Calculator error!"),tr("Ievadītais skaitlis pārsniedza 15 simbolus!"),QMessageBox::Ok);
        cipari = 0;
        Izvade = QString::number(cipari, 'g', 15);
    }
    ui->Rezultats->setText(Izvade);
}

void MainWindow::on_Poga_komats_clicked(){
    if(!(ui->Rezultats->text().contains('.')))
        ui->Rezultats->setText(ui->Rezultats->text() + ".");
    komatatrigger = true;
}

void MainWindow::on_ZimjuMaina_clicked()
{
    double cipars;
    QString Izvade;
    cipars = (ui->Rezultats->text()).toDouble();
    cipars = cipars * -1;
    Izvade = QString::number(cipars,'g',15);
    ui->Rezultats->setText(Izvade);
}

void MainWindow::on_Poga_Sakne_clicked(){
    double cipari,cipars2;
    QString Izvade;
    if(Summastrigger){
        cipars2 = (ui->Rezultats->text()).toDouble();
        Izvade = QString::number(cipars2,'g', 15);
        ui->IevadesSkaitlis->setText(Izvade);
    } else {
        Summastrigger = true;
    }
    cipari = (ui->Rezultats->text()).toDouble();
    cipari = sqrt(cipari);
    Izvade = QString::number(cipari,'g', 15);
    ui->OperatoraRaditajs->setText("Sqrt");
    ui->Rezultats->setText(Izvade);
}


void MainWindow::on_Poga_Kvadrata_clicked(){
    double cipari, cipars2;
    QString Izvade;
    if(Summastrigger){
        cipars2 = (ui->Rezultats->text()).toDouble();
        Izvade = QString::number(cipars2,'g', 15);
        ui->IevadesSkaitlis->setText(Izvade);
    } else {
        Summastrigger = true;
    }
    cipari = (ui->Rezultats->text()).toDouble();
    cipari = cipari*cipari;
    if(cipari >= 1000000000000000){
        QMessageBox::warning(this, tr("Calculator error!"),tr("Ievadītais skaitlis pārsniedza 15 simbolus!"),QMessageBox::Ok);
        ui->OperatoraRaditajs->setText("");
        ui->Rezultats->setText("");
        ui->IevadesSkaitlis->setText("");
        Summastrigger = false;
    } else {
        Izvade = QString::number(cipari,'g', 15);
        ui->OperatoraRaditajs->setText("^2");
        ui->Rezultats->setText(Izvade);
    }
}


void MainWindow::on_Poga_Dzest_clicked(){
    SaskaitisanasTrigger = true;
    AtnemsanasTrigger = true;
    ReizinasanasTrigger = true;
    DalisanasTrigger = true;

    ui->Rezultats->setText("");
    ui->OperatoraRaditajs->setText("");
    ui->IevadesSkaitlis->setText("");
}

void MainWindow::OperatoruDarbibas(){
    QString Izvade;
    IevadesSkaitlis = ui->Rezultats->text().toDouble();
    ui->Rezultats->setText("");

    Izvade = QString::number(IevadesSkaitlis,'g',15);
    ui->IevadesSkaitlis->setText(Izvade);
    SaskaitisanasTrigger = false;
    AtnemsanasTrigger = false;
    ReizinasanasTrigger = false;
    DalisanasTrigger = false;
    QPushButton *button = (QPushButton *)sender();
    QString Operators = button->text();
    if(Operators == "+") {
        SaskaitisanasTrigger = true;
        ui->OperatoraRaditajs->setText(" +");
    } else if(Operators == "-") {
        AtnemsanasTrigger = true;
        ui->OperatoraRaditajs->setText(" -");
    } else if(Operators == "x") {
        ReizinasanasTrigger = true;
        ui->OperatoraRaditajs->setText(" x");
    } else if(Operators == "/") {
        DalisanasTrigger = true;
        ui->OperatoraRaditajs->setText(" /");
    }
}

void MainWindow::on_Poga_vienadiba_clicked(){

    double summa = 0.0, IevadesSkaitlis2;
    QString Izvade;
    IevadesSkaitlis2 = ui->Rezultats->text().toDouble();

    if(ui->Poga_saskaitisana->isChecked()/*SaskaitisanasTrigger*/) {
        summa = IevadesSkaitlis + IevadesSkaitlis2;

        SaskaitisanasTrigger = false;
        ui->Poga_saskaitisana->setChecked(true);
    } else if (ui->Poga_atnemsana->isChecked()/*AtnemsanasTrigger*/) {
        summa = IevadesSkaitlis - IevadesSkaitlis2;

        AtnemsanasTrigger = false;
        ui->Poga_atnemsana->setChecked(true);
    } else if (ui->Poga_reizinasana->isChecked()/*ReizinasanasTrigger*/) {
        summa = IevadesSkaitlis * IevadesSkaitlis2;

        ReizinasanasTrigger = false;
        ui->Poga_reizinasana->setChecked(true);
    } else if (ui->Poga_Dalisana->isChecked()/*DalisanasTrigger*/) {
        summa = IevadesSkaitlis / IevadesSkaitlis2;

        DalisanasTrigger = false;
        ui->Poga_Dalisana->setChecked(true);
    }

    if(summa >= 1000000000000000){
        QMessageBox::warning(this, tr("Calculator error!"),tr("Ievadītais skaitlis pārsniedza 15 simbolus!"),QMessageBox::Ok);
        summa = 0;
        Izvade = QString::number(summa, 'g', 15);
        ui->Rezultats->setText(Izvade);
        Summastrigger = false;
    }

//    if(vienadibasTrigger) {
//        Izvade = QString::number(IevadesSkaitlis, 'g', 15);
//        ui->Rezultats->setText(Izvade);
//        vienadibasTrigger = false;
//    }
    Izvade = QString::number(summa, 'g', 15);
    ui->Rezultats->setText(Izvade);
    Summastrigger = true;
}
