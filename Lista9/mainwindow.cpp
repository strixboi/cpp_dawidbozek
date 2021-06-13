#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()));
    connect(ui->przycisk, SIGNAL(clicked()), ui->widget, SLOT(on_click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koniec_programu()
{
    //qApp->quit();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Opcja","Zakmnąć program?",QMessageBox::Yes|QMessageBox::No);

    if(reply==QMessageBox::Yes)
    {QApplication::quit();qDebug() << "Zamknięto";}
    else{qDebug() << "Nie zamknięto";}




}


void MainWindow::on_action_O_programie_triggered()
{
 QMessageBox::aboutQt(this,"O wspaniałym programie");
}

//pomimo tego, ze funkcja jest zaimplementowana względnie poprawnie nie chce działać, prosiłbym o wytłumaczenie dlaczego
void MainWindow::on_click()
{
    qDebug() << "Wciśnięto przycisk";
    if(ui->przycisk->text() == "Start")
        ui->przycisk->setText("Stop");
    else
        ui->przycisk->setText("Start");
}
