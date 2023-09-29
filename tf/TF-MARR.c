#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//estruturas
struct data{
    int dia;
    int mes;
    int ano;
};
struct horario{
    int hora;
    int minuto;
};
struct evento{
    struct data data;
    struct horario horario_inicio;
    struct horario horario_fim;
    char descricao[20];
    char local[20];
};
//fim estruturas
//getters e setters
void getData(struct data p){
    printf("%.2i/%.2i/%.4i\n", p.dia, p.mes, p.ano);
}
void setData(struct data *p){
    while (1){
        printf("Insira a data (dd mm aaaa): ");
        scanf("%i", &p->dia);
        scanf("%i", &p->mes);
        scanf("%i", &p->ano);
        //Eu poderia verificar se o mês tem 30 ou 31 dias, ou se é ano bissexto
        //Poderia, mas não vou, mas poderia...
        if (p->dia > 31 || p->dia <= 0){
            printf("ERRO: Dia inválido!\n");
            continue;
        }
        if (p->mes > 12 || p->mes <= 0){
            printf("ERRO: Mês inválido!\n");
            continue;
        }
        break;   
    }
}
void getHorario(struct horario p){
    printf("%.2i:%.2i\n", p.hora, p.minuto);
}
void setHorario(struct horario *p){
    while (1){
        printf("Insira o horário (hh mm): ");
        scanf("%i", &p->hora);
        scanf("%i", &p->minuto);
        if(p->hora >= 24 || p->hora < 0 || p->minuto < 0 || p->minuto >= 60){
            printf("ERRO!\nHorario inválido");
            continue;
        }
        break;
    }
}
void getEvento(struct evento p){
    getData(p.data);
    getHorario(p.horario_inicio);
    getHorario(p.horario_fim);
    printf("Descrição: %s\n", p.descricao);
    printf("Local: %s\n", p.local);
}
void setEvento(struct evento *p){
    printf("Informe a descrição do evento: ");
    scanf("%s", p->descricao);
    printf("Informe o local do evento: ");
    scanf("%s", p->local);
    setData(&p->data);
    int horarioInicio = 0;
    int horarioFim = 0;
    while (1){
        printf("Horario de inicio:\n");
        setHorario(&p->horario_inicio);
        printf("Horario de fim:\n");
        setHorario(&p->horario_fim);
        horarioInicio = p->horario_inicio.hora * 60 + p->horario_inicio.minuto;
        horarioFim = p->horario_fim.hora * 60 + p->horario_fim.minuto;
        if (horarioFim < horarioInicio)
            printf("ERRO!\nHorário de inicio deve ser antes do horario de fim!\n");
        else
            break;
    }
}
//fim getters e setters
//funções gerais
int verificarConflito(struct evento eventoCadastrado, int n, struct evento *agenda) {
    int horarioCadastradoInicio = eventoCadastrado.horario_inicio.hora * 60 + eventoCadastrado.horario_inicio.minuto;
    int horarioCadastradoFim = eventoCadastrado.horario_fim.hora * 60 + eventoCadastrado.horario_fim.minuto;

    for (int i = 0; i < n; i++) {
        int horarioAgendaInicio = agenda[i].horario_inicio.hora * 60 + agenda[i].horario_inicio.minuto;
        int horarioAgendaFim = agenda[i].horario_fim.hora * 60 + agenda[i].horario_fim.minuto;

        if (strcmp(eventoCadastrado.local, agenda[i].local) == 0 &&
            eventoCadastrado.data.dia == agenda[i].data.dia &&
            eventoCadastrado.data.mes == agenda[i].data.mes &&
            eventoCadastrado.data.ano == agenda[i].data.ano &&
            ((horarioCadastradoInicio >= horarioAgendaInicio && horarioCadastradoInicio < horarioAgendaFim) ||
             (horarioCadastradoFim > horarioAgendaInicio && horarioCadastradoFim <= horarioAgendaFim))) {
            printf("ERRO!\nConflito de horário com o evento %d!\n", i + 1);
            return 0;
        }
    }
    return 1;
}
int main(){
    int escolha = 1, count = 0, i, deuboa = 0;
    struct data dataEscolhida;
    char descricaoEscolhida[20];
    struct evento *agenda;
    struct evento eventoCadastrado;
    agenda = malloc(sizeof(struct evento));
    while (escolha != 0){
        printf("Escolha uma opção:\n");
        printf("(0) Sair do programa.\n");
        printf("(1) Cadastro de um novo evento.\n");
        printf("(2) Apresentação de todos os eventos.\n");
        printf("(3) Apresentação dos eventos por data.\n");
        printf("(4) Apresentação dos eventos por descrição.\n");
        printf("(5) Remover evento.\n");

        scanf("%i", &escolha);
        printf("\n");
        switch (escolha){
        case 1:
            while (!deuboa){
                setEvento(&eventoCadastrado);
                deuboa = verificarConflito(eventoCadastrado, count, agenda);
                if (deuboa){
                    count++;
                    agenda = realloc(agenda, sizeof(struct evento) * count);
                    agenda[count-1] = eventoCadastrado;
                }
            }
            escolha = 1;
            deuboa = 0;
            printf("\n");
            break;
        case 2:
            for (i = 0; i < count; i++){
                printf("Evento %i\n", i+1);
                getEvento(agenda[i]);
                printf("\n\n");
            }
            break;
        case 3:
            printf("Informe a data desejada (dd mm aaaa): ");
            scanf("%i %i %i", &dataEscolhida.dia, &dataEscolhida.mes, &dataEscolhida.ano);
            for (i = 0; i < count; i++){
                if (agenda[i].data.dia == dataEscolhida.dia&&
                    agenda[i].data.mes == dataEscolhida.mes&&
                    agenda[i].data.ano == dataEscolhida.ano){
                    printf("Evento %i\n", i+1);
                    getEvento(agenda[i]);
                    printf("\n\n");
                    deuboa = 1;
                }
            }
            if (deuboa == 0)
                printf("\nNão foi encontrado um evento no dia especificado.\n\n");
            deuboa = 0;
            break;
        case 4:
            printf("Informe a descrição do evento: ");
            scanf("%s", descricaoEscolhida);
            for (i = 0; i < count; i++){
                if (!strcmp(descricaoEscolhida, agenda[i].descricao)){
                    printf("\nEvento %i\n", i+1);
                    getEvento(agenda[i]);
                    printf("\n\n");
                    deuboa = 1;
                }
            }
            if (deuboa == 0)
                printf("\nNão foi encontrado um evento com a descrição especificada.\n\n");
            deuboa = 0;
            break;
        case 5:
                if (!(count <= 0)){
                    printf("Informe o número do evento que deseja excluir: ");
                    scanf("%i", &i);
                    if(!(count < i || i <= 0)){
                        //Converter i para contagem começando em 0
                        i -=1;
                        //Passar todos os eventos para o seu valor anterior
                        for (; i+1 < count; i++){
                            agenda[i] = agenda[i+1];
                        }
                        count--;
                        agenda = realloc(agenda, sizeof(struct evento) * count);
                        printf("Evento removido com sucesso!\n\n");
                    }else
                        printf("Não há evento com esse número!\n\n");
                }else{
                    printf("Não há eventos registrados!\n\n");
                }
                i = 0;
            break;

        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    //LIBERAR MEMÓRIA
    //NUNCA MAIS ESQUEÇO ISSO
    //Segundo o StackOverflow, posso fazer isso para liberar vetor de struct
    free(agenda);
}