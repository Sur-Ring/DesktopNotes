//
// Created by Jiang_Boyuan on 25-3-31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AddEntry.h" resolved

#include "AddEntry.h"
#include "ui_AddEntry.h"

namespace TodoList {
AddEntry::AddEntry(QWidget *parent) :
    QWidget(parent), ui(new Ui::AddEntry) {
    ui->setupUi(this);
}

AddEntry::~AddEntry() {
    delete ui;
}
}

