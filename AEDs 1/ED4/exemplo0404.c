/*Nome: Alice Pereira Valle Guimaraes / 813338
Dia: 12/09/2023
*/
#include "io.h"
//Verifica se e um numero divisivel por dois
bool even ( int x )
{
    bool result = false;
    //se o resto de x for = a 0, entao o numero e divisivel por 2
    if ( x % 2 == 0 )
    {
        //muda o valor para verdadeiro
        result = true;
    } 
    return ( result );
} 
//confere se é um numero positivo
bool positive ( int x )
{
    bool result = false;
    //se x for maior que 0, ou seja, se for um numero positivo, mudar para um valor positivo
    if ( x > 0 )
    {
        //mudando para positivo
        result = true;
    } 
    //retorna o valor positivo ou negativo de result
    return ( result );
}
//verifica se o numero pertence ao intervalo aberto
bool belongsTo ( int x, int inferior, int superior )
{
    bool result = false;
    //testa se o numero e maior que inferior e menor que superior
    if ( inferior < x && x < superior )
    {
        //muda o resultado para verdadeiro
        result = true;
    }
    //retorna o valor
    return ( result );
}

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




// pede valores e imprique quantos positivos tem
void method_02 ( )
{
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    IO_id ( "Method02 - v0.0" );
    quantidade = IO_readint ( "Entrar com uma quantidade: " );
    controle = 1;
    while ( controle <= quantidade )
    {
        valor = IO_readint ( IO_concat (IO_concat ( "", IO_toString_d ( controle ) ),": " ) );
        //chama a função positive e confere se o valor e positivo ou negativo
        if ( positive ( valor ) )
        {
            //adiciona mais um ao contador de numeros positivos
            contador = contador + 1;
        } 
        //adiciona mais um ao controle para refazer o while e printar um numero a mais
        controle = controle + 1;
    } 
    IO_printf ( "%s%d\n", "Positivos = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}


void method_03 ( )
{
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    IO_id ( "Method_03 - v0.0" );
    quantidade = IO_readint ( "Entrar com uma quantidade: " );
    controle = 1;
    while ( controle <= quantidade )
    {
        //recebe um valor
        valor = IO_readint ( IO_concat (IO_concat ( "", IO_toString_d ( controle ) ),": " ) );
        //chama a funcao belongsto que testa se um certo valor esta entre um valor inferior e superior, que no caso e 0 e 100
        if ( belongsTo ( valor, 0, 100 ) )
        {
            //adiciona um a mais na contagem
            contador = contador + 1;
        }
        controle = controle + 1;
    } 
    IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_04 ( )
{
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    IO_id ( "Method_04 - v0.0" );
    quantidade = IO_readint ( "Entrar com uma quantidade: " );
    controle = 1;
    while ( controle <= quantidade )
    {
        //recebe o valor para a variavel 'valor'
        valor = IO_readint ( IO_concat (IO_concat ( "", IO_toString_d ( controle ) ),": " ) );
        //chama a funcao 'belongsto' e a funcao 'even' e confere se ambas sao verdadeiras
        if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
        {
            //adiciona 1 a contagem
            contador = contador + 1;
        } 
        controle = controle + 1;
    } 
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
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
        printf ( "\n%s" , "2 - Method_02" );
        printf ( "\n%s" , "3 - Method_03" );
        printf ( "\n%s" , "4 - Method_04" );
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
            case 2: 
                method_02 ( ); 
                break;
            case 3: 
                method_03 ( ); 
                break;
            case 4: 
                method_04 ( ); 
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