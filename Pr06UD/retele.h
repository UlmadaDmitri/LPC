#ifndef RETELE_H_INCLUDED
#define RETELE_H_INCLUDED
struct data
{
    int zi;
    int luna;
    int an;
};
struct retelesociale
{
    int id;
    char nume[20];
    data datanasterii;
    char retea[20];
    int prieteni;
    char nick[20];
};


#endif // RETELE_H_INCLUDED
