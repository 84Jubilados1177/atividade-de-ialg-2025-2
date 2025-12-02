#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <map>
#include "textos.hpp"
#include "funcoes.hpp"
using namespace std;

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

int main(){
    string nome_arquivo = "banco_de_dados.csv";
    string lixo;
    string opcao_string;
    bool loop = true;
    int opcao_menu_int = 0;
    int indice1 = 0, indice2 = 0;
    int capacidade = 40;
    int numero_de_musicas;
    Musica* musica = new Musica[capacidade];

    musica = Leitura_csv(musica, nome_arquivo, capacidade, numero_de_musicas);

    system("clear");
    while (opcao_menu_int != 7){
        Menu(0);
        // Caso o usuário digite uma letra dá erro
        getline(cin, opcao_string);
        while (!(Valida_opcao(opcao_string))) {
            Mensagem_de_erro(0);

            Menu(0);
            getline(cin, opcao_string);
        }
        opcao_menu_int = stoi(opcao_string);

        switch (opcao_menu_int){
            // Exibição da playlist
            case 1: 
                system("clear");

                loop = true;
                while(loop){
                    Menu(10);
                    opcao_menu_int = 0;

                    // Caso o usuário digite uma letra dá erro
                    getline(cin, opcao_string);
                    while (!(Valida_opcao(opcao_string))) {
                        Mensagem_de_erro(0);

                        Menu(10);
                        getline(cin, opcao_string);
                    }
                    opcao_menu_int = stoi(opcao_string);

                    switch (opcao_menu_int){
                    // Exibir playlist completa
                    case 1:
                        system("clear");
                        Exibe_banco_de_dados(musica, 1, numero_de_musicas);
                        loop = false;
                        break;
                    // Exibir parte da playlist
                    case 2:
                        // Inicializa os índices
                        indice1 = 0;
                        indice2 = 0;
                        system("clear");

                        // Confere se os índices são válidos
                        while(indice1 > numero_de_musicas or indice1 < 1){

                            Enunciados(101, numero_de_musicas);
                            // Caso o usuário digite uma letra dá erro
                            getline(cin, opcao_string);
                            while (!(Valida_opcao(opcao_string))) {
                                Mensagem_de_erro(0);

                                Enunciados(101, numero_de_musicas);
                                getline(cin, opcao_string);
                            }
                            indice1 = stoi(opcao_string);

                            if(indice1 > numero_de_musicas or indice1 < 1)
                                Mensagem_de_erro(201);
                        }
                        while(indice2 > numero_de_musicas or indice2 < 1){
                            Enunciados(102, numero_de_musicas);
                            // Caso o usuário digite uma letra dá erro
                            getline(cin, opcao_string);
                            while (!(Valida_opcao(opcao_string))) {
                                Mensagem_de_erro(0);

                                Enunciados(102, numero_de_musicas);
                                getline(cin, opcao_string);
                            }
                            indice2 = stoi(opcao_string);

                            if(indice2 > numero_de_musicas or indice2 < 1)
                                Mensagem_de_erro(201);
                        }
                        Linha();
                        
                        // Exibe o banco de dados: 
                        //    começando pelo índice 1 e terminando no índice 2
                        Ordena_os_indices(indice1, indice2);
                        Exibe_banco_de_dados(musica, indice1, indice2);

                        loop = false;
                        break;
                    // Cancelar
                    case 3:
                        loop = false;
                        break;
                    default:
                        // Caso o usuário digite um número que não seja 1, 2 ou 3
                        Mensagem_de_erro(101);
                        break;
                    }
                }
                break;
            // Buscar na playlist
            case 2:
                system("clear");
                opcao_menu_int = 0;

                while(opcao_menu_int != 1 and opcao_menu_int != 2 and opcao_menu_int != 3 and opcao_menu_int != 4){
                    Menu(20);
                    
                    // Caso o usuário digite uma letra dá erro
                    getline(cin, opcao_string);
                    while (!(Valida_opcao(opcao_string))) {
                        Mensagem_de_erro(0);

                        Menu(20);
                        getline(cin, opcao_string);
                    }
                    opcao_menu_int = stoi(opcao_string);

                    switch (opcao_menu_int){
                    // Buscar pelo nome da música
                    case 1:
                        system("clear");
                        BuscaPorNome(musica, capacidade);
                        break;
                    
                    case 2:
                    // Buscar pelo nome do artista
                        system("clear");
                        BuscaPorArtista(musica, capacidade);
                        break;
                    case 3:
                    // Buscar por um trecho da música
                        system("clear");
                        BuscaPorParte(musica, capacidade);
                        break;
                    case 4:
                        // Volta para o menu principal (0) sem fazer nad
                        system("clear");
                        break;

                    default:
                        // Caso o usuário digite um numero maior que 4 ou menor do que 1
                        Mensagem_de_erro(101);
                        break;
                    }
                }
                break;
            // Ordenação
            case 3:
                system("clear");
                opcao_menu_int = 0;                

                while(opcao_menu_int != 1 and opcao_menu_int != 2 and opcao_menu_int != 3 and opcao_menu_int != 4){  
                    Menu(30);    
                    // Caso o usuário digite uma letra dá erro
                    getline(cin, opcao_string);
                    while (!(Valida_opcao(opcao_string))) {
                        Mensagem_de_erro(0);

                        Menu(30);
                        getline(cin, opcao_string);
                    }
                    opcao_menu_int = stoi(opcao_string);
                    
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
                        // Volta para o menu principal (0) sem fazer nada
                        system("clear");
                        break;
                    default:
                        // Caso o usuário digite um numero maior que 4 ou menor do que 1
                        Mensagem_de_erro(101);
                        break;
                    }
                }
                break;
            //Adicionar música a playlist
            case 4:
                Adicionar_nova_musica(musica, capacidade, numero_de_musicas);
                break;
            // Remover da playlist
            case 5:
                Apaga_musica(musica, capacidade, numero_de_musicas, nome_arquivo);
                break;
            // Salvar
            case 6:
                system("clear");
                Salvar(musica, numero_de_musicas, nome_arquivo);

                // Mensagem de salvamento
                Enunciados(600);
                break;
            case 7:
                Saindo();
                break;
            case 10122005: // APAGAR ESSA PARTE
                Linha();
                cout  << RESET << "--------- Dados gerais do banco de dados ---------" << endl;
                cout << "Tamanho do banco de dados: " << COR_CANCELAR << capacidade << RESET << endl;
                cout << "Número de músicas: " << COR_CANCELAR << numero_de_musicas << RESET << endl;
                break;

            default:
                Mensagem_de_erro(100);
                break;
            }
    }

    return 0;
}