/*
	TODAS AS IMPLEMENTAÇÕES DAS OPERAÇÕES FEITA PELO USUÁRIO
*/

#include "../includes/lista.h"

void saque(Lista *li){
	printf("\t\tDigite o número de sua conta: ");
    scanf("%d", &sacar.conta_numero);
    
    Lista *aux = li;
    aux = lcd_busca(aux, sacar);
    
    if(!lcd_vazia(aux)){
		printf("\t\tDigite o valor de Saque:$ ");
		scanf("%f", &sacar.quantidade);
		
		if(aux->dadoLis.quantidade >= sacar.quantidade){
			aux->dadoLis.quantidade -= sacar.quantidade;
			printf("\t\tSaque realizado com sucesso!");
		}else{
			printf("\t\tSaldo insuficiente!");
			menuCliente(li);
		}
	}else{
		printf("\t\tConta inexistente ou incorreta!");
		menuCliente(li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuCliente(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\nInválido!\a");
		goto adicionar_invalido;
    }
}

void deposito(Lista *li){
	printf("\t\tDigite o número de sua conta: ");
    scanf("%d", &depositar.conta_numero);
    
    Lista *aux = li;
    aux = lcd_busca(aux, depositar);
    
    if(!lcd_vazia(aux)){
		printf("\t\tDigite o valor de Depósito:$ ");
		scanf("%f", &depositar.quantidade);
		aux->dadoLis.quantidade += depositar.quantidade;
	}else{
		printf("\t\tConta inexistente ou incorreta!");
		menuCliente(li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuCliente(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\nInválido!\a");
		goto adicionar_invalido;
    }
	//~ lcd_imprime(aux);
}

void transferencia(Lista *li){
	float val_trans = 0;
	
	printf("\t\tDigite o número de sua conta: ");
    scanf("%d", &transacao.conta_numero);
    
    Lista *aux = li;
    aux = lcd_busca(aux, transacao);
    
    if(!lcd_vazia(aux)){
		printf("\t\tDigite o valor de transferência: ");
		scanf("%f", &val_trans);
		
		if(aux->dadoLis.quantidade >= val_trans){
			aux->dadoLis.quantidade -= val_trans;
			
			printf("\t\tDigite o número da conta destinatária: ");
			scanf("%d", &procurar.conta_numero);
			
			aux = lcd_busca(aux, procurar);
			if(!lcd_vazia(aux)){
				aux->dadoLis.quantidade += val_trans;
			}else{
				printf("\t\tConta do destinátario não existe ou incorreta!\n\n");
				menuCliente(li);
			}
		}else{
			printf("\t\tDinheiro em caixa insuficiente!\n\n");
			menuCliente(li);
		}
	}else{
		printf("\t\tConta inexistente ou incorreta!\n\n");
		menuCliente(li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuCliente(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\nInválido!\a");
		goto adicionar_invalido;
    }
}

void verificaSaldo(Lista *li){
	printf("\t\tDigite o número de sua conta: ");
    scanf("%d", &procurar.conta_numero);
    
    Lista *aux = li;
    aux = lcd_busca(aux, procurar);
    
    if(!lcd_vazia(aux)){
		printf("\n\t\tSeu saldo é %.2f\n\n", aux->dadoLis.quantidade);
	}else{
		printf("Conta inexistente ou incorreta!");
		menuCliente(li);
	}
	
	adicionar_invalido:
    printf("\n\n\n\t\tDigite 1 para ir ao Menu e 0 para Sair: ");
    scanf("%d",&main_fechar);
    
    if(main_fechar==1){
        menuCliente(li);
	}
    else if(main_fechar==0){
		fechar(li);
	}
    else{
        printf("\n\t\tInválido!\a");
		goto adicionar_invalido;
    }
}
