#include <iostream>
#include <cmath>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to check if a triangle is non-degenerate
bool isNonDegenerate(double ab, double ac, double bc)
{
    return (ab + bc > ac) && (bc + ac > ab) && (ab + ac > bc);
}

double absv(double num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

// Function to check if a point is inside a triangle
bool isInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp)
{
    double abc = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    double abp = (x1 * (y2 - yp) + x2 * (yp - y1) + xp * (y1 - y2)) / 2.0;
    double pbc = (xp * (y2 - y3) + x2 * (y3 - yp) + x3 * (yp - y2)) / 2.0;
    double apc = (x1 * (yp - y3) + xp * (y3 - y1) + x3 * (y1 - yp)) / 2.0;
    double total = absv(abp) + absv(pbc) + absv(apc);
    return absv(abc) == total;
}

// Function to determine the scenario number
int pointsbelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq)
{
    bool p_inside = isInsideTriangle(x1, y1, x2, y2, x3, y3, xp, yp);
    bool q_inside = isInsideTriangle(x1, y1, x2, y2, x3, y3, xq, yq);

    if (!isNonDegenerate(distance(x1, y1, x2, y2), distance(x2, y2, x3, y3), distance(x1, y1, x3, y3)))
    {
        return 0; // Triangle is degenerate
    }
    else if (p_inside && !q_inside)
    {
        return 1; // p belongs but q does not
    }
    else if (!p_inside && q_inside)
    {
        return 2; // q belongs but p does not
    }
    else if (p_inside && q_inside)
    {
        return 3; // Both p and q belong
    }
    else
    {
        return 4; // Neither p nor q belong
    }
}

int main()
{
    int x1 = 3, y1 = 1, x2 = 7, y2 = 1, x3 = 5, y3 = 5, xp = 1, yp = 1, xq = 4, yq = 3;
    std::cout << pointsbelong(x1, y1, x2, y2, x3, y3, xp, yp, xq, yq) << std::endl; // Output: 3
    return 0;
}
