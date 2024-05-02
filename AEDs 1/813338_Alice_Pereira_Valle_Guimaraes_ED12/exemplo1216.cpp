#include "mymatrix.hpp"
void method00()
{
    
}
void method01()
{
    // chama o construtor de matrix e faz uma matrix de int
    Matrix<int> int_matrix(2, 2, 0);
    // primeiro numero = linha, segundo numero = colunas, terceiro numero = valor da posição
    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);
    cout << "\nMethod_01 - v0.0\n" << endl;
    // exibir a matrix
    int_matrix.print();
    pause ( "Apertar ENTER para continuar" );
}
void method02()
{
    Matrix <int> matrix (2, 2, 0);
    cout << endl << "\nMethod_02 - v0.0" << endl;
    // pede o valor para a matrix
    matrix.read();
    // exibe a matrix
    matrix.print();
    pause ( "Apertar ENTER para continuar" );
}
void method03()
{
    Matrix <int> matrix(2, 2, 0);
    cout << endl << "Method_03 - v0.0" << endl;
    matrix.read();
    matrix.print();
    matrix.fprint("MATRIX1.TXT");
    pause ( "Apertar ENTER para continuar" );
}
void method04()
{
    Matrix <int> matrix(1, 1, 0);
    cout << endl << "\nMethod_04 - v0.0" << endl;
    // ler dados do arquivo
    matrix.fread("MATRIX1.TXT");
    // mostrar dados
    matrix.print();
    pause ( "Apertar ENTER para continuar" );
}
void method05()
{
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);
    cout << endl << "Method_05 - v0.0" << endl;
    int_matrix1.fread("MATRIX1.TXT");
    cout << "\nOriginal: \n\n";
    int_matrix1.print();
    int_matrix2 = int_matrix1;
    cout << "\nCopia: \n\n";
    int_matrix2.print();
    pause ( "Apertar ENTER para continuar" );
}
void method06()
{
    Matrix <int> int_matrix(2, 2, 0);
    int_matrix.set ( 0, 0, 0 ); 
    int_matrix.set ( 0, 1, 0 );
    int_matrix.set ( 1, 0, 0 ); 
    int_matrix.set ( 1, 1, 0 );
    cout << endl << "Method_06 - v0.0" << endl;
    int_matrix.print();
    cout << "\nZeros = " << int_matrix.isZeros() << endl;
    int_matrix.fread("MATRIX1.TXT");
    int_matrix.print();
    cout << "\nZeros = " << int_matrix.isZeros() << endl;
    pause ( "Apertar ENTER para continuar" );
}
void method07()
{
    Matrix <int> int_matrix1 (1, 1, 0);
    Matrix <int> int_matrix2 (1, 1, 0);
    cout << endl << "Method_07 - v0.0" << endl;
    int_matrix1.fread("MATRIX1.TXT");
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    int_matrix2 = int_matrix1;
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    cout << "\nDiferentes = " << (int_matrix1 != int_matrix2) << endl;
    int_matrix2.set(0, 0, (-1));
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    cout << "\nDiferentes = " << (int_matrix1 != int_matrix2) << endl;
    pause ( "Apertar ENTER para continuar" );
}
// a terceira matrix vai ter o valor de matrix1 - matrix2
void method08()
{
    Matrix <int> int_matrix1 (1, 1, 0);
    Matrix <int> int_matrix2 (1, 1, 0);
    Matrix <int> int_matrix3 (1, 1, 0);
    cout << endl << "Method_08 - v0.0" << endl;
    int_matrix1.fread("MATRIX1.TXT");
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    int_matrix2 = int_matrix1;
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    int_matrix3 = int_matrix1 - int_matrix2;
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    pause ( "Apertar ENTER para continuar" );
}
void method09()
{
    Matrix <int> int_matrix1(2, 2, 0);
    int_matrix1.set(0, 0, 1);
    int_matrix1.set(0, 1, 0);
    int_matrix1.set(1, 0, 0);
    int_matrix1.set(1, 1, 1);
    Matrix <int> int_matrix2 (1, 1, 0);
    Matrix <int> int_matrix3 (1, 1, 0);
    cout << endl << "Method_09 - v0.0" << endl;
    int_matrix2.fread("MATRIX1.TXT");
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    int_matrix3 = int_matrix1 * int_matrix2;
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    pause ( "Apertar ENTER para continuar" );
}
//multiplicar a matrix * -1 deixando a matrix negativa
void method10()
{
    //matrix com 3 linha e 3 colunas e com o valor nulo
    Matrix <int> int_matrix(3, 3, 0);
    cout << endl << "Method_10 - v0.0" << endl;
    int_matrix.fread("MATRIX1.TXT");
    cout << "\nMatrix\n";
    int_matrix.print();
    for(int x = 0; x < int_matrix.getRows(); x++)
    {
        for(int y = 0; y < int_matrix.getColumns(); y++)
        {
            int_matrix.set(x, y, int_matrix.get(x, y) * (-1));
        }
    }
    cout << "\nMatrix\n";
    int_matrix.print();
    pause ( "Apertar ENTER para continuar" );
}
void method11()
{
    int n = 0;
    int l = 0;
    int c = 0;
    int max = 0;
    int min = 0;
    cout << "\nDigite a quantidade de linhas: ";
    cin >> l;
    cout << "\nDigite a quantidade de colunas: ";
    cin >> c;
    cout << "\nDigite a quantidade de numeros aleatorios: ";
    cin >> n;
    cout << "\nDigite o numero minimo: ";
    cin >> min;
    cout << "\nDigite o numero maximo: ";
    cin >> max;
    if(max <= 0 || min <= 0 || n <= 0 || l <= 0 || c <= 0)
    {
        cout << "\nERRO: nenhum dos numeros podem ser menor ou igual a 0, ou menor do q a quantidade da matrix.\n";
    }
    else
    {
        Matrix<int> int_matrix(l, c, 0);
        int_matrix.random(l, c, max, min, n);
    }
}
void method12()
{
    int num = 0;
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);
    cout << "\nDigite um numero: ";
    cin >> num;
    int_matrix1.freadmatrixfromfile("DADOS.TXT");
    int_matrix2 = int_matrix1.scalar(num);
    int_matrix2.print();
}
void method13()
{
    bool teste = false;
    Matrix <int> int_matrix1(1, 1, 0);
    int_matrix1.freadmatrixfromfile("DADOS1.TXT");
    teste = int_matrix1.identidade();
    cout << teste;
    if(teste)
    {
        cout << "\nÉ uma matrix identidade\n";
    }
    else
    {
        cout << "\nNão é uma matrix identidade\n";
    }
}
void method14()
{
    bool teste = false;
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);
    int_matrix1.freadmatrixfromfile ( "DADOS1.TXT" );
    int_matrix2.freadmatrixfromfile ( "DADOS2.TXT" );
    teste = (int_matrix1 == int_matrix2);
    if(teste)
    {
        cout << "\nSão matrix iguais.\n";
    }
    else
    {
        cout << "\nSão matrix diferentes.\n";
    }
}
void method15()
{
    Matrix <int> int_matrix1(1, 1, 0);
    Matrix <int> int_matrix2(1, 1, 0);
    int_matrix1.freadmatrixfromfile ( "DADOS1.TXT" );
    int_matrix2.freadmatrixfromfile ( "DADOS2.TXT" );
    Matrix<int> soma = int_matrix1.add(int_matrix2);
    cout << "\nMatrix 1: \n";
    int_matrix1.print();
    cout << "\nMatrix 2: \n";
    int_matrix2.print();
    cout << "\nSoma: \n";
    soma.print();
}
void method16()
{/*Incluir uma função (1216) para
operar duas linhas da matriz, guardando no lugar da primeira,
as somas de cada elemento da primeira com o respectivo da segunda
multiplicados por uma constante.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix1.addRows ( 0, 1, (-1) )*/
    Matrix <int> int_matrix(1, 1, 0);
    int_matrix.freadmatrixfromfile ( "DADOS1.TXT" );
    int_matrix.addRows(0, 1, (-1));
    int_matrix.print();
}

