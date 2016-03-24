#ifndef _COMUM_H_
#define _COMUM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main_fechar; // USADO POR TODO O SISTEMA PARA FAZER O CONTROLE DE MENUS

struct date {
    int dia, mes, ano;
};

struct registro {
    char nome[60];
    unsigned conta_numero, idade;
    char endereco[60];
    char cep[15];
    char telefone[10];
    char conta_tipo[10];
    float quantidade;
    struct date data_nascimento;
    struct date deposito;
    struct date retirar;
}adicionar, atualizar, procurar, remover, sacar, depositar, transacao;

struct lista 
{
	struct registro dadoLis;
	struct lista* ante;
	struct lista* prox;
};
typedef struct lista Lista;

//MENUS
void menuCliente(); //TELA (printf) PARA AS OPERAÇÕES DO CLIENTE
void menuAdmin(); //TELA (printf) PARA AS OPERAÇÕES DO ADMINISTRADOR

//CLIENTE     OPERAÇÕES
void saque();
void deposito();
void transferencia();
void verificaSaldo();

//ADMININSTRADOR     OPERAÇÕES
void criaConta();
void removeConta();
void listaContas();
void detalhesConta();
void buscaConta();
void atualizarConta();

//GERAIS
void fechar(); //IMPRIME MENSAGEM DO SISTEMA FECHADO
Lista* abrirArquivo(); //ABRE O ARQUIVO E SALVA TUDO EM MEMÓRIA
void fecharArquivo(Lista *li); //SALVA TUDO QUE ESTAVA EM MEMÓRIA NO ARQUIVO

#endif
