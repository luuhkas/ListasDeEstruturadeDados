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

        for (int i = 0; i < 100; i++) // apenas para criar um vetor de 100 numeros
        {
            vet2[i] = i + 1;
            printf("%d ", vet2[i]);
        }

        printf("\n\n");

        invert_elementos(vet2, 0, 99);

        for (int i = 0; i < 100; i++) // apenas para verificar se foi invertido corretamente
            printf("%d ", vet2[i]);

        break;

    case 6:

        int x, y;
        printf("Digite dois numeros para tirar o mdc: ");
        scanf("%d %d", &x, &y);

        printf("O resultado do mdc entre %d e %d eh: %d", x, y, mdcxey(x, y));
        break;

    case 7:
        int k2, n2;
        printf("Digite um algarismo e um numero para saber quantas vezes esse algarismo aparece no numero\n");
        scanf("%d %d", &k2, &n2);

        printf("O numero de vezes que o algarismo %d aparece no numero %d eh: %d\n", k2, n2, quantas_vezes_k(k2, n2));
        break;

    case 8:
        int n_1, n_2;

        printf("Digite dois numeros para saber seu produto: \n");
        scanf("%d %d", &n_1, &n_2);

        printf("O resultado de %d x %d = %d\n", n_1, n_2, Multip_Rec(n_1, n_2));
        break;

    case 9:
        int n3;

        printf("Digite um numero para todos os numeros pares ate ele: \n");
        scanf("%d", &n3);

        par_crescente(n3);
        break;
    case 10:
        int n4;

        printf("Digite um numero para saber todos seus antecessores ate 0: \n");
        scanf("%d", &n4);

        inteiros_positivo_descrescente(n4);
        break;

    case 11:
        int n5;

        printf("Digite um numero para saber a sequencia de antecessores, comecando do valor informado: \n");
        scanf("%d", &n5);

        inteiros_positivos_par_decrescente(n5);
        break;
    case 12:
        int n6;

        printf("Digite um numero para saber o fatorial duplo (produto dos numeros impares ate o numero informado): \n");
        scanf("%d", &n6);

        printf("O fatorial duplo de %d eh: %d", n6, fatorial_duplo(n6));
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
    if (primeiro >= ultimo) // caso base
        return;

    int aux = vet[primeiro];
    vet[primeiro] = vet[ultimo];
    vet[ultimo] = aux;

    invert_elementos(vet, primeiro + 1, ultimo - 1); // chamada recursiva
}

// lógica um pouco mais dificil. Mas cheguei na conclusao de andar com o primeiro pra direita do vetor e o ultimo
// pra esquerda do mesmo.

// --------------------------------------------------------------------------------------------------------------

/*
6) O máximo divisor comum dos inteiros x e y é o maior inteiro que é
divisível por x e y. Escreva uma função recursiva mdc em C, que retorna o
máximo divisor comum de x e y. O mdc de x e y é definido como segue:
se y é igual a 0, então mdc(x,y) é x; caso contrário, mdc(x,y) é mdc (y,
x%y), onde % é o operador resto.
*/

int mdcxey(int x, int y)
{
    if (y == 0) // caso de parada, apenas para se y for 0
        return x;

    if (x % y == 0) // caso base, como funciona o algoritmo de euclides
        return y;

    mdcxey(y, x % y);
}

// foi bem tranquila porque o enunciado ja da a resposta. Mas deu pra entender que tem que usar o algoritmo
// de euclides.

// --------------------------------------------------------------------------------------------------------------

/*
7) Escreva uma função recursiva que determine quantas vezes um
dígito K ocorre em um número natural N. Por exemplo, o dígito 2 ocorre 3
vezes em 762021192.
 */

int quantas_vezes_k(int k, int n)
{
    if (n == 0) // caso base
        return 0;

    if (n % 10 == k)
        return 1 + quantas_vezes_k(k, n / 10); // chamada recursiva

    return quantas_vezes_k(k, n / 10); // chamada recursiva. a diferença aqui é que a condição só é cumprida quando o
    //algarismo é diferente
}

