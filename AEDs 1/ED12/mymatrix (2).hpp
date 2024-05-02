#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_
#include <iostream>
using std::cin;
using std::cout;
using std:: endl;
#include <iomanip>
using std:: setw; 
#include <string>
using std:: string;
#include <fstream>
using std::ofstream;
using std::ifstream;

void pause(std:: string text)
{
    std::string dummy; // Declaração de uma variável chamada "dummy" do tipo string.
    std::cin.clear(); // Limpa o estado de erro do objeto std::cin, se houver algum.
    std::cout << std::endl << text; // Imprime uma nova linha e, em seguida, o conteúdo de uma variável "text" na saída padrão.
    std::cin.ignore(); // Ignora o próximo caractere a ser lido, se houver, do buffer de entrada padrão.
    std::getline(std::cin, dummy); // Lê uma linha inteira da entrada padrão e armazena na variável "dummy".
    std::cout << std::endl << std::endl; // Imprime duas novas linhas na saída padrão.
}

template <typename T>
class Matrix
{
    private:
    T optional;
    int rows;
    int columns;
    T** data;
    public:
    Matrix()
    {
        //apontando diretamente para rowns q esta no privado da classe
        this->rows    = 0;
        this->columns = 0;
        data = nullptr;
    }//final do contrutor matrix
    //faz a matrix
    Matrix (int rows, int columns, T initial)
    {
        bool OK = true;
        //optional, rows e columns esta sendo apontado diretamente pelo this
        this->optional = initial;
        this->rows     = rows;
        this->columns  = columns;
        //fazendo um array de data com a quantidade de linhas
        data = new T*[rows];
        if(data != nullptr)
        {
            for(int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
                OK = OK && (data[x] !=nullptr);
            }
            if(! OK)
            {
                data = nullptr;
            }
        }
    }//final do construtor matrix
    //liberar o espoça dos dados da matrix
    ~Matrix()
    {
        if(data != nullptr)
        {
            for(int x = 0; x < rows; x = x + 1)
            {
                delete(data[x]);
            }
            delete (data);
            data = nullptr;
        }
    }
    void set(int row, int column, T value)
    {
        if(row < 0 || row >= rows || column >= columns)
        {
            cout << "\nERRO: posição invalida\n";
        }
        else
        {
            data[row][column] = value;
        }
    }
    T get(int row, int column)
    {
        T value = optional;
        if(row < 0 || row >= rows || column < 0 || column >= columns)
        {
            cout << "\nERRO: posição invalida\n";
        }
        else
        {
            value = data [row][column];
        }
        return (value);
    }
    // exibe a matrix na tela
    void print()
    {
        cout << endl;
        for(int x = 0; x < rows; x = x + 1)
        {
            for(int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    // recebe o valor da matrix exibindo a posição onde o valor vai estar
    void read()
    {
        cout << endl;
        for(int x = 0; x < rows; x = x + 1)
        {
            for(int y = 0; y < columns; y = y + 1)
            {
                cout << setw(2) << x << ", " << setw(2) << y << ": ";
                cin >> data[x][y];
            }
        }
        cout << endl;
    }
    // grava a matrix no arquivo
    void fprint (string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << rows    << endl;
        afile << columns << endl;
        for(int x = 0; x < rows; x = x + 1)
        {
            for(int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            }
        }
        afile.close();
    }
    // le matrix do arquivo
    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open(fileName);
        // m recebe valor do arquivo 
        // m = rows
        afile >> m;
        // n recebe valor do arquivo
        // n = columns
        afile >> n;
        if(m <= 0 || n <= 0)
        {
            cout << "\nERRO: dimensões erradas para a matrix.\n" << endl;
        }
        else
        {
            rows    = m;
            columns = n;
            data = new T*[rows];
            for(int x = 0; x < rows; x++)
            {
                data[x] = new T[columns];
            }
            for(int x = 0; x < rows; x++)
            {
                for(int y = 0; y < columns; y++)
                {
                    afile >> data[x][y];
                }
            }
        }
        afile.close();
    }
    Matrix& operator= (const Matrix <T> &other)
    {
        /*
            other =
            T optional;
            int rows;
            int columns;
            T** data;
            
            pq recebeu os valores da matrix
        */
        if(other.rows == 0 || other.columns == 0)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            // acessa diretamente rows da classe com o nome de other
            this->rows    = other.rows;
            this->columns = other.columns;
            this->data    = new T*[rows];
            for(int  x = 0; x < rows; x++)
            {
                this->data[x] = new T[columns];
            }
            for(int  x = 0; x < rows; x++)
            {
                for(int y = 0; y < columns; y++)
                {
                    data[x][y] = other.data[x][y];
                }
            }
        }
        return (*this);
    }
    //testa de a matrix só contem zeros
    bool isZeros()
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if(rows > 0 && columns > 0)
        {
            result = true;
            while(x < rows && result)
            {
                y = 0;
                while(y < columns && result)
                {
                    result = result && (data[x][y] == 0);
                    y = y + 1;
                }
            }
        }
        return (result);
    }
    // cerve para verificar de duas variaveis são diferentes
    bool operator!=(const Matrix <T> &other)
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if(other.rows == 0 || rows != other.rows || other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            x = 0;
            while(x < rows && ! result)
            {
                y = 0;
                while(y < columns && ! result)
                {
                    /*A expressão result = (data[x][y] != other.data[x][y]); compara os valores nos elementos correspondentes de duas matrizes (data e other.data) na posição (x, y). O resultado da comparação (data[x][y] != other.data[x][y]) é um valor booleano (true ou false), indicando se os valores são diferentes.

A expressão dentro dos parênteses, (data[x][y] != other.data[x][y]), avalia se o elemento na posição (x, y) da matriz data é diferente do elemento correspondente na matriz other.data. Se os elementos são diferentes, a expressão resulta em true; se forem iguais, a expressão resulta em false.

Esse valor booleano é então atribuído à variável result. Portanto, após essa linha de código ser executada, result conterá o resultado da comparação entre os elementos (x, y) das duas matrizes.*/
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                }
                x = x + 1;
            }
        }
        return (result);
    }
    Matrix& operator- (const Matrix <T> &other)
    {
        static Matrix <T> result (1, 1, 0);
        if(other.rows == 0 || rows != other.rows || other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            // criando um array para data
            result.data = new T* [result.rows];
            for ( int x = 0; x < result.rows; x=x+1 )
            {
                result.data [x] = new T [ result.columns ];
            }
            for(int x = 0; x < result.rows; x++)
            {
                for(int y = 0; y < result.columns; y++)
                {
                    result.data[x][y] = data[x][y] - other.data[x][y];
                }
            }
        }
        return (result);
    }
    // soma duas matrixs
    Matrix& operator* (const Matrix <T> &other)
    {
        static Matrix <T> result (1, 1, 0);
        int x   = 0;
        int y   = 0;
        int z   = 0;
        int sum = 0;
        if(other.rows == 0 || rows != other.rows || other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
            result.data[0][0] = 0;
        }
        else
        {
            result.rows    = rows;
            result.columns = other.columns;
            result.data    = new T* [result.rows];
            for(int a = 0; a < result.rows; a++)
            {
                result.data[a] = new T [result.columns];
            }
            for(x = 0; x < result.rows; x++)
            {
                for(y = 0; y < result.columns; y++)
                {
                    sum = 0;
                    for(z = 0; z < columns; z++)
                    {
                        sum = sum + data[x][z] * other.data[z][y];
                    }
                    result.data[x][y] = sum;
                }
            }
        }
        return (result);
    }
    const int getRows()
    {
        return (rows);
    }
    const int getColumns()
    {
        return (columns);
    }
    void random(int l, int c, int max, int min, int n)
    {
        Matrix <T> int_matrix (l, c, 0);
        ofstream afile;
        afile.open("DADOS.TXT");
        cout << endl;
        srand(time(NULL));
        afile << n << endl;
        int_matrix.rows = l;
        int_matrix.columns = c;
        afile << rows    << endl;
        afile << columns << endl;
        for(int x = 0; x < l; x = x + 1)
        {
            for(int y = 0; y < c; y = y + 1)
            {
                for(int a = 0; a < n; a++)
                {
                    int z = rand() % (max - min + 1) + min;
                    cout << z << endl;
                    data[x][y] = z;
                    afile << data[x][y] << endl;
                }
            }
        }
        afile.close();
    }
     void freadmatrixfromfile(string fileName) {
        ifstream afile;
        afile.open(fileName);
        afile >> this->rows;
        afile >> this->columns;
        this->data = new int*[this->rows];
        for (int i = 0; i < this->rows; i++) 
        {
            this->data[i] = new int[this->columns];
        }

        for(int x = 0; x < this->rows; x++) 
        {
            for(int y = 0; y < this->columns; y++) 
            {
                afile >> this->data[x][y];
            }
        }
        afile.close();
    }

    Matrix<int> scalar(int n) {
        Matrix<int> int_matrix(this->rows, this->columns, 0);

        for(int x = 0; x < this->rows; x++) {
            for(int y = 0; y < this->columns; y++) {
                int_matrix.data[x][y] = this->data[x][y] * n;
            }
        }
        return int_matrix;
    }
    bool identidade()
    {
        this->data = new int*[this->rows];
        for (int i = 0; i < this->rows; i++) 
        {
            this->data[i] = new int[this->columns];
        }
        if (this->data == nullptr) 
        {
            return false;
        }
        for(int x = 0; x < this->rows; x++) 
        {
            for(int y = 0; y < this->columns; y++) 
            {
                if(this->data[x][y] != 1 || this->data[x][y] != 0)
                {
                    return false;
                    break;
                }
            }
        }
        return true;
    }
    bool operator==(const Matrix<T>& other) const {
        if (this->rows != other.rows || this->columns != other.columns) 
        {
            return false;
        }

        for (int i = 0; i < this->rows; ++i) 
        {
            for (int j = 0; j < this->columns; ++j) 
            {
                if (this->data[i][j] != other.data[i][j]) 
                {
                    return false;
                }
            }
        }
        return true;
    }
    Matrix <T> add(Matrix <T> &other)
    {
        Matrix <T> result(this-> rows, this-> columns, 0);
        if (this->rows == other.rows && this->columns == other.columns)
        {
            for(int x = 0; x < this->rows; x++)
            {
                for(int y = 0; y < this->columns; y++)
                {
                    result.data[x][y] = this->data[x][y] + other.data[x][y];
                }
            }
        }
        return result;
    }
    void addRows(int primeiralinha, int segundalinha, int constant)
    {
        
        if(primeiralinha < 0 || segundalinha < 0)
        {
            cout<< "\nERRO: posição invalida.";
        }
        else
        {
            for(int i = 0; i < columns; i++)
            {
                this->data[primeiralinha][i] = this->data[primeiralinha][i] + (this->data[segundalinha][i] * constant);
            }
        }
    }
    void subtractRows(int primeiral, int segundal, int constant)
    {
        if(primeiral < 0 || segundal < 0)
        {
            cout << "\nERRO: O valor das linhas não podem ser menor que 0\n";
        }
        else
        {
            for(int i = 0; i < columns; i ++)
            {
                this->data[primeiral][i] = (this->data[primeiral][i] - (this->data[segundal][i] * constant)) * (-1);
            }
        }
    }
    bool searchRows(int search)
    {
        bool tem = false;
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->rows; j++)
            {
                if(this->data[i][j] == search)
                {
                    tem = true;
                    cout << search << " esta na linha " << i;
                }
            }
        }
        return (tem);
    }
    bool searchColumns(int search)
    {
        bool tem = false;
        for(int i = 0; i < this->columns; i++)
        {
            for(int j = 0; j < this->columns; j++)
            {
                if(this->data[i][j] == search)
                {
                    tem = true;
                    cout << "\n";
                    cout << search << " esta na coluna " << j;
                }
            }
        }
        return (tem);
    }
    void transpose()
    {
        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->columns; j++)
            {
                this->data[j][i] = this->data[i][j];
            }
        }
    }
    bool extra1()
    {
        bool trem = false;
        if(this->rows != this->columns)
        {
            cout << "\nA matrix não é quadrada.\n";
            exit(0);
        }
        else
        {
            cout << "\nA matrix é quadrada.\n";
            for(int i = 0; i < this->rows; i++)
            {
                for(int j = 0; j < this->columns; j++)
                {
                    if(this->data[i][j] != this->data[i][j - 1] + 1 && this->data[i][j] != this->data[i - 1][j] + 1)
                    {
                        trem = true;
                    }
                    else
                    {
                        trem = false;
                    }
                }
            }
        }
        return (trem);
    }
    void extra2(int max)
    {
        int x = 1;
        if(this->rows != this->columns)
        {
            cout<< "\nO numero de linhas não pode ser diferente do numero de colunas.\n";
        }
        else
        {
            for(int i = 0; i < this->rows; i++)
            {
                for(int j = 0; j < this->columns; j++)
                {
                    if(x <= max)
                    {
                        this->data[j][i] = x;
                        x++;
                    }
                }
            }
        }
    }
};
#endif