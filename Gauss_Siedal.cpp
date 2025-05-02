#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> gaussSeidel(const vector<vector<double>>& A, const vector<double>& b, 
                           double tolerance = 1e-10, int maxIterations = 1000) {
    int n = b.size();
    vector<double> x(n, 0.0);

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        vector<double> x_new = x;

        for (int i = 0; i < n; ++i) {
            double sum = 0.0;

            for (int j = 0; j < n; ++j) {
                if (j != i)
                    sum += A[i][j] * x_new[j];
            }

            x_new[i] = (b[i] - sum) / A[i][i];
        }
        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error = max(error, abs(x_new[i] - x[i]));
        }

        if (error < tolerance) {
            cout << "Convergence reached after " << iteration + 1 << " iterations." << endl;
            return x_new;
        }

        x = x_new;
    }

    cout << "Maximum iterations reached." << endl;
    return x;
}

int main() {
    vector<vector<double>> A = {
        {4, -1, 0, 0},
        {-1, 4, -1, 0},
        {0, -1, 4, -1},
        {0, 0, -1, 3}
    };

    vector<double> b = {15, 10, 10, 10};

    vector<double> solution = gaussSeidel(A, b);

    cout << "Solution: ";
    for (double val : solution) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
