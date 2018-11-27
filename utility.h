#ifndef UTILITY_H
#define UTILITY_H

// Trig
#ifndef M_PI
#define M_PI 3.141592654
#endif

// Random
uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::seed_seq ss{ uint32_t( seed & 0xffffffff ), uint32_t( seed >> 32 ) };
std::mt19937 mt(ss);

#endif
