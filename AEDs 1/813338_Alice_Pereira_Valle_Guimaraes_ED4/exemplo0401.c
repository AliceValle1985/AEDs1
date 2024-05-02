/*Nome: Alice Pereira Valle Guimaraes / 813338
Dia: 12/09/2023
*/
#include "io.h"
void method_01 ( )
{
     int quantidade = 0;
     int valor = 0;
     int controle = 0;
     IO_id ( "Method 01 - v0.0" );
     quantidade = IO_readint ( "Entrar com uma quantidade: " );
     controle = 1;
     //enquanto o valor do 'controle' for menor ou igual a 'quantidade', pedir o valor para a variavel 'valor' e mostrar o valor do 'controle' e adicionar um a mais pra repetir o processo
     while ( controle <= quantidade )
     {   
         //Recebe o valor 
         valor = IO_readint ( IO_concat ( IO_concat ( "", IO_toString_d ( controle ) ), ": " ) );
         //adiciona um a mais no controle
         controle = controle + 1;
     } 
     IO_pause ( "Apertar ENTER para continuar" );
} 
int main (void)
{
    int opcao = 0;
    printf ( "%s\n", "Exemplo0400 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n" );
        printf ( "\n%s", "Opcao = " );
        scanf ( "%d", &opcao );
        getchar( );
        printf ( "\n%s%d", "Opcao = ", opcao );
        switch ( opcao )
        {
            case 0:
                break;
            case 1: 
                method_01 ( ); 
                break;
            default: 
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( opcao != 0 );
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 12/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/