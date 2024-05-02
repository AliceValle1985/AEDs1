/*Alice Pereira Valle Guimaraes - 813338 - 18/09/2023*/
#include "io.h"
#include <math.h>
//Metodo para mostrar o valor de uma variavel (y) enquanto ela for menor do que o numero que ira ser designado a variavel (x)
void method_01a (int x)
{
    int y = 0;
    while (y <= x)
    {
        IO_printf("%s%d\n", "Valor = ", y);
        y = y + 1;
    }
}
//vai fazer a msm coisa que o metodo 1 mas ira mostrar a numeracao dos numeros, exemplo:
/*  1: 5
    2: 5
    3: 5
    4: 5
    5: 5
    */
// a variavel z não serve para literalmente nada
void method_02a (int x)
{
    int y = 1;
    int z = 2;
    while(y <= x)
    {
        IO_printf("%d: %d\n", y, x);
        z = z + 2;
        y = y + 1;
    }  
}
//ira exibir a variavel de dois em dois numeros, como na chamada de funcao foi dado o valor de 5, entao ira mostrar os valores de 2, 4, 6, 8 e 10
void method_03a(int x)
{
    int y = 1;
    int z = 0;
    while(y <= x)
    {
        z = 2 * y;
        IO_printf("%d: %d\n", y, z);
        y = y + 1;
    }
}
//enquanto y (que e igual a 0) for igual a 0 mostrar y (0) e z (0), entao 0: 0
void mehtod_04a(int x)
{
    int y = 0;
    int z = 0;
    while(y == 0)
    {
        z = 2 * y;
        IO_printf("%d: %d\n", y, z);/*0: 0*/
        y = y -1;
    }
}


//vai exibir a variavel y e iria multiplicar por dois e ira subitrair 1 ate chegar a 1 (y > 0)
void method_05a(int x)
{
    int y = 0;
    for(y = x; y > 0; y--)
    {
        IO_printf("%d: %d\n", y, (2 * y));
        /*  5: 10
            4: 8
            3: 6
            2: 4
            1: 2
        */
    }
}
/*
Incluir função e método (0511) para:
para ler uma quantidade inteira (n) do teclado e, mediante um procedimento,
mostrar essa quantidade em valores múltiplos de 7 em ordem crescente.
*/
void method_11a(int x)
{
    for(int i = 1; i <= x; i++)       
    {
        if(i % 7 == 0)
        {
            printf("%d\n", i);        
        }
    }
}
void method_12a(int x)
{
/*
 Incluir função e método (0512) para:
para ler uma quantidade inteira do teclado e, mediante um procedimento,
mostrar essa quantidade em valores múltiplos de 3 e 4 em ordem crescente
*/
    for(int i = 1; i <= x; i++)
    {
        if(i % 3 == 0 && i % 4 == 0)
        {
            printf("\n%d", i);
        }
    }
}
void method_13a(double x){
    /* Incluir função e método (0513) para:
para ler uma quantidade inteira do teclado e, mediante um procedimento,
mostrar essa quantidade em valores ímpares potências de 5 em ordem decrescente.*/
    for (int y = x; y > 0; y--)
    {
        IO_printf("%d: %.2lf\n", 5 - (y-1), pow(5, y)); 
    }
} 

float method_14a(int x){
    int numerador = 1;
    int denominador = 1;
    for (int i = 1; i <= x; i++)
    {
        denominador = i * 6;
        IO_printf("%d: %d/%d\n", i, numerador, denominador);
    }
}

