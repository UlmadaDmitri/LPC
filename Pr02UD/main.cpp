#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#define NMAX 30
using namespace std;
int lucas(int n);
int main()
{
    int numar;
    int i;
    int jos, sus;
    int contor, cit;
    cout << "Proiect Nr. 2, elaborat de Ulmada Dmitri" << endl;
    cout << "Tema: Numerele Lucas\n";
    cout << "Introduceti numarul intreg, pentru verificare: ";
    cin >> numar;
    cout << "Introduceti limitele de jos si de sus: ";
    cin >> jos >> sus;
    cout << "Cite numere lucas: ";
    cin >> cit;
    int temp = 0;
    int cont = 0;
    bool check = false;
    for(cont = 0; cont <= numar; cont++)
    {
        temp = lucas(cont);
        if(temp == numar)
        {
            cout << "\n1. " <<numar <<" este numarul Lucas";
            check = true;
            break;
        }
        else
            cont++;
    }
    if (!check)
        cout << "\n1. " << numar <<"\ nu este lucas";

    cout << "\n2. Numerele lucas de la " << jos << " la " << sus << endl;
    i=1;
    while (lucas (i) >jos && lucas (i) <sus)
    {
        cout << setw(8) << lucas (i);
        i++;
    }

    cout << "\n3. Primele "<< cit << " numere lucas " << endl;
    for( contor = 0; contor < cit; contor++)
        cout << setw(8) << lucas(contor) ;
    if(contor)
        cout << "\nIn total: " << contor << " numere\n";
    else
        cout << "Nu sunt numere lucas pe interval";
    cout << "\n4. Numere lucas sunt:\n";
    jos = 1;
    sus = 10;
    for (numar = jos; numar <= sus; numar++)
    {

        cout << setw(8) << lucas(numar);

    }
    cout << "\n5. Cel mai mare numar lucas este: ";
    cout << lucas(NMAX);
    return 0;
}
int lucas(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 3;
    return lucas(n - 1) +
           lucas(n - 2);
}


