// В массиве размера N, заполненного случ.числами от 0 до 10, 
// подсчитать количество элементов, встречающихся более одного раза.

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void numbers(int& a, int& b, int& size) {
    cout << "Диапазон чисел (a,b): ";
    cin >> a >> b;
    cout << "Размер массива: ";
    cin >> size;
}

void randomArray(int* arr, int size, const int min, const int max) {
    srand(time(0));
    while (size > 0) { *(arr + size) = rand() % (max - min) + min; size--; }
}

void sort(int* arr, const int size) {
    for (int* i = arr + 1; i < arr + size; i++)
        for (int* j = i; j >= arr && *(j - 1) > *j; j--) swap(*(j - 1), *j);
}

void task(int* arr, const int size) {
    int cnt = 0;
    for (int* i = arr; i < arr + size;) {
        int j = 0;
        while (++i < arr + size && *i == *(i - 1))
            j++;
        if (j != 0)
            cnt += j + 1;
    }
    cout << "Число элементов: " << cnt << endl;
}

void write(int* arr, const int size) {
    cout << "Массив: ";
    for (int* i = arr; i < arr + size; i++) {
        cout << *i << " ";
    }
    cout << endl;
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
    int size, min, max;
    numbers(min, max, size);
    int* arr = getMemory(size);
    randomArray(arr, size, min, max);
    write(arr, size);
    sort(arr, size);
    task(arr, size);
    deleteMemory(arr);
    return 0;
}