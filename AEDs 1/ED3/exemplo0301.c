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
int main ( )
{
    int x = 0;
    do
    {
        IO_id ( "EXEMPLO0301 - Programa - v0.0" );
        IO_println ( "Opcoes" );
        IO_println ( "0 - parar" );
        IO_println ( "1 - repeticao com teste no inicio" );
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