#include "../includes/lista.h"

int main(){  //PRIMEIRA TELA.
    int escolha;
    
    Lista *li = lcd_cria(); //CRIA A LISTA QUE VAI SER USADA DURANTE TODO O PROGRAMA
    li = abrirArquivo(); //SALVA NA LISTA TUDO QUE ESTAVA EM ARQUIVO
    
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU PRINCIPAL \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1 : Cliente\n\t\t2 : Adminstrador\n\t\t3 : Sair\n\n\t\tDigite sua escolha: ");
    scanf("%d", &escolha);

    switch(escolha){ //CHAMADA PARA AS FUNÇÕES E A LISTA PREENCHIDA COM OS VALORES
        case 1:menuCliente(li);
        break;
        case 2:menuAdmin(li);
        break;
        case 3:fechar(li);
        break;
    }
    return 0;
}
