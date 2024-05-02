/*
Exemplo0200 - v0.0. - 31 / 08 / 2023
Author: Alice Pereira Valle Guimaraes
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0200 exemplo0200.c
Windows: gcc -o exemplo0200 exemplo0200.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0200
Windows: exemplo0200
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include "io.h"
/**
Method_01.
*/
void method_01 ( void )
{
    int x = 0; 
    IO_id ( "Method_01 - Programa - v0.0" );
    x = IO_readint ( "Entrar com um valor inteiro: " );
    if ( x == 0 )
    {
        IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
    }
    if ( x != 0 )
    {
        IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
} 

void method_02 ( void )
{
    int x = 0; 
    IO_id ( "Method_02 - Programa - v0.0" );
    x = IO_readint ( "Entrar com um valor inteiro: " );
    if ( x == 0 )
    {
        IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
    }
    else 
    {
        IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_03 ( void )
{
    int x = 0; 

    IO_id ( "Method_03 - Programa - v0.0" );
    x = IO_readint ( "Entrar com um valor inteiro: " );
    if ( x == 0 )
    {
        IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
    }
    else
    {
        IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
        if ( x > 0 )
        {
            IO_printf ( "%s (%d)\n", "Valor maior que zero", x );
        }
        else
        {
            IO_printf ( "%s (%d)\n", "Valor menor que zero", x );
        }
    }
}


void method_04 ( void )
{
    double x = 0.0; 
    IO_id ( "EXEMPLO0204 - Programa - v0.0" );
    x = IO_readdouble ( "Entrar com um valor real: " );
    if ( 1.0 <= x && x <= 10.0 )
    {
        IO_printf ( "%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x );
    }
    else
    {
        IO_printf ( "%s (%lf)\n", "Valor fora do intervalo [1:10] ", x );
        if ( x < 1.0 )
        {
            IO_printf ( "%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x );
        }
        else
        {
        IO_printf ( "%s (%lf)\n", "Valor acima do intervalo [1:10]", x );
        }
    }

    IO_pause ( "Apertar ENTER para continuar" );
} 

void method_05 ( void )
{
    char x = '_'; 
    IO_id ( "Method_05 - Programa - v0.0" );
    x = IO_readchar ( "Entrar com um caractere: " );
    if ( ('a' <= x) && (x <= 'z') )
    {
        IO_printf ( "%s (%c)\n", "Letra minuscula", x );
    }
    else
    {
        IO_printf ( "%s (%c)\n", "Valor diferente de minuscula", x );
        if ( ('A' <= x) && (x <= 'Z') )
        {
            IO_printf ( "%s (%c)\n", "Letra maiuscula", x );
        }
        else
        {
            if ( ('0' <= x) && (x <= '9') )
            {
                IO_printf ( "%s (%c)\n", "Algarismo", x );
            }
            else
            {
                IO_printf ( "%s (%c)\n", "Valor diferente de algarismo", x );
            } 
        } 
        } 
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_06 ( void )
{
    char x = '_'; 
    IO_id ( "Method_06 - Programa - v0.0" );
    x = IO_readchar ( "Entrar com um caractere: " );
    if ( ( 'a' <= x && x <= 'z' ) || ( 'A' <= x && x <= 'Z' ) ) 
    {
        IO_printf ( "%s (%c)\n", "Letra", x );
    }
    else
    {
        IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
    }
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_07 ( void )
{
    char x = '_'; 
    IO_id ( "Method_07 - Programa - v0.0" );
    x = IO_readchar ( "Entrar com um caractere: " );
    if ( ! ( ( 'a' <= x && x <= 'z' ) || ( 'A' <= x && x <= 'Z' ) ) )
    {
        IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
    }
    else
    {
        IO_printf ( "%s (%c)\n", "Letra", x );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_08 ( void )
{
    char x = '_'; 
    IO_id ( "Method_08 - Programa - v0.0" );
    x = IO_readchar ( "Entrar com um caractere ['0','A','a']: " );
    switch ( x )
    {
        case '0':
            IO_printf ( "%s (%c=%d)\n", "Valor igual do simbolo zero", x, x );
            break;
        case 'A':
            IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra A", x, x );
            break;
        case 'a':
            IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra a", x, x );
            break;
        default:
        IO_printf ( "%s (%c=%d)\n", "Valor diferente das opcoes ['0','A','a']", x, x );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_09 ( void )
{
    int x = 0; 
    IO_id ( "Method_09 - Programa - v0.0" );
    x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
    switch ( x )
    {
        case 0:
            IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
            break;
        case 1:
            IO_printf ( "%s (%d)\n", "Valor igual a um ", x );
            break;
        case 2:
            IO_printf ( "%s (%d)\n", "Valor igual a dois", x );
            break;
        case 3:
            IO_printf ( "%s (%d)\n", "Valor igual a tres", x );
            break;
            default:
        IO_printf ( "%s (%d)\n", "Valor diferente das opcoes [0,1,2,3]", x );
    }
}

void method_10 ( void )
{
    int x = 0; 
    IO_id ( "Method_09 - Programa - v0.0" );
    x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
    switch ( x )
    {
        case 0:
            IO_println ( IO_concat ( "Valor igual a zero (",
            IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
            break;
        case 1:
            IO_println ( IO_concat ( "Valor igual a um (",
            IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
            break;
        case 2:
            IO_println ( IO_concat ( "Valor igual a dois (",
            IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
            break;
        case 3:
            IO_println ( IO_concat ( "Valor igual a três (",
            IO_concat ( IO_toString_d ( x ), ")\n" ) ) );
            break;
        default: 
            IO_println ( IO_concat ( "Valor diferente das opcoes [0,1,2,3] (",
            IO_concat ( IO_toString_d ( x ), ")" ) ) );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}
void method_11 ( )
{
    int par = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &par);
    if ((par % 2) != 1)
    {
        printf("\nE um numero par.");
    }
    else
    {
    printf("\nNao e um numero par");
    }
}
void method_12 ( ) 
{
    int x = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &x);
    if((x % 2) != 0 && x < (-15))
    {
        printf("\nE um numero impar e menor que -15");
    }
    else if((x % 2) == 0 && x > 15)
    {
         printf("\nE um numero par maior que 15");
    }
    else if((x % 2) == 0 && x > (-15) && x < 15)
    {
        printf("\nE um numero par que esta entre -15 e 15");
    }
    else if((x % 2) != 1 && x > (-15) && x < 15)
    {
        printf("\nE um numero impar que esta entre -15 e 15");
    }
}

void method_13 ( )
{   
    int x = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &x);
    if (x < 65 && x > 25)
    {
        printf("\nEsse numero pertence e ao intervalo de 25 a 65.");
    }
    else
    {
        printf("Esse numero nao pertence ao intervalo de 25 a 65.");
    }
}

void method_14( )
{
    int x = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &x);
    if (x < 60 && x > 20)
    {
        printf("\nEsse numero pertence e ao intervalo de 20 a 60.");
    }
    else
    {
        printf("Esse numero nao pertence ao intervalo de 20 a 60.");
    }
}

void method_15( )
{
    int x = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &x);
    if (x < 30 && x > 15)
    {
        printf("\nEsse numero pertence e ao intervalo de 15 a 30.");
    }
    else
    {
        printf("\nEsse numero nao pertence ao intervalo de 15 a 30.");
    }
    if (x < 50 && x > 25)
    {
        printf("\nEsse numero pertence e ao intervalo de 25 a 50.");
    }
    else
    {
        printf("\nEsse numero nao pertence ao intervalo de 25 a 50.");
    }   
}

void method_16 ( )
{
    int primeiro = 0;
    int segundo  = 0;
    printf("\nDigite o primeiro numero: ");
    scanf("%d", &primeiro);
    printf("\nDigite o segundo numero: ");
    scanf("%d", &segundo);
    if ((primeiro % 2) != 1)
    {
        printf("\nO primeiro numero e par");
    }
    else
    {
        printf("\nO primeiro numero NAO e par");
    }
    if((segundo % 2) != 1)
    {
        printf("\nO segundo numero e par");
    }
    else
    {
        printf("\nO segundo numero NAO e par");
    }
}

void method_17 ( ) 
{
    int primeiro = 0;
    int segundo  = 0;
    printf("\nDigite o primeiro numero: ");
    scanf("%d", &primeiro);
    printf("\nDigite o segundo numero: ");
    scanf("%d", &segundo);
    if ((primeiro % 2) != 0 && primeiro < 0)
    {
        printf("\nO primeiro e um numero impar negativo.");
    }
    else
    {
        printf("\nO primeiro NAO e um numero impar negativo.");
    }
    if((segundo % 2) != 1 && segundo > 0)
    {
        printf("\nO segundo e um numero par positivo.");
    }
    else
    {
        printf("\nO segundo NAO e um numero par positivo.");
    }
}

void method_18 ( )
{
    int primeiro = 0;
    int segundo = 0;
    printf("\nDigite o primeiro numero: ");
    scanf("%d", &primeiro);
    printf("\nDigite o segundo numero: ");
    scanf("%d", &segundo);
    if(segundo < primeiro)
    {
        printf("\nO segundo valor eh menor que o primeiro valor.");
    }
    if (segundo == primeiro)
    {
        printf("\nO segundo valor eh igual ao primeiro valor.");
    }
    if(primeiro = (primeiro * 2))
    {
        printf("\nO segundo valor eh o dobro do primeiro valor.");
    }
}

void method_19 ( )
{
    double primeiro = 0;
    double segundo  = 0;
    double terceiro  = 0;
    printf("\nDigite o primeiro numero: ");
    scanf("%lf", &primeiro);
    printf("\nDigite o segundo numero: ");
    scanf("%lf", &segundo);
    printf("\nDigite o terceiro numero: ");
    scanf("%lf", &terceiro);
    if (terceiro < segundo && terceiro > primeiro)
    {
        printf("\nO terceiro numero esta entre o primeiro e o segundo.");
    }
    else if (terceiro < primeiro  &&  terceiro > segundo)
    {
        printf("\nO terceiro numero NAO esta entre o primeiro e o segundo.");
    }
    else if (primeiro == segundo)
    {
        printf("\nO primeiro e segundo numero sao iguais.");
    }
    else
     {
        printf("\nO terceiro numero nao esta no intervalo entre o primeiro e o segundo");
    }
}
//Nao entendi o motivo do metodo 20 nao estar funcionando, a logica dele esta correta. Ate tentei colocar um getchar para ver se era esse o erro, mas aparentemente nao eh, entao nao sei o que poderia ser
void method_20 ( )
{
    double primeiro = 0;
    double segundo  = 0;
    double terceiro  = 0;
    printf("\nDigite o primeiro numero: ");
    scanf("%lf", &primeiro);
    getchar( );
    printf("\nDigite o segundo numero: ");
    scanf("%lf", &segundo);
    getchar( );
    printf("\nDigite o terceiro numero: ");
    scanf("%lf", &terceiro);
    getchar( );
    if (primeiro != segundo && segundo != terceiro && terceiro != primeiro)
    {
         if (terceiro > segundo && terceiro < primeiro)
        {
            printf("\nO terceiro numero esta entre o primeiro e o segundo.");
        }
        else if (terceiro > primeiro  &&  terceiro < segundo)
        {
            printf("\nO terceiro numero esta entre o primeiro e o segundo.");
        }
        else if (terceiro < segundo && terceiro > primeiro)
        {
            printf("\nO terceiro numero NAO esta entre o primeiro e o segundo.");
        }
        else if (terceiro < primeiro && terceiro > segundo)
        {
            printf("\nO terceiro numero NAO esta entre o primeiro e o segundo.");
        }
    }
    else
    {
        printf("Os tres numeros sao iguais.");
    }
    
}
void method_21()
{
    char palavra1[4];
    char palavra2[4];
    char palavra3[4];

    printf("\nDigite as tres letras do primeiro char: ");
    for(int i = 0; i < 3; i++)
    {
        scanf(" %c", &palavra1[i]);
    }
    printf("\nDigite as tres letras do segundo char: ");
    for(int i = 0; i < 3; i++)
    {
        scanf(" %c", &palavra2[i]);
    }
    printf("\nDigite as tres letras do terceiro char: ");
    for(int i = 0; i < 3; i++)
    {
        scanf(" %c", &palavra3[i]);
    }
    int resultado1 = strcmp(palavra1, palavra2);
    int resultado2 = strcmp(palavra1, palavra3);
    if(resultado1 == 0)
    {
        printf("\nA primeira palavra é igual a segunda.\n");
    }
    if(resultado2 == 0)
    {
        printf("\nA primeira palavra é igual a terceira.\n");
    }
    for(int i = 0; i < 3; i++)
    {
        
        if(palavra1[1] == palavra2[i] || palavra1[1] == palavra3[i])
        {
            printf("\n%c esta entre os dois outros valores.\n", palavra1[1]);
        }
        if(palavra1[2] == palavra2[i] || palavra1[2] == palavra3[i])
        {
            printf("\n%c esta entre os dois outros valores.\n", palavra1[2]);
        }
        if(palavra1[3] == palavra2[i] || palavra1[3] == palavra3[i])
        {
            printf("\n%c esta entre os dois outros valores.\n", palavra1[3]);
        }
    }
}
void method_22()
{
    char palavra1[4];
    printf("\nDigite as tres letras do char: ");
    for(int i = 0; i < 3; i++)
    {
        scanf(" %c", &palavra1[i]);
    }
    if(palavra1[0] > palavra1[1] && palavra1[0] < palavra1[2] || palavra1[0] < palavra1[1] && palavra1[0] > palavra1[2])
    {
        printf("\n%c esta entre %c e %c.", palavra1[0], palavra1[1], palavra1[2] );
        printf("\nBucetão");
    }
    else 
    {
        printf("\n%c não esta entre %c e %c.", palavra1[0], palavra1[1], palavra1[2] );
    }
}
int main ( void )
{
 int opcao = 0;
    printf ( "%s\n", "Exemplo0200 - Programa = v0.0" );
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
        printf ( "\n%s" , "18 - Method_18" );
        printf ( "\n%s" , "19 - Method_19" );
        printf ( "\n%s" , "20 - Method_20" );
        printf ( "\n%s" , "21 - Extra_21" );
        printf ( "\n%s" , "22 - Extra_22" );
        printf ( "\n" );
        printf ( "\n%s", "Opcao = " );
        scanf ( "%d", &opcao );
        getchar( );
        printf ( "\n%s%d", "Opcao = ", opcao );
        switch ( opcao )
        {
            case 0:
                break;
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
            case 18:
                method_18 ( );
                break;
            case 19 :
                method_19 ( );
                break;
            case 20:
                method_20 ( );
                break;
            case 21:
                method_21 ( );
                break;
            case 22:
                method_22 ( );
                break;
            default: 
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( opcao != 0 );
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
*/