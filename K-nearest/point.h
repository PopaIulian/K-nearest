#ifndef POINT_H
#define POINT_H
#include <QPoint>
#include<QPainter>

class Point
{
public:
    Point();
    Point(int x, int y, QColor color);

    QPoint GetPoint() const;

    QColor GetColor() const;

private:
    QPoint m_point;
    QColor m_color;

};

#endif // POINT_H