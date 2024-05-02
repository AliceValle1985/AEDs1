//Alice Pereira Valle Guimaraes - 813338 - 06/10/2023
#include<stdio.h>
#include "io.h"
#include <math.h>

//Vai armazenar a quantidade de x no aquivo criado
void writeints(char filename[], int x)
{
    //abre um arquivo para escrita
    FILE *arquivo = fopen(filename, "wt");
    //repete x vezes e escreve x (*x) no arquivo
    for(int y = 0; y <= x; y++)
    {
        //ecreve no arquivo
        fprintf(arquivo, "%d\n", x);
    }
    //fecha o arquivo
    fclose(arquivo);
}
void method01()
{
    IO_id ( "\nMethod_01 - v0.0" );
    //da o nome de "Dados.txt" para "filename" e 10 para "x"
    writeints("Dados1.txt", 10);
    IO_pause ( "Apertar ENTER para continuar" );
}
void read(char filename[])
{
    int x         = 0;
    //abre o arquivo para escrita
    FILE* arquivo = fopen (filename, "rt");
    //le dados de um arquivo e armazena em x
    fscanf(arquivo, "%d", &x);
    //enquanto for diferente do final do arquivo
    while(! feof ( arquivo ))
    {
        //exiba x na tela
        printf("%d\n", x);
        //le dnv para garantir q nao vai dar erro e ficar lendo para sempre
        fscanf(arquivo, "%d\n", &x);
    }
    //fecha o arquivo
    fclose(arquivo);
}
void method02()
{
    IO_id ( "\nMethod_02 - v0.0" );
    read("Dados1.txt");
    IO_pause ( "Apertar ENTER para continuar" );
}
void writedouble(char filename[], int x)
{
    //abre o arquivo
    FILE *arquivo = fopen(filename, "wt");
    for(int i = 0; i < x; i++)
    {
        //escreve mo arquivio 1.0 vezes o numero pedido
        IO_fprintf(arquivo, "%lf\n",(0.1 * i));
    }
    //fecha o arquivo
    fclose(arquivo);
}
void method03()
{
    IO_id ( "\nMethod_03 - v0.0" );
    writedouble("Dados2.txt", 10);
    IO_pause ( "Apertar ENTER para continuar" );
}

void readdouble(chars filename)
{
    //abre o arquivo para leitura
    FILE *arquivo = fopen(filename, "rt");
    int x    = 0;
    int y    = 0;
    double z = 0.0;
    //fscanf armazena o valor lido em uma variavel e no arquivo ao msm tempo
    fscanf(arquivo, "%d", &x);
    //enquanto não for o final do arquivo e quando y for menor ou igual a x
    while(! feof (arquivo) && y <=x)
    {
        //fscanf armazena o valor lido em uma variavel e no arquivo ao msm tempo (nesse caso armazena no z)
        fscanf(arquivo, "%lf", &z);
        //exibe na tela o y e z (%2d mostra numeros com no maximo dois digitos)
        printf("%2d: %lf\n", y, z);
        y = y + 1;
    }
    //fecha o arquivo
    fclose(arquivo);
}
void method04()
{
    IO_id ("\nMethod_04 - v0.0" );
    readdouble("DADOS2.txt");
    IO_pause ("Apertar ENTER para continuar" );
}//end method04

