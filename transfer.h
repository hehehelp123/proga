#pragma once
#include <iostream>
#include "src/pugixml.hpp"
#include "src/pugiconfig.hpp"
#include <vector>
#include <windows.h>
#include <map>
#include "transfer.h"

class point {
    std::string vehicle;
    std::vector<std::string> numbers, street;
    int number;
    std::pair<double, double> location;
public:
    explicit point(std::string vehicle, std::vector<std::string> street, std::vector<std::string> numbers, std::pair<double, double> location, int number);
    void out();
    std::pair<double, double> getCoord();
};

class line {
    int n = 0;
    std::string name = "";
    std::vector<point*> stations;
public:
    line() = default;
    void add(point* x);
    void setName(std::string s);
    std::string getName();
    int getN();
    double dist();
};

class street : public line {
public:
    explicit street(std::string name = "");
};

class way : public line {
    std::string type = "";
public:
    explicit way(std::string name = "", std::string type = "");
    double getDist();
};