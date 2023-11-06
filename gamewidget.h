#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <list>

#include <SFML/Graphics.hpp>

#include "enemyfish.h"
#include "playerfish.h"

/**
 * @brief Класс GameWidget представляет виджет игрового окна, унаследованный от QWidget и sf::RenderWindow.
 */
class GameWidget : public QWidget, public sf::RenderWindow
{
    Q_OBJECT

public:
    /**
     * @brief Перечисление Status определяет статус игры (Playing, Win, Lose).
     */
    enum class Status { Playing, Win, Lose };

    const int MAX_ENEMIES = 5;        ///< Максимальное количество вражеских рыб
    const float WINNING_SCALE = 1.0f; ///< Масштаб для достижения победы
    const float BG_SCALE = 0.40f;     ///< Масштаб фона

    /**
     * @brief Конструктор класса GameWidget.
     * @param parent Указатель на родительский виджет.
     */
    explicit GameWidget(QWidget *parent = nullptr);

private:
    /**
     * @brief Виртуальный метод для инициализации игры.
     */
    virtual void OnInit();

    /**
     * @brief Виртуальный метод для обновления состояния игры.
     */
    virtual void OnUpdate();

    /**
     * @brief Начать новую игру.
     */
    void startGame();

    /**
     * @brief Проверить завершение игры.
     */
    void checkGameOver();

    /**
     * @brief Добавить новых врагов на экран.
     */
    void addNewEnemies();

    /**
     * @brief Виртуальный метод для управления движком рисования.
     */
    virtual QPaintEngine* paintEngine() const;

    /**
     * @brief Обработка события отображения виджета.
     * @param event Событие отображения.
     */
    virtual void showEvent(QShowEvent*);

    /**
     * @brief Обработка события отрисовки виджета.
     * @param event Событие отрисовки.
     */
    virtual void paintEvent(QPaintEvent*);

    QTimer timer;       ///< Таймер для обновления игры
    bool initialized;   ///< Флаг инициализации игры

    Status status;      ///< Текущий статус игры

    sf::Texture bgTexture; ///< Текстура фона
    sf::Sprite  bgSprite;  ///< Спрайт фона

    sf::Text gameOverText; ///< Текст для отображения при завершении игры
    sf::Font font;         ///< Шрифт для текста

    PlayerFish player;                             ///< Игрок
    std::list<std::shared_ptr<EnemyFish>> enemies; ///< Враги
};


#endif // GAMEWIDGET_H
