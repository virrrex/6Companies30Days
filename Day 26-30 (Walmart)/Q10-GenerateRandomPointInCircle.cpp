#include <bits/stdc++.h>
using namespace std;

#define M_PI 22/7

class Solution {
public:
    double R, X, Y;
    Solution(double radius, double x_center, double y_center) : R(radius), X(x_center), Y(y_center) {
        srand(time(0));
    }
    double random(){
        return (double)rand() / RAND_MAX;
    }
    vector<double> randPoint() {
        vector<double> randomPoint(2);
        double len = sqrt(random()) * R, deg = 2 * M_PI * random();
        randomPoint[0] = X + len * cos(deg);
        randomPoint[1] = Y + len * sin(deg);
        return randomPoint;
    }
};