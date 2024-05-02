//Alice Pereira Valle Guimaraes - 813338 - 19/10/2023
#include <stdio.h>
#include "io.h"
void printmatrix(int linhas, int colunas, int matrix[][colunas])
{
    //passa pelas linhas
    for(int l = 0; l < linhas; l++)
    {
        //passa pela as colunas
        for(int c = 0; c < colunas; c++)
        {
            //exibe a matrix
            IO_printf("%3d\t", matrix[l][c]);
        }
        //pular para proxima linha
        printf("\n");
    }
}
void method01()
{
    //dar o valor para a matrix
    int matrix[][3] =   {
                            {1,2,3},
                            {4,5,6},
                            {7,8,9}
                        };
    IO_id("Method01 - v0.0");
    //chamar a funcao para exibir na tela
    printmatrix(3, 3, matrix);
    IO_pause("Aperte ENTER para continuar.");
}
void readmatrix(int rows, int columns, int matrix[][columns])
{
	int z = 0;
	chars text = IO_new_chars(STR_SIZE);
	for(int l = 0; l < rows; l++)
	{
		for(int c = 0; c < columns; c++)
		{
			strcpy(text, STR_EMPTY);
			z = IO_readint ( IO_concat (IO_concat ( IO_concat ( text, IO_toString_d ( l ) ), ", " ),IO_concat ( IO_concat ( text, IO_toString_d ( c ) ), " : " ) ) );
			matrix[l][c] = z;
		}		
	}	
}
void method02( )
{
    int n = 2;
    int matrix[n][n];
    IO_id("Method_02 - v0.0");
    readmatrix(n, n, matrix);
    printf("\n");
    printmatrix(n, n, matrix);
    IO_pause("Aperte ENTER para continuar.");
}
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0902 - Programa = v0.0" );
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
                method01 ( ); 
                break;
            case 2: 
                method02 ( ); 
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