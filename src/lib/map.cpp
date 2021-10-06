/**
 * @author André Furlan
 * @email ensismoebius@gmail.com
 * This whole project are under GPLv3, for
 * more information read the license file
 *
 * @date 2021-10-06
*/

#include "map.h"
#include <cmath>

double
mapOneRangeToAnother(double sourceNumber, double fromA, double fromB, double toA, double toB, int decimalPrecision)
{
    double deltaA = fromB - fromA;
    double deltaB = toB - toA;
    double scale = deltaB / deltaA;
    double negA = -1 * fromA;
    double offset = (negA * scale) + toA;
    double finalNumber = (sourceNumber * scale) + offset;
    int calcScale = (int)std::pow(10, decimalPrecision);
    return (double)std::round(finalNumber * calcScale) / calcScale;
}
