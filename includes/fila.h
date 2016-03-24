#include "comum.h"

struct lista {
	struct registro dadosFila;
	struct lista *prox;
};
typedef struct lista Lista;

struct fila {
	Lista *ini;
	Lista *fim;
};
typedef struct fila Fila;

Fila *fila_cria();

void fila_insere(Fila *f, struct registro);

void fila_imprime(Fila *f);

float fila_inicio(Fila *f);

void fila_remove(Fila *f);

int fila_vazia(Fila *f);

void fila_libera(Fila *f);

Fila* buscaFL(Fila *f, struct registro v);
