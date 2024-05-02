
//Alice Pereira Valle Guimaraes - 813338 - 02/10/2023#include<stdio.h>
#include "io.h"

//Vai armazenar a quantidade de x no aquivo criado
void writeints(char filename[], int x)
{
    //abre um arquivo para escrever nele
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
    writeints("Dados1.txt", 10);
    IO_pause ( "Apertar ENTER para continuar" );
}
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0701 - Programa = v0.0" );
    printf ( "%s\n", "Autor: Alice Pereira Valle Guimaraes" );
    printf ( "\n" ); 
    
    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01" );
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