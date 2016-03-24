#include "../includes/lista.h"

void menuAdmin(Lista *li){ //TELA USUÁRIO
    int escolha;
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU ADMINISTRADOR \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1 : Cria nova conta\n\t\t2 : Remove conta\n\t\t3 : Lista todas contas\n\t\t4 : Detalhes de uma conta\n\t\t5 : Buscar conta\n\t\t6 : Atualizar dados de conta\n\t\t7 : Sair\n\n\t\tDigite sua escolha: ");
    scanf("%d", &escolha);

    switch(escolha){ //RECEBE A LISTA DA PRIMEIRA TELA E PASSA PARA A ESCOLHA FEITA PELO USUÁRIO PARA SUAS OPERAÇÕES
        case 1:criaConta(li);
        break;
        case 2:removeConta(li);
        break;
        case 3:listaContas(li);
        break;
        case 4:detalhesConta(li);
        break;
        case 5:buscaConta(li);
        break;
        case 6:atualizarConta(li);
        break;
        case 7:fechar(li);
        break;
    }
}
