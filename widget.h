#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "gamewidget.h"

/**
 * @brief Класс Widget представляет основной виджет приложения, унаследованный от QWidget.
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса Widget.
     * @param parent Указатель на родительский виджет.
     */
    Widget(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса Widget.
     */
    ~Widget();

private:
    GameWidget* gameWidget; // Виджет игры
};


#endif // WIDGET_H
