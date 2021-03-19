#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b)
{
    int x_max = b.x;
    int x_min = a.x;
    int y_max = b.y;
    int y_min = a.y;

    if (a.x >= b.x)
    {
        x_max = a.x;
        x_min = b.x;
    }
    if (a.y >= b.y)
    {
        y_max = a.y;
        y_min = b.y;
    }

    if (a.x == b.x)
    {
        if ((p.x < a.x) && p.y <= y_max && p.y > y_min)
        {
            return 1;
        }
        else if ((p.x == a.x) && (p.y >= y_min && p.y <= y_max))
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    if (a.y == b.y)
    {

        if ((p.y == a.y) && (p.x >= x_min && p.x <= x_max))
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    double m;
    double n;
    m = (double)(a.y - b.y) / (a.x - b.x);
    n = (double)b.y - m * b.x;

    if ((fabs(p.y - (m * p.x + n)) < 0.00001) &&
        (fabs(p.x - (p.y - n) / m) < 0.00001) &&
        (p.x >= x_min) && (p.x <= x_max) &&
        (p.y >= y_min) && (p.y <= y_max))
    {
        return 2;
    }
    else if (((p.y < y_max) 
    && (p.y > y_min) 
    && (p.x < x_max) 
    && (((p.y - n) / m) > p.x)) 
    || (p.y == y_max && ((p.y - n) / m) > p.x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inside(point p, point poly[], int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (verify(p, poly[i], poly[0]) == 2)
            {
                return 1;
            }
            else if (verify(p, poly[i], poly[0]) == 1)
            {
                counter += 1;
            }
            if (counter % 2 == 0 || counter == 0)
            {
                return 0;
            }
            else if (counter % 2 != 0)
            {
                return 1;
            }
        }
        if (verify(p, poly[i], poly[i + 1]) == 2)
        {
            return 1;
        }
        else if (verify(p, poly[i], poly[i + 1]) == 1)
        {
            counter += 1;
        }
    }
    return 0;
}
