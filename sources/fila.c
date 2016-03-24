#include "../includes/fila.h"

Fila *fila_cria(){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere(Fila *f, struct registro v){
	Lista *n = (Lista*)malloc(sizeof(Lista));
	n->dadosFila = v;
	n->prox = NULL;
	if(f->fim != NULL){
		f->fim->prox = n;
	}else{
		f->ini = n;
	}
	f->fim = n;
}

void fila_imprime(Fila *f){
	Lista *aux;
	for(aux = f->ini; aux != NULL; aux = aux->prox){
		printf("%.1f\n", aux->dadosFila.quantidade);
	}
}

void fila_remove(Fila *f){
	Lista *aux;
	//float v;
	
	aux = f->ini;
	//v = aux->dadosFila.quantidade;
	f->ini = aux->prox;
	if(f->ini == NULL){
		f->fim = NULL;
	}
	free(aux);
	//return v;
}

int fila_vazia(Fila *f){
	return (f->ini == NULL);
}

void fila_libera(Fila *f){
	Lista *aux = f->ini;
	while(aux != NULL){
		Lista *t = aux->prox;
		free(aux);
		aux = t;
	}
	free(f);
}

Fila* buscaFL(Fila *l, struct registro v){
	Fila *aux = l;
	for(; aux != NULL; aux = aux->ini->prox){
		if(aux->ini->dadosFila.conta_numero == v.conta_numero){
			return aux;
		}
	}
	return NULL;
}
