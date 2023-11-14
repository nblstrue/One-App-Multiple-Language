#include "assert.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "variables.h"

FILE *stock;

void stock_open(FILE *a)
{
    a = fopen(fichier, "a+");
    if(a == NULL)
    {
        printf("\n\nFATAL ERROR: cannot open or create 'stock'");
        exit(-1);
    }
}

int stock_close(FILE *a)
{
    int close = fclose(a);
    if(close == EOF)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void send(client *p1, FILE *a)
{
    fprintf(a, "%s %s ", p1->nom, p1->pnom);
    if(p1->place == 1)
    {
        fprintf(a, "Client gare\n");
    }
    else
    {
        fprintf(a, "Client pas gare\n");
    }
}

void recup(client *p1, FILE *a)
{
    strcpy(p_CL->nom, "Lathro-Seri");
    strcpy(p_CL->pnom, "Nathan");
    p_CL->place = 1;
    
    CH50 place;
    char vrai[] = "Client gare";

    fscanf(stock, "%s %s %s\n", p1->nom, p1->pnom, place);
    
    int z = strlen(place);
    strcpy(place[z - 1], '\0');

    int b = strcmp(place, vrai);
    if(b == 0)
    {
        p1->place = 1;
    }
    else
    {
        p1->place = 0;
    }
}

void stage2(client *p)
{
    client test;
    client *p_test = &test;

    printf("\nPassed\n");

    stock_open(stock);
    send(p, stock);
    stock_close(stock);
    stock_open(stock);
    recup(p_test, stock);
    stock_close(stock);

    printf("\n\nNom = %s\nPrenom = %s\nPlace = %d", p_test->nom, p_test->pnom, p_test->place);
}
