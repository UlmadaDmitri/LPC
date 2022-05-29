#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <conio.h>
#define NMAX 200
using namespace std;
int Citire(int n, int a[]);
void Afisare(int n, int a[], char s[]);
void Afisare(int n, int a[], char b[10][20]);
int Minimum(int n , int a[]);
int Maximum(int n , int a[]);
float Media(int n, int a[]);
int Sortare(int n, int a[]);
int Rotire(int n, int a[]);
int Adougare(int &n, int a[], int val);
int Adaugare(int &n, int a[], int val, char);
int Adaugare(int &n, int a[], int val, int p);
int Adaugare(int &n, int a[], int val, int p, char);
int Cautare(int n, int a[], int val);
int Stergere(int &n, int a[], int val);
int Clasificare(int n, int a[], int m, int b[]);
int Generare(int n, int a[]);
bool Palindrome(int n);
int main()
{
    int key;
    int n = 10, poz = 5, m = 5;
    int ncaut;
    int val;
    int prieteni[NMAX] = { 51, 53, 57, 59, 61, 64, 66, 67, 68, 69 };
    char nume [][20] = { " inchis",  " prietenos" ," sociabil" , " popular", " celebru"};
    int categorii[] = {0,0,0,0,0,0};
    int gener[NMAX];
    cout <<"Introduceti cati abonati sunt: " ;
    cin >> n ;
    Citire(n, prieteni);
    cout << "Tabloul de prieteni ocupa: " << sizeof(prieteni) << " Bt" << endl;
    do
    {
        system("cls");
        cout << "Proiect nr.3 elaborat de Ulmada Dmitri" << endl;
        cout << "Tema: Nr. de prieteni ale abonatilor unei retele sociale" << endl;
        cout << "\n1. De determinat intr-un tabel numar de prieteni";
        cout << "\n2. De determinat intr-un tabel numar media de prieteni";
        cout << "\n3. De aranjat un tabel cu numar de prieteni in ordine crescatoare sau descrescatoare";
        cout << "\n4. De efectuat rotirea la stanga a elementelor tabelului de 10 ori";
        cout << "\n5. De adaugat date in tabelul de numerele";
        cout << "\n6. De sters date din tabelul de numerele";
        cout << "\n7. Clasificare(nr. de abonati cu nr. de prieteni in limitele indicate)";
        cout << "\n8. Generare";
        cout << "\n0. Stop";
        cout << "\n\n\t Alegeti de la 0 la 8 -> ";
        cin >> key;
        switch(key)
        {
            case 1:
                Afisare(n, prieteni, " inital");
                cout <<"\nCel mai mic numar de prieteni este: " << Minimum(n, prieteni);
                cout <<"\nCel mai mare numar de prieteni este: " << Maximum(n, prieteni);
                break;
            case 2:
                Afisare (n,prieteni, " inital");
                cout << "\nNumar de prieteni media este: " << Media(n, prieteni);
                break;
            case 3:
                Afisare (n, prieteni, " inital");
                Sortare (n, prieteni);
                Afisare (n, prieteni, " aranjat");
                break;
            case 4:
                Afisare(n, prieteni, " inital");
                Rotire(n, prieteni);
                Afisare(n, prieteni, " rotit");
                break;
            case 5:
                Afisare(n, prieteni, " inital");
                Adaugare(n, prieteni, 69 ,'A');
                Afisare(n, prieteni, " Adaugat");
                break;
            case 6:
                cout << "\n Introduceti ce valoare trebuie de sters: ";
                cin >> ncaut;
                if ((val = Cautare(n, prieteni, ncaut)) != -1)
                Stergere(n, prieteni, /*val*/Cautare(n, prieteni, ncaut));
                Afisare(n, prieteni, " sters");
                break;
            case 7:
                Afisare(n, prieteni , " initial");
                Clasificare(n, prieteni, m, categorii);
                Afisare(m, categorii, nume);
                break;
            case 8:
                Generare(n, gener);
                Afisare(n, gener, "generat");
                break;
        }
        getch();
    } while(key);

    return 0;
}
int Citire(int n, int a[])
{
    int key;
    int i;
        cout << "\n 1. De la tastatura";
        cout << "\n 2. De generat aleator";
        cout << "\n 3. De generat intr-un mod special";
        cout << "\n 4. Din fisier";
        cout << "\n 5. Implicit";
        cout << "\n\n\t Alege -> ";
        cin >> key;
        switch(key) {
             case 1:
                 for (i = 0; i < n; i++) {
                 cout << "Abonat cu nr. " << i + 1 << ": ";
                 cin >> a[i];
        }
                 break;
             case 2:
                for (i = 0; i < n; i++)
                a[i] = rand() % 201 + 50;
                break;
             case 3:
                for (i = 0; i < n; i++)
                a[i] = i % 50 + 150;
                break;
    }
    return 1;
}
void Afisare(int n, int a[] ,char s[])
{
    cout << "\nTabloul de prieteni " << s <<"\n";
    for (int i = 0 ; i < n; i++)
        cout << setw(8) << a[i];
        cout << endl;
}
void Afisare(int n, int a[], char s[], char gen)
{
    cout << "\nTabloul de valori " << s << "\n";
    for (int i = 0; i < n; i++)
        cout << setw(8) << a[i];
        cout << endl;
}
void Afisare(int n, int a[] ,char b[10][20])
{
    int i;
    cout << "\nTabloul de categorii\n";
    for (int i = 0 ; i < n; i++)
        cout << "Sunt "<< a[i]<< " abonati in categoria" << b[i] << endl;
}
int Minimum(int n , int a[])
{
    int aux = a[0];
    if (n <= 0) return 0;
    for(int i = 1; i < n; i++)
        if (a[i] < aux) aux = a[i];
    return aux;
}
int Maximum(int n , int a[])
{
    int aux = a[0];
    if (n <= 0) return 0;
    for(int i = 1; i < n; i++)
        if (a[i] > aux) aux = a[i];
    return aux;
}
float Media(int n, int a[])
{
    int aux = a[0];
    if (n <= 0) return 0;
    for(int i = 1; i < n; i++)
        aux += a[i];
    aux /= n;
    return aux;
}
int Sortare(int n, int a[])
{
    int k = 0, aux;
    bool change;
    do
    {
       change = false; k++;
        for(int i = 0; i < n-k; i++)
            if (a[i] > a[i+1])
       {
          aux = a[i];
          a[i] = a[i+1];
          a[i+1] = aux;
          change = true;
       }
    } while (change);
    return 1;
}
int Rotire(int n, int a[])
{
     for (int j = 0; j < 10; j++)
    {
        int aux = a[n-1];
        for (int i = n-1; i > 0; i--)
        {
            a[i] = a[i-1];
        }
        a[0] = aux;
    }
    return 1;
}
int Adaugare(int &n, int a[], int val)
{
    for (int i = n; i > 0 ; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = val;
        n++;
}
int Adaugare(int &n, int a[], int val, char)
{
        a[n++] = val;
}
int Adaugare(int &n, int a[], int val, int p)
{
        for (int i = n; i > 0 ; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = val;
        n++;
}
int Adaugare(int &n, int a[], int val, int p, char)
{
        for (int i = n; i > 0 ; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = val;
        n++;
}
int Cautare(int n, int a[], int val)
{
     for ( int i = 0; i <= n; i++)
    {
        if (a[i] == val )
            return i;
    }
    return -1 ;
}
int Stergere(int &n, int a[], int val)
{
    if (val != -1)
    {
        for (int i = val; i <= n; i++)
        {
            a[i] = a[i+1];
        }
    }

    return 1;
}
int Clasificare(int n, int a[], int m, int b[])
{
    int i,j;
    int limite[] = {10, 40, 60, 80, 100};
    for ( i = 0; i < m; i++)
        b[m]=0;
    for ( i = 0; i < n; i++)
         for ( j = 0; j < m; j++)
    if (a[i] <= limite[j]) {b[j]++ ; break;}


    return 1;
}
int Generare(int n, int a[])
{
    for(int num = 1, contor = 0; contor < n; num++)
        if(Palindrome(num))
        {
            a[contor] = num;
            contor++;
        }
    return 1;
}
bool Palindrome(int n)
{
    int copia = n, invers = 0;
    while(copia != 0)
    {
        invers = invers*10 + copia%10;
        copia = copia/10;
    }
    return (invers == n);
}

