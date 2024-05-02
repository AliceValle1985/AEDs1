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
void transposeIntMatrix ( int rows, int columns, int matrix2[ ][rows] , int matrix1[ ][columns] )
{
    int x = 0;
    int y = 0;
    for ( x = 0; x<rows; x=x+1 )
    {
        for ( y = 0; y<columns; y=y+1 )
        {
            matrix2[ y ][ x ] = matrix1 [ x ][ y ];
        }
    }
}
void method06 ( )
{
    int matrix1 [ ][2] = { {1, 0} ,
    {0, 1} };
    int matrix2 [ ][2] = { {0, 0} ,
    {0, 0} };
    int matrix3 [ ][3] = { {1, 2, 3} ,
    {4, 5, 6} };
    int matrix4 [ ][3] = { {1, 2, 3} ,
    {4, 5, 6} ,
    {7, 8, 9} };
    IO_id ( "Method_06 - v0.0" );
    IO_println ( "\nMatrix1 " );
    printIntMatrix( 2, 2, matrix1 );
    transposeIntMatrix ( 2, 2, matrix2, matrix1 );
    IO_println ( "\nMatrix2" );
    printIntMatrix( 2, 2, matrix2 );
    IO_println ( "\nMatrix3" );
    printIntMatrix( 2, 3, matrix3 );
    transposeIntMatrix ( 2, 3, matrix4, matrix3 );
    IO_println ( "\nMatrix4" );
    printIntMatrix( 3, 2, matrix4 );
    IO_pause ( "Apertar ENTER para continuar" );
} 
bool isIdentity ( int rows, int columns, int matrix[ ][columns] )
{
     bool result = false;
     int x = 0;
     int y = 0;
     if ( rows <= 0 || columns <= 0 || rows != columns )
     {
         IO_printf ( "\nERRO: Valor invalido.\n" );
     }
     else
     {
         x = 0;
         result = true;
         while ( x<rows && result )
         {
             y = 0;
             while ( y<columns && result )
             {
                 if ( x == y )
                 {
                     result = result && ( matrix [ x ][ y ] == 1 );
                 }
                 else
                 {
                     result = result && ( matrix [ x ][ y ] == 0 );
                 } 
                 y = y + 1;
             } 
             x = x + 1;
         } 
     } 
     return ( result );
} 
void method07 ( )
{
     int matrix1 [ ][2] = { {0, 0} ,
     {0, 0} };
     int matrix2 [ ][3] = { {1, 2, 3} ,
     {4, 5, 6} };
     int matrix3 [ ][2] = { {1, 0} ,
     {0, 1} };

     IO_id ( "Method_07 - v0.0" );

     IO_println ( "\nMatrix1" );
     printIntMatrix( 2, 2, matrix1 );
     IO_printf ( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) );
     IO_println ( "\nMatrix2" );
     printIntMatrix( 2, 3, matrix2 );
     IO_printf ( "isIdentity (matrix2) = %d", isIdentity (2, 3, matrix2) );
     IO_println ( "\nMatrix3" );
     printIntMatrix( 2, 2, matrix3 );
     IO_printf ( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) );
     IO_pause ( "Apertar ENTER para continuar" );
}
bool isEqual ( int rows, int columns, int matrix1[ ][columns], int matrix2[ ][columns] )
{
     bool result = true;
     int x = 0;
     int y = 0;
     x = 0;
     while ( x<rows && result )
     {
         y = 0;
         while ( y<columns && result )
         {
             result = result && 
             ( matrix1 [ x ][ y ] == matrix2 [ x ][ y ] );
             y = y + 1;
         } 
         x = x + 1;
     } 
     return ( result );
} 
void method08 ( )
{
     int matrix1 [ ][2] = { {0, 0} ,
     {0, 0} };
     int matrix2 [ ][2] = { {1, 2} ,
     {3, 4} };
     int matrix3 [ ][2] = { {1, 0} ,
     {0, 1} };
     IO_id ( "Method_08 - v0.0" );
     IO_println ( "\nMatrix1" );
     printIntMatrix( 2, 2, matrix1 );
     IO_println ( "\nMatrix2" );
     printIntMatrix( 2, 2, matrix2 );
     IO_printf ( "isEqual (matrix1, matrix2) = %d",
     isEqual (2, 2, matrix1, matrix2) );
     copyIntMatrix ( 2, 2, matrix1, matrix3 );
     copyIntMatrix ( 2, 2, matrix2, matrix3 );
     IO_println ( "\nMatrix1" );
     printIntMatrix( 2, 2, matrix1 );
     IO_println ( "\nMatrix3" );
     printIntMatrix( 2, 2, matrix2 );
     IO_printf ( "isEqual (matrix1, matrix2) = %d",
     isEqual (2, 2, matrix1, matrix2) );
     IO_pause ( "Apertar ENTER para continuar" );
}
void addIntMatrix ( int rows, int columns, int matrix3[ ][columns], int matrix1[ ][columns], int k, int matrix2[ ][columns] )
{
 int x = 0;
 int y = 0;
 for ( x=0; x<rows; x=x+1 )
 {
     for ( y = 0; y < columns; y = y + 1 )
     {
         matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ];
     }
 } 
} 
void method09 ( )
{
     int matrix1 [ ][2] = { {1, 2},
     {3, 4} };
     int matrix2 [ ][2] = { {1, 0},
     {0, 1} };
     int matrix3 [ ][2] = { {0, 0},
     {0, 0} };
     IO_id ( "Method_09 - v0.0" );
     IO_println ( "\nMatrix1" );
     printIntMatrix( 2, 2, matrix1 );
     IO_println ( "\nMatrix2" );
     printIntMatrix( 2, 2, matrix2 );
     addIntMatrix ( 2, 2, matrix3, matrix1, (-2), matrix2 );
     IO_println ( "\nMatrix3" );
     printIntMatrix( 2, 2, matrix3 );
     IO_pause ( "Apertar ENTER para continuar" );
} 
void mulIntMatrix ( int rows3, int columns3, int matrix3[ ][columns3], int rows1, int columns1, int matrix1[ ][columns1],  int rows2, int columns2, int matrix2[ ][columns2] )
{
     int x = 0;
     int y = 0;
     int z = 0;
     int soma = 0;
     if ( rows1 <= 0 || columns1 <= 0 ||rows2 <= 0 || columns2 <= 0 ||rows3 <= 0 || columns3 <= 0 ||columns1 != rows2 ||rows1 != rows3 ||columns2 != columns3 )
     {
         IO_printf ( "\nERRO: Valor invalido.\n" );
     }
     else
     {
         for ( x=0; x<rows3; x=x+1 )
         {
             for ( y = 0; y < columns3; y = y + 1 )
             {
                 soma = 0;
                 for ( z = 0; z < columns1; z = z + 1 )
                 {
                     soma = soma + matrix1 [ x ][ z ] * matrix2 [ z ][ y ];
                 } 
                 matrix3 [ x ][ y ] = soma;
             }
         }
     } 
} 

