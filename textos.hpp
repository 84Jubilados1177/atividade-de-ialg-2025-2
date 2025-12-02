#ifndef TEXTOS_HPP
#define TEXTOS_HPP
#include <iostream>
#include <chrono>
#include <thread>
#define COR_CANCELAR    "\033[1m\033[31m"
#define COR_OPCOES      "\033[1m\033[96m"
#define RESET           "\033[0m"
#define COR_USUARIO     "\033[1m\033[153;153;153m"
#define NEGRITO     "\033[1m"
using namespace std;

void Linha(){
    cout << RESET;
    cout << "--------------------------------------------------" << endl;
}

void Imprime_formatado(const string &texto, int lim = 47, int spaces = 3) {
    cout << RESET;
    const int LIMITE = lim;
    bool controle = true;
    int pos = 0;

    while (pos < texto.size() and controle) {
        int fim = pos + LIMITE;

        if (fim >= texto.size() and controle) {
            cout << texto.substr(pos) << "\n";
            for(int i = 0; i < spaces; i++)
                cout << " ";
            controle = false;
        }

        if (texto[fim] == ' ' and controle) {
            cout << texto.substr(pos, LIMITE) << "\n";
            for(int i = 0; i < spaces; i++)
                cout << " ";
            pos += LIMITE + 1;
        }
        else if (controle){
            int quebra = fim;
            while (quebra > pos && texto[quebra] != ' ')
                quebra--;

            if (quebra == pos)
                quebra = fim;

            cout << texto.substr(pos, quebra - pos) << "\n";
            for(int i = 0; i < spaces; i++)
                cout << " ";

            pos = quebra;
            while (pos < texto.size() && texto[pos] == ' ')
                pos++;
        }
    }
}

void Digita_lento(const string& texto, float milissegundos_por_letra) {
    int tempo = milissegundos_por_letra*1000;
    for (char c : texto) {
        cout << c;
        cout.flush(); 
        this_thread::sleep_for(chrono::milliseconds(tempo));
    }
}

void Menu(int numero, string musica = "", string artista = ""){
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
        cout << "Como deseja ordenar as músicas?" << endl;
        cout << COR_OPCOES << "(1)" << RESET << " Ordem alfabética [pelo nome]" << endl;
        cout << COR_OPCOES << "(2)" << RESET << " Número total de visualizações" << endl;
        cout << COR_OPCOES << "(3)" << RESET << " Média de vizualizações por ano" << endl;
        cout << COR_CANCELAR << "(4)" << RESET << " Cancelar" << endl;
        Linha();
        cout  << " " << COR_USUARIO;
        break; 
    case 50:
        Linha();
        Imprime_formatado("Você tem certeza de que deseja apagar a música " + musica + " do(s) artista " + artista + "?", 50, 0);
        cout << endl << COR_OPCOES << "(1)" << RESET << " Sim" << endl;
        cout << COR_CANCELAR << "(2)" << RESET << " Cancelar" << endl;
        Linha();
        cout  << " " << COR_USUARIO;
        break;    
    default:
        Linha();
        cout << "ERRO INVÁLIDO" << endl;
        break;
        break;
    }
}


void Enunciados(int numero, int auxiliar1 = 0, int auxiliar2 = 0){
    cout << RESET;
    switch (numero)
    {
    case 101:
        Linha();
        cout << "Digite um índice entre 1 e " << auxiliar1 << ": \n";
        cout  << COR_USUARIO;
        break;
    case 102:
        Linha();
        cout << "Digite outro índice entre 1 e " << auxiliar1 << ": \n";
        cout  << COR_USUARIO;
        break;
    case 201:
        Linha();
        cout << "Insira o nome ou um trecho do nome da música: \n";
        cout  << COR_USUARIO;
        break;
    case 202:
        Linha();
        cout << "Insira o nome do artista: \n";
        cout  << COR_USUARIO;
        break;
    case 203:
        Linha();
        cout << "Insira o trecho da música: \n";
        cout  << COR_USUARIO;
        break;
    case 300:
        Linha();
        cout << "Playlist ordenada!" << endl;
        break;
    case 401:
        Linha();
		cout << "Digite o nome da música: ";
        break;
    case 402:
        Linha();
		cout << "Digite o nome do artista: ";
        break;
    case 403:
        Linha();
	    cout << "Digite o ano em que a música foi lançada: ";
        break;
    case 404:
        Linha();
	    cout << "Digite a duração da música: ";
        break;
    case 405:
        Linha();
	    cout << "Digite o número de visualizações da música: ";
        break;
    case 406:
        Linha();
	    cout << "Digite a média de visualizações por ano da música: ";
        break;
    case 407:
        Linha();
        cout << "Digite a parte que mais gosta da música (Separe os versos com \".\" ou \";\"): ";
        break;
    case 501:
        Linha();
        cout << "Digite o nome da musica: ";
        break;
    case 502:
        Linha();
        cout << "Digite o nome do(s) artista(s): ";
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
    system("clear");
    cout << RESET;
    switch (erro){
    
    case 0:
        Linha();
        cout << "Entrada inválida. Por favor, insira um NUMERO \nINTEIRO dentre as opções.\n";
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

    case 501:
        cout << "Essa música não existe no banco de dados." << endl;
        break;
    case 502:
        Linha();
        cout << "Nenhuma música encontrada com esse nome e artista.\n";
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
    Digita_lento("Saindo", 0.1);
    for(int i = 0; i < 3; i++)
        Digita_lento(" .", 0.5);

    cout << endl;
    Linha();
}

#endif