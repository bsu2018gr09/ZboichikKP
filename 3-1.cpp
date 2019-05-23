/*Назовём два слова, стоящие рядом, особой парой, если заданная буква встречается в них одинаковое число раз,
 * и номера позиций, в которых она располагается и в том и в другом слове, одинаковы.
 * Вывести на экран все особые пары и удалить их.*/

#include <iostream>//где условие????

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
    char *pch2;
    pch2 = strtok(NULL, " ,.-;");
    while (pch2) {
        for (int i(0); pch[i] != '\0' || pch2[i] != '\0'; i++) {
            if (pch[i] == letter || pch2[i] == letter) {
                flag = true;
                if ((pch[i] == letter && pch2[i] != letter) || (pch[i] != letter && pch2[i] == letter)) {// так не прокатит. Задание на использование функций из библиотеки, а не самопальных...
                    flag = false;//не нашел ни одной функции из библиотек, которая могла бы помочь. 
                    break;
                }
            }
        }
        if (flag) {
            cout << pch << '\n';
            flag = false;
        }
        pch = pch2;
        pch2 = strtok(NULL, " ,.-;");
    }
}

void deleteMemory(char *&str) {
    delete[] str;
    str = nullptr;
}
