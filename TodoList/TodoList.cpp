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
    update_entry();
    connect(ui->add_area, SIGNAL(clicked()), this, SLOT(on_add_clicked()));
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

// 这个软件不是为了大量记录而设计的, 因此这样的暴力更新不会有什么问题, 有问题了再说
void TodoList::update_entry() {
    if (entry_list.size() < todo_text_list.size()) {
        for (qsizetype i = entry_list.size(); i < todo_text_list.size(); ++i) {
            auto *entry = new TodoEntry(i,this);
            connect(entry, SIGNAL(edited(int,const QString&)), this, SLOT(onTextChanged(int,const QString&)));
            ui->entry_list->addWidget(entry);
            entry_list.append(entry);
        }
    }

    if (entry_list.size() > todo_text_list.size()) {
        for (qsizetype i = todo_text_list.size(); i < entry_list.size(); ++i) {
            entry_list[i]->hide();
        }
    }

    for (qsizetype i = 0; i < todo_text_list.size(); ++i) {
        entry_list[i]->setText(todo_text_list[i]);
        entry_list[i]->show();
    }
}

void TodoList::onTextChanged(int index, const QString &text) {
    qDebug()<<index<<" changed: "<<text<<" len:"<<text.length();
    if (text=="") {
        qDebug()<<"text:empty"<<" text_list_len: "<<todo_text_list.size()<<" entry_list_len:"<<entry_list.size();
        todo_text_list.removeAt(index);
        qDebug()<<"text:empty111"<<" text_list_len: "<<todo_text_list.size()<<" entry_list_len:"<<entry_list.size();
        update_entry();
    }else {
        todo_text_list[index] = text;
    }
    // TODO 暂时注释掉
    // save_todo();
}

void TodoList::on_add_clicked() {
    todo_text_list<<"";
    update_entry();
    qDebug()<<"text_list_len: "<<todo_text_list.size()<<" entry_list_len:"<<entry_list.size();
    entry_list[todo_text_list.size()-1]->focus_entry();
}
} // TodoList
