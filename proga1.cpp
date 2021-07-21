// proga1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

class CPoint
{
    float x, y;
public:
    explicit CPoint(float a = 0, float b = 0) :
        x(a), y(b)
    {
    }
    CPoint(const CPoint& obj) :
        x(obj.x), y(obj.y)
    {
    }
    float X() const
    {
        return x;
    }
    float Y() const
    {
        return y;
    }
    CPoint& operator=(const CPoint& obj)
    {
        x = obj.x;
        y = obj.y;
        return *this;
    }
};

class CPolyline
{
protected:
    vector <CPoint> points;
    bool Check()
    {
        return true;
    }
public:
    explicit CPolyline(vector <CPoint> pointsInp) :
        points(pointsInp)
    {
    }
    explicit CPolyline(const CPolyline& obj) :
        points(obj.points)
    {
    }
    CPolyline& operator=(const CPolyline& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        points = obj.points;
    }
    void out()
    {
        cout << "Points: " << endl;
        for (int i = 0; i < points.size(); ++i)
        {
            cout << points[i].X() << " " << points[i].Y() << endl;
        }
    }
};

class CClosedPolyLine : public CPolyline
{
protected:
    bool Closed = true;
public:
    explicit CClosedPolyLine(vector <CPoint> pointsInp):
        CPolyline(pointsInp)
    {
    }
    explicit CClosedPolyLine(const CClosedPolyLine& obj) :
        CPolyline(obj.points)
    {
    }
    CClosedPolyLine& operator=(const CClosedPolyLine& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        points = obj.points;
    }
};

class CPolygon : public CClosedPolyLine
{
protected:
    bool exist = true;
    int scal(CPoint a, CPoint b, CPoint c)
    {
        int y = -(a.Y() - b.Y()) * (a.X() - c.X()) + (a.X() - b.X()) * (a.Y() - c.Y());
        if (y > 0) 
            return 1;
        if (y < 0)
            return -1;
        return 0;
    }
    bool Check() 
    {
        for (int i = 0; i < points.size() - 1; ++i)
        {
            int sign = -2;
            for (int j = 0; j < points.size(); ++j)
            {
                if (j == i || j == i + 1) continue;
                if (sign == -2 || sign == 0)
                {
                    sign = scal(points[i], points[i + 1], points[j]);
                }
                if (sign != scal(points[i], points[i + 1], points[j]) && scal(points[i], points[i + 1], points[j]) != 0) return false;
            }
        }
        return true;
    }
public:
    explicit CPolygon(vector <CPoint> pointsInp):
        CClosedPolyLine(pointsInp)
    {
        if (Check())
            return;
        points.resize(0);
        exist = false;
        cout << "incorrect polygon" << endl;
    }
    explicit CPolygon(const CPolygon& obj) :
        CPolygon(obj.points)
    {
    }
    CPolygon& operator=(const CPolygon& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        points = obj.points;
        if (Check())
            return *this;
        points.resize(0);
        exist = false;
        cout << "incorrect polygon" << endl;
        return *this;
    }
    float area()
    {
        float s = 0;
        for (int i = 0; i < points.size() - 1; ++i)
        {

            s += points[i].X() * points[i + 1].Y();
            s -= points[i + 1].X() * points[i].Y();
        }
        s += points[points.size() - 1].X() * points[0].Y();
        s -= points[points.size() - 1].Y() * points[0].X();
        s = abs(s) / 2;
        return s;
    }
    float perimeter()
    {
        float p = 0;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            p += sqrt((points[i].X() - points[i + 1].X()) * (points[i].X() - points[i + 1].X()) + (points[i].Y() - points[i + 1].Y()) * (points[i].Y() - points[i + 1].Y()));
        }
        p += sqrt((points[0].X() - points[points.size() - 1].X()) * (points[0].X() - points[points.size() - 1].X()) + (points[0].Y() - points[points.size() - 1].Y()) * (points[0].Y() - points[points.size() - 1].Y()));
        return p;
    }
};

class CTriangle : public CPolygon
{
protected:
    void newCheck() 
    {
        if (points.size() != 3)
        {
            points.resize(0);
            cout << "Incorrect triangle" << endl;
            return;
        }
        if (scal(points[0], points[1], points[2]) == 0)
        {
            points.resize(0);
            cout << "Incorrect triangle" << endl;
            return;
        }
    }
public:
    explicit CTriangle(vector <CPoint> pointsInp):
        CPolygon(pointsInp)
    {
        newCheck();
    }
    explicit CTriangle(const CTriangle& obj) :
        CTriangle(obj.points)
    {
    }
    CTriangle& operator=(const CTriangle& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        points = obj.points;
        if (Check())
        {
            points.resize(0);
            exist = false;
            cout << "incorrect polygon" << endl;
        }
        newCheck();
        return *this;
    }
};

