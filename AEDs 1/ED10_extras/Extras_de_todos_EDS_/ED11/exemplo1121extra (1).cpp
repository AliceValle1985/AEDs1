#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_
#include <iostream>
#include <random>
using std::cin;
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;
#include<string>
using std::string;
#include<fstream>
using std::ofstream;
using std::ifstream;
//uma variavel 'T' significa q ela pode receber qualquer valor, float, int, char...
template < typename T >
class Array
{
    private:
    //qualquer valor optional
    T optional;
    //int length
    int length;
    //qualquer valor data
    T *data;
    public:
    //construtor
    Array(int n, T initial)
    {
        optional = initial;
        length = 0;
        //data = a valor nenhum
        data = nullptr;
        //se n for maior que 0
        if(n > 0)
        {
            //length  pega o valor de n
            length = n;
            //data tem a memoria alocado pra se tornar um array com o tamanho de length
            data = new T[length];
        }
    }
    void free( )
    {
        if(data != nullptr)
        {
            delete ( data );
            data = nullptr;
        }
    }
    void set(int position, T value)
    {
        if(0 <= position && position < length)
        {
            data[position] = value;
        }
    }
    //retorna o valor de data
    T get(int position)
    {
       T value = optional;
        if(0 <= position && position < length)
        {
            value = data[position];
        }
        return(value);
    }
    void print()
    {
        cout<<endl;
        for(int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << ":" << setw(9) << data[x] << endl;
        }
        cout << endl;
    }
    //vai ler os valores para o array
    void read()
    {
        cout<< endl;
        for(int x = 0; x < length; x = x + 1)
        {
            //setw vai dar 3 espaços para poder exibir na tela de uma maneira mais armonica
            cout << setw( 3 ) << x << " : ";
            cin >> data[x];
        }
        cout << endl;
    }
    
    void fprint ( string fileName )
    {
        //criando um arquivo para escrita
        ofstream afile; 
        //abrindo o arquivo
        afile.open ( fileName );
        //arquivo recebe length
        afile << length << endl;
        //enquanto x for menor que length vai armazenar o valor de data no arquivo
        for ( int x = 0; x < length; x=x+1 )
        {
            afile << data[ x ] << endl;
        } // end for
        //fechando o arquivo
        afile.close ( );
    } 
    void fread ( string fileName )
    {
        //criando um arquivo para leitura
        ifstream afile; // input file
        int n = 0;
        //abrindo o arquivo com o nome dado a filename
        afile.open ( fileName );
        //afile armazena o valor dentro do arquivo e armazena em n 
        afile >> n;
        //se n for menor que 0 
        if ( n <= 0 )
        {
            //mostrar erro
            cout << "\nERROR: Invalid length.\n" << endl;
        }
        else
        {
            //length fica iguak a n
            length = n;
            //alocar area para o array data
            data = new T [ n ];
            //enquanto x for menor que length, colocar oq tem no arquivo no vetor de data
            for ( int x = 0; x < length; x=x+1 )
            {
                afile >> data[ x ];
            } // end for
        } // end if
        //fechou o arquivo
        afile.close ( );
    }
    Array ( ) // construtor padrao
        {
        // definir valores iniciais
        length = 0;
        // reservar area
        data = nullptr;
    } // end constructor
    // contrutor baseado em copia
    Array ( int length, int other [ ] )
    {
        if ( length <= 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            // criar copia
            this->length = length;
            // reservar area
            data = new T [ this->length ];
            // ler dados
            for ( int x = 0; x < this->length; x=x+1 )
            {
                data [ x ] = other [ x ];
            } // end for
        } // end if
    }
    
