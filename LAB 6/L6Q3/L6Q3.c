/* DAA Lab 06 - Q3: Convolution of two vectors in O(n log n)
 * using a divide and conquer FFT (Cooley-Tukey).
 * A has length m, B has length n, n >= m. Result C has length m+n-1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double re, im;
} Complex;

Complex cAdd(Complex a, Complex b) {
    Complex r = { a.re + b.re, a.im + b.im };
    return r;
}

Complex cSub(Complex a, Complex b) {
    Complex r = { a.re - b.re, a.im - b.im };
    return r;
}

Complex cMul(Complex a, Complex b) {
    Complex r = { a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re };
    return r;
}

void fft(Complex *a, int n, int invert) {
    if (n == 1) return;

    Complex *even = malloc((n / 2) * sizeof(Complex));
    Complex *odd  = malloc((n / 2) * sizeof(Complex));
    for (int i = 0; i < n / 2; i++) {
        even[i] = a[2 * i];
        odd[i]  = a[2 * i + 1];
    }

    fft(even, n / 2, invert);
    fft(odd, n / 2, invert);

    double angleSign = invert ? 1.0 : -1.0;
    for (int k = 0; k < n / 2; k++) {
        double angle = angleSign * 2 * M_PI * k / n;
        Complex w = { cos(angle), sin(angle) };
        Complex t = cMul(w, odd[k]);
        a[k]         = cAdd(even[k], t);
        a[k + n / 2] = cSub(even[k], t);
    }

    free(even);
    free(odd);
}

int nextPowerOf2(int x) {
    int p = 1;
    while (p < x) p *= 2;
    return p;
}

int convolve(double *A, int m, double *B, int n, double *result) {
    int resultLen = m + n - 1;
    int size = nextPowerOf2(resultLen);

    Complex *fa = malloc(size * sizeof(Complex));
    Complex *fb = malloc(size * sizeof(Complex));

    for (int i = 0; i < size; i++) {
        fa[i].re = (i < m) ? A[i] : 0;
        fa[i].im = 0;
        fb[i].re = (i < n) ? B[i] : 0;
        fb[i].im = 0;
    }

    fft(fa, size, 0);
    fft(fb, size, 0);

    for (int i = 0; i < size; i++)
        fa[i] = cMul(fa[i], fb[i]);

    fft(fa, size, 1);

    for (int i = 0; i < resultLen; i++)
        result[i] = fa[i].re / size;

    free(fa);
    free(fb);
    return resultLen;
}

int main(void) {
    int m, n;
    printf("Enter length of vector A (m): ");
    scanf("%d", &m);
    double *A = malloc(m * sizeof(double));
    printf("Enter %d elements of A:\n", m);
    for (int i = 0; i < m; i++) scanf("%lf", &A[i]);

    printf("Enter length of vector B (n), n >= m: ");
    scanf("%d", &n);
    double *B = malloc(n * sizeof(double));
    printf("Enter %d elements of B:\n", n);
    for (int i = 0; i < n; i++) scanf("%lf", &B[i]);

    double *result = malloc((m + n - 1) * sizeof(double));
    int resultLen = convolve(A, m, B, n, result);

    printf("\nConvolution C = A * B:\n");
    for (int i = 0; i < resultLen; i++)
        printf("%.4f ", result[i]);
    printf("\n");

    free(A);
    free(B);
    free(result);
    return 0;
}