int somarvalores (int x)
{
    //soma = 1
    int soma = 1;
    //quantidade de vezes q esse loop vai acontecer vai ser x - 1 vezes enquanto y for menor ou igual a x - 1
    for(int y = 0; y <= (x - 1); y++)
    {
        //vai mostrar o y de forma crescente e depois o y multiplicado por 2
        IO_printf("%d: %d\n", y, (2 * y));
        /*
            0: 0
            1: 2
            2: 4
            3: 6
            4: 8
        */
        soma = soma + (2 * y);
    }
    return (soma);
}
double method_15a (int x, double y)
{
    int numerador = 1;
    double denominador = 1.0;
    for(int i = 1; i <= x; i++)
    {
        denominador = pow( y, (2 * i) - 1);
        IO_printf("%d: %d/%.2lf\n", i, numerador, denominador);
    }
}
int method_16a (int x)
{
    int soma = 0;
    int z = 0;
    for (int i = 1; i <= x; i++)
    {
        z = z + 3;
        IO_printf("%d - ", z);
        if (((z % 2) == 0) && ((z % 4) != 0)) 
        {
            soma += z;
        }
    }
    return(soma);
}
double method_17a (int x, double y)
{
    int numerador = 1;
    int denominador = 6;
    double soma = 0.0;
    for (int i = 1; i <= x; i++)
    {
        denominador = denominador + y;
        IO_printf("%d: %d/%d\n", i, numerador, denominador);
        if (((denominador % 2) == 0) && ((denominador % 5) != 0))
        {
            soma = soma + ((float)numerador / (float)denominador);
        }
    }
    return(soma);
}
double somarfracao1(int x)
{
    double soma        = 1.0;
    double numerador   = 0.0;
    double denominador = 0.0;
    //ira exibir em ordem decrescente
    for(int y = 1; y <= (x -1); y++)
    {
        numerador  = 1.0;
        denominador = 2.0 * y;
        //vai exibir y (que e a quantidade), o numerador (que e o numero q vai ser dividido pelo denominador), denominador (vai dividir o numerador) e por ultimo o numerador sendo dividido pelo denominador
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y, numerador, denominador, (numerador/denominador));
        //soma do valor de todas as fracoes
        soma = soma + (1.0)/(2.0 * y);
    }
    return (soma);
}
double somarfracoes2 (int x)
{
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
    for(int y = 1; y <= (x - 1); y++)
    {
        numerador = 2.0 * y-1;
        denominador = 2.0 * y;
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y+1, numerador, denominador, (numerador/denominador) );
        soma = soma + numerador / denominador;
    }
    return(soma);
}
double somarfracao3(int x)
{
    double soma = 1.0;
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
    for(int y = 1; y < x; y++)
    {
        IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n", y+1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)) );
        soma = soma + (2.0 * y)/(2.0 * y + 1);
    }
    return (soma);
}
int multiplicarvalores(int x)
{
    int produto = 1;
    for(int y = 1; y <= x; y++)
    {
        IO_printf("%d: %d\n", y, (2 * y - 1));
        produto = produto * (2*y-1);
    }
    return(produto);
}
void method_01 ()
{
    IO_id ("Method_01 - v0.0");
    //5 e o numero desinado, entao ira mostrar do numero zero ate o numero 5
    method_01a (5);
    IO_pause ("Apertar ENTER para continuar");
}

void method_02()
{
    IO_id ( "Method_02 - v0.0" );
    //da o valor de 5 para mostrar 5 vezes
    method_02a(5);
    IO_pause ("Apertar ENTER para continuar");
    
}

void method_03()
{
    IO_id("Method_03 - v0.0");
    method_03a (5);
    IO_pause("Aperte ENTER para continuar");
}

void method_04()
{
    IO_id ("Method_04 - v0.0");
    mehtod_04a(5);
    IO_pause("Apertar ENTER para continuar");
           
}

void method_05()
{
    IO_id("Mwthod_05 -v0.0");
    method_05a(5);
    IO_pause("Apertar ENTER para continuar");
}

void method_06()
{
    int soma = 0;
    IO_id("Method_06 - v0.0");
    soma = somarvalores(5);
    IO_pause("Aperte ENTER para continuar");
}

