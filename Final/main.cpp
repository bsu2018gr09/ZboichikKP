/*
1. (9) Объект содержит информацию для регистрации одного автомобиля с
полями: дата регистрации (самостоятельно надо подумать в каком виде
это удобнее хранить. Поощряется композиция классов!), марка машины,
год выпуска, цвет, гос.номер (можно для упрощения хранить только
цифры). Создать массив объектов (регистрационный список). Разработать
функции для
a) регистрации новой машины;
b) удаления машины из регистрационного списка;
c) поиска автомашин не старше заданного года;
d) поиска автомашин в заданном регионе;
e) сортировки массива объектов по году выпуска.
f) поиска машины по любой комбинации признаков;
 */
#include<iostream>
#include "Car.h"

using namespace std;

Car *initArrayFromFile(int &count);

void writeToFile(Car *arr, int n);

void printArray(Car *arr, int n);

void expandArraySize(Car *&arr, int &size, int add);

void editCar(Car *&arr, int size, int n);

void delCar(Car *&arr, int &size, int n1, int n2);

int findOldCars(Car *arr, int n, Car *&rez, int year);

int findByRegion(Car *arr, int n, Car *&rez, int state);

void initByRandom(Car *&arr, int n, int cnt);

int findByParam(Car *arr, int n, Car *&rez, char *state);

void createFile();

int getFileSize();

int main() {
    setlocale(LC_ALL, "Russian");
    createFile();
    int n, x;
    int cntFile, cntLocal, localSize;
    Car *arrFile = initArrayFromFile(cntFile);
    Car *arrLocal = initArrayFromFile(cntLocal);
    localSize = cntLocal;
    while (1) {
        cout << "\n1-Вывести записи\n2-Новая запись\n3-Редактировать запись\n4-Удаление \n5-Сортировка \n6-Выйти\n";
        cin >> n;
        switch (n) {
            case 1:
                cout << "1-Все записи\n2-По значению \n";
                cin >> x;
                switch (x) {
                    case 1:
                        arrFile = initArrayFromFile(cntFile);
                        printArray(arrFile, cntFile);
                        //printArray(arrLocal, cntLocal);
                        break;
                    case 2:
                        char *tmp = giveMemory<char>(30);
                        cout << "Введите значение, по какому будет поиск\n";
                        cin >> tmp;
                        int localSize2 = 0;
                        Car *rez = giveMemory<Car>(cntFile);
                        arrFile = initArrayFromFile(cntFile);
                        arrLocal = initArrayFromFile(cntLocal);
                        localSize2 = findByParam(arrFile, localSize, rez, tmp);
                        if (localSize2 != 0) {
                            cout << localSize2 << '\n';
                            printArray(rez, localSize2);
                            freeMemory(arrLocal);
                            arrFile = initArrayFromFile(cntFile);
                            arrLocal = initArrayFromFile(cntLocal);
                            freeMemory(rez);
                            freeMemory(tmp);
                        }
                        break;
                }
                break;
            case 2:
                cout << "\n1-Вручную\n2-Случайные\n3-В меню\n";
                cin >> n;
                int cnt;
                if (n == 1) {
                    cnt = 1;

                    if (cnt + cntLocal > localSize) {
                        expandArraySize(arrLocal, localSize, cnt);
                    }
                    for (int i{cntLocal}; i < cntLocal + cnt; ++i) {
                        arrLocal[i].SetId(getFileSize() / 7);
                        int ent, ent2, ent3;

                        cout << "Введите день\n";
                        cin >> ent;
                        cout << "Введите месяц\n";
                        cin >> ent2;
                        cout << "Введите год\n";
                        cin >> ent3;
                        arrLocal[i].SetDate(ent, ent2, ent3);
                        cout << "Введите цвет\n";
                        cin >> ent;
                        arrLocal[i].SetColor(ent);
                        cout << "Введите номер\n";
                        cin >> ent;
                        arrLocal[i].SetStateNumber(ent);
                        cout << "Введите марку\n";
                        char *brand = giveMemory<char>(10);
                        cin >> brand;
                        arrLocal[i].SetBrand(brand);
                    }
                    cntLocal += cnt;
                    printArray(arrLocal, cntLocal);
                    writeToFile(arrLocal, cntLocal);
                    arrFile = initArrayFromFile(cntLocal);
                    break;
                } else if (n == 2) {
                    cout << "Введите количество: \n";
                    cin >> cnt;
                    if (cnt + cntLocal > localSize) {
                        expandArraySize(arrLocal, localSize, cnt);
                    }
                    initByRandom(arrLocal, cntLocal, cnt);
                    cntLocal += cnt;
                    printArray(arrLocal, cntLocal);
                    writeToFile(arrLocal, cntLocal);
                    arrFile = initArrayFromFile(cntLocal);
                    break;
                } else {
                    break;
                }
                break;
            case 3:
                int nmb;
                cout << "\nВведите номер записи, которую хотите изменить ";
                cin >> nmb;
                editCar(arrLocal, cntLocal, nmb);
                writeToFile(arrLocal, cntLocal);
                arrFile = initArrayFromFile(cntLocal);
                break;
            case 4:
                int nbr1;
                int nbr2;
                cout << "\nВведите номера записи, откуда хотите удалить \n";
                cin >> nbr1;
                cout << "\nВведите номера записи, докуда хотите удалить \n";
                cin >> nbr2;
                cout << nbr1 << "-" << nbr2 << '\n';
                delCar(arrLocal, cntLocal, nbr1, nbr2);
                writeToFile(arrLocal, cntLocal);
                printArray(arrLocal, cntLocal);
                arrLocal = initArrayFromFile(cntLocal);
                arrFile = initArrayFromFile(cntLocal);
                break;
            case 5:
                int func;
                cout << "\nВыберите функцию:\n";
                cout << "1-Список машин не старше введенного года\n";
                cout << "2-Список машин в регионе\n";
                cin >> func;
                if (func == 1) {
                    int year;
                    cout << "Введите год: ";
                    cin >> year;
                    Car *rez = giveMemory<Car>(cntLocal);
                    int oldCars = findOldCars(arrLocal, cntLocal, rez, year);
                    printArray(rez, oldCars);
                    freeMemory(rez);
                } else if (func == 2) {
                    int state;
                    cout << "Введите регион: \n";
                    cin >> state;
                    Car *rez = giveMemory<Car>(cntLocal);
                    int region = findByRegion(arrLocal, cntLocal, rez, state);
                    printArray(rez, region);
                    writeToFile(rez, region);
                    arrFile = initArrayFromFile(cntFile);
                    arrLocal = initArrayFromFile(cntLocal);
                }
                break;
            case 6:
                exit(0);
        }
    }
}

