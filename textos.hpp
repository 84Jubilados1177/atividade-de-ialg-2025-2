#ifndef TEXTOS_HPP
#define TEXTOS_HPP
#include <iostream>
#include <chrono>
#include <thread>
#define COR_CANCELAR        "\033[1m\033[31m"
#define COR_OPCOES          "\033[1m\033[96m"
#define RESET               "\033[0m"
#define COR_USUARIO         "\033[1m\033[153;153;153m"
#define NEGRITO             "\033[1m"
#define PROPORCAO_JANELA    "\033[8;"
using namespace std;

struct Musica {
    string nome = "";
    string artista = "";
    string duracao = "";
    int ano = 0;
    long long views = 0;
    double media_views = 0;
    string descricao = "";
};

void Linha(){
    cout << RESET;
    cout << "――――――――――――――――――――――――――――――――――――――――――――――――――" << endl;
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
        cout << "―――――――――――――――― MENU DA PLAYLIST ――――――――――――――――" << endl;
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

void Interface(Musica musica){
    system("clear");
    cout << RESET;
    
    cout << "Nome da música: " << musica.nome << endl;
    cout << "Nome do(s) artista(s): " << musica.artista << endl;

    if(musica.ano != 0)
        cout << "Ano de lançamento: " << musica.ano << endl;
    else    
        cout << "Ano de lançamento: " << endl;

    cout << "Duração da música: " << musica.duracao << endl;

    if(musica.views != 0)
        cout << "Número de visualizações: " << musica.views << endl;
    else    
        cout << "Número de visualizações: " << endl;

    if(musica.media_views != 0){
        cout << fixed << setprecision(4); 
        cout << "Média de visualizações por ano: " << musica.media_views << endl;
    }
    else    
        cout << "Média de visualizações por ano: " << endl;
    
    cout << "Parte mais escutada: " << musica.descricao << endl;

    Linha();
}

void Enunciados(int numero, int auxiliar1 = 0){
    cout << RESET;
    switch (numero)
    {
    case 101:
        Linha();
        cout << "Digite um índice entre 1 e " << auxiliar1 << ": \n";
        break;
    case 102:
        Linha();
        cout << "Digite outro índice entre 1 e " << auxiliar1 << ": \n";
        break;
    case 201:
        Linha();
        cout << "Insira o nome ou um trecho do nome da música: \n";
        break;
    case 202:
        Linha();
        cout << "Insira o nome do artista: \n";
        break;
    case 203:
        Linha();
        cout << "Insira o trecho da música: \n";
        break;
    case 300:
        Linha();
        cout << "Playlist ordenada!" << endl;
        break;
    case 400:
        // Nada por enquanto
        break;
    case 401:
		cout << "Digite o nome da música: ";
        break;
    case 402:
		cout << "Digite o nome do artista: ";
        break;
    case 403:
	    cout << "Digite o ano em que a música foi lançada: ";
        break;
    case 404:
	    cout << "Digite a duração da música: ";
        break;
    case 405:
	    cout << "Digite o número de visualizações: ";
        break;
    case 406:
        cout << "Digite a parte que mais gosta da música (Separe os versos com \".\" ou \";\"): ";
        break;
    case 408:
        system("clear");
        Linha();
        cout << "Música adicionada com sucesso!" << endl;
        Linha();
        break;
    case 501:
        system("clear");
        Linha();
        cout << "Digite o nome da musica: ";
        break;
    case 502:
        system("clear");
        Linha();
        cout << "Digite o nome do(s) artista(s): ";
        break;
    case 600:
        Linha();
        cout << "Playlist salva com sucesso!" << endl;
        Linha();
        break;
    case 112:
        /* code  */
        break;
    
    default:
        Linha();
        cout << "ERRO INVÁLIDO" << endl;
        break;
    }

    cout  << COR_USUARIO;
}

void Mensagem_de_erro(int erro){
    float tempo_padrao = 0.633;
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

    case 403:
        Linha();
        cout << "Valor inválido! Informe um valor positivo menor\n ou igual a 2025." << endl;
        Linha();
        Digita_lento(". . . ", tempo_padrao);
        break;

    case 404:
        Linha();
        cout << "Valor inválido! Digite uma duração dentro do\npadrão de horas comum (xx:xx:xx)" << endl;
        Linha();
        Digita_lento(". . . ", tempo_padrao);
        break;

    case 405:
        Linha();
        cout << "Valor inválido! Digite um número inteiro. " << endl;
        Linha();
        Digita_lento(". . . ", tempo_padrao);
        break;

    case 406:
        Linha();
		cout << "A descrição não pode ser vazia! Digite pelo menos um espaço: ";
        Linha();
        Digita_lento(". . . ", tempo_padrao);
        break;
        
    case 504:
        Linha();
        cout << "Nenhuma música encontrada com esse nome e artista.\n";
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
    system("clear");

    Linha();
    Digita_lento("Saindo", 0.1);
    for(int i = 0; i < 3; i++)
        Digita_lento(" .", 0.5);

    cout << endl;
}

#endif