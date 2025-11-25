#ifndef TEXTOS_HPP
#define TEXTOS_HPP
#include <iostream>
using namespace std;

void Menu(int numero){

    switch (numero){
    case 0:
        cout << "---------------------- MENU ----------------------" << endl;
        cout << "(1) Exibir músicas" << endl;
        cout << "(2) Buscar na playlist" << endl;
        cout << "(3) Adicionar nova música à playlist" << endl;
        cout << "(4) Remover música da playlist" << endl;
        cout << "(5) Sair da aplicação" << endl;
        cout << "--------------------------------------------------" << endl;
        break;
    case 10:
        cout << "--------------------------------------------------" << endl;
        cout << "(1) Exibir playlist completa" << endl;
        cout << "(2) Exibir parte da playlist" << endl;
        cout << "--------------------------------------------------" << endl;
        break;
    case 11:
        cout << "--------------------------------------------------" << endl;
        cout << "Como deseja ordenar as músicas para exibição?" << endl;
        cout << "(1) Ordem alfabética [pelo nome]" << endl;
        cout << "(2) Número total de visualizações" << endl;
        cout << "(3) Média de vizualizações por ano" << endl;
        cout << "(4) Cancelar" << endl;
        cout << "--------------------------------------------------" << endl;
        break;
    case 20:
        cout << "--------------------------------------------------" << endl;
        cout << "(1) Buscar pelo nome da música" << endl;
        cout << "(2) Buscar músicas pelo nome do artista" << endl;
        cout << "(3) Buscar pela letra da parte mais repetida" << endl;
        cout << "--------------------------------------------------" << endl;
        break;
    case 30:
        /* code */
        break;
    
    default:
        break;
    }

    /*
    --------------------------------------------------
    X - Salvar alterações
    --------------------------------------------------
    */
}


void Enunciados(int numero, int auxiliar1 = 0, int auxiliar2 = 0){
    switch (numero)
    {
    case 101:
        cout << "--------------------------------------------------" << endl;
        cout << "Digite um índice entre 1 e " << auxiliar1 << ": ";
        break;
    case 102:
        cout << "--------------------------------------------------" << endl;
        cout << "Digite outro índice entre 1 e " << auxiliar1 << ": ";
        break;
    case 201:
        cout << "--------------------------------------------------" << endl;
        cout << "Insira o nome ou um trecho do nome da música: ";
        break;
    case 202:
        cout << "--------------------------------------------------" << endl;
        cout << "Insira o nome do artista: ";
        break;
    case 203:
        cout << "--------------------------------------------------" << endl;
        cout << "Insira o trecho da música: ";
        break;
    case 111:
        /* code  */
        break;
    
    default:
        break;
    }
}

void Mensagem_de_erro(int erro){
    switch (erro){
    case 101:
        cout << "--------------------------------------------------" << endl;
        cout << "Essa opção é inválida, digite uma opção dentre as \nopções listadas." << endl;
        break;
    
    case 201:
        cout << "--------------------------------------------------" << endl;
        cout << "Índice inválido, por favor insira um índice entre\nos limites solicitados." << endl;
        break;
    
    default:
        cout << "--------------------------------------------------" << endl;
        cout << "ERRO INVÁLIDO" << endl;
        break;
    }
}

#endif