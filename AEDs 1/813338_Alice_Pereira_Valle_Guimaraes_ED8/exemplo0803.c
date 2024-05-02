//Alice Pereira Valle Guimaraes 13/10/2023
#include <stdio.h>
#include "io.h"
void printlnArray(int n, int array [])
{
    for(int i = 0; i < n; i++)
    {
        IO_printf("%2d: %d\n", i, array[i]);
    }
}
void method01()
{
    int array[] = {1, 2, 3, 4, 5};
    IO_id ( "Method_01 - v0.0" );
    printlnArray(5, array);
    IO_pause ( "Apertar ENTER para continuar" );
}
void readIntArray ( int n, int array [ ] )
{
 int x = 0;
 int y = 0;
 chars text = IO_new_chars ( STR_SIZE );
 for ( x=0; x<n; x=x+1 )
 {
 strcpy ( text, STR_EMPTY );
 y = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( x ) ), " : " ) );
 array [ x ] = y;
 } 
} 
void method02()
{
    int n = 5;
    int array[n];
    IO_id ( "Method_02 - v0.0" );
    readIntArray(n, array);
    printf("\n");
    readIntArray(n, array);
    IO_pause ( "Apertar ENTER para continuar" );
}
void fprintIntArray ( chars fileName, int n, int array [ ] )
{
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;
 IO_fprintf ( arquivo, "%d\n", n );
 for ( x=0; x<n; x=x+1 )
 {
 IO_fprintf ( arquivo, "%d\n", array [ x ] );
 } 
 
 fclose ( arquivo );
} 
void method03 ( )
{
 int n = 5; 
 int array [ n ];
 IO_id ( "Method_03 - v0.0" );
 readIntArray ( n, array );
 IO_printf ( "\n" );
 fprintIntArray ( "ARRAY1.TXT", n, array );
 IO_pause ( "Apertar ENTER para continuar" );
} 

int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0801 - Programa = v0.0" );
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
        scanf ( "%d", &x );
        getchar( );
        printf ( "\n%s%d", "Opcao = ", x );
        switch ( x )
        {
            case 0:
                break;
            case 1: 
                method01 ( ); 
                break;
            case 2: 
                method02 ( ); 
                break;
            case 3: 
                method03 ( ); 
                break;
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( x != 0 );
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}