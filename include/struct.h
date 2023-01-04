#ifndef STRUCT_H
#define STRUCT_H



#define LONGVILLE 12


#define LONGDEP 31

#define LONGRESP 31

#define SIZE_TIUT 15

#define MAX_LONGFICH 15



typedef struct list
{
    char departement[LONGDEP];
    int nbP;
    char resp[LONGRESP];
    struct list *suivant;

}MaillonDept,*ListDep;


typedef struct 
{
    char VilleDep[LONGVILLE];
    ListDep ldept;
    int nbDept;
} VilleIUT;


#endif