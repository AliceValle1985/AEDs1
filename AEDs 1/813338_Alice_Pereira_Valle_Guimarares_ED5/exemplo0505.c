/*Alice Pereira Valle Guimaraes - 813338 - 18/09/2023*/
#include "io.h"
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
void method_01 ()
{
    IO_id ("Method_01 - v0.0");
    //5 e o numero desinado, entao ira mostrar do numero zero ate o numero 5
    method_01a (5);
    IO_pause ("Apertar ENTER para continuar");
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
void method_02()
{
    IO_id ( "Method_02 - v0.0" );
    //da o valor de 5 para mostrar 5 vezes
    method_02a(5);
    IO_pause ("Apertar ENTER para continuar");
    
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
void method_03()
{
    IO_id("Method_03 - v0.0");
    method_03a (5);
    IO_pause("Aperte ENTER para continuar");
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
void method_04()
{
    IO_id ("Method_04 - v0.0");
    mehtod_04a(5);
    IO_pause("Apertar ENTER para continuar");
           
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
void method_05()
{
    IO_id("Mwthod_05 -v0.0");
    method_05a(5);
    IO_pause("Apertar ENTER para continuar");
}
int main(void)
{
     int opcao = 0;
    printf ( "%s\n", "Exemplo0505 - Programa = v0.0" );
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
        default:
            printf ( "\nERRO: Opcao invalida.\n" );
                break;
    }
}while (opcao !=0);
     printf ( "\n\nApertar ENTER para terminar." );
    getchar( );  
    return 0;
}