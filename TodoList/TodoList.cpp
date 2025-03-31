//
// Created by Jiang_Boyuan on 25-3-31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TodoList.h" resolved

#include "TodoList.h"
#include "ui_TodoList.h"

#include <QFile>

namespace TodoList {
QString todo_file_path = "Data/todo.txt";

TodoList::TodoList(QWidget *parent) : QWidget(parent), ui(new Ui::TodoList) {
    ui->setupUi(this);
    load_todo();
    for (int i = 0; i < todo_text_list.size(); ++i) {
        TodoEntry *entry = new TodoEntry(i,this);
        entry->setText(todo_text_list[i]);
        connect(entry, SIGNAL(edited(int,const QString&)), this, SLOT(onTextChanged(int,const QString&)));
        ui->entry_list->addWidget(entry);
        entry_list.append(entry);
    }
}

TodoList::~TodoList() {
    delete ui;
}

void TodoList::load_todo() {
    QFile file(todo_file_path);
    file.open(QIODevice::ReadOnly);
    QString data;
    if (file.isOpen()) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            data = in.readLine();
            todo_text_list << data;
        }
        file.close();
    }
}

void TodoList::save_todo() {
    QFile file(todo_file_path);
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    if (file.isOpen()) {
        QTextStream in(&file);
        for (int i = 0; i < todo_text_list.size(); ++i) {
            in<<todo_text_list[i]<<"\n";
        }
        file.close();
    }
}

void TodoList::onTextChanged(int index, const QString &text) {
    qDebug()<<index<<" changed: "<<text;
    todo_text_list[index] = text;
    save_todo();
}
} // TodoList
