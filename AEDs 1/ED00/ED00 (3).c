//1458201_AED1
// Modelo de Lista para testar métodos
#include "io.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <stdbool.h> 

//metodo 1
int method_01 (void)
{
    printf ( "\n%s\n", "EXEMPLO0101 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( 0 );
}
//metodo 2
int method_02 (void)
{

    system ( "cls" );
    printf ( "\n%s\n", "EXEMPLO0102 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 3
int method_03 (void)
{
     printf ( "\n%s\n", "EXEMPLO0103 - PRIMEIRO EXEMPLO EM C" );
     IO_clrscr ( ); // para limpar a tela
     printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
     printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
     getchar( ); // para esperar
 return ( EXIT_SUCCESS );
}
//metodo 4
int method_04 (void)
{

    printf ( "\n%s\n", "EXEMPLO0104 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n" ); 
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "\n" );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
return ( EXIT_SUCCESS );
}
//metodo 5
int method_05 (void)
{
    printf ( "\n%s\n", "EXEMPLO0105 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "\nEXEMPLOS DE VALORES : " );
    printf ( "\nCARACTERE : %c", 'A' ); 
    printf ( "\nINTEIRO : %d", 10 ); 
    printf ( "\nREAL : %f", 3.1415 );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 6
int method_06 (void)
{
    const float PI = 3.1415; 
    printf ( "\n%s\n", "EXEMPLO0106 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "\nEXEMPLOS DE VALORES : " );
    printf ( "\nCARACTERE : %c", 'A' ); 
    printf ( "\nINTEIRO : %d", 10 ); 
    printf ( "\nREAL : %f", PI ); 
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 7
int method_07 (void)
{
 
    const float PI = 3.14;
    printf ( "\n%s\n", "EXEMPLO0107 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "\nEXEMPLOS DE VALORES : " );
    printf ( "\nCARACTERE : %c", 'A' ); 
    printf ( "\nINTEIRO : %d", 10 ); 
    printf ( "\nREAL : %f", PI ); 
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 8
int method_08 (void)
{
    const float PI = 3.14; 
    float X = 10.01; 
    printf ( "\n%s\n", "EXEMPLO0108 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "\nEXEMPLOS DE VALORES : " );
    printf ( "\nCARACTERE : %c", 'A' ); 
    printf ( "\nINTEIRO : %d", 10 ); 
    printf ( "\nREAL : %f", PI );
    printf ( "\nREAL : %f", X );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 9
int method_09 (void)
{
 
    const float PI = 3.14;
    float X = 10.01;
    int I = 10;
    printf ( "\n%s\n", "EXEMPLO0109 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "\nEXEMPLOS DE VALORES : " );
    printf ( "\nINTEIRO : %i" , I );
    printf ( "\nREAL : %f" , X );
    printf ( "\nREAL : %f" , PI );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar ( ); 
}
//metodo 10
int method_10 (void)
{
    const float PI = 3.14;
    float X = 10.01;
    int I = 10;
    char N = '\n'; 
    printf ( "\n%s\n", "EXEMPLO0106 - PRIMEIRO EXEMPLO EM C" );
    printf ( "\n%s\n", "MATRICULA: 813338 ALUNO : Alice Pereira Valle Guimaraes" );
    printf ( "%c%s" , N, "EXEMPLOS DE VALORES : " );
    printf ( "%c%s%i", N, "INTEIRO : " , I );
    printf ( "%c%s%f", N, "REAL : " , X );
    printf ( "%c%s%f", N, "REAL : " , PI );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar ( ); 

}
//metodo 11
int method_11 (void)
{
    int X = 0;
    printf ( "EXEMPLO0201 - LER E IMPRIMIR UM VALOR INTEIRO" );
    printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &X );
    getchar( ); 
    printf ( "\nO VALOR DIGITADO FOI: %d", X );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 12
int method_12 (void)
{
    float X = 0.0;
    printf ( "EXEMPLO0202 - LER E IMPRIMIR UM VALOR REAL" );
    printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
    scanf ( "%f", &X );
    getchar( ); 
    printf ( "\nO VALOR DIGITADO FOI: %f", X );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( );
    return ( EXIT_SUCCESS );
}
//metodo 13
int method_13 (void)
{
    char X = '0';
    printf ( "EXEMPLO0203 - LER E IMPRIMIR UM CARACTERE" );
    printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
    scanf ( "%c", &X );
    getchar( );
    printf ( "\nO VALOR DIGITADO FOI: %c", X );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 14
int method_14 (void)
{
    char X [10];
    printf ( "EXEMPLO0204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES" );
    printf ( "\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: " );
    scanf ( "%s", X );
    getchar( ); 
    printf ( "\nFOI DIGITADO: %s", X );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 15
int method_15 (void)
{
    int X=0, Y=0, Z=0;
    printf ( "EXEMPLO0205 - LER E SOMAR DOIS VALORES INTEIROS" );
    printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &X );
    getchar( ); 
    printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &Y );
    getchar( ); 
    Z = X + Y;
    printf ( "\nA SOMA DOS DOIS = %d", Z );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 16
int method_16 (void)
{
    float X=0.0, Y=0.0, Z=0.0;
    printf ( "EXEMPLO0206 - LER E SUBTRAIR DOIS VALORES REAIS" );
    printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
    scanf ( "%f", &X );
    getchar( ); 
    printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
    scanf ( "%f", &Y );
    getchar( ); 
    Z = X - Y;
    printf ( "\nA DIFERENCA ENTRE OS DOIS = %f", Z );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( );
    return ( EXIT_SUCCESS );
}
//metodo 17
int method_17 (void)
{
    bool X=false, Y=false, Z=false;
    printf ( "EXEMPLO0207 - OPERAR VALORES LOGICOS" );
    X = true;
    Y = false;
    Z = X || Y; // X ou Y
    printf ( "\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
    Z = X && Y; // X e Y
    printf ( "\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 18
int method_18 (void)
{
    float D = 0.0, 
    T = 0.0, 
    V = 0.0; 
    printf ( "EXEMPLO0208 - CALCULAR A VELOCIDADE DE UM VEICULO" );
    printf ( "\nFORNECER UMA DISTANCIA QUALQUER EM METROS: " );
    scanf ( "%f", &D );
    getchar( ); 
    printf ( "\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: " );
    scanf ( "%f", &T );
    getchar( ); 
    V = D / T;
    printf ( "\nV = D / T = %f%s", V, " m/s " );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 19
int method_19 (void)
{
    const char SENHA[5] = "Rita";
    char S [10];
    printf ( "EXEMPLO0209 - COMPARAR CARACTERES COM UMA SENHA" );
    printf ( "\nFORNECER UMA CADEIA DE CARACTERES QUALQUER: " );
    scanf ( "%s", S ); 
    getchar( ); 
    printf ( "\nA COMPARACAO COM A SENHA = %d", (strcmp(S,SENHA)==0)?1:0 );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 20
int method_20 (void)
{
    const double PI = 3.14;
    double ARCO = 0.0,
    COSSENO = 0.0,
    SENO = 0.0,
    TANGENTE = 0.0;
    printf ( "EXEMPLO0210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO" );
    printf ( "\nFORNECER O VALOR DO SENO: " );
    scanf ( "%lf", &SENO );
    getchar( ); 
    COSSENO = sqrt( 1.0 - pow(SENO,2) ); 
    TANGENTE = SENO / COSSENO;
    ARCO = atan( TANGENTE ); 
    printf ( "\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (ARCO*180.0/PI) );
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 21
int method_21 (void)
{
    int X = 0;
    printf ( "EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO" );
    printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &X );
    getchar( ); 
    if ( X == 0 )
    printf ( "\nO VALOR DIGITADO FOI ZERO" );
    else
    printf ( "\nO VALOR DIGITADO NAO FOI ZERO" );
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar( );
    return ( EXIT_SUCCESS );
}
//metodo 22
int method_22 (void)
{
    float X = 0.0;
    printf ( "EXEMPLO302 - LER E TESTAR UM VALOR REAL" );
    printf ( "\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: " );
    scanf ( "%f", &X );
    getchar( ); 
    if( X != 0.0 ) {
    printf ( "\nO VALOR DIGITADO FOI DIFERENTE DE ZERO" ); }
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 23
int method_23 (void)
{
    char X = '0';
    printf ( "EXEMPLO303 - LER E TESTAR UM CARACTERE" );
    printf ( "\nFORNECER UM ALGARISMO QUALQUER: " );
    scanf ( "%c", &X );
    getchar( ); 
    if( X >= '0' && X <= '9' ) 
    {
        printf ( "\nO VALOR DIGITADO FOI UM ALGARISMO" );
        printf ( "\nO ALGARISMO DIGITADO FOI: %c", X );
    } 
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 24
int method_24 (void)
{
    char X = '0';
    printf ( "EXEMPLO304 - LER E TESTAR CARACTERE" );
    printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
    scanf ( "%c", &X );
    getchar( ); 
    if( !( X >= '0' && X <= '9') ) 
    {
        printf ( "\nNAO FOI DIGITADO UM ALGARISMO" );
        printf ( "\nFOI DIGITADO O CARACTERE: %c", X );
    } 
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 25
int method_25 (void)
{
    int X=0, Y=0;
    printf ( "EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS" );
    printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &X );
    printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &Y );
    if( X == Y ) {
        printf ( "\nDOIS VALORES IGUAIS" ); }
            else {
                    printf ( "\n%d", X );
                    printf ( " DIFERENTE DE " );
                    printf ( "%d", Y );
                 } 
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    fflush ( stdin ); 
    getchar( ); 
    return ( EXIT_SUCCESS );
}
//metodo 26
void method_26 (void)
{
    float X=0.0, Y=0.0;
    printf ( "EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS" );
    printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
    scanf ( "%f", &X );
    printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
    scanf ( "%f", &Y );
    if( !(X == Y) ) {
        printf ( "\n%f", X );
        printf ( " DIFERENTE DE " );
        printf ( "%f", Y );
    }
    else 
    {
        printf ( "VALORES IGUAIS" );
    } 
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    fflush ( stdin );
    getchar( );
}
//metodo 27
void method_27 (void)
{
    int X=0, Y=0;
    bool Z=false;
    printf ( "EXEMPLO307 - TRATAR VALORES LOGICOS" );
    printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &X );
    printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
    scanf ( "%d", &Y );
    Z = (X == Y);
    if( Z ) {
        printf ( "VALORES IGUAIS" );
        }
    else{
        printf ( "VALORES DIFERENTES" );
        }
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    fflush ( stdin ); 
    getchar( ); 
}

void method_28 (void)
{
    char X = '0';
    printf ( "EXEMPLO308 - LER E TESTAR UMA LETRA" );
    printf ( "\nFORNECER UMA LETRA QUALQUER: " );
    scanf ( "%c", &X );
    getchar( ); 
    if( X >= 'A' && X <= 'Z' )
    printf ( "FOI DIGITADA UMA LETRA MAIUSCULA" );
    else
    if( X >= 'a' && X <= 'z' )
    printf ( "FOI DIGITADA UMA LETRA MINUSCULA" );
    else
    printf ( "NAO FOI DIGITADA UMA LETRA" );
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar( ); 
}

void method_29 (void)
{
    char X = '0';
    printf ( "EXEMPLO309 - COMPARAR CARACTERES < , = , >" );
    printf ( "\nFORNECER UM DOS CARACTERES CITADOS: " );
    scanf ( "%c", &X );
    getchar( ); // limpar a entrada de dados
    switch( X )
    {
        case '>': printf ( "FOI DIGITADO O SINAL DE MAIOR" );
        break;
        case '=': printf ( "FOI DIGITADO O SINAL DE IGUAL" );
        break;
        case '<': printf ( "FOI DIGITADO O SINAL DE MENOR" );
        break;
        default : printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
} 
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar


}

void method_30 (void)
{
    char X = '0';
 printf ( "EXEMPLO310 - IDENTIFICAR CARACTERES" );
 printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 switch ( X )
 {
 case 'A':
 case 'E':
 case 'I':
 case 'O':
 case 'U': printf ( "FOI DIGITADO UMA VOGAL" );
 break;
 case '0':
 case '1':
 case '2':
 case '3':
 case '4':
 case '5':
 case '6':
 case '7':
 case '8':
 case '9': printf ( "FOI DIGITADO UM ALGARISMO" );
 printf ( "\nO NUMERO CORRESPONDENTE = %d", (X-48) );
 break;
 default: printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
 } // IDENTIFICACAO DE UM CARACTERE
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar

}// end method_30()

void method_31 (void)
{
    int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0401 - LER E IMPRIMIR 03 VALORES INTEIROS" );
 printf ( "\n" ); // mudar de linha
 CONTADOR = 1;
 while( CONTADOR <= 3 ) // REPETIR
 {
 printf ( "\n" ); // mudar de linha
 printf ( "%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 } // ENQUANTO ( CONTADOR <= 3 )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end main ( )


void method_32 (void)
{
   int X = 0, N = 0, CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0402 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &N );
 getchar( ); 
 CONTADOR = 1;
 while( CONTADOR <= N )
 {
 printf ( "\n%d", CONTADOR );
 printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 } // ENQUANTO ( CONTADOR <= N )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_32()

void method_33 (void)
{
    int X = 0, N = 0;
// identificar
 printf ( "EXEMPLO0403 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &N );
 getchar( ); // limpar a entrada de dados
 while( N > 0 ) // REPETIR
 {
 printf ( "\n%d", N );
 printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 N = N - 1;
 } // ENQUANTO N > 0
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_33()

void method_34 (void)
{
   int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0404 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
 for( CONTADOR = 1; CONTADOR <= 3; CONTADOR = CONTADOR+1)
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 } // PARA CONTADOR EM [1:3]
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_34()

void method_35 (void)
{
  int X = 0,
 N = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0405 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &N );
 getchar( ); // limpar a entrada de dados
 for( CONTADOR = 1; CONTADOR <= N; CONTADOR++ )
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d", X );
 } // PARA CONTADOR EM [1:N]
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_35()

void method_36 (void)
{
   int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0406 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
 CONTADOR = 1;
 do // REPETIR
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 }
 while( CONTADOR <= 3 ); // ATE' ( CONTADOR > 3 )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_36()

void method_37 (void)
{
   int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0407 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &CONTADOR );
 getchar( ); // limpar a entrada de dados
 do // REPETIR
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR - 1;
 }
 while( CONTADOR > 0 ); // ATE' ( CONTADOR <= 3 )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_37()

void method_38 (void)
{
    int X = 0;
// identificar
 printf ( "EXEMPLO0408 - LER E IMPRIMIR INTEIROS NAO NULOS\n" );
 printf ( "\nFORNECER UM VALOR INTEIRO (0 = PARAR) : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 while ( X != 0 ) // REPETIR
 {
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 printf ( "\nDIGITE UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 } // ENQUANTO X DIFERENTE DE ZERO
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
}// end method_38()

int method_39 (void)
{
   int X = 0;
 // identificar
    printf ( "EXEMPLO0409 - PARA LER UM INTEIRO NAO NULO\n" );
    printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
    scanf ( "%d", &X );
    getchar( ); // limpar a entrada de dados
    while( X == 0 ) // REPETIR
    {
        printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
        scanf ( "%d", &X );
        getchar( ); // limpar a entrada de dados
    } // ENQUANTO X IGUAL A ZERO
    printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
 // encerrar
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar

}// end method_39()

int method_40 (void)
{
    int X = 0;
 // identificar
    printf ( "EXEMPLO0410 - LER UM INTEIRO NAO NULO\n" );
    do // REPETIR
    {
        printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
        scanf ( "%d", &X );
        getchar( ); // limpar a entrada de dados
    }
    while( X == 0 ); // ATE' X DIFERENTE DE ZERO
    printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
// encerrar
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar
}// end method_40()

int Numb41 ( void )
{
    printf ( "\n" );
    printf ( "\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS" );
    printf ( "\n" );
} // fim procedimento P1( )

int method_41 (void)
{
    printf ( "EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO" );
    Numb41 ( ); // chamada ao procedimento
    printf ( "\n" );
// encerrar
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar
}// end method_41()

void Numb42 ( int X )
{
    printf ( "\n" );
    printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
    printf ( "\n" );
} // fim procedimento P1( )

int method_42 (void)
{
    int X = 0;
    printf ( "EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n" );
    for ( X = 1; X <= 5; X = X + 1 ) {
    Numb42 (X); // chamar 5 vezes
    printf ( "\n" ); }
// encerrar
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar
}// end method_42()

void Numb43 ( int X )
{
    X = X + 1; // AVANCAR O CONTEXTO
    printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
    printf ( "\n" );
    if ( X < 5 )
    Numb43 ( X ); // CHAMAR O PROCEDIMENTO RECURSIVAMENTE
    printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
    X = X - 1; // RETORNAR AO CONTEXTO ANTERIOR
    getchar ( ); //
}

int method_43 (void)
{
    int X = 0; // não deixei global por questoes de bugs
    printf ( "EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n" );
    Numb43 ( X ); // OBSERVAR A RECURSIVIDADE !
    printf ( "\n" );
 // encerrar
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar
}// end method_43()

void Numb44 ( int X )
{
    printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
    if ( X < 5 )
    Numb44( X + 1 ); // chamar recursivamente com parametro
    printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
    getchar ( ); // para esperar
} // fim procedimento P1( )

int method_44 (void)
{
    printf ( "EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO\n" );
    Numb44 ( 1 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
    printf ( "\n" );
 // encerrar
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar
}// end method_44()

void Numb45 ( int X )
{
    printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
    if ( X > 1 )
    Numb45 ( X - 1 );
    printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
    getchar ( ); // para esperar
} // fim procedimento P1( )

int method_45 (void)
{
    printf ( "EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n" );
    Numb45 ( 5 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
    printf ( "\n" );
 // encerrar
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar

}// end method_45()

void Numb462 ();

void Numb46 (int X)
{
    printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
    if ( X < 5 )
    Numb462 ( X );
    printf ( "RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
    getchar ( ); // para esperar
} // fim do procedimento P1( )

void Numb462 (int X)
{
    printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
    X = X+1;
    printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X );
    getchar ( ); // para esperar
    Numb46 ( X );
} // fim do procedimento P2( )

int method_46 (void)
{
    printf ( "EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
    Numb46 ( 1 ); // OBSERVAR RECURSIVIDADE INDIRETA !
    printf ( "\n" );
// encerrar
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    fflush ( stdin ); // limpar a entrada de dados
getchar ( ); // para esperar
return ( EXIT_SUCCESS );
}

void Numb47 ( int* X )
{
*X = *X + 1; // AVANCAR O CONTEXTO NA REFERENCIA
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X );
if ( *X < 5 )
Numb47 ( X );
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X );
*X = *X - 1; // RETORNAR AO CONTEXTO DA REFERENCIA ANTERIOR
getchar ( ); // para esperar
} // fim procedimento P1( )

int method_47 (void)
{
 // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
 // VARIAVEL LOCAL
    int X;
    printf ( "EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
    X = 0;
    Numb47 ( &X ); // OBSERVAR REPETICAO FINITA !
    printf ( "\n" );
    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar ( ); // para
 
}// end method_47()

void Numb(); 

void Numb1 ( int X )
{
X = X + 1;
printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
if ( X < 4 )
{
Numb1 ( X );
Numb ( X );
}
printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
getchar ( ) ; // para esperar
} // fim do procedimento P1( )

void Numb ( int X )
{
printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
if ( X > 1 )
Numb ( X - 1 );
printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
getchar ( ); // para esperar
} // fim procedimento P2( )

int method_48 (void)
{
    printf ( "EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
    Numb1 ( 1 );
    printf ( "\n" );
    printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
    getchar( ); // para esperar

}

int method_49 (void)
{
    printf ( "EXEMPLO0509 - USO DE MODULOS" );
 // encerrar
    IO_pause ( "APERTAR <Enter> PARA TERMINAR." );

}// end method_49()

int method_50 (void)
{
    chars text = "MUDAR DE LINHA";
 // identificar
    printf ( "EXEMPLO0510 - USO DE MODULOS" );
    printf ( "%c" , EOL );
    printf ( "%s%c", text, EOL );
 // encerrar
    IO_pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
}// end method_50()


void menu (void) 
{
    IO_clrscr ( );
    IO_printf("%s\n\n", "1472403_AED1_Lista ED01");
    IO_printf("%s\n", "   Menu   ");
    IO_printf("%s\n", "0 - Terminar");
    IO_printf("%s\n", "1 - Method_01");
    IO_printf("%s\n", "2 - Method_02");
    IO_printf("%s\n", "3 - Method_03");
    IO_printf("%s\n", "4 - Method_04");
    IO_printf("%s\n", "5 - Method_05");
    IO_printf("%s\n", "6 - Method_06");
    IO_printf("%s\n", "7 - Method_07");
    IO_printf("%s\n", "8 - Method_08");
    IO_printf("%s\n", "9 - Method_09");
    IO_printf("%s\n", "10 - Method_10");
    IO_printf("%s\n", "11 - Method_11");
    IO_printf("%s\n", "12 - Method_12");
    IO_printf("%s\n", "13 - Method_13");
    IO_printf("%s\n", "14 - Method_14");
    IO_printf("%s\n", "15 - Method_15");
    IO_printf("%s\n", "16 - Method_16");
    IO_printf("%s\n", "17 - Method_17");
    IO_printf("%s\n", "18 - Method_18");
    IO_printf("%s\n", "19 - Method_19");
    IO_printf("%s\n", "20 - Method_20");
    IO_printf("%s\n", "21 - Method_21");
    IO_printf("%s\n", "22 - Method_22");
    IO_printf("%s\n", "23 - Method_23");
    IO_printf("%s\n", "24 - Method_24");
    IO_printf("%s\n", "25 - Method_25");
    IO_printf("%s\n", "26 - Method_26");
    IO_printf("%s\n", "27 - Method_27");
    IO_printf("%s\n", "28 - Method_28");
    IO_printf("%s\n", "29 - Method_29");
    IO_printf("%s\n", "30 - Method_30");
    IO_printf("%s\n", "31 - Method_31");
    IO_printf("%s\n", "32 - Method_32");
    IO_printf("%s\n", "33 - Method_33");
    IO_printf("%s\n", "34 - Method_34");
    IO_printf("%s\n", "35 - Method_35");
    IO_printf("%s\n", "36 - Method_36");
    IO_printf("%s\n", "37 - Method_37");
    IO_printf("%s\n", "38 - Method_38");
    IO_printf("%s\n", "39 - Method_39");
    IO_printf("%s\n", "40 - Method_40");
    IO_printf("%s\n", "41 - Method_41");
    IO_printf("%s\n", "42 - Method_42");
    IO_printf("%s\n", "43 - Method_43");
    IO_printf("%s\n", "44 - Method_44");
    IO_printf("%s\n", "45 - Method_45");
    IO_printf("%s\n", "46 - Method_46");
    IO_printf("%s\n", "47 - Method_47");
    IO_printf("%s\n", "48 - Method_48");
    IO_printf("%s\n", "49 - Method_49");
    IO_printf("%s\n", "50 - Method_50");
    
    
} //end menu
int P1 ( int X )
{
printf ( "\n" );
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
printf ( "\n" );
} // fim procedimento P1( )


int main(void)
{
    //definir dados
    int opcao =0;

    
    do
    {
        //acoes
        menu();
        opcao = IO_readint ("Qual a opcao? ");
        switch(opcao)
        {
            case 0:
                break;
            case 1: method_01 ();
                break;
            case 2: method_02 ();
                break;
            case 3: method_03 ();
                break;
            case 4: method_04 ();
                break;
            case 5: method_05 ();
                break;
            case 6: method_06 ();
                break;
            case 7: method_07 ();
                break;
            case 8: method_08 ();
                break;
            case 9: method_09 ();
                break;
            case 10: method_10 ();
                break; 
            case 11: method_11 ();
                break;
            case 12: method_12 ();
                break;
            case 13: method_13 ();
                break;
            case 14: method_14 ();
                break;
            case 15: method_15 ();
                break;
            case 16: method_16 ();
                break;
            case 17: method_17 ();
                break;
            case 18: method_18 ();
                break;
            case 19: method_19 ();
                break;
            case 20: method_20 ();
                break;
            case 21: method_21 ();
                break;
            case 22: method_22 ();
                break;
            case 23: method_23 ();
                break;
            case 24: method_24 ();
                break;
            case 25: method_25 ();
                break;
            case 26: method_26 ();
                break;
            case 27: method_27 ();
                break;
            case 28: method_28 ();
                break;
            case 29: method_29 ();
                break;
            case 30: method_30 ();
                break;
            case 31: method_31 ();
                break;
            case 32: method_32 ();
                break;
            case 33: method_33 ();
                break;
            case 34: method_34 ();
                break;
            case 35: method_35 ();
                break;
            case 36: method_36 ();
                break;
            case 37: method_37 ();
                break;
            case 38: method_38 ();
                break;
            case 39: method_39 ();
                break;
            case 40: method_40 ();
                break;
            case 41: method_41 ();
                break;
            case 42: method_42 ();
                break;
            case 43: method_43 ();
                break;
            case 44: method_44 ();
                break;
            case 45: method_45 ();
                break;
            case 46: method_46 ();
                break;
            case 47: method_47 ();
                break;
            case 48: method_48 ();
                break;
            case 49: method_49 ();
                break;
            case 50: method_50 ();
                break;
            default: IO_printf("%s\n", "Erro: Valor invalido");
                     IO_pause ("Apertar ENTER.");
                break;
        } //end switch
    } while (opcao != 0);
    
    //encerrar
    IO_pause ("Apertar ENTER");
    return (0);
    
    
} // end main ()

/* 
    Testes e observações
*/