// parte da logica é semelhante ao exercicio numero 1. o que tem a mais é verificar se o algarismo escolhido eh igual ao
// algarismo do numero na instancia q eh selecionado.

// --------------------------------------------------------------------------------------------------------------

/*
8) A multiplicação de dois números inteiros pode ser feita através de
somas sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2)
que calcule a multiplicação de dois inteiros.
 */

int Multip_Rec(int n1, int n2)
{
    if (n2 <= 1) // caso base
        return n1;

    return n1 + Multip_Rec(n1, n2 - 1); // chamada recursiva
}

// lógica similar a questão de potenciação. A diferença aqui é que é com soma. Só lembrar dos conceitos básicos da matemática

// --------------------------------------------------------------------------------------------------------------

/*
9) Faça uma função recursiva que receba um número inteiro positivo par
N e imprima todos os números pares de 0 até N em ordem crescente.
*/

void par_crescente(int n)
{
    if (n % 2 != 0) // caso nao seja par
    {
        printf("Escolha um numero par");
        exit(-1);
    }

    if (n == 0) // caso base
        printf("%d ", n);

    else
    {
        par_crescente(n - 2); // chamada recursiva
        printf("%d ", n);
    }
}

/*
essa questao foi de longe a mais dificil ate agora. primeiramente pensei em resolver criando dois parametros (n e aux)
em que aux começava com 0 e o caso base seria quando ele fosse igual a n. mas depois vi que a questão só aceitava 1 para-
metro. ai foi a parte mais dificil de pensar em printar somente depois do encerramento do empilhamento.
*/

// --------------------------------------------------------------------------------------------------------------

/*
10) Faça uma função recursiva que receba um número inteiro positivo
N e imprima todos os números naturais de 0 até N em ordem
decrescente.
 */

void inteiros_positivo_descrescente(int n)
{
    if (n < 0)
      exit(-2);

    if (n == 0) // caso base
    {
        printf("%d ", n);
        exit(0);
    }

    printf("%d ", n);

    return inteiros_positivo_descrescente(n - 1); // chamada recursiva
}

// logica bem parecida com a anterior, mas aqui eh bem mais facil de pensar, pois basta ir printando em cada instancia
// que esta sendo empilhada.

// --------------------------------------------------------------------------------------------------------------

/*
11) Faça uma função recursiva que receba um número inteiro positivo par
N e imprima todos os números pares de 0 até N em ordem decrescente.
 */

int inteiros_positivos_par_decrescente(int n)
{
    if (n < 0)
        exit(-3);

    printf("%d ", n);

    if (n == 0)
        return n;

    return inteiros_positivos_par_decrescente(n - 2);
}

// versao mais facil da questao 9, logica bem similar, foi exatamente na solucao dessa questao que pensei primeiramente
// na questao 9, o diferencial dessa questao agora foi que fiz com um retorno do tipo int, acho que fica ate mais pratico
// de resolver com um retorno do tipo int.

// --------------------------------------------------------------------------------------------------------------

/*
12) A função fatorial duplo é definida como o produto de todos os números
naturais ímpares de 1 até algum número natural ímpar N. Assim, o fatorial
duplo de 5 é 5!! = 1 * 3 * 5 = 15 Faça uma função recursiva que receba
um número inteiro positivo impar N e retorne o fatorial duplo desse
número.
*/

int fatorial_duplo(int n)
{
    if (n % 2 == 0)
    {
        printf("Digite um numero impar\n");
        exit(-4);
    }

    if (n == 1) // caso base
        return n;

    return n * fatorial_duplo(n - 2); // chamada recursiva
}

// mais uma vez, tendo feito as questoes anteriores, essa parece mais do mesmo. mas acredito que a intencao seja essa.
