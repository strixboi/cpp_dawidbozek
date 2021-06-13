#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::lightGray);
    auto r = this->rect();
    painter.drawRect(r);

    painter.setPen(QPen(Qt::black,3));
    painter.drawLine(rect().width() / 2.0, rect().height() / 2.0 + 15, rect().width() / 2.0, rect().height() / 2.0 - 15);
    painter.drawLine(rect().width() / 2.0 - 15, rect().height() / 2.0, rect().width() / 2.0 + 15, rect().height() / 2.0);


    QRadialGradient Grad(QPointF(30,80),15);
    Grad.setColorAt(0.1, Qt::magenta);
    Grad.setColorAt(0.7, Qt::lightGray);
    painter.setBrush(QBrush(Grad));

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta)));
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);
    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            //painter.drawEllipse(-20, 60, 20, 20);
            QRect rect(20,60,30,30);
            painter.fillRect(rect,Grad);

        }
        painter.rotate(360.0 / num_disks);
    }
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}
