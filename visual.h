#ifndef VISUAL_H
#define VISUAL_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class Visual : public QMainWindow 
{
    Q_OBJECT

public:
    explicit Visual(QWidget *parent = nullptr);
    ~Visual();

private:
    QLineEdit *taskinp;
    QPushButton *addbtn;
    QListWidget *tasklst;
};

#endif //VISUAL_H