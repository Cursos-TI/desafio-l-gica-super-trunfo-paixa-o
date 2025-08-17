#include <stdio.h> //Cabeçalho de entrada e saída padrão
#include <locale.h> //Para corrigir acentuação
#include <string.h> //Manipular string
#define limpar while (getchar() != '\n'); // Define a variável limpar para consumir o \n do buffer da captura anterior

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

    //COMPARANDO AS CARTAS
    printf("|---------------------------------------------------|\n");
    printf("|-------------- COMPARANDO AS CARTAS ---------------|\n");
    printf("|---------------------------------------------------|\n\n");
    
    if(populacao1 >= populacao2){

        if(populacao1 == populacao2){

            printf("Comparação de cartas (atributo POPULAÇÃO):\n\n");
            printf("Carta %s - %s: %lu\n", codCarta1, cidade1, populacao1);
            printf("Carta %s - %s: %lu\n", codCarta2, cidade2, populacao2);
            printf("Resultado: EMPATE\n\n");
        }
        if(populacao1 > populacao2){

            printf("Carta %s - %s: %lu\n", codCarta1, cidade1, populacao1);
            printf("Carta %s - %s: %lu\n", codCarta2, cidade2, populacao2);
            printf("Resultado: CARTA %s VENCEU\n\n", codCarta1);
        }

    }else{

        printf("Comparação de cartas (atributo POPULAÇÃO):\n\n");
        printf("Carta %s - %s: %lu\n", codCarta1, cidade1, populacao1);
        printf("Carta %s - %s: %lu\n", codCarta2, cidade2, populacao2);
        printf("Resultado: CARTA %s VENCEU\n\n", codCarta2);
    }
}
