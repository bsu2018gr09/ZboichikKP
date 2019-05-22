#include <iostream>
#include <iomanip>
#include <fstream>
#include <clocale>
#include <cstring>
#include <string.h>

//В тексте выбрать все слова, начинающиеся с гласных букв, и расположить их в порядке возрастания
// количества букв в слове.

using namespace std;
const int MAX = 1000000;
int slowa = 0;

void swapStr(char *a, char *b);

void printArr(char **arr);

void fullWords(char **arr);

void sort(char **arr);

static char vowelsEn[] = "AaEeIiOoUuYy";
static char vowelsRus[] = "А а Е е И и О о У у Ы ы Э э Я я ";


int main() {
    char **arr = new(nothrow) char *[MAX];
    if (!arr) {
        cout << "Can't create array";
        exit;
    }
    fullWords(arr);
    sort(arr);
    printArr(arr);
}


//тут читаем файл, разбиваем на слова, и записываем их в массив, если они начинаются на гласную
void fullWords(char **arr) {
    char *buff = new char[MAX];
    ifstream file1("/Users/kostyaz/dev/Barvenov/tom2.txt");
    if (!file1) {
        cout << "No file /Users/kostyaz/dev/Barvenov/tom2.txt. Can't create\n";
        exit(1);
    }
    while (1) {
        file1.getline(buff, MAX - 1);
        if (file1.fail()) file1.clear();
        if (file1.eof()) break;
        char *pch = strtok(buff, " ,.-;\'\"?!-:”—");
        while (pch != NULL) {
            for (int i = 0; i < 12; i++) {
                if (pch[0] == vowelsEn[i]) {
                    arr[slowa] = new (nothrow) char[20];
                    strcpy(arr[slowa], pch);
                    slowa++;
                }
            }
            pch = strtok(NULL, " ,.-;\'\"”?!-:—");
        }
    }
    file1.close();
}
// тут обмен слов в массиве
void swapStr(char *a, char *b) {
    char *tmp = new(nothrow) char[15];
    strcpy(tmp, b);
    strcpy(b, a);
    strcpy(a, tmp);
}

//сортировка пузырьком(
void sort(char **arr) {
    ifstream file1("/Users/kostyaz/dev/Barvenov/file2.txt");
    if (!file1) {
        cout << "No file d:\\date2.txt. Can't create\n";
        exit(1);
    }
    for (int i = 0; i < slowa; i++) {
        for (int j = 0; j < slowa - i - 1; j++) {
            if (strlen(arr[j]) < strlen(arr[j+1])) {
                swapStr(arr[j], arr[j+1]);
            }
        }
    }

}

//вывод
void printArr(char **arr) {
    ofstream file1("/Users/kostyaz/dev/Barvenov/file2.txt");
    for (int i = 0; i < slowa; i++) {
        file1 << arr[i] << '\n';
       // cout << arr[i] << '\n';
    }
    file1.close();
}
