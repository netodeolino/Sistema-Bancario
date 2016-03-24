/*
	TODAS AS IMPLEMENTAÇÕES DAS OPERAÇÕES FEITA PELO ADMINISTRADOR
*/

#include "../includes/lista.h"
#include "../includes/arv_bin_busca.h"

void criaConta(Lista *li){
	int maior=0;
	Lista *haha = li->prox;
	for(; haha != li; haha = haha->prox){
		if(haha->dadoLis.conta_numero > maior){
			maior = haha->dadoLis.conta_numero;
		}
	}
	
	adicionar.conta_numero = maior+1;
    //printf("\n\t\tDigite o número da conta: ");
    //scanf("%d", &adicionar.conta_numero);
    printf("\n\t\tDigite o nome: ");
    scanf("%s",adicionar.nome);
    printf("\n\t\tDigite a data de nascimento (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&adicionar.data_nascimento.dia, &adicionar.data_nascimento.mes, &adicionar.data_nascimento.ano);
    printf("\n\t\tDigite a idade: ");
    scanf("%d",&adicionar.idade);
    printf("\n\t\tDigite o endereço: ");
    scanf("%s",adicionar.endereco);
    printf("\n\t\tDigite o número do cep da cidade: ");
    scanf("%s",adicionar.cep);
    printf("\n\t\tDigite seu telefone: ");
    scanf("%s",adicionar.telefone);
    printf("\n\t\tDigite a quantidade para deposito:$ ");
    scanf("%f",&adicionar.quantidade);
    printf("\n\t\tDigite a data de hoje (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&adicionar.deposito.dia, &adicionar.deposito.mes, &adicionar.deposito.ano);
    printf("\n\t\tTipo de conta:\n\t\t\t#Poupança \n\t\t\t#Corrente \n\t\t\tDigite sua escolha: ");
    scanf("%s",adicionar.conta_tipo);
    
    li = lcd_insere_fim(li, adicionar);
    
    printf("\n\t\tConta criada com Sucesso!");
    
    adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuAdmin(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\n\t\tInválido!\a");
		goto adicionar_invalido;
    }
    //fecharArquivo(li);
}

void removeConta(Lista *li){
	Lista *aux = li;
	
	printf("\t\tDigite o número da conta a ser removida: ");
    scanf("%d", &remover.conta_numero);
    
    aux = lcd_busca(aux, remover);
    if(!lcd_vazia(aux)){
		li = lcd_retira(li, aux); //lcd_busca(aux, remover) PODE SER USADO TAMBÉM
		printf("\n\t\tConta removida com Sucesso!");
	}else{
		printf("\n\t\tConta inexistente ou incorreta!");
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuAdmin(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\n\t\tInválido!\a");
		goto adicionar_invalido;
    }
}

void listaContas(Lista *li){
	if(lcd_vazia(li)){
		printf("\n\t\tNenhuma conta salva!\n");
		menuAdmin(li);
	}else{
		Lista *aux = li;
		printf("\nN° CONTA\tNOME\t\tENDEREÇO\t\tTELEFONE\n");
		do{
			printf("\n%6d\t %10s\t\t%10s\t\t%10s", aux->dadoLis.conta_numero, aux->dadoLis.nome, aux->dadoLis.endereco,
				aux->dadoLis.telefone);
			aux = aux->prox;
		}while(aux != li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuAdmin(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\n\t\tInválido!\a");
		goto adicionar_invalido;
    }
}


void detalhesConta(Lista *li){
	Lista *aux = li;
	
	printf("\t\tDigite o número da conta: ");
    scanf("%d", &procurar.conta_numero);
	
	aux = lcd_busca(li, procurar);
	
	if(!lcd_vazia(aux)){
		printf("\n\t\tNúmero da conta:%d\n\t\tNome:%s \n\t\tData de nascimento:%d/%d/%d \n\t\tIdade:%d \n\t\tEndereço:%s \n\t\tCEP:%s \n\t\tTelefone:%s \n\t\tTipo da conta:%s \n\t\tValor depósitado:$ %.2f \n\t\tData de depósito:%d/%d/%d\n\n",
			aux->dadoLis.conta_numero, aux->dadoLis.nome, aux->dadoLis.data_nascimento.dia, aux->dadoLis.data_nascimento.mes,
			aux->dadoLis.data_nascimento.ano, aux->dadoLis.idade, aux->dadoLis.endereco, aux->dadoLis.cep, aux->dadoLis.telefone,
			aux->dadoLis.conta_tipo, aux->dadoLis.quantidade, aux->dadoLis.deposito.dia, aux->dadoLis.deposito.mes,
			aux->dadoLis.deposito.ano);
	}else{
		printf("\n\t\tConta inexistente ou incorreta!");
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuAdmin(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\n\t\tInválido!\a");
		goto adicionar_invalido;
    }
}

void buscaConta(Lista *li){
	Arv *a = NULL;
	if(lcd_vazia(li)){
		printf("\n\t\tNenhuma conta salva!\n");
		menuAdmin(li);
	}else{
		Lista *aux = li;
		
		do{
			a = abb_insere(a, aux->dadoLis);
			aux = aux->prox;
		}while(aux != li);
	}
	
	printf("\t\tDigite o número da conta para busca: ");
	scanf("%d", &procurar.conta_numero);
	
	a = abb_busca(a, procurar);
	if(!abb_vazia(a)){
		printf("\n\t\tNome do cliente: %s\n", a->dadosArv.nome);
		printf("\t\tIdade do cliente: %d\n", a->dadosArv.idade);
		printf("\t\tEndereço do cliente: %s\n", a->dadosArv.endereco);
		printf("\t\tTipo de conta do cliente: %s\n\n", a->dadosArv.conta_tipo);
	}else{
		printf("\n\t\tConta inexistente ou incorreta!");
		//menuAdmin(li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuAdmin(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\nInválido!\a");
		goto adicionar_invalido;
    }
}

void atualizarConta(Lista *li){
	int escolha;
	Lista *aux = li;
	
	printf("\t\tDigite o número da conta: ");
    scanf("%d", &atualizar.conta_numero);
    
    aux = lcd_busca(aux, atualizar);
    
    if(!lcd_vazia(aux)){
		printf("\n\t\tQual informação deseja alterar?\n\t\t1 : Endereço\n\t\t2 : Telefone\n\t\t");
		scanf("%d",&escolha);
		
		if(escolha == 1){
			
			printf("\t\tDigite o novo endereço: ");
            scanf("%s", atualizar.endereco);
            
            strcpy(aux->dadoLis.endereco, atualizar.endereco);

            printf("\n\t\tAtualização salva!");
        }else if(escolha == 2){
            printf("\t\tDigite o novo telefone: ");
            scanf("%s", atualizar.telefone);
                
            strcpy(aux->dadoLis.telefone, atualizar.telefone);

			printf("\n\t\tAtualização salva!");
        }else{
			printf("\n\t\tEscolha inválida!\n");
			menuAdmin(aux);
		}
	}else{
		printf("\n\t\tConta inexistente ou incorreta!");
		menuAdmin(li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuAdmin(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\n\t\tInválido!\a");
		goto adicionar_invalido;
    }
}
