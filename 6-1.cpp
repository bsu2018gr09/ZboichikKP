#include <iostream>
#include <cstring>

using namespace std;

class LinearEquation {
private:
    double a, b, c;
public:
    LinearEquation(double coefA = 0, double coefB = 0, double coefC = 0) : a(coefA), b(coefB), c(coefC) {}

    LinearEquation() : a(0), b(0), c(0) {}

    ~LinearEquation() {}

    void result(LinearEquation equation); //результат

    void print(); //вывод

    bool operator||(LinearEquation equation); // сравнение

    void findZeroX(); //пересечение с X

    void findZeroY(); //пересечение с Y

};

void LinearEquation::findZeroX() {
    double Y;
    if (b == 0 || c == 0) { Y = 0; }
    else {
        Y = c / b;
    }
    cout << Y << '\n';
}

void LinearEquation::findZeroY() {
    double X;
    if (a == 0 || c == 0) { X = 0; }
    else {
        X = c / a;
    }
    cout << X << '\n';
}

void LinearEquation::result(LinearEquation equation) {
    double X;
    double Y;
    //if(a == 0 || equation.a == 0){X = 0; Y = ()return;}
    // else if(a == 0 || equation.b == 0){return;}
    double det = a * equation.b - b * equation.a;
    X = -(c * equation.b - b * equation.c) / det;
    Y = -(a * equation.c - c * equation.a) / det;
    if (det == 0){cout << "X = all" << " " << "Y = all" << '\n';}
    else{cout << "X=" << X << " " << "Y=" << Y << '\n';}
}

void LinearEquation::print() {
    cout << "f(x)=" << a << "x+" << b << "y+" << c << '\n';
}

bool LinearEquation::operator||(LinearEquation equation) {
    if (a == equation.a && b == equation.b && c == equation.c) { return true; }
    else { return false; }
}

int main() {
    LinearEquation First(5, 1, 1);
    LinearEquation Second(1, 1, 1);

    First.print();
    Second.print();

    First.findZeroX();
    First.findZeroY();

    First.result(Second);
    if ((First || Second)) { cout << "функции равны"; }
}