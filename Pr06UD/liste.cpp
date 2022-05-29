#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "retele.h"
void Linia(int,int,int,int);
void Lista1()
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
        if (retelele.prieteni>10)
        {
            n++;
            printf("\n%c%3d%c %3d %c%-20.20s%c  %02d.%02d.%4d   %c    %s   %c    %2d   %c%-17.17s%c ",
                   186, n, 179, retelele.id, 179, retelele.nume, 179, retelele.datanasterii.zi, retelele.datanasterii.luna, retelele.datanasterii.an, 179,retelele.retea, 179, retelele.prieteni, 179, retelele.nick, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fclose(f);
}
void Lista2()
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
        if (strcmp(retelele.retea , "VK") ==0)
        {
            n++;
            printf("\n%c%3d%c %3d %c%-20.20s%c  %02d.%02d.%4d   %c    %s   %c    %2d   %c%-17.17s%c ",
                   186, n, 179, retelele.id, 179, retelele.nume, 179, retelele.datanasterii.zi, retelele.datanasterii.luna, retelele.datanasterii.an, 179,retelele.retea, 179, retelele.prieteni, 179, retelele.nick, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fclose(f);
}
void Lista3()
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
        if (retelele.datanasterii.an == 2001)
        {
            n++;
            printf("\n%c%3d%c %3d %c%-20.20s%c  %02d.%02d.%4d   %c    %s   %c    %2d   %c%-17.17s%c ",
                   186, n, 179, retelele.id, 179, retelele.nume, 179, retelele.datanasterii.zi, retelele.datanasterii.luna, retelele.datanasterii.an, 179,retelele.retea, 179, retelele.prieteni, 179, retelele.nick, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fclose(f);
}
void Lista4()
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
        if (strlen(retelele.nick)>5)
        {
            n++;
            printf("\n%c%3d%c %3d %c%-20.20s%c  %02d.%02d.%4d   %c    %s   %c    %2d   %c%-17.17s%c ",
                   186, n, 179, retelele.id, 179, retelele.nume, 179, retelele.datanasterii.zi, retelele.datanasterii.luna, retelele.datanasterii.an, 179,retelele.retea, 179, retelele.prieteni, 179, retelele.nick, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fclose(f);
}
