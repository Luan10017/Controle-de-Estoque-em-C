#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regrasDeControle.h"


int main()
{
        struct dados info;
        struct dados *ponteiroStruct;
        int opcao;
        int i;
        int tam;    //n. de bytes da estrutura

        ponteiroStruct = & info;
        tam = sizeof(struct dados);

        while(1){
        printf(" 1  -Inclua dados  \n");
        printf(" 2  -Lista dados  \n");
        printf(" 3  -Pesquisa dados  \n");
        printf(" 4  -Pesquisa letra  \n");
        printf(" 5  -Pesquisa validade  \n");
        printf(" 6  -Lista itens abaixo de estoque min  \n");
        printf(" 7  -Entrada de produto  \n");
        printf(" 8  -Saida de produto  \n");
        printf(" 9  -Altera dados  \n");
        printf(" 10 -Exclui dados  \n");
        printf(" 11 -Saida\n");
        scanf("%d", &opcao);
        getchar();


    switch(opcao)
                {
                case 1 : inclui(ponteiroStruct, tam);   //passa como parametro o ponteiro para a estrutura e o n. de bytes da desta
                break;

                case 2: lista(ponteiroStruct, tam);
                break;

                case 3: pesquisa(ponteiroStruct, tam);
                break;

                case 4: pesquisaLetra(ponteiroStruct, tam);
                break;

                case 5: pesquisaValidade(ponteiroStruct, tam);
                break;

                case 6: listaMinimo(ponteiroStruct, tam);
                break;

                case 7: entrada(ponteiroStruct, tam);
                break;

                case 8: saida(ponteiroStruct, tam);
                break;

                case 9: altera(ponteiroStruct, tam);
                break;

                case 10: exclui(ponteiroStruct, tam);
                break;

                case 11: exit(0);
                break;

                default: printf("\n opcao invalida\n");
                }
    };

}


