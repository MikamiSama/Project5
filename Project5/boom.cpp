#include <iostream>
using namespace std;

class Point {
    double x, y, z;

public:
    Point() : x(0), y(0), z(0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double val) { x = val; }
    void setY(double val) { y = val; }
    void setZ(double val) { z = val; }

    void display() const {
        cout << "Point: (" << x << ", " << y << ", " << z << ")\n";
    }

    void serialize() const {
        cout << "SERIALIZED: " << x << " " << y << " " << z << "\n";
    }

    void deserialize() {
        cout << "Enter serialized point (x y z): ";
        cin >> x >> y >> z;
    }
};

int main() {
    Point p1(1.0, 2.0, 3.0);
    p1.display();

    cout << "\nSerializing point:\n";
    p1.serialize();

    Point p2;
    cout << "\nDeserializing new point:\n";
    p2.deserialize();
    p2.display();

    return 0;
}