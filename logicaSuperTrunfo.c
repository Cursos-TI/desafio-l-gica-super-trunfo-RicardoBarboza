#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
   

    char estado1, codigo1[4], cidade1[30], estado2, codigo2[4], cidade2[30];
    unsigned int populacao1, pontos_turisticos1, populacao2, pontos_turisticos2, bilhao = 1000000000, atributo1, atributo2;
    float area1, pib1, densidade_populacional1, pib_per_capta1, area2, pib2, densidade_populacional2, pib_per_capta2;
    double indice1, indice2;
    

    // entrada de dados da primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1); // espaço antes do %c para ignorar espaços em branco como o enter
    sprintf(codigo1, "%c01", estado1); // codigo1 recebe estado1+"01"
    printf("Cidade: ");
    scanf(" %[^\n]", cidade1); // lê até que o enter seja premido
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (em km2): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    sprintf(codigo2, "%c01", estado2);

    // entrada de dados da segunda carta
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2); // espaço antes do %c para ignorar espaços em branco como o enter
    sprintf(codigo2, "%c01", estado2); // codigo1 recebe estado1+"01"
    printf("Cidade: ");
    scanf(" %[^\n]", cidade2); // lê até que o enter seja premido
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (em km2): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);


    // Calculo de densidade populaciona e pib per capta da carta 1
    densidade_populacional1 = (float) populacao1/area1;  // Densidade Populacional em Habitantes por KM2
    pib_per_capta1 = (float) (pib1/populacao1)*bilhao; // PIB Per Capt em Reais por habitantes

    // Calculo de densidade populaciona e pib per capta da carta 2
    densidade_populacional2 = (float) populacao2/area2; // Densidade Populacional em Habitantes por KM2
    pib_per_capta2 = (float) (pib2/populacao2)*bilhao; // PIB Per Capt em Reais por habitantes


    // impressão da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km2\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f Habitantes por km2\n", densidade_populacional1);
    printf("PIB per Capta: %.2f Reais por Habitante\n", pib_per_capta1);

    // impressão da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km2\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f Habitantes por km2\n", densidade_populacional2);
    printf("PIB per Capta: %.2f Reais por Habitante\n\n", pib_per_capta2);

    // Calculo do Indice de cada cidade o maior vence
    indice1 = (double) populacao1 + area1 + pib1 + pontos_turisticos1 + (1/densidade_populacional1) + pib_per_capta1;
    indice2 = (double) populacao2 + area1 + pib2 + pontos_turisticos2 + (1/densidade_populacional2) + pib_per_capta2;

    // Menu para ecolher os Atributos
    printf("Escolha um Atributo (1 a 4):\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    scanf("%d", &atributo1);

    switch (atributo1) {
        case 1:
            printf("Você escolheu: População\n");
            printf("Escolha outro Atributo:\n");
            printf("2 - Área\n");
            printf("3 - PIB\n");
            printf("4 - Pontos Turisticos\n");
            scanf("%d", &atributo2);

            printf(
                (populacao1 == populacao2) ?
                "\nAmbas as Cidades possuem a mesma população\n\n" :
                "\nA População da Cidade %s é maior número\n\n",
                (populacao1 > populacao2) ? cidade1 : cidade2
             );


            if (atributo2 == 2) {
                
                printf("Segunda escolha: Área\n\n");
                
                printf(
                    (area1 == area2) ?
                    "Ambas as Cidades possuem a mesma Área\n\n" :
                    "A Área da Cidade %s é maior\n\n",
                    (area1 > area2) ? cidade1 : cidade2
                );

                // Como foi escolhido populacao e area, mostro também a Densidade Populacional
                printf(
                    (densidade_populacional1 == densidade_populacional2) ?
                    "Ambas as Cidades possuem a mesma Densidade Populacional\n\n" :
                    "A Cidade %s possui uma Densidade Populacional menor\n\n",
                    (densidade_populacional1 < densidade_populacional1) ? cidade1 : cidade2
                );

            }    

            else if (atributo2 == 3) {

                printf("Segunda escolha: PIP\n");
                                
                printf(
                    (pib1 == pib2) ?
                    "Ambas as Cidades possuem o mesmo PIB\n\n" :
                    "O PIB da Cidade %s é maior\n\n",
                    (pib1 > pib2) ? cidade1 : cidade2
                );

                // Como foi escolhido populacao e pib mostro tambem a renda per capta
                printf(
                    (pib_per_capta1 == pib_per_capta2) ?
                    "Ambas as Cidades possuem o mesmo PIB per Capta\n\n" :
                    "O PIB per Capta da Cidade %s é maior\n\n",
                    (pib_per_capta1 > pib_per_capta2) ? cidade1 : cidade2
                );
            }

            else if (atributo2 == 4) {

                printf("Segunda escolha: Pontos Turísticos\n");
                
                printf(
                    (pontos_turisticos1 == pontos_turisticos2) ?
                    "Ambas as Cidades possuem o mesmo número de Pontos Turísticos\n\n" :
                    "Os Pontos Turísticos da Cidade %s são em maior número\n\n",
                    (pontos_turisticos1 > pontos_turisticos2) ? cidade1 : cidade2
                );
            }    

            else
                printf("Escolha inválida\n");
            break;

        case 2:
            printf("Você escolheu: Área\n");
            printf("Escolha outro Atributo:\n");
            printf("1 - População\n");
            printf("3 - PIB\n");
            printf("4 - Pontos Turísticos\n");
            scanf("%d", &atributo2);


            printf(
                (area1 == area2) ?
                "Ambas as Cidades possuem a mesma Área\n\n" :
                "A Área da Cidade %s é maior\n\n",
                (area1 > area2) ? cidade1 : cidade2
            );


            if (atributo2 == 1) {

                printf("Segunda escolha: População\n");

                printf(
                    (populacao1 == populacao2) ?
                    "Ambas as Cidades possuem a mesma população\n\n" :
                    "A População da Cidade %s é maior número\n\n",
                    (populacao1 > populacao2) ? cidade1 : cidade2
                );

                // Como foi escolhido populacao e area, mostro também a Densidade Populacional
                printf(
                    (densidade_populacional1 == densidade_populacional2) ?
                    "Ambas as Cidades possuem a mesma Densidade Populacional\n\n" :
                    "A Cidade %s possui uma Densidade Populacional menor\n\n",
                    (densidade_populacional1 < densidade_populacional1) ? cidade1 : cidade2
                );
            }    

            else if (atributo2 == 3) {
                
                printf("Segunda escolha: PIP\n");

                printf(
                    (pib1 == pib2) ?
                    "Ambas as Cidades possuem o mesmo PIB\n\n" :
                    "O PIB da Cidade %s é maior\n\n",
                    (pib1 > pib2) ? cidade1 : cidade2
                );
            }        

            else if (atributo2 == 4) {

                printf("Segunda escolha: Pontos Turísticos\n");

                printf(
                    (pontos_turisticos1 == pontos_turisticos2) ?
                    "Ambas as Cidades possuem o mesmo número de Pontos Turísticos\n\n" :
                    "Os Pontos Turísticos da Cidade %s são em maior número\n\n",
                    (pontos_turisticos1 > pontos_turisticos2) ? cidade1 : cidade2
                );
            }    

            else
                printf("Escolha inválida\n");
            break;

        case 3:
            printf("Você escolheu: PIB\n");
            printf("Escolha outro Atributo:\n");
            printf("1 - População\n");
            printf("2 - Área\n");
            printf("4 - Pontos Turísticos\n");
            scanf("%d", &atributo2);

            printf(
                (pib1 == pib2) ?
                "Ambas as Cidades possuem o mesmo PIB\n\n" :
                "O PIB da Cidade %s é maior\n\n",
                (pib1 > pib2) ? cidade1 : cidade2
            );


            if (atributo2 == 1) {

                printf("Segunda escolha: População\n");

                printf(
                    (populacao1 == populacao2) ?
                    "Ambas as Cidades possuem a mesma população\n\n" :
                    "A População da Cidade %s é maior número\n\n",
                    (populacao1 > populacao2) ? cidade1 : cidade2
                );

                // Como foi escolhido populacao e pib mostro tambem a renda per capta
                printf(
                    (pib_per_capta1 == pib_per_capta2) ?
                    "Ambas as Cidades possuem o mesmo PIB per Capta\n\n" :
                    "O PIB per Capta da Cidade %s é maior\n\n",
                    (pib_per_capta1 > pib_per_capta2) ? cidade1 : cidade2
                );
            }    

            else if (atributo2 == 2) {

                printf("Segunda escolha: Área\n");

                printf(
                    (area1 == area2) ?
                    "Ambas as Cidades possuem a mesma Área\n\n" :
                    "A Área da Cidade %s é maior\n\n",
                    (area1 > area2) ? cidade1 : cidade2
                );
            }    


            else if (atributo2 == 4) {

                printf("Segunda escolha: Pontos Turísticos\n");

                printf(
                    (pontos_turisticos1 == pontos_turisticos2) ?
                    "Ambas as Cidades possuem o mesmo número de Pontos Turísticos\n\n" :
                    "Os Pontos Turísticos da Cidade %s são em maior número\n\n",
                    (pontos_turisticos1 > pontos_turisticos2) ? cidade1 : cidade2
                );
            }        

            else
                printf("Escolha inválida\n");
            break;

        case 4:
            printf("Você escolheu: Pontos Turísticos\n");
            printf("Escolha outro Atributo:\n");
            printf("1 - População\n");
            printf("2 - Área\n");
            printf("3 - PIB\n");
            scanf("%d", &atributo2);

            printf(
                (pontos_turisticos1 == pontos_turisticos2) ?
                "Ambas as Cidades possuem o mesmo número de Pontos Turísticos\n\n" :
                "Os Pontos Turísticos da Cidade %s são em maior número\n\n",
                (pontos_turisticos1 > pontos_turisticos2) ? cidade1 : cidade2
            );

            if (atributo2 == 1) {

                printf("Segunda escolha: População\n");

                printf(
                    (populacao1 == populacao2) ?
                    "Ambas as Cidades possuem a mesma população\n\n" :
                    "A População da Cidade %s é maior número\n\n",
                    (populacao1 > populacao2) ? cidade1 : cidade2
                );
            }    


            else if (atributo2 == 2) {

                printf("Segunda escolha: Área\n");

                printf(
                    (area1 == area2) ?
                    "Ambas as Cidades possuem a mesma Área\n\n" :
                    "A Área da Cidade %s é maior\n\n",
                    (area1 > area2) ? cidade1 : cidade2
                );
            }    


            else if (atributo2 == 3) {

                        
                printf("Segunda escolha: PIP\n");

                printf(
                    (pib1 == pib2) ?
                    "Ambas as Cidades possuem o mesmo PIB\n\n" :
                    "O PIB da Cidade %s é maior\n\n",
                    (pib1 > pib2) ? cidade1 : cidade2
                );
            }    

            else
                printf("Escolha inválida\n");
            break;

        default:
            printf("Escolha inválida\n");
    }


    // Comparo os Indedices e indico o vencedor
    (indice1 == indice2)
    ? printf("As Cidades empataram com o Índice: %.2lf\n\n", indice1)
    : printf("%s foi a Cidade Vencedora pois alcançou o Índice: %.2f\n\n",
             (indice1 > indice2) ? cidade1 : cidade2,
             (indice1 > indice2) ? indice1 : indice2);


    return 0;

}
