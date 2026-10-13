#include "temperature.h"

double ctf(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double ftc(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}