void method10 ( )
{
     IO_id ( "Method_10 - v0.0" );
     int matrix1 [ ][2] = { {1, 2},
     {3, 4} };
     int matrix2 [ ][2] = { {1, 0},
     {0, 1} };
     int matrix3 [ ][2] = { {0, 0},
     {0, 0} };
     IO_id ( "EXEMPLO0910 - Method_09 - v0.0" );
     IO_println ( "\nMatrix1" );
     printIntMatrix( 2, 2, matrix1 );
     IO_println ( "\nMatrix2" );
     printIntMatrix( 2, 2, matrix2 );
     mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 );
     IO_println ( "\nMatrix3 = Matrix1 * Matrix2" );
     printIntMatrix( 2, 2, matrix3 );
     IO_println ( "\nMatrix2" );
     printIntMatrix( 2, 2, matrix2 );
     IO_println ( "\nMatrix1" );
     printIntMatrix( 2, 2, matrix1 );
     mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 );
     IO_println ( "\nMatrix3 = Matrix2 * Matrix1" );
     printIntMatrix( 2, 2, matrix3 );
     IO_pause ( "Apertar ENTER para continuar" );
}
void readDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
 int x = 0;
 int y = 0;
 float z = 0;
 chars text = IO_new_chars ( STR_SIZE );
