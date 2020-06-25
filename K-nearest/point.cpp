#include "point.h"

Point::Point()
{

}

Point::Point(int x, int y, QColor color)
    : m_point(QPoint(x,y))
    , m_color(color)
{

}

QPoint Point::GetPoint() const
{
    return m_point;
}

QColor Point::GetColor() const
{
    return m_color;
}
