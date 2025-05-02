#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * log(x) - 1.2;
}

double regulaFalsi(double x0, double x1, double eps = 1e-5) {
    if (f(x0) * f(x1) >= 0) {
        cout << "Regula Falsi method fails." << endl;
        return NAN;
    }

    double x;
    for (int i = 0; i < 100; ++i) {
        x = x0 - (f(x0) * (x1 - x0)) / (f(x1) - f(x0));

        if (abs(f(x)) < eps) {
            cout << "Root is: " << x << endl;
            return x;
        }

        if (f(x0) * f(x) < 0)
            x1 = x;
        else
            x0 = x;
    }

    cout << "Method did not converge within 100 iterations." << endl;
    return NAN;
}

int main() {
    double x0 = 1.0, x1 = 2.0;
    double root = regulaFalsi(x0, x1);
    cout<<"The Root is: "<< root << endl;
    return 0;
}