void writetext(chars filename)
{
    //cria e abre o arquivo para escrita
    FILE *arquivo = fopen(filename, "wt");
    //cria uma string com o tamanho de STR_SIZE
    chars linha = IO_new_chars(STR_SIZE);
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
    do 
    {
        /*Definição de strcpy: A função strcpy em C e usada para copiar o conteúdo de uma string (cadeia de caracteres) para outra.
        char origem[] = "Hello, World!";
        char destino[20]; // Deve ter espaço suficiente para a cópia

        strcpy(destino, origem);

        printf("String de origem: %s\n", origem);
        printf("String de destino: %s\n", destino);
        */
        strcpy(linha, IO_readln(""));
        //vai gravar no arquivo a string "linha"
        IO_fprintf(arquivo, "%s\n", linha);
    }//strcmp compara duas strings, caractere por caractere, se elas forem iguais, ele retorna o valor 0, entao se for 0 eh um valor verdadeiro, e diferente de 0 eh um valor falso
    while(strcmp ("PARAR", linha) !=0);
    fclose(arquivo);
}
void method05()
{
    IO_id ( "Method_05 - v0.0" );
    writetext("DADOS3.txt");
    IO_pause("Aperte ENTER para continuar");
}//end method05
/*o while vai passar ate o final do arquivo e ate receber o valor de "PARAR"
vai exibir na tela oq estava escrito no arquivo
*/
void readtext(chars filename)
{
    //cria e abre um arquivo para leitura
    FILE *arquivo = fopen(filename, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    strcpy(linha, IO_freadln(arquivo));
    //feof le até o final do arquivo e strcmp compara duas strings e retorna um valor 0
    while(! feof(arquivo) && strcmp("PARAR", linha) != 0)
    {
        printf("%s\n", linha);
        //IO_freadln le ate o final da linha
        strcpy(linha, IO_freadln(arquivo));
    }
    //fecha o arquivo
    fclose(arquivo);
}
void method06 ( )
{
    IO_id ( "Method_06 - v0.0" );
    readtext ( "DADOS3.TXT" );
    IO_pause ( "Apertar ENTER para continuar" );
}//end method 06



void copytest(chars fileout, chars filein)
{
    FILE *saida   = fopen(fileout, "wt");
    FILE *entrada = fopen (filein, "rt");
    chars linha   = IO_new_chars(STR_SIZE);
    int contador  = 0;
    //copia a variavel "entrada" e armazena em "linha"
    strcpy(linha, IO_freadln(entrada));
    //vai ler o arquivo ate o final
    while(! feof (entrada) )
    {
        //adiciona um ao contador
        contador++;
        //confere se foi escrito "PARAR"
        if(strcmp("PARAR", linha) != 0)
        {
            //ela armazena o valor da "linha" e armazena no arquivo "saida"
            IO_fprintln(saida, linha);
        }
        //copia a variavel "entrada" e armazena em "linha"
        strcpy(linha, IO_freadln(entrada));
    }
    IO_printf("Linhas = %d\n", contador);
    fclose(  saida  );
    fclose( entrada );
    /*basicamente, oq estadentro do arquivo "entrada" eh armazenado na variavel "linha"
    strcpy(linha, entrada);
    depois o while le o arquivo ate o final, adiciona 1 ao contador, confere se alguma vez em linha foi escrito "PARAR", quando encontra "PARAR" ele armazena oq tem em linha no arquivo "saida" 
    if(strcmp("PARAR", linha) != 0)
        {
            //ela armazena o valor da "linha" e armazena no arquivo "saida"
            IO_fprintf(saida, linha);
        }
        e depois exibe a quantidade de linhas lidas
        
        Em resumo, a função copytest lê linhas de um arquivo de entrada e copia todas as linhas, exceto aquelas que contêm a palavra "PARAR", para um arquivo de saída. O número total de linhas lidas é exibido no final.
    */
}
void method07 ( )
{
    IO_id ( "Method_07 - v0.0" );
    copytest ( "DADOS4.TXT", "DADOS3.TXT" );
    IO_pause ( "Apertar ENTER para continuar" );
}//end method07


void appendtext(chars filename)
{
    //abre o arquivo para acrecentar valores nele
    FILE *arquivo = fopen(filename, "at");
    chars linha = IO_new_chars(STR_SIZE);
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\")\n");
    do
    {
        //IO_readln recebe o valor e strcmp armazena em linha
        strcpy(linha, IO_readln(""));
        //armazenar o valor de linha em arquivo
        IO_fprintln ( arquivo, linha );
    }while(strcmp("PARAR", linha) != 0);
    fclose(arquivo);
}
void method08()
{
    IO_id ( "Method_08 - v0.0" );
    appendtext ("DADOS4.txt");
    IO_pause ( "Apertar ENTER para continuar" );
}//end method08

