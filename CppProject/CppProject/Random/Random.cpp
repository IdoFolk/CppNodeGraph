#include "Random.h"

#include <random>
using namespace std;

int Random::GetRandomInt(int minValue, int maxValue)
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(minValue, maxValue);

    return dis(gen);
}
