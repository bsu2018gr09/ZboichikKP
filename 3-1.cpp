#include <iostream>

using namespace std;
const int MAX = 255;

bool findWord(char *m, char);

void giveMemory(char *&);

void deleteMemory(char *&str);

void printWord(char *str, int len);


int main() {
    int len = 0;
    char letter;
    char *str = nullptr;
    cout << "Enter string" << '\n';


    giveMemory(str);
    cin.getline(str, 255);
    //findWord(letter, str, len);
    //printWord(str, len);
    cout << "Enter letter" << '\n';
    cin >> letter;
    findWord(str, letter);
    deleteMemory(str);
}

void giveMemory(char *&str) {
    str = new(nothrow) char[MAX];
    if (!str) {
        cout << "error" << "\n";
    }
}

bool findWord(char *str, char letter) {
    bool flag = false;
    char *pch = strtok(str, " ,.-;");
    char *pch2 = pch;
    pch2 = strtok(NULL, " ,.-;");
    while (pch) {
        for (int i(0); pch[i] != '\0' && pch2[i] != '\0'; i++) {
            if (pch[i] == letter && pch2[i] == letter) {
                flag = true;
            } else if ((pch[i] != letter && pch2[i] == letter) && (pch[i] == letter && pch2[i] != letter)) { break; }
        }
        pch = pch2;
        if (flag) {
            cout << pch << '\n';
            flag = false;
        }
        pch2 = strtok(NULL, " ,.-;");
    }
}


void printWord(char *str, int len) {
    while (str[len] != ' ') {
        cout << str[len];
        len++;
    }
}

void deleteMemory(char *&str) {
    delete[] str;
    str = nullptr;
}