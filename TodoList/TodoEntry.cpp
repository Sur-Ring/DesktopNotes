//
// Created by Jiang_Boyuan on 25-3-31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TodoEntry.h" resolved

#include "TodoEntry.h"
#include "ui_TodoEntry.h"

namespace TodoList {
TodoEntry::TodoEntry(int index, QWidget *parent) :
    QWidget(parent), ui(new Ui::TodoEntry), index(index) {
    ui->setupUi(this);
    connect(ui->entry, SIGNAL(editingFinished()), this, SLOT(on_editing_finished()));
}

TodoEntry::~TodoEntry() {
    delete ui;
}

void TodoEntry::setText(const QString& text) {
    ui->entry->setText(text);
}

void TodoEntry::on_editing_finished() {
    qDebug()<<index<<" is: "<<ui->entry->text();
    edited(index, ui->entry->text());
}
} // TodoList
