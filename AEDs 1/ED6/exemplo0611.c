/*Alice Pereira Valle Guimaraes - 813338 - 29/09/2023*/
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
/*oq eu entendi: a funcao chama ela msm e faz oq esta dentro do () e ai ela volta para o inicio para refazer oq ela já tinha feito
nesse caso ela faz x - 1 ate que o valor seja maior que 0
*/


//vai fazer a msm coisa que os anteriores o que vai mostrar o numero maiores que 1
void method_03a(int x)
{
    if(x > 1)
    {
        method_03a(x - 1);
        IO_printf("%s%d\n", "Valor = ", x);
    }
}
void method_03()
{
    IO_id("Method_03 - v0.0");
    method_03a(5);
    /*
        Valor = 2
        Valor = 3
        Valor = 4
        Valor = 5
    */
    IO_pause ("Apertar ENTER para continuar");
}
//end method_03

//metodo_04
void method_04a (int x)
{
    if(x > 1)
    {
        method_04a(x - 1);
        IO_printf("%s%d\n", "Valor = ", 2 * (x - 1));
    }
    else
    {
        IO_printf("%s\n", "Valor = 1");
    }
}
void method_04()
{
    IO_id("Method_04 - v0.0");
    method_04a ( 5 );
    /*
        Valor = 1
        Valor = 2
        Valor = 4
        Valor = 6
        Valor = 8
    */
    IO_pause("Aperte ENTER para continuar");
}
//end method_04


//metodo 5 vai chamar funao e vai diminuir o valor de x ate que x seja maior que 1
void method_05a(int x)
{
    if(x > 1)
    {
        method_05a(x - 1);
        //vai exibir o x, depois o x - 1 multiplicado por 2, e depois depois o x - 1 multiplicado por 2 + 1 
        IO_printf("%d: %d/%d\n", x, (2 * (x -1)), (2 * (x - 1) + 1));
        /*
            2: 1 / 2
            3: 4 / 5
            4: 6 / 7
            5: 8 / 9
        */
    }
}
void method_05()
{
    IO_id("\nMethod_05 - v0.0");
    method_05a(5);
    IO_pause("Apertar ENTER para continuar");
}// end method_05



double somarfracoes_06a(int x)
{
    double soma = 0.0;
    if(x - 1)
    {
        soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarfracoes_06a(x - 1);
        IO_printf("%d: %lf / %lf\n", x, (2.0 * (x - 1)), (2.0 * (x - 1) + 1));
    }
    else
    {
        soma = 1.0;
        IO_printf("%d: %lf \n", x, 1.0);
    }
    return (soma);
}
void method_06()
{
    double soma = 0.0;
    IO_id ( "Method_06 - v0.0" );
    soma = somarfracoes_06a(5);
    IO_printf("Soma = %lf\n", soma);
    IO_pause("Apertar ENTER para continuar");
}//end method_06


double somarfracoes2_07b(int x, double soma, double numerador, double denominador)
{
    //enquanto x for maior que 0
    if(x > 0)
    {
        //exibir x, o numerador e denominador
        IO_printf("%d: %lf / %lf\n", x, numerador, denominador);
        //vai diminuir 1 de x, vai fazer a soma + numerador (dividivo pelo denominador), exibe tambem o numerador + 2 e o denominador+2
        soma = somarfracoes2_07b (x - 1, soma + ((1.0 * numerador ) / denominador), numerador + 2.0, denominador + 2.0);
    }
    // e vai retornar o valor da soma 
    return (soma);
}
double somarfracoes2_07a(int x)
{
    double soma = 0.0;
    //enquanto o valor de x for maior que 0 
    if (x > 0)
    {
        //exibir x e 1.0
        IO_printf("%d: %lf\n", x, 1.0);
        //ira chamar a funcao somarfracoes2_07b e ira fazer todos os calculos feitos anteriormente na funcao somarfracoes2_07b
        soma = somarfracoes2_07b(x - 1, 1.0, 2.0, 3.0);
        /*
            5: 1.000000
            4: 2.000000 / 3.000000
            3: 4.000000 / 5.000000
            2: 6.000000 / 7.000000
            1: 8.000000 / 9.000000
            soma = 4.212698
            
        */
    }
    //vai retornar o resultado da soma
    return (soma);
}
void method_07()
{
    double soma = 0.0;
    IO_id ( "\nMethod_07 - v0.0" );
    soma = somarfracoes2_07a(5);
    IO_printf("soma = %lf\n", soma);
    IO_pause("Apertar ENTER para continuar");
}//end Method_07

