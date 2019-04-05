#include<iostream>
#include<fstream>

using namespace std;
struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} c;
struct color2 {
    float r;
    float g;
    float b;
} d;


int main() {
    ifstream fff("/Users/kostyaz/dev/Barvenov/4.bmp", ios::binary); //  ios::binary влияет ТОЛЬКО на endl.
    ofstream ggg("/Users/kostyaz/dev/Barvenov/2.bmp",
                 ios::binary);//сюда пишем (поток типа ofstream= output file stream)
    if (!fff) {
        cout << "No file d:\\1.bmp. Can't open\n";
        exit(1);
    }
    if (!ggg) {
        cout << " file d:\\rez.bmp. Can't create\n";
        exit(1);
    }

    char buf[30];// куда читать байты
    unsigned char r, g, b;//компоненты цвета
    color c;
    unsigned int w, h;//надеемся. что тут 4 байта

    fff.read((char *) &buf, 18); //чтение 18 байт заголовка bmp
    ggg.write((char *) &buf, 18); //запись 18 байт заголовка bmp
    fff.read((char *) &w, 4);
    cout << "w=" << w; //чтение width из заголовка bmp
    fff.read((char *) &w, 4);
    cout << ", h=" << w; //чтение height из заголовка bmp
    w = 128;
    ggg.write((char *) &w,
              4); //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
    h = 256;
    ggg.write((char *) &h, 4); //запись height в заголовок bmp
    fff.read((char *) &buf, 28); //чтение 28 байт заголовка bmp
    ggg.write((char *) &buf, 28); //запись 28 байт заголовка bmp

    c.r = 128; //первый цвет градиента
    c.g = 16;
    c.b = 77;

    float r2 = 254;
    float g2 = 46;
    float b2 = 99;

    int step = 150;

  //  float w2 = w / 2.52;

    float stepr = (r2 - c.r) / step;
    float stepg = (g2 - c.g) / step;
    float stepb = (b2 - c.b) / step;
    cout << "  " << stepr << "   ";

    d.r = (float) c.r;
    d.g = (float) c.g;
    d.b = (float) c.b;


    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ggg.write((char *) &c, 3); //запись сразу всего цвета
                d.b = stepb + d.b;
                d.g = stepg + d.g;
                d.r = stepr + d.r;

            c.b = (unsigned char) d.b;
            c.g = (unsigned char) d.g;
            c.r = (unsigned char) d.r;

        }

        c.r = 128; //первый цвет градиента
        c.g = 16;
        c.b = 77;

        d.r = (float) c.r;
        d.g = (float) c.g;
        d.b = (float) c.b;


    }
    /*for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ggg.write((char *)&c, 3);
            c.b = c.b + stepb;
            c.g = c.g + stepg;
            c.r = c.r + stepr;
        }
        c.r = 128; c.g = 16; c.b = 77;
    }
*/
    fff.close();//закрыли файл
    ggg.close();//закрыли файл
    return 1;
}

