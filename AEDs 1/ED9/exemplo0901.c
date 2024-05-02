//Alice Pereira Valle Guimaraes - 813338 - 19/10/2023
#include <stdio.h>
#include "io.h"
void printmatrix(int linhas, int colunas, int matrix[][colunas])
{
    for(int l = 0; l < linhas; l++)
    {
        for(int c = 0; c < colunas; c++)
        {
            IO_printf("%3d\t", matrix[l][c]);
        }
        printf("\n");
    }
}
void method01()
{
    int matrix[][3] =   {
                            {1,2,3},
                            {4,5,6},
                            {7,8,9}
                        };
    IO_id("Method01 - v0.0");
    printmatrix(3, 3, matrix);
}
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0901 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
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