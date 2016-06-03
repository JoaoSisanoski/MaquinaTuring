#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char alfabeto[30];

typedef struct _estado{
    char gravacao;
    char move_fita;
    int proximo_estado;

}estado;
int get_index_from_char(char *string, char c){
    char *e;
    e = strchr(string, c);
    return (int)(e - string);

}
void testeExpressao(estado **maquina, char *string){
    char *index = string;
    int x = get_index_from_char(alfabeto, &(index));





}
int main(int argc , char *argv[])
{
    FILE *file_input;
    estado **tabela_transicao;
    int numero_transicoes, numero_estados;
    int contagem_alfabeto;
    int x, aux_int;
    char aux;
    int estado_atual;
    char leitura_atual;
    if (argc < 1){
        exit(EXIT_FAILURE);
    }
    file_input = fopen (argv[1], "r");
    if (file_input == NULL){
        exit(EXIT_FAILURE);
    }
    fscanf(file_input, "%s", alfabeto);
    printf("%s", alfabeto);
    fscanf(file_input, "%d", &numero_estados);
    fscanf(file_input, "%d", &numero_transicoes);
    contagem_alfabeto = strlen(alfabeto) + 1;
    tabela_transicao = (estado **)malloc(contagem_alfabeto  * sizeof(estado*));
    for( x= 0; x < contagem_alfabeto; x++)
        tabela_transicao[ x ] = (estado *)malloc(numero_estados * sizeof(estado));
    //consome quebra de linha
    fscanf(file_input, "%c", &aux);
    x = 0;
    while (x < numero_transicoes){
        fscanf(file_input, "%d", &estado_atual);
        estado_atual--;
        fscanf(file_input, "%*[ \n\t]%c", &leitura_atual);
        estado novo_estado;
        fscanf(file_input, "%*[ \n\t]%c", &(novo_estado.gravacao));
        fscanf(file_input, "%*[ \n\t]%c", &(novo_estado.move_fita));
        fscanf(file_input, "%d", &(novo_estado.proximo_estado));
        //consome quebra de linha
        fscanf(file_input, "%c", &aux);
        aux_int = get_index_from_char(alfabeto, leitura_atual);
        if (leitura_atual == '-'){
            aux_int = contagem_alfabeto-1;
        }
        tabela_transicao[aux_int][estado_atual] = novo_estado;
        x++;
    }
    fscanf(file_input, "%d", &(numero_transicoes));


    return 0;
}
