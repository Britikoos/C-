#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Point {
private:
    int x;
    int y;
public :
    Point() // конструктор точки по умолчанию (0.0)
    {
        x = 0;
        y = 0;
    }

    Point(int t_x, int t_y) { //конструктор точки с координатами t_x and t_y
        this->x = t_x;
        this->y = t_y;
    }

    Point(const Point &other) { //оператор копирования
        this->x = other.x;
        this->y = other.y;
    }

    Point&  operator= (const Point &other){
        if (&other == this)
            return *this;
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    void print_point() {
        cout << "(" << x << ";" << y << ")" << endl;
    }

    int getX() { return this->x; } //геттер

    int getY() { return this->y; }

    //  ~Point()  //деструктор
    //{
    //  cout << "Clean memory" << endl;
    //}

};

class Polyline { //ломанная
private:
    int numOfPoint;
    vector<Point> setPoint;
public:
    Polyline() {
        numOfPoint = 0;
        setPoint.resize(0);
    }

    Polyline(int numOfPoint, Point setPoint[]) {
        this->numOfPoint = numOfPoint;
        for (int i{0}; i < numOfPoint; i++)
            this->setPoint.push_back(setPoint[i]);
        //cout << setPoint;
    }

    Polyline(const Polyline &other) { //??????? вернуться
        this->numOfPoint = other.numOfPoint;
        this->setPoint = other.setPoint;
    }

    Polyline&  operator=(const Polyline &other) = default ;

    int getNumOfPoint() { return numOfPoint; }

    Point getPoint(int num) { return setPoint[num]; }

    int lenVector(Point point1, Point point2) {
        return sqrt(pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2));
    }

    int lenPolyline() {
        int sum{0};
        for (int i{0}; i < getNumOfPoint() - 1; i++)
            sum = sum + lenVector(setPoint[i], setPoint[i + 1]);
        return sum;
    }

    ~Polyline() {}

};

class ClosePolyline : public Polyline { //замкнутая ломанная
private:
public:
    ClosePolyline(int numOfPoint, Point setPoint[])
            : Polyline(numOfPoint, setPoint) {}

    ClosePolyline(const ClosePolyline &other)
            : Polyline(other) {}

    ClosePolyline&  operator=(const ClosePolyline &other) = default ;

    int perimeter() {
        return Polyline::lenPolyline() + lenVector(getPoint(getNumOfPoint() - 1), getPoint(0));
    }

    ~ClosePolyline() {}
};

class Polygon : public ClosePolyline { //многоугольник
public:
    Polygon(int numOfPoint, Point setPoint[])
            : ClosePolyline(numOfPoint, setPoint) {}

    Polygon(const Polygon &other)
            : ClosePolyline(other) {}


    int perimeter() {
        return ClosePolyline::perimeter();
    }

    ~Polygon() {}
};

class Triangle : public ClosePolyline {  //треугольник

    Triangle(int numOfPoint, Point setPoint[])
            : ClosePolyline(numOfPoint, setPoint) {}

    Triangle(const Triangle &other)
            : ClosePolyline(other) {}

    int p() {
        return ClosePolyline::perimeter() / 2;
    }

    //формула герона
    int square() {
        return sqrt(p() * (p() - lenVector(getPoint(0), getPoint(1))) * (p() - lenVector(getPoint(1), getPoint(2))) *
                    (p() - lenVector(getPoint(2), getPoint(0))));
    }

    ~Triangle() {};
};

class Trapezoid : public ClosePolyline { //трапеция

    Trapezoid(int numOfPoint, Point setPoint[])
            : ClosePolyline(numOfPoint, setPoint) {}

    Trapezoid(const Trapezoid &other)
            : ClosePolyline(other) {}

    int perimeter() {
        return ClosePolyline::perimeter();
    }

    int square() {
        int a, b, h, ab;
        a = lenVector(getPoint(0), getPoint(1));
        b = lenVector(getPoint(2), getPoint(3));
        ab = lenVector(getPoint(1), getPoint(3));
        h = sqrt(pow(ab, 2) - pow(abs(b - a), 2));
        return abs(a - b) * 0, 5 * h;
    }

    ~Trapezoid() {}
};

class RegPolygon : public Polygon { //правильный многоугольник
    RegPolygon(int numOfPoint, Point setPoint[])
            : Polygon(numOfPoint, setPoint) {}

    RegPolygon(const RegPolygon &other)
            : Polygon(other) {}

     RegPolygon& operator=(const RegPolygon &other) = default;

    int square(int numOfPoint) {
        return (numOfPoint * pow(lenVector(getPoint(0), getPoint(1)), 2)) / (4 * tan(180 / numOfPoint));
    }

    int perimeter(int numOfPoint) {
        return lenVector(getPoint(0), getPoint(1)) * numOfPoint;
    }

    ~RegPolygon() {}
};


int main() {
    cout << "point" << endl;
    int x, y;
    cin >> x >> y;
    Point A(x, y);
    A.print_point();
    cin >> x >> y;
    Point B(x, y);
    B.print_point();

    cout << "polyline" << endl;
    int numOfPoint;
    int z, w;
    cin >> numOfPoint;
    Point setPoint[numOfPoint];
    for (int i; i < numOfPoint; i++) {
        cin >> z >> w;
        setPoint[i] = Point(z, w);
    }
    Polyline ABCD(numOfPoint, setPoint);
    int num;
    cin >> num;
    ABCD.getPoint(num);


    return 0;
}
