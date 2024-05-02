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
int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1202 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - Metodo 01 " << endl;
        cout << " 2 - Metodo 02 " << endl;
        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
        switch ( x )
        {
            case 0: method00 ( ); break;
            case 1: method01 ( ); break;
            case 2: method02 ( ); break;
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch
    }
    while ( x != 0 );
    // encerrar
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}