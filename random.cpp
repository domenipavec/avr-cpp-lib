// random.cpp
// Simplistic random generator

#include "random.h"

uint32_t m_w = M_W;    /* must not be zero */
uint32_t m_z = M_Z;    /* must not be zero */
 
uint32_t get_random()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  /* 32-bit result */
}

uint32_t get_random(uint32_t max) {
	return get_random() / (RANDOM_MAX / max + 1);
}
