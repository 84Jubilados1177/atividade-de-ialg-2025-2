#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void digitar_letra_por_letra(const string& texto, int milissegundos_por_letra) {
    for (char c : texto) {
        cout << c;
        cout.flush(); 

        this_thread::sleep_for(chrono::milliseconds(milissegundos_por_letra));
    }
    cout << endl; 
}

int main() {
    string mensagem = "Ola, mundo! Esta mensagem esta sendo digitada letra por letra no Linux.";
    int v_rapida = 5;
    int v_media = 50;
    int v_lenta = 100;
    int v__muito_lenta = 500;

    string teste;

    getline(cin, teste);
    cout << teste << endl;
    // cout << "Rápido:" << endl;
    // digitar_letra_por_letra(mensagem, v_rapida);

    // cout << "Médio:" << endl;
    // digitar_letra_por_letra(mensagem, v_media);

    // cout << "Lento:" << endl;
    // digitar_letra_por_letra(mensagem, v_lenta);

    // cout << "Muito lento:" << endl;
    // digitar_letra_por_letra(mensagem, v_lenta);

    return 0;
}
