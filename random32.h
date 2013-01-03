// random.h
// Simplistic random generator

#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

// choose this randomly
#define M_W 1357
#define M_Z 7531

#define RANDOM_MAX 4294967295u

uint32_t get_random();
uint32_t get_random(uint32_t); // iz intervala [0, M-1]

#endif
