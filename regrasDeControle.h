#ifndef REGRASDECONTROLE_H_INCLUDED
#define REGRASDECONTROLE_H_INCLUDED

struct dados
{
    char nome[20];
    int quantidade;
    int estoqueMin;
    int validadeMes;
    int validadeAno;
    //elementos da estrutura
};

void inclui(struct dados *ps, int tam)
{
    FILE *ponteiroProduto, *ponteiroContador;
    int cont = 0;
    int i;

    ponteiroContador = fopen("contador.txt", "r");
    fscanf(ponteiroContador,"%d",&cont);
    printf("contador antes %d\n",cont);
    fclose(ponteiroContador);

    //zera os dados da estrutura

    ponteiroProduto = fopen("arquivo.txt", "a");

    if( ponteiroProduto == NULL)
    {
        printf("\nERRO");
        exit(1);
    }

    //aqui os dados sao recebidos via teclado


    printf("Nome: ");
    fflush(stdin);
    gets(ps->nome);
    printf("Quantidade: ");
    scanf("%d",&ps->quantidade);
    printf("Estoque minimo: ");
    scanf("%d",&ps->estoqueMin);
    printf("Mes de validade: ");
    scanf("%d",&ps->validadeMes);
    printf("Ano de validade: ");
    scanf("%d",&ps->validadeAno);

    fwrite(ps, tam,1,ponteiroProduto);
    fclose(ponteiroProduto);

    cont++;

    ponteiroContador = fopen("contador.txt", "w");
    fprintf(ponteiroContador,"%d",cont);
    printf("contador depois %d\n",cont);
    fclose(ponteiroContador);
}

