
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
void printintarray(int_array array)
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
    printintarray(array);
    if(array.data)
    {
        free(array.data);
    }
    IO_pause ("Apertar ENTER para continuar");
}
/*armazena valores em um array*/
int_array io_readlnarray()
{
    chars text = IO_new_chars(STR_SIZE);
    //variavel estatica, não tem o valor alterado na chamada de função, só pode ser alterada na função em q ela foi declarada
    static int_array array;
    do
    {
        //ler o valor inteiro do teclado
        array.length = IO_readint("\nLength: ");
    }
    while(array.length <= 0);
    //faz a msm coisa que o malloc, rezerva espaço para armazenar
    array.data = IO_new_ints(array.length);
    if(array.data == NULL)
    {
        array.length = 0;
    }
    else
    {
        /*for(ix = 0; ix < length; ix++)*/
        for(array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            //zera o valor de text, deixando ele sem valor nenhum dentro
            strcpy(text, STR_EMPTY);
            array.data [ array.ix ] = IO_readint ( IO_concat (IO_concat ( text, IO_toString_d ( array.ix ) ), " : " ) );
        }
    }
    return(array);
}
void method02()
{
    int_array array;
    IO_id ("Method_02 - v0.0");
    //chama a função para receber os dados
    array = io_readlnarray( );
    //testando se os dados existem
    if(array.data)
    {
        printf("\n");
        //exibe os valores do array
        printintarray(array);
        free(array.data);
    }
    IO_pause ( "Apertar ENTER para continuar" );
}
//grava um array em um arquivo
void fprintfarray(chars filename, int_array array)
{
    //abre o arquivo
    FILE *arquivo = fopen(filename, "w");
    fprintf(arquivo, "%d\n", array.length);
    //se data existir
    if(array.data)
    {
        for(array.ix = 0; array.ix < array.length; array.ix++)
        {
            fprintf(arquivo, "%d\n", array.data[array.ix]);
        }
    }
    fclose(arquivo);
}
void method03()
{
    int_array array;
    IO_id ( "Method_03 - v0.0" );
    //receber os valores de array
    array = io_readlnarray();
    if(array.data)
    {
        //vai exibir na tela o array 
        printintarray(array);
        //vai gravar no arquivo
        fprintfarray("array.txt", array);
        free(array.data);
    }
    IO_pause ( "Apertar ENTER para continuar" );
}
//ler oq esta no arquivo
int freadarray(chars filename)
{
    int n = 0;
    FILE *arquivo = fopen(filename, "r");
    if(arquivo)
    {
        fscanf(arquivo, "%d", &n);
        if(n <= 0)
        {
            n = 0;
        }
    }
    return (n);
}
int_array fio_readarray(chars filename)
{
    int x = 0;
    int y = 0;
    //abre o arquivo
    FILE *arquivo = fopen(filename, "r");
    //declara um array estatico
    static int_array array;
    //se o arquivo existir
    if(arquivo)
    {
        //pegar oq esta no arquivo e armazenar em array.length
        fscanf(arquivo, "%d\n", &array.length);
        //se não tiver nenhum valor em length
        if(array.length <= 0)
        {
            //exibir na tela 
            printf("\nERRO: valor invalido.\n");
            array.length = 0;
        }
        else
        {
            //aloca memoria de length para data
            array.data = IO_new_ints ( array.length );
            if(array.data)
            {
                array.ix = 0;
                //enquanto não for o final do arquivo e enquanto ix for menor q length
                while(!feof(arquivo) && array.ix < array.length)
                {
                    //pegar oq esta np arquivo e armazenar em ix
                    fscanf(arquivo, "%d", &array.data[array.ix]);
                    array.ix++;
                }
            }
        }
    }
    return (array);
}
void method04()
{
    int_array array;
    IO_id ( "Method_04 - v0.0" );
    array = fio_readarray("array.txt");
    if(array.data)
    {
        printf("\n");
        printintarray(array);
        free(array.data);
    }
    IO_pause ( "Apertar ENTER para continuar" );
}
//copia int_array array para ref_int_array(referencia pra int array) copy 
//copia uma structa para outra
ref_int_array copyintarray(int_array array)
{
    int x = 0;
    int y = 0;
    //ref_int_array é como se fosse outra struct
    ref_int_array copy;
    //confere se o tamanho do vetor de array.data é menor ou igual a que 0 
    if(array.length <= 0)
    {
        printf("\nERRO: valor invalido\n");
        array.length = 0;
    }
    else
    {
        //aloca memoria para copy
        copy = new_int_array(array.length);
        //se copy existir
        if(copy)
        {
            //o valor de copy. length vai ser igual o valor de array.length
            copy -> length = array.length;
            //aloca a memoria de copy.length para copy.data
            copy -> data = IO_new_ints(copy -> length);
            //se copy.data não existir ou array não existir
            if(copy -> data == NULL || array.data == NULL)
            {
                //mostrar erro
                printf("\nERRO: falta espaço ou dados.\n");
            }
            else
            {
                //for(ix = 0; ix < length; ix++);
                for(array.ix = 0; array.ix < array.length; array.ix++)
                {
                    copy -> data[array.ix] = array.data[array.ix];
                }
            }
        }
    }
    return(copy);
}
void method05()
{
    int_array array;
    ref_int_array other;
    IO_id ( "Method_05 - v0.0" );
    array = fio_readarray("array1.txt");
    other = copyintarray(array);
    if(array.data)
    {
        //printando na tela o array e a copia
        printintarray(array);
        printintarray(*other);
        //temq que usar o free pq em fio_readrray ele utiliza uma alocação
        free(array.data);
        free(other -> data);
        free(other);
    }
    IO_pause("Aperte ENTER para continuar.");
}
typedef
    struct s_int_matrix
    {
        int linhas;
        int colunas;
        ints *data;
        int ix, iy;
    }int_matrix;
