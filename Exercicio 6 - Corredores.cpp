#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_CORREDORES = 2;
const int NUM_VOLTAS = 3;

int main() {
    string nomes[NUM_CORREDORES];
    double tempos[NUM_CORREDORES][NUM_VOLTAS];

    // Leitura dos dados
    for (int i = 0; i < NUM_CORREDORES; ++i) {
        cout << "Digite o nome do corredor " << (i + 1) << ": ";
        cin >> nomes[i];

        cout << "Digite os tempos de " << nomes[i] << " para cada volta:\n";
        for (int j = 0; j < NUM_VOLTAS; ++j) {
            cout << "Volta " << (j + 1) << ": ";
            cin >> tempos[i][j];
        }
    }

    // Encontrar a melhor volta
    double melhorTempo = tempos[0][0];
    string melhorCorredor = nomes[0];
    int melhorVolta = 1;

    for (int i = 0; i < NUM_CORREDORES; ++i) {
        for (int j = 0; j < NUM_VOLTAS; ++j) {
            if (tempos[i][j] < melhorTempo) {
                melhorTempo = tempos[i][j];
                melhorCorredor = nomes[i];
                melhorVolta = j + 1;
            }
        }
    }

    // Calcular médias das voltas
    double medias[NUM_VOLTAS] = {0};

    for (int j = 0; j < NUM_VOLTAS; ++j) {
        double soma = 0;
        for (int i = 0; i < NUM_CORREDORES; ++i) {
            soma += tempos[i][j];
        }
        medias[j] = soma / NUM_CORREDORES;
    }

    // Encontrar a volta com a média mais rápida
    double menorMedia = medias[0];
    int voltaMaisRapida = 1;

    for (int j = 1; j < NUM_VOLTAS; ++j) {
        if (medias[j] < menorMedia) {
            menorMedia = medias[j];
            voltaMaisRapida = j + 1;
        }
    }

    // Classificar corredores
    double temposTotais[NUM_CORREDORES];
    for (int i = 0; i < NUM_CORREDORES; ++i) {
        temposTotais[i] = 0;
        for (int j = 0; j < NUM_VOLTAS; ++j) {
            temposTotais[i] += tempos[i][j];
        }
    }

    // Encontrar a classificação
    for (int i = 0; i < NUM_CORREDORES - 1; ++i) {
        for (int j = i + 1; j < NUM_CORREDORES; ++j) {
            if (temposTotais[i] > temposTotais[j]) {
                // Trocar tempos totais
                double tempTotal = temposTotais[i];
                temposTotais[i] = temposTotais[j];
                temposTotais[j] = tempTotal;

                // Trocar nomes correspondentes
                string tempNome = nomes[i];
                nomes[i] = nomes[j];
                nomes[j] = tempNome;
            }
        }
    }

    // Exibir resultados
    cout << fixed << setprecision(2);

    cout << "\nMelhor volta da prova:\n";
    cout << "Corredor: " << melhorCorredor << "\n";
    cout << "Volta: " << melhorVolta << "\n";
    cout << "Tempo: " << melhorTempo << " segundos\n";

    cout << "\nClassificação final:\n";
    for (int i = 0; i < NUM_CORREDORES; ++i) {
        cout << (i + 1) << "º lugar: " << nomes[i] << " com tempo total de " << temposTotais[i] << " segundos\n";
    }

    cout << "\nVolta com a média mais rápida:\n";
    cout << "Volta: " << voltaMaisRapida << "\n";
    cout << "Média: " << medias[voltaMaisRapida - 1] << " segundos\n";

    return 0;
}
