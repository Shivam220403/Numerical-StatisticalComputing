#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> gaussElimination(vector<vector<double>> a, vector<double> b) {
    int n = b.size();

    for (int i = 0; i < n; ++i) {
        // Partial pivoting
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(a[k][i]) > abs(a[maxRow][i])) {
                maxRow = k;
            }
        }

        if (a[maxRow][i] == 0) {
            cerr << "Singular matrix detected." << endl;
            return {};
        }

        if (maxRow != i) {
            swap(a[i], a[maxRow]);
            swap(b[i], b[maxRow]);
        }

        for (int j = i + 1; j < n; ++j) {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k < n; ++k) {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    return x;
}

int main() {
    vector<vector<double>> a = {
        {3, 2, 1},
        {2, 3, 2},
        {1, 2, 3}
    };
    vector<double> b = {1, 2, 3};

    vector<double> result = gaussElimination(a, b);
    cout << "Solution: ";
    for (double xi : result) {
        cout << xi << " ";
    }
    cout << endl;

    return 0;
}
