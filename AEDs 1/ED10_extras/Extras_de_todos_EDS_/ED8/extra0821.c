//Alice Pereira Valle Guimaraes 13/10/2023
#define MAX_SIZE 100
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "io.h"
void printlntArray(int n, int array [])
{
    for(int i = 0; i < n; i++)
    {
        IO_printf("%2d: %d\n", i, array[i]);
    }
}
void method01()
{
    int array[] = {1, 2, 3, 4, 5};
    IO_id ( "Method_01 - v0.0" );
    printlntArray(5, array);
    IO_pause ( "Apertar ENTER para continuar" );
}
void readIntArray ( int n, int array [ ] )
{
 int x = 0;
 int y = 0;
 chars text = IO_new_chars ( STR_SIZE );
 for ( x=0; x<n; x=x+1 )
 {
 strcpy ( text, STR_EMPTY );
 y = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( x ) ), " : " ) );
 array [ x ] = y;
 } 
} 
void method02()
{
    int n = 5;
    int array[n];
    IO_id ( "Method_02 - v0.0" );
    readIntArray(n, array);
    printf("\n");
    readIntArray(n, array);
    IO_pause ( "Apertar ENTER para continuar" );
}
void fprintIntArray ( chars fileName, int n, int array [ ] )
{
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;
 IO_fprintf ( arquivo, "%d\n", n );
 for ( x=0; x<n; x=x+1 )
 {
 IO_fprintf ( arquivo, "%d\n", array [ x ] );
 } 
 
 fclose ( arquivo );
} 
void method03 ( )
{
    int n = 5; 
    int array [ n ];
    IO_id ( "Method_03 - v0.0" );
    readIntArray ( n, array );
    IO_printf ( "\n" );
    fprintIntArray ( "ARRAY1.TXT", n, array );
    IO_pause ( "Apertar ENTER para continuar" );
    } 

