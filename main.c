#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char leitura;
    char escrita;
}acao;
typedef struct _estado{
    acao *acao_fita;
    char move_fita;
    int proximo_estado;

}estado;
int get_index_from_char(char *string, char c){
    char *e;
    e = strchr(string, c);
    return (int)(e - string);

}
int main(int argc , char *argv[])
{
    FILE *file_input;
    int **tabela_transicao;
    char alfabeto[30];
    int numero_transicoes, numero_estados;
    int contagem_alfabeto;
    int x;


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
    //fscanf(file_input, "%d", &numero_transicoes);


    contagem_alfabeto = strlen(alfabeto) + 1;
    tabela_transicao = (int **)malloc(contagem_alfabeto  * sizeof(int*));
    for( x= 0; x < contagem_alfabeto; x++)
        tabela_transicao[ x ] = (int *)malloc(numero_estados * sizeof(int));



    x = 0;
    while (x < numero_transicoes){

        x++;
    }


    return 0;
}
