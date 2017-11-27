#include <ctime>
#include <cstdlib>

#include "Random.h"

Random::Random() {
    rand_engine.seed(time(nullptr));
}

int Random::GetRandom(int begin, int end) {
    return std::uniform_int_distribution<int>(begin,end)(rand_engine);
}

float Random::GetRandom(float begin, float end) {
    return std::uniform_real_distribution<float>(begin,end)(rand_engine);
}
