//
// Created by Konstantin Zboichik on 2019-06-06.
//
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Car.h"


using namespace std;

char file[] = "/Users/kostyaz/123.txt";

void createFile(){
    ifstream file2(file);
    if(!file2){
        ofstream outfile(file);
        outfile<<"123";
        outfile.close();
    }
    file2.close();
}

int getFileSize() {
    int cnt{0};
    char *tmp = giveMemory<char>(200);
    ifstream fff(file);

    while (1) {
        fff >> tmp;
        ++cnt;
        if (fff.eof())
            break;
    }
    fff.close();
    freeMemory(tmp);
    return cnt;
}

Car *initArrayFromFile(int &count) {
    int cnt = getFileSize();
    cnt /= 7;
    count = cnt;
    Car *arr = giveMemory<Car>(cnt);
    ifstream fff2(file);
    int id, day, month, year, color, stateNumber;
    char *brand = giveMemory<char>(200);
    for (int i{0}; i < cnt; ++i) {
        fff2 >> id;
        arr[i].SetId(id);
        fff2 >> day;
        arr[i].SetDay(day);
        fff2 >> month;
        arr[i].SetMonth(month);
        fff2 >> year;
        arr[i].SetYear(year);
        fff2 >> color;
        arr[i].SetColor(color);
        fff2 >> stateNumber;
        arr[i].SetStateNumber(stateNumber);
        fff2 >> brand;
        arr[i].SetBrand(brand);
    }
    fff2.close();
    freeMemory(brand);

    return arr;
}

void writeToFile(Car *arr, int n) {
    ofstream fff(file, ios::trunc);
    for (int i{0}; i < n; ++i)
        fff << " " << arr[i].GetId() << " " << arr[i].GetDay() << " " << arr[i].GetMonth() << " " << arr[i].GetYear()
            << " " << arr[i].GetColor() << " " << arr[i].GetStateNumber() << " " << arr[i].GetBrand() << '\n';
    //fff << arr[i].() << " " << arr[i].GetName() << " " << arr[i].GetYear() << " " << arr[i].GetCost() << " " << arr[i].GetColor() << "\n";
    fff.close();
}

void printArray(Car *arr, int n) {
    for (int i{0}; i < n; ++i) {
        cout << arr[i];
    }
}

void expandArraySize(Car *&arr, int &size, int add) {
    int tmp = size;
    if (size == 0)
        size = 1;
    while (size < tmp + add)
        size *= 2;
    Car *newArr = giveMemory<Car>(size);
    for (int i{0}; i < tmp; ++i) {
        newArr[i] = arr[i];
    }
    arr = giveMemory<Car>(size);
    for (int i{0}; i < tmp; ++i) {
        arr[i] = newArr[i];
    }
    freeMemory(newArr);
}

void editCar(Car *&arr, int size, int n) {
    if (n < size) {
        Car *tmp = giveMemory<Car>(1);
        cin >> tmp[0];
        arr[n] = tmp[0];
        freeMemory(tmp);
    }
}

void delCar(Car *&arr, int &size, int n1, int n2) {
    int x = n2 - n1;
    //Car *newArr = giveMemory<Car>(size - x);
    for (int i{0}; i < n2 - n1 + 1; ++i) {
        if (n1 + x + i - 1 > size) { break; }
        arr[n1 + i - 1] = arr[n1 + x + i];
    }
    if (n1 < size)
        size -= x;
}

int findOldCars(Car *arr, int n, Car *&rez, int year) {
    int cnt{0};
    for (int i{0}; i < n; ++i) {
        if (arr[i].GetYear() >= year) {
            rez[cnt] = arr[i];
            ++cnt;
        }
    }
    return cnt;
}

int findByRegion(Car *arr, int n, Car *&rez, int state) {
    int cnt{0};
    for (int i{0}; i < n; ++i) {
        if (arr[i].GetStateNumber() % 10 == state) {
            rez[cnt] = arr[i];
            ++cnt;
        }
    }
    return cnt;
}

/*void findByParam(Car *arr, int n, Car *&rez, char* state){
    int cnt{ 0 };
    for (int i{ 0 }; i < n; ++i) {
        if (arr[i].find) {
            rez[cnt] = arr[i];
            ++cnt;
        }
    }
  //  return cnt;
}
*/

void sortByYear(Car *&arr, int start, int end) {
    int i = start, j = end;
    Car *tmp = giveMemory<Car>(1);
    Car pivot = arr[(start + end) / 2];
    while (i <= j) {
        while (arr[i].GetYear() < pivot.GetYear())
            i++;
        while (arr[j].GetYear() > pivot.GetYear())
            j--;
        if (i <= j) {
            tmp[0] = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp[0];
            i++;
            j--;
        }
    };
    if (start < j)
        sortByYear(arr, start, j);
    if (i < end)
        sortByYear(arr, i, end);
}

/*int sortCarsByYear(Car *arr, int n, Car *&rez, char* model) {
    int cnt{ 0 };
    for (int i{ 0 }; i < n; ++i) {
        if (strcmp(arr[i].GetModel(), model) == 0) {
            rez[cnt] = arr[i];
            ++cnt;
        }
    }
    sort(rez, 0, cnt - 1);
    return cnt;
}*/

void initByRandom(Car *&arr, int n, int cnt) {
    srand(time(0));
    char a[10][10] = {"Tesla", "BMW", "Nissan", "Renault", "Geely", "Ford", "Opel", "KIA", "Mazda", "Volvo"};
    for (int i{n}; i < n + cnt; ++i) {
        arr[i].SetId(i);
        arr[i].SetDay(rand() % 30 + 1);
        arr[i].SetMonth(rand() % 12 + 1);
        arr[i].SetYear(rand() % 19 + 2000);
        arr[i].SetStateNumber(rand() % 89999 + 10000);
        arr[i].SetColor(rand() % 10);
        arr[i].SetBrand(a[rand() % 10]);
    }
}

int findByParam(Car *arr, int n, Car *&rez, char *state) {
    int cnt{0};
    bool flag = false;
    // cout << sizeof(state) << '\n';
    //cout << size_t(state) << '\n';
    // cout << sizeof(strtol(state)) << '\n';
    char *pEnd;

    //cout << strtol(state, &pEnd, 10);
    for (int i{0}; i < n; ++i) {
        if (strstr(arr[i].GetBrand(), state) != 0) {
            rez[cnt] = arr[i];
            ++cnt;
            flag = true;
        }
        if (sizeof(state) != 4 && atoi(state) == 0) {
            continue;
        }
        int *nums = giveMemory<int>(5);
        long int cnt2 = strtol(state, &pEnd, 10);
        nums[0] = arr[i].GetDay();
        nums[1] = arr[i].GetStateNumber();
        nums[2] = arr[i].GetMonth();
        nums[3] = arr[i].GetYear();
        nums[4] = arr[i].GetColor();
        unsigned long mod = 10;
        while ((cnt2 % mod) != cnt2) mod *= 10;
        if (!flag) {
            for (int p(0); p < 5; ++p) {
                for (; (nums[p] % mod) != cnt2 && nums[p] > mod; nums[p] /= 10);
                if ((nums[p] % mod) == cnt2) {
                    rez[cnt] = arr[i];
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}


