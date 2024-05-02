#include "io.h"
#include <stdio.h>

void printIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{
 int x = 0;
 int y = 0;
 for ( x=0; x<rows; x=x+1 )
 {
     for ( y=0; y<columns; y=y+1 )
     {
         IO_printf ( "%3d\t", matrix [ x ][ y ] );
     }
     IO_printf ( "\n" );
 } 
} 

void method01 ( )
{
 int matrix [ ][3] = { 
 {1, 2, 3},
 {4, 5, 6},
 {7, 8, 9}
 };
 IO_id ( "Method_01 - v0.0" );
 printIntMatrix ( 3, 3, matrix );
 IO_pause ( "Apertar ENTER para continuar" );
}

void readIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{
 int x = 0;
 int y = 0;
 int z = 0;
 chars text = IO_new_chars ( STR_SIZE );
 for ( x=0; x<rows; x=x+1 )
 {
     for ( y=0; y<columns; y=y+1 )
     {
         strcpy ( text, STR_EMPTY );
         z = IO_readint ( IO_concat (IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ), IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
         matrix [ x ][ y ] = z;
     } 
 } 
} 

void method02 ( )
{
 int n = 2;
 int matrix [ n ][ n ];
 IO_id ( "Method_02 - v0.0" );
 readIntMatrix ( n, n, matrix );
 IO_printf ( "\n" );
 printIntMatrix ( n, n, matrix );
 IO_pause ( "Apertar ENTER para continuar" );
}

void fprintIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] )
{
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;
 int y = 0;
 IO_fprintf ( arquivo, "%d\n", rows );
 IO_fprintf ( arquivo, "%d\n", columns );
 for ( x=0; x<rows; x=x+1 )
 {
     for ( y=0; y<columns; y=y+1 )
     {
         IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] );
     } 
 } 
 fclose ( arquivo );
} 

void method03 ( )
{
 int rows = 0;
 int columns = 0;
 IO_id ( "Method_03 - v0.0" );
 rows = IO_readint ( "\nrows = " );
 columns = IO_readint ( "\ncolumns = " );
 IO_printf ( "\n" );
 if ( rows <= 0 || columns <= 0 )
 {
     IO_println ( "\nERRO: Valor invalido." );
 }
 else
 {
     int matrix [ rows ][ columns ];
     readIntMatrix ( rows, columns, matrix );
     IO_printf ( "\n" );
     printIntMatrix ( rows, columns, matrix );
     IO_printf ( "\n" );
     fprintIntMatrix( "MATRIX1.TXT", rows, columns, matrix );
 } 
 IO_pause ( "Apertar ENTER para continuar" );
} 
int freadMatrixRows ( chars fileName )
{
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 ints array = NULL;
 IO_fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
     IO_println ( "ERRO: Valor invalido." );
     n = 0;
 }
    return ( n );
} 

int freadMatrixColumns ( chars fileName )
{
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 IO_fscanf ( arquivo, "%d", &n );
 IO_fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
     IO_println ( "ERRO: Valor invalido." );
     n = 0;
 } 
 return ( n );
} 

void freadIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] )
{
 int x = 0;
 int y = 0;
 int z = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 IO_fscanf ( arquivo, "%d", &x );
 IO_fscanf ( arquivo, "%d", &y );
 if ( rows <= 0 || rows > x || columns <= 0 || columns > y )
 {
     IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
     x = 0;
     while ( ! feof ( arquivo ) && x < rows )
     {
     y = 0;
         while ( ! feof ( arquivo ) && y < columns )
         {
             IO_fscanf ( arquivo, "%d", &z );
             matrix [ x ][ y ] = z;
             y = y+1;
         } 
     x = x+1;
     } 
 } 
 fclose ( arquivo );
} 

void method04 ( )
{
 int rows = 0;
 int columns = 0;
 IO_id ( "Method_04 - v0.0" );
 rows = freadMatrixRows ( "MATRIX1.TXT" );
 columns = freadMatrixColumns ( "MATRIX1.TXT" );
 
 if ( rows <= 0 || columns <= 0 )
 {
     IO_println ( "\nERRO: Valor invalido." );
 }
 else
 {
     int matrix [ rows ][ columns ];
     freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix );
     IO_printf ( "\n" );
     printIntMatrix ( rows, columns, matrix );
 }
 IO_pause ( "Apertar ENTER para continuar" );
} 

