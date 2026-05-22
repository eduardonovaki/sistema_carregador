#include <stdio.h>
// funções 
float calculo_tempo(int capacidade_bateria, float porcentagem){
    float energia_faltando;
    float tempo_horas;
    float tempo_minutos;

    energia_faltando = capacidade_bateria * (1 - (porcentagem/100));
    tempo_horas = energia_faltando / 20;
    tempo_minutos = tempo_horas * 60;

    return tempo_minutos;
}

int inicio(){ 
    int escolha; 
    printf("---Bem-vindo ao carregador eletrico da FIAP!---\n"); 

    do {
        printf("Digite 1 para novo carregamento | Digite 2 para sair: "); 
        scanf("%d", &escolha);

        if (escolha != 1 && escolha != 2) {
            printf("Opcao invalida! Por favor, digite 1 ou 2.\n");
        }
    } while (escolha != 1 && escolha != 2);

    return escolha; 
}


//MAIN:


int main() {
    int escolha = inicio();
    int capacidade_bateria;
    float porcentagem;
    float tempo_carregamento;
    char yesorno;



    switch(escolha){
        case 1:
            printf("Digite a capacidade_bateria da sua bateria (em kWh): ");
            scanf("%d", &capacidade_bateria);

            printf("Digite a porcentagem atual da bateria: ");
            scanf("%f", &porcentagem);

            tempo_carregamento = calculo_tempo(capacidade_bateria, porcentagem);

            printf("Este carregador eh capaz de carregar sua bateria em aproximadamete %.1f minutos, deseja continuar? (Y para sim /N para nao) ", tempo_carregamento);
            scanf(" %c", &yesorno);

            float energia_faltando = capacidade_bateria * (1 - porcentagem/100);
            float valor = energia_faltando * 1.2;
            if (yesorno == 'Y'){
                printf("-------Carregamento iniciando-------\n\n");
                for (float i = porcentagem; i <100; i += 10){
                    printf("---Aguarde %.2f porcento...---\n", i);
                }
                printf("-------Carregamento finalizado!-----\n");
                printf("%.1f kWh foram carregados em %.1f minutos!\n", energia_faltando, tempo_carregamento);
                printf("O valor da recarga eh de %.2f R$\n", valor);
                printf("Obrigado pela preferencia!\n");
            } else if(yesorno == 'N'){
                printf("\nEstamos trabalhando para construir carregadores mais velozes. Obrigado pela compreensao!\n\n");
                }
                break;
       case 2:
        printf("---Saindo do carregador FIAP---");
        break;
    }

    return 0;
}



