//
// Created by Jiang_Boyuan on 25-3-31.
//

#ifndef TODOENTRY_H
#define TODOENTRY_H

#include <QWidget>

namespace TodoList {
QT_BEGIN_NAMESPACE

namespace Ui {
class TodoEntry;
}

QT_END_NAMESPACE

class TodoEntry : public QWidget {
    Q_OBJECT

public:
    explicit TodoEntry(int index, QWidget *parent = nullptr);

    ~TodoEntry() override;

    int index;

    void setText(const QString &text);
    void focus_entry();

private:
    Ui::TodoEntry *ui;
signals:
    void edited(int, const QString&);
private slots:
    void on_editing_finished();
};
} // TodoList

#endif //TODOENTRY_H