int freadArraySize ( chars fileName )
{
    int n = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
    IO_fscanf ( arquivo, "%d", &n );
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    } 
    return ( n );
} 
void freadIntArray ( chars fileName, int n, int array [ ] )
{
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
    IO_fscanf ( arquivo, "%d", &x );
    if ( n <= 0 || n > x )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
        x = 0;
        while ( ! feof ( arquivo ) && x < n )
        { 
            IO_fscanf ( arquivo, "%d", &y );
            array [ x ] = y;
            x = x+1;
        }
    } 
} 
void method04 ( )
{
    int n = 0;
    IO_id ( "Method_04 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        IO_printf ( "\n" );
        printlntArray ( n, array );
    }
    IO_pause ( "Apertar ENTER para continuar" );
} 
void copyIntArray ( int n, int copy [ ], int array [ ] )
{
    int x = 0;
    int y = 0;
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    }
    else
    {
    for ( x = 0; x < n; x = x + 1 )
    {
        
        copy [ x ] = array [ x ];
    }
    }

} 
void method05 ( )
{
    int n = 0;
    IO_id ( "Method_05 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        int other [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        copyIntArray ( n, other, array );
        IO_printf ( "\nOriginal\n" );
        printlntArray ( n, array );
        IO_printf ( "\nCopia\n" );
        printlntArray ( n, other );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
}
int sumIntArray ( int n, int array [ ] )
{
    int soma = 0;
    int x = 0;
    for ( x=0; x<n; x=x+1 )
    {
        soma = soma + array [ x ];
    } 
    return ( soma );
} 
void method06 ( )
{
    int n = 0;
    IO_id ( "Method_06 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        IO_printf ( "\nSoma = %d\n", sumIntArray ( n, array ) );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
} 
bool isAllZeros ( int n, int array [ ] )
{
    bool result = true;
    int x = 0;
    x=0; 
    while ( x<n && result )
    {
        result = result && ( array [ x ] == 0 );
        x = x + 1;
    } 
    return ( result );
} 
void method07 ( )
{
    int n = 5; 
    int array1 [ ] = { 0,0,0,0,0 };
    int array2 [ ] = { 1,2,3,4,5 };
    int array3 [ ] = { 1,2,0,4,5 };
    IO_id ( "Method_07 - v0.0" );
    IO_println ( "\nArray1" );
    printlntArray ( n, array1 );
    IO_printf ( "isAllZeros (array1) = %d", isAllZeros (n, array1) );
    IO_println ( "\nArray2" );
    printlntArray ( n, array2 );
    IO_printf ( "isAllZeros (array2) = %d", isAllZeros (n, array2) );
    IO_println ( "\nArray3" );
    printlntArray ( n, array3 );
    IO_printf ( "isAllZeros (array3) = %d", isAllZeros (n, array3) );
    IO_pause ( "Apertar ENTER para continuar" );
} 
void addIntArray ( int n, int array3 [ ], int array1 [ ], int k, int array2 [ ] )
{
    int x = 0;
    for ( x=0; x<n; x=x+1 )
    {
        array3 [ x ]= array1 [ x ] + k * array2 [ x ];
    } 
} 
void method08 ( )
{
    int n = 0;
    IO_id ( "Method_08 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        int other [ n ];
        int sum [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        copyIntArray ( n, other, array );
        IO_printf ( "\nOriginal\n" );
        printlntArray ( n, array );
        IO_printf ( "\nCopia\n" );
        printlntArray ( n, other );
        addIntArray ( n, sum, array, (-2), other );
        IO_printf ( "\nSoma\n" );
        printlntArray ( n, sum );
    }
    IO_pause ( "Apertar ENTER para continuar" );
} 
bool isEqual ( int n, int array1 [ ], int array2 [ ] )
{
    bool result = true;
    int x = 0;
    x = 0;
    while ( x<n && result )
    {
        result = result && ( array1 [ x ] == array2 [ x ] );
        x = x + 1;
    } 
    return ( result );
} 
void method09 ( )
{
    int n = 0;
    IO_id ( "Method_09 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        int other [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        copyIntArray ( n, other, array );
        IO_printf ( "\nOriginal\n" );
        printlntArray ( n, array );
        IO_printf ( "\nCopia\n" );
        printlntArray ( n, other );
        IO_printf ( "\nIguais = %d\n", isEqual ( n, array, other ) );
        other [ 0 ] = (-1) * other [ 0 ];
        IO_printf ( "\nCopia alterada\n" );
        printlntArray ( n, other );
        IO_printf ( "\nIguais = %d\n", isEqual ( n, array, other ) );
    } 
IO_pause ( "Apertar ENTER para continuar" );
} 
bool searchArray ( int value, int n, int array [ ] )
{
    bool result = false;
    int x = 0;
    x = 0;
    while ( x<n && ! result )
    {
        result = ( value == array [ x ] );
        x = x + 1;
    } 
    return ( result );
} 
void method10 ( )
{
    int n = 0; 
    int value = 0; 
    IO_id ( "Method_10 - v0.0" );
    n = freadArraySize ( "ARRAY1.TXT" );
    if ( n <= 0 )
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [ n ];
        freadIntArray ( "ARRAY1.TXT", n, array );
        IO_printf ( "\nOriginal\n" );
        printlntArray ( n, array );
        value = array [ 0 ];
        IO_printf ( "\nProcurar por (%d) = %d\n", 
        value, searchArray ( value, n, array ) );
        value = array [ n / 2 ];
        IO_printf ( "\nProcurar por (%d) = %d\n", 
        value, searchArray ( value, n, array ) );
        value = array [ n - 1 ];
        IO_printf ( "\nProcurar por (%d) = %d\n", 
        value, searchArray ( value, n, array ) );
        value = (-1);
        IO_printf ( "\nProcurar por (%d) = %d\n", 
        value, searchArray ( value, n, array ) );
    } 
    IO_pause ( "Apertar ENTER para continuar" );
} 
/* Incluir um método (0811) para
ler o tamanho de um arranjo para inteiros do teclado,
bem como todos os seus elementos, garantindo que só tenha valores positivos e ímpares.
Verificar se o tamanho (ou dimensão) não é nulo ou negativo.
Para testar, ler diferentes quantidades de dados.*/
void m11(int x, int array[])
{
    for(int i = 0; i < x; i++)
    {
        printf("\nValor do array: ");
        scanf("%d", &array[i]);
        while(array[i] % 2 == 0 || array[i] < 0)
        {
            printf("O valor deve ser impar, positivo e verdadeiro. Digite de novo: \n");
            scanf("%d", &array[i]);
        }
        
    }
    printf("Valores do array: ");
    for(int i = 0; i < x; i++)
    {
        printf("\n%d\n", array[i]);
    }
}
void method11()
{
    
    int x = 0;
    printf("\nDigite o tamanho do array: ");
    scanf("%d", &x);
    while(x < 0)
    {
        printf("A quantidade do array deve ser maior que 0, tente novamente: ");
        scanf("%d", &x);
    }
    int array[x];
    m11(x, array);
}
/*ler um arranjo com inteiros positivos de arquivo.
Valores negativos e também os pares deverão ser descartados.
O arranjo e o nome do arquivo serão dados como parâmetros.
Guardar, em arquivo primeiro o tamanho, depois os elementos, um dado por linha.
Para testar, ler diferentes nomes e quantidade de dados.
*/
void m12(char filename[])
{
    int quantidade = 0;
    printf("\nDigite a quantidade: ");
    scanf("%d", &quantidade);
    FILE *arquivo = fopen(filename, "r");
    if(arquivo == NULL)
    {
        printf("\nERRO, arquivo nao existe");
        printf("\n");
        return;
    }
    int array[quantidade];
    for(int i = 0; i < quantidade; i++)
    {
        fscanf(arquivo, "%d\n", &array[i]);
        if(array[i] > 0 && array[i] % 2 != 0)
        {
            printf("%d\n", array[i]);
        }
    }
    fclose(arquivo);
}
void method12()
{
    char nomearquivo[50];
    printf("\nDigite o nome do arquivo: ");
    scanf("%s", nomearquivo);
    m12(nomearquivo);
}

/*gerar um valor inteiro aleatoriamente dentro de um intervalo, 
cujos limites de início e de fim serão recebidos como parâmetros;
Para para testar, ler os limites do intervalo do teclado;
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatórios 
dentro do intervalo e armazená-los em arranjo;
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade 
de números aleatórios ( N ) que serão gravados em seguida*/
void m13(int max, int min)
{
    FILE *arquivo = fopen("DADOS.TXT", "w");
    if(arquivo == NULL)
    {
        printf("\nERRO, arquivo nao existe.");
        printf("\n");
        return;
    }
    
    int elementos = 0;
    int valor = 0;
    printf("\nDigite a quantidade de elementos: ");
    scanf("%d", &elementos);
    int array[elementos];
    fprintf(arquivo, "A quantidade de numeros aleatorios eh de: %d\n", elementos);
    for(int i = 0; i < elementos; i++)
    {
        valor = (rand( ) % (max - min)) + min;
        array[i] = valor;
        fprintf(arquivo, "%d\n", array[i]);
        printf("%d\n", valor);
    }
    fclose(arquivo);
}
void method13()
{
    int max = 0;
    int min = 0;
    printf("\nDigite o valor maximo: ");
    scanf("%d", &max);
    printf("\nDigite o valor minimo: ");
    scanf("%d", &min);
    m13(max, min);
}


/*procurar o menor valor ímpar em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e 
aplicar a função sobre o arranjo com os valores lidos;
DICA: Procurar o primeiro valor ímpar da tabela como referência inicial
para o menor valor ímpar.
Exemplo: arranjo = lerArquivo ( n, "DADOS.TXT" );
menor = acharMenorImpar ( n, arranjo );
*/
int m141(int quantidade, int array[])
{
    int numimpar = 0;
    int encontrado = false;
    for(int i = 0; i < quantidade; i++)
    {
        if(array[i] % 2 != 0)
        {
            numimpar = array[i];
            encontrado = true;
            break;
        }
    }
    if(!encontrado)
    {
        printf("Nenhum numero impar foi encontrado.");
        return -1;
    }
    else
    {
        for(int i = 0; i < quantidade; i++)
        {
            if(array[i] % 2 != 0 && array[i] < numimpar)
            {
                numimpar = array[i];
            }
        }
        return numimpar;
    }
}
void m142(chars filename)
{
    int quantidade = 0;
    printf("Digite a qunatidade: ");
    scanf("%d", &quantidade);
    FILE *arquivo = fopen(filename, "r");
    if(arquivo == NULL)
    {
        printf("\nERRO, arquivo nao existe.");
        printf("\n");
        return;
    }
    fscanf(arquivo, "%d", &quantidade);
    int arranjo[quantidade];

    for (int i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%d", &arranjo[i]);
    }

    fclose(arquivo);

    int menor = m141(quantidade, arranjo);

    if (menor == -1) {
        printf("Nenhum valor ímpar foi encontrado no array lido do arquivo.\n");
    } else {
        printf("O menor valor ímpar do arranjo lido do arquivo é: %d\n", menor);
    }

}
void method14()
{
    char nomearquivo[50];
    printf("\nDigite o nome do arquivo: ");
    scanf("%s", nomearquivo);
}
void method15()
{

}
void m16(int quantidade, char filename[])
{
    FILE *arquivo = fopen(filename, "r");
    FILE *arquivo2 = fopen("DADOS.TXT", "w");
    int array[quantidade];
    int num = 0;
    if (arquivo == NULL || arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for(int i = 0; i < quantidade; i++)
    {
        fscanf(arquivo, "%d", &array[i]);
        num += array[i];
    }
    num /= quantidade;
    printf("Media: %d", num);
    fprintf(arquivo2, "Media: %d", num);
    printf("Numeros acima da media: ");
    fprintf(arquivo2, "Numeros acima da media: ");
    
    for(int i = 0; i < quantidade; i++)
    {
        
        if(array [i] < num)
        {
            printf("%d: %d", i, array[i]);
            fprintf(arquivo, "%d: %d", i, array[i]);
        }
        
    }
    
    printf("Numeros abaixo da media: ");
    fprintf(arquivo2, "Numeros abaixo da media: ");
    
    for(int i = 0; i < quantidade; i++)
    {
        
        if(array [i] > num)
        {
            printf("%d: %d", i, array[i]);
            fprintf(arquivo, "%d: %d", i, array[i]);
        }
        
    }
    fclose(arquivo);
    fclose(arquivo2);
}
void method16()
{
    chars nomearquivo;
    int quantidade = 0;
    printf("\nDigite a quantidade: ");
    scanf("%d", &quantidade);
    printf("\nDe um nome para o arquivo: ");
    scanf("%s", nomearquivo);
    m16(quantidade, nomearquivo);
}
bool estaOrdenadoDecrescente(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
    }
    return true;
}
void m17()
{
    int array1[] = {10, 8, 5, 3, 1}; // Array ordenado em ordem decrescente
    int array2[] = {1, 3, 5, 8, 10}; // Array não ordenado em ordem decrescente

    if (estaOrdenadoDecrescente(array1, 5)) {
        printf("O array1 esta ordenado em ordem decrescente.\n");
    } else {
        printf("O array1 nao esta ordenado em ordem decrescente.\n");
    }

    if (estaOrdenadoDecrescente(array2, 5)) {
        printf("O array2 esta ordenado em ordem decrescente.\n");
    } else {
        printf("O array2 nao esta ordenado em ordem decrescente.\n");
    }

}
void method17()
{
    m17( );
}




int lerDadosArquivo(const char *nomeArquivo, int arr[]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(arquivo, "%d", &arr[i]) != EOF && i < MAX_SIZE) {
        i++;
    }

    fclose(arquivo);
    return i; // retorna o número de elementos lidos
}

bool procurarValor(int arr[], int tamanho, int valor, int posicaoInicial) {
    for (int i = posicaoInicial; i < tamanho; i++) {
        if (arr[i] == valor) {
            printf("O valor %d foi encontrado na posição %d.\n", valor, i);
            return true;
        }
    }
    printf("O valor %d nao foi encontrado a partir da posição indicada.\n", valor);
    return false;
}

void m18() {
    int arr[MAX_SIZE];
    int tamanho = lerDadosArquivo("DADOS.TXT", arr);

    if (tamanho == 0) {
        printf("O valor tem que ser maior que 0");
    }

    int valorProcurado, posicaoInicial;
    printf("Digite o valor inteiro a ser procurado: ");
    scanf("%d", &valorProcurado);
    printf("Digite a posicao inicial para comecar a procura: ");
    scanf("%d", &posicaoInicial);

    if (procurarValor(arr, tamanho, valorProcurado, posicaoInicial)) {
        printf("O valor foi encontrado no arranjo a partir da posicao indicada.\n");
    } else {
        printf("O valor nao foi encontrado no arranjo a partir da posicao indicada.\n");
    }
}

void method18() {
    m18();
}






int* ler(int *n, const char* fileName) {
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    int *arranjo = (int *)malloc(MAX_SIZE * sizeof(int));
    int i = 0;

    while (fscanf(file, "%d", &arranjo[i]) != EOF) {
        i++;
    }

    *n = i;

    fclose(file);
    return arranjo;
}

int acharPosicao(int procurado, int posicaoInicial, int n, int* arranjo) {
    for (int i = posicaoInicial; i < n; i++) {
        if (arranjo[i] == procurado) {
            return i;
        }
    }
    return -1; 
}
void method19()
{
    /*
    int n;
    int *arranjo = lerArquivo(&n, "DADOS.TXT");

    int procurado;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &procurado);

    int onde = acharPosicao(procurado, 0, n, arranjo);

    if (onde != -1) {
        printf("O valor %d foi encontrado na posição %d do arranjo.\n", procurado, onde);
    } else {
        printf("O valor %d não foi encontrado no arranjo.\n", procurado);
    }

    free(arranjo); // Não se esqueça de liberar a memória alocada dinamicamente.
    */

}




/*
int* ler(int *n, const char* fileName) {
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    int *arranjo = (int *)malloc(MAX_SIZE * sizeof(int));
    int i = 0;

    while (fscanf(file, "%d", &arranjo[i]) != EOF) {
        i++;
    }

    *n = i;

    fclose(file);
    return arranjo; 
}*/

int acharQuantos(int procurado, int posicaoInicial, int n, int* arranjo) {
    int count = 0;
    for (int i = posicaoInicial; i < n; i++) {
        if (arranjo[i] == procurado) {
            count++;
        }
    }
    return count;
}
void method20() 
{
    
}
/*
void method20() {
    int n;
    int arranjo = lerArquivo(&n, "DADOS.TXT");

    int procurado;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &procurado);

    int vezes = acharQuantos(procurado, 0, n, arranjo);

    if (vezes > 0) {
        printf("O valor %d aparece %d vezes no arranjo.\n", procurado, vezes);
    } else {
        printf("O valor %d não foi encontrado no arranjo.\n", procurado);
    }

    free(arranjo); // Não se esqueça de liberar a memória alocada dinamicamente.
}*/

void method21a( )
{
    FILE *arquivo = fopen("DIVISORES.TXT", "w");
    if (arquivo == NULL) 
    {
        printf("\nERRO: Não foi possível abrir o arquivo.");
        return;
    }
    int num = 0;
    int a = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &num);
    int *divisores = (int*) malloc(num * sizeof(int));
    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            divisores[a] = i;
            printf("\nDivisores = %d", i);
            fprintf(arquivo, "\n%d", divisores[a]);
        }
        a++;
    }
    free(divisores);
    fclose(arquivo);
}
void method21( )
{
    method21a( );
}
int main(void)
{
    int x = 0;
    printf ( "%s\n", "Exemplo0821 - Programa = v0.0" );
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
        printf ( "\n%s" , "15 - Method_15" );
        printf ( "\n%s" , "16 - Method_16" );
        printf ( "\n%s" , "17 - Method_17" );
        printf ( "\n%s" , "18 - Method_18" );
        printf ( "\n%s" , "19 - Method_19" );
        printf ( "\n%s" , "20 - Method_20" );
        printf ( "\n%s" , "21 - Extra_21" );
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
            case 15: 
                method15 ( ); 
                break;
            case 16: 
                method16 ( ); 
                break;
            case 17:
                method17 ( ); 
                break;
            case 18: 
                method18 ( ); 
                break;
            case 19: 
                method19 ( ); 
                break;
            case 20: 
                method20 ( ); 
                break;
            case 21: 
                method21 ( ); 
                break;
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( x != 0 );
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    return ( 0 );
}