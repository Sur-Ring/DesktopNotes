//
// Created by Jiang_Boyuan on 25-3-31.
//

#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QWidget>

namespace TodoList {
QT_BEGIN_NAMESPACE
namespace Ui { class AddEntry; }
QT_END_NAMESPACE

class AddEntry : public QWidget {
Q_OBJECT

public:
    explicit AddEntry(QWidget *parent = nullptr);
    ~AddEntry() override;
private:
    Ui::AddEntry *ui;
};
} // TodoList

#endif //ADDENTRY_H
