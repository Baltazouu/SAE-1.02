

#define SIZE_TIUT 20
/**
typedef struct list
{
    char departement[30];
    int nbP;
    char resp[30];
    struct list * suivant;

}MaillonDept, *ListDept;

typedef struct
{
    char VilleDep[31];
    ListDept ldept;
    int nbDept;
    
}VilleIUT;
*/



typedef struct list
{       
    int nb;
    char departement[20];
    liste *suivant;
}MaillonDept,*liste;


typedef struct 
{
    char NomVille[20];
    liste *list;
}Ville;


