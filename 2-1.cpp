// В массиве А(N,М) удалить столбцы, все элементы которых являются простыми числами.
#include <iostream>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;

int **memoryAllocation(int, int);

void initArray(int **, int, int);

void printArray(int **, int, int);

int deleteSimpleColom(int **, int, int);

void deleteColom(int **, int, int, int);

bool isSimpleColom(int **, int, int);

bool isSimple(int);

void deleteArray(int **, int, int);

int main() {
    int N, M;
    cout << "Enter N, M" << '\n';
    cin >> N >> M;
    int **Arr = memoryAllocation(N, M);
    initArray(Arr, N, M);
    printArray(Arr, N, M);
    M = deleteSimpleColom(Arr, N, M);
    printArray(Arr, N, M);
    deleteArray(Arr, N, M);
}


int **memoryAllocation(int N, int M) {
    int **Arr = new(nothrow) int *[N];
    for (int i = 0; i < N; ++i) {
        int *p = new(nothrow) int[M];
        *(Arr + i) = p;
    }
    return Arr;
}

void initArray(int **Arr, int N, int M) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int *p1 = *(Arr + i);
        for (int g = 0; g < M; g++) {
            // p1[g] = -10 + (rand() % 21);
            *(p1 + g) = (rand() % 11);
        }
    }
}

void printArray(int **p, int N, int M) {
    for (int i = 0; i < N; i++) {
        int *p1 = *(p + i);
        for (int j = 0; j < M; j++) {
            cout << setw(5) << *(p1 + j);
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isSimple(int a) {
    if (a <= 1) {
        return false;
    }
    for (int j(2); j <= sqrt(a); j++) {
        if (a % j == 0) {
            return false;
        }
    }
    return true;
}

bool isSimpleColom(int **Arr, int j, int N) {
    for (int i = 0; i < N; i++) {
        if (!isSimple(*(*(Arr + i) + j))) { return false; }
    }
    return true;
}

void deleteColom(int **Arr, int j, int N, int M) {
    for (; j < M; j++) {
        for (int i = 0; i < N; i++) {
            *(*(Arr + i) + j) = *(*(Arr + i) + j + 1);
        }
    }
};

int deleteSimpleColom(int **Arr, int N, int M) {
    for (int j = 0; j < M; j++) {
        if (isSimpleColom(Arr, j, N)) {
            deleteColom(Arr, j, N, M);
            --M;
            --j;
        }
    }
    return M;
}

void deleteArray(int **Arr, int N, int M) {
    for (int i = 0; i < N; ++i) {
        delete[] *(Arr + i);
        *(Arr + i) = nullptr;

    }
    delete[] Arr;
    Arr = nullptr;
}

