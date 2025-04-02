#include <iostream>
#include <cstdio>
using namespace std;

class Point {
private:
    double x, y, z;
	// It's only for me

public:
    Point() : x(0), y(0), z(0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double val) { x = val; }
    void setY(double val) { y = val; }
    void setZ(double val) { z = val; }

    void saveToFile(const char* filename) const {
        FILE* file = fopen(filename, "w");
        if (file) {
            fprintf(file, "%f %f %f", x, y, z);
            fclose(file);
            cout << "Point saved to " << filename << endl;
        }
        else {
            cout << "Error opening file for writing" << endl;
        }
    }

    void loadFromFile(const char* filename) {
        FILE* file = fopen(filename, "r");
        if (file) {
            int read = fscanf(file, "%lf %lf %lf", &x, &y, &z);
            fclose(file);
            if (read == 3) {
                cout << "Point loaded from " << filename << endl;
            }
            else {
                cout << "Error reading data from file" << endl;
            }
        }
        else {
            cout << "Error opening file for reading" << endl;
        }
    }

    void print() const {
        cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Point p(1.5, 2.5, 3.5);

    p.saveToFile("point.txt");

    Point p2;
    p2.loadFromFile("point.txt");
    p2.print();

    return 0;
}