#ifndef KNEARST_H
#define KNEARST_H
#include <point.h>
#include <vector>

class KNearst
{
public:
    KNearst();

    std::vector<Point> GetPoints() const;

    bool initialize(std::string csv_file_path);

private:
    std::vector<std::string> Tokenize(const std::string &str, const char delim);

private:
    std::vector<Point> m_points;

};

#endif // KNEARST_H
