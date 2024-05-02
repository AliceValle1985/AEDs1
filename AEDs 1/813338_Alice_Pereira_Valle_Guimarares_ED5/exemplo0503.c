/*Alice Pereira Valle Guimaraes - 813338 - 18/09/2023*/
#include "io.h"
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
    method_01a (5);
    IO_pause ("Apertar ENTER para continuar");
}
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
    method_02a(5);
    IO_pause ("Apertar ENTER para continuar");
    
}
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
int main(void)
{
    int opcao = 0;
    printf ( "%s\n", "Exemplo0503 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n%s" , "2 - Method_02" );
        printf ( "\n%s" , "3 - Method_03" );
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