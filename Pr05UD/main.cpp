#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
//#include <conio.h>
#define LMAX 120


using namespace std;
//interfata
int Citire(char fraza[]);
int NrCuvinte(char sir[]);
int NrCuvinteLungMare6(char sir[]);
int NrCuvinteLungMic5(char sir[]);
int Cuvinte();
int CuvinteLungMare6();
int CuvinteLungMic5();
int TransferCuvinteLungMic5(/*char sir[]*/);
int EliminaCuvinteLungMic5(char sir[]);
int ViewFile(char nume[]);
int CopiaRezerva(char nume[]);


int main()
{
    int opt;
    char fraza[81] = "Ana Virlan prieteneste cu Ana Cabac, iar Daniil Novicov - nu.";
    cout << "Proiect nr.5 elaborat de Novicov Daniil" << endl;
    cout << "Tema: Siruri de caractere. Fisiere text" << endl;
    do {
        //system("cls");
        cout << "\n 1. Numarul de cuvinte dintr-o fraza";
        cout << "\n 2. Cuvintele lungimea carora e mai mare ca 6 dintr- o fraza";
        cout << "\n 3. Cuvinte lungimea carora e mai mica decat 5";
        cout << "\n 4. Numarul de cuvinte dintr-un fisier";
        cout << "\n 5. Cuvintele lungimea carora e mai mare ca 6 dintr-un fisier";
        cout << "\n 6. Cuvinte lungimea carora e mai mica decat 5 dintr-un fisier";
        cout << "\n 7. De inscris in alt fisier text cuvintele, care e mai mica decat 5";
        cout << "\n 8. De sters cuvintele de lungime mai mica decat 5";
        cout << "\n 9. Copia de Rezerva a fisierului";
        cout << "\n 0. Stop";
        cout << "\n\n\t Alege de la 0 la 8 -> ";
        cin >> opt;
        switch(opt)
        {
            case 1:
                cout << "Introduceti o fraza:\n";
                fflush(stdin); gets(fraza);
                cout << "Fraza initiala \n";
                puts(fraza);
                if (int n = NrCuvinte(fraza))
                cout << "\nIn total " << n << " cuvinte\n";
                else  cout <<"Nu-s cuvinte\n";
                break;
            case 2:
                cout << "Fraza initiala \n";
                puts(fraza);
                if (int n = NrCuvinteLungMare6(fraza))
                cout << "\nIn total " << n << " cuvinte\n";
                else  cout <<"Nu-s cuvinte\n";
                break;
            case 3:
                cout << "Fraza initiala \n";
                puts(fraza);
                if (int n = NrCuvinteLungMic5(fraza))
                cout << "\nIn total " << n << " cuvinte\n";
                else  cout <<"Nu-s cuvinte\n";
                break;
            case 4:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("frazfile.in");
                if (Cuvinte() !=0)
                cout << "\nIn total " << Cuvinte() << " cuvinte\n";
                else  cout <<"Nu-s cuvinte\n";
                break;
            case 5:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("frazfile.in");
                if (int n = CuvinteLungMare6())
                cout << "\nIn total " << n << " cuvinte\n";
                else  cout <<"Nu-s cuvinte\n";
                break;
            case 6:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("frazfile.in");
                if (int n = CuvinteLungMic5())
                cout << "\nIn total " << n << " cuvinte\n";
                else  cout <<"Nu-s cuvinte\n";
                break;
            case 7:
                cout << "Cuvinte lumgimea carora e mai mica decat 5 au fost scrise in fisier \n";
                //ViewFile("frazfile.in");
                TransferCuvinteLungMic5();
                break;
            case 8:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("frazfile.in");
                EliminaCuvinteLungMic5("frazfile.in");
                break;
            case 9:
                CopiaRezerva("frazfile.in");
                cout << "Copia a fost facuta";
                break;
        }
        fflush(stdin); //o4istka bufera
        /*cout << "Apasa un buton";
    getchar();*/

    } while(opt);
    return 0;
}

int Citire(char fraza[])
{
    return 1;
}

int NrCuvinte(char sir[])
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    n = 1;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
        n++;

    return n;
}
int NrCuvinteLungMare6(char sir[])
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    n = 0;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
        if (strlen(cuvint) > 6) {
        n++;
        cout << " " << cuvint;
}
    return n;
}
int NrCuvinteLungMic5(char sir[])
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    n = 1;
    cout << cuvint;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
        if (strlen(cuvint) < 5) {
        n++;
        cout << " " << cuvint;
}
    return n;
}
int Cuvinte()
{
    FILE *f;
    char sir[LMAX];
    int n = 0;
    f = fopen("frazfile.in", "r");
    while(fgets(sir, LMAX-1, f) != NULL)
        n+= NrCuvinte(sir);
    fclose(f);
    return n;
}
int CuvinteLungMare6()
{
    FILE *f;
    char sir[LMAX];
    int n = 0;
    f = fopen("frazfile.in", "r");
    while(fgets(sir, LMAX-1, f) != NULL)
        n+= NrCuvinteLungMare6(sir);
    fclose(f);
    return n;
}
int CuvinteLungMic5()
{
    FILE *f;
    char sir[LMAX];
    int n = 0;
    f = fopen("frazfile.in", "r");
    while(fgets(sir, LMAX-1, f) != NULL)
        n+= NrCuvinteLungMic5(sir);
    fclose(f);
    return n;
}
int TransferCuvinteLungMic5(/*char sir[]*/)
{
    FILE *f;
    FILE *t;
    char fraza[LMAX], copia[LMAX], *cuvint;
    f = fopen("frazfile.in", "r");
    t = fopen("frazfile1.in", "w");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (strlen(cuvint) < 5) fputs(cuvint, t);
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL) {
            fputs(" ", t);
        if (strlen(cuvint) < 5) fputs(cuvint, t);
    }
    }
    fclose(f);
    fclose(t);
    return 0;
}
int EliminaCuvinteLungMic5(char sir[])
{
    return 1;
}
int ViewFile(char nume[])
{
    FILE *f;
    char sir [LMAX];
    f = fopen(nume, "r");
    while (fgets(sir, LMAX-1, f) != NULL)
        cout << sir;
    fclose(f);
}
int CopiaRezerva(char nume[])
{
    FILE *f;
    FILE *rez;
    char sir[LMAX];
    f = fopen(nume, "r");
    rez = fopen("rezerv.in", "w");
    while(fgets(sir, LMAX - 1, f) != NULL)
    {
        fputs(sir, rez);
    }
    fclose(f);
    fclose(rez);
    return 1;
}
