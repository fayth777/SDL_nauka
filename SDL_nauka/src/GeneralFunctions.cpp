#include "GeneralFunctions.h"
#include <random>
float Lerp(float a, float b, float f)
{
	
		return (a * (1.0 - f)) + (b * f);

}

float GetRandom(float min, float max)
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(min, max); 
    return dis(e);

}