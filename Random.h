#ifndef MYRANDOM_H
#define MYRANDOM_H

#include <random>

class Random {
    std::mt19937 rand_engine;

    public:
        Random();
        int GetRandom(int begin, int end);
        float GetRandom(float begin, float end);
};

#endif //MYRANDOM_H
