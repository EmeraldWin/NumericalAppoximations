#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double userFunction(double x) {
    double answer;

    answer = (x) * exp(-x);

    return answer;
}

int main() {
    double a, b, h, n, totalSum, totalSum1, totalSum2, answer;

    cout << "Upper Bound: " << endl;
    cin  >> b;
    cout << "Lower Bound: " << endl;
    cin  >> a;
    cout << "Spacing between subintervals: " << endl;
    cin  >> h;

    n = (b - a) / h;
    totalSum = 0;

    int userChoice;
    cout << endl;
    cout << "Pick One: " << endl;
    cout << "1. Composite Trapezoid Rule" << endl;
    cout << "2. Composite Simpson's 1/3"  << endl;
    cout << "3. Gaussian Quadrature Rule" << endl;
    cin  >> userChoice;
    cout << endl;

    if (userChoice == 1) {
        for (int i = 1; i <= (n - 1); ++i) {
        totalSum += userFunction(a + (i * h));
        
        }
        answer = (h / 2) * (userFunction(0) + userFunction(1)) + (h * totalSum);
        cout << "Numerical Solution from Composite Trapezoid Rule: " << setprecision(10) << answer << endl;
    }

    if (userChoice == 2) {
        for (int i = 1; i <= (n / 2); ++i) {
        totalSum1 += userFunction(a + ((2* i - 1) * h));
        }

        for (int i = 1; i <= (n - 2) / 2; ++i) {
        totalSum2 += userFunction(a + (2 * i * h));
        }

        answer = (h / 3) * (userFunction(a) + userFunction(b)) + ((4 * h) / 3) * (totalSum1) + ((2 * h) / 3) * (totalSum2);
        cout << "Numerical Solution from Composite Simpson's 1/3 Rule: " << setprecision(10) << answer << endl;
    }

    if (userChoice == 3) {
        double t = sqrt(0.333333333);

        answer = (0.5) * (userFunction(0.5 + (0.5 * (-t))) + userFunction(0.5 + (0.5 * t)));
        cout << "Numerical Soution from Gaussian Quadrature Rule: " << setprecision(10) << answer << endl;
    }

    return 0;
}