void method_07( )
{
    double soma = 0.0;
    IO_id("Method_07 - v0.0");
    soma = somarfracao1(5);
    IO_printf("Soma de fracoes = %lf\n", soma);
    IO_pause("Apertar ENTER para continuar");
}
void method_08()
{
    double soma = 0.0;
    IO_id("Method_08 - v0.0");
    soma = somarfracoes2(5);
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_09 ( )
{
    double soma = 0.0;
    IO_id ( "EXEMPLO0509 - Method_09 - v0.0" );
    soma = somarfracao3 ( 5 );
    IO_printf ( "soma de fracoes = %lf\n", soma );
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_10 ( )
{
    IO_id ( "Method_10 - v0.0" );
    IO_printf ( "%s%d\n", "produto = ", multiplicarvalores ( 5 ) );
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_11()
{
    int x = 0;
    printf("\nDigite a quantidade de numeros multiplos de 7: \n");
    scanf("%d", &x);
    printf("Multiplos de sete em ordem crescente: ");
    method_11a(x);
}
void method_12()
{
    int x = 0;
    printf("\nDigite um numero: \n");
    scanf("%d", &x);
    printf("Multiplos de 3 e 4 em ordem crescente: ");
    method_12a(x);
}
void method_13(){
    double x = IO_readint("\nDigite quantidade a ser testada: ");
    method_13a(x);
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_14( )
{
    int x = IO_readint("\nDigite quantidade a ser testada: ");
    method_14a(x);
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_15( )
{
    int x = IO_readint("\nDigite quantidade a ser testada: ");
    double y = IO_readint("\nNumero do denominador: ");
    method_15a(x , y);
    IO_pause ( "Apertar ENTER para continuar" );
} 


void method_16 ( )
{
    IO_printf("%s%d\n", "\nSoma dos pares nao multiplos de 4: \n", method_16a(5));
     IO_printf("%s%d\n", "\nSoma dos pares nao multiplos de 4: \n", method_16a(10));
     IO_printf("%s%d\n", "\nSoma dos pares nao multiplos de 4: \n", method_16a(15));
    IO_pause ( "Apertar ENTER para continuar" );
} 


void method_17 ( )
{
    int x = 0 ; 
    double y = 0.0;
    IO_id ( "EXEMPLO0517 - Method17 - v0.0" );
    IO_printf("%s%f\n", "\nSoma dos pares postivos, não multiplos de 5 TESTE 1: \n", method_17a (5, 3));
    IO_printf("%s%f\n", "\nSoma dos pares postivos, não multiplos de 5 TESTE 2: \n", method_17a (10, 2)); 
    IO_printf("%s%f\n", "\nSoma dos pares postivos, não multiplos de 5 TESTE 3: \n", method_17a (15, 7)); 
    IO_pause ( "Apertar ENTER para continuar" );
}
int main(void)
{
     int opcao = 0;
    printf ( "%s\n", "Exemplo0517 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n%s" , "2 - Method_02" );
        printf ( "\n%s" , "3 - Method_03" );
        printf ( "\n%s" , "4 - Method_04" );
        printf ( "\n%s" , "5 - Method_05" );
        printf ( "\n%s" , "6 - Method_06" );
        printf ( "\n%s" , "7 - Method_07" );
        printf ( "\n%s" , "8 - Method_08" );
        printf ( "\n%s" , "9 - Method_09" );
        printf ( "\n%s" , "10 - Method_10" );
        printf ( "\n%s" , "11 - Method_11" );
        printf ( "\n%s" , "12 - Method_12" );
        printf ( "\n%s" , "13 - Method_13" );
        printf ( "\n%s" , "14 - Method_14" );
        printf ( "\n%s" , "15 - Method_15" );
        printf ( "\n%s" , "16 - Method_16" );
        printf ( "\n%s" , "17 - Method_17" );
        printf ( "\n" );
        printf ( "\n%s", "Opcao = " );
        scanf ( "%d", &opcao );
        getchar( );
        printf ( "\n%s%d", "Opcao = ", opcao );
    switch (opcao)
    {
        case 1:
            method_01 ( );
            break;
        case 2:
            method_02 ( );
            break;
        case 3:
            method_03 ( );
            break;
        case 4:
            method_04 ( );
            break;
        case 5:
            method_05 ( );
            break;
        case 6:
            method_06 ( );
            break;
        case 7:
            method_07 ( );
            break;
        case 8:
            method_08 ( );
            break;
        case 9:
            method_09 ( );
            break;
        case 10:
            method_10 ( );
            break;
        case 11:
            method_11 ( );
            break;
        case 12:
            method_12 ( );
            break;
        case 13:
            method_13 ( );
            break;
        case 14:
            method_14 ( );
            break;
        case 15:
            method_15 ( );
            break;
        case 16:
            method_16 ( );
            break;
        case 17:
            method_17 ( );
            break;
        default:
            printf ( "\nERRO: Opcao invalida.\n" );
                break;
    }
}while (opcao !=0);
     printf ( "\n\nApertar ENTER para terminar." );
    getchar( );  
    return 0;
}