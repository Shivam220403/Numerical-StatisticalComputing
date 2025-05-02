#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 11;
}

int main() {
    double a, b, c;
    int max_iterations, iteration = 0;

    cout << "Enter the initial guesses a and b (a < b): ";
    cin >> a >> b;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;

    while (iteration < max_iterations) {
        double fa = f(a), fb = f(b);
        
        if (fabs(fb - fa) < 1e-12) {
            cout << "Division by near-zero detected. Exiting.\n";
            return 1;
        }

        c = (a * fb - b * fa) / (fb - fa);

        if (fabs(f(c)) < 0.001) {
            break;
        }

        a = b;
        b = c;
        iteration++;
    }

    cout << "The root of the function is approximately: " << fixed << setprecision(3) << c << endl;

    return 0;
}
