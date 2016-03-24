#include "../includes/arv_bin_busca.h"

int abb_vazia(Arv *a){ //TODAS OPERAÇÕES DE ÁRVORE FEITA PARA A BUSCA RÁPIDA PELO ADMINISTRADOR (SÓ ELE FAZ ESSA BUSCA)
	return (a == NULL);
}

Arv* abb_busca(Arv *a, struct registro v){
	if(abb_vazia(a)) return NULL;
	if(a->dadosArv.conta_numero == v.conta_numero) return a;
	if(v.conta_numero < a->dadosArv.conta_numero) return abb_busca(a->esq, v);
	return abb_busca(a->dir, v);
}

Arv* abb_insere(Arv *a, struct registro v){
	if(abb_vazia(a)){
		Arv *t = (Arv*)malloc(sizeof(Arv));
		t->dadosArv = v;
		t->esq = t->dir = NULL;
		return t;
	}
	if(v.conta_numero <= a->dadosArv.conta_numero) a->esq = abb_insere(a->esq, v);
	if(v.conta_numero > a->dadosArv.conta_numero) a->dir = abb_insere(a->dir, v);
	return a;
}
/*
//Retorna verdadeiro apenas se 'a' é folha da árvore
int abb_folha(Arv *a){
	return abb_vazia(a->esq) && abb_vazia(a->dir);
}

//Pré ordem
void abb_imprime(Arv *a, int nivel){
	int i;
	for(i = 0; i < nivel; i++) printf("  ");
	if(abb_vazia(a)) { printf("-\n"); return; }
	printf("%d\n", a->v);
	if(abb_folha(a))return;
	abb_imprime(a->esq, nivel+1);
	abb_imprime(a->dir, nivel+1);
}

//Imprime os elementos da árvore em ordem simétrica (crescente).
void abb_ordem_simetrica(Arv *a){
	if(abb_vazia(a)) return;
	abb_ordem_simetrica(a->esq);
	printf("%d ", a->v);
	abb_ordem_simetrica(a->dir);
}

//Retorna o no com o valor menor ou igual a raiz
Arv* abb_prodecessor(Arv *a){
	if(abb_vazia(a) || (a->esq == NULL)) return NULL;
	Arv *t = a->esq;
	for(; t->dir != NULL; t = t->dir);
	return t;
}

//Retorna o no com o valor maior da raiz
Arv* abb_sucessor(Arv *a){
	if(abb_vazia(a) || (a->dir == NULL)) return NULL;
	Arv *t = a->dir;
	for(; t->esq != NULL; t = t->esq);
	return t;
}

//Remove nó de valor v da árvore com raiz 'a' retornando a nova raiz da árvore
Arv* abb_retira(Arv *a, int v){
	if(abb_vazia(a)) return a;
	if(v == a->v){
		if(abb_folha(a)){
			free(a);
			return NULL;
		}
		if(abb_vazia(a->esq)){
			Arv *t = a->dir;
			free(a);
			return t;
		}
		if(abb_vazia(a->dir)){
			Arv *t = a->esq;
			free(a);
			return t;
		}
		// 'a' tem dois filhos
		Arv *t = abb_prodecessor(a);
		int temp = t->v;
		t->v = a->v;
		a->v = temp;
		a->esq = abb_retira(a->esq, v);
	}
	else if(v < a->v) a->esq = abb_retira(a->esq, v); 
	else if(v > a->v) a->dir = abb_retira(a->dir, v);
	return a;
}
*/
