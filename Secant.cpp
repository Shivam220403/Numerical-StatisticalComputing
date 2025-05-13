#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - x - 11;
}

double secantMethod(double a, double b, int max_iterations, double tolerance = 0.001) {
    int iteration = 0;
    double c;

    while (iteration < max_iterations) {
        double fa = f(a), fb = f(b);

        if (fabs(fb - fa) < 1e-12) {
            cout << "Division by near-zero detected. Exiting.\n";
            return NAN;
        }

        c = (a * fb - b * fa) / (fb - fa);

        if (fabs(f(c)) < tolerance) {
            break;
        }

        a = b;
        b = c;
        iteration++;
    }

    return c;
}

int main() {
    double a, b;
    int max_iterations;

    cout << "Enter the initial guesses a and b (a < b): ";
    cin >> a >> b;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;

    double root = secantMethod(a, b, max_iterations);
    if (isnan(root)) {
        cout << "Root finding failed due to instability or invalid inputs.\n";
    } else {
        cout << "The root of the function is approximately: " << fixed << setprecision(3) << root << endl;
    }

    return 0;
}
