#include "knearst.h"
#include <fstream>
#include "qmath.h"
#include "QDebug"

KNearst::KNearst(int k)
    :m_k(k)
{

}

std::vector<Point> KNearst::GetPoints() const
{
    return m_points;
}

bool KNearst::initialize(std::string csv_file_path)
{
    std::string line;
    std::ifstream myfile(csv_file_path);
    if (!myfile.is_open())
        return false;

    while (!myfile.eof())
    {
        getline(myfile, line);
        if (line.size() == 0)
            break;

        std::vector <std::string> tokens = Tokenize(line, ',');
        QColor color;
        if(tokens[0]=="r")
            color=QColor(255,0,0);
        else
            color=QColor(0,0,255);

        int x = std::stoi(tokens[1]);
        int y = std::stoi(tokens[2]);
        m_points.push_back(Point(y,x,color));
    }
    return true;
}



void KNearst::InsertNewPoint(QPoint point)
{
    for(size_t i=0;i<m_points.size()-1;i++)
        for(size_t j=i+1;j<m_points.size();j++)
        {
            if(EuclidianDistance(m_points[i].GetPoint(),point)>EuclidianDistance(m_points[j].GetPoint(),point))
            {
                auto p = m_points[i];
                auto q = m_points[j];
                m_points[i] = q;
                m_points[j] = p;
            }
        }
    int nrR=0;
    int nrG=0;
    for(int i=0;i<m_k;i++)
    {
        if(m_points[i].GetColor()==QColor(255,0,0))
            nrR++;
        else
            nrG++;

        // qDebug()<<EuclidianDistance(p.GetPoint(),point)<<"\n";
    }
    QColor c;
    if(nrR>nrG)
        c=QColor(255,0,0);
    else
        c=QColor(0,0,255);
    m_points.push_back(Point(point,c));
}

void KNearst::InsertNewPointWeight(QPoint point)
{
    for(size_t i=0;i<m_points.size()-1;i++)
        for(size_t j=i+1;j<m_points.size();j++)
        {
            if(EuclidianDistance(m_points[i].GetPoint(),point)>EuclidianDistance(m_points[j].GetPoint(),point))
            {
                auto p = m_points[i];
                auto q = m_points[j];
                m_points[i] = q;
                m_points[j] = p;
            }
        }
    double nrR=0;
    double nrG=0;
    for(int i=0;i<m_k;i++)
    {
        if(m_points[i].GetColor()==QColor(255,0,0))
            nrR += EuclidianDistanceWeight(m_points[i].GetPoint(),point);
        else
            nrG += EuclidianDistanceWeight(m_points[i].GetPoint(),point);;
    }
    QColor c;
    if(nrR>nrG)
        c=QColor(255,0,0);
    else
        c=QColor(0,0,255);
    m_points.push_back(Point(point,c));
}

int KNearst::CalculateMaxK()
{
    int minError=INT_MAX;
    int kVal=-1;
    for(int k=1;k<m_points.size();k++)
    {
        int nr=0;
        for(int i=0;i<m_points.size();i++)
        {
            QColor color=GetColor(i);
            if(color != m_points[i].GetColor())
                nr++;
        }
        if(nr<minError)
        {
            minError=nr;
            kVal =k;
        }
    }
    return kVal;
}

std::vector<std::string> KNearst::Tokenize(const std::string &str, const char delim)
{
    std::vector<std::string> out;
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
    return out;
}

double KNearst::EuclidianDistance(QPoint point1, QPoint point2)
{
    return qSqrt(((point1.x() - point2.x())*(point1.x() - point2.x())) + ((point1.y() - point2.y())*(point1.y() - point2.y())));
}

double KNearst::EuclidianDistanceWeight(QPoint point1, QPoint point2)
{
    double dist = qSqrt(((point1.x() - point2.x())*(point1.x() - point2.x())) + ((point1.y() - point2.y())*(point1.y() - point2.y())));
    return 1/(dist*dist);
}

QColor KNearst::GetColor(int poz)
{
    for(size_t i=0;i<m_points.size()-1;i++)
        for(size_t j=i+1;j<m_points.size();j++)
        {
            if(i!=poz && j!=poz)
            {
                if(EuclidianDistance(m_points[i].GetPoint(),m_points[poz].GetPoint())>EuclidianDistance(m_points[j].GetPoint(),m_points[poz].GetPoint()))
                {
                    auto p = m_points[i];
                    auto q = m_points[j];
                    m_points[i] = q;
                    m_points[j] = p;
                }
            }
        }
    int nrR=0;
    int nrG=0;
    for(int i=0;i<m_k;i++)
    {
        if(m_points[i].GetColor()==QColor(255,0,0))
            nrR++;
        else
            nrG++;
    }

    QColor c;
    if(nrR>nrG)
        return QColor(255,0,0);
    else
        return QColor(0,0,255);
}
