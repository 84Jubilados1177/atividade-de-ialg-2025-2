#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include "textos.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <map>
using namespace std;

struct Musica {
    string nome;
    string artista;
    string duracao;
    int ano;
    long long views;
    double media_views;
    string descricao;
};

const map<string, string> MAPA_ACENTOS = {
    // Minúsculas
    {"á", "a"}, {"à", "a"}, {"ã", "a"}, {"â", "a"},
    {"é", "e"}, {"ê", "e"},
    {"í", "i"},
    {"ó", "o"}, {"õ", "o"}, {"ô", "o"},
    {"ú", "u"}, {"ü", "u"},
    {"ç", "c"},
    
    // Maiúsculas
    {"Á", "A"}, {"À", "A"}, {"Ã", "A"}, {"Â", "A"},
    {"É", "E"}, {"Ê", "E"},
    {"Í", "I"},
    {"Ó", "O"}, {"Õ", "O"}, {"Ô", "O"},
    {"Ú", "U"}, {"Ü", "U"},
    {"Ç", "C"}
};

string Retira_acentos(const string& str) {
    string temp = str;

    for (const auto& par : MAPA_ACENTOS) {
         
        size_t pos = temp.find(par.first);
        
        while (pos != string::npos) {
            temp.replace(pos, par.first.length(), par.second);
            pos = temp.find(par.first, pos + par.second.length());
        }
    }
    
    return temp;
}


void Redimensionamento(Musica* &musica, int tamanho_anterior){
    Musica* novo_vetor = new Musica[tamanho_anterior+5];

    for(int i = 0; i < tamanho_anterior; i++)
        novo_vetor[i] = musica[i];

    delete[] musica;
    musica = novo_vetor;
    
}

Musica* Leitura_csv(Musica *musica, string nome_arquivo, int &capacidade, int &numero_de_musicas){
    ifstream entrada_csv(nome_arquivo);
    int i = 0;
    char lixo;

    while(entrada_csv >> lixo){

        // Recebe o nome da música  
        getline(entrada_csv, musica[i].nome, '\"');
        entrada_csv >> lixo;

        // Recebe o nome do artista
        entrada_csv >> lixo;
        getline(entrada_csv, musica[i].artista, '\"');
        entrada_csv >> lixo;

        // Recebe a duração da música
        entrada_csv >> lixo;
        getline(entrada_csv, musica[i].duracao, '\"');
        entrada_csv >> lixo;

        // Recebe o ano de lancamento da música
        entrada_csv >> musica[i].ano >> lixo;

        // Recebe o número de vizualizações da música
        entrada_csv >> musica[i].views >> lixo;

        // Recebe a média de vizualizações por ano da música
        entrada_csv >> musica[i].media_views >> lixo;

        // Recebe o nome do artista
        entrada_csv >> lixo;
        getline(entrada_csv, musica[i].descricao, '\"');

        // Encremento do endereço
        i++;  

        if(i == capacidade){
            Redimensionamento(musica, capacidade);
            capacidade +=5 ;
        }
        
    }

    numero_de_musicas = i;
    return musica;
}

void Exibe_banco_de_dados(Musica* &musica, int posicao_inicial, int posicao_final){
    cout << RESET;
    for(int i = posicao_inicial-1; i < posicao_final; i++){
        cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   ";
                 Imprime_formatado(musica[i].descricao);
                 cout << endl;
                 Linha();
    }
}

string Minusculo(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' and s[i] <= 'Z'){
            s[i] = s[i] + 32;    
        }
    }
    return s;
}

bool Achar_posicao(string texto, string trecho){
    return texto.find(trecho) < texto.size();
}

void BuscaPorNome(Musica *musica, int capacidade){
    cin.ignore();
    string trecho;
    Enunciados(201);
    getline(cin, trecho);
    trecho = Minusculo(Retira_acentos(trecho));

    bool achou = false;
    Linha();

    for(int i = 0; i < capacidade; i++){
        string nome = Minusculo(Retira_acentos(musica[i].nome));

        if(Achar_posicao(nome, trecho)){
            achou = true;
            cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   ";
                 Imprime_formatado(musica[i].descricao);
                 cout << endl;
                 Linha();
        }
    }

    if(!achou)
        cout << "Nenhuma música encontrada com esse nome.\n";
}

