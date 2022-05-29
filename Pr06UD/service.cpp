#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "retele.h"
void AranjareOras()
{
    FILE *f;
    retelesociale retelelea[100];
    retelesociale retelele, aux;
    char prenume[15];
    int i = 0;
    int cit = 0;
    f = fopen("retelelePo.in", "rb");
    while(fread(&retelele, sizeof(retelesociale), 1, f) > 0)
    {
        retelelea[i] = retelele;
        i++;
        cit = i;
    }
    fclose(f);
    for(i = 0; i < cit; i++)
    {
        bool flag = true;
        for(int j = 0; j < cit - (i+1); j++)
        {
            int cmp = strcmp(retelelea[j].nume, retelelea[j+1].nume);
            if (cmp > 0)
            {
                flag = false;
                aux = retelelea[j];
                retelelea[j] = retelelea[j+1];
                retelelea[j+1] = aux;
            }
        }
        if (flag) break;
    }
    f = fopen("retelelePo.in", "wb");
    for (i = 0; i < cit; i++)
    {
       fwrite(&retelelea[i], sizeof(retelesociale), 1, f);
    }
    fclose(f);
    printf("\nAranjarea a fost facuta");
}
