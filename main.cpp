#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "textos.hpp"
using namespace std;

struct Musica{
    string nome;
    string artista;
    string duracao;
    int ano;
    long long views;
    double media_views;
    string descricao;
};

void Realocacao(Musica* &musica, int tamanho_anterior){
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
            Realocacao(musica, capacidade);
            capacidade +=5 ;
        }
        
    }

    numero_de_musicas = i;
    return musica;
}

void imprime_formatado(const string &texto) {
    const int LIMITE = 47;
    bool controle = true;
    int pos = 0;

    while (pos < texto.size() and controle) {
        int fim = pos + LIMITE;

        if (fim >= texto.size() and controle) {
            cout << texto.substr(pos) << "\n   ";
            controle = false;
        }

        if (texto[fim] == ' ' and controle) {
            cout << texto.substr(pos, LIMITE) << "\n   ";
            pos += LIMITE + 1;
        }
        else if (controle){
            int quebra = fim;
            while (quebra > pos && texto[quebra] != ' ')
                quebra--;

            if (quebra == pos)
                quebra = fim;

            cout << texto.substr(pos, quebra - pos) << "\n   ";

            pos = quebra;
            while (pos < texto.size() && texto[pos] == ' ')
                pos++;
        }
    }
}

void Exibe_banco_de_dados(Musica* &musica, int posicao_inicial, int posicao_final){
    for(int i = posicao_inicial-1; i < posicao_final; i++){
        cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   ";
                 imprime_formatado(musica[i].descricao);
                 cout << endl << "--------------------------------------------------\n";
    }
}

string minusculo(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' and s[i] <= 'Z'){
            s[i] = s[i] + 32;    
        }
    }
    return s;
}

bool achar_posicao(string texto, string trecho){
    return texto.find(trecho) < texto.size();
}

void BuscaPorNome(Musica *musica, int capacidade){
    cin.ignore();
    string trecho;
    Enunciados(201);
    getline(cin, trecho);
    trecho = minusculo(trecho);

    bool achou = false;
    cout << "--------------------------------------------------\n";

    for(int i = 0; i < capacidade; i++){
        string nome = minusculo(musica[i].nome);

        if(achar_posicao(nome, trecho)){
            achou = true;
            cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   ";
                 imprime_formatado(musica[i].descricao);
                 cout << endl << "--------------------------------------------------\n";
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
    trecho = minusculo(trecho);

    bool achou = false;
    cout << "--------------------------------------------------\n";

    for(int i = 0; i < capacidade; i++){
        string artista = minusculo(musica[i].artista);

        if(achar_posicao(artista, trecho)){
            achou = true;
            cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   ";
                 imprime_formatado(musica[i].descricao);
                 cout << endl << "--------------------------------------------------\n";
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
    trecho = minusculo(trecho);

    bool achou = false;
    cout << "--------------------------------------------------\n";

    for(int i = 0; i < capacidade; i++){
        string parte = minusculo(musica[i].descricao);

        if(achar_posicao(parte, trecho)){
            achou = true;
            cout << "Nome: " << musica[i].nome << "\n"
                 << "Artista: " << musica[i].artista << "\n"
                 << "Duração: " << musica[i].duracao << "\n"
                 << "Ano: " << musica[i].ano << "\n"
                 << "Views: " << musica[i].views << "\n"
                 << "Media de views por ano: " << fixed << setprecision(4) << musica[i].media_views << "\n"
                 << "Parte mais reproduzida: \n   \"";
                 imprime_formatado(musica[i].descricao);
                 cout << endl << "--------------------------------------------------\n";
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
        while((j >= 0) and (minusculo(musicas[j].nome) > minusculo(auxiliar.nome))){
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


int main(){
    string nome_arquivo = "banco_de_dados.csv";
    char lixo;
    bool loop = true;
    int opcao_menu_int = 0;
    int indice1 = 0, indice2 = 0;
    int capacidade = 40;
    int numero_de_musicas;
    Musica* musica = new Musica[40];

    musica = Leitura_csv(musica, nome_arquivo, capacidade, numero_de_musicas);

    system("clear");
    while (opcao_menu_int != 5){
        Menu(0);
        cin >> opcao_menu_int;

        switch (opcao_menu_int){
        case 1: // Exibição da playlist
            loop = true;
            while(loop){
                Menu(10);
                opcao_menu_int = 0;
                cin >> opcao_menu_int;

                switch (opcao_menu_int){
                case 1:
                    Exibe_banco_de_dados(musica, 1, numero_de_musicas);
                    loop = false;
                    break;
                case 2:
                    while(indice1 > numero_de_musicas or indice1 < 1){
                        Enunciados(101, numero_de_musicas);
                        cin >> indice1;

                        if(indice1 > numero_de_musicas or indice1 < 1)
                            Mensagem_de_erro(201);
                    }
                    while(indice2 > numero_de_musicas or indice2 < 1){
                        Enunciados(102, numero_de_musicas);
                        cin >> indice2;

                        if(indice2 > numero_de_musicas or indice2 < 1)
                            Mensagem_de_erro(201);
                    }

                    Ordena_os_indices(indice1, indice2);
                    Exibe_banco_de_dados(musica, indice1, indice2);

                    loop = false;
                    break;
                case 3:
                    loop = false;
                    break;
                default:
                    Mensagem_de_erro(101);
                    break;
                }
            }
            break;
        case 2:
			opcao_menu_int = 0;
            while(opcao_menu_int != 1 and opcao_menu_int != 2 and opcao_menu_int != 3){
                Menu(20);
                cin >> opcao_menu_int;

                switch (opcao_menu_int){
                case 1:
                    BuscaPorNome(musica, capacidade);
                    break;
                case 2:
                    BuscaPorArtista(musica, capacidade);
                    break;
                case 3:
                    BuscaPorParte(musica, capacidade);
                    break;

                default:
                    Mensagem_de_erro(101);
                    break;
                }
            }
            /* code */ 
            break;
        case 3:
            Menu(11);
            opcao_menu_int = 0;
            while(opcao_menu_int != 1 and opcao_menu_int != 2 and opcao_menu_int != 3 and opcao_menu_int != 4){
                cin >> opcao_menu_int;

                switch (opcao_menu_int){
                case 1: // (1) Ordem alfabética [pelo nome]
                    Ordem_alfabetica_nome(musica, numero_de_musicas);
                    Enunciados(300);
                    break;
                case 2: // (2) Número total de visualizações
                    Ordem_visualizacoes(musica, numero_de_musicas);
                    Enunciados(300);
                    break;
                case 3: // (3) Média de vizualizações por ano"
                    Ordem_media_visualizacoes(musica, numero_de_musicas);
                    Enunciados(300);
                    break;
                case 4:
                    break;
                default:
                    Mensagem_de_erro(101);
                    break;
                }
            }
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            Saindo();
            break;
        case 10122005:
            cout << "Dados gerais do banco de dados:" << endl;
            cout << "Tamanho do banco de dados: " << "\033[31m" << capacidade << "\033[0m\n" << endl;
            break;

        default:
            break;
        }
    }
    



    // cout << fixed << setprecision(4);
    // for(int i = 0 ; i < capacidade ; i++){
    //     cout << "Musica posição " << i+1 << ":" << endl;
    //     cout << musica[i].nome << endl;
    //     cout << musica[i].artista << endl;
    //     cout << musica[i].duracao << endl;
    //     cout << musica[i].ano << endl;
    //     cout << musica[i].views << endl;
    //     cout << musica[i].media_views << endl;

    //     cout << "-------------------------------------------" << endl;
    // }

    return 0;
}