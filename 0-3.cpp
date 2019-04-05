#include <iostream>
#include <ctime>

using namespace std;

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

void task(int* arr, const int size, const int num) {
    for (int j = num; j > 0; j--) {
        int temp = *(arr + size - 1);
        for (int* i = arr + size - 1; i > arr; i--) {
            *i = *(i - 1);
        }
        *arr = temp;
    }
}

void move(int& num) {
    cout << "Сдвиг массива: ";
    cin >> num;
}

int* getMemory(int size) {
    int* arr = new (nothrow) int[size];
    if (!arr) exit(1);
    return arr;
}

void deleteMemory(int* arr) {
    delete[] arr;
    arr = nullptr;
}

int main() {
    int size, min, max, num;
    numbers(min, max, size);
    int* arr = getMemory(size);
    move(num);
    randomArray(arr, size, min, max);
    write(arr, size);
    task(arr, size, num);
    write(arr, size);
    deleteMemory(arr);
    return 0;
}