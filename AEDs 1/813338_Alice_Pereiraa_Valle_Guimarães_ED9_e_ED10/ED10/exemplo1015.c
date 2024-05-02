
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
ref_int_matrix freadintmatrix(chars filename)
{
    ref_int_matrix matrix = NULL;
    int linhas = 0;
    int colunas = 0;
    FILE* arquivo = fopen ( filename, "rt" );

    fscanf ( arquivo, "%d", &linhas );
    fscanf ( arquivo, "%d", &colunas );
    if ( linhas <= 0 || colunas <= 0 )
    {
    IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
    // reservar espaco para armazenar
    matrix = new_int_matrix ( linhas, colunas );
    // testar se ha' espaco
    if ( matrix != NULL && matrix->data == NULL )
    {
    // nao ha' espaco
    matrix->linhas = 0;
    matrix->colunas = 0;
    matrix->ix = 0;
    matrix->iy = 0;
    }
        else
{
// testar a existência
if ( matrix != NULL )
{
// ler e guardar valores na matriz
matrix->ix = 0;
while ( ! feof ( arquivo ) && matrix->ix < matrix->linhas )
{
matrix->iy = 0;
while ( ! feof ( arquivo ) && matrix->iy < matrix->colunas )
{
// guardar valor
fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
// passar ao proximo
matrix->iy = matrix->iy+1;
} // end while
// passar ao proximo
matrix->ix = matrix->ix+1;
} // end while
matrix->ix = 0;
matrix->iy = 0;
} // end if
} // end if
} // end if
// retornar matriz lida
return ( matrix );
} // end freadintMatrix ( )
        
void method09 ( )
{
// identificar
IO_id ( "Method_09 - v0.0" );
// ler dados
ref_int_matrix matrix = freadintmatrix ( "MATRIX1.TXT" );
// mostrar dados
IO_printf ( "\n" );
printintmatrix ( matrix );
// reciclar espaco
free_int_matrix ( matrix );
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )


