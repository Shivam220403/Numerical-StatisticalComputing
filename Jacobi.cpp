#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> jacobi(const vector<vector<double>>& a, const vector<double>& b,
                      double tol = 1e-10, int maxIterations = 100) {
    int n = b.size();
    vector<double> x(n, 0.0);

    for (int itr = 0; itr < maxIterations; ++itr) {
        vector<double> x_new(n);

        for (int i = 0; i < n; ++i) {
            double sum = 0.0;

            for (int j = 0; j < n; ++j) {
                if (j != i)
                    sum += a[i][j] * x[j];
            }

            x_new[i] = (b[i] - sum) / a[i][i];
        }

        // Convergence check
        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(x_new[i] - x[i]) >= tol) {
                converged = false;
                break;
            }
        }

        if (converged) {
            cout << "Converged after " << itr + 1 << " iterations." << endl;
            return x_new;
        }

        x = x_new;
    }

    cout << "Jacobi method did not converge within the maximum number of iterations." << endl;
    return {};
}

int main() {
    vector<vector<double>> a = {
        {10, 1, 2},
        {1, 10, 1},
        {2, -1, 10}
    };
    vector<double> b = {27, -11, 17};

    vector<double> solution = jacobi(a, b);

    if (!solution.empty()) {
        cout << "Solution: ";
        for (double val : solution)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
