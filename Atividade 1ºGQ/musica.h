#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

Musica* criar_musica(char* titulo, char* artista, float duracao);
void consultar_musica(Musica* m, char* titulo, char* artista, float* duracao);
void imprimir_musica(Musica* m);
void destruir_musica(Musica* m);

#endif