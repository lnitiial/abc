#include "widget.h"
#include "ui_widget.h"
#include <time.h>
#include <QResizeEvent>
#include <QtCore/qmath.h>
#include <QProcess>
#include <QDir>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->map = new int*[4];
    for(int i=0; i<4; i++)
    {
        this->map[i] = new int[4];
    }
    //  初始化
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            this->map[i][j] = 0;
        }
    }
    rand_two();
    show_view();
    this->is_move_merge = true;
    this->score = 0;
    this->best = 0;
    FILE* frp = fopen("./best.txt","r");
    if(NULL == frp)
    {
        frp = fopen("./best.txt","w");
        best=0;
    }
    else
    {
       fscanf(frp,"%d",&best);
    }
    fclose(frp);
    ui->label_best->setText(QString::number(this->best));


}

Widget::~Widget()
{
    FILE* fwp = fopen("./best.txt","w");
    if(NULL == fwp)
    {
        qDebug("保存失败");
    }
    fprintf(fwp,"%d",score>best? score:best);
    fclose(fwp);

    for(int i=0; i<4; i++)
    {
        delete[] this->map[i];
    }
    delete this->map;
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
        case Qt::Key_Up: up(); break;
        case Qt::Key_Down: down(); break;
        case Qt::Key_Left: left(); break;
        case Qt::Key_Right: right(); break;
    }
    rand_two();
    show_view();
    if(is_die())
    {
        QMessageBox messagebox(QMessageBox::Question,"提示","GAME OVER!",
                               QMessageBox::Yes | QMessageBox::No);
        messagebox.setInformativeText("Try again?");

        int ret = messagebox.exec();
        switch(ret)
        {
        case QMessageBox::Yes:
            reboot();
            break;
        case QMessageBox::No:
            qApp->quit();
            break;
        }

    }

}

bool Widget::is_full()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(map[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Widget::rand_two()
{
    if(!is_full() && is_move_merge)
    {
        int x=0,y=0;
        srand(time(NULL));
        x = rand()%4;
        y = rand()%4;
        while(this->map[x][y]!=0)
        {
            x = rand()%4;
            y = rand()%4;
        }
        this->map[x][y] = 2;
    }
}

bool Widget::is_die()
{
    if(!is_full()) return false;

    // 横向判断
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(map[i][j] == map[i][j+1])
                return false;
        }
    }

    // 纵向判断
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(map[i][j] == map[i+1][j])
                return false;
        }
    }
    return true;
}
int qLog2(int num)
{
    int cnt = 0;
    while(1!=num)
    {
        num/=2;
        cnt++;
    }

    return cnt;
}


void Widget::show_view()
{
    char background_color[][14]={"(238,228,218)","(237,224,200)","(242,177,121)",
                                 "(245,149,99)","(246,124,95)","(246,94,59)",
                                "(237,207,114)","(237,204,97)","(237,200,80)"};
    char color[][14]={"(119,110,101)","(119,110,101)","(249,246,242)",
                      "(249,246,242)","(249,246,242)","(249,246,242)",
                     "(249,246,242)","(249,246,242)","(249,246,242)"};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            QString str = "label_";
            str+=QString::number(i);
            str+=QString::number(j);
            QLabel *label = this->findChild<QLabel *>(str);
            if(0 == map[i][j])
            {
                label->setText("");
                label->setStyleSheet("background-color: rgb(205, 193, 180);");
            }
            else
            {
                QString style = "background-color: rgb";
                style+=background_color[qLog2(map[i][j])-1];
                style+=";";
                style+="color: rgb";
                style+=color[qLog2(map[i][j])-1];
                style+=";";
                label->setStyleSheet(style);
                label->setText(QString::number(map[i][j]));
            }

        }
    }
    ui->label_score->setText(QString::number(score));
    ui->label_best->setText(QString::number(score>best?score:best));

}

void Widget::up()
{
    for(int i=0;i<4;i++)
    {
        int flag = 0;
        for(int j=1;j<4;j++)
        {
            if(map[j][i]!=0)
            {
                if(map[flag][i]==0)
                {
                    map[flag][i]=map[j][i];
                    map[j][i]=0;
                    is_move_merge = true;
                }
                else if(map[j][i]==map[flag][i])
                {
                    map[flag][i]+=map[j][i];
                    score+=map[flag][i];
                    map[j][i]=0;
                    is_move_merge = true;
                    flag++;
                }
                else
                {
                    map[flag+1][i]=map[j][i];
                    if(flag+1!=j)
                    {
                        map[j][i]=0;
                    }
                    flag++;
                }
            }

        }
    }
}

void Widget::down()
{
    for(int i=0;i<4;i++)
    {
        int flag = 3;
        for(int j=2;j>=0;j--)
        {
            if(map[j][i]!=0)
            {
                if(map[flag][i]==0)
                {
                    map[flag][i]=map[j][i];
                    map[j][i]=0;
                    is_move_merge = true;
                }
                else if(map[j][i]==map[flag][i])
                {
                    map[flag][i]+=map[j][i];
                    score+=map[flag][i];
                    map[j][i]=0;
                    flag--;
                    is_move_merge = true;
                }
                else
                {
                    map[flag-1][i]=map[j][i];
                    if(flag-1!=j)
                    {
                        map[j][i]=0;
                    }
                    flag--;
                }
            }

        }
    }

}

void Widget::left()
{
    for(int i=0;i<4;i++)
    {
        int flag = 0;
        for(int j=1;j<4;j++)
        {
            if(map[i][j]!=0)
            {
                if(map[i][flag]==0)
                {
                    map[i][flag]=map[i][j];
                    map[i][j]=0;
                    is_move_merge = true;
                }
                else if(map[i][j]==map[i][flag])
                {
                    map[i][flag]+=map[i][j];
                    score+=map[i][flag];
                    map[i][j]=0;
                    flag++;
                    is_move_merge = true;
                }
                else
                {
                    map[i][flag+1]=map[i][j];
                    if(flag+1!=j)
                    {
                        map[i][j]=0;
                    }
                    flag++;
                }
            }

        }
    }

}

void Widget::right()
{
    for(int i=0;i<4;i++)
    {
        int flag = 3;
        for(int j=2;j>=0;j--)
        {
            if(map[i][j]!=0)
            {
                if(map[i][flag]==0)
                {
                    map[i][flag]=map[i][j];
                    map[i][j]=0;
                    is_move_merge = true;
                }
                else if(map[i][j]==map[i][flag])
                {
                    map[i][flag]+=map[i][j];
                    score+=map[i][flag];
                    map[i][j]=0;
                    is_move_merge = true;
                    flag--;
                }
                else
                {
                    map[i][flag-1]=map[i][j];
                    if(flag-1!=j)
                    {
                        map[i][j]=0;
                    }
                    flag--;
                }
            }

        }
    }
}

void Widget::reboot()
{
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}



void Widget::on_pushButton_clicked()
{
     this->reboot();
}
