#include <iostream>
#include <iomanip>

const int MAX_SIZE = 10;

void gaussElimination(double mat[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(mat[k][i]) > std::abs(mat[maxRow][i])) {
                maxRow = k;
            }
        }
        for (int k = i; k <= n; k++) {
            std::swap(mat[maxRow][k], mat[i][k]);
        }

        // Make all elements below the diagonal equal to zero
        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // Back substitution
    double solution[MAX_SIZE];
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= mat[i][j] * solution[j];
        }
        solution[i] /= mat[i][i];
    }

    // Print the solution
    std::cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "x[" << i << "] = " << std::fixed << std::setprecision(2) << solution[i] << "\n";
    }
}

int main() {
    int n;
    double mat[MAX_SIZE][MAX_SIZE + 1];

    std::cout << "Enter the number of variables in the system: ";
    std::cin >> n;

    std::cout << "Enter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            std::cout << "mat[" << i << "][" << j << "]: ";
            std::cin >> mat[i][j];
        }
    }

    gaussElimination(mat, n);

    return 0;
}
