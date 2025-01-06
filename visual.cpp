#include "visual.h"

Visual::Visual(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Основной вертикальный layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Поле ввода задачи (taskinp)
    taskinp = new QLineEdit(this);
    taskinp->setFixedHeight(30);
    taskinp->setPlaceholderText("Введите задачу...");

    // Кнопка добавления (addbtn)
    addbtn = new QPushButton("Добавить задачу", this);
    addbtn->setFixedSize(120, 30);

    // Список задач (tasklst)
    tasklst = new QListWidget(this);
    tasklst->setMinimumWidth(400);
    tasklst->setUniformItemSizes(true);
    tasklst->setSpacing(5); // Отступы между элементами списка

    // Создаем горизонтальный layout для поля ввода и кнопки
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(taskinp);
    inputLayout->addWidget(addbtn);

    // Добавление виджетов в основной layout
    mainLayout->addWidget(tasklst);
    mainLayout->addLayout(inputLayout);

    connect(addbtn, &QPushButton::clicked, [this]() {
        QString task = taskinp->text();
        if (!task.isEmpty()) {
            // Создаем виджет для элемента списка
            QWidget *itemWidget = new QWidget();
            QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);
            
            // Создаем label для текста задачи
            QLabel *taskLabel = new QLabel(task);
            taskLabel->setWordWrap(true); // Перенос длинного текста
            taskLabel->setMaximumWidth(tasklst->width() - 100);
            
            // Создаем кнопку удаления
            QPushButton *removebtn = new QPushButton("Удалить");
            removebtn->setFixedSize(80, 25);

            // Добавляем элементы в layout элемента списка
            itemLayout->addWidget(taskLabel, 1); // Растягиваем текст
            itemLayout->addWidget(removebtn);
            itemLayout->setContentsMargins(5, 5, 5, 5);

            // Создаем элемент списка
            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(itemWidget->sizeHint()); // Устанавливаем размер элемента
            
            tasklst->addItem(item);
            tasklst->setItemWidget(item, itemWidget);

            // Подключаем удаление
            connect(removebtn, &QPushButton::clicked, [this, item]() {
                delete item;
            });

            taskinp->clear();
        }
    });

    // Устанавливаем минимальный размер окна
    setMinimumSize(500, 400);
}

Visual::~Visual() {

}