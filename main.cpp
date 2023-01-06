#include <iostream>
#include "Control_Tower.h"

int main() {
    Control_Tower control_tower;
    control_tower.Read_Files();
    int n;
    do{
        cout<<"Opcao 1: Encontrar o percurso entre dois locais com menor numero de voos\n";
        cout<<"Opcao 2: Informacoes sobre um aeroporto\n";
        cout<<"Opcao 3: Sair\n";
        cout<<"Insira a sua opcao: ";
        cin>>n;
        if(n==1){

        }
        else if(n==2){
            cout<<"Introduza o codigo do aeroporto: "<<endl;
            string code;
            cin>>code;
        }
        else if(n>3){
            cout<<"Introduza uma opcao valia: "<<endl;
        }
    }
    while(n!=3);
}