if ( rows <= 0 || columns <= 0 )
 {
     IO_println ( "\nERRO: Valor invalido." );
 }
 else 
 { 
    for ( x=0; x<rows; x=x+1 )
     {
         for ( y=0; y<columns; y=y+1 )
         {
             strcpy ( text, STR_EMPTY );
             z = IO_readdouble ( IO_concat (IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ), IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
             matrix[ x ][ y ] = z;
         } 
     } 
 }
} 

void printDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
 int x = 0;
 int y = 0;
 if ( rows <= 0 || columns <= 0 )
 {
     IO_println ( "\nERRO: Valor invalido." );
 }
 else
 { 
     for ( x=0; x<rows; x=x+1 )
     {
         for ( y=0; y<columns; y=y+1 )
         {
             IO_printf ( "%3.3f\t", matrix [ x ][ y ] );
         }
         IO_printf ( "\n" );
     } 
 }
} 

void method11()
{
 int n = 2;
 double matrix [ n ][ n ];
 IO_id ( "Method_11 - v0.0" );
 readDoubleMatrix ( n, n, matrix );
 IO_printf ( "\n" );
 printDoubleMatrix ( n, n, matrix );
 IO_pause ( "Apertar ENTER para continuar" );
}

void freadDoubleMatrix ( chars fileName, int rows, int columns, double matrix[ ][ columns] )
{
 int x = 0;
 int y = 0;
 int z = 0;
 FILE* arquivo = fopen ( fileName, "wt" );
 IO_fprintf ( arquivo, "%d\n", rows );
 IO_fprintf ( arquivo, "%d\n", columns );
 chars text = IO_new_chars ( STR_SIZE );
 for ( x=0; x<rows; x=x+1 )
 {
     for ( y=0; y<columns; y=y+1 )
     {
         strcpy ( text, STR_EMPTY );
         z = IO_readint ( IO_concat (IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ), IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
         matrix [ x ][ y ] = z;
         IO_fprintf ( arquivo, "%f\n", matrix [ x ][ y ] );
     } 
 } 
 fclose ( arquivo );
} 

void printfReadMatrix(chars fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    int rows, columns;
    fscanf(file, "%d %d", &rows, &columns);

    double matrix[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    fclose(file);
}
    
    
    
    
void method12()
{ /* gravar uma matriz real em arquivo. A matriz e o nome do arquivo serão dados como parâmetros. Para testar, usar a leitura da matriz do problema anterior. Usar outro método para ler e recuperar a matriz do arquivo, antes de mostrá-la na tela. */
 IO_id ( "Method_12 - v0.0" );
 int rows = 0;
 int columns = 0;
 rows = freadMatrixRows ( "MATRIX12.TXT" );
 columns = freadMatrixColumns ( "MATRIX12.TXT" );
 IO_printf ( "\n" );
 if ( rows <= 0 || columns <= 0 )
 {
     IO_println ( "\nERRO: Valor invalido." );
 }
 else
 {
     double matrix [ rows ][ columns ];
     freadDoubleMatrix("MATRIX12.TXT", rows, columns, matrix);
     printfReadMatrix("MATRIX12.TXT");
 } 
 IO_pause ( "Apertar ENTER para continuar" );
} 
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0912 - Programa = v0.0" );
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
        printf ( "\n%s" , "6 - Method_06" );
        printf ( "\n%s" , "7 - Method_07" );
        printf ( "\n%s" , "8 - Method_08" );
        printf ( "\n%s" , "9 - Method_09" );
        printf ( "\n%s" , "10 - Method_10" );
        printf ( "\n%s" , "11 - Method_11" );
        printf ( "\n%s" , "12 - Method_12" );
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
            case 6: 
                method06 ( ); 
                break;
            case 7: 
                method07 ( ); 
                break;
            case 8: 
                method08 ( ); 
                break;
            case 9: 
                method09 ( ); 
                break;
            case 10: 
                method10 ( ); 
                break;
            case 11: 
                method11 ( ); 
                break;
            case 12: 
                method12 ( ); 
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