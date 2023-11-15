#include "stage1.h"
#include "stage2.h"

int main(void)
{
    strcpy(p_CL->nom, "Lathro-Seri");
    strcpy(p_CL->pnom, "Nathan");
    p_CL->place = 1;

    stage1();
    //stage2(p_CL, (p_CL+indice));

    printf("Client 1 = %s %s\nEtat de la place = %d\n\nClient 2 = %s %s\nEtat de la place = %d", p_CL->nom, p_CL->pnom, p_CL->place, (p_CL+1)->nom, (p_CL+1)->pnom, (p_CL+1)->place);
    return 0;
}