#include "../includes/lista.h"

Lista* abrirArquivo(){ //ABRE O ARQUIVO E SALVA NA LISTA E "RETORNA" A LISTA PREENCHIDA PARA QUEM FEZ A CHAMADA DA FUNÇÃO
	FILE *old;
    old=fopen("./files/bancoUFC.dat","r");
    
    Lista *ne = lcd_cria();
    
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %s %s %f %d/%d/%d", &adicionar.conta_numero, adicionar.nome,
		&adicionar.data_nascimento.dia, &adicionar.data_nascimento.mes, &adicionar.data_nascimento.ano,
		&adicionar.idade, adicionar.endereco, adicionar.cep, adicionar.telefone, adicionar.conta_tipo,
		&adicionar.quantidade, &adicionar.deposito.dia, &adicionar.deposito.mes, &adicionar.deposito.ano) !=EOF ){
		
		ne = lcd_insere_fim(ne, adicionar);
	}
	fclose(old);
	
	//fecharArquivo(ne);//PARA TESTE
	return ne;
}
