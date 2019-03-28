#include <iostream>
#include "iomanip"

using namespace std;
const int MAX = 255;

//bool findWord(char *m, char);

void giveMemory(char *&);

void deleteMemory(char *&str);

void printArr(string *arr, int);

void sort(string *, int);

void words(char *str);

static char vowels[] = "AaEeIiOoUuYy";

int main() {
    int len = 0;
    char *str = nullptr;
    cout << "Enter string" << '\n';
    giveMemory(str);
    cin.getline(str, 255);
    words(str);
    deleteMemory(str);
}

void giveMemory(char *&str) {
    str = new(nothrow) char[MAX];
    if (!str) {
        cout << "error" << "\n";
    }
}

void words(char *str) {
    int cnt = 0;
    bool flag = false;
    char *pch = strtok(str, " ,.-;");
    string *arr = new string[MAX];
    while (pch != NULL) {
        for (int i{0}; i < 12; i++) {
            if (pch[0] == vowels[i]) {
                flag = true;
            }
        }
        if (flag) {
            arr[cnt] = pch;
            cnt++;
            flag = false;
        }
        pch = strtok(NULL, " ,.-");
    }
    sort(arr, cnt);
    printArr(arr, cnt);
}

void sort(string *arr, int cnt) {
    for (int i{0}; i < cnt; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (arr[j].length() > arr[j + 1].length()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArr(string *arr, int cnt) {
    for (int i{0}; i < cnt; i++) {
        cout << arr[i] << " ";
    }
}

void deleteMemory(char *&str) {
    delete[] str;
    str = nullptr;
}

/*bool findWord(char *str, char letter){
    bool flag = false;
    char *pch = strtok(str, " ,.-;");
    char *pch2;
    pch2 = strtok(NULL, " ,.-;");
    while (pch2) {
        for (int i(0); pch[i] != '\0' || pch2[i] != '\0'; i++) {
            if (pch[i] == letter || pch2[i] == letter) {
                flag = true;
                if ((pch[i] == letter && pch2[i] != letter) || (pch[i] != letter && pch2[i] == letter)) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << pch << "  " << pch2 << '\n';
            flag = false;
        }
        pch = pch2;
        pch2 = strtok(NULL, " ,.-;");
    }
}
 */