typedef int_matrix * ref_int_matrix;
//reservar espaço para uma matrix de inteiros
ref_int_matrix new_int_matrix(int linhas, int colunas)
{
    //reservando o valor de memoria de int_matrix em tmpmatrix
    ref_int_matrix tmpmatrix = (ref_int_matrix) malloc (sizeof(int_matrix));
    // estabelecer valores padroes
     if ( tmpmatrix != NULL )
     {
         tmpmatrix->linhas = 0;
         tmpmatrix->colunas = 0;
         tmpmatrix->data = NULL;
         // reservar espaco
         if ( linhas>0 && colunas>0 )
         {
             tmpmatrix->linhas = linhas;
             tmpmatrix->colunas = colunas;
             //reservando espaço para o vetor de data 
             tmpmatrix->data = malloc (linhas * sizeof(ints));
             if ( tmpmatrix->data )
             {
                 for ( tmpmatrix->ix=0; tmpmatrix->ix<tmpmatrix->linhas; tmpmatrix->ix=tmpmatrix->ix+1 )
                 {
                     //reservando a quantidade de culunas do tamanho de inteiros
                     tmpmatrix->data [ tmpmatrix->ix ] = (ints) malloc (colunas * sizeof(int));
                 } // end for
             } // end if
         } // end if
         tmpmatrix->ix = 0;
         tmpmatrix->iy = 0;
     } // end if
     return ( tmpmatrix );
}
void free_int_matrix(ref_int_matrix matrix)
{
    //se a matrix não for nula
    if(matrix != NULL)
    {
        //se a data não for nula
        if(matrix -> data != NULL)
        {
            //for(ix = 0; ix < linhas; ix++)
            for(matrix -> ix = 0; matrix -> ix < matrix -> linhas; matrix -> ix++)
            {
                //libera os espaços da matrix, um por um
                free(matrix -> data[matrix -> ix]);
            }
            //libera o espaço de data
            free(matrix -> data);
        }
        //libera a propria matrix
        free(matrix);
    }
}
void printintmatrix(ref_int_matrix matrix)
{
    //testando a existencia
    if(matrix != NULL && matrix -> data != NULL)
    {
        for(matrix -> ix = 0; matrix -> ix < matrix -> linhas; matrix -> ix++)
        {
            for(matrix -> iy = 0; matrix -> iy < matrix -> colunas; matrix -> iy++)
            {
                printf("%3d\t", matrix -> data[matrix -> ix][matrix -> iy]);
            }
            printf("\n");
        }
    }
}
void method06()
{
    ref_int_matrix matrix = new_int_matrix(3, 3);
    if(matrix != NULL && matrix -> data != NULL)
    {
        /*data[x][y]*/
        /*posição 0 0 = 1*/
        matrix -> data[0][0] = 1;
        /*posição 0 1 = 2*/
        matrix -> data[0][1] = 2;
        /*posição 0 2 = 3*/
        matrix -> data[0][2] = 3;
        /*posição 1 0 = 1*/
        matrix -> data[1][0] = 4;
        /*posição 1 1 = 5*/
        matrix -> data[1][1] = 5;
        /*posição 1 2 = 6*/
        matrix -> data[1][2] = 6;
        /*posição 2 0 = 7*/
        matrix -> data[2][0] = 7;
        /*posição 2 1 = 8*/
        matrix -> data[2][1] = 8;
        /*posição 2 2 = 9*/
        matrix -> data[2][2] = 9; 
    }
    IO_id ( "Method_06 - v0.0" );
    printintmatrix(matrix);
    free_int_matrix(matrix);
    IO_pause ( "Apertar ENTER para continuar" );
}
//receber os valores das matrix com valores inteiros
ref_int_matrix io_readintmatrix( )
{
    int linhas  = 0;
    int colunas = 0;
    chars text  = IO_new_chars(STR_SIZE);
    //receber o valor de linhas só se o valor for maior que 0
    do
    {
        linhas = IO_readint("\nLinhas = ");
    } while(linhas <= 0);
    //receber o valor de colunas só se o valor for maior que 0
    do
    {
        colunas = IO_readint("\nColunas = ");
    } while(colunas <= 0);
    //cria uma matrix de inteiros
    ref_int_matrix matrix = new_int_matrix(linhas, colunas);
    //se a matrix existir
    if(matrix != NULL)
    {
        //conferir se data não é nula
        if(matrix -> data == NULL)
        {
            matrix -> linhas  = 0;
            matrix -> colunas = 0;
            matrix -> ix      = 0;
            matrix -> iy      = 0;
        }
        else
        {
            //percorrer pela matrix
            for(matrix -> ix = 0; matrix -> ix < matrix -> linhas; matrix->ix=matrix->ix+1)
            {
                for(matrix -> iy = 0; matrix -> iy < matrix -> colunas; matrix->iy=matrix->iy+1)
                {
                    //zerar o valor de text
                    strcpy(text, STR_EMPTY);
                    //mostrar 0, 0 : na tela e receber o valor das posições da matrix
                    matrix -> data[matrix -> ix][matrix -> iy] = IO_readint( IO_concat (IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix )), ", "),IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) );
                }
                printf("\n");
            }
        }
    }
    //retornar os valores da matrix
    return(matrix);
}
void method07()
{
    ref_int_matrix matrix = NULL;
    IO_id("Method_07 - v0.0");
    //receber o valor da matrix
    matrix = io_readintmatrix( );
    printf("\n");
    //printar a matrix na tela
    printintmatrix(matrix);
    //liberar o espaço allocado da matrix
    free_int_matrix(matrix);
    IO_pause("Aperte ENTER para continuar.");
}
//printar a matrix em um arquivo
void fprintfmatrix(chars filename, ref_int_matrix matrix)
{
    FILE * arquivo = fopen(filename, "w");
    if(matrix == NULL)
    {
        printf("\nERRO: Não ha dado.");
    }
    else
    {
        //mostrar a quantidade de linhas
        fprintf(arquivo, "%d\n", matrix -> linhas);
        //mostrar a quantidade de colunas
        fprintf(arquivo, "%d\n", matrix -> colunas);
        if(matrix -> data != NULL)
        {
            //passar por toda a matrix
            for(matrix -> ix = 0; matrix -> ix < matrix -> linhas; matrix -> ix = matrix -> ix + 1)
            {
                for(matrix -> iy = 0; matrix -> iy < matrix -> colunas; matrix -> iy = matrix -> iy + 1)
                {
                    //gravar no arquivo
                    fprintf(arquivo, "%d\n", matrix -> data[matrix -> ix][matrix -> iy]);
                }
            }
        }
        //fechar o arquivo
        fclose(arquivo);
    }
}
void method08( )
{
    ref_int_matrix matrix = NULL;
    IO_id ( "Method_08 - v0.0" );
    //ler inteiros pra uma matrix
    matrix = io_readintmatrix( );
    //gravar no arquivo
    fprintfmatrix("matrix1.txt", matrix);
    //liberar o espaço usado
    free_int_matrix(matrix);
    IO_pause ( "Apertar ENTER para continuar" );
}
int main(void)
{
    int x = 0;
    printf ("%s\n", "Exemplo1008 - Programa = v0.0");
    printf ("%s\n", "Autor: Alice Pereira Valle Guimaraes");
    printf ("\n" ); 
    do
    {
        printf ("\n%s\n", "Opcoes:");
        printf ("\n%s" , "0 - Terminar");
        printf ("\n%s" , "1 - Method_01");
        printf ("\n%s" , "2 - Method_02");
        printf ("\n%s" , "3 - Method_03");
        printf ("\n%s" , "4 - Method_04");
        printf ("\n%s" , "5 - Method_05");
        printf ("\n%s" , "6 - Method_06");
        printf ("\n%s" , "7 - Method_07");
        printf ("\n%s" , "8 - Method_08");
        printf ("\n" );
        printf ("\n%s", "Opcao = " );
        scanf ( "%d", &x );
        getchar( );
        printf ("\n%s%d", "Opcao = ", x);
        printf("\n");
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