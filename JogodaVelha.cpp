#include <iostream>
#include <limits>
using namespace std;

char tabuleiro[9];

void inicializarTabuleiro() {
    for (int i = 0; i < 9; i++) {
        tabuleiro[i] = '1' + i;
    }
}

void mostrarTabuleiro() {
    cout << " " << tabuleiro[0] << " | " << tabuleiro[1] << " | " << tabuleiro[2] << endl;
    cout << "-----------" << endl;
    cout << " " << tabuleiro[3] << " | " << tabuleiro[4] << " | " << tabuleiro[5] << endl;
    cout << "-----------" << endl;
    cout << " " << tabuleiro[6] << " | " << tabuleiro[7] << " | " << tabuleiro[8] << endl;
}

bool verificarVitoria() {
    int v[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        if (tabuleiro[v[i][0]] == tabuleiro[v[i][1]] &&
            tabuleiro[v[i][1]] == tabuleiro[v[i][2]]) {
            return true;
        }
    }
    return false;
}

bool verificarEmpate() {
    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] != 'X' && tabuleiro[i] != 'O') {
            return false;
        }
    }
    return true;
}

bool jogadaValida(int pos) {
    return (pos >= 0 && pos < 9 &&
           tabuleiro[pos] != 'X' &&
           tabuleiro[pos] != 'O');
}

int main() {
    char jogarNovamente;

    do {
        inicializarTabuleiro();
        int turno = 0;
        bool fim = false;

        mostrarTabuleiro();

        while (!fim) {
            int pos;
            char jogador = (turno % 2 == 0) ? 'X' : 'O';
            int numJogador = (turno % 2 == 0) ? 1 : 2;

            cout << "Jogador " << numJogador << " (" << jogador << "), escolha uma posição: ";

            // validacao
            while (!(cin >> pos)) {
                cout << "Posição inválida ou já ocupada! Escolha outra posição.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Jogador " << numJogador << " (" << jogador << "), escolha uma posição: ";
            }

            pos--;

            if (!jogadaValida(pos)) {
                cout << "Posição inválida ou já ocupada! Escolha outra posição.\n";
                continue;
            }

            tabuleiro[pos] = jogador;
            mostrarTabuleiro();

            if (verificarVitoria()) {
                cout << "Parabéns! Jogador " << numJogador << " venceu!\n";
                fim = true;
            }
            else if (verificarEmpate()) {
                cout << "Empate! Nenhum jogador venceu.\n";
                fim = true;
            }

            turno++;
        }

        cout << "Deseja reiniciar o jogo? (S/N): ";
        cin >> jogarNovamente;

    } while (jogarNovamente == 'S' || jogarNovamente == 's' ||
             jogarNovamente == 'Y' || jogarNovamente == 'y');

    cout << "Jogo encerrado.\n";

    return 0;
}
