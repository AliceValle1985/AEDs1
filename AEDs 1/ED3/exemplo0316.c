/*
Exemplo0301 - v0.0. - 04 / 09/ / 2023
Author: Alice Pereira Valle Guimaraes
*/
// dependencias
#include "io.h" 
// para definicoes proprias
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
    
void method_07 ( void )
{
    /*faz a mesma coisa que o metodo 6, só que deixa na ordem correta, exemplo:
    0: [A]
    1: [l]
    2: [i]
    3: [c]
    4: [e]
    */
     int x = 0;
     int y = 0;
    /*str_size é usado para denominar o valor maximo de um vetor de caracteres*/
     char palavra [STR_SIZE];
     int tamanho = 0;
     IO_id ( "Method07 - v0.0" );
     IO_printf ( "Entrar com uma palavra: " );
     scanf ( "%s", palavra ); 
     getchar( );
    /*strlen é uma função que é usada para calcular o comprimento de uma string.
    A função strlen percorre a string até encontrar o caractere nulo ('\0') que marca o fim da string, contando o número de caracteres antes do caractere nulo.
    se uma string eh igual a "hello, world!"
    int tamanho = strlen(nome da string);
    o valor da variavel sera 13, pq em "hello, world!" tem 13 caracteres
    */
     tamanho = strlen ( palavra );
     for ( y = 0; y < tamanho; y = y + 1 )
     {
         IO_printf ( "%d: [%c]\n", y, palavra [y] );
     } 
     IO_pause ( "Apertar ENTER para continuar" );
}

void method_08 ( void )
{
    /*Imprime os numeros um por um na tela*/
     int inferior = 0;
     int superior = 0;
     int x = 0;
     IO_id ( "Method08 - v0.0" );
     inferior = IO_readint ( "Limite inferior do intervalo: " );
     superior = IO_readint ( "Limite superior do intervalo : " );
     for ( x = inferior; x <= superior; x = x + 1 )
     {
         IO_printf ( "%d\n", x );
     } 
     IO_pause ( "Apertar ENTER para continuar" );
}

void method_09 ( void )
{
    /*gera uma sequência de números a partir de um valor superior até um valor inferior, diminuindo o valor em incrementos dado pelo usuário (passo)
    exemplo:
    150.000000
    147.000000
    144.000000
    141.000000
    138.000000
    135.000000
    132.000000
    129.000000
    126.000000
    123.000000
    120.000000
    117.000000
    114.000000
    111.000000
    108.000000
    105.000000
    102.000000
    */
     double inferior = 0;
     double superior = 0;
     double passo = 0;
     double x = 0;
     IO_id ( "Method_09 - v0.0" );
     inferior = IO_readdouble ( "Limite inferior do intervalo : " );
     superior = IO_readdouble ( "Limite superior do intervalo : " );
     passo = IO_readdouble ( "Variacao no intervalo (passo): " );
     for ( x = superior; x >= inferior; x = x - passo )
     {
         IO_printf ( "%lf\n", x );
     } 
     IO_pause ( "Apertar ENTER para continuar" );
}

void method_10 ( void )
{
    /*faz a mesma  coisa do codigo anterior so que proibe o usuario de digitar o valor inferior menor do que o valor superior, exemplo:
    100.000000
    103.000000
    106.000000
    109.000000
    112.000000
    115.000000
    118.000000
    121.000000
    124.000000
    127.000000
    130.000000
    133.000000
    136.000000
    139.000000
    142.000000
    145.000000
    148.000000
    */
     double inferior = 0;
     double superior = 0;
     double passo = 0;
     double x = 0;
     IO_id ( "Method10 - v0.0" );
     inferior = IO_readdouble ( "Limite inferior do intervalo : " );
     do
     {
         superior = IO_readdouble ( "Limite superior do intervalo: " );
     }
     while ( inferior >= superior );
     do
     {
         passo = IO_readdouble ( "Variacao no intervalo (passo): " );
     }
     while ( passo <= 0.0 );
     for ( x = inferior; x <= superior; x = x + passo )
     {
         IO_printf ( "%lf\n", x );
     } 
     IO_pause ( "Apertar ENTER para continuar" );
}


void method_11(void)
{
    /*- ler uma palavra do teclado;
- mostrar as letras maiúsculas*/
    char palavra[STR_SIZE];
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        if(palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            printf("%c\n", palavra[i]);
        }
    }
}
void method_12(void)
{
    
    char palavra[STR_SIZE];
    int contagem = 0;
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        if(palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            contagem ++;
            printf("%c\n", palavra[i]);
        }
    }
    printf("\nMaiusculas: %d\n", contagem);
}

void method_13(void)
{
    /*- ler uma palavra do teclado;
- contar e mostrar as letras maiúsculas percorrendo do fim para o início da palavra. */
    char palavra[STR_SIZE];
    int contagem = 0;
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    getchar( );
    int tamanho = strlen(palavra);
    for(int i = tamanho; i >= 0; i--)
    {
        if(palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            contagem ++;
            printf("%c\n", palavra[i]);
        }
    }
    printf("\nMaiusculas: %d\n", contagem);
}
void method_14(void)
{
    /*- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas*/
    char palavra[STR_SIZE];

    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    getchar( );
    int contagem = 0;
    int tamanho = strlen(palavra);
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        if(palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            contagem++;
            printf("Maiusculas: %c\n", palavra[i]);
        }
        if(palavra[i] >= 'a' && palavra[i] <= 'z')
        {
            contagem++;
            printf("Minusculas: %c\n", palavra[i]);
        }
    }
    printf("%d\n", contagem);
}
void method_15(void)
{
    /*- - ler uma cadeia de caracteres do teclado;
- contar e mostrar todos os dígitos, percorrendo do fim para o início da cadeia de caracteres*/
    char palavra[STR_SIZE];
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    getchar( );
    int contagem = 0;
    int tamanho = strlen(palavra);
    for(int i = tamanho; i >= 0; i--)
    {
        printf("%c", palavra[i]);
        printf("\n");
    }
    printf("%d\n", tamanho);
}
void method_16(void)
{
    /*- - ler uma cadeia de caracteres do teclado;
- contar e mostrar tudo o que não for dígito e também não for letra*/
    char palavra[STR_SIZE];
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    getchar( );
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        if(!((palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= '0' && palavra[i] <= '9')))
        {
            printf("%c\n", palavra[i]); 
        }
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
        IO_println ( "5 - Metodo 5" );
        IO_println ( "6 - Metodo 6" );
        IO_println ( "7 - Metodo 7" );
        IO_println ( "8 - Metodo 8" );
        IO_println ( "9 - Metodo 9" );
        IO_println ( "10 - Metodo 10" );
        IO_println ( "11 - Metodo 11" );
        IO_println ( "12 - Metodo 12" );
        IO_println ( "13 - Metodo 13" );
        IO_println ( "14 - Metodo 14" );
        IO_println ( "15 - Metodo 15" );
        IO_println ( "16 - Metodo 16" );
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
            case 7:
                method_07 ( );
                break;
            case 8:
                method_08 ( );
                break;
            case 9:
                method_09 ( );
                break;
            case 10:
                method_10 ( );
                break;
            case 11:
                method_11 ( );
                break;
            case 12:
                method_12 ( );
                break;
            case 13:
                method_13 ( );
                break;
            case 14:
                method_14 ( );
                break;
            case 15:
                method_15 ( );
                break;
            case 16:
                method_16 ( );
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