#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {setFocus();}

void MyWidget::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::magenta);
    auto r = this->rect();
    painter.drawRect(r);

    painter.setBrush(QBrush(Qt::black));
    for (const auto& circ : circles)
    {
        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.drawEllipse(point, circ.radius, circ.radius);
    }
}

void MyWidget::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->position();
    auto rec = rect();
    Circle c;
    c.radius = DEFAULT_RADIUS;
    c.center.setX(pos.x() / rec.width());
    c.center.setY(pos.y() / rec.height());
    circles.push_back(c);
    repaint();
}

void MyWidget::wheelEvent(QWheelEvent* event)
{
    for(auto& cir : circles)
    {
            cir.radius -= 2;
            repaint();
    }

}



void MyWidget::keyPressEvent(QKeyEvent* event)
{
    if ((event->key() == Qt::Key_Z) && (event->modifiers() == Qt::ControlModifier))
    {
        circles.pop_back();
        repaint();
    }
}

