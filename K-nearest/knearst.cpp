#include "knearst.h"
#include <fstream>

KNearst::KNearst()
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
