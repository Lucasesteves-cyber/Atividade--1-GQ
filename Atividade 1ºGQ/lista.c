#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct elem {
    Musica* dados;
    struct elem* prox;
} Elem;

struct lista {
    int qtd;
    Elem* inicio;
};

Lista* criar_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
}

int inserir_inicio(Lista* li, Musica* m) {
    if (li == NULL || m == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = m;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;
    return 1;
}

int inserir_final(Lista* li, Musica* m) {
    if (li == NULL || m == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = m;
    no->prox = NULL;
    if (li->inicio == NULL) {
        li->inicio = no;
    } else {
        Elem* aux = li->inicio;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = no;
    }
    li->qtd++;
    return 1;
}

int inserir_posicao(Lista* li, Musica* m, int pos) {
    if (li == NULL || m == NULL || pos < 0 || pos > li->qtd) return 0;
    if (pos == 0) return inserir_inicio(li, m);
    if (pos == li->qtd) return inserir_final(li, m);
    
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = m;
    
    Elem* aux = li->inicio;
    for (int i = 0; i < pos - 1; i++) aux = aux->prox;
    
    no->prox = aux->prox;
    aux->prox = no;
    li->qtd++;
    return 1;
}

int remover_inicio(Lista* li) {
    if (li == NULL || li->inicio == NULL) return 0;
    Elem* no = li->inicio;
    li->inicio = no->prox;
    destruir_musica(no->dados);
    free(no);
    li->qtd--;
    return 1;
}

int remover_final(Lista* li) {
    if (li == NULL || li->inicio == NULL) return 0;
    Elem *ant = NULL, *no = li->inicio;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }
    if (ant == NULL) li->inicio = NULL;
    else ant->prox = NULL;
    destruir_musica(no->dados);
    free(no);
    li->qtd--;
    return 1;
}

int remover_posicao(Lista* li, int pos) {
    if (li == NULL || pos < 0 || pos >= li->qtd) return 0;
    if (pos == 0) return remover_inicio(li);
    if (pos == li->qtd - 1) return remover_final(li);
    
    Elem *ant = NULL, *no = li->inicio;
    for (int i = 0; i < pos; i++) {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    destruir_musica(no->dados);
    free(no);
    li->qtd--;
    return 1;
}

Musica* consultar_inicio(Lista* li) {
    if (li == NULL || li->inicio == NULL) return NULL;
    return li->inicio->dados;
}

Musica* consultar_posicao(Lista* li, int pos) {
    if (li == NULL || pos < 0 || pos >= li->qtd) return NULL;
    Elem* aux = li->inicio;
    for (int i = 0; i < pos; i++) aux = aux->prox;
    return aux->dados;
}

int tamanho_lista(Lista* li) {
    if (li == NULL) return 0;
    return li->qtd;
}

void destruir_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while (li->inicio != NULL) {
            no = li->inicio;
            li->inicio = li->inicio->prox;
            destruir_musica(no->dados);
            free(no);
        }
        free(li);
    }
}