void readwords(chars filename)
{
    FILE *arquivo = fopen(filename, "rt");
    chars linha   = IO_new_chars(STR_SIZE);
    //vai ler  e vai armazenar em arquivo
    strcpy ( linha, IO_fread ( arquivo ) );
    //ler o arquivo enquanto nao estiver no final e enquanto não tiver a entrada de "PARAR"
    while(! feof(arquivo) && strcmp("PARAR", linha) != 0)
    {
        //exibir na tela oq foi escrito
        printf("%s", linha);
        //armazenar em linha oq foi escrito
        strcpy(linha, IO_fread(arquivo));
    }
    fclose(arquivo);
}
void method09()
{
    IO_id ( "Method_09 - v0.0" );
    readwords ("DADOS4.txt");
    IO_pause ( "Apertar ENTER para continuar" );
}//end method09



/*
Este código tem a função searchword que busca uma palavra em um arquivo de texto. A função recebe o nome do arquivo e a palavra que você deseja procurar. Ela abre o arquivo, lê as linhas uma por uma e compara cada linha com a palavra desejada. Se a palavra for encontrada em alguma linha do arquivo, a função retorna verdadeiro (1), caso contrário, retorna falso (0).*/
bool searchword(chars filename, chars word)
{
    FILE *arquivo = fopen(filename, "rt");
    chars linha   = IO_new_chars(STR_SIZE);
    strcpy(linha, IO_fread(arquivo));
    //enquanto nao for o final do arquivo e enquanto linha for diferente de word
    while(! feof(arquivo) && strcmp(word, linha) != 0)
    {
        strcmp(linha, IO_fread(arquivo));
    }
    fclose(arquivo);
    return (strcmp(word, linha) == 0);
} 
void method10()
{
    IO_id ( "Method_10 - v0.0" );
    IO_printf("Procurar (\"%s\") = %d\n", "pqr", searchword("DADOS4.txt", "pqr"));
    IO_printf("Procurar (\"%s\") = %d\n", "pqs", searchword("DADOS4.txt", "pqs"));
    IO_pause ( "Apertar ENTER para continuar" );
}
/* Incluir um método (0711) para
ler um valor inteiro do teclado e 
gravar essa quantidade em múltiplos de 3, ímpares, em ordem crescente, começando em 9.
Exemplo: n = 5 => { 9, 15, 21, 27, 33 }
*/
int multiplosde3(chars filename)
{
    FILE *arquivo = fopen(filename, "w");
    int numero = 9;
    int x = 0;
    //testa se o arquivo foi criado corretamente
    if(arquivo == NULL)
    {
        printf("Arquivo nao foi criado corretamente.");
    }
    //pede a quantidade de numeros o usuario quer que sejam gravados
    printf("\nQuantos numeros voce deseja ver que sao multiplos de 3 depois do 9? ");
    scanf("%d", &x);
    if(x <= 0)
    {
        printf("A quantidade nao pode ser igual ou menor que zero.");
        return 0;
    }
    //
    for(int i = 0; i < x; i++)
    {
        //testa se o numero eh multiplo de 3 e impar
        if(numero % 3 == 0 && numero % 2 == 1)
        {
            //se for, grava no arquivo
            fprintf(arquivo, "%d\n", numero);
            //exibe na tela
            printf("%d\n", numero);
            //adiciona 6 a mais para ser um multiplo de 3 e continuar a ser impar
            numero = numero + 6;
        }
    }
    //fecha o arquivo
    fclose(arquivo);
}
void method11()
{
    chars nomearquivo = IO_new_chars(STR_SIZE);
    IO_id ( "Method_11 - v0.0" );
    printf("\nQual é o nome que deseja dar ao arquivo? ");
    scanf("%s", nomearquivo);
    multiplosde3(nomearquivo);
    IO_pause ( "Apertar ENTER para continuar" );
}//end method11



