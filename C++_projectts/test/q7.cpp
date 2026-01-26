#include <cmath>

struct Point {
    double x;
    double y;
};


double sss(Point t1, Point t2) {
    double dx = t2.x - t1.x;
    double dy = t2.y - t1.y;
    return sqrt(dx * dx + dy * dy);
}