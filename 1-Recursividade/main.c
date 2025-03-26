#include <stdio.h>
#include "headers.h"

int main()
{
    int numero;

    printf("Digie um numero para ver o inverso: ");
    scanf("%d", &numero);

    inverter_numero (numero);

    return 0;
}