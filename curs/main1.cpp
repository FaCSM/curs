#include <iostream>
#include <windows.h>
#include "ConColor.cpp"

using namespace std;
void SetColor(ConsoleColor text, ConsoleColor background) {
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, (WORD) ((background << 4) | text));
}

void
first() {       //Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.
    SetColor(Magenta, Black);
    cout << "1.Amount of memory occupied by different types of variables (bytes):\n";
    SetColor(Green, Black);
    cout << "          int ";
    SetColor(White, Black);
    cout << sizeof(int) << endl;
    SetColor(Green, Black);
    cout << "    short int ";
    SetColor(White, Black);
    cout << sizeof(short int) << endl;
    SetColor(Green, Black);
    cout << "     long int ";
    SetColor(White, Black);
    cout << sizeof(long int) << endl;
    SetColor(Green, Black);
    cout << "        float ";
    SetColor(White, Black);
    cout << sizeof(float) << endl;
    SetColor(Green, Black);
    cout << "       double ";
    SetColor(White, Black);
    cout << sizeof(double) << endl;
    SetColor(Green, Black);
    cout << "  long double ";
    SetColor(White, Black);
    cout << sizeof(long double) << endl;
    SetColor(Green, Black);
    cout << "         char ";
    SetColor(White, Black);
    cout << sizeof(char) << endl;
    SetColor(Green, Black);
    cout << "         bool ";
    SetColor(White, Black);
    cout << sizeof(bool) << endl;
    SetColor(LightGray, Black);
}

void
second() {      //Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
    int value = -127;
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    SetColor(Magenta, Black);
    cout << "2.print the binary representation of an integer(int)\n";

    SetColor(Yellow, Red);
    putchar(' ');
    SetColor(LightBlue, Black);
    for (int i = 1; i <= order; i++) {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0) {
            SetColor(Yellow, Red);
            putchar(' ');
            SetColor(Yellow, Black);
        }
        if (i % order - 1 == 0) {
            SetColor(Yellow, Red);
            putchar(' ');
            SetColor(Yellow, Black);
        }
    }
    cout << endl;
}

void
third() {       //Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
    union {
        int value;
        float numb_f = 3.14;
    };
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    SetColor(Magenta, Black);
    cout << "3.print the binary representation of float\n";

    SetColor(Yellow, Red);
    putchar(' ');
    SetColor(LightBlue, Black);
    for (int i = 1; i <= order; i++) {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i == 9) {
            SetColor(Yellow, Red);
            putchar(' ');
            SetColor(Yellow, Black);
        }
        if (i == 1) {
            SetColor(Yellow, Red);
            putchar(' ');
            SetColor(LightGreen, Black);
        }
    }
    SetColor(Yellow, Red);
    putchar(' ');
    SetColor(LightGray, Black);
    cout << endl;
}

void
four() {        //Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. (*)
    union {
        int value[2];
        double numb_f = 23.1443;
    };
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    SetColor(Magenta, Black);
    cout << "4.print the binary representation of double\n";

    SetColor(Yellow, Red);
    putchar(' ');
    SetColor(LightBlue, Black);
    for (int i = 1; i <= order; i++) {
        putchar(value[0] & mask ? '1' : '0');
        value[0] <<= 1;
        if (i == 12) {
            SetColor(Yellow, Red);
            putchar(' ');
            SetColor(Yellow, Black);
        }
        if (i == 1) {
            SetColor(Yellow, Red);
            putchar(' ');
            SetColor(LightGreen, Black);
        }
    }
    for (int i = 1; i <= order; i++) {
        putchar(value[1] & mask ? '1' : '0');
        value[1] <<= 1;

    }
    SetColor(Yellow, Red);
    putchar(' ');
    SetColor(LightGray, Black);
    cout<<endl;
}

int main1() {

    int task;
    bool check = true;
    while (check) {
        system("cls");
        SetColor(White, Black);
        cout
                << "Select Task:\n0.Exit\n1.RAM used by variables\n2.View binary of int\n3.View binary of float\n4.View binary of double";
        cin >> task;
        char ch;
        switch (task) {
            case 1:
                first();
                ch = 0;
                cout << "Press |C| to continue...";
                do {
                    std::cin >> ch;
                } while (ch != 'c');
                break;
            case 2:
                second();
                ch = 0;
                cout << "Press |C| to continue...";
                do {
                    std::cin >> ch;
                } while (ch != 'c');
                break;
            case 3:
                third();
                ch = 0;
                cout << "Press |C| to continue...";
                do {
                    std::cin >> ch;
                } while (ch != 'c');
                break;
            case 4:
                four();
                ch = 0;
                cout << "Press |C| to continue...";
                do {
                    std::cin >> ch;
                } while (ch != 'c');
                break;
            case 0:
                check = false;
                break;
        }
    }
}