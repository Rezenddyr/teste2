#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace chrono;

void InsertionSort(int n, vector<int>& vet) {
    for (int i = 1; i < n; ++i) {
        int chave = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
}

int main() {
    // Tamanho do vetor grande
    const int N = 1000000;
    // Criando vetor grande com valores aleatórios
    vector<int> vet(N);
    generate(vet.begin(), vet.end(), rand);
    
    // Vetor para salvar os valores iniciais
    vector<int> original_vet = vet;

    // Abrindo arquivo para gravar resultados
    ofstream results("dados.txt");
    results << "Size,Time(ms)" << endl;

    // Variáveis para medir o tempo
    steady_clock::time_point start, end;
    duration<double> time_span;

    // Ordenar partes do vetor de tamanhos crescentes
    for (int size = 50000; size <= N; size += 50000) {
        // Restaurar os valores iniciais do vetor
        copy(original_vet.begin(), original_vet.end(), vet.begin());

        // Medir o tempo de execução da ordenação
        start = steady_clock::now();
        InsertionSort(size, vet);
        end = steady_clock::now();
        
        time_span = duration_cast<duration<double>>(end - start);
        
        // Gravar o tamanho e o tempo no arquivo
        results << size << "," << time_span.count() * 1000 << endl; // tempo em milissegundos
    }

    // Fechar o arquivo
    results.close();

    cout << "Experimento concluído. Resultados salvos em 'insertion_sort_times.csv'." << endl;

    return 0;
}
