//Неотрицательные элементы (случайные числа) массива А(N), где N=100000 переставить 
//в конец массива, сохраняя порядок следования.
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.

//написал свой код

#include<iostream>
#include<time.h>

using namespace std;

int *memoryAllocation(int);

void randomInitArray(int *, int);

void printArray(int *, int);

void deleteMemory(int *);

void shiftPositive(int *arr, int, int);

int countOfNeg(int *arr, int N);

void sortNegative(int *arr, int left, int right);

int main() {
    int neg = 0;
    srand(time(0));
    int N;
    cin >> N;
    int *A = memoryAllocation(N);
    randomInitArray(A, N);
   // printArray(A, N);
    neg = countOfNeg(A, N);
    cout << neg << '\n';
    shiftPositive(A, N, neg);
    sortNegative(A,0, neg);
    //printArray(A, N);
    deleteMemory(A);
}

int *memoryAllocation(int N) {
    int *Arr = new(nothrow) int[N];
    if (!Arr) {
        cout << "error" << "\n";
    }
    return Arr;
}

void randomInitArray(int *A, int N) {
    for (int i(0); i < N; ++i) {
        *(A + i) = rand() % 21 - 10;
    }
}

int countOfNeg(int *arr, int N) {
    int neg = 0;
    for (int i(0); i < N; i++) {
        if (arr[i] < 0) {
            neg++;
        }
    }
    return neg;
}

void shiftPositive(int *arr, int N, int neg) {
    int cnt;
    for (int i(0); i < neg;) {
        if (arr[i] >= 0) {
            cnt = arr[i];
            for (int j = i; j < N - 1; j++) {
                arr[j] = arr[j + 1];

            }
            //printArray(arr,N);
            arr[N - 1] = cnt;
        } else {
            i++;
        }
    }
}

void sortNegative(int *arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
        sortNegative(arr, left, j);
    if (i < right)
        sortNegative(arr, i, right);
}

void printArray(int *A, int N) {
    for (int i(0); i < N; ++i) {
        cout << *(A + i) << ";";
        cout << "     ";
    }
    cout << "\n";

}

void deleteMemory(int *A) {
    A = nullptr;
    delete[] A;
}
