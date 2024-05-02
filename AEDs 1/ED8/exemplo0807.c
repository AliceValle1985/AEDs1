//Alice Pereira Valle Guimaraes 13/10/2023
#include <stdio.h>
#include "io.h"
void printlntArray(int n, int array [])
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
    printlntArray(5, array);
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

int freadArraySize ( chars fileName )
{
    int n = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
    IO_fscanf ( arquivo, "%d", &n );
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    } 
    return ( n );
} 
void freadIntArray ( chars fileName, int n, int array [ ] )
{
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
    IO_fscanf ( arquivo, "%d", &x );
    if ( n <= 0 || n > x )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
        x = 0;
        while ( ! feof ( arquivo ) && x < n )
        { 
            IO_fscanf ( arquivo, "%d", &y );
            array [ x ] = y;
            x = x+1;
        }
    } 
} 
void method04 ( )
{
    int n = 0;
    IO_id ( "Method_04 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        IO_printf ( "\n" );
        printlntArray ( n, array );
    }
    IO_pause ( "Apertar ENTER para continuar" );
} 
void copyIntArray ( int n, int copy [ ], int array [ ] )
{
    int x = 0;
    int y = 0;
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    }
    else
    {
    for ( x = 0; x < n; x = x + 1 )
    {
        
        copy [ x ] = array [ x ];
    }
    }

} 
void method05 ( )
{
    int n = 0;
    IO_id ( "Method_05 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        int other [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        copyIntArray ( n, other, array );
        IO_printf ( "\nOriginal\n" );
        printlntArray ( n, array );
        IO_printf ( "\nCopia\n" );
        printlntArray ( n, other );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}
int sumIntArray ( int n, int array [ ] )
{
    int soma = 0;
    int x = 0;
    for ( x=0; x<n; x=x+1 )
    {
        soma = soma + array [ x ];
    } 
    return ( soma );
} 
void method06 ( )
{
    int n = 0;
    IO_id ( "Method_06 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        IO_printf ( "\nSoma = %d\n", sumIntArray ( n, array ) );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
} 
bool isAllZeros ( int n, int array [ ] )
{
    bool result = true;
    int x = 0;
    x=0; 
    while ( x<n && result )
    {
        result = result && ( array [ x ] == 0 );
        x = x + 1;
    } 
    return ( result );
} 
void method07 ( )
{
    int n = 5; 
    int array1 [ ] = { 0,0,0,0,0 };
    int array2 [ ] = { 1,2,3,4,5 };
    int array3 [ ] = { 1,2,0,4,5 };
    IO_id ( "Method_07 - v0.0" );
    IO_println ( "\nArray1" );
    printlntArray ( n, array1 );
    IO_printf ( "isAllZeros (array1) = %d", isAllZeros (n, array1) );
    IO_println ( "\nArray2" );
    printlntArray ( n, array2 );
    IO_printf ( "isAllZeros (array2) = %d", isAllZeros (n, array2) );
    IO_println ( "\nArray3" );
    printlntArray ( n, array3 );
    IO_printf ( "isAllZeros (array3) = %d", isAllZeros (n, array3) );
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
        printf ( "\n%s" , "4 - Method_04" );
        printf ( "\n%s" , "5 - Method_05" );
        printf ( "\n%s" , "6 - Method_06" );
        printf ( "\n%s" , "7 - Method_07" );

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
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( x != 0 );
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}