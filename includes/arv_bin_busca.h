#include "comum.h"

struct arv {
	struct registro dadosArv;
	struct arv *esq;
	struct arv *dir;
};
typedef struct arv Arv;

int abb_vazia(Arv *a);

Arv* abb_busca(Arv *a, struct registro v);

Arv* abb_insere(Arv *a, struct registro v);
