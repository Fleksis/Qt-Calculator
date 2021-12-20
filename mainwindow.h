#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Skaitli();

    void on_Poga_komats_clicked();

    void on_Poga_Sakne_clicked();

    void on_Poga_Kvadrata_clicked();

    void on_Poga_Dzest_clicked();

    void OperatoruDarbibas();

    void on_Poga_vienadiba_clicked();

    void on_ZimjuMaina_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
