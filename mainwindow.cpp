#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <windows.h>
#include <winuser.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