void copyIntMatrix ( int rows, int columns,
 int matrix2[ ][columns], int matrix1[ ][columns] )
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

void method05 ( )
{
 int rows = 0;
 int columns = 0;
 IO_id ( "Method_05 - v0.0" );
 rows = freadMatrixRows ( "MATRIX1.TXT" );
 columns = freadMatrixColumns ( "MATRIX1.TXT" );
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

void mulIntMatrix ( int rows3, int columns3,
 int matrix3[ ][columns3],
 int rows1, int columns1,
 int matrix1[ ][columns1], 
 int rows2, int columns2,
 int matrix2[ ][columns2] )
{
 int x = 0;
 int y = 0;
 int z = 0;
 int soma = 0;
 if ( rows1 <= 0 || columns1 <= 0 ||
 rows2 <= 0 || columns2 <= 0 ||
 rows3 <= 0 || columns3 <= 0 ||
 columns1 != rows2 ||
 rows1 != rows3 ||
 columns2 != columns3 )
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
 int matrix2 [ ][2] = { {1, 2},
 {2, 1} };
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
{/*  ler as dimensões (quantidade de linhas e de colunas) de uma matriz real do teclado,  bem como todos os seus elementos (apenas valores positivos). Verificar se as dimensões não são nulas ou negativas. Para testar, ler dados e mostrá-los na tela por outro método */
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

void printDiagonalMatrix(int linhas, int colunas, double matrix [linhas] [colunas])
{
    printf("\nDiagonal: \n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (i == j)
            {
                printf("%3.3lf\t", matrix[i][j]);
            }
            else
            {
                printf("  \t");
            }
        }
        printf("\n");
    }

    
}

void diagonalquadrada()
{
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printDiagonalMatrix (linhas, colunas, matrix );
        getchar();
        printf("\n");
    }
}
    
void method13()
{ /* mostrar somente os valores na diagonal principal de uma matriz real, se for quadrada. */
    diagonalquadrada();
}

void printDiagonalSecMatrix (int linhas, int colunas, double matrix [linhas] [colunas] )
{
    int j = 0;
    printf("\nDiagonal secundaria: \n");
    for (int i = linhas-1; i >= 0; i--)
    {
        printf("%3.3lf\t", matrix[j][i]);
        printf("\n");
        j++;
    }
}

void method14 ( )
{/* mostrar somente os valores na diagonal secundária de uma matriz real, se for quadrada. */
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printDoubleMatrix (linhas, colunas, matrix );
        printDiagonalSecMatrix (linhas, colunas, matrix );
        getchar();
        printf("\n");
    }
} 

void printTrianguloMatrix (int linhas, int colunas, double matrix[linhas][colunas] )
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if(i >= j)
            {
                printf("%3.3lf\t", matrix[i][j]);
            }
            else
            {
                printf("    \t");
            }
        }
        printf("\n");
    }
}

void method15()
{ /* mostrar somente os valores abaixo e na diagonal principal de uma matriz real, se for quadrada. */
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printTrianguloMatrix (linhas, colunas, matrix );
        getchar();
        printf("\n");
    }
} 

void printTrianguloInversoMatrix (int linhas, int colunas, double matrix[linhas][colunas] )
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if(i <= j)
            {
                printf("%3.3lf\t", matrix[i][j]);
            }
            else
            {
                printf("    \t");
            }
        }
        printf("\n");
    }
}

void method16()
{ /* mostrar somente os valores acima e na diagonal principal de uma matriz real, se for quadrada. */
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printTrianguloInversoMatrix (linhas, colunas, matrix );
        getchar();
        printf("\n");
    }
}


void printTrianguloSecMatrix (int linhas, int colunas, double matrix [linhas] [colunas] )
{
    printf("\nTriangulo Secundario: \n");
  
    for (int i = colunas-1; i >= 0; i--)
    {
        for(int j = 0; j < linhas; j++)
        {
            if (j >= i)
            {
                printf("%3.3lf\t", matrix[j][i]);
            }
            else
            {
                printf("    \t");
            }
        }
        printf("\n");
    }
}

