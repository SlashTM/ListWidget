#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QList"

QList<QString> left {"banana", "apple", "orange", "tomato", "cabbage", "potato", "board", "fridge", "knife"};
QList<QString> right {"carrot", "parrot", "onion", "bluberries", "strawberries", "kiwi", "watermelon"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->left_list->addItems(left);
    ui->right_list->addItems(right);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_to_right_clicked()
{
    if(ui->left_list->count()==0){
        QMessageBox::warning(0,"Error!", "List is Empty!");
    }
    QListWidgetItem *item = ui->left_list->item(ui->left_list->currentRow());
    if (!item) {
        QMessageBox::warning(0,"Error!","Choose element!");
    }
    ui->right_list->addItem(ui->left_list->takeItem(ui->left_list->currentRow()));
    ui->left_list->setCurrentRow(-1);
}

void MainWindow::on_to_left_clicked()
{
    if(ui->right_list->count()==0){
        QMessageBox::warning(0,"Error!", "List is Empty!");
    }
    QListWidgetItem *item = ui->right_list->item(ui->right_list->currentRow());
    if (!item) {
        QMessageBox::warning(0,"Error!","Choose element!");
    }
    ui->left_list->addItem(ui->right_list->takeItem(ui->right_list->currentRow()));
    ui->right_list->setCurrentRow(-1);
}

void MainWindow::on_sort_clicked()
{
    if (ui->left_list->count()!=0){
        ui->left_list->sortItems(Qt::AscendingOrder);
    }
    if (ui->right_list->count()!=0){
        ui->right_list->sortItems(Qt::DescendingOrder);
    }
}

