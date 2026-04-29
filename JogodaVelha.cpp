#include <iostream>
using namespace std;

char tabuleiro[9];

// Função para inicializar o tabuleiro
void inicializarTabuleiro() {
    for (int i = 0; i < 9; i++) {
        tabuleiro[i] = '1' + i;
    }
}

// Função para exibir o tabuleiro
void mostrarTabuleiro() {
    cout << " " << tabuleiro[0] << " | " << tabuleiro[1] << " | " << tabuleiro[2] << endl;
    cout << "-----------" << endl;
    cout << " " << tabuleiro[3] << " | " << tabuleiro[4] << " | " << tabuleiro[5] << endl;
    cout << "-----------" << endl;
    cout << " " << tabuleiro[6] << " | " << tabuleiro[7] << " | " << tabuleiro[8] << endl;
}

// Função para verificar vitória
bool verificarVitoria() {
    int vitorias[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        if (tabuleiro[vitorias[i][0]] == tabuleiro[vitorias[i][1]] &&
            tabuleiro[vitorias[i][1]] == tabuleiro[vitorias[i][2]]) {
            return true;
        }
    }
    return false;
}

// Função para verificar empate
bool verificarEmpate() {
    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] != 'X' && tabuleiro[i] != 'O') {
            return false;
        }
    }
    return true;
}

// Função para validar jogada
bool jogadaValida(int pos) {
    if (pos < 0 || pos > 8) return false;
    if (tabuleiro[pos] == 'X' || tabuleiro[pos] == 'O') return false;
    return true;
}

int main() {
    char jogarNovamente;

    do {
        inicializarTabuleiro();
        int turno = 0;
        bool jogoAcabou = false;

        while (!jogoAcabou) {
            mostrarTabuleiro();

            int pos;
            char jogador = (turno % 2 == 0) ? 'X' : 'O';
            int numeroJogador = (turno % 2 == 0) ? 1 : 2;

            cout << "Jogador " << numeroJogador << " (" << jogador << "), escolha uma posição: ";
            cin >> pos;

            pos--; // ajustar para índice do array

            if (!jogadaValida(pos)) {
                cout << "Posição inválida ou já ocupada! Escolha outra posição.\n";
                continue;
            }

            tabuleiro[pos] = jogador;

            if (verificarVitoria()) {
                mostrarTabuleiro();
                cout << "Parabéns! Jogador " << numeroJogador << " venceu!\n";
                jogoAcabou = true;
            }
            else if (verificarEmpate()) {
                mostrarTabuleiro();
                cout << "Empate! Nenhum jogador venceu.\n";
                jogoAcabou = true;
            }

            turno++;
        }

        cout << "Deseja reiniciar o jogo? (S/N): ";
        cin >> jogarNovamente;

    } while (jogarNovamente == 'S' || jogarNovamente == 's');

    cout << "Jogo encerrado.\n";

    return 0;
}