class CTrapezoid : public CPolygon
{
protected:
    void newCheck()
    {
        if (points.size() != 4)
        {
            points.resize(0);
            cout << "Incorrect trapezoid" << endl;
            return;
        }
        if (scal(points[0], points[1], CPoint(points[2].X() - points[3].X() + points[0].X(), points[2].Y() - points[3].Y() + points[0].Y())) != 0 && scal(points[1], points[2], CPoint(points[3].X() - points[0].X() + points[1].X(), points[3].Y() - points[0].Y() + points[1].Y())) != 0)
        {
            points.resize(0);
            cout << "Incorrect trapezoid" << endl;
            return;
        }
    }
public:
    explicit CTrapezoid(vector <CPoint> pointsInp) :
        CPolygon(pointsInp)
    {
        newCheck();
    }
    explicit CTrapezoid(const CTrapezoid& obj) :
        CTrapezoid(obj.points)
    {
    }
    CTrapezoid& operator=(const CTrapezoid& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        points = obj.points;
        if (Check())
        {
            points.resize(0);
            exist = false;
            cout << "incorrect polygon" << endl;
        }
        newCheck();
        return *this;
    }
};

class CRightPolygon : public CPolygon
{
protected:
    void newCheck()
    {
        if (points.size() < 3)
        {
            points.resize(0);
            cout << "Incorrect right polygon" << endl;
            return;
        }
        int d = -1;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            if (d < 0)
            {
                d = sqrt((points[i].X() - points[i + 1].X()) * (points[i].X() - points[i + 1].X()) + (points[i].Y() - points[i + 1].Y()) * (points[i].Y() - points[i + 1].Y()));
            }
            if (d != sqrt((points[i].X() - points[i + 1].X()) * (points[i].X() - points[i + 1].X()) + (points[i].Y() - points[i + 1].Y()) * (points[i].Y() - points[i + 1].Y())))
            {
                points.resize(0);
                cout << "Incorrect right polygon" << endl;
                return;
            }
        }
    }
public:
    explicit CRightPolygon(vector <CPoint> pointsInp) :
        CPolygon(pointsInp)
    {
        newCheck();
    }
    explicit CRightPolygon(const CRightPolygon& obj) :
        CRightPolygon(obj.points)
    {
    }
    CRightPolygon& operator=(const CRightPolygon& obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        points = obj.points;
        if (Check())
        {
            points.resize(0);
            exist = false;
            cout << "incorrect polygon" << endl;
        }
        newCheck();
        return *this;
    }
};

int main()
{
    vector <CPoint> a = { CPoint(0, 1),CPoint(1, 1), CPoint(1, 0), CPoint(0, 0)};
    vector <CPoint> b = { CPoint(4, 56), CPoint(2, 7), CPoint(24, 5), CPoint(4, 10) };
    vector <CPoint> g = { CPoint(1, 1), CPoint(10, 10), CPoint(140, 100), CPoint(40, 0) };
    vector <CPoint> e = { CPoint(1, 1), CPoint(10, 10), CPoint(140, 100)};
    CClosedPolyLine* c;
    CClosedPolyLine* r;
    c = new CClosedPolyLine(a);
    r = new CClosedPolyLine(b);
    c->out();
    r->out();
    c = r;
    r = new CClosedPolyLine({ CPoint(0, 0) });
    c->out();
    r->out();
    CPoint* w = new CPoint(0, 0);
    delete w;
    CPolygon* d = new CPolygon(a);
    CPolygon* f = new CPolygon(b);
    cout << d->area() << " " << d->perimeter() << endl;
    CTrapezoid* tr = new CTrapezoid(g);
    CTriangle* triang = new CTriangle(e);
    CRightPolygon* y = new CRightPolygon(a);
    vector<CPolygon*> polygons;
    polygons.push_back(tr);
    polygons.push_back(triang);
    polygons.push_back(y);
    for (int i = 0; i < polygons.size(); ++i)
    {
        cout << "polygon:" << endl;
        polygons[i]->out();
        cout << polygons[i]->area() << " " << polygons[i]->perimeter() << endl << endl;
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