/**
copyIntMatrix - Copiar matriz com valores inteiros.
@return referencia para o grupo de valores inteiros
*/
ref_int_matrix copyintmatrix ( ref_int_matrix matrix )
{
// definir dados locais
ref_int_matrix copy = NULL;
if ( matrix == NULL || matrix->data == NULL )
{
IO_printf ( "\nERRO: Faltam dados.\n" );
}
else
{
if ( matrix->linhas <= 0 || matrix->colunas <= 0 )
{
IO_printf ( "\nERRO: Valor invalido.\n" );
}
else
{
// reservar espaco
copy = new_int_matrix ( matrix->linhas, matrix->colunas );
// testar se ha' espaco e dados
if ( copy == NULL || copy->data == NULL )
{
printf ( "\nERRO: Falta espaco." );
}
else
{
// copiar valores
for ( copy->ix = 0; copy->ix < copy->linhas; copy->ix = copy->ix + 1 )
{
for ( copy->iy = 0; copy->iy < copy->colunas; copy->iy = copy->iy + 1 )
{
// copiar valor
copy->data [ copy->ix ][ copy->iy ]
= matrix->data [ copy->ix ][ copy->iy ];
} // end for
} // end for
} // end if
} // end if
} // end if
// retornar copia
return ( copy );
} // end copyIntMatrix ( )
/**
Method_10.
*/
void method10 ( )
{
// definir dados
ref_int_matrix matrix = NULL;
ref_int_matrix other = NULL;
// identificar
IO_id ( "Method_10 - v0.0" );
// ler dados
matrix = freadintmatrix ( "MATRIX1.TXT" );
// copiar dados
other = copyintmatrix ( matrix );
// mostrar dados
IO_printf ( "\nOriginal\n" );
printintmatrix ( matrix );
// mostrar dados
IO_printf ( "\nCopia\n" );
printintmatrix ( other );
// reciclar espaco
free_int_matrix ( matrix );
free_int_matrix ( other );
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // end method10 ( )

/*) Incluir um método (1011) para
gerar um valor inteiro aleatoriamente dentro de um intervalo, 
cujos limites de início e de fim serão recebidos como parâmetros.
Para para testar, ler os limites do intervalo do teclado;
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatórios 
dentro do intervalo e armazená-los em arranjo;
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade 
de números aleatórios ( N ) que serão gravados em seguida.
DICA: Usar a função rand( ), mas tentar limitar valores muito grandes.
Exemplo: valor = RandomIntGenerate ( inferior, superior );*/
void fprintfarray2(chars filename, int_array array, int n)
{
    //abre o arquivo
    FILE *arquivo = fopen(filename, "w");
    fprintf(arquivo, "Quantidade de numeros aleatorios: %d\n", n);
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
void trem1(int x, int y)
{
    int n = 0;
    int_array array;
    array.data = (ints) malloc(array.length * sizeof(int));
    srand(time(0));
    int valor = 0;
    printf("Digite a quantidade de valores aleatórios: ");
    scanf("%d", &n);
    array.length = n;
    for(int i = 0; i < n; i++)
    {
        valor = rand( ) % (x - y + 1) + y;
        array.data[i] = valor;
    }
    fprintfarray2("DADOS.TXT", array, n);
    free(array.data);
}
void method11()
{
    int x = 0;
    int y = 0;
    printf("\nDigite dois valores para gerar um numero aleatorio entre eles. (O primeiro valor tem que ser maior que o segundo)\n");
    do
    {
        printf("\nPrimeiro valor: ");
        scanf("%d", &x);
        printf("\nSegundo valor: ");
        scanf("%d", &y);
    }while(x < y);
    trem1(x, y);
}
//exercicio 2
int readarrayfromfile(chars filename)
{
    int n = 0;
    int a = 0;
    FILE *arquivo = fopen(filename, "r");
    int_array array;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &n); 
    getchar( );
    if(arquivo)
    {
        fscanf(arquivo, "%d", &array.length);
        array.data = (ints) malloc(array.length * sizeof(int));
    
        for(array.ix = 0; array.ix <= array.length; array.ix++)
        {
            fscanf(arquivo, "%d", &array.data[array.ix]);
        }
        int valorencontrado = 0;
        for(array.ix = 0; array.ix < array.length; array.ix++)
        {
            if(array.data[array.ix] == n)
            {
                printf("Valor %d encontrado!", n);
                valorencontrado = 1;
                break;
            }   
        }
        if (valorencontrado != 1) 
        {
            printf("Valor %d não encontrado!\n", n);
        }
         free(array.data);
    }
    else
    {
        printf("Arquivo não existe.");
    }
    fclose(arquivo);
}
void method12()
{
    readarrayfromfile("DADOS.TXT");
}

/*operar a comparação de dois arranjos.
Para testar, receber dados de arquivos e
aplicar a função sobre os arranjos com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
Exemplo: arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
arranjo2 = readArrayFromFile ( "DADOS2.TXT" );
resposta = arrayCompare ( arranjo1, arranjo2 );*/

int_array readarrayfromfile3(chars filename)
{
    int_array array;
    FILE *arquivo = fopen(filename, "r");
    if(arquivo)
    {
        fscanf(arquivo, "%d", &array.length); // leia o comprimento do arquivo
        array.data = (ints) malloc(array.length * sizeof(int)); // aloque memória para os dados

        for(array.ix = 0; array.ix <= array.length; array.ix++)
        {
            fscanf(arquivo, "%d", &array.data[array.ix]);
        }
    }
    else
    {
        printf("\nERRO: arquivo não encontrado.");
    }
    fclose(arquivo);
    return array;
}
bool arraycompare(int_array array1, int_array array2)
{
    bool verdadeiro = true;
    if(array1.length != array2.length)
    {
        return false;
    }
    for(array1.ix = 0; array1.ix < array1.length; array1.ix++)
    {
        if(array1.data[array1.ix] != array2.data[array1.ix])
        {
            verdadeiro = false;
            break;
        }
    }
    return verdadeiro;
}
void method13()
{
    bool resposta = false;
    int_array array1;
    int_array array2;
    array1 = readarrayfromfile3("DADOS.TXT");
    array2 = readarrayfromfile3("DADOS2.TXT");
        resposta = arraycompare(array1, array2);
        if(resposta)
        {
            printf("\nOs arrays são identicos.\n");
        }
        else
        {
            printf("\nOs arrays são diferentes.\n");
        } 
}
int arrayadd(int_array array1, int_array array2)
{
    int n = 0;
    int soma = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &n);
    for(array1.ix = 0; array1.ix < array1.length+1; array1.ix++)
    {
        array2.data[array1.ix] = array2.data[array1.ix] * n; 
        soma += array1.data[array1.ix] + array2.data[array1.ix];
    }
    return soma;
}
void method14()
{
    int_array array1;
    int_array array2;
    int soma = 0;
    array1 = readarrayfromfile3("DADOS.TXT");
    array2 = readarrayfromfile3("DADOS2.TXT");
    soma =  arrayadd(array1, array2);
    printf("%d", soma);
}
bool isArrayDecrescente(int_array array1)
{
    bool resposta = true;
    for (array1.ix = 0; array1.ix < array1.length - 1; array1.ix++)
    {
        if (array1.data[array1.ix] < array1.data[array1.ix + 1])
        {
            resposta = false;
            break; 
        }
    }
    return resposta;
}



void method15()
{
    int_array array1;
    bool resposta;
    array1 = readarrayfromfile3("DADOS.TXT");
    resposta = isArrayDecrescente(array1);
    if(resposta == true)
    {
        printf("\nEsta em ordem decrescente");
    }
    else
    {
        printf("\nNao esta em ordem decrescente");
    }
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
        printf ("\n%s" , "9 - Method_09");
        printf ("\n%s" , "10 - Method_10");
        printf ("\n%s" , "11 - Method_11");
        printf ("\n%s" , "12 - Method_12");
        printf ("\n%s" , "13 - Method_13");
        printf ("\n%s" , "14 - Method_14");
        printf ("\n%s" , "15 - Method_15");
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
            case 15: 
                method15 ( ); 
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