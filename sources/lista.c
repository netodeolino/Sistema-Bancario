#include "../includes/lista.h"

// Cria nova lista vazia (igual a NULL).
Lista* lcd_cria(){
	return NULL;
}

// Insere novo nó antes do nó p.
void lcd_insere_antes(Lista *p, Lista *novo){
	novo->ante = p->ante;
	novo->prox = p;
	p->ante->prox = novo;
	p->ante = novo;
}

// Insere novo nó depois do nó p.
void lcd_insere_depois(Lista *p, Lista *novo){
	novo->prox = p->prox;
	novo->ante = p;
	p->prox->ante = novo;
	p->prox = novo;
}

// Insere novo nó no início da lista l com valor v.
Lista* lcd_insere_ini(Lista *l, struct registro v){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	if(novo == NULL){
		printf("Erro: memória insuficiente!");
		exit(1);
	}
	novo->dadoLis = v;
	if(!lcd_vazia(l)){
		lcd_insere_antes(l, novo);
		return novo;
	}
	novo->prox = novo;
	novo->ante = novo;
	return novo;
}

// Insere novo nó no final da lista l com valor v.
Lista* lcd_insere_fim(Lista *l, struct registro v){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	if(novo == NULL){
		printf("Erro: memória insuficiente!");
		exit(1);
	}
	novo->dadoLis = v;
	if(!lcd_vazia(l)){
		lcd_insere_antes(l, novo);
		return l;
	}
	novo->prox = novo;
	novo->ante = novo;
	return novo;
}

// Libera a memória alocada para os nós da lista l.
void lcd_libera(Lista *l){
	while(l != NULL){
		l = lcd_retira(l, l);
	}
}

// Imprime valores (info) armazenados na lista l.
void lcd_imprime(Lista *l){
	if(lcd_vazia(l)){
		printf("[ ]\n");
		return;
	}else{
		Lista *p = l;
		printf("[ ");
		do{
			printf("%f ", p->dadoLis.quantidade);
			p = p->prox;
		}while(p != l);
		printf("]\n");
	}
}

// Retorna 1 se a lista l está vazia, e 0 caso contrário.
int lcd_vazia(Lista *l){
	return (l == NULL);
}

// Retorna endereço do 1o nó na lista l que contém o valor v.
Lista* lcd_busca(Lista *l, struct registro v){
	Lista *p = l;
	if(p == NULL){
		return NULL;
	}
	do{
		if(p->dadoLis.conta_numero == v.conta_numero){
			return p;
		}
		p = p->prox;
	}while(p != l);
	return NULL;
}

// Retira da lista l o 1o nó com valor v. Retorna lista modificada.
Lista* lcd_retira(Lista *l, Lista *no){
	if((l != NULL) && (no != NULL)){
		no->ante->prox = no->prox;
		no->prox->ante = no->ante;
		if(l == no && no->prox != no){
			Lista *p = no->prox;
			free(no);
			return p;
		}
		if(l == no && no->prox == l){
			free(no);
			return NULL;
		}
		free(no);
		return l;
	}
	return l;
}

// Retorna 1 se l1 e l2 possuem os mesmos valores armazenados (na mesma ordem), 0 caso contrário.
int lcd_igual(Lista *l1, Lista *l2){
	if((l1 == NULL) || (l2 == NULL)){
		return 0;
	}
	Lista *p1 = l1;
	Lista *p2 = l1;
	do{
		if(p1->dadoLis.conta_numero != p2->dadoLis.conta_numero){
			return 0;
			p1 = p1->prox;
			p2 = p2->prox;
		}
	}while(p1 != p2);
	
	if(p1->ante != NULL && p2->ante != NULL){
		return 1;
	}
	return 0;
}

