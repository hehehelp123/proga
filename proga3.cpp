#include <iostream>
#include "src/pugixml.hpp"
#include "src/pugiconfig.hpp"
#include <vector>
#include <windows.h>
#include <map>
#include "transfer.h"

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    pugi::xml_document doc;
    pugi::xml_parse_result res = doc.load_file("data.xml");
    pugi::xml_node st = doc.child("dataset");
    std::string vehicleCur, streetCur, routesCur, locationCur;
    int numberCur;
    std::vector<point*> stations;
    std::vector<std::string> numbers;
    std::vector<std::string> strTime;
    std::map < std::pair<std::string, std::string>, way > ways;
    std::map<std::string, street> streets;
    std::pair<double, double> coord;
    for (pugi::xml_node curPoint : st.children("transport_station"))
    {
        numbers.resize(0);
        strTime.resize(0);
        int k = 0;
        for (pugi::xml_node prop : curPoint.children())
        {
            std::string x = "";
            switch (k)
            {
            case 0:
                numberCur = std::stoi(prop.child_value());
                break;
            case 1:
                vehicleCur = prop.child_value();
                break;
            case 5:
                streetCur = prop.child_value();
                for (int i = 0; i < streetCur.size(); ++i)
                {
                    if (streetCur[i] == ',')
                    {
                        if (x != "") strTime.push_back(x);
                        x = "";
                        ++i;
                        continue;
                    }
                    x += streetCur[i];
                }
                if (x != "") strTime.push_back(x);

                break;
            case 6:
                routesCur = prop.child_value();
                for (int i = 0; i < routesCur.size(); ++i)
                {
                    if (routesCur[i] == '.' || routesCur[i] == ',')
                        routesCur[i] = ' ';
                }
                for (int i = 0; i < routesCur.size(); ++i)
                {
                    if (routesCur[i] == ' ')
                    {
                        if (x != "") numbers.push_back(x);
                        x = "";
                        continue;
                    }
                    x += routesCur[i];
                }
                if(x != "") numbers.push_back(x);
                break;
            case 7:
                locationCur = prop.child_value();
                std::string l1 = locationCur;
                std::string l2 = locationCur;
                int fl = 0;
                for (int i = 0; i < locationCur.size(); ++i)
                {
                    if (!fl)
                    {
                        if (locationCur[i] == ',')
                        {
                            l1[i] = '0';
                            l2[i] = '0';
                            fl = 1;
                            continue;
                        }
                        if (l1[i] == ',')
                            l1[i] = '.';
                        l2[i] = '0';
                    }
                    else
                    {
                        if (l2[i] == ',')
                            l2[i] = '.';
                        l1[i] = '0';
                    }
                }
                coord = std::make_pair(std::stod(l1), std::stod(l2));
            }
            k++;
        }
        stations.push_back(new point(vehicleCur, strTime, numbers, coord, numberCur));
        for (int i = 0; i < strTime.size(); ++i)
        {
            if (streets.find(strTime[i]) == streets.end())
            {
                streets[strTime[i]] = street(strTime[i]);
            }
            streets[strTime[i]].add(stations[stations.size() - 1]);
        }
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (ways.find(make_pair(numbers[i], vehicleCur)) == ways.end())
            {
                ways[make_pair(numbers[i], vehicleCur)] = way(numbers[i]);
            }
            ways[make_pair(numbers[i], vehicleCur)].add(stations[stations.size() - 1]);
        }
    }
    //stations[0].out();
    // Первое задание
    int max = -1;
    std::string name;
    std::string dataType[3] = { "Автобус", "Троллейбус", "Трамвай" };
    for (std::string type : dataType)
    {
        max = -1;
        for (auto x : ways)
        {
            if (x.second.getN() > max && x.first.second == type)
            {
                max = x.second.getN();
                name = x.second.getName();
            }
        }
        std::cout << type << " " << max << " " << name << std::endl;
    }
    
    std::cout << std::endl;
    // Второе задание
    double maxDist = INT_MIN;
    way k;
    double g;
    for (std::string type : dataType)
    {
        maxDist = INT_MIN;
        for (auto &x : ways)
        {
            if (x.first.second == type)
            {
                g = x.second.getDist();
                if (maxDist < g)
                {
                    maxDist = g;
                    k = x.second;
                }
            }
        }
        std::cout << type << " " << k.getName() << std::endl;
    }
    
    // Третье задание
    max = -1;
    for (auto x : streets)
    {
        if (x.second.getN() > max)
        {
            max = x.second.getN();
            name = x.second.getName();
        }
    }
    std::cout << std::endl << name << " " << max << std::endl;
    for (int i = 0; i < stations.size(); ++i)
    {
        delete(stations[i]);
    }
}
