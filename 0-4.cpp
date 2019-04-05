//  Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.

#include <iostream>
#include <ctime>

using namespace std;

void move(int& num) {
    cout << "Номер элемента:";
    cin >> num;
}

void numbers(int& min, int& max, int& size) {
    cout << "Диапазон чисел (a,b): ";
    cin >> min >> max;
    cout << "Размер массива: ";
    cin >> size;
}

void randomArray(int* arr, int size, const int min, const int max) {
    srand(time(0));
    for (int i = 0; i < size; i++) *(arr + i) = rand() % 10;
}

void write(int* arr, const int size) {
    cout << "Массив: ";
    for (int* i = arr; i < arr + size; i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void sort(int* arr, const int size, const int num) {
    for (int* i = arr + 1 + num; i < arr + size; i++)
        for (int* j = i; j >= arr + num && *(j - 1) > *j; j--) swap(*(j - 1), *j);
}

void getMemory(int*& arr, int size) {
    arr = new (nothrow) int[size];
    if (!arr) exit(1);
}

void deleteMemory(int* arr) {
    delete[] arr;
    arr = nullptr;
}
int main() {

    int size, min, max, num;
    numbers(min, max, size);
    int* arr;
    getMemory(arr, size);
    move(num);
    randomArray(arr, size, min, max);
    write(arr, size);
    sort(arr, size, num);
    write(arr, size);
    deleteMemory(arr);
    return 0;
}