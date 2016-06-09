#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _estado{
    char gravacao;
    char move_fita;
    int proximo_estado;
    int estado;
    int iniciado;

}estado;
char alfabeto[30];
//a tabela de trasicao e baseada em tabela_transicao[size_alfabeto][size_transicoes]
estado **tabela_transicao;
int estado_atual;
int estado_inicial, estado_final;
int get_index_from_char(char *string, char c){
    char *e;
    e = strchr(string, c);
    return (int)(e - string);

}
void testeExpressao(estado **maquina, char *string){
    //int size = strlen(string);
    int x = 0;
    estado *estado_presente;
    estado_atual = estado_inicial;
    char strin[100];
    strcpy(strin, string);
    char *c = string;
    while(1){

        if (*c == '\0'){
            if (estado_atual == 3)
                estado_atual++;
            break;
        }
        int z = get_index_from_char(alfabeto, *c);
        estado_presente = &tabela_transicao[z][estado_atual];

        string[x] = estado_presente->gravacao;
        if (estado_presente->move_fita == 'D'){
            c++;
            x++;
            
        } else {
            
            c--;
            x--;
            
        }
    
        estado_atual = (tabela_transicao[z][estado_presente->estado]).proximo_estado;
    }
    if (estado_atual == estado_final)
        printf("%s OK\n", strin);
    else
        printf("%s not OK\n", strin);
}
int main(int argc , char *argv[])
{
    FILE *file_input;
    int numero_transicoes, numero_estados;
    int contagem_alfabeto;
    int x, aux_int;
    char aux;
    int estado_atual, proximo_estado;
    char leitura_atual;
    char fita[100];
    estado_inicial = -1;
    if (argc < 1){
        exit(EXIT_FAILURE);
    }
    file_input = fopen (argv[1], "r");
    if (file_input == NULL){
        exit(EXIT_FAILURE);
    }
    fscanf(file_input, "%s", alfabeto);
    fscanf(file_input, "%d", &numero_estados);
    estado_final = numero_estados -1;
    fscanf(file_input, "%d", &numero_transicoes);
    contagem_alfabeto = strlen(alfabeto) + 1;
    tabela_transicao = (estado **)calloc(contagem_alfabeto, sizeof(estado*));
    for( x= 0; x < contagem_alfabeto; x++)
        tabela_transicao[ x ] = (estado *)calloc(numero_estados, sizeof(estado));
    fscanf(file_input, "%c", &aux);
    x = 0; 
    while (x < numero_transicoes){
        estado *novo_estado = malloc(sizeof(estado));
        fscanf(file_input, "%d", &estado_atual);
        estado_atual--;
        novo_estado->estado = estado_atual;
        fscanf(file_input, "%*[ \n\t]%c", &leitura_atual);
        fscanf(file_input, "%*[ \n\t]%c", &(novo_estado->gravacao));
        fscanf(file_input, "%*[ \n\t]%c", &(novo_estado->move_fita));
        fscanf(file_input, "%d", &(proximo_estado));
        novo_estado->proximo_estado = proximo_estado-1;
        fscanf(file_input, "%c", &aux);
        aux_int = get_index_from_char(alfabeto, leitura_atual);
        if (leitura_atual == '-'){
            aux_int = contagem_alfabeto-1;
        }
        if (estado_inicial == -1){
            estado_inicial = novo_estado->estado;
        }
        novo_estado->iniciado = 1;
        tabela_transicao[aux_int][estado_atual] = *novo_estado;
        x++;
    }
    fscanf(file_input, "%d", &(numero_transicoes));
    x = 0;
    do {
        fscanf(file_input, "%s", fita);

        testeExpressao(tabela_transicao, fita);
        x++;
    }while (x < numero_transicoes);
    return 0;
}