int contardigitos(int x)
{
    int respostas = 1;
    if(x >= 10)
    {
        respostas = 1 + contardigitos(x / 10);
    }
    else
    {
        respostas = contardigitos(- x);
    }
    return (respostas);
}
void method_08()
{
    IO_id ("\nMethod_08 - v0.0");
    IO_printf("Digitos (%3d) = %d\n", 123, contardigitos(123));
    IO_printf("Digitos (%3d) = %d\n", 1, contardigitos(1));
    IO_printf("Digitos (%3d) = %d\n", - 10, contardigitos(-10));
    IO_pause("Aperte ENTER para continuar");
}// end method_08



int fibonacci(int x)
{
    int resposta = 0;
    if (x == 1 || x == 2)
    {
        resposta = 1;
    }
    else
    {
        if (x > 1)
        {
            resposta = fibonacci (x - 1) + fibonacci (x - 2);
        }
    }
    return (resposta);
}
void method_09()
{
    IO_id("Method_09 - v0.0");
    IO_printf("Fibonacci = (%d) = %d\n", 1, fibonacci( 1 ));
    //Fibonacci = ( 1 ) = 1
    IO_printf("Fibonacci = (%d) = %d\n", 2, fibonacci( 2 ));
    //Fibonacci = ( 2 ) = 1
    IO_printf("Fibonacci = (%d) = %d\n", 3, fibonacci( 3 ));
    //Fibonacci = ( 3 ) = 2
    IO_printf("Fibonacci = (%d) = %d\n", 4, fibonacci( 4 ));
    //Fibonacci = ( 4 ) = 3
    IO_printf("Fibonacci = (%d) = %d\n", 5, fibonacci( 5 ));
    //Fibonacci = ( 5 ) = 5
    IO_pause ( "Apertar ENTER para continuar" );
}
/*
    Fibonacci = (1) = 1
    Fibonacci = (2) = 1
    Fibonacci = (3) = 2
    Fibonacci = (4) = 3
    Fibonacci = (5) = 5
*/
// end mathod_09

int contarminusculas(chars cadeia, int x)
{
    int resposta = 0;
    if(0 <= x && x < strlen(cadeia))
    {
        if(cadeia [x] >= 'a' && cadeia[x] <= 'z')
        {
            resposta = 1;
        }
        resposta = resposta + contarminusculas (cadeia, x + 1);
    }
    return (resposta);
}
void method_10()
{
    
    IO_id("Method_10 - v0.0");
    IO_printf ( "Minusculas (\"abc\",0) = %d\n", contarminusculas ( "abc", 0 ) );
    //Minusculas ("AbC",0) = 1
    IO_printf ( "Minusculas (\"aBc\",0) = %d\n", contarminusculas ( "aBc", 0 ) );
    //Minusculas ("aBc",0) = 2
    IO_printf ( "Minusculas (\"AbC\",0) = %d\n", contarminusculas ( "AbC", 0 ) );
    //Minusculas ("abc",0) = 3
    IO_pause("Apertar ENTER para continuar");
}
/*
    Minusculas ("abc",0) = 3
    Minusculas ("aBc",0) = 2
    Minusculas ("AbC",0) = 1
*/
//end method_10

/* Incluir um método recursivo (0611) para
ler um valor inteiro do teclado e chamar procedimento recursivo para
mostrar essa quantidade em valores pares em ordem crescente começando no valor 7*/
int mostrarpares(int x, int a)
{
    if(x > 0)
    {
        //o a vem para ca com o valor de 7, entao nao e um numero par, não sendo um numero par ele e jogado para o else, que vai aumentar um a mais no valor de 7, fazendo ser um 8, e como chamou uma funcao recursiva ela vai voltar para o inicio e vai fazer de novo a verificacao. Ai o valor vai ser um par e vai realizar o if, que ira exibir o par na tela e vai mudar os valores de x e a na recursao, x - 1 (para diminuir a quantidade de vezes que o if vai ser feito) e a + 2 para aumentar o valor do a para um outro numero par
        if (a % 2 == 0)
        {
            printf("%d \n", a);
            mostrarpares(x - 1, a + 2);
        }
        else
        {
            mostrarpares(x, a + 1);
        }
    }
}

void method_11()
{
    int x = 0;
    printf("\nDigite a quantidade de numeros pares: ");
    scanf("%d", &x);
    getchar( );
    while(x <= 0)
    {
        printf("Tem que ser uma quantidade maior que zero. Tente novamente: ");
        scanf("%d", &x);
        getchar( );
    }
    if (x > 0)
    {
        printf("Quantidade de pares depois do 7: \n");
        mostrarpares(x, 7);
        printf("\n");
    }
}

int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0611 - Programa = v0.0" );
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
