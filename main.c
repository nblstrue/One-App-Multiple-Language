#include "stage1.h"
#include "stage2.h"

int main(void)
{
    strcpy(p_CL->nom, "Lathro-Seri");
    strcpy(p_CL->pnom, "Nathan");
    p_CL->place = 1;
    
    stage2(p_CL);
    return 0;
}