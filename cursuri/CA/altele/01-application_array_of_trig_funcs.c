// Copyright 2024 Darius Neatu (neatudarius@gmail.com)

// Să se scrie un program care afișează valorile funcțiilor trigonometrice
// (sin, cos, tan) pentru toate unghiurile din 15 în 15 grade din intervalul
// [0, 360].

#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// definim tipul pointer la o functie trigonometrica care primeste
// un double si returneza un double.
typedef double (*trig_func_ptr_t)(double);

typedef struct {
    trig_func_ptr_t func;
    const char *name;
} trig_func_info_t;

int main(void)
{
    // Exemplu de pointer la functie.
    // trig_func_ptr_t pfunc = sin;
    // printf("%lf %lf\n", sin(0), pfunc(0));
    // return 0;

    // Rezolvarea problemei.
    const trig_func_info_t trig_funcs[] = {
        {sin, "sinus"},
        {cos, "cosinus"},
        // {tan, "tangent"} // nu e bine definita in 0 si 180
    };
    const int num_trig_funcs = sizeof(trig_funcs) / sizeof(trig_funcs[0]);

    for (int i = 0; i < num_trig_funcs; i++) {
        printf("=== %s ===\n", trig_funcs[i].name);
        for (int angle = 0; angle <= 360; angle += 15) { // 360 / 15
            printf("%3d: %f\n", angle, trig_funcs[i].func(angle * M_PI / 180));
        }
    }

    return 0;
}

// Compile:
// $ make
// Run:
// $ ./01-application_array_of_trig_funcs
// === sinus ===
//   0: 0.000000
//  15: 0.258819
//  30: 0.500000
//  45: 0.707107
//  60: 0.866025
//  75: 0.965926
//  90: 1.000000
// 105: 0.965926
// 120: 0.866025
// 135: 0.707107
// 150: 0.500000
// 165: 0.258819
// 180: 0.000000
// 195: -0.258819
// 210: -0.500000
// 225: -0.707107
// 240: -0.866025
// 255: -0.965926
// 270: -1.000000
// 285: -0.965926
// 300: -0.866025
// 315: -0.707107
// 330: -0.500000
// 345: -0.258819
// 360: -0.000000
// === cosinus ===
//   0: 1.000000
//  15: 0.965926
//  30: 0.866025
//  45: 0.707107
//  60: 0.500000
//  75: 0.258819
//  90: 0.000000
// 105: -0.258819
// 120: -0.500000
// 135: -0.707107
// 150: -0.866025
// 165: -0.965926
// 180: -1.000000
// 195: -0.965926
// 210: -0.866025
// 225: -0.707107
// 240: -0.500000
// 255: -0.258819
// 270: -0.000000
// 285: 0.258819
// 300: 0.500000
// 315: 0.707107
// 330: 0.866025
// 345: 0.965926
// 360: 1.000000
