#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "retele.h"

using namespace std;

void Inscriere()
{
    FILE *ft, *f;
    retelesociale retelele;
    char prenume[20];
    ft = fopen("file10.txt", "r");
    f = fopen("retelelePo.in", "wb");
    while(fscanf(ft, "%d %s %s %d %d %d %s %d %s",
            &retelele.id, retelele.nume, prenume, &retelele.datanasterii.zi, &retelele.datanasterii.luna, &retelele.datanasterii.an, &retelele.retea, &retelele.prieteni, &retelele.nick) !=EOF)
          {
          strcat(retelele.nume, " ");
        strcat(retelele.nume,prenume);
          fwrite(&retelele, sizeof(retelele), 1 ,f);
          }
 printf("\nOK");
 fclose(ft);
 fclose(f);

}
void Linia(int st, int lin, int mij, int dr)
{
    int i;
    printf("\n%c", st);
    for (i=1; i<=3; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=5; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=20; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=15; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=9; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=9; i++) printf("%c", lin); printf("%c", mij);
    for (i=1; i<=17; i++) printf("%c", lin); printf("%c", mij);
}
void Afisare()
{
     retelesociale retelele;
     FILE *f;
     int n = 0;
     f = fopen("retelelePo.in", "rb");
     printf("\nLista initiala a retelele de Auto");
     Linia(201, 205, 209, 187);
      printf("\n%cNr %c ID%3c        Nume       %2c Data nasterii%2cDen. ret.%cNr. priet%c    Nickname     %c",
            186, 179, 179, 179, 179, 179, 179, 179, 186);
     Linia(199, 196, 197, 182);
     while(fread(&retelele, sizeof(retelele),1, f)>0)
     {
         n++;
         printf("\n%c%3d%c %3d %c%-20.20s%c  %02d.%02d.%4d   %c    %s   %c    %2d   %c%-17.17s%c ",
            186, n, 179, retelele.id, 179, retelele.nume, 179, retelele.datanasterii.zi, retelele.datanasterii.luna, retelele.datanasterii.an, 179,retelele.retea , 179, retelele.prieteni, 179, retelele.nick , 186);
     }
     Linia(200, 205, 207, 188);
     fclose(f);
}
void Adaugare()
{
    FILE *ft, *f;
    retelesociale retelele;
    char prenume[20];
    ft = fopen("file20.txt", "r");
    f = fopen("retelelePo.in", "ab");
    while(fscanf(ft, "%d %s %s %d %d %d %s %d %s",
            &retelele.id, retelele.nume, prenume, &retelele.datanasterii.zi, &retelele.datanasterii.luna, &retelele.datanasterii.an, &retelele.retea, &retelele.prieteni, &retelele.nick) !=EOF)
          {
          strcat(retelele.nume, " ");
        strcat(retelele.nume,prenume);
          fwrite(&retelele, sizeof(retelele), 1 ,f);
          }
 printf("\nOK");
 fclose(ft);
 fclose(f);

}
