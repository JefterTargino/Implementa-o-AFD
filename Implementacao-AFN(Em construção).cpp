/*
	* Projeto: Implementação AFD ( Teoria da Computação)
    * Professor: Isaac de Lima Oliveira Filho
	* Autores: Jan Carlos dos Santos Silva e Jefter Roberto Mota Targino
	* Data criação: 06/03/2021
	* Versao: 2.0
	* Data da ultima modificao: 06/03/2021
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
        string palavra, palavraT, acr("*");
        int estAtual= 0, achou= 0;

        int temp=0, afn=0;


    cout <<endl<<endl<< "Entre com a sua cadeia: ";
    cin >> palavra;
    cout << endl << "Cadeia digitada: " << palavra <<endl<<endl;

//-a---b*--------c--
bool valido=false, lambda=false;
int vlr=0, x=0;
    while( letra<palavra.length()){
    for(int k = 0; k<qtdInte;k++){
        for(int j=0; j<qtdEstados;j++){
                //cout<<endl<<"     Valor J1: "<<j<<endl;
                //cout<<endl<<"     Estado temp: "<<temp<<endl;
                //cout<<"     Estado atual: "<<estAtual<<" j: "<<j<<" k :"<<k<<endl;
                //cout<<"     Matriz: "<<matriz[estAtual][j][k]<<" == "<<"Caractere: "<<palavra[letra]<<endl<<endl;

                for(int z = 0; z<qtdInte;z++){
                        for(x=0; x<qtdEstados;x++){
                                cout<<"    | Matriz: "<<matriz[estAtual][x][z]<<endl;
                            if ((matriz[estAtual][x][z] == '*')){
                                //cout<<"    | Matriz: "<<matriz[estAtual][x][z]<<endl;
                                //cout<<"    | Estado atual: "<<estAtual<<" x: "<<x<<" z :"<<z<<endl;
                                //cout<<endl<<"     TEM LAMBDA     "<<endl;
                                //vlr=x;
                                lambda=true;
                            }
                        }
                    }
                    if(lambda==true){
                        palavraT=palavra;
                        palavra = palavra + acr;
                        achou=1;
                        //lambda=false;

                    }

                if ((matriz[estAtual][j][k] == palavra[letra])){
                    //a*--b*--c

                        cout<<endl<<"     CONDICAO 1: "<<j<<endl;
                    temp = estAtual;
                    estAtual=j;
                    achou =1;
                    letra++;
                    j=qtdEstados;
                    k=qtdInte;
                }

                //else if(lambda==true){
                        //temp = estAtual;
                        //estAtual=vlr;
                        //achou =1;
                        //letra++;
                        //j=qtdEstados;
                        //k=qtdInte;
                      //  lambda=false;
                    //}
                else if(matriz[estAtual][j][k] == '*'){
                    for(int a = 0; a<qtdInte;a++){
                        for(int b=0; b<qtdEstados;b++){
                            if ((matriz[estAtual][b][a] == palavra[letra])){
                                cout<<endl<<"     TEM CAMINHO     "<<endl;
                                valido=true;
                            }
                            //else
                              //  valido=false;
                        }
                    }
                        //letra--;
                        cout<<endl<<"     Valor J2: "<<j<<endl;
                    if(valido==false){
                    temp = estAtual;
        cout<<endl<<"     Valor J3: "<<j<<endl;
                    estAtual=j;
                    achou =1;
                    //letra++;
                    j=0;//qtdEstados;
                    k=0;//qtdInte;
                    }}
                else if ( (matriz[estAtual][j][k] != palavra[letra]) && achou==1){
                        cout<<endl<<"     Valor J4: "<<j<<endl;
                    if(lambda==true){
                        achou=1;
                    }
                    else{
                        achou=0;
                    }
                    valido=false;
                    lambda=false;
                }
                else if ( palavra[letra] == '*'){
                        afn=1;
                }
        }

    }
        cout << "   q"<<temp<<" para q"<<estAtual<<endl;
        cout<<"     Estado atual: "<<estAtual<<" Achou: "<<achou<<" AFN:"<<afn<<endl;
        cout<<"      Lambda: "<<lambda<<endl;
        if(achou==0){
            if(lambda==false){
                        estAtual=estAtual;
                    }
                    else{
                        estAtual=temp;
                    }

            letra=100;
        }

    }
bool teste=false;
cout<<"     Estado atual: "<<estAtual<<" Achou: "<<achou<<" AFN:"<<afn<<endl;
cout << endl << "Cadeia Final: " << palavra <<endl<<endl;
    for(int i = 0; i<qtdEstadosFim; i++){
        if((estadosFim[i] == estAtual) && (achou==1 || afn==1)){
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
