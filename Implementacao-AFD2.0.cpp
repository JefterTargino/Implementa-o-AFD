/*
	* Projeto: Implementação AFD ( Teoria da Computação)
    * Professor: Isaac de Lima Oliveira Filho
	* Autores: Jan Carlos dos Santos Silva e Jefter Roberto Mota Targino
	* Data criação: 06/03/2021
	* Versao: 2.0
	* Data da ultima modificao: 13/03/2021
	* Descricao: Algoritmo que indica as cadeias que são reconhecidas ou não pelo autômato.
*/
#include <iostream>
#include <bits/stdc++.h>        //BIBLIOTECAS NECESSARIAS
#include <string>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main(){ // FUNÇÃO PRINCIPAL
    setlocale(LC_ALL,"Portuguese");

    int qtdEstados, qtdEstadosFim,i=0, qtdInte;

cout<<"|*******************************************|"<<endl;
cout<<"|******* Reconhecedor de cadeias AFD *******|"<<endl;
cout<<"|*******************************************|"<<endl;
cout<<"|****** By Jefter Targino e Jan Carlos******|"<<endl<<endl;



    cout << "Digite a quantidade de estados do AFD: ";
    cin >>qtdEstados;   //

    cout << "Digite a quantidade maxima de interações: ";
    cin >>qtdInte;   //

    char matriz [qtdEstados][qtdEstados][qtdInte];   //

    cout << "Quantidade de estados finais: ";
    cin >>qtdEstadosFim;

    int estadosFim[qtdEstadosFim];

    for(int i=0; i<qtdEstadosFim; i++){
        cout << "Estado final | q";
        cin >>estadosFim[i];
    }

    cout << endl<< "   Estado Inicial: q" << i << endl;
    cout << "   Quantidade de estados no AFD: " << qtdEstados << endl;
    cout << "   Estados Finais: ";
    for(int i=0; i<qtdEstadosFim;i++)
        cout << "| q" << estadosFim[i] << " |";


    //MATRIZ DE TRANSIÇÃO
    cout << endl <<endl << "Preencha os campos com o caractere que liga os estados, caso contrario digite -" << endl;
    for(int k = 0; k<qtdInte;k++){
    for(int i = 0; i<qtdEstados; i++){
        for(int j = 0; j<qtdEstados;j++){

                cout << "De q"<< i << " para q" << j << " interacao "<<k+1<<": ";
                cin >> matriz[i][j][k];
                //cout << endl;
            }
        }
    }

INICIO:
system("clear");

    cout << "Matriz de Transição de Estados" << endl;
    for(int i = 0; i<qtdEstados; i++){
        for(int j = 0; j<qtdEstados;j++){
            for(int k = 0; k<qtdInte;k++){
                cout << matriz[i][j][k] << " ";
            }
        }
                cout << endl;
    }
    cout <<endl<< "   Estados Finais: ";
    for(int i=0; i<qtdEstadosFim;i++)
        cout << "| q" << estadosFim[i] << " |";

        int letra=0;
        string palavra;
        int estAtual= 0, achou= 0;

        int temp=0;


    cout <<endl<<endl<< "Entre com a sua cadeia: ";
    cin >> palavra;
    cout << endl << "Cadeia digitada: " << palavra <<endl<<endl;


    while( letra<palavra.length()){
    for(int k = 0; k<qtdInte;k++){
        for(int j=0; j<qtdEstados;j++){

                if (matriz[estAtual][j][k] == palavra[letra]){
                    temp = estAtual;
                    estAtual=j;
                    achou =1;
                    letra++;
                    j=qtdEstados;
                    k=qtdInte;
                }
                else if ( (matriz[estAtual][j][k] != palavra[letra]) && achou==1){
                    achou=0;

                }
                }

        }
        cout << "   q"<<temp<<" para q"<<estAtual<<endl;
        if(achou==0){
            estAtual=temp;
            letra=100;
        }

    }
bool teste=false;
    for(int i = 0; i<qtdEstadosFim; i++){
        if((estadosFim[i] == estAtual) && achou==1){
            teste=true;
        }
        }
        if(teste==true){
            cout<<endl<<"     !!! A cadeia foi reconhecida !!!"<<endl<<endl;
        }
        else
            cout<<endl<<"     !!! A cadeia foi rejeitada !!!"<<endl<<endl;

system("PAUSE");
goto INICIO;
return 0;
}
