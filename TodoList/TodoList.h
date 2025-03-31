//
// Created by Jiang_Boyuan on 25-3-31.
//

#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>

#include "TodoEntry.h"

namespace TodoList {
QT_BEGIN_NAMESPACE
namespace Ui { class TodoList; }
QT_END_NAMESPACE


class TodoList : public QWidget {
Q_OBJECT

public:
    explicit TodoList(QWidget *parent = nullptr);
    ~TodoList() override;

private:
    Ui::TodoList *ui;
    QList<QString> todo_text_list;
    QList<TodoEntry*> entry_list;
    void load_todo();
    void save_todo();
    void update_entry();
private slots:
    void onTextChanged(int index, const QString &text);
    void on_add_clicked();
};
} // TodoList

#endif //TODOLIST_H
