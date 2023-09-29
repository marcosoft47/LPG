#include <stdlib.h>
#include <stdio.h>
//Estruturas
struct data{
    int dia;
    int mes;
    int ano;
};
struct pessoa{
    char nome[30];
    char cpf[11];
    struct data nascimento;
};
//Funções
void setPessoa(struct pessoa *p){
    printf("Digite o nome: ");
    gets(p->nome);
    printf("Digite o CPF: ");
    gets(p->cpf);
    setData(&p ->nascimento);
}
void getPessoa (struct pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("CPF: %s\n", p.cpf);
    printf("Data de nascimento: %i/%i/%i\n", p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);
};
void setData(struct data *d){
    printf("Digite a data (dd mm aaaa): ");
    scanf("%i", &d->dia);
    scanf("%i", &d->mes);
    scanf("%i", &d->ano);
}
void getData(struct data d){
    printf("%i/%i/%i", d.dia, d.mes, d.ano);
}
//Programa principal
int main(){
    struct pessoa fulano;
    setPessoa(&fulano);
    getPessoa(fulano);
}