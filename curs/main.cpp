#include <iostream>
#include "main1.cpp"
#include "main2.cpp"
#include "main3.cpp"
#include "main4.cpp"
#define clear() system("cls")
using namespace std;
int task;
void SetConColor(ConsoleColor text, ConsoleColor background) {
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, (WORD) ((background << 4) | text));
}
int main() {
    system("mode con cols=160 lines=50");
    while (true) {
        system("title Main Menu");
        SetConColor(Red,Black);
        cout<<"\n"
              "        /@@@(             @@@@                      @@/                             @@@@             (@&@*                                                \n"
              "        @@ @@           *@%.@&                                                     @@ &@            @@ @@                                                 \n"
              "       ,@/ ,@#         @@  @@       @@@&@@@/@@     @@     .@.,@@@&@@&              @@  @@         @@  #@*      /@@@&@@@@     /@ *@@@&@@(      @@       %@.\n"
              "       @@   @@       @@.   @&     @@       /@(     @@     @@@      @@             %@.  %@*      .@@   @@     @@*      /@(    @@@      @@     (@,       @@ \n"
              "      /@/   .@@     @@    @@     @@        @@     &@     *@@       @@             @@    @@     @@    /@*    @@(((#&@@@@     (@%       @@     @@       %@  \n"
              "      @@     @@   @@     .@%    #@*       #@#     @@     @@       /@             &@     *@#  (@/     @@     @@              @@       %@     /@.       @@  \n"
              "     *@/      @@/@#      @@     %@,      @@@     &@     .@*       @@             @@      @@ @@      (@,     @@             /@.       @@     @@      @@@   \n"
              "     @@       @@@        @@      @@@&@@@/ @/     @@     @@       #@,            @@.      ,@@        @@       @@@@&@@@@     @@       @@      .@@@&@@@ @@   \n\n\n";
        SetConColor(White,Black);
        cout<< "Choose a task\n0. Exit\n1. ";
        SetConColor(Red,Black);
        cout<< "Work #1:";
        SetConColor(White,Black);
        cout<< "Type of Data\n2. ";
        SetConColor(Red,Black);
        cout<< "Work #2:";
        SetConColor(White,Black);
        cout<< "One-dimensional static array\n3. ";
        SetConColor(Red,Black);
        cout<< "Work #3:";
        SetConColor(White,Black);
        cout<< "Two-dimensional static array\n4. ";
        SetConColor(Red,Black);
        cout<< "Work #4:";
        SetConColor(White,Black);
        cout<< "Text strings as character arrays\n";
        cin >> task;
        switch (task) {
            case 1: {
                clear();
                system("title Type of Data");
                main1();
                clear();
                break;
            }
            case 2: {
                clear();
                system("title One-dimensional static array");
                main2();
                clear();
                break;
            }
            case 3: {
                clear();
                system("title Two-dimensional static array");
                main3();
                clear();
                break;
            }
            case 4: {
                clear();
                system("title Text strings as character arrays");
                main4();
                clear();
                break;
            }
            case 0: {
                system("pause");
                break;
            }

        }
    }
}
