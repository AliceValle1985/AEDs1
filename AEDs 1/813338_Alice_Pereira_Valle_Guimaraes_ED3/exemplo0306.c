/*
Exemplo0301 - v0.0. - 04 / 09/ / 2023
Author: Alice Pereira Valle Guimaraes
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
Method00 - nao faz nada.
*/
void method00 ( )
{

} 
void method01 ( )
{

    int x = 0;
    IO_id ( "EXEMPLO0301 - Method01 - v0.0" );
    x = IO_readint ( "Entrar com uma quantidade: " );
    while ( x > 0 )
    {
        IO_println ( IO_toString_d ( x ) );
        x = x - 1;
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}

void method02(void)
{
    int x = 0;
    int y =0;
    IO_id ( "Method_02 - v0.0" );
    x = IO_readint ( "Entrar com uma quantidade: " );
    y = x; 
     while ( y > 0 )
     {
     IO_println ( IO_toString_d ( x ) );
     y = y - 1;
     } 
}
void method_03 ( void )
{
     int x = 0;
     int y = 0;
     IO_id ( "Method_03 - v0.0" );
     x = IO_readint ( "Entrar com uma quantidade: " );
     y = 1; 
     while ( y <= x )
     {
     IO_printf ( "%d\n", y );
     y = y + 1;
     }
    IO_pause ( "Apertar ENTER para continuar" );
} 

void method_04 ( void )
{
    //vai pedir quantos valores o usuario deseja armazenar, e depois vai armazenar assim:
    // 1 .  z
    // 2 . z2    (e por assim vai) 
     int x = 0;
     int y = 0;
     int z = 0;
     IO_id ( "Method_04 - v0.0" );
     x = IO_readint ( "Entrar com uma quantidade: " );
     for ( y = 1; y <= x; y = y + 1 )
     {
         z = IO_readint ( "Valor = " );
         IO_printf ( "%d. %d\n", y, z );
     } 
}
    

void method_05 ( void )
{
    //vai fazer  a mesma coisa do metodo 4, só que irá comecar pelo numero dado, ou seja, se o usuario dar o valor de 10, ira mostrar de 10 a 1, nao de 1 a dez como era no outro metodo
     int x = 0;
     int y = 0;
     int z = 0;
     IO_id ( "Method_05 - v0.0" );
     x = IO_readint ( "Entrar com uma quantidade: " );
     for ( y = x; y >= 1; y = y - 1 )
     {
     z = IO_readint ( "Valor = " );
     IO_printf ( "%d. %d\n", y, z );
     }
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_06 ( void )
{
    /*Vai mostrar a as letras da palavra ao contrario, exemplo:
    4: [e]
    3: [c]
    2: [i]
    1: [l]
    0: [a]
    */
     int x = 0;
     int y = 0;
     chars palavra = IO_new_chars ( STR_SIZE );
     int tamanho = 0;
     IO_id ( "Method_06 - v0.0" );
     palavra = IO_readstring ( "Entrar com uma palavra: " );
     tamanho = strlen ( palavra ) - 1;
     for ( y = tamanho; y >= 0; y = y - 1 )
     {
         IO_printf ( "%d: [%c]\n", y, palavra [y] );
     }
}
    
int main ( )
{
    int x = 0;
    do
    {
        IO_id ( "EXEMPLO0301 - Programa - v0.0" );
        IO_println ( "Opcoes" );
        IO_println ( "0 - parar" );
        IO_println ( "1 - repeticao com teste no inicio" );
        IO_println ( "2 - Metodo 2" );
        IO_println ( "3 - Metodo 3" );
        IO_println ( "4 - Metodo 4" );
        IO_println ( "4 - Metodo 4" );
        IO_println ( "5 - Metodo 5" );
        IO_println ( "6 - Metodo 6" );
        IO_println ( "" );
        x = IO_readint ( "Entrar com uma opcao: " );
        switch ( x )
        {
            case 0:
                method00 ( );
                break;
            case 1:
                method01 ( );
                break;
            case 2:
                method02 ( );
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
            case 6:
                method_06 ( );
                break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
                IO_concat ( IO_toString_d ( x ), ")" ) ) );
        } 
    }
    while ( x != 0 );
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} 
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/