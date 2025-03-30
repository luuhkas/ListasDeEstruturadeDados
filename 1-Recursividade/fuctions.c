//
// Created by lucas on 26/03/2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

void menu()
{
    int escolha;

    printf("Escolha o numero da questao: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        int numero;

        printf("Digite um numero para ver o inverso: ");
        scanf("%d", &numero);

        inverter_numero(numero);
        break;
    case 2:
        int* vet; // criei um ponteiro, no caso esse será um vetor.
        int tam;

        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tam); // decidi pedir o tamanho ao usuário.

        if ((vet = (int*)malloc(tam * sizeof(int))) == NULL) // verificação e alocação de memória
        {
            printf("Erro ao alocar memoria!\n");
            exit(1);
        }

        printf("Digite os elementos do vetor vet: \n"); // apenas para dar ao usuário o poder de criar o vetor.

        for (int i = 0; i < tam; i++)
        {
            printf("Elemento vet[%d]: ", i + 1);
            scanf("%d", &vet[i]);
        }

        printf("A soma dos elemtos do vetor eh: %d", soma_vetor(vet, tam));
        free(vet);
        break;
    case 3:

        int N;
        printf("Digite um numero para saber seu somatorio de 0 ate ele: \n");
        scanf("%d", &N);

        int soma = somatorioN(N);

        printf("O resultado do somatorio eh: %d", soma);

        break;

    case 4:

        int k, n;
        printf("Escolha um numero base e um expoente: \n");
        scanf("%d %d", &k, &n);

        int resultado = func_pow(k, n);

        printf("O resultado eh: %d", resultado);
        break;

    case 5:
        int vet2[100];

        for (int i = 0; i < 100; i++)
        {
            vet2[i] = i + 1;
            printf("%d ", vet2[i]);
        }

        printf("\n\n");

        invert_elementos(vet2, 0, 99);

        for (int i = 0; i < 100; i++)
            printf("%d ", vet2[i]);

        break;
    default:
        printf("Digite um valor valido");
        break;
    }
}

/*
1) Faça uma função recursiva que permita inverter um número inteiro N. Ex:
123 - 321
 */

int inverter_numero(int numero)
{
    if (numero == 0) // caso base
        return 0;

    printf("%d", numero % 10);
    inverter_numero(numero / 10); // chamada recursiva
}

// a forma de encontrar a logica foi em pensar em como imprimir separadamente cada algarismo do numero.

// --------------------------------------------------------------------------------------------------------------

/*
2) Faça uma função recursiva que permita somar os elementos de
um vetor de inteiros.
 */

int soma_vetor(int* vet, int tam)
{
    if (tam == 0) // caso base
        return 0;

    return vet[tam - 1] + soma_vetor(vet, tam - 1); // chamada recursiva
}

// pensei primeiramente no caso base e a chamada recursiva seria o elemento atual + o anterior.
// no caso, começa em "tam - 1", pois como é um vetor, ele para 1 a menos que o tamanho dele.

// --------------------------------------------------------------------------------------------------------------

/*
3) Crie uma função recursiva que receba um número inteiro positivo N
e calcule o somatório dos números de 1 a N.
 */

int somatorioN(int n)
{
    if (n == 1) // caso base
        return 1;

    return n + somatorioN(n - 1); // chamada recursiva
}

// Foi a questão mais simples até agora. De incio eu pensei de forma errada
// (talvez por impulso pelas outras questões) que o caso base seria 0.
// a chamada recursiva eh bem fácil, pois é só pensar em somar o número atual com o anterior.

// --------------------------------------------------------------------------------------------------------------

/*
4) Crie um programa em C, que contenha uma função recursiva que
receba dois inteiros positivos k e n e calcule k^n. Utilize apenas
multiplicações. O programa principal deve solicitar ao usuário os valores
de k e n e imprimir o resultado da chamada da função.
 */

int func_pow(int k, int n)
{
    if (n == 1) //caso base
        return k;

    return k * func_pow(k, n - 1); // chamada recursiva
}

// muito parecida com as anteriores, bastou pensar na parada e em usar o numero atual e depois o anterior.
// com a diferença de precisar de dois parametros.

// --------------------------------------------------------------------------------------------------------------

/*
5) Crie um programa em C que receba um vetor de números reais com
100 elementos. Escreva uma função recursiva que inverta ordem dos
elementos presentes no vetor.
 */

void invert_elementos(int* vet, int primeiro, int ultimo)
{
    if (primeiro >= ultimo)
        return;

    int aux = vet[primeiro];
    vet[primeiro] = vet[ultimo];
    vet[ultimo] = aux;

    invert_elementos(vet, primeiro + 1, ultimo - 1);
}
