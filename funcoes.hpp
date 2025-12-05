#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include "textos.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;

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

void limpaBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}


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

bool E_um_numero(char caractere){
    if(caractere < '0' || caractere > '9')
        return false;
    
    return true;
}

bool Valida_opcao(string str){
    int  i = 0;
    bool e_numero = true;
    char c;
    while(i < str.size()){
        c = str[i];
        if(!(E_um_numero(c)))
            e_numero = false;
        i++;
    }
    return e_numero;
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
    salvamento.close();
}

int Encontra_musica_para_apagar(Musica *musica, int capacidade){

    string nome_artista, nome_musica;
    bool achou = false;
    int posicao_musica = -1;
    int i = 0;

    Enunciados(501);
    getline(cin, nome_musica);
    nome_musica = Minusculo(Retira_acentos(nome_musica));
    Enunciados(502);
    getline(cin, nome_artista);
    nome_artista = Minusculo(Retira_acentos(nome_artista));

    for(i = 0; i < capacidade; i++){
        if (nome_musica == Minusculo(Retira_acentos(musica[i].nome)) && nome_artista == Minusculo(Retira_acentos(musica[i].artista))){
            posicao_musica = i;
            achou = true;
        }
    }
    if(!achou){
        Mensagem_de_erro(502);
    }

    return posicao_musica;
}

