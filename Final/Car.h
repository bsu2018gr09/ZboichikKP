//
// Created by Konstantin Zboichik on 2019-06-06.
//

#ifndef FINAL7_1_CAR_H
#define FINAL7_1_CAR_H
#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;


template<class T>
T *giveMemory(int n) {
    T *arr = new(nothrow) T[n];
    if (!arr) {
        cout << "Can't give memory";
        exit(0);
    }
    return arr;
}

template<class T>
void freeMemory(T *&arr) {
    delete[]arr;
    arr = nullptr;
}


class Car {
private:
    int day;
    int month;
    int year;
    char *brand;
    int color;
    int stateNumber;
    int id;

public:
    Car() : id{0}, stateNumber{0}, brand{giveMemory<char>(5)}, color{0}, day{0}, month{0}, year{0} {
        strcpy(brand, "null");
    }

    Car(int _id, int _stateNum, char *_br, int _d, int _m, int _y, int _color) : id{_id},
                                                                                 stateNumber{_stateNum},
                                                                                 brand{giveMemory<char>(
                                                                                         strlen(_br) + 1)},
                                                                                 color{_color}, day{_d},
                                                                                 month{_m}, year{_y} {
        strcpy(brand, _br);
    }

    Car(Car const &tmp) : id{tmp.id}, stateNumber{tmp.stateNumber},
                          brand{giveMemory<char>(strlen(tmp.brand) + 1)}, color{tmp.color},
                          day{tmp.year}, month{tmp.month}, year{tmp.year} {}

    ~Car() {
        freeMemory<char>(brand);
    }

    void SetDay(int i) {
        day = i;
    }

    void SetMonth(int i) {
        month = i;
    }

    void SetYear(int i) {
        year = i;
    }

    void SetColor(int i) {
        color = i;
    }

    void SetId(int i) {
        id = i;
    }

    void SetBrand(char *i) {
        strcpy(brand, i);
    }

    void SetStateNumber(int i) {
        stateNumber = i;
    }

    int GetColor() {
        return color;
    }

    int GetDay() {
        return day;
    }

    int GetMonth() {
        return month;
    }

    int GetYear() {
        return year;
    }


    int GetId() {
        return id;
    }

    char *GetBrand() {
        return brand;
    }

    int GetStateNumber() {
        return stateNumber;
    }


    friend ostream &operator<<(ostream &os, Car const &t) {
        os << "Id: " << t.id << " Day: " << setw(2) << setfill('0') << t.day << "." << setw(2) << setfill('0')
           << t.month << "." << setw(4) << setfill('0') << t.year << " Color: " << t.color << " state: "
           << t.stateNumber << " brand: " << t.brand << "\n";
        return os;
    }

    friend istream &operator>>(istream &is, Car &t) {
        cout << "Day: ";
        is >> t.day;
        cout << "Month: ";
        is >> t.month;
        cout << "Year: ";
        is >> t.year;
        cout << "color: ";
        is >> t.color;
        cout << "State Number: ";
        is >> t.stateNumber;
        cout << "brand: ";
        is >> t.brand;
        cout << "\n";
        return is;
    }

};


#endif //FINAL7_1_CAR_H
