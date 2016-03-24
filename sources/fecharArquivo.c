#include "../includes/lista.h"

void fecharArquivo(Lista *li){ //RECEBE A LISTA ATUALIZADA COM SUAS MUDANÇAS REALIZADAS E SALVA NO ARQUIVO
	FILE *newrec;
    newrec = fopen("./files/new.dat","w");
    
    Lista *aux = li;
    
    while(aux != NULL){
		fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d\n", aux->dadoLis.conta_numero, aux->dadoLis.nome,
		aux->dadoLis.data_nascimento.dia, aux->dadoLis.data_nascimento.mes, aux->dadoLis.data_nascimento.ano,
		aux->dadoLis.idade, aux->dadoLis.endereco, aux->dadoLis.cep, aux->dadoLis.telefone, aux->dadoLis.conta_tipo,
		aux->dadoLis.quantidade, aux->dadoLis.deposito.dia, aux->dadoLis.deposito.mes, aux->dadoLis.deposito.ano);
		
		aux = lcd_retira(aux, aux);
	}
	fclose(newrec);
	remove("./files/bancoUFC.dat");
    rename("./files/new.dat","./files/bancoUFC.dat");
}
