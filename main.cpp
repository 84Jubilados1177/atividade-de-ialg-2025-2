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
    Musica* novo_vetor = new Musica[tamanho_anterior+10];

    for(int i = 0; i < tamanho_anterior; i++)
        novo_vetor[i] = musica[i];
    
    delete[] musica;
    musica = novo_vetor;
    delete[] novo_vetor;
}

int main(){
    string nome_arquivo = "banco_de_dados.csv";
    char lixo;
    Musica* musica = new Musica[10];

    ifstream entrada_csv(nome_arquivo);
    
    for(int i = 0; i < 10; i++){
        // Recebe o nome da música
        entrada_csv >> lixo;
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
    }

    Realocacao(musica, 10);

    cout << fixed << setprecision(4);

    for(int i = 0 ; i < 20 ; i++){
        cout << "Musica posição " << i+1 << ":" << endl;
        cout << musica[i].nome << endl;
        cout << musica[i].artista << endl;
        cout << musica[i].duracao << endl;
        cout << musica[i].ano << endl;
        cout << musica[i].views << endl;
        cout << musica[i].media_views << endl;

        cout << "-------------------------------------------" << endl;
    }

    

    return 0;
}