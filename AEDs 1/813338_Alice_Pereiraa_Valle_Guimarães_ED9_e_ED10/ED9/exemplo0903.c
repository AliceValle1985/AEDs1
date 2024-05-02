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
void fprintmatrix(chars filename, int linhas, int colunas, int matrix[][colunas])
{
    FILE *arquivo = fopen(filename, "w");
    IO_fprintf(arquivo, "%d\n", linhas);
    IO_fprintf(arquivo, "%d\n", colunas);
    for(int l = 0; l < linhas; l++)
    {
        for(int c = 0; c < colunas; c++)
        {
            IO_fprintf(arquivo, "%d\n", matrix[l][c]);
        }
    }
    fclose(arquivo);
}
void method03()
{
    int l = 0;
    int c = 0;
    l = IO_readint("\nLinhas = " );
    c = IO_readint("\nColunas = ");
    if(l <= 0 || c <= 0)
    {
        printf("Valor invalido, nao pode ser menor ou igual a zero.");
    }
    else
    {
        int matrix[l][c];
        readmatrix(l, c, matrix);
        printf("\n");
        printmatrix(l, c, matrix);
        fprintmatrix("matrix.txt", l, c, matrix);
    }
    IO_pause("Aperte ENTER para continuar.");
}
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0903 - Programa = v0.0" );
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