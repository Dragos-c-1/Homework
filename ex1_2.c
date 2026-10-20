#include <stdio.h>
#include <stdlib.h>

#include "temperature.h"

#define USE_HEADER1 0

#if defined(USE_HEADER1) && (USE_HEADER1 == 1)
#include "header1.h"
#else
#include "header2.h"
#endif

void afiseazaMeniu(void) {
    printf("\n==========================================\n");
    printf("        Selecteaza optiunea           \n");
    printf("==========================================\n");
    printf("1.  Conversie Celsius -> Fahrenheit\n");
    printf("2.  Conversie Fahrenheit -> Celsius\n");
    printf("3.  Testare includere conditionata (f)\n");
    printf("0. Iesire\n");
    printf("Alege o optiune: ");
}

int main(void) {
    int optiune = -1;
    char buffer[100];

    while (1) {
        afiseazaMeniu();

        // Citim linia introdusa de la tastatura
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        // Daca s-a apasat direct Enter, reimprospatam meniul
        if (buffer[0] == '\n') {
            continue;
        }

        optiune = atoi(buffer);

        if (optiune == 0) {
            printf("Program terminat.\n");
            break;
        }

        switch (optiune) {
        case 1: {
            double c = 22.30; // Valoare implicita
            printf("\nIntrodu valoarea in Celsius [Apasa Enter pentru valoarea implicita: %.2f]: ", c);

            if (fgets(buffer, sizeof(buffer), stdin) != NULL && buffer[0] != '\n') {
                c = atof(buffer);
            }

            double tempF = ctf(c);
            printf("-> Rezultat: %.2f C = %.2f F\n", c, tempF);
            break;
        }

        case 2: {
            double tempF = 72.14; // Valoare implicita
            printf("\nIntrodu valoarea in Fahrenheit [Apasa Enter pentru valoarea implicita: %.2f]: ", tempF);

            if (fgets(buffer, sizeof(buffer), stdin) != NULL && buffer[0] != '\n') {
                tempF = atof(buffer);
            }

            double c = ftc(tempF);
            printf("-> Rezultat: %.2f F = %.2f C\n", tempF, c);
            break;
        }

        case 3: {
            printf("\n--- Test T.1.2: Conditional Header Inclusion ---\n");
            printf("USE_HEADER1 este setat pe: %d\n", USE_HEADER1);
            printf("Apelam functia f(): ");
            f();
            break;
        }

        default:
            printf("\nOptiune invalida! Incearca din nou.\n");
            break;
        }
    }

    return 0;
}