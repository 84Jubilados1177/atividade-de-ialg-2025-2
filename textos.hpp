#ifndef TEXTOS_HPP
#define TEXTOS_HPP
#include <iostream>
#define COR_CANCELAR    "\033[1m\033[31m"
#define COR_OPCOES      "\033[1m\033[96m"
#define RESET           "\033[0m"
#define COR_USUARIO     "\033[1m\033[153;153;153m"
using namespace std;

void Linha(){
    cout << RESET;
    cout << "--------------------------------------------------" << endl;
}

void Menu(int numero){
    cout << RESET;

    switch (numero){
    case 0:
        cout << "---------------------- MENU ----------------------" << endl;
        cout << COR_OPCOES << "(1)" << RESET << " Exibir playlist" << endl;
        cout << COR_OPCOES << "(2)" << RESET << " Buscar na playlist" << endl;
        cout << COR_OPCOES << "(3)" << RESET << " Ordenar playlist" << endl;
        cout << COR_OPCOES << "(4)" << RESET << " Adicionar nova música à playlist" << endl;
        cout << COR_OPCOES << "(5)" << RESET << " Remover música da playlist" << endl;
        cout << COR_OPCOES << "(6)" << RESET << " Salvar playlist" << endl;
        cout << COR_CANCELAR << "(7)" << RESET << " Sair da aplicação" << endl;
        Linha();
        cout  << " " << COR_USUARIO;
        break;
    case 10:
        Linha();
        cout << COR_OPCOES << "(1)" << RESET << " Exibir playlist completa" << endl;
        cout << COR_OPCOES << "(2)" << RESET << " Exibir parte da playlist" << endl;
        cout << COR_CANCELAR << "(3)" << RESET << " Cancelar" << endl;
        Linha();
        cout  << " " << COR_USUARIO;
        break;
    case 20:
        Linha();
        cout << COR_OPCOES << "(1)" << RESET << " Buscar pelo nome da música" << endl;
        cout << COR_OPCOES << "(2)" << RESET << " Buscar músicas pelo nome do artista" << endl;
        cout << COR_OPCOES << "(3)" << RESET << " Buscar pela letra da parte mais repetida" << endl;
        cout << COR_CANCELAR << "(4)" << RESET << " Cancelar" << endl;
        Linha();
        cout  << " " << COR_USUARIO;
        break;
    case 30:
        Linha();
        cout << "Como deseja ordenar as músicas para exibição?" << endl;
        cout << COR_OPCOES << "(1)" << RESET << " Ordem alfabética [pelo nome]" << endl;
        cout << COR_OPCOES << "(2)" << RESET << " Número total de visualizações" << endl;
        cout << COR_OPCOES << "(3)" << RESET << " Média de vizualizações por ano" << endl;
        cout << COR_CANCELAR << "(4)" << RESET << " Cancelar" << endl;
        Linha();
        cout  << " " << COR_USUARIO;
        break;    
    default:
        Linha();
        cout << "ERRO INVÁLIDO" << endl;
        break;
        break;
    }

    /*
    --------------------------------------------------
    X - Salvar alterações
    --------------------------------------------------
    */
}


void Enunciados(int numero, int auxiliar1 = 0, int auxiliar2 = 0){
    cout << RESET;
    switch (numero)
    {
    case 101:
        Linha();
        cout << "Digite um índice entre 1 e " << auxiliar1 << ": ";
        cout  << COR_USUARIO;
        break;
    case 102:
        Linha();
        cout << "Digite outro índice entre 1 e " << auxiliar1 << ": ";
        cout  << COR_USUARIO;
        break;
    case 201:
        Linha();
        cout << "Insira o nome ou um trecho do nome da música: ";
        break;
    case 202:
        Linha();
        cout << "Insira o nome do artista: ";
        cout  << COR_USUARIO;
        break;
    case 203:
        Linha();
        cout << "Insira o trecho da música: ";
        cout  << COR_USUARIO;
        break;
    case 300:
        Linha();
        cout << "Playlist ordenada!" << endl;
        break;
    case 600:
        Linha();
        cout << "Playlist salva com sucesso!" << endl;
        break;
    case 112:
        /* code  */
        break;
    
    default:
        Linha();
        cout << "ERRO INVÁLIDO" << endl;
        break;
    }
}

void Mensagem_de_erro(int erro){
    cout << RESET;
    switch (erro){
    
    case 0:
        Linha();
        cout << "Entrada inválida. Por favor, insira um NUMERO \ndentre as opções.\n";
        break;
    case 100:
        Linha();
        cout << "Entrada inválida. Por favor, insira um numero \ndentre as opções.\n";
        break;
    case 101:
        Linha();
        cout << "Essa opção é inválida, digite uma opção dentre as \nopções listadas." << endl;
        break;
    
    case 201:
        Linha();
        cout << "Índice inválido, por favor insira um índice entre\nos limites solicitados." << endl;
        break;
    
    default:
        Linha();
        cout << "ERRO INVÁLIDO" << endl;
        break;
    }
}
void Saindo(){
    cout << RESET;
    Linha();
    cout << "Saindo . . ." << endl;
    Linha();
}

#endif