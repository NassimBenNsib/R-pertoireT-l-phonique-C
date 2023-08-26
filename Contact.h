#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

typedef struct
{
    char Rue[20] ;
    char Ville[20] ;
    char Code_postal[5] ;
}Adresse ;
typedef struct
{
    char Num_Tel[9] ;
    char Nom[20] ;
    char Prenom[20] ;
    char DN[11] ;
    Adresse AD ;
    char E_Mail[30] ;
}Contact ;
typedef struct Cellule
{
    Contact Info ;
    struct Cellule *Suivant ;
} ;
typedef struct Cellule *Liste_Tel ;

#endif // CONTACT_H_INCLUDED
