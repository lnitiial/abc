#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;

}

class Widget : public QWidget
{
    Q_OBJECT
    int** map;
    int score;
    int best;
    bool is_move_merge;


public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void keyPressEvent(QKeyEvent *event);
    bool is_full(void);
    void rand_two(void);
    bool is_die(void);
    void show_view(void);
    void up(void);
    void down(void);
    void left(void);
    void right(void);
    void reboot(void);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
