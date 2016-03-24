#include "../includes/lista.h"

void fechar(Lista *li){ //O PROGRAMA FINALIZA DE FATO AQUI, NOTE QUE, A FUNÇÃO FECHAR ARQUIVO É CHAMADA AQUI
	
	fecharArquivo(li);
	
	printf("\n\n\t\tSistema bancário FECHADO!\n\n");
}