void lista(struct dados *ps, int tam)
{
    FILE *ponteiroProduto, *ponteiroContador;
    int i;
    int cont,comp;

    ponteiroContador = fopen("contador.txt", "r");
    fscanf(ponteiroContador,"%d",&cont);
    printf("%d\n",cont);
    fclose(ponteiroContador);

    ponteiroProduto = fopen("arquivo.txt", "r"); /*r" --> Abre o arquivo apenas para leitura.*/

    if( ponteiroProduto== NULL)
    {
        puts("\nERRO\n");
        exit(1);
    }

    for(i=0; i<cont; i++)
    {
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(ponteiroProduto,comp,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(ps,tam,1,ponteiroProduto);   //le o registro
        if(ps -> nome[0] != '*')
        {
            //verifica se esta apagado
            //imprimi registro na tela
            printf("\nNome do usuario: \t%s",ps->nome);
            printf("\nQuantidade: \t\t%d",ps->quantidade);
            printf("\nEstoque minimo: \t%d",ps->estoqueMin);
            printf("\nMes de validade: \t%d",ps->validadeMes);
            printf("\nAno de validade: \t%d",ps->validadeAno);
        }
        printf("\n\n");
    }
    fclose(ponteiroProduto);
}

int pesquisa(struct dados *ps, int tam)
{
    FILE *ponteiroProduto, *ponteiroContador;
    int y,x;
    int cont,comp;
    char nome1[20];

    printf("Informe um nome para pesquisa: ");
    gets(nome1);

    ponteiroContador = fopen("contador.txt", "r");
    fscanf(ponteiroContador,"%d",&cont);
    printf("%d\n",cont);
    fclose(ponteiroContador);

    ponteiroProduto = fopen("arquivo.txt", "r"); /*r" --> Abre o arquivo apenas para leitura.*/

    if( ponteiroProduto== NULL)
    {
        puts("\nERRO\n");
        exit(1);
    }

    for(y=0; y<cont; y++)
    {
        fread(ps,tam,1,ponteiroProduto);
        for(x = 0; nome1[x] != '\0'; x++)
        {
            if(nome1[x] != ps->nome[x])
            {
                break;
            }
        }
        if(nome1[x] == '\0' && ps->nome[x] == '\0')
        {
            printf("n. do reg.: %d\n",y);
            return y;
        }
    }
    printf("reg. nao existe\n");
    return -1;

    fclose(ponteiroProduto);
}


void pesquisaLetra(struct dados *ps, int tam)
{
    FILE *ponteiroProduto, *ponteiroContador;
    int i;
    int cont,comp;
    char nome1[20];

    printf("Informe um nome para pesquisa: ");
    gets(nome1);

    ponteiroContador = fopen("contador.txt", "r");
    fscanf(ponteiroContador,"%d",&cont);
    printf("%d\n",cont);
    fclose(ponteiroContador);

    ponteiroProduto = fopen("arquivo.txt", "r"); /*r" --> Abre o arquivo apenas para leitura.*/

    if( ponteiroProduto== NULL)
    {
        puts("\nERRO\n");
        exit(1);
    }

    for(i=0; i<cont; i++)
    {
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(ponteiroProduto,comp,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(ps,tam,1,ponteiroProduto);   //le o registro
        if(nome1[0] == ps -> nome[0] && ps -> nome[0] != '*')
        {
            //verifica se esta apagado
            //imprimi registro na tela
            printf("\nNome do usuario: \t%s",ps->nome);
            printf("\nQuantidade: \t\t%d",ps->quantidade);
            printf("\nEstoque minimo: \t%d",ps->estoqueMin);
            printf("\nMes de validade: \t%d",ps->validadeMes);
            printf("\nAno de validade: \t%d",ps->validadeAno);
            printf("\n\n");
        }

    }
    fclose(ponteiroProduto);
}


void pesquisaValidade(struct dados *ps, int tam)
{
    FILE *ponteiroProduto, *ponteiroContador;
    int i,mes,ano;
    int cont,comp;

    ponteiroContador = fopen("contador.txt", "r");
    fscanf(ponteiroContador,"%d",&cont);
    printf("%d\n",cont);
    fclose(ponteiroContador);

    ponteiroProduto = fopen("arquivo.txt", "r"); /*r" --> Abre o arquivo apenas para leitura.*/

    if( ponteiroProduto== NULL)
    {
        puts("\nERRO\n");
        exit(1);
    }

    printf("Informe mes a ser pesquisado: ");
    scanf("%d",&mes);
    printf("Informe ano a ser pesquisado: ");
    scanf("%d",&ano);


    for(i=0; i<cont; i++)
    {
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(ponteiroProduto,comp,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(ps,tam,1,ponteiroProduto);   //le o registro
        if(ps -> nome[0] != '*' && mes == ps->validadeMes && ano == ps->validadeAno )
        {
            //verifica se esta apagado
            //imprimi registro na tela
            printf("\nNome do usuario: \t%s",ps->nome);
            printf("\nQuantidade: \t\t%d",ps->quantidade);
            printf("\nEstoque minimo: \t%d",ps->estoqueMin);
            printf("\nMes de validade: \t%d",ps->validadeMes);
            printf("\nAno de validade: \t%d",ps->validadeAno);
        }
        printf("\n\n");
    }
    fclose(ponteiroProduto);
}

void listaMinimo(struct dados *ps, int tam)
{
    FILE *ponteiroProduto, *ponteiroContador;
    int i;
    int cont,comp;

    ponteiroContador = fopen("contador.txt", "r");
    fscanf(ponteiroContador,"%d",&cont);
    printf("%d\n",cont);
    fclose(ponteiroContador);

    ponteiroProduto = fopen("arquivo.txt", "r"); /*r" --> Abre o arquivo apenas para leitura.*/

    if( ponteiroProduto== NULL)
    {
        puts("\nERRO\n");
        exit(1);
    }

    for(i=0; i<cont; i++)
    {
        comp = i*tam;   //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(ponteiroProduto,comp,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(ps,tam,1,ponteiroProduto);   //le o registro
        if(ps -> nome[0] != '*' && (ps ->estoqueMin) > (ps ->quantidade))
        {
            //verifica se esta apagado
            //imprimi registro na tela
            printf("\nNome do usuario: \t%s",ps->nome);
            printf("\nQuantidade: \t\t%d",ps->quantidade);
            printf("\nEstoque minimo: \t%d",ps->estoqueMin);
            printf("\nMes de validade: \t%d",ps->validadeMes);
            printf("\nAno de validade: \t%d",ps->validadeAno);
        }
        printf("\n\n");
    }
    fclose(ponteiroProduto);
}

void entrada(struct dados *ps, int tam)
{
    FILE *ponteiroProduto;
    int n_reg;
    int n_bytes;

    n_reg = pesquisa(ps, tam);  //pesquisa o registro no arquivo

    ponteiroProduto = fopen("arquivo.txt", "r+");
    n_bytes = tam * n_reg;

    fseek(ponteiroProduto,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser apagado
    fread(ps, tam, 1, ponteiroProduto );   //le o registro do arquivo
    printf("nome do produto para entrada e' %s\n",ps -> nome);
    //apaga o registro do arquivo

    ps -> quantidade++;

    fseek(ponteiroProduto,n_bytes,0);  //posiciona o ponteiro do arquivo no inicio do regisro a ser apagado
    fwrite(ps,tam,1,ponteiroProduto);  //escreve o registro

    fclose(ponteiroProduto);

}

void saida(struct dados *ps, int tam)
{
    FILE *ponteiroProduto;
    int n_reg;
    int n_bytes;

    n_reg = pesquisa(ps, tam);  //pesquisa o registro no arquivo


    ponteiroProduto = fopen("arquivo.txt", "r+");
    n_bytes = tam * n_reg;

    fseek(ponteiroProduto,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser apagado
    fread(ps, tam, 1, ponteiroProduto );   //le o registro do arquivo
    printf("nome do produto para saida e' %s\n",ps -> nome);
    //apaga o registro do arquivo

    ps -> quantidade--;

    fseek(ponteiroProduto,n_bytes,0);  //posiciona o ponteiro do arquivo no inicio do regisro a ser apagado
    fwrite(ps,tam,1,ponteiroProduto);  //escreve o registro

    fclose(ponteiroProduto);

}


void altera(struct dados *ps, int tam)
{
    FILE *ponteiroProduto;
    int n_reg;;
    int n_bytes;

    n_reg = pesquisa(ps, tam);     //pesquisa o registro no arquivo

    printf("altera reg n.: %d\n",n_reg);
    n_bytes = tam * n_reg;

    ponteiroProduto = fopen("arquivo.txt", "r+");

    fseek(ponteiroProduto,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser alterado
    fread(ps, tam, 1, ponteiroProduto );  //le registro do arquivo

    printf("recebe os dados para alteracao: ");

    printf("Nome: ");
    fflush(stdin);
    gets(ps->nome);
    printf("Quantidade: ");
    scanf("%d",&ps->quantidade);
    printf("Estoque minimo: ");
    scanf("%d",&ps->estoqueMin);
    printf("Mes de validade: ");
    scanf("%d",&ps->validadeMes);
    printf("Ano de validade: ");
    scanf("%d",&ps->validadeAno);
    //recebe via teclado todos os dados do registro

    fseek(ponteiroProduto,n_bytes,0);    //posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
    fwrite(ps, tam,1,ponteiroProduto);  //escreve o registro no arquivo

    fclose(ponteiroProduto);
}

void exclui(struct dados *ps, int tam)
{
    FILE *ponteiroProduto;
    int n_reg;
    int n_bytes;

    n_reg = pesquisa(ps, tam);  //pesquisa o registro no arquivo

    ponteiroProduto = fopen("arquivo.txt", "r+");
    n_bytes = tam * n_reg;

    fseek(ponteiroProduto,n_bytes,0);       //posioiona o ponteiro do arquivo no registro a ser apagado
    fread(ps, tam, 1, ponteiroProduto );   //le o registro do arquivo
    printf("nome para apagar e' %s\n",ps -> nome);
    //apaga o registro do arquivo

    ps -> nome[0]='*';

    fseek(ponteiroProduto,n_bytes,0);  //posiciona o ponteiro do arquivo no inicio do regisro a ser apagado
    fwrite(ps,tam,1,ponteiroProduto);  //escreve o registro

    fclose(ponteiroProduto);

}


#endif // REGRASDECONTROLE_H_INCLUDED
