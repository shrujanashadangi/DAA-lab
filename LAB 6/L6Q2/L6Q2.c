/* DAA Lab 06 - Q2: 2D square matrix operations and their complexities
 * Reads two n x n matrices A and B, and runs addition, multiplication,zero-matrix check,symmetry check,determinant,in-place transpose,
 * and dominant eigenvalue/eigenvector (power iteration) on them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *createMatrix(int n) {
    return malloc(n * n * sizeof(int));
}

void readMatrix(int *m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i * n + j]);
}

void printMatrix(int *m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", m[i * n + j]);
        printf("\n");
    }
}

int *addMatrix(int *a, int *b, int n) {
    int *c = createMatrix(n);
    for (int i = 0; i < n * n; i++)
        c[i] = a[i] + b[i];
    return c;
}

int *multiplyMatrix(int *a, int *b, int n) {
    int *c = createMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += a[i * n + k] * b[k * n + j];
            c[i * n + j] = sum;
        }
    }
    return c;
}

int isZeroMatrix(int *m, int n) {
    for (int i = 0; i < n * n; i++)
        if (m[i] != 0) return 0;
    return 1;
}

int isSymmetric(int *m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (m[i * n + j] != m[j * n + i]) return 0;
    return 1;
}

/* determinant via Gaussian elimination with partial pivoting */
double determinant(int *m, int n) {
    double *a = malloc(n * n * sizeof(double));
    for (int i = 0; i < n * n; i++) a[i] = m[i];

    double det = 1;
    for (int i = 0; i < n; i++) {
        int pivotRow = i;
        for (int k = i + 1; k < n; k++)
            if (fabs(a[k * n + i]) > fabs(a[pivotRow * n + i])) pivotRow = k;

        if (fabs(a[pivotRow * n + i]) < 1e-9) {
            det = 0;
            break;
        }

        if (pivotRow != i) {
            for (int c = 0; c < n; c++) {
                double t = a[i * n + c];
                a[i * n + c] = a[pivotRow * n + c];
                a[pivotRow * n + c] = t;
            }
            det = -det;
        }

        det *= a[i * n + i];
        for (int k = i + 1; k < n; k++) {
            double factor = a[k * n + i] / a[i * n + i];
            for (int j = i; j < n; j++)
                a[k * n + j] -= factor * a[i * n + j];
        }
    }

    free(a);
    return det;
}

void transposeInPlace(int *m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int t = m[i * n + j];
            m[i * n + j] = m[j * n + i];
            m[j * n + i] = t;
        }
}

/* dominant eigenvalue and eigenvector via power iteration */
double powerIteration(int *m, int n, double *eigenVector) {
    double *x = malloc(n * sizeof(double));
    double *y = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) x[i] = 1.0;

    double eigenValue = 0;
    int iterations = 200;
    for (int it = 0; it < iterations; it++) {
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            for (int j = 0; j < n; j++)
                y[i] += m[i * n + j] * x[j];
        }

        double norm = 0;
        for (int i = 0; i < n; i++) norm += y[i] * y[i];
        norm = sqrt(norm);
        if (norm < 1e-12) break;

        for (int i = 0; i < n; i++) x[i] = y[i] / norm;
        eigenValue = norm;
    }

    for (int i = 0; i < n; i++) eigenVector[i] = x[i];
    free(x);
    free(y);
    return eigenValue;
}

void runSingleMatrixOps(int *m, int n, const char *label) {
    printf("\n--- Checks on matrix %s ---\n", label);

    printf("Is %s a zero matrix? %s\n", label, isZeroMatrix(m, n) ? "Yes" : "No");
    printf("Is %s symmetric? %s\n", label, isSymmetric(m, n) ? "Yes" : "No");
    printf("Determinant of %s: %.2f\n", label, determinant(m, n));

    transposeInPlace(m, n);
    printf("%s transposed in place:\n", label);
    printMatrix(m, n);
    transposeInPlace(m, n); /* flip back so later steps use the original matrix */

    double *eigenVector = malloc(n * sizeof(double));
    double eigenValue = powerIteration(m, n, eigenVector);
    printf("Dominant eigenvalue of %s (approx): %.4f\n", label, eigenValue);
    printf("Corresponding eigenvector (approx): ");
    for (int i = 0; i < n; i++) printf("%.4f ", eigenVector[i]);
    printf("\n");

    free(eigenVector);
}

int main(void) {
    int n;
    printf("Enter size of square matrix (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *a = createMatrix(n);
    int *b = createMatrix(n);

    printf("Enter matrix A (%d x %d):\n", n, n);
    readMatrix(a, n);
    printf("Enter matrix B (%d x %d):\n", n, n);
    readMatrix(b, n);

    printf("\nMatrix A:\n");
    printMatrix(a, n);
    printf("Matrix B:\n");
    printMatrix(b, n);

    int *sum = addMatrix(a, b, n);
    printf("\nA + B:\n");
    printMatrix(sum, n);

    int *prod = multiplyMatrix(a, b, n);
    printf("\nA * B:\n");
    printMatrix(prod, n);

    runSingleMatrixOps(a, n, "A");
    runSingleMatrixOps(b, n, "B");

    return 0;
}
