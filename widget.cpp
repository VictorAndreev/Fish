#include "widget.h"

#include <QVBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    gameWidget = new GameWidget(this);

    this->setWindowTitle("Рыбки");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(gameWidget);

    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

Widget::~Widget()
{
}

