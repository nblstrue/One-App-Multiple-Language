#include "assert.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "variables.h"

void create(void)//Crée un client dans le tableau de structures
{
    printf("\nA quelle place, entre 0 et 4 compris, voulez vous stocker vos informations ?\n=>");
    fflush(stdin);
    scanf("%d", &indice);

    while(indice >= lengh || indice < 0)
    {
        printf("\n\nFATAL ERROR: beyond array scope (indice = %d)", indice);
        printf("\nEntre 0 et 4, en dehors de | %d |, dans quelle indice voulez vous rentrer vos informations?\n=>", indice);
        fflush(stdin);
        scanf("%d", &indice);
    }

    int a = strcmp((p_CL+indice)->nom, "\0");

    while(a != 0)
    {
        printf("\n\nERROR: struct already filled (indice.nom = %s)", (p_CL+indice)->nom);
        printf("Entre 0 et 4, en dehors de | %d |, dans quelle indice voulez vous rentrer vos informations?\n=>", indice);
        scanf("%d", &indice);
    }

    printf("\n\nVotre nom\n=>");
    fflush(stdin);
    fgets((p_CL+indice)->nom, sizeof(CH50), stdin);
    int A = strlen((p_CL+indice)->nom);
    (p_CL+indice)->nom[A-1] = '\0';

    printf("\nVotre prenom\n=>");
    fflush(stdin);
    fgets((p_CL+indice)->pnom, sizeof(CH30), stdin);
    int B = strlen((p_CL+indice)->pnom);
    (p_CL+indice)->nom[B-1] = '\0';

    printf("\nEst ce que vous etes garez ? (oui = 1 et non = 0)\n=>");
    fflush(stdin);
    scanf("%d", &(p_CL+indice)->place);

    while((p_CL+indice)->place > 1 || (p_CL+indice)->place < 0)
    {
        printf("\n\nERROR: wrong value (place = %d)", (p_CL+indice)->place);
        printf("\nEst ce que vous etes garez ? (oui = 1 et non = 0)\n=>");
        fflush(stdin);
        scanf("%d", &(p_CL+indice)->place);
    }

    printf("\n\n[-]Client numero %d\nNom = %s\nPrenom = %s\n", indice+1, (p_CL+indice)->nom, (p_CL+indice)->pnom);
    if((p_CL+indice)->place == 1)
    {
        printf("Mme/Mr %s est gare(e) dans le parking", (p_CL+indice)->nom);
    }
    else
    {
        printf("Mme/Mr %s n'est pas gare(e) dans le parking", (p_CL+indice)->nom);
    }
}

void show(char *name)//Lit les données d'un client à partir de son nom
{
    int z = 0;

    for(int i = 0; i < lengh; i++)
    {
        int a = strcmp((p_CL+i)->nom, name);

        if(a == 0)
        {
            printf("\n\n[-]Client numero %d\nNom = %s\nPrenom = %s\n", i+1, (p_CL+i)->nom, (p_CL+i)->pnom);
            if((p_CL+i)->place == 1)
            {
                printf("Mme/Mr %s est gare(e) dans le parking", (p_CL+i)->nom);
            }
            else
            {
                printf("Mme/Mr %s n'est pas gare(e) dans le parking", (p_CL+i)->nom);
            }
        }
        else{z++;}
    }

    if(z == lengh)
    {
        printf("\n\n%s n'existe pas dans la base de donnees", name);
    }
}

void show_all(void)//Lit tout le tableau de structures
{
    for(int i = 0; i < lengh; i++)
    {
        int a = strcmp((p_CL+i)->nom, "\0");

        if(a !=0)
        {
            printf("\n\n[-]Client numero %d\nNom = %s\nPrenom = %s\n", i+1, (p_CL+i)->nom, (p_CL+i)->pnom);
            if((p_CL+i)->place == 1)
            {
                printf("Mme/Mr %s est gare(e) dans le parking", (p_CL+i)->nom);
            }
            else
            {
                printf("Mme/Mr %s n'est pas gare(e) dans le parking", (p_CL+i)->nom);
            }
        }
    }
}

void cmp(client *p1, client *p2)//Compare deux structures
{
    int a = strcmp(p1->nom, p2->nom);
    int b = strcmp(p1->pnom, p2->pnom);

    if(a == 0)
    printf("\n\nLes deux personnes ont le meme nom");
    else
    printf("\n\nLes deux personnes n'ont pas le meme nom");

    if(b == 0)
    printf("\nLes deux personnes ont le meme prenom");
    else
    printf("\nLes deux personnes n'ont pas le meme prenom");

    if(p1->place == p2->place)
    printf("\nLes deux personnes sont gares dans le parking");
    else
    {
        if(p1->place == 1)
        printf("\nSeulement Mme/Mr %s est gare(e)", p1->nom);
        else
        {
            if(p1->place == 1)
            printf("\nSeulement Mme/Mr %s est gare(e)", p2->nom);
            else
            printf("\nAucune des deux personnes n'est gare(e) dans le parking");
        }
    }
}

void verif(void)//Vérifie les duplications d'informations
{
    for(int i = 1; i < lengh; i++)
    {
        int a = strcmp((p_CL+i)->nom, (p_CL+i-1)->nom);
        int b = strcmp((p_CL+i)->nom, '\0');
        if(a == 0 && b != 0)
        {
            printf("\n\nClient numero %d et numero %d ont le meme nom\nEcrasement du client numero %d...", i, i-1, i);
            strcpy((p_CL+i)->nom, '\0');
            strcpy((p_CL+i)->pnom, '\0');
            (p_CL+i)->place = 0;
        }
    }
}

void stage1(void)
{
    create();
    show((p_CL+indice)->nom);
    show_all();
    printf("\n\n%s et %s compares", (p_CL+indice)->nom, p_CL->nom);
    cmp(p_CL, (p_CL+indice));
    printf("\n\n%s et %s compares", p_CL->nom, p_CL->nom);
    cmp(p_CL, p_CL);
    verif();
}
