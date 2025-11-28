#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <map>
#include "textos.hpp"
#include "funcoes.hpp"
using namespace std;

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
    while (opcao_menu_int != 7){
        Menu(0);
        while (!(cin >> opcao_menu_int)) {
            Mensagem_de_erro(0);
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Menu(0);
        }

        switch (opcao_menu_int){
            case 1: // Exibição da playlist
                system("clear");
                loop = true;
                while(loop){
                    Menu(10);
                    opcao_menu_int = 0;
                    cin >> opcao_menu_int;

                    switch (opcao_menu_int){
                    case 1:
                        system("clear");
                        Exibe_banco_de_dados(musica, 1, numero_de_musicas);
                        loop = false;
                        break;
                    case 2:
                        indice1 = 0;
                        indice2 = 0;
                        system("clear");
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
                        Linha();
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
                system("clear");
                opcao_menu_int = 0;
                while(opcao_menu_int != 1 and opcao_menu_int != 2 and opcao_menu_int != 3 and opcao_menu_int != 4){
                    Menu(20);
                    cin >> opcao_menu_int;

                    switch (opcao_menu_int){
                    case 1:
                        system("clear");
                        BuscaPorNome(musica, capacidade);
                        break;
                    case 2:
                        system("clear");
                        BuscaPorArtista(musica, capacidade);
                        break;
                    case 3:
                        system("clear");
                        BuscaPorParte(musica, capacidade);
                        break;
                    case 4:
                        // Sai do codigo
                        break;

                    default:
                        Mensagem_de_erro(101);
                        break;
                    }
                }
                /* code */ 
                break;
            case 3:
                system("clear");
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
                system("clear");
                Salvar(musica, numero_de_musicas, nome_arquivo);
                Enunciados(600);
                break;
            case 7:
                Saindo();
                break;
            case 10122005:
                cout << "Dados gerais do banco de dados:" << endl;
                cout << "Tamanho do banco de dados: " << "\033[31m" << capacidade << "\033[0m\n" << endl;
                break;

            default:
                Mensagem_de_erro(100);
                break;
            }
    }

    return 0;
}