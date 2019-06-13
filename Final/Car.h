//
// Created by Konstantin Zboichik on 2019-06-06.
//

#ifndef FINAL7_1_CAR_H
#define FINAL7_1_CAR_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
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


using namespace std;
typedef int type;

class Car {

private:
    class Date {
    private:
        int day;
        int month;
        int year;

    public:
        Date() : day{0}, month{0}, year{0} {}

        Date(int _day, int _month, int _year) : day{_day}, month(_month), year{_year} {}

        ~Date() {

        }

        void SetDay(int i) {
            day = i;//прямо вот без проверок и прочего? Почему бы тогда просто не сделать public все поля. Раз так запросто пишем туда
        }

        int GetDay() {
            return day;
        }

        void SetMonth(int i) {
            month = i;//прямо вот без проверок и прочего? Почему бы тогда просто не сделать public все поля. Раз так запросто пишем туда

        }

        int GetMonth() {
            return month;

        }

        void SetYear(int i) {
            year = i;//прямо вот без проверок и прочего? Почему бы тогда просто не сделать public все поля. Раз так запросто пишем туда
        }

        int GetYear() {
            return year;

        friend ostream &operator<<(ostream &os, Date const &t) {
            os << " Date: " << setw(2) << setfill('0') << t.day << "." << setw(2) << setfill('0') << t.month << "."
               << setw(4) << setfill('0') << t.year << " ";
            return os;
        }

        friend istream &operator>>(istream &is, Date &t) {
            cout << "Day: ";
            is >> t.day;
            cout << "Month: ";
            is >> t.month;
            cout << "Year: ";
            is >> t.year;
            return is;
        }


    };

    char *brand;
    int color;
    int stateNumber;
    int id;
    Date date;

public:
    Car() : id{0}, stateNumber{0}, brand{giveMemory<char>(5)}, color{0} {//потенциально ОЧЕНЬ опасное место!!! Не в том порядке инициализируются!!!!!
        strcpy(brand, "null");
    }

    Car(int _id, int _stateNum, char *_br, int _d, int _m, int _y, int _color) : id{_id},
                                                                                 stateNumber{_stateNum},
                                                                                 brand{giveMemory<char>(
                                                                                         strlen(_br) + 1)},
                                                                                 color{_color} {//потенциально ОЧЕНЬ опасное место!!! Не в том порядке инициализируются!!!!!
        strcpy(brand, _br);
    }

    Car(Car const &tmp) : id{tmp.id}, stateNumber{tmp.stateNumber},
                          brand{giveMemory<char>(strlen(tmp.brand) + 1)}, color{tmp.color} {}//и вот, не скопируем бренд? Только память выделим?

    ~Car() {
        freeMemory<char>(brand);
    }

    void SetDate(int _day, int _month, int _year) {
        date.SetDay(_day);
        date.SetMonth(_month);
        date.SetYear(_year);
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
        return date.GetDay();
    }

    int GetMonth() {
        return date.GetMonth();
    }

    int GetYear() {
        return date.GetYear();
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
        os <</* "Id: " << t.id <<*/ t.date << " Color: " << t.color << " State: "
           << t.stateNumber << " Brand: " << t.brand << "\n";
        return os;
    }

    friend istream &operator>>(istream &is, Car &t) {
   //     cout << "Id: ";
     //   is >> t.id;
        cout << "Date: ";
        is >> t.date;
        cout << "Color: ";
        is >> t.color;
        cout << "State Number: ";
        is >> t.stateNumber;
        cout << "Brand: ";
        is >> t.brand;
        cout << "\n";
        return is;
    }

};

#endif //FINAL7_1_CAR_H