void Apaga_musica(Musica* &musicas, int capacidade, int &tamanho, string nome_arquivo){
    int opcao = 0, posicao = -1, j = 0;
    string opcao_string;
    Musica* nova_playlist = new Musica[capacidade];
       
    posicao = Encontra_musica_para_apagar(musicas, tamanho);

    while((opcao < 1 or opcao > 2) and !(posicao < 0)){

        Menu(50, musicas[posicao].nome, musicas[posicao].artista);

        getline(cin, opcao_string);
        while (opcao_string.size() > 1 or !E_um_numero(opcao_string[0])) {
            Mensagem_de_erro(0);

            Menu(30);
            getline(cin, opcao_string);
        }
        opcao = stoi(opcao_string);

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
    if(posicao < 0){
        Mensagem_de_erro(501);
    }
}

bool Valida_ano(int ano){
    bool validado = true;
    if(ano > 2025 or ano < 0){
        validado = false;
    }

    return validado;
}

bool Valida_duracao(string duracao){
    bool validado = true;
    bool dois_pontos = false;
    bool segunda_parte = false;
    bool nao_e_numero = false;
    int cont_a = 0, cont_b = 0, cont_c = 0;
    int secao = 0, contagem = 0, k = -1;
    string tempo;

    if(duracao.size() >= 4 or duracao.size() <= 8){
        for(int i = 0; i < duracao.size(); i++){
            if(duracao[i] == ':'){
                dois_pontos = true;
                contagem ++;
            }
            else if(!(E_um_numero(duracao[i]))){
                validado = false;
                nao_e_numero = !E_um_numero(duracao[i]);
            }
        }
        if(dois_pontos && contagem <= 2){
            for(int i = 0; i < duracao.size(); i++){
                if(duracao[i] == ':')
                    secao++;
                else if(secao == 2)
                    cont_c++;
                else if(secao == 1)
                    cont_b++;
                else if(secao == 0)
                    cont_a++;
            }

        }
        else{
            validado = false;
        }
    }
    else
        validado = false;

    if((((cont_a < 1 or cont_a > 2) or (cont_b != 2)) or !(cont_c == 2 or cont_c == 0)) or nao_e_numero)
        validado = false;
    else{
        if(cont_c == 2){
            // horas
            if (cont_a == 1){
                tempo = duracao[0];
            }
            else{            
                tempo = duracao[0];
                tempo += duracao[1];
            }
            if(stoi(tempo) > 23){
                validado = false;
            }
            // Minutos
            tempo = duracao[cont_a + 1];
            tempo += duracao[cont_a + 2];
            if(stoi(tempo) > 59){
                validado = false;
            }
            // Minutos
            tempo = duracao[cont_a + cont_b + 2];
            tempo += duracao[cont_a + cont_b + 3];
            if(stoi(tempo) > 59){
                validado = false;
            }
        }
        else{
            // minutos
            if (cont_a == 1){
                tempo = duracao[0];
            }
            else{            
                tempo = duracao[0];
                tempo += duracao[1];
            }
            if(stoi(tempo) > 59){
                validado = false;
            }
            // Segundos
            tempo = duracao[cont_a + 1];
            tempo += duracao[cont_a + 2];
            if(stoi(tempo) > 59){
                validado = false;
            }
        }
    }

    return validado;
}

bool Valida_visualizacoes(long long visualizacoes){
    bool validado = false;

    if(visualizacoes >= 0 && visualizacoes <= 9223372036854775807) // limite do Long long ~
        validado = true;

    return validado;
}

void Adicionar_nova_musica (Musica* &musicas, int &capacidade, int &numero_de_musicas){
	int i = numero_de_musicas;
    string intermediario;
	bool voltar = true;
	bool ok = false;
    bool musica_inexistente = false;

	if (numero_de_musicas == capacidade){
		Redimensionamento(musicas, capacidade);
        capacidade +=5 ;
	}
	
	while (voltar){
		bool artista_igual = false;
		bool nome_musica_igual = false;
        musica_inexistente = false;

        Interface(musicas[i]);
        Enunciados(401); // Nome da música
		getline(cin, musicas[i].nome);
		for (int j = 0; j < numero_de_musicas; j++){
			if (Minusculo(Retira_acentos(musicas[i].nome)) == Minusculo(Retira_acentos(musicas[j].nome))){
				nome_musica_igual = true;
			}
		}

        Interface(musicas[i]);
        Enunciados(402); // Nome do artista
		getline(cin, musicas[i].artista);
		for (int j = 0; j < numero_de_musicas; j++){
			if (Minusculo(Retira_acentos(musicas[i].artista)) == Minusculo(Retira_acentos(musicas[j].artista))){
				artista_igual = true;
			}
		}
		if (artista_igual and nome_musica_igual){
            Mensagem_de_erro(400);
            musicas[i].artista = "";
            musicas[i].nome = "";
            musica_inexistente = true;
            voltar = true;
		}
		else{
			voltar = false;
		}
	}
	
    if(!musica_inexistente){
        ok = false;
        Interface(musicas[i]);
        Enunciados(403); // Ano de lançamento
        while (!ok) {
            cin >> intermediario;
            if (intermediario.size() <= 4 && Valida_opcao(intermediario)) {
                musicas[i].ano = stoi(intermediario);
                if(Valida_ano(musicas[i].ano)){
                    ok = true;
                }
                else {
                    Mensagem_de_erro(403);
                    musicas[i].ano = 0;
                    Interface(musicas[i]);
                    Enunciados(403); // Ano de lançamento
                }
            } 
            else {
                Mensagem_de_erro(403);
                musicas[i].ano = 0;
                Interface(musicas[i]);
                Enunciados(403); // Ano de lançamento
            }
        }
        limpaBuffer();
        
        ok = false;
        while(!ok){
            Interface(musicas[i]);
            Enunciados(404); // Duração
            getline(cin, musicas[i].duracao);
            if (Valida_duracao(musicas[i].duracao)) {
                ok = true;
            } else {
                Mensagem_de_erro(404);
                musicas[i].duracao = "";
                Interface(musicas[i]);
                Enunciados(404); // Ano de lançamento
            }
        }
        
        ok = false;
        Interface(musicas[i]);
        Enunciados(405); // Número de vizualizações
        while (!ok) {
            cin >> intermediario;
            if (intermediario.size() <= 20 && Valida_opcao(intermediario)) {
                musicas[i].views = stoi(intermediario);
                if(Valida_visualizacoes(musicas[i].views)){
                    ok = true;
                }
                else {
                    Mensagem_de_erro(405);
                    musicas[i].views = 0;
                    Interface(musicas[i]);
                    Enunciados(405); // views de lançamento
                }
            } 
            else {
                Mensagem_de_erro(405);
                musicas[i].views = 0;
                Interface(musicas[i]);
                Enunciados(405); // Ano de lançamento
            }
        }
	}

    

    // Media de vizualizações por ano
    if(musicas[i].ano == 2025)
        musicas[i].media_views = musicas[i].views;
    else
        musicas[i].media_views = round((musicas[i].views / (2025 - musicas[i].ano)) * 10000.0) / 10000.0;	
	limpaBuffer();
	ok = false;
    Interface(musicas[i]);
    Enunciados(406); // Parte mais tocada
	do{
		getline(cin, musicas[i].descricao);
		if (musicas[i].descricao.size() == 0)
            Mensagem_de_erro(406);
	}while (musicas[i].descricao.size() == 0);
	
    Enunciados(408); //123123123
		
	numero_de_musicas++;
}

#endif