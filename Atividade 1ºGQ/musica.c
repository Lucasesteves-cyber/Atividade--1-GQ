#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "musica.h"

struct musica {
    char titulo[50];
    char artista[50];
    float duracao;
};

Musica* criar_musica(char* titulo, char* artista, float duracao) {
    Musica* m = (Musica*) malloc(sizeof(Musica));
    if (m != NULL) {
        strcpy(m->titulo, titulo);
        strcpy(m->artista, artista);
        m->duracao = duracao;
    }
    return m;
}

void consultar_musica(Musica* m, char* titulo, char* artista, float* duracao) {
    if (m != NULL) {
        if (titulo != NULL) strcpy(titulo, m->titulo);
        if (artista != NULL) strcpy(artista, m->artista);
        if (duracao != NULL) *duracao = m->duracao;
    }
}

void imprimir_musica(Musica* m) {
    if (m != NULL) {
        printf("Musica: %s | Artista: %s | Duracao: %.2f min\n", m->titulo, m->artista, m->duracao);
    }
}

void destruir_musica(Musica* m) {
    if (m != NULL) {
        free(m);
    }
}
