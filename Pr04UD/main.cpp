#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#define PMAX 200

using namespace std;

int Citire(int &linia, int &coloana, int a[PMAX][PMAX]);
void Afisare(int linia, int coloana, int a[PMAX][PMAX], char s[]);
int Maxim(int linia, int coloana, int a[PMAX][PMAX]);
int Minim(int linia, int coloana, int a[PMAX][PMAX]);
int Interschimbarea(int linia, int coloana, int a[PMAX][PMAX]);
int Caracteristica(int &linia, int &coloana, int a[PMAX][PMAX]);
int Aranjarea(int linia, int coloana, int a[PMAX][PMAX]);
int Generare(int b[PMAX][PMAX]);



int main()
{
    int prieteni[PMAX][PMAX] = {{15, 2, 130, 4, 11}, {4, 13, 91, 23, 4}, {12, 38, 94, 75, 21}, {16, 56, 19, 88, 94}, {11, 56, 23, 44, 53}};
    int b[PMAX][PMAX];
    int linia = 5, coloana = 5 ;
    int key;
    Citire(linia, coloana, prieteni);
    do
    {
        system("cls");
        cout << "Proiect nr.4 elaborat de Ulmada Dmitri" << endl;
        cout << "Tema: Nr. de prieteni ale n abonati in m retele sociale" << endl;
        cout << "\n1. De determinat intr-o matrice de prieteni,nr. de prieteni maxim";
        cout << "\n2. De determinat intr-o matrice de prieteni,nr. de prieteni minim";
        cout << "\n3. De interschimbat doua coloane";
        cout << "\n4. De adaugat o linie, de completat cu caracteristica";
        cout << "\n5. De aranjat o matrice de prieteni dupa linia adaugata.";
        cout << "\n6. Generare";
        cout << "\n0. Stop";
        cout << "\n\n\t Alegeti de la 0 la 6 -> ";
        cin >> key;
        switch (key)
        {
        case 1:
            Afisare (linia, coloana, prieteni, "initiala");
            Maxim(linia, coloana, prieteni);
            break;
        case 2:
            Afisare (linia, coloana, prieteni, "initiala");
            Minim(linia, coloana, prieteni);
            break;
        case 3:
            Afisare (linia, coloana, prieteni, "initiala");
            Interschimbarea(linia, coloana, prieteni);
            Afisare (linia, coloana, prieteni, "interschimbata");
            break;
        case 4:
            Afisare (linia, coloana, prieteni, "initiala");
            Caracteristica(linia, coloana, prieteni);
            Afisare (linia, coloana, prieteni, "cu caracteristica");
            break;
        case 5:
            Afisare (linia, coloana, prieteni, "initiala");
            Aranjarea(linia, coloana, prieteni);
            Afisare (linia, coloana, prieteni, "aranjat");
            break;
        case 6:
            Afisare (linia, coloana, prieteni, "initiala");
            Generare(b);
            Afisare (3, 3, b, "generata");
            break;
        }
        getch();
    }
    while (key);
    return 0;
}
Citire(int &linia, int &coloana, int a[PMAX][PMAX]) // posle main()

{
    int key;
    int i, j;
    do
    {
        cout << "De unde citim: ";
        cout << "\n1. De la tastatura";
        cout << "\n2. De generat aleator";
        cout << "\n3. Implicit";
        cout << "\n\n\t Alegeti de la 1 pana la 3 -> ";
        cin >> key;
    }
    while(key < 1 || key > 3);
    switch(key)
    {
    case 1:
        do
        {
            cout << "Cate linii vor fi in matricea: ";
            cin >> linia;
            cout << "Cate coloane vor fi in matricea: ";
            cin >> coloana;
        }
        while(linia >= PMAX || coloana >= PMAX );
        for(i = 0; i < linia; i++)
        {
            for (j = 0; j < coloana; j++)
            {
                cout << "Nr. de prieteni ale abonatului" << i+1 << " retea cu nr." << j+1 << ": ";
                cin >> a[i][j];
            }
        }
        break;
    case 2:
        do
        {
            cout << "Cate linii vor fi in matricea: ";
            cin >> linia;
            cout << "Cate coloane vor fi in matricea: ";
            cin >> coloana;
        }
        while(linia >= PMAX || coloana >= PMAX );
        for(i = 0; i < linia; i++)
        {
            for (j = 0; j < coloana; j++)
            {
                a[i][j] = rand() % 150 + 1;
            }
        }
    case 3:
        cout << "Matricea implicita";
        break;
    }

    return 1;
}
void Afisare(int linia, int coloana, int a[PMAX][PMAX], char s[])
{
    cout << "\nMatricea de prieteni " << s << " \n";
    for (int i = 0; i < linia; i++)
    {
        for (int j = 0; j < coloana; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << endl;
    }
}
int Maxim(int linia, int coloana, int a[PMAX][PMAX])
{
    int aux;
    for (int i = 0; i < linia; i++)
    {
        aux = a[i][0];
        for (int j = 0; j < coloana; j++)
        {
            if(aux < a[i][j])
            {
                aux = a[i][j];
            }

        }
        cout << "\n Nr. de prieteni maxim abonatului cu nr." << i+1 << " este: " << aux;
    }

    return 1;
}
int Minim(int linia, int coloana, int a[PMAX][PMAX])
{
    int aux;
    for (int i = 0; i < linia; i++)
    {
        aux = a[i][0];
        for (int j = 0; j < coloana; j++)
        {
            if(aux > a[i][j])
            {
                aux = a[i][j];
            }

        }
        cout << "\n Nr. de prieteni minim abonatului cu nr." << i+1 << " este: " << aux;
    }

    return 1;
}
int Interschimbarea(int linia, int coloana, int a[PMAX][PMAX])
{
    int coloana1, coloana2;
    int aux;
    cout << "Care coloana va fi interschimbata: ";
    cin >> coloana1;
    cout << "Cu care coloana va fi interschimbata prima linia: ";
    cin >> coloana2;
    for (int i = 0; i < linia; i++)
    {
        aux = a[i][coloana1-1];
        a[i][coloana1-1] = a[i][coloana2-1];
        a[i][coloana2-1] = aux;
    }
    return 1;
}
int Caracteristica(int &linia, int &coloana, int a[PMAX][PMAX])
{
    int CaracteristicaColoana;
    for (int j = 0; j < coloana; j++)
    {
        CaracteristicaColoana = 0;
        for (int i = 0; i < linia; i++)
        {
            if (a[i][j] > 100) CaracteristicaColoana++;
        }
        a[linia][j] = CaracteristicaColoana;
    }
    linia++;
    return 1;
}
int Aranjarea(int linia, int coloana, int a[PMAX][PMAX])
{
    int aux;
    for (int h = 0; h < coloana-1; h++)
    {
        for (int j = 0; j < coloana-1; j++)
        {
            if (a[linia-1][j] < a[linia-1][j+1])
            {
                for (int i = 0; i < linia; i++)
                {
                    aux = a[i][j];
                    a[i][j] = a[i][j+1];
                    a[i][j+1] = aux;
                }
            }
        }
    }

    return 1;
}
int Generare(int b[PMAX][PMAX])
{

    for (int i = 0; i < 3; i++)
    {
        b[i][0] = i+1;
        for (int j = 1; j < 3; j++)
        {
            b[i][j] = i+2;
        }
    }

    return 1;
}
