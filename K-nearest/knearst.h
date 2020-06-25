#ifndef KNEARST_H
#define KNEARST_H
#include <point.h>
#include <vector>

class KNearst
{
public:
    KNearst(int k);

    std::vector<Point> GetPoints() const;

    bool initialize(std::string csv_file_path);

    void InsertNewPoint(QPoint point);

private:
    std::vector<std::string> Tokenize(const std::string &str, const char delim);

private:
    double EuclidianDistance(QPoint point1, QPoint point2);

private:
    std::vector<Point> m_points;
    int m_k;


};

#endif // KNEARST_H
