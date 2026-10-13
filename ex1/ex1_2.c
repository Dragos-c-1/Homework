#include <stdio.h>

// Modulul pentru T.1.1 (Conversie temperatura)
#include "temperature.h"

// Setare pentru T.1.2: 1 pentru header1.h, 0 pentru header2.h
#define USE_HEADER1 0

#if defined(USE_HEADER1) && (USE_HEADER1 == 1)
#include "header1.h"
#else
#include "header2.h"
#endif

int main(void) {
    // ==========================================
    // T.1.1: Conversie Temperatura
    // ==========================================
    printf("--- T.1.1: Temperature Conversion ---\n");
    double tempc = 22.30;
    double tempf = ctf(tempc);
    double cback = ftc(tempf);

    printf("%.2f C = %.2f F\n", tempc, tempf);
    printf("%.2f F = %.2f C (inapoi)\n\n", tempf, cback);

    // ==========================================
    // T.1.2: Conditional Header Inclusion
    // ==========================================
    printf("--- T.1.2: Conditional Header Inclusion ---\n");
    printf("USE_HEADER1 este setat pe: %d\n", USE_HEADER1);
    printf("Apelam functia f(): ");
    f();

    return 0;
}
