#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Inscriere();
void Afisare();
void Adaugare();
void Modificare();

void AranjareOras();
void AranjareOra();


void Lista1();
void Lista2();
void Lista3();
void Lista4();
void Lista5();

int main()
{
    int opt;
    do
        {
        system("cls");
        cout << "Laborator Nr6 Elaborate de Ulmada Dmitri" << endl;
        cout << "1.  Inscriere" << endl;
        cout << "2.  Afisare" << endl;
        cout << "3.  Adaugare" << endl;
        cout << "4.  AranjareAlfabetica" << endl;
        cout << "5.  Nr. de prieteni mai mare decat 10" << endl;
        cout << "6.  Abonat foloseste numai VK" << endl;
        cout << "7.  Abonat a fost nascut in anul 2001" << endl;
        cout << "8.  Nickname-ul abonatului are mai mult decat 5 simboluri" << endl;
        cout << "0.  Stop";
        cout << "\n\n\t Alegeti (de la 0 la 11) -> ";
        cin >> opt;
        switch(opt)
        {
        case 1:
            Inscriere();
            break;
        case 2:
            Afisare();
            break;
        case 3:
            Adaugare();
            break;
        case 4:
            AranjareOras();
            break;
        case 5:
            Lista1();
            break;
        case 6:
            Lista2();
            break;
        case 7:
            Lista3();
            break;
        case 8:
            Lista4();
            break;
        }
 getch();
    }while(opt);
return 0;
}
