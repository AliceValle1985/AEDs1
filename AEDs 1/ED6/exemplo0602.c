/*Alice Pereira Valle Guimaraes - 813338 - 26/09/2023*/
#include <stdio.h>
#include "io.h"

//funcao recursiriva para o metodo 1
void method_01a(int x)
{
    //se x for maior que 0
    if (x > 0)
    {
        //exibir o valor de x na tela
        IO_printf("%s%d\n", "Valor = ", x);
        //e se chama, diminuindo o valor de x ate o valor fique 1 a mais de 1, pq eh x > 0 e nao x >= 0
        method_01a(x - 1);
        /*
            Valor = 5
            Valor = 4
            Valor = 3
            Valor = 2
            Valor = 1
        */
    }
}
//metodo que ira chamar a funcao recursiva
void method_01()
{
    //essas variaveis nao servem para literalmente nada, entao ignore, o deixei pq estava no codigo do professor
    int quantidade = 0;
    int valor      = 0;
    int controle   = 0;
    IO_id("\nMethod_01 - v0.0");
    method_01a(5);
    IO_pause("Aperte ENTER para continuar");
}


//funcoa recursiva q chama ela msm enquanto x for maior que 0, e diminur o valor de x por - 1, basicamente vai fazer a msm coisa que o method_01 fez
void method_02a(int x)
{
    //se x for maior que 5
    if (x > 0)
    {
        //chamar o metodo e subtrair 1 do x 
        method_02a(x - 1);
        //exibir o valor
        IO_printf("%s%d\n", "Valor = ", x);
    }
}
void method_02( )
{
    IO_id("Method_02 - v0.0");
    //chamar a funcao recursiva
    method_02a(5);
    IO_pause ("Apertar ENTER para continuar");
}


int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0602 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n%s" , "2 - Method_02" );
        printf ( "\n" );
        printf ( "\n%s", "Opcao = " );
        scanf ( "%d", &x );
        getchar( );
        printf ( "\n%s%d", "Opcao = ", x );
        switch ( x )
        {
            case 0:
                break;
            case 1: 
                method_01 ( ); 
                break;
            case 2: 
                method_02 ( ); 
                break;
            default: 
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( x != 0 );
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}
