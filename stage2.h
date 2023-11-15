#include "assert.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "variables.h"

void send(FILE* file, client *p)
{
    fprintf(file, "%s %s %d\n", p->nom, p->pnom, p->place);
}

void recup(FILE *file, client *p)
{
    fscanf(file, "%s %s %d\n", p->nom, p->pnom, &p->place);
}

void open(FILE *file, char *name)
{
    file = fopen(name, "a+");
}

void w_r(FILE *file, char *name)
{
    file = fopen(name, "r+");
}

void close(FILE *file)
{
    fclose(file);
}

void show(client *p)
{
    printf("\n\n%s | %s | %d\n\n", p->nom, p->pnom, p->place);
}

void stage2(client *p_s, client *p_r)
{
    int choice;

    info = fopen(fichier, "a+");
    if(info != NULL)
    {
        w_r(info, fichier);
        printf("\n\nVoulez vous envoyer des informations ou récupérer les anciennes (oui = 1 et non = 0)\n=>");
        fflush(stdin);
        scanf("%d", &choice);

        while(choice > 1 && choice < 0)
        {
            printf("\n\nFATAL ERROR: incorrect value send (choice = %d)", &choice);
            printf("\n\nVoulez vous envoyer des informations ou recuperer les anciennes (envoyer = 1 et recuperer = 0)\n=>");
            fflush(stdin);
            scanf("%d", &choice);
        }
        
        if(choice == 1)
        {
            send(info, p_s);
            close(info);
        }
        else
        {
            recup(info, p_r);
            close(info);
        }
    }
    else
    {
        printf("\n\nFATAL ERROR: cannot create or open the stocking document");
        exit(-1);
    }

}
