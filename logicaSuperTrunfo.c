#include <stdio.h> //Cabeçalho de entrada e saída padrão
#include <locale.h> //Para corrigir acentuação
#include <string.h> //Manipular string
#include <unistd.h>//contém declarações de funções que permitem que seu programa interaja com o sistema operacional de forma padronizada.
#define limpar while (getchar() != '\n'); // Define a variável 'limpar' para consumir o \n do buffer da captura anterior

int main(){
    setlocale(LC_ALL, "portuguese");

    //Variáveis primeira carta
    char estado1[20] = "", cidade1[20] = "", codCarta1[20] = "";
    unsigned long int populacao1 = 0;
    unsigned int pontosTuristico1 = 0;
    float area1 = 0.0, pib1 = 0.0;
    double densidadePopulacional1 = 0.0, superPoderCarta1 = 0.0, inversoDensidadePopulacional1 = 0.0, pibConvertido1 = 0.0, pibPerCapita1 = 0.0;

    //Variáveis segunda carta
    char estado2[20] = "", cidade2[20] = "", codCarta2[20] = "";
    unsigned long int populacao2 = 0;
    unsigned int pontosTuristico2 = 0;
    float area2 = 0.0, pib2 = 0.0;
    double densidadePopulacional2 = 0.0, superPoderCarta2 = 0.0, inversoDensidadePopulacional2 = 0.0, pibConvertido2 = 0.0, pibPerCapita2 = 0.0;

    //Variáveis de MENU e RESULTADO
    int subMenu = 0, opcoesMenu1 = 0, opcoesMenu2 = 0;
    double primeiroAtributoCarta1 = 0.0, segundoAtributoCarta1 = 0.0, primeiroAtributoCarta2 = 0.0, segundoAtributoCarta2 = 0.0;
    double somaAtributosCarta1 = 0.0, somaAtributosCarta2 = 0.0;

    //Coletando dados primeira carta
    printf("\n|---------------------------------------------------|\n");
    printf("|----------- DIGITE OS DADOS SOLICITADOS -----------|\n");
    printf("|---------------------------------------------------|\n\n");

    printf("PRIMEIRA CARTA\n\n");

    printf("Estado (Digite a sigla que representa o estado): ");
    fgets(estado1, sizeof(estado1), stdin);//Captura uma estring incluido os "espaços"
    estado1[strcspn(estado1, "\n")] = '\0';//Limpa o \n do buffer

    printf("Código da Carta (O estado + um número de 01 a 04): ");
    fgets(codCarta1, sizeof(codCarta1), stdin);//Captura uma estring incluido os "espaços"
    codCarta1[strcspn(codCarta1, "\n")] = '\0';//Limpa o \n do buffer

    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);//Captura uma estring incluido os "espaços"
    cidade1[strcspn(cidade1, "\n")] = '\0';//Limpa o \n do buffer

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Número de Pontos turísticos: ");
    scanf("%u", &pontosTuristico1);

    printf("Área (Em km²): ");
    scanf("%f", &area1);

    printf("PIB (em Bilhões): ");
    scanf("%f", &pib1);

    limpar; // Limpa o \n do buffer da captura anterior

    //Coletando dados segunda carta
    printf("\n\n");
    printf("|---------------------------------------------------|\n");
    printf("|----------- DIGITE OS DADOS SOLICITADOS -----------|\n");
    printf("|---------------------------------------------------|\n\n");

    printf("SEGUNDA CARTA\n\n");

    printf("Estado (Digite a sigla que representa o estado): ");
    fgets(estado2, sizeof(estado2), stdin);//Captura uma estring incluido os "espaços"
    estado2[strcspn(estado2, "\n")] = '\0';//Limpa o \n do buffer da captura anterior

    printf("Código da Carta (O estado + um número de 01 a 04): ");
    fgets(codCarta2, sizeof(codCarta2), stdin);//Captura uma estring incluido os "espaços"
    codCarta2[strcspn(codCarta2, "\n")] = '\0';//Limpa o \n do buffer da captura anterior

    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);//Captura uma estring incluido os "espaços"
    cidade2[strcspn(cidade2, "\n")] = '\0';//Limpa o \n do buffer da captura anterior

    printf("População: ");
    scanf("%lu", &populacao2);
    
    printf("Número de Pontos turísticos: ");
    scanf("%u", &pontosTuristico2);

    printf("Área (Em km²): ");
    scanf("%f", &area2);

    printf("PIB (em Bilhões): ");
    scanf("%f", &pib2);

    //Calcular PIB Per Capita e Dsensidade Populacional carta 01
    pibConvertido1 = (double) (pib1 * 1000000000.0); //PIB em bilhões, por isso multiplica por 1 bilhão
    pibPerCapita1 = (double) (pibConvertido1 / populacao1);
    densidadePopulacional1 = (double) (populacao1 / area1);

    //Calcular PIB Per Capita e Dsensidade Populacional carta 02
    pibConvertido2 = (double) (pib2 * 1000000000.0); //PIB em bilhões, por isso multiplica por 1 bilhão
    pibPerCapita2 = (double) (pibConvertido2 / populacao2);
    densidadePopulacional2 = (double) (populacao2 / area2);

    //Calcular Super Poder carta 1
    inversoDensidadePopulacional1 = (double) (1 / densidadePopulacional1); //Calcula o inerso da densidade populacional
    superPoderCarta1 = (double) (populacao1 + pontosTuristico1 + area1 + pibConvertido1 + pibPerCapita1 + inversoDensidadePopulacional1);

    //Calcular Super Poder carta 2
    inversoDensidadePopulacional2 = (double) (1 / densidadePopulacional2); //Calcula o inerso da densidade populacional
    superPoderCarta2 = (double) (populacao2 + pontosTuristico2 + area2 + pibConvertido2 + pibPerCapita2 + inversoDensidadePopulacional2);


    //Apresentando os dados inseridos das cartas 1 e 2
   printf("\n|---------------------------------------------------|\n");
    printf("|----------------- DADOS INSERIDOS -----------------|\n");
    printf("|---------------------------------------------------|\n\n");

    //Carta 01
    printf("********************* CARTA 01 *********************\n\n");

    printf("CÓDIGO DA CARTA: %s\n", codCarta1);
    printf("ESTADO: %s\n", estado1);
    printf("CIDADE: %s\n", cidade1);
    printf("POPULAÇÃO: %lu habitantes\n", populacao1);
    printf("QUANTIDADE DE PONTOS TURÍSTICOS: %u\n", pontosTuristico1);
    printf("ÁREA: %.2f km²\n", area1);
    printf("PIB: R$ %.2f Bilhões\n", pib1);
    printf("PIB PER CAPITA: R$ %.2f\n", pibPerCapita1);
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", densidadePopulacional1);
    printf("SUPER POWER: %.2f (°-°)\n\n", superPoderCarta1);

    //Carta 02
    printf("********************* CARTA 02 *********************\n\n");

    printf("CÓDIGO DA CARTA: %s\n", codCarta2);
    printf("ESTADO: %s\n", estado2);
    printf("CIDADE: %s\n", cidade2);
    printf("POPULAÇÃO: %lu habitantes\n", populacao2);
    printf("QUANTIDADE DE PONTOS TURÍSTICOS: %u\n", pontosTuristico2);
    printf("ÁREA: %.2f km²\n", area2);
    printf("PIB: R$ %.2f Bilhões\n", pib2);
    printf("PIB PER CAPITA: R$ %.2f\n", pibPerCapita2);
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", densidadePopulacional2);
    printf("SUPER POWER: %.2f (°-°)\n\n", superPoderCarta2);

    //MENU
    while(1){ //Repete o jogo; o (1) dentro do while serve para o loop ser constante "infinito"

        while(1) {// repete o submenu; o (1) dentro do while serve para o loop ser constante "infinito"
            
            while(1){// repete o menu; o (1) dentro do while serve para o loop ser constante "infinito"
    
                printf("\n|---------------------------------------------------|\n");
                printf("|---------------------- MENU -----------------------|\n");
                printf("|---------------------------------------------------|\n\n");
    
                printf("Qual primeiro atributo será usado para comparação das cartas?\n\n");
                printf("opção 1 - POPULAÇÃO\n");
                printf("opção 2 - ÁREA\n");
                printf("opção 3 - PIB\n");
                printf("opção 4 - NÚMERO DE PONTOS TURÍSTICOS\n");
                printf("opção 5 - DENSIDADE DEMOGRÁFICA\n");
                printf("opção 6 - sair...\n\n");
    
                printf("SELECIONE UMA OPÇÃO: ");
                scanf("%d", &opcoesMenu1);
    
                if(opcoesMenu1 == 1){
                    
                    primeiroAtributoCarta1 = (double) populacao1;
                    primeiroAtributoCarta2 = (double) populacao2;
                    break;
                    
                }else if(opcoesMenu1 == 2){
                    
                    primeiroAtributoCarta1 = (double) area1;
                    primeiroAtributoCarta2 = (double) area2;
                    break;
                    
                }else if(opcoesMenu1 == 3){
                    
                    primeiroAtributoCarta1 = (double) (pib1*1000000000.0);
                    primeiroAtributoCarta2 = (double) (pib2*1000000000.0);
                    break;
                    
                }else if(opcoesMenu1 == 4){
                    
                    primeiroAtributoCarta1 = (double) pontosTuristico1;
                    primeiroAtributoCarta2 = (double) pontosTuristico2;
                    break;
                    
                }else if(opcoesMenu1 == 5){
                    
                    primeiroAtributoCarta1 = (double) (1/densidadePopulacional1);
                    primeiroAtributoCarta2 = (double) (1/densidadePopulacional2);
                    break;
                    
                }else if(opcoesMenu1 == 6){
                    
                    printf("\nSaindo......\n\n");
                    sleep(2);
                    return(0);
                    
                }else if(opcoesMenu1 != 1 && opcoesMenu1 != 2 && opcoesMenu1 != 3 && opcoesMenu1 != 4 && opcoesMenu1 != 5 && opcoesMenu1 != 6){
                
                printf("\n\nOpção inválida! Tente novamente......\n\n"); //Volta o loop de Menu
                sleep(2);
                limpar; 
                }
            }
    
            while(1){
                    
                printf("\n\nQual segundo atributo será usado para comparação das cartas?\n\n");
                printf("opção 1 - POPULAÇÃO\n");
                printf("opção 2 - ÁREA\n");
                printf("opção 3 - PIB\n");
                printf("opção 4 - NÚMERO DE PONTOS TURÍSTICOS\n");
                printf("opção 5 - DENSIDADE DEMOGRÁFICA\n");
                printf("opção 6 - sair...\n\n");
    
                printf("SELECIONE UMA OPÇÃO: ");
                scanf("%d", &opcoesMenu2);
    
                if(opcoesMenu2 == 1){
                    
                    segundoAtributoCarta1 = (double) populacao1;
                    segundoAtributoCarta2 = (double) populacao2;
                    break;
                    
                }else if(opcoesMenu2 == 2){
                    
                    segundoAtributoCarta1 = (double) area1;
                    segundoAtributoCarta2 = (double) area2;
                    break;
                    
                }else if(opcoesMenu2 == 3){
                    
                    segundoAtributoCarta1 = (double) (pib1*1000000000.0);
                    segundoAtributoCarta2 = (double) (pib2*1000000000.0);
                    break;
                    
                }else if(opcoesMenu2 == 4){
                    
                    segundoAtributoCarta1 = (double) pontosTuristico1;
                    segundoAtributoCarta2 = (double) pontosTuristico2;
                    break;
                    
                }else if(opcoesMenu2 == 5){
                    
                    segundoAtributoCarta1 = (double)(1/densidadePopulacional1);
                    segundoAtributoCarta2 = (double)(1/densidadePopulacional2);
                    break;
                    
                }else if(opcoesMenu2 == 6){
                    
                    printf("\nSaindo......\n\n");
                    sleep(2);
                    return(0);
                    
                }else if(opcoesMenu2 != 1 && opcoesMenu2 != 2 && opcoesMenu2 != 3 && opcoesMenu2 != 4 && opcoesMenu2 != 5 && opcoesMenu2 != 6){
                
                printf("\n\nOpção inválida! Tente novamente......\n\n");
                sleep(2);
                limpar;
                
                }
            }
            
            if( opcoesMenu1 == opcoesMenu2){//Reinicia o Menu
    
                printf("\nVocê selecinou duas opções iguais. Tente novamente......\n\n");
                sleep(2);
                
            }else if(opcoesMenu2 == 1 || opcoesMenu2 == 2 || opcoesMenu2 == 3 || opcoesMenu2 == 4 || opcoesMenu2 == 5){
                
                break;//Sai do Menu
                
            }else if(opcoesMenu1 == 1 || opcoesMenu1 == 2 || opcoesMenu1 == 3 || opcoesMenu1 == 4 || opcoesMenu1 == 5){
                
                break;
            }
        }
            
        while(1){
            
            //Soma dos atributos
            somaAtributosCarta1 = primeiroAtributoCarta1 + segundoAtributoCarta1;
            somaAtributosCarta2 = primeiroAtributoCarta2 + segundoAtributoCarta2;
            
            printf("\n|---------------------------------------------------|\n");
            printf("|-------------- COMPARANDO AS CARTAS ---------------|\n");
            printf("|---------------------------------------------------|\n\n");
            
            if((opcoesMenu1 == 1 && opcoesMenu2 == 2) || (opcoesMenu2 == 1 && opcoesMenu1 == 2)){
                
                printf("Atributos escolhidos: POPULAÇÃO e ÁREA\n\n");
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade1, estado1, populacao1);
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade1, estado1, area1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade2, estado2, populacao2);
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade2, estado2, area2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 1 && opcoesMenu2 == 3) || (opcoesMenu2 == 1 && opcoesMenu1 == 3)){
                
                printf("Atributos escolhidos: POPULAÇÃO e PIB\n\n");
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade1, estado1, populacao1);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade1, estado1, pib1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade2, estado2, populacao2);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade2, estado2, pib2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 1 && opcoesMenu2 == 4) || (opcoesMenu2 == 1 && opcoesMenu1 == 4)){
                
                printf("Atributos escolhidos: POPULAÇÃO e quantidade de PONTOS TURÍSTICOS\n\n");
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade1, estado1, populacao1);
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %d\n", cidade1, estado1, pontosTuristico1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade2, estado2, populacao2);
                printf("A quantidade de PONTOS TURÍSTICOS %s - %s é: %u\n", cidade2, estado2, pontosTuristico2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 1 && opcoesMenu2 == 5) || (opcoesMenu2 == 1 && opcoesMenu1 == 5)){
                
                printf("Atributos escolhidos: POPULAÇÃO e DENSIDADE POPULACIONAL\n\n");
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade1, estado1, populacao1);
                printf("A DENSIDAE POPULACIONAL de %s - %s é: %.2f hab/km²\n", cidade1, estado1, densidadePopulacional1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A POPULAÇÃO de %s - %s é: %lu habitantes\n", cidade2, estado2, populacao2);
                printf("A DENSIDAE POPULACIONAL de %s - %s é: %.2f hab/km²\n", cidade2, estado2, densidadePopulacional2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 2 && opcoesMenu2 == 3) || (opcoesMenu2 == 2 && opcoesMenu1 == 3)){
                
                printf("Atributos escolhidos: ÁREA e PIB\n\n");
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade1, estado1, area1);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade1, estado1, pib1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade2, estado2, area2);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade2, estado2, pib2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 2 && opcoesMenu2 == 4) || (opcoesMenu2 == 2 && opcoesMenu1 == 4)){
                
                printf("Atributos escolhidos: ÁREA e a quantidade de PONTOS TURÍSTICOS\n\n");
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade1, estado1, area1);
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %u\n", cidade1, estado1, pontosTuristico1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade2, estado2, area2);
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %u\n", cidade2, estado2, pontosTuristico2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 2 && opcoesMenu2 == 5) || (opcoesMenu2 == 2 && opcoesMenu1 == 5)){
                
                printf("Atributos escolhidos: ÁREA e DENSIDADE POPULACIONAL\n\n");
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade1, estado1, area1);
                printf("A DENSIDADE POPULACIONAL de %s - %s é: %.2f hab/km²\n", cidade1, estado1, densidadePopulacional1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A ÁREA de %s - %s é: %.2f km²\n", cidade2, estado2, area2);
                printf("A DENSIDADE POPULACIONAL de %s - %s é: %.2f hab/km²\n", cidade2, estado2, densidadePopulacional2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 3 && opcoesMenu2 == 4) || (opcoesMenu2 == 3 && opcoesMenu1 == 4)){
                
                printf("Atributos escolhidos: PIB e a quantidade de PONTOS TURÍSTICOS\n\n");
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %u\n", cidade1, estado1, pontosTuristico1);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade1, estado1, pib1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %u\n", cidade2, estado2, pontosTuristico2);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade2, estado2, pib2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 3 && opcoesMenu2 == 5) || (opcoesMenu2 == 3 && opcoesMenu1 == 5)){
                
                printf("Atributos escolhidos: PIB e a DENSIDADE POPULACIONAL\n\n");
                printf("A DENSIDADE de %s - %s é: %.2f hab/km²\n", cidade1, estado1, densidadePopulacional1);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade1, estado1, pib1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A DENSIDADE de %s - %s é: %.2f hab/km²\n", cidade2, estado2, densidadePopulacional2);
                printf("O PIB de %s - %s é: R$ %.2f Bilhões\n", cidade2, estado2, pib2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if((opcoesMenu1 == 4 && opcoesMenu2 == 5) || (opcoesMenu2 == 4 && opcoesMenu1 == 5)){
                
                printf("Atributos escolhidos: quantidade de PONTOS TURÍSTICOS e DENSIDADE POPULACIONAL\n\n");
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %u\n", cidade1, estado1, pontosTuristico1);
                printf("O DENSIDADE POPULACIONAL de %s - %s é: %.2f hab/km²\n", cidade1, estado1, densidadePopulacional1);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade1, estado1, somaAtributosCarta1);
                printf("A quantidade de PONTOS TURÍSTICOS de %s - %s é: %u\n", cidade2, estado2, pontosTuristico2);
                printf("A DENSIDADE POPULACIONAL de %s - %s é: %.2f\n", cidade2, estado2, densidadePopulacional2);
                printf("Soma dos atributos escolhidos de %s - %s é: %.2f\n\n", cidade2, estado2, somaAtributosCarta2);
                
            }
            if(somaAtributosCarta1 > somaAtributosCarta2){
            
                printf("CARTA %s VENCEU\n\n", codCarta1);
                
            }else if(somaAtributosCarta1 < somaAtributosCarta2){
            
                printf("\nCARTA %s VENCEU\n\n", codCarta2);
                
            }else if(somaAtributosCarta1 == somaAtributosCarta2){
            
                printf("\nEMPATE\n\n");
            }

            opcoesMenu1 = '\0';
            opcoesMenu2 = '\0';
        break;
        }
    while (1){ //Loop do sub menu, para retornar ao menu anterior
    
            printf("------------------\n");
            printf(" Voltar: Option 0\n");
            printf(" Sair:   Option 1\n");
            printf("------------------\n\n");
            scanf("%d", &subMenu);

            if(subMenu == 0){ //Se o usuário digitar a opção 0 volta para o loop do menu anterior
                printf("\nVoltando......\n\n");
                sleep(3);
                break;
            }
            switch (subMenu){//Switch do sub menu
                case 1:
                printf("\nSaindo......\n\n");
                sleep(2);
                return (0);//Encerra o programa

                default:
                printf("\nOpção inválida! Tente novamente......\n\n");
                sleep(2);
                break;
                limpar;
            }
        }

    }
}
