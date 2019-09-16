#include "snake.h"

SNAKE::SNAKE(QWidget *parent) : QWidget(parent)
{
    left_direction = false;
    right_direction = true;
    up_direction = false;
    down_direction = false;
    no_joints=0;
    for (int i = 0; i < 4; i++)
    {
       add_joint(250-i*20,250);
    }
    connect(this, SIGNAL(signalSetFood(int, int)),this, SLOT(slotSetFood(int, int)));
    connect(this, SIGNAL(signalGotFood()),this, SLOT(slotGotFood()));
    makeFood();
    timerId = startTimer(140);


}

void SNAKE::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if ((key == Qt::Key_Left) && (!right_direction)) {
        left_direction = true;
        up_direction = false;
        down_direction = false;
    }
    if ((key == Qt::Key_Right) && (!left_direction)) {
        right_direction = true;
        up_direction = false;
        down_direction = false;
    }
    if ((key == Qt::Key_Up) && (!down_direction)) {
        up_direction = true;
        right_direction = false;
        left_direction = false;
    }
    if ((key == Qt::Key_Down) && (!up_direction)) {
        down_direction = true;
        right_direction = false;
        left_direction = false;
    }
    QWidget::keyPressEvent(e);

}

void SNAKE::add_joint(int x, int y)
{
    JOINT *ptr;
    ptr=new JOINT();
    ptr->setParent(this);
    joints_arr[no_joints]=ptr;
    ptr->set_centerX(x);
    ptr->set_centerY(y);
    no_joints++;
}

 void SNAKE::makeFood()
{
     food_X=rand()%400+0;
     food_Y=rand()%400+0;
     emit signalSetFood(food_X, food_Y);
}
 void SNAKE::isItFood()
 {
     if (food_X < joints_arr[0]->get_centerX()+10 && food_X > joints_arr[0]->get_centerX()-10 && food_Y < joints_arr[0]->get_centerY()+10 && food_Y > joints_arr[0]->get_centerY()-10) {
         emit signalGotFood();
         makeFood();
     }
 }
void SNAKE::check_end_game()
{
    if (joints_arr[0]->get_centerY() >= 500)
    {
        emit signalGameOver();
    }
    if (joints_arr[0]->get_centerY() < 0)
    {
        emit signalGameOver();
    }
    if (joints_arr[0]->get_centerX() >= 500)
    {
        emit signalGameOver();
    }
    if (joints_arr[0]->get_centerX() < 0)
    {
        emit signalGameOver();
    }
}

void SNAKE::move()
{
    isItFood();
    for (int i = no_joints-1; i > 0; i--) {
        joints_arr[i]->set_centerX(joints_arr[i-1]->get_centerX());
        joints_arr[i]->set_centerY(joints_arr[i-1]->get_centerY());
    }
    int numx=joints_arr[0]->get_centerX();
    int numy=joints_arr[0]->get_centerY();

    if (left_direction) {
        numx-=20;
        joints_arr[0]->set_centerX(numx)  ;
    }

    if (right_direction) {
        numx+=20;
        joints_arr[0]->set_centerX(numx)  ;
    }

    if (up_direction) {
        numy-=20;
        joints_arr[0]->set_centerY(numy)  ;
    }

    if (down_direction) {
        numy+=20;
        joints_arr[0]->set_centerY(numy)  ;
    }
    isItFood();
}

void SNAKE::draw_snake()
{
    for(int i=0;i<no_joints;i++)
    {
        joints_arr[i]->draw_joint();
    }
}

void SNAKE::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    check_end_game();
    //s1->checkCollision();
    isItFood();
    draw_snake();
    move();

}

void SNAKE::slotSetFood(int food_X, int food_Y)
{
    apple=new QPushButton();
    apple->setParent(this);
    apple->setGeometry(food_X,food_Y,30,30);
    apple->show();

}

void SNAKE::slotGotFood()
{
    delete apple;
    add_joint(joints_arr[no_joints-1]->get_centerX()-20,joints_arr[no_joints-1]->get_centerY()-20);
}