/*Incluir um método (0712) para
ler um valor inteiro do teclado e 
gravar essa quantidade em múltiplos de 7, ímpares, em ordem decrescente encerrando em 21.
Exemplo: n = 5 => { 77, 63, 49, 35, 21 */
int multiplosde7(chars filename)
{
    FILE *arquivo = fopen(filename, "w");
    int numero = 21;
    int x = 0;
    //testa se o arquivo foi criado corretamente
    if(arquivo == NULL)
    {
        printf("Arquivo nao foi criado corretamente.");
    }
    //pede a quantidade de numeros o usuario quer que sejam gravados
    printf("\nQuantos numeros voce deseja ver que sao multiplos de 7 e impares depois do 21? ");
    scanf("%d", &x);
    if(x <= 0)
    {
        printf("A quantidade nao pode ser menor ou igual a zero.");
        return 0;
    }
    numero = 21 + (14 * (x - 1));
    /*
        21 + (14 * x) = 21 + (14 * 5)
        21 + (70)
        91
    */
    for(int i = 0; i < x; i++)
    {
        //testa se o numero eh multiplo de 3 e impar
        if(numero % 7 == 0 && numero % 2 == 1)
        {
            
            //se for, grava no arquivo
            fprintf(arquivo, "%d\n", numero);
            //exibe na tela
            printf("%d\n", numero);
            //
            numero = numero - 14;
            /*
                21 + (14 * x) = 21 + (14 * 5)
                21 + (70)
                91 - 14
                77 - 14
                ...
            */
        }
    }
    //fecha o arquivo
    fclose(arquivo);
}

void method12()
{
    chars nomearquivo = IO_new_chars(STR_SIZE);
    IO_id ( "Method_12 - v0.0" );
    printf("\nQual é o nome que deseja dar ao arquivo? ");
    scanf("%s", nomearquivo);
    multiplosde7(nomearquivo);
    printf("Aperte ENTER para continuar.");
}//end method12


void potencia7(chars filename)
{
    //cria um arquivo q vai ter o nome dado pelo usuario
    FILE *arquivo = fopen (filename, "w");
    int x         = 0;
    int potencia  = 1;
    printf("Quantas potencias de 7 voce deseja saber? ");
    scanf("%d", &x);
    //exibe na tela as potencias de 7
    for(int i = 0; i < x; i++)
    {
        fprintf(arquivo, "%d\n", potencia);
        printf("%d\n", potencia);
        potencia = potencia * 7;
    }
    fclose(arquivo);
}
void method13()
{
    chars nomearquivo = IO_new_chars(STR_SIZE);
    IO_id ( "Method_12 - v0.0" );
    printf("Qual eh o nome que deseja dar ao arquivo? ");
    scanf("%s", nomearquivo);
    potencia7(nomearquivo);
    printf("Aperte ENTER para continuar.");
}//end mehtod13



/* Incluir um método (0714) para
ler um valor inteiro do teclado e 
gravar essa quantidade em valores decrescentes da sequência: ... 1/2401 1/343 1/49 1/7 1.
Exemplo: n = 5 => { 1/2401, 1/343, 1/49, 1/7, 1 }*/


void fracaopotencia7(chars filename)
{
    FILE *arquivo = fopen(filename, "w");
    int x         = 0;
    int potencia  = 1;
    printf("\nDigite um numero: ");
    scanf("%d", &x);
    //for para dar o valor inical para "potencia", x vai ser o numero que o usuario quer
    for(int j = 0; j < x; j++)
    {
        potencia *= 7;
    }
    for(int i = 0; i < x; i++)
    {
        printf("1 / %d\n", potencia);
        fprintf(arquivo, "1 / %d\n", potencia);
        potencia /= 7;
    }
    printf("1\n");
    fclose(arquivo);
}
void method14()
{
    chars nomearquivo = IO_new_chars(STR_SIZE);
    printf("\nQual e o nome do arquivo que voce deseja? ");
    scanf("%s", nomearquivo);
    fracaopotencia7(nomearquivo);
    printf("Aperte ENTER para continuar.");
}
    


int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0714 - Programa = v0.0" );
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
        printf ( "\n%s" , "10 - Method_10" );
        printf ( "\n%s" , "11 - Method_11" );
        printf ( "\n%s" , "12 - Method_12" );
        printf ( "\n%s" , "13 - Method_13" );
        printf ( "\n%s" , "14 - Method_14" );
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
            case 13: 
                method13 ( ); 
                break;
            case 14: 
                method14 ( ); 
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