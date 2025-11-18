#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Musica{
    string nome;
    string artista;
    string duracao;
    int ano;
    int views;
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

Musica* Leitura_csv(Musica *musica, string nome_arquivo, int &capacidade){
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

    return musica;
}

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
        /* code */
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


int main(){
    string nome_arquivo = "banco_de_dados.csv";
    char lixo;
    bool loop = true;
    int opcao_menu_int = 0;
    int indice1 = 0, indice2 = 0;
    int capacidade = 10;
    Musica* musica = new Musica[10];

    musica = Leitura_csv(musica, nome_arquivo, capacidade);

    while (opcao_menu_int != 5){
        
        Menu(0);
        cin >> opcao_menu_int;

        switch (opcao_menu_int){
        case 1: // Exibição da playlist
            loop = true;
            while(loop){
                Menu(10);
                cin >> opcao_menu_int;

                switch (opcao_menu_int){
                case 1:
                    /* code */
                    loop = false;
                    break;
                case 2:
                    while(indice1 > capacidade or indice1 < 1){
                        Enunciados(101, capacidade);
                        cin >> indice1;

                        if(indice1 > capacidade or indice1 < 1)
                            Mensagem_de_erro(201);
                    }
                    while(indice2 > capacidade or indice2 < 1){
                        Enunciados(102, capacidade);
                        cin >> indice2;

                        if(indice2 > capacidade or indice2 < 1)
                            Mensagem_de_erro(201);
                    }
                    loop = false;
                    break;
                default:
                    Mensagem_de_erro(101);
                    break;
                }
                cout << opcao_menu_int << endl;
            }
            break;
        case 2:
            while(opcao_menu_int != 1 or opcao_menu_int != 2 or opcao_menu_int != 3){
                Menu(20);
                cin >> opcao_menu_int;

                switch (opcao_menu_int){
                case 1:
                    /* code */
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    /* code */
                    break;

                default:
                    Mensagem_de_erro(101);
                    break;
                }
            }
            /* code */ 
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* Mensagem de saída */
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