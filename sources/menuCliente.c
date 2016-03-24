#include "../includes/lista.h"

void menuCliente(Lista *li){ //TELA ADMINISTRADOR
    int escolha;
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU CLIENTE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1 : Saque\n\t\t2 : Deposito\n\t\t3 : Transferencia\n\t\t4 : Verificar Saldo\n\t\t5 : Sair\n\n\t\tDigite sua escolha: ");
    scanf("%d", &escolha);

    switch(escolha){ //RECEBE A LISTA DA PRIMEIRA TELA E PASSA PARA A ESCOLHA FEITA PELO ADMIN PARA SUAS OPERAÇÕES
        case 1:saque(li);
        break;
        case 2:deposito(li);
        break;
        case 3:transferencia(li);
        break;
        case 4:verificaSaldo(li);
        break;
        case 5:fechar(li);
        break;
    }
}
