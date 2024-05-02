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
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0702 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
        printf ( "\n%s" , "2 - Method_02" );
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