void method17()
{ /* mostrar somente os valores abaixo e na diagonal secundária de uma matriz real, se for quadrada. */
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printDoubleMatrix ( linhas, colunas, matrix );
        printTrianguloSecMatrix (linhas, colunas, matrix );
        getchar();
        printf("\n");
    }
}

void printTrianguloSecInversoMatrix (int linhas, int colunas, double matrix [linhas] [colunas] )
{
    printf("\nTriangulo Secundario: \n");
  
    for (int i = colunas-1; i >= 0; i--)
    {
        for(int j = 0; j < linhas; j++)
        {
            if (i >= j)
            {
                printf("%3.3lf\t", matrix[j][i]);
            }
            else
            {
                printf("    \t");
            }
        }
        printf("\n");
    }
}

void method18()
{ /* mostrar somente os valores acima e na diagonal secundária de uma matriz real, se for quadrada. */
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printDoubleMatrix ( linhas, colunas, matrix );
        printTrianguloSecInversoMatrix (linhas, colunas, matrix );
        getchar();
        printf("\n");
    }
}

bool Is0TrianguloMatrix (int linhas, int colunas, double matrix[linhas][colunas])
{
    bool result = 1;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if(i >= j)
            {
                printf("%3.3lf\t", matrix[i][j]);
            }
            if(i > j)
            {
                if(matrix[i][j] != 0)
                {
                    result = 0;
                }
            }
        }
        printf("\n");
    }
    return result;
}

void method19()
{ /* testar se não são todos zeros os valores abaixo da diagonal principal de uma matriz real quadrada. */
    int linhas, colunas = 0;
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);
    if(linhas != colunas)
    {
        printf("Matriz não é quadrada.");
    }
    else
    {
        double matrix[linhas][colunas];
        readDoubleMatrix ( linhas, colunas, matrix );
        printDoubleMatrix ( linhas, colunas, matrix );
        bool result = Is0TrianguloMatrix(linhas, colunas, matrix);      
        getchar();
        if(result)
        {
            printf("São todos numeros 0");
        }
        else
        {
            printf("Tem mais numeros alem de 0 abaixo da diagonal");
        }
        getchar();
        printf("\n");
    }    
}

void method20()
{ 
}
int main()
{
    int x = 0; 
    
    do
    {
        IO_clrscr();
        IO_id("Exemplo0900 - v0.0");
        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - method_01" );
        IO_println ( " 2 - method_02" );
        IO_println ( " 3 - method_03" );
        IO_println ( " 4 - method_04" );
        IO_println ( " 5 - method_05" );
        IO_println ( " 6 - method_06" );
        IO_println ( " 7 - method_07" );
        IO_println ( " 8 - method_08" );
        IO_println ( " 9 - method_09" );
        IO_println ( "10 - method_10" );
        IO_println ( "11 - method_11");
        IO_println ( "12 - method_12");
        IO_println ( "13 - method_13");
        IO_println ( "14 - method_14");
        IO_println ( "15 - method_15");
        IO_println ( "16 - method_16");
        IO_println ( "17 - method_17");
        IO_println ( "18 - method_18");
        IO_println ( "19 - method_19");
        IO_println ( "20 - method_20");

        IO_println ( "" );

        x = IO_readint ( "Entrar com uma opcao: " );
        
        switch (x)
        {
            case 0:
                break;
            case 1:
                method01 ();
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
            case 13:
                method13 ( );
                break;
            case 14:
                method14 ( );
                break;
            case 15:
                method15 ( );
                break;
            case 16:
                method16 ( );
                break;
            case 17:
                method17 ( );
                break;
            case 18:
                method18 ( );
                break;
            case 19:
                method19 ( );
                break;
            case 20:
                method20 ( );
                break;
            default:
                IO_pause ( "ERRO: Valor invalido." );
        }
    } while (x!= 0);
 
    IO_pause("Aperte ENTER para terminar");
    return 0;
}
