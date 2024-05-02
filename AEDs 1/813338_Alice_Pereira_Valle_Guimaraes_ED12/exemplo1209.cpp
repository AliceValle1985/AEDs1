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
int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1209 - Programa - v0.0\n " << endl;
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
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch
    }
    while ( x != 0 );
    // encerrar
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}