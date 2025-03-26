//
// Created by lucas on 26/03/2025.
//

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
