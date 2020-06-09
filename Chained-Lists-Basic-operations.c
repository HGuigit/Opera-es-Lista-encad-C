#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int valor;
    struct elemento *next;
};

typedef struct elemento elemento;

void insere_elemento_ini(elemento *lista);

void insere_elemento_fim(elemento *lista);

void insere_elemento_pos(elemento *lista);

void printar_lista(elemento *lista);

int checa_vazia(elemento *lista);

void excluir_elemento(elemento *lista, char excl);

int main() {
    int resp;
    char excl;
    elemento *lista;
    lista = (elemento *)malloc(sizeof(elemento));

    do {
        printf(
            "O que deseja fazer?\n 1 - Inserir um elemento no inicio\n 2 - "
            "Imprimir lista\n 3 - Inserir um elemento no final da lista\n 4 - "
            "checar se a lista esta vazia\n 5 - Insere um elemento em alguma "
            "posicao\n 6 - Exclui um elemento por valor ou posicao\n 10 - "
            "Parar \n\n");
        scanf("%d", &resp);
        if (resp == 1) insere_elemento_ini(lista);
        if (resp == 2) printar_lista(lista);
        if (resp == 3) insere_elemento_fim(lista);

        if (resp == 4) printf("\n%d\n", checa_vazia(lista));
        if (resp == 5) insere_elemento_pos(lista);
        if (resp == 6) {
            printf("Deseja excluir por (e)lemento ou por (p)osição?\n");
            fflush(stdin);
            scanf("%c", &excl);
            fflush(stdin);
            excluir_elemento(lista, excl);
        }
    } while (resp != 10);
}

void insere_elemento_ini(elemento *lista) {
    elemento *p;
    elemento *aux;
    p = (elemento *)malloc(sizeof(elemento));
    printf("Digite qual elemento deseja inserir:\n");
    scanf("%d", &p->valor);
    aux = lista->next;
    lista->next = p;
    p->next = aux;
}

void printar_lista(elemento *lista) {
    elemento *search = lista;

    do {
        search = search->next;
        printf("\n%d\n", search->valor);

    } while (search->next != NULL);
}

void insere_elemento_fim(elemento *lista) {
    elemento *search = lista;
    elemento *p;
    p = (elemento *)malloc(sizeof(elemento));
    int flag = 0;
    printf("Digite o valor que deseja inserir na lista:\n");
    scanf("%d", &p->valor);
    if (checa_vazia(lista) == 1) {
        lista->next = p;
        p->next = NULL;
    }
    do {
        if (search->next == NULL) {
            search->next = p;
            p->next = NULL;
            flag++;
        }
        search = search->next;
    } while (flag == 0);
}
int checa_vazia(elemento *lista) {
    if (lista->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}
void insere_elemento_pos(elemento *lista) {
    int pos;
    int achou = 0;
    int cont = 0;
    int num;
    elemento *prox = lista->next;
    elemento *anterior = lista;
    elemento *p;
    p = (elemento *)malloc(sizeof(elemento));
    printf(
        "Digite em qual posicao da lista voce deseja inserir um "
        "elemento\n");
    scanf("%d", &pos);
    printf("Digite qual o elemento que voce deseja inserir:\n");
    scanf("%d", &num);
    while (prox != NULL) {
        if (cont == pos) {
            anterior->next = p;
            p->next = prox;
            p->valor = num;
            achou++;
        }
        prox = prox->next;
        anterior = anterior->next;
        cont = cont + 1;
    }
    if (!achou) {
        printf("Impossivel inserir na lista, a lista tem tamanho:%d\n", cont);
    }
}

void excluir_elemento(elemento *lista, char excl) {
    int num;
    elemento *anterior = lista;
    elemento *prox = lista->next;
    int cont = 0;
    int flag;
    int pos;

    if (excl == 'e' || excl == 'E') {
        printf("Digite qual elemento deseja excluir:\n");
        scanf("%d", &num);
        do {
            if (prox->valor == num) {
                anterior->next = prox->next;
                free(prox);
                flag++;
            }
            prox = prox->next;
            anterior = anterior->next;
        } while (flag != 1);
    }
    if (excl == 'p' || excl == 'P') {
        printf("Digite qual posicao desja excluir:\n");
        scanf("%d", &pos);
        do {
            if (cont == pos) {
                anterior->next = prox->next;
                free(prox);
                flag++;
            }
            cont++;
            prox = prox->next;
            anterior = anterior->next;
        } while (flag != 1);
    }
}
