#include "point.h"

Point::Point()
{

}

Point::Point(int x, int y, QColor color)
    : m_point(QPoint(x,y))
    , m_color(color)
{

}

Point::Point(QPoint p, QColor color)
    :m_point(p)
    ,m_color(color)
{

}

void Point::operator =( Point &p)
{
    m_color = p.m_color;
    m_point = p.m_point;
}

QPoint Point::GetPoint() const
{
    return m_point;
}

QColor Point::GetColor() const
{
    return m_color;
}
