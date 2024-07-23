#include <bits/stdc++.h>
using namespace std;

void colorir(int vet[], int tam, int current = -1, int compared = -1, int insertPos = -1) {
    for (int i = 0; i < tam; ++i) {
        if (i == current) {
            cout << "\033[34m" << vet[i] << " \033[0m"; // Azul para o elemento atual
        } else if (i == compared) {
            cout << "\033[31m" << vet[i] << " \033[0m"; // Vermelho para o elemento comparado
        } else if (i == insertPos) {
            cout << "\033[32m" << vet[i] << " \033[0m"; // Verde para a posição de inserção
        } else {
            cout << vet[i] << " ";
        }
    }
    cout << endl;
}

void InsertionSort(int tam, int vet[]) {
    for (int i = 1; i < tam; ++i) {
        int chave = vet[i];
        int j = i - 1;
        colorir(vet, tam, i, j, -1);
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            colorir(vet, tam, i, j, j + 1);
            j = j - 1;
        }
        vet[j + 1] = chave;
        colorir(vet, tam, -1, -1, j + 1);
    }
}

int main() {
    srand(time(NULL));
    int tam = 10, vet[tam];
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 31;
    }
    for (int i = 0; i < tam; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
    InsertionSort(tam, vet);
    return 0;
}
