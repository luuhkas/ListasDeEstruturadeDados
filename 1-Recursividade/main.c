#include <stdio.h>
#include "headers.h"
int inverter_numero(int numero)
{
    if (numero == 0)
    {
        return 1;
    }

    printf("%d", numero % 10);
    inverter_numero (numero / 10);
}

int main(void)
{
    int numero;

    printf("Digie um numero para ver o inverso: ");
    scanf("%d", &numero);

    inverter_numero (numero);

    return 0;
}