    Array ( const Array& other )
    {
        if ( other.length <= 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            // criar copia
            length = other.length;
            // reservar area
            data = new T [ other.length ];
            // ler dados
            for ( int x = 0; x < length; x=x+1 )
            {
                data [ x ] = other.data [ x ];
            } // end for
        } // end if
    } // end constructor ( )
        //recebendo other do q esta privado
    Array& operator= ( const Array <T> other )
    {
        //se o length de other for menor q 0, exibir o erro
        if ( other.length <= 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            //this = ponteiro par ao objeto em que ele esta sendo chamado, no caso esta apontando para length
            this->length = other.length;
            //this = ponteiro data e alocando o valor de length para data com quantidade de length
            this->data = new T [ other.length ];
            //percorre pela data e data recebe o valor de data
            for ( int x = 0; x < this->length; x=x+1 )
            {
                data [ x ] = other.data [ x ];
            } // end for
        } // end if
        return ( *this );
    } // end operator= ( )
    bool operator== ( const Array <T> other )
    {
        //resultado falso
        bool result = false;
        // x = 0
        int x = 0;
        //se length for igual a 0, exibir erro
        if ( other.length == 0 || length != other.length )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            x = 0; 
            //result = verdadeiro
            result = true;
            //enquanto x for menor que length e resultado for verdadeiro
            while ( x < this->length && result )
            {
                //sei la que porra é essa
                result = result && (data [ x ] == other.data [ x ] );
                //x + 1, pra não ficar uma repetição infinita
                x = x + 1;
            } // end while
        } // end if
        //retornar o resultado
        return ( result );
    } // end operator== ( )
    Array& operator+ ( const Array <T> other )
    {
        static Array <T> result ( other );
        if ( other.length <= 0 )
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
            {
            for ( int x = 0; x < this->length; x=x+1 )
            {
                result.data [ x ] = result.data [ x ] + this->data [ x ];
            } 
        } 
        return ( result );
    }
    const int getLength()
    {
        return (length);
    }
    //pegar o valor de data e armazenar em value
    T& operator[](const int position)
    {
        int x = 0;
        static T value = optional;
        // se a posição for menor que 0 ou length for menor ou igual a position, exibir erro
        if((position < 0  && x != 1) || (length <= position && x != 1))
        {
            cout << endl << "\nERROR: Posição invalida.\n" << endl;
            x++;
        }
        else
        {
            //valor = data em uma posição especifica
            value = data [position];
        }
        //retornar o valor de value
        return (value);
    }
    void m11(int n, int max, int min) 
    {
        ofstream afile; 
        afile.open ( "DADOS.TXT" );
        if (!afile.is_open()) 
        {
            cout << "Erro ao abrir o arquivo DADOS.TXT" << endl;
            return;
        }
        srand(time(NULL));
        afile << n << endl;
        for (int i = 0; i < n; i++)
        {
            int x = rand() % (max - min + 1) + min;
            data[i] = x;
            cout<< x << endl;
            afile << data[ i ] << endl;
        }
        afile.close();
    }
    Array<int> readarrayfromfile(string filename)
    {
        Array<int> a(5, 0);
        a.fread("DADOS.TXT");
        return a;
    }
    int searchfirsteven()
    {
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        //n é o tamanho do array
        //0 é o valor q sera inicializado
        Array <int> a (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        int maior = a[0];
        for(int i = 0; i < n; i++)
        {
            if(maior < a[i])
            {
                maior = a[i];
            }
        }
        afile.close();
        return(maior);
    }
    int searchfirstodd()
    {
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        //n é o tamanho do array
        //0 é o valor q sera inicializado
        Array <int> a (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        int menor = a[0];
        for(int i = 0; i < n; i++)
        {
            if(a[i] < menor)
            {
                menor = a[i];
            }
        }
        afile.close();
        return(menor);
    }
    int addinterval ( int inicio, int fim )
    {
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        int soma = 0;
        Array <int> a (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        for(int i = inicio; i <= fim; i++)
        {
            soma = soma + a[i];
        }
        afile.close();
        return (soma);
    }
    int media ( int inicio, int fim )
    {
        int media = 0;
        int n = 0;
        int m = fim - inicio;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        int soma = 0;
        Array <int> a (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        for(int i = inicio; i <= fim; i++)
        {
            soma = soma + a[i];
        }
        media = soma / m;
        afile.close();
        return (media);
    }
    bool positivos( )
    {
        bool vdd = true;
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        Array <int> a (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        for(int i = 0; i <= n; i++)
        {
            if(a[i] < 0)
            {
                
                vdd = false;
            }
        }
        if(vdd == false)
        {
            cout << "\nTem numero negativo nesse array.\n";
        }
        else
        {
            cout << "\nTodos numeros são positivos\n" << endl; 
        }
        afile.close();
        return (vdd);
    }
    bool ordenado()
    {
        bool ord = true;
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        Array <int> a (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        int n1 = a[2];
        int n2 = a[1];
        for(int i = 1; i <= n; i++)
        {
            if(a[i] < a[i - 1])
            {
                ord = false;
                break;
            }
        }
        afile.close();
        if(!ord)
        {
            cout << "\nNão esta na ordem crescente." << endl;
        }
        else
        {
            cout << "\nEsta na ordem crescente." << endl;
        }
        afile.close();
        return (ord);
    }
    bool interval18(int search, int inicio, int fim)
    {
        bool existe = false;
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        int soma = 0;
        Array <int> a (n, 0);
        Array <int> a2 (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        for(int i = inicio; i <= fim; i++)
        {
            if(search == a[i])
            {
                existe = true;
                a2[i] = a[i];
            }
        }
        if(existe == true)
        {
            cout << "\nEsse numero existe dentro do arquivo." << endl;
        }
        else if(existe != true)
        {
            cout << "\nEsse numero não se encontra dentro do arquivo." << endl;
        }
        afile.close();
        return (existe);
    }
    void scalar(int num, int inicio, int fim)
    {
        int desgraca = 0;
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        int soma = 0;
        Array <int> a (n, 0);
        Array <int> a2 (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        cout << "\nNumeros multiplicados: " << endl;
        for(int i = inicio; i <= fim; i++)
        {
            desgraca = a[i] * num;
            cout << desgraca << endl;
        }
        afile.close();
    }
    void crescente()
    {
        int n = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        int soma = 0;
        Array <int> a (n, 0);
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (a[j] > a[j + 1]) 
                {
                    std::swap(a[j], a[j + 1]);
                }
            }
        }
        cout << "Arranjo ordenado em ordem crescente: ";
        for (int i = 0; i < n; ++i) 
        {
            std::cout << a[i] << " ";
        }
    }
    bool diferentes()
    {
        bool igual = false;
        int n = 0;
        int x = 0;
        ifstream afile;
        afile.open("DADOS.TXT");
        afile >> n;
        afile >> x;
        int soma = 0;
        Array <int> a (n, 0);
        Array <int> a2 (n, 0);
        a = readarrayfromfile("DADOS.TXT");
        a2 = readarrayfromfile("DADOS2.TXT");
        if (n != x) 
        {
            cout << "Tamanhos diferentes." << endl;
            return true;
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i] != a2[i])
            {
                return true;
            }  
        }
        return false;
    }
};
#endif
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
void pause(std:: string text)
{
    std::string dummy; // Declaração de uma variável chamada "dummy" do tipo string.
    std::cin.clear(); // Limpa o estado de erro do objeto std::cin, se houver algum.
    std::cout << std::endl << text; // Imprime uma nova linha e, em seguida, o conteúdo de uma variável "text" na saída padrão.
    std::cin.ignore(); // Ignora o próximo caractere a ser lido, se houver, do buffer de entrada padrão.
    std::getline(std::cin, dummy); // Lê uma linha inteira da entrada padrão e armazena na variável "dummy".
    std::cout << std::endl << std::endl; // Imprime duas novas linhas na saída padrão.
}
//#include "myarray.hpp"
using namespace std;
//não faz porra nenhuma
void method00()
{
    
}
//exibe o valor dos arrays
void method01()
{
    //5 = posição e 0 é o valor
    Array <int> int_array ( 5, 0 );
    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);
    cout << "\nMethod_01 - v0.0\n" << endl;
    int_array.print();
    int_array.free();
    pause("Aperte ENTER para continuar.");
}
void method02()
{
    Array <int> Int_array(5, 0);
    cout<< endl << "Method_02 - v0.0" << endl;
    //ler dados
    Int_array.read();
    //exibir dados
    Int_array.print();
    //alocar espaço
    Int_array.free();
    pause("Aperte ENTER para continuar.");
}
void method03()
{
    //criando um array de inteiros com 5 espaços
    Array <int> Int_array (5, 0);
    cout << endl << "Method_03 - v0.0" << endl;
    //recebe o valor para o array
    Int_array.read();
    //grava o array no arquivo "INT_ARRAY1.TXT"
    Int_array.fprint("INT_ARRAY1.TXT");
    //libera o espaço do array
    Int_array.free();
    pause("Aperte ENTER para continuar.");
}
void method04()
{
    Array <int> Int_array (5, 0);
    cout << endl << "Method_04 - v0.0" << endl;
    //ler os numeros do arquivo
    Int_array.fread("INT_ARRAY1.TXT");
    //exibir o array
    Int_array.print();
    Int_array.free();
    pause ( "Apertar ENTER para continuar" );
}
void method05()
{
    int other[] = {1, 2, 3, 4, 5};
    Array <int> int_array(5, other);
    cout << endl << "Method_05 - v0.0" << endl;
    cout << "\nCopla\n" << endl;
    int_array.print();
    int_array.free();
    // encerrar
    pause ( "Apertar ENTER para continuar" );
}
void method06()
{
    //cria uma variavel com o nome de array 1
    //transforma o int_array pra ser um array
    Array <int> int_array1 (1, 0);
    cout << endl << "Method_06 - v0.0" << endl;
    //leoq esta em INT_ARRAY1.TXT e armazena em fread
    int_array1.fread("INT_ARRAY1.TXT");
    //Original
    cout << "\nOriginal\n" << endl;
    //printa o array1 na tela
    int_array1.print();
    //cria outra variavel com o nome de array2 
    Array <int> int_array2(int_array1);
    //copia
    cout << "\nCopia\n" << endl;
    //exibe o array2 na tela
    int_array2.print();
    //libera array1
    int_array1.free();
    //libera array2
    int_array2.free();
    // encerrar
    pause ( "Apertar ENTER para continuar" );
}
void method07()
{
    Array <int> int_array1(1, 0);
    Array <int> int_array2(1, 0);
    cout << endl << "Method_07 - v0.0" << endl;
    int_array1.fread("INT_ARRAY1.TXT");
    cout << "\nOriginal\n" << endl;
    int_array1.print();
    int_array2 = int_array1;
    cout << "\nCopia\n" << endl;
    int_array2.print();
    // reciclar espaco
    int_array1.free ( ); 
    int_array2.free ( ); 
    // encerrar
    pause ( "Apertar ENTER para continuar" );
}
void method08()
{
    int other [] = {1, 2, 3};
    Array <int> int_array1 (3, other);
    Array <int> int_array2 (3, other);
    int x;
    cout << endl << "Method_08 - v0.0" << endl;
    cout << endl;
    cout<< "Array_1";
    int_array1.print();
    cout << "Array_2";
    int_array2.print();
    //o == é como se fosse uma função 
    cout << "\nIgualdade = " << (int_array1 == int_array2) << endl;
    int_array1.free();
    int_array2.free();
    // encerrar
    pause ( "Apertar ENTER para continuar" );
}
void method09 ( )
{
    Array <int> int_array1 ( 1, 0 );
    Array <int> int_array2 ( 1, 0 );
    Array <int> int_array3 ( 1, 0 );
    cout << endl << "EXEMPLO1110 - Method_09 - v0.0" << endl;
    int_array1.fread ( "INT_ARRAY1.TXT" );
    int_array2 = int_array1;
    int_array3 = int_array2 + int_array1;
    cout << endl;
    cout << "Original" << endl;
    int_array1.print ( );
    cout << "Copia" << endl;
    int_array2.print ( );
    cout << "Soma" << endl;
    int_array3.print ( );
    int_array1.free ( ); 
    int_array2.free ( ); 
    int_array3.free ( ); 
    pause ( "Apertar ENTER para continuar" );
}
void method10()
{
    int other[] = {1, 2, 4, 5};
    Array <int> int_array(5, other);
    int x;
    cout << endl << "Method_10 - v0.0" << endl;
    for(x = 0; x < int_array.getLength(); x = x + 1)
    {
        cout << endl << setw(3) << x << ":" << int_array [x];
    }
    cout << endl << "\nFora dos limites: ";
    cout << endl << "[-1]: " << int_array.get(-1) << endl;
    cout << endl << "[" << int_array.getLength( ) << "]: " << int_array [ int_array.getLength( ) ] << endl;
    // encerrar
    pause ( "Apertar ENTER para continuar" );
}

void method11()
{
    int n = 0;
    int max = 0;
    int min = 0;
    cout << "\nQuantidade de valores a serem gerados: ";
    cin >> n;
    cout << "\nValor mínimo gerado: ";
    cin >> min;
    cout << "\nValor máximo gerado: ";
    cin >> max;
    Array <int> a (n, 0);
    a.m11(n, max, min);
}
void method12()
{
    int maior = 0;
    Array <int> a (5, 0);
    maior = a.searchfirsteven();
    cout << "\nO maior numero do array é: " << maior << endl;
}
void method13()
{
    int menor = 0;
    Array <int> a (5, 0);
    menor = a.searchfirstodd();
    cout << "\nO menor numero do array é: " << menor << endl;
}
void method14()
{
    int inicio = 0;
    int fim    = 0;
    int soma   = 0;
    Array <int> a (5, 0);
    cout << "\nDigite a posição inicial: ";
    cin >> inicio;
    cout << "\nDigite a posição final: ";
    cin >> fim;
    soma = a.addinterval(inicio, fim);
    cout << "\nSoma das posições: " << soma << endl;
    
}
void method15()
{
    int inicio = 0;
    int fim    = 0;
    int media   = 0;
    Array <int> a (5, 0);
    cout << "\nDigite a posição inicial: ";
    cin >> inicio;
    cout << "\nDigite a posição final: ";
    cin >> fim;
    media = a.media(inicio, fim);
    cout << "\nMedia das posições: " << media << endl;
    
}
void method16()
{
    bool teste = false;
    Array <int> a (5, 0);
    teste = a.positivos( );
}
void method17()
{
    bool teste = false;
    Array <int> a (5, 0);
    teste = a.ordenado( );
}
void method18()
{
    bool existe = false;
    int search = 0;
    int inicio = 0;
    int fim    = 0;
    Array <int> a (5, 0);
    cout << "\nDigite a posição inicial: ";
    cin >> inicio;
    cout << "\nDigite a posição final: ";
    cin >> fim;
    cout << "\nDigite o numero procurado: ";
    cin >> search;
    existe = a.interval18(search, inicio, fim);
}
void method19()
{
    int num    = 0;
    int inicio = 0;
    int fim    = 0;
    Array <int> a (5, 0);
    Array <int> novo (5, 0);
    cout << "\nDigite a posição inicial: ";
    cin >> inicio;
    cout << "\nDigite a posição final: ";
    cin >> fim;
    cout << "\nDigite o numero para multiplicar: ";
    cin >> num;
    a.scalar(num, inicio, fim);
}
void method20()
{
    Array <int> a (5, 0);
    a.crescente( );
}
void method21()
{
    bool iguais = true;
    Array <int> a (5, 0);
    iguais = a.diferentes();
    if(iguais == true)
    {
        cout << "\nTodos os valores são iguais." << endl; 
    }
    else if(iguais == false)
    {
        cout << "\nTem valores diferentes." << endl;
    }
}
int main ( int argc, char** argv )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1121 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - metodo 1" << endl;
        cout << " 2 - metodo 2" << endl;
        cout << " 3 - metodo 3" << endl;
        cout << " 4 - metodo 4" << endl;
        cout << " 5 - metodo 5" << endl;
        cout << " 6 - metodo 6" << endl;
        cout << " 7 - metodo 7" << endl;
        cout << " 8 - metodo 8" << endl;
        cout << " 9 - metodo 9" << endl;
        cout << "10 - metodo 10" << endl;
        cout << "11 - exercicio 13" << endl;
        cout << "12 - exercicio 12" << endl;
        cout << "13 - exercicio 13" << endl;
        cout << "14 - exercicio 14" << endl;
        cout << "15 - exercicio 15" << endl;
        cout << "16 - exercicio 16" << endl;
        cout << "17 - exercicio 17" << endl;
        cout << "18 - exercicio 18" << endl;
        cout << "19 - exercicio 19" << endl;
        cout << "20 - exercicio 20" << endl;
        cout << "21 - extra 21" << endl;
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
            case 17: method17 ( ); break;
            case 18: method18 ( ); break;
            case 19: method19 ( ); break;
            case 20: method20 ( ); break;
            case 21: method21 ( ); break;
            default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch
    }
    while ( x != 0 );
    // encerrar
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}