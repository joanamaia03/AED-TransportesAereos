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
        cout<<"Insira a sua opcao:\n";
        cin>>n;
        if(n==1){
            vector<string> user_airlines;
            cout<<"->Indique o tipo de dado para o Ponto de partida:\n";
            cout<<"Para Codigo do aeroporto insira 1\n";
            cout<<"Para Cidade insira 2\n";
            cout<<"Para Pais insira 3\n";
            cout<<"Para Coordenadas insira 4\n";
            cout<<"Para Cancelar insira 5\n";
            int s1;
            cin>>s1;
            string a;
            if(s1==1) {
                cout<<"Insira o Codigo do aeroporto:\n";
                cin >> a;
            }
            else if(s1==2) {
                cout<<"Insira a Cidade do aeroporto:\n";
                cin >> a;
            }
            else if(s1==3) {
                cout<<"Insira o Pais do aeroporto:\n";
                cin >> a;
            }
            else if(s1==4) {
                cout<<"Insira a Latitude:\n";
                string a1;
                cin >> a1;
                cout<<"Insira a Longitude:\n";
                string a2;
                cin >> a2;
                a.append(a1);
                a.append(",");
                a.append(a2);
            }
            else if(s1==5) {
                continue;
            }
            cout<<"->Indique o tipo de dado para o Destino:\n";
            cout<<"Para Codigo do aeroporto insira 1\n";
            cout<<"Para Cidade insira 2\n";
            cout<<"Para Pais insira 3\n";
            cout<<"Para Coordenadas insira 4\n";
            cout<<"Para Cancelar insira 5\n";
            int d1;
            cin>>d1;
            string b;
            if(d1==1) {
                cout<<"Insira o Codigo do aeroporto:\n";
                cin >> b;
            }
            else if(s1==2) {
                cout<<"Insira a Cidade do aeroporto:\n";
                cin >> b;
            }
            else if(s1==3) {
                cout<<"Insira o Pais do aeroporto:\n";
                cin >> b;
            }
            else if(s1==4) {
                cout<<"Insira a Latitude:\n";
                string b1;
                cin >> b1;
                cout<<"Insira a Longitude:\n";
                string b2;
                cin >> b2;
                b.append(b1);
                b.append(",");
                b.append(b2);
            }
            else{
                continue;
            }
            cout<<"Insira companhias aereas de preferencia (insira um ponto final '.' para finalizar lista):\n";
            string c = "";
            cin>>c;
            while (c!="."){
                user_airlines.push_back(c);
                cin>>c;
            }
            control_tower.shortestPath(s1,d1,a,b,user_airlines);
        }
        else if(n==2){
            cout<<"Opcao 1: Numero de voos num dado aeroporto\n";
            cout<<"Opcao 2: Numero de voos para destinos diferentes num dado aeroporto\n";
            cout<<"Opcao 3: Numero de voos com companhias areas diferentes num dado aeroporto\n";
            cout<<"Opcao 4: Numero de voos para paises diferentes num dado aeroporto\n";
            cout<<"Opcao 5: Cancelar operacao\n";
            int s;
            cin>>s;
            if (s==1){
                cout<<"Insira o codigo do aeroporto\n";
                string code;
                cin>>code;
                control_tower.FlightsPerAirport(code);
            }
            if (s==2){
                cout<<"Insira o codigo do aeroporto\n";
                string code;
                cin>>code;
                control_tower.TargetsPerAirport(code);
            }
            if (s==3){
                cout<<"Insira o codigo do aeroporto\n";
                string code;
                cin>>code;
                control_tower.AirlinesPerAirport(code);
            }
            if (s==4){
                cout<<"Insira o codigo do aeroporto\n";
                string code;
                cin>>code;
                control_tower.CountriesPerAirport(code);
            }
            else{
                continue;
            }
        }
        else if(n!=3){
            cout<<"Introduza uma opcao valida: "<<endl;
        }
    }
    while(n!=3);
}
