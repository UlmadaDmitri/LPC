#include <iostream>
#include <iomanip>
#define SMAX 200

using namespace std;
int main()
{
    int n = 10;
    int abon;
    int minim, maxim ;
    int decalaj;
    int valoare, maimic = 0, egal = 0, maimare = 0;
    int jos, sus;
    int contor = 0;
    int celebru = 0, popular = 0, prietenos = 0, sociabil = 0, inchis = 0;
    float media;
    cout << "Pr. Nr 1 elaborat de Ulmada Dmitri" << endl;
    cout << "Tema: Nr.de prieteni ale abonatilor unei retele sociale" << endl;
    cout << "Cati abonati? " ;
    cin >> n;
    cout << "Introduceti numarul mediu de prieteni : ";
    cin >> valoare;
    cout << "Introduceti limitele de prietenii ale abonatilor : ";
    cin >> jos >> sus;
    cout << "Indica numarul de prieteni :" ;
    media = 0;
    maxim = -SMAX;
    minim = +SMAX;
    int i = 1;
    while ( i <= n )
    {
        cin >> abon;
        if (abon > maxim)
            maxim = abon;
        media += abon;
        if (abon < minim)
            minim = abon;
        if (abon < valoare) maimic++;
        else if (abon > valoare) maimare++;
        else  egal++;
        if (abon <= sus & abon >= jos) contor+=1;

        if (abon >= 80 ) celebru++;
        else if (abon >= 60) popular++;
        else if (abon >= 40) prietenos++;
        else if (abon >= 10) sociabil++;
        else inchis++;
        i++;
    }
    decalaj = maxim - minim;
    media /= n;
    cout << "1.\t numarul minim de prieteni: " << minim << endl;
    cout << "\t numarul maxim de prieteni: " << maxim << endl;
    cout << "2.\t Decalajul: " << decalaj << endl;
    cout << "3.\t Media: " << setprecision(5) << media;
    if (media - (int)media > 0) cout << "0";
    cout << endl;
    cout << "4.\t Numarul de abonati cu o multime de prieteni: " << maimare << "; Numarul de abonati cu putini prieteni: " << maimic << "; Egal: " << egal << endl;
    cout << "5.\t Numerele de abonati cu numar de prieteni " << jos << " la " << sus << endl;
    cout <<"\t In total: " << contor << " abonati" << endl;
    cout <<"Abonati inchis: " << inchis << endl;
    cout <<"Abonati sociabili: " << sociabil << endl;
    cout <<"Abonati prietenos: " << prietenos << endl;
    cout <<"Abonati popular: " << popular << endl;
    cout <<"Abonati celebru: " << celebru << endl;

    return 0;
}
