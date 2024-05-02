//Alice Pereira Valle Guimaraes - 813338
#include "io.h" 
#include <stdio.h>
typedef
struct s_int_array
{
    int length;
    int ix;
    ints data;
} int_array;// int_array é o nome que vai ser usado pra chamar a struct (como uma variavel, tipo int_array nomevariavel;)
typedef int_array* ref_int_array;
/*aloca memorias para data, para fazer o ix como posição de data e lenght como tamanhodo vetor de data 
então: data[lenght];
       ix = posição
*/
ref_int_array new_int_array(int n)
{
    //malloc(tamanho de um int array), retorna o tamanho de int_array em bytes e alocando (guardando memoria) para tmparray
    ref_int_array tmparray = (ref_int_array) malloc(sizeof(int_array));
    if(tmparray == NULL)
    {
        printf("\nERRO: falta esppaço.\n");
    }
    else
    {
        //acessa lenght de tmparray
        tmparray -> length = 0;
        //acessa data em tmparray
        tmparray -> data   = NULL;
        //acessa ix em tmparray
        tmparray -> ix     = -1;
        if(n > 0)
        {
            //armazenar n em lenght
            tmparray -> length = n;
            //rezervar espaços para os dados
            tmparray -> data = (ints) malloc (n * sizeof(int));
            //indicador do primeiro elemento
            tmparray -> ix = 0;
        }
    }
    return (tmparray);
}

/*libera a memoria alocada de data*/
void free_int_array(ref_int_array tmparray)
{
    //se tmarray e data forem diferentes de nulo liberar o espaço de data
    if(tmparray != NULL)
    {
        if(tmparray -> data != NULL)
        {
            free(tmparray -> data);
        }
    }
    //Liberar o espaço de tmparray
    free(tmparray);
}
/*printar na tela a posição de data[posição] e o valor de data*/
void printlnarray(int_array array)
{
    //se array.data existir
    if(array.data)
    {
        /*Esse for é basicamente =
            for(ix = 0; ix < lenght; ix++)
        */
        for(array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            //basicamente = printf("%2d: %d\n", ix, data[ix]);
            printf("%2d: %d\n", array.ix, array.data[array.ix]);
        }
    }
}
void method01()
{
    //dando o nome de array para a struct array
    int_array array;
    //dando o tamanho quevai ter o vetor de data
    array.length = 5;
    //dando ao vetor de data a quantidade de lenght vezes o tamanho de um inteiro
    array.data = (ints) malloc(array.length * sizeof(int));
    //testando a existencia de array.data
    if(array.data)
    {
        //dando os valores a array.data
        array.data[0] = 1;
        array.data[1] = 2;
        array.data[2] = 3;
        array.data[3] = 4;
        array.data[4] = 5;
    }
    IO_id("Method_01 - v0.0");
    printlnarray(array);
    if(array.data)
    {
        free(array.data);
    }
    IO_pause ("Apertar ENTER para continuar");
}
int main(void)
{
    int x = 0;
    printf ("%s\n", "Exemplo1001 - Programa = v0.0");
    printf ("%s\n", "Autor: Alice Pereira Valle Guimaraes");
    printf ("\n" ); 
    
    do
    {
        printf ("\n%s\n", "Opcoes:");
        printf ("\n%s" , "0 - Terminar");
        printf ("\n%s" , "1 - Method_01");
        printf ("\n" );
        printf ("\n%s", "Opcao = " );
        scanf ( "%d", &x );
        getchar( );
        printf ("\n%s%d", "Opcao = ", x);
        switch ( x )
        {
            case 0:
                break;
            case 1: 
                method01 ( ); 
                break;
            default: 
                printf ("\nERRO: Opcao invalida.\n");
                break;
        } 
    }
    while ( x != 0 );
    printf ("\n\nApertar ENTER para terminar.");
    getchar( );
    return ( 0 );
}