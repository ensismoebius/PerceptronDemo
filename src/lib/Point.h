/**
 * @author André Furlan
 * @email ensismoebius@gmail.com
 * This whole project are under GPLv3, for
 * more information read the license file
 *
 * @date 2021-10-04
*/

#ifndef src_Point_h
#define src_Point_h

class Point
{
private:
public:
    int label;
    float x;
    float y;
    Point(float x, float y);
    Point();
    ~Point();
};

#endif
