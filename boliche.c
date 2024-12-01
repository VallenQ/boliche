#include <stdio.h>

void exibirPlacar(int jogadas[], int totalJogadas) {
    int frame = 1, lancamento = 1;
    printf("Placar:\n");
    for (int i = 0; i < totalJogadas; i++) {
        if (frame <= 10) {
            if (lancamento == 1) {
                if (jogadas[i] == 10 && frame < 10) { 
                    printf("X _ | ");
                    frame++;
                } else { 
                    printf("%d", jogadas[i]);
                    lancamento = 2;
                }
            } else { 
                if (jogadas[i - 1] + jogadas[i] == 10) {
                    printf("/ | "); 
                } else {
                    printf("%d | ", jogadas[i]); 
                }
                lancamento = 1;
                frame++;
            }
        }
    }
    printf("\n");
}

int calcularPontuacao(int jogadas[], int totalJogadas) {
    int pontuacao = 0, frame = 1, lancamento = 1;

    for (int i = 0; i < totalJogadas; i++) {
        if (frame <= 10) {
            if (lancamento == 1) {
                if (jogadas[i] == 10 && frame < 10) { 
                    pontuacao += 10 + jogadas[i + 1] + jogadas[i + 2];
                    frame++;
                } else { 
                    pontuacao += jogadas[i];
                    lancamento = 2;
                }
            } else { 
                pontuacao += jogadas[i];
                if (jogadas[i - 1] + jogadas[i] == 10) { 
                    pontuacao += jogadas[i + 1];
                }
                lancamento = 1;
                frame++;
            }
        }
    }

    return pontuacao;
}

int main() {
    int jogadas[21]; 
    int totalJogadas = 0, frame = 1, lancamento = 1;

    printf("Digite a sequência:\n");

    
    while (frame <= 10) {
        int pinos;
        scanf("%d", &pinos);
        jogadas[totalJogadas++] = pinos;

        if (lancamento == 1) {
            if (pinos == 10 && frame < 10) { 
                frame++;
            } else {
                lancamento = 2; 
            }
        } else { 
            frame++;
            lancamento = 1;
        }

        
        if (frame == 10 && lancamento == 1 && pinos == 10) { 
            scanf("%d", &pinos);
            jogadas[totalJogadas++] = pinos;

            scanf("%d", &pinos);
            jogadas[totalJogadas++] = pinos;
            frame++; 
        } else if (frame == 10 && lancamento == 2) {
            int soma = jogadas[totalJogadas - 2] + jogadas[totalJogadas - 1];
            if (soma == 10) { 
                scanf("%d", &pinos);
                jogadas[totalJogadas++] = pinos;
            }
            frame++; 
        }
    }

    exibirPlacar(jogadas, totalJogadas);
    int pontuacaoFinal = calcularPontuacao(jogadas, totalJogadas);
    printf("%d\n", pontuacaoFinal);

    return 0;
}
