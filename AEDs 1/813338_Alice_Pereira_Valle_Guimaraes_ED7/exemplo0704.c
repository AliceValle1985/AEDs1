//Alice Pereira Valle Guimaraes - 813338 - 02/10/2023
#include<stdio.h>
#include "io.h"

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
}

int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0704 - Programa = v0.0" );
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