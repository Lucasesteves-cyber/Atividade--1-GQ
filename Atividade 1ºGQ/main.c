#include <stdio.h> 
#include "lista.h"

int pos_atual = 0;

void adiciona_musica(Lista* li, Musica* m) {
    inserir_final(li, m);
}

void adiciona_musica_posicao(Lista* li, Musica* m, int pos) {
    inserir_posicao(li, m, pos);
}

void remove_musica(Lista* li, int pos) {
    remover_posicao(li, pos);
}

float tempo_restante(Lista* li) {
    float total = 0;
    int tam = tamanho_lista(li);
    for (int i = pos_atual; i < tam; i++) {
        Musica* m = consultar_posicao(li, i);
        float dur;
        consultar_musica(m, NULL, NULL, &dur);
        total += dur;
    }
    return total;
}

void play(Lista* li) {
    Musica* m = consultar_posicao(li, pos_atual);
    if (m != NULL) {
        printf("Tocando agora: ");
        imprimir_musica(m);
        pos_atual++;
    } else {
        printf("Fim da playlist.\n");
    }
}

int musicas_reproduzidas() {
    return pos_atual;
}

int main() {
    Lista* playlist = criar_lista();

    adiciona_musica(playlist, criar_musica("Song 1", "Artist A", 3.5));
    adiciona_musica(playlist, criar_musica("Song 2", "Artist B", 4.0));
    adiciona_musica(playlist, criar_musica("Song 3", "Artist C", 2.8));
    adiciona_musica(playlist, criar_musica("Song 4", "Artist D", 5.1));
    adiciona_musica(playlist, criar_musica("Song 5", "Artist E", 3.2));
    adiciona_musica(playlist, criar_musica("Song 6", "Artist F", 4.5));
    adiciona_musica(playlist, criar_musica("Song 7", "Artist G", 3.9));
    adiciona_musica(playlist, criar_musica("Song 8", "Artist H", 2.5));
    adiciona_musica(playlist, criar_musica("Song 9", "Artist I", 4.1));
    adiciona_musica(playlist, criar_musica("Song 10", "Artist J", 3.7));

    printf("--- Simulando Playlist ---\n");
    printf("Tempo total restante: %.2f min\n", tempo_restante(playlist));

    play(playlist);
    play(playlist);

    printf("Musicas reproduzidas: %d\n", musicas_reproduzidas());
    printf("Tempo restante atualizado: %.2f min\n", tempo_restante(playlist));

    adiciona_musica_posicao(playlist, criar_musica("Bonus Track", "Artist X", 3.0), 2);
    remove_musica(playlist, 5);

    printf("\n--- Final da Execucao ---\n");
    printf("Quantidade de musicas na playlist: %d\n", tamanho_lista(playlist));
    printf("Posicao da proxima musica a ser reproduzida: %d\n", pos_atual);

    destruir_lista(playlist);
    return 0;
}