void BuscaPorArtista(Musica *musica, int capacidade){
    cin.ignore();
    string trecho;
    Enunciados(202);
    getline(cin, trecho);
    trecho = Minusculo(Retira_acentos(trecho));

    bool achou = false;
    Linha();

    for(int i = 0; i < capacidade; i++){
        string artista = Minusculo(Retira_acentos(musica[i].artista));

        if(Achar_posicao(artista, trecho)){
            achou = true;
            cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   ";
                 Imprime_formatado(musica[i].descricao);
                 cout << endl;
                 Linha();
        }
    }

    if(!achou)
        cout << "Nenhuma música encontrada desse artista.\n";
}

void BuscaPorParte(Musica *musica, int capacidade){
    cin.ignore();
    string trecho;
    Enunciados(203);
    getline(cin, trecho);
    trecho = Minusculo(Retira_acentos(trecho));

    bool achou = false;
    Linha();

    for(int i = 0; i < capacidade; i++){
        string parte = Minusculo(Retira_acentos(musica[i].descricao));

        if(Achar_posicao(parte, trecho)){
            achou = true;
            cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   \"";
                 Imprime_formatado(musica[i].descricao);
                 cout << endl;
                 Linha();
        }
    }

    if(!achou)
        cout << "Nenhuma música encontrada contém esse trecho.\n";
}

void Ordena_os_indices(int &indice1, int &indice2){
    int auxiliar;
    if(indice1 > indice2){
        auxiliar = indice2;
        indice2 = indice1;
        indice1 = auxiliar;
    }
}

void Ordem_alfabetica_nome (Musica* &musicas, int tamanho){
    Musica auxiliar;
    int j;

    for(int i = 1; i < tamanho; i++){
        auxiliar = musicas[i];
        j = i - 1;
        while((j >= 0) and (Minusculo(musicas[j].nome) > Minusculo(auxiliar.nome))){
            musicas[j+1] = musicas[j];
            j--;
        }
        musicas[j+1] = auxiliar;
    }

}

void Ordem_visualizacoes (Musica* &musicas, int tamanho){
    Musica auxiliar;
    int j;

    for(int i = 1; i < tamanho; i++){
        auxiliar = musicas[i];
        j = i - 1;
        while((j >= 0) and (musicas[j].views < auxiliar.views)){
            musicas[j+1] = musicas[j];
            j--;
        }
        musicas[j+1] = auxiliar;
    }

}
void Ordem_media_visualizacoes (Musica* &musicas, int tamanho){
    Musica auxiliar;
    int j;

    for(int i = 1; i < tamanho; i++){
        auxiliar = musicas[i];
        j = i - 1;
        while((j >= 0) and (musicas[j].media_views < auxiliar.media_views)){
            musicas[j+1] = musicas[j];
            j--;
        }
        musicas[j+1] = auxiliar;
    }

}

void Salvar(Musica* musicas, int tamanho, string nome_arquivo){
    ofstream salvamento(nome_arquivo);
    for(int i = 0; i < tamanho; i++){
        salvamento << fixed << setprecision(4);
        salvamento << "\"" << musicas[i].nome << "\",";
        salvamento << "\"" << musicas[i].artista << "\",";
        salvamento << "\"" << musicas[i].duracao << "\",";
        salvamento << musicas[i].ano << ",";
        salvamento << musicas[i].views << ",";
        salvamento << musicas[i].media_views << ",";
        salvamento << "\"" << musicas[i].descricao << "\"\n";
    }
}

int Valida_artista(Musica *musica, int capacidade){
    cin.ignore(); 
    int i = 0, posicao = -1;
    string nomeA, nomeM, nome;
    string artista; 
    Enunciados(202);
    getline(cin, nomeA);
    nomeA = Minusculo(Retira_acentos(nomeA));

    bool achou = false;

    while(i < capacidade and !achou){
        artista = Minusculo(Retira_acentos(musica[i].artista));
        if(Achar_posicao(artista, nomeA)){
            achou = true;
            Enunciados(201);
            getline(cin, nomeM);
            nomeM = Minusculo(Retira_acentos(nomeM));

            bool achouM = false;
            Linha();
            int j = 0;

            while(j < capacidade and !achouM){
                nome = Minusculo(Retira_acentos(musica[j].nome));

                if(Achar_posicao(nome, nomeM)){
                    achouM = true;
                    posicao = j;
                    cout << NEGRITO << "  Musica a ser deletada: " << RESET << endl << endl;
                    cout << "  Artista: " << musica[i].artista << endl
                            << "  Música: " << musica[j].nome << endl;
                            Linha();
                }
            j++;
            }
            if(!achouM){
                Mensagem_de_erro(501);
            }
        }
        i++;
    }

    if(!achou){
        Mensagem_de_erro(502);
    }

    return posicao;
}

