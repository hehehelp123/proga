#include "transfer.h"

point::point(std::string vehicle, std::vector<std::string> street, std::vector<std::string> numbers, std::pair<double, double> location, int number)
{
    this->vehicle = vehicle;
    this->street = street;
    this->numbers = numbers;
    this->location = location;
    this->number = number;
}

void point::out()
{
    std::cout << number << std::endl;
    std::cout << vehicle << std::endl;
    for (int i = 0; i < street.size(); ++i)
    {
        std::cout << street[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << location.first << " " << location.second << std::endl;
}

std::pair<double, double> point::getCoord()
{
    return location;
}

double distTwoPoints(std::pair<double, double> x1, std::pair<double, double> x2)
{
    return std::sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
}

void line::add(point* x)
{
    ++n;
    stations.push_back(x);
}

void line::setName(std::string s)
{
    name = s;
}

std::string line::getName()
{
    return name;
}

int line::getN()
{
    return n;
}

double line::dist()
{
    double S = 0;
    int start = 0;
    int end = -1;
    std::vector<bool> checked(n);
    checked[0] = true;
    for (int i = 0; i < n - 1; ++i)
    {
        double min = INT_MAX;
        int index = -1;
        if (i == 0)
        {
            for (int j = 0; j < n; ++j)
            {
                if (checked[j])
                    continue;
                double distTime = distTwoPoints(stations[start]->getCoord(), stations[j]->getCoord());
                if (distTime < min)
                {
                    index = j;
                    min = distTime;
                }
            }
            S += min;
            checked[index] = true;
            end = index;
        }
        else
        {
            bool fSecond = false;
            for (int j = 0; j < n; ++j)
            {
                if (checked[j])
                    continue;
                double distTime = distTwoPoints(stations[start]->getCoord(), stations[j]->getCoord());
                if (distTime < min)
                {
                    index = j;
                    min = distTime;
                }
            }
            for (int j = 0; j < n; ++j)
            {
                if (checked[j])
                    continue;
                double distTime = distTwoPoints(stations[end]->getCoord(), stations[j]->getCoord());
                if (distTime < min)
                {
                    index = j;
                    min = distTime;
                }
            }
            S += min;
            checked[index] = true;
            if (fSecond)
                end = index;
            else
                start = index;
        }
    }
    return S;
}

street::street(std::string name)
{
    this->setName(name);
}

way::way(std::string name, std::string type)
{
    this->setName(name);
    this->type = type;
}

double way::getDist()
{
    return dist();
}
