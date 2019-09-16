#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <QPushButton>
#include <QTime>
#include <stdlib.h>
#include "joint.h"
using namespace std;
class SNAKE : public QWidget
{
    Q_OBJECT
public:
    explicit SNAKE(QWidget *parent = 0);
private:
    QPushButton *apple;
    int food_X;
    int food_Y;
    JOINT *joints_arr[50];
    short no_joints;
    bool left_direction;
    bool right_direction;
    bool up_direction;
    bool down_direction;
    int timerId;
protected:
   void keyPressEvent(QKeyEvent *);
   void timerEvent(QTimerEvent *);
public:   
   void add_joint(int x, int y);
   void move();
   void draw_snake();
   void makeFood();
   void isItFood();
   void check_end_game();
signals:
    void signalGotFood();
    void signalSetFood(int, int);
    void signalGameOver();
public slots:
    void slotSetFood(int, int);
    void slotGotFood();

};

#endif // SNAKE_H