void Apaga_musica(Musica* &musicas, int capacidade, int &tamanho, string nome_arquivo){
    int opcao = 0, posicao = -1, j = 0;
    Musica* nova_playlist = new Musica[capacidade];
       
    posicao = Valida_artista(musicas, tamanho);

    while((opcao < 1 or opcao > 2) and !(posicao < 0)){

        Menu(50, musicas[posicao].nome);

        while (!(cin >> opcao)) {
            Mensagem_de_erro(0);
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Menu(50);
        }
        switch (opcao){
        case 1:
            for(int i = 0; i < tamanho; i++){
                if(posicao != i){
                    nova_playlist[j] = musicas[i];
                    j++;
                }
            }

                delete[] musicas;
                musicas = nova_playlist;
                tamanho--;
            break;
        case 2:
            /* Cancela ação */
            break;
        default:
            break;
        }
    }

}
void limpaBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

void Adicionar_nova_musica (Musica* &musicas, int &capacidade, int &numero_de_musicas){
	int i = numero_de_musicas;
	bool voltar = true;
	if (numero_de_musicas == capacidade){
		Redimensionamento(musicas, capacidade);
        capacidade +=5 ;
	}
	
	while (voltar){
		bool artista_igual = false;
		bool nome_musica_igual = false;
		cout << "Digite o nome da música: ";
		cin.ignore();
		getline(cin, musicas[i].nome);
		for (int j = 0; j < numero_de_musicas; j++){
			if (Minusculo(musicas[i].nome) == Minusculo(musicas[j].nome)){
				nome_musica_igual = true;
			}
		}
		cout << "Digite o nome do artista: ";
		getline(cin, musicas[i].artista);
		for (int j = 0; j < numero_de_musicas; j++){
			if (Minusculo(musicas[i].artista) == Minusculo(musicas[j].artista)){
				artista_igual = true;
			}
		}
		if (artista_igual and nome_musica_igual){
			cout << "Essa música já existe. Escolha outra!" << endl;
		}
		else{
			voltar = false;
		}
	}
	
	bool ok = false;
	cout << "Digite o ano em que a música foi lançada: ";
	while (!ok) {
		cin >> musicas[i].ano;
		if (!cin.fail()) {
			ok = true;
		} else {
			cout << "Valor inválido! Digite um ano inteiro: ";
			limpaBuffer();
		}
	}
	limpaBuffer();
	
	cout << "Digite a duração da música: ";
	getline(cin, musicas[i].duracao);
	
	ok = false;
	cout << "Digite o número de visualizações da música: ";
	while (!ok) {
		cin >> musicas[i].views;
		if (!cin.fail()) {
			ok = true;
		} else {
			cout << "Valor inválido! Digite um número inteiro: ";
			limpaBuffer();
		}
	}
	limpaBuffer();
	
	ok = false;
	cout << "Digite a média de visualizações por ano da música: ";
	while (!ok) {
		cin >> musicas[i].media_views;
		if (!cin.fail()) {
			ok = true;
		} else {
			cout << "Valor inválido! Digite um numero inteiro ou quebrado: ";
			limpaBuffer();
		}
	}
	limpaBuffer();
	cout << "Digite a parte que mais gosta da música (Separe os versos com \".\" ou \";\"): ";	
	do{
		getline(cin, musicas[i].descricao);
		if (musicas[i].descricao.size() == 0)
			cout << "A descrição não pode ser vazia! Digite pelo menos um espaço: ";
		}while (musicas[i].descricao.size() == 0);
	cout << endl << "Música adicionada!";
		
	numero_de_musicas++;
}

#endif