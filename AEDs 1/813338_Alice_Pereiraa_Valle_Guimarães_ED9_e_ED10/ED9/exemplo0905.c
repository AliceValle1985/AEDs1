//Alice Pereira Valle Guimaraes - 813338 - 19/10/2023
#include <stdio.h>
#include "io.h"
void printIntMatrix(int linhas, int colunas, int matrix[][colunas])
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
    printIntMatrix(3, 3, matrix);
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
    printIntMatrix(n, n, matrix);
    IO_pause("Aperte ENTER para continuar.");
}
void fprintIntMatrix(chars filename, int linhas, int colunas, int matrix[][colunas])
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
        printIntMatrix(l, c, matrix);
        fprintIntMatrix("MATRIX1.TXT", l, c, matrix);
    }
    IO_pause("Aperte ENTER para continuar.");
}
//ler a linha da matriz com valores inteiros
int freadIntMatrixRows(chars filename)
{
    FILE *arquivo = fopen(filename, "r");
    int x         = 0;
    //ler o arquivo e armazenar em x
    IO_fscanf(arquivo, "%d", &x);
    if(x <= 0)
    {
        IO_println("ERRO: valor invalido.");
        x = 0;
    }
    return( x );
}
int freadIntMatrixColumns(chars filename)
{
    FILE *arquivo = fopen(filename, "r");
    int x         = 0;
    //ler do arquivo e armazenar em x
    IO_fscanf(arquivo, "%d", &x);
    IO_fscanf(arquivo, "%d", &x);
    if(x <= 0)
    {
        IO_println("ERRO: valor invalido.");
        x = 0;
    }
    return ( x );
}
void freadIntMatrix(chars filename, int linhas, int colunas, int matrix[][colunas])
{
    int x = 0;
    int y = 0;
    int z = 0;
    FILE *arquivo = fopen(filename, "r");
    //ler dados do arquivo e armazenar em x e y
    IO_fscanf ( arquivo, "%d", &x );
    IO_fscanf ( arquivo, "%d", &y );
    if(linhas <= 0 || linhas > x || colunas <= 0 || colunas > y)
    {
        IO_println("ERRO: valor invalido");
    }
    else
    {
        x = 0;
        //enquanto nao for o final do arquivo e enquanto x for menor que linhas
        while(! feof(arquivo) && x < linhas)
        {
            y = 0;
            //ebquanto nao for o final de arquivo e enquanto y fo rmenor que as colunas
            while(! feof(arquivo) && y < colunas)
            {
                //grava o valor em z
                IO_fscanf(arquivo, "%d", &z);
                //guardar valor
                matrix[x][y] = z;
                y++;
            }
            x++;
        }
    }
    fclose(arquivo);
}
void method04()
{
    int linhas  = 0;
    int colunas = 0;
    IO_id ( "Method_04 - v0.0" );
    linhas  = freadIntMatrixRows ("MATRIX1.TXT");
    colunas = freadIntMatrixColumns ( "MATRIX1.TXT" );
    if ( linhas <= 0 || colunas <= 0 )
    {
        IO_println ( "\nERRO: Valor invalido." );
    }
    else
    {
        int matrix [ linhas ][ colunas ];
        freadIntMatrix ( "MATRIX1.TXT", linhas, colunas, matrix );
        IO_printf ( "\n" );
        printIntMatrix ( linhas, colunas, matrix );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}
void copyIntMatrix ( int rows, int columns, int matrix2[ ][columns], int matrix1[ ][columns] )
{
    int x = 0;
    int y = 0;
    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                matrix2 [ x ][ y ] = matrix1 [ x ][ y ];
            } 
        } 
    } 
} 
//copia uma matrix na outra
void method05 ( )
{
     int rows = 0;
     int columns = 0;
     IO_id ( "Method_05 - v0.0" );
     rows = freadIntMatrixRows ( "MATRIX1.TXT" );
     columns = freadIntMatrixColumns ( "MATRIX1.TXT" );
     if ( rows <= 0 || columns <= 0 )
     {
         IO_println ( "\nERRO: Valor invalido." );
     }
     else
     {
         int matrix [ rows ][ columns ];
         int other [ rows ][ columns ];
         freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix );
         copyIntMatrix ( rows, columns, other, matrix );
         IO_printf ( "\nOriginal\n" );
         printIntMatrix ( rows, columns, matrix );
         IO_printf ( "\nCopia\n" );
         printIntMatrix ( rows, columns, other );
     } 
     IO_pause ( "Apertar ENTER para continuar" );
} 
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0905 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    
    do
    {
        IO_clrscr();
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n%s" , "2 - Method_02" );
        printf ( "\n%s" , "3 - Method_03" );
        printf ( "\n%s" , "4 - Method_04" );
        printf ( "\n%s" , "5 - Method_05" );
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
            case 4: 
                method04 ( ); 
                break;
            case 5: 
                method05 ( ); 
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