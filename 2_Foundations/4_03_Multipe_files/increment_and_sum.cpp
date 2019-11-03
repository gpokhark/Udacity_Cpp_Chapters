#include "vect_add_one.h"

int IncrementAndComputeVectorSum(std::vector<int> v)
{
    int total = 0;
    AddOneToEach(v);
    for (auto &i : v)
    {
        total += i;
    }
    return total;
}