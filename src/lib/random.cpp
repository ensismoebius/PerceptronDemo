#include "random.h"

float utils::random()
{
    return ((std::rand() / float(RAND_MAX)) * 2.0) - 1.0;
}
