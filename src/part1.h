
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
}VilleIUT;