int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1216 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Metodo 01 " << endl;
        cout << " 2 - Metodo 02 " << endl;
        cout << " 3 - Metodo 03 " << endl;
        cout << " 4 - Metodo 04 " << endl;
        cout << " 5 - Metodo 05 " << endl;
        cout << " 6 - Metodo 06 " << endl;
        cout << " 7 - Metodo 07 " << endl;
        cout << " 8 - Metodo 08 " << endl;
        cout << " 9 - Metodo 09 " << endl;
        cout << " 10 - Metodo 10 " << endl;
        cout << " 11 - Metodo 11 " << endl;
        cout << " 12 - Metodo 12 " << endl;
        cout << " 13 - Metodo 13 " << endl;
        cout << " 14 - Metodo 14 " << endl;
        cout << " 15 - Metodo 15 " << endl;
        cout << " 16 - Metodo 16 " << endl;
        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
        switch ( x )
        {
            case 0: method00 ( ); break;
            case 1: method01 ( ); break;
            case 2: method02 ( ); break;
            case 3: method03 ( ); break;
            case 4: method04 ( ); break;
            case 5: method05 ( ); break;
            case 6: method06 ( ); break;
            case 7: method07 ( ); break;
            case 8: method08 ( ); break;
            case 9: method09 ( ); break;
            case 10: method10 ( ); break;
            case 11: method11 ( ); break;
            case 12: method12 ( ); break;
            case 13: method13 ( ); break;
            case 14: method14 ( ); break;
            case 15: method15 ( ); break;
            case 16: method16 ( ); break;
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch
    }
    while ( x != 0 );
    // encerrar
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}