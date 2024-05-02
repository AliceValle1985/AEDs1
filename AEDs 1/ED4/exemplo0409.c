/*Nome: Alice Pereira Valle Guimaraes / 813338
Dia: 12/09/2023
*/
#include "io.h"
//Verifica se tem algum numero
bool isDigit ( char x )
{
    bool result = false;
    //verifica se o caractere esta entre 0 e 9
    if ( '0' <= x && x <= '9' )
    {
        //e muda o resultado para verdadeiro
        result = true;
    } 
    //retorna um valor verdadeiro
    return ( result );
}
//verifica se o caractere e uma letra minuscula
bool isLowerCase ( char x )
{
    bool result = false;
    //se o valor de um caractere for maior que a e menor que z (se estiver entre a e z) o resultado passara para um valor verdariro
    if ( 'a' <= x && x <= 'z' )
    {
        result = true;
    } 
    return ( result );
}
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


void method_05 ( )
{
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    bool ok = false;
    IO_id ( "EXEMPLO0405 - Method05 - v0.0" );
    quantidade = IO_readint ( "Entrar com uma quantidade: " );
    controle = 1;
    while ( controle <= quantidade )
    {
        valor = IO_readint ( IO_concat (IO_concat ( "", IO_toString_d ( controle ) ),": " ) );
        //pega o resultado de belongsto (verdadeiro ou falso) e armazena na variavel 'ok'
        ok = belongsTo ( valor, 0, 100 );
        //verifica se o 'ok' esta como true e chama a função even
        ok = ok && even ( valor );
        //se 'ok' for true, adicionar 1 a mais no contador
        if ( ok )
        {
            contador = contador + 1;
        } 
        controle = controle + 1;
    }
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}
//retorna a quantidade de letras minusculas
void method_06 ( )
{
    //STR_SIZE da a quantidade de caracteres q foram armazenados nesse vetor
    chars palavra = IO_new_chars ( STR_SIZE );
    int tamanho = 0;
    char simbolo = '_';
    int contador = 0;
    IO_id ( "Method06 - v0.0" );
    palavra = IO_readstring ( "Entrar com uma palavra: " );
    //armazenou a quantidade de caracteres na variavel tamanho
    tamanho = strlen ( palavra );
    //percorre pela variavel palavra
    for (int i = 0; i < tamanho; i = i + 1 )
    {
        //e armazena cada caractere na variavel simbolo
        simbolo = palavra [ i ];
        //se for uma letra minuscula, adicina um ao contador
        if ( isLowerCase ( simbolo ) )
        {
            contador = contador + 1;
        } 
    } 
    //mostrar quantas minusculas
    IO_printf ( "%s%d\n", "Minusculas = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}
//contar as letras minusculas e mostrar elas
void method_07 ( )
{
    chars palavra = IO_new_chars ( STR_SIZE );
    int tamanho = 0;
    char simbolo = '_';
    int contador = 0;
    IO_id ( "Method07 - v0.0" );
    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen ( palavra );
    //percorrer pela string
    for ( int i = 0; i < tamanho; i = i + 1 )
    {
        //armazenar a string na variavel simbolo
        simbolo = palavra [ i ];
        //chama a funcao que verifica se a letra e minuscula
        if ( isLowerCase ( simbolo ) )
        {
            //mostrae a letra minuscula
            IO_printf ( "%c ", simbolo );
            //adicionar 1 ao contador
            contador = contador + 1;
        } 
    } 
    //mostrar a quantidade de minusculas
    IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_08 ( )
{
    chars palavra = IO_new_chars ( STR_SIZE );
    int tamanho = 0;
    char simbolo = '_';
    int contador = 0;
    chars minusculas = IO_new_chars ( STR_SIZE );
    strcpy ( minusculas, STR_EMPTY );
    IO_id ( "Method08 - v0.0" );
    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen ( palavra );
    //percorrer pela string
    for ( int i = 0; i < tamanho; i = i + 1 )
    {
        //armazenar a palavra no simbolo
        simbolo = palavra [ i ];
        //conferir se e uma minuscula
        if ( isLowerCase ( simbolo ) )
        {
            //pegando o valor em simbolo, convertendo-o em uma string e anexando essa string à variável minusculas 
            minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) );
            //adicionando ao contador
            contador = contador + 1;
        } 
    }
    //exibindo a contagem e as minusculas
    IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas );
    IO_pause ( "Apertar ENTER para continuar" );
}
//conta e exibe na tela os numeros colocados em uma string
void method_09 ( )
{
    chars palavra = IO_new_chars ( STR_SIZE );
    int tamanho = 0;
    char simbolo = '_';
    int contador = 0;
    IO_id ( "Method09 - v0.0" );
    palavra = IO_readstring ( "Entrar com caracteres: " );
    //transforma a quantidade de caracteres da string 'palavra' em numeros inteiros e armazena em tamanho
    tamanho = strlen ( palavra );
    //percorre a 'string' palavra q foi armazenana em 'simbolo'
    for ( int i = 0; i < tamanho; i = i + 1 )
    {
        //armazena 'palavra' em 'simbolo'
        simbolo = palavra [ i ];
        //testa se tem algum numero
        if ( isDigit ( simbolo ) )
        {
            //exibe na tela qual numero, um por um
            IO_printf ( "%c ", simbolo );
            //adiciona 1 ao contador
            contador = contador + 1;
        } 
    } 
    //exibe a quantidade de numeros
    IO_printf ( "\n%s%d\n", "Algarismos = ", contador );
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
        printf ( "\n%s" , "5 - Method_05" );
        printf ( "\n%s" , "6 - Method_06" );
        printf ( "\n%s" , "7 - Method_07" );
        printf ( "\n%s" , "8 - Method_08" );
        printf ( "\n%s" , "9 - Method_09" );
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
            case 5: 
                method_05 ( ); 
                break;
            case 6: 
                method_06 ( ); 
                break;
            case 7: 
                method_07 ( ); 
                break;
            case 8: 
                method_08 ( ); 
                break;
            case 9: 
                method_09 ( ); 
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