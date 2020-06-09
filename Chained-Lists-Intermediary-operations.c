#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int valor;
    struct elemento *next;
};

typedef struct elemento elemento;

void insere_elemento_fim(elemento *lista, int num);

int checa_vazia(elemento *lista);

void printar_lista(elemento *lista);

void deletar_repetidos(elemento *lista);

void deletar_repetidos_l1_l2(elemento *lista, elemento *lista2);

void copiar_l1_criando_l2(elemento *lista, elemento *lista2);

void deletar_repetidos_l1_l2(elemento *lista, elemento *lista2);

void juntar_listas(elemento *lista, elemento *lista2);

int main() {
    int num_A, num_B, i;
    elemento *A;
    elemento *B;
    elemento *aux_1;
    elemento *aux_2;

    A = (elemento *)malloc(sizeof(elemento));
    B = (elemento *)malloc(sizeof(elemento));
    aux_1 = (elemento *)malloc(sizeof(elemento));
    aux_2 = (elemento *)malloc(sizeof(elemento));
    A->next = NULL;
    B->next = NULL;
    aux_1->next = NULL;
    aux_2->next = NULL;

    scanf("%d", &num_A);
    for (i = 0; i < num_A; i++) {
        insere_elemento_fim(A, num_A);
    }

    scanf("%d", &num_B);
    for (i = 0; i < num_B; i++) {
        insere_elemento_fim(B, num_B);
    }
    copiar_l1_criando_l2(A, aux_1);

    copiar_l1_criando_l2(B, aux_2);

    deletar_repetidos(A);

    deletar_repetidos(B);

    deletar_repetidos_l1_l2(A, B);

    deletar_repetidos_l1_l2(B, aux_1);

    printar_lista(A);

    printf("\n");

    printar_lista(B);

    printf("\n");

    juntar_listas(A, B);

    printar_lista(A);

    return 0;
}

void insere_elemento_fim(elemento *lista, int num) {
    elemento *search = lista;
    elemento *p;
    int cont = 0;
    p = (elemento *)malloc(sizeof(elemento));
    int flag = 0;

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

void printar_lista(elemento *lista) {
    elemento *procura = lista;

    while (procura->next != NULL) {
        procura = procura->next;
        printf("%d ", procura->valor);
    }
}

void deletar_repetidos(elemento *lista) {
    elemento *fixo;
    elemento *ant;
    elemento *prox;

    for (fixo = lista; fixo != NULL; fixo = fixo->next) {
        ant = fixo;
        for (prox = fixo->next; prox != NULL; prox = prox->next) {
            if (fixo->valor == prox->valor) {
                if (prox->next == NULL) {
                    ant->next = NULL;
                    elemento *remove = prox;
                    free(remove);
                } else {
                    ant->next = prox->next;
                    elemento *remove = prox;
                    free(remove);
                }
            } else {
                ant = prox;
            }
        }
    }
}

void copiar_l1_criando_l2(elemento *lista, elemento *lista2) {
    elemento *p;
    elemento *aux;
    p = (elemento *)malloc(sizeof(elemento));
    lista2->next = p;
    elemento *search = lista;
    do {
        search = search->next;
        p->valor = search->valor;

        if (search->next != NULL) {
            p->next = (elemento *)malloc(sizeof(elemento));
            p = p->next;
        }
    } while (search->next != NULL);
}
void deletar_repetidos_l1_l2(elemento *lista, elemento *lista2) {
    elemento *fixo;
    elemento *ant = lista;
    elemento *prox;

    for (fixo = lista2->next; fixo != NULL; fixo = fixo->next) {
        ant = lista;
        for (prox = ant->next; prox != NULL; prox = prox->next) {
            if (fixo->valor == prox->valor) {
                if (prox->next == NULL) {
                    ant->next = NULL;
                    elemento *remove = prox;
                    free(remove);
                } else {
                    ant->next = prox->next;
                    elemento *remove = prox;
                    free(remove);
                }
            } else {
                ant = prox;
            }
        }
    }
}

void juntar_listas(elemento *lista, elemento *lista2) {
    elemento *search = lista->next;
    do {
        if (search->next == NULL) {
            search->next = lista2->next;
        } else {
            search = search->next;
        }
    } while (search->next != NULL);
}

void liberar_memoria()  // FAZER;
