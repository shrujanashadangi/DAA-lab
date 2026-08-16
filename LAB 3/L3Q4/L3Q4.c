/* DAA Lab 03 - Q4: Matrix Multiplication using Strassen's Method */

#include <stdio.h>
#include <stdlib.h>

typedef int **Mat;

Mat alloc(int n) {
    Mat m = (Mat)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) m[i] = (int *)calloc(n, sizeof(int));
    return m;
}

void freeMat(Mat m, int n) {
    for (int i = 0; i < n; i++) free(m[i]);
    free(m);
}

Mat add(Mat a, Mat b, int n) {
    Mat r = alloc(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r[i][j] = a[i][j] + b[i][j];
    return r;
}

Mat sub(Mat a, Mat b, int n) {
    Mat r = alloc(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r[i][j] = a[i][j] - b[i][j];
    return r;
}

Mat cut(Mat src, int n, int ro, int co) {
    Mat r = alloc(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r[i][j] = src[ro + i][co + j];
    return r;
}

void place(Mat dest, Mat blk, int n, int ro, int co) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[ro + i][co + j] = blk[i][j];
}

Mat strassen(Mat a, Mat b, int n) {
    if (n == 1) {
        Mat r = alloc(1);
        r[0][0] = a[0][0] * b[0][0];
        return r;
    }

    int h = n / 2;
    Mat a11 = cut(a, h, 0, 0), a12 = cut(a, h, 0, h);
    Mat a21 = cut(a, h, h, 0), a22 = cut(a, h, h, h);
    Mat b11 = cut(b, h, 0, 0), b12 = cut(b, h, 0, h);
    Mat b21 = cut(b, h, h, 0), b22 = cut(b, h, h, h);

    Mat t1 = sub(b12, b22, h);
    Mat m1 = strassen(a11, t1, h);

    Mat t2 = add(a11, a12, h);
    Mat m2 = strassen(t2, b22, h);

    Mat t3 = add(a21, a22, h);
    Mat m3 = strassen(t3, b11, h);

    Mat t4 = sub(b21, b11, h);
    Mat m4 = strassen(a22, t4, h);

    Mat t5a = add(a11, a22, h);
    Mat t5b = add(b11, b22, h);
    Mat m5 = strassen(t5a, t5b, h);

    Mat t6a = sub(a12, a22, h);
    Mat t6b = add(b21, b22, h);
    Mat m6 = strassen(t6a, t6b, h);

    Mat t7a = sub(a11, a21, h);
    Mat t7b = add(b11, b12, h);
    Mat m7 = strassen(t7a, t7b, h);

    Mat c11 = add(sub(add(m5, m4, h), m2, h), m6, h);
    Mat c12 = add(m1, m2, h);
    Mat c21 = add(m3, m4, h);
    Mat c22 = sub(sub(add(m5, m1, h), m3, h), m7, h);

    Mat c = alloc(n);
    place(c, c11, h, 0, 0);
    place(c, c12, h, 0, h);
    place(c, c21, h, h, 0);
    place(c, c22, h, h, h);

    return c;
}

void printMat(Mat m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%4d ", m[i][j]);
        printf("\n");
    }
}

void readMat(Mat m, int n, const char *label) {
    printf("Enter matrix %s (%d x %d):\n", label, n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
}

int main(void) {
    int n;
    printf("Enter n (must be a power of 2): ");
    if (scanf("%d", &n) != 1 || n <= 0 || (n & (n - 1)) != 0) {
        printf("n must be a power of 2 (1, 2, 4, 8, ...).\n");
        return 1;
    }

    Mat a = alloc(n), b = alloc(n);
    readMat(a, n, "A");
    readMat(b, n, "B");

    Mat c = strassen(a, b, n);

    printf("\nMatrix A:\n");
    printMat(a, n);
    printf("\nMatrix B:\n");
    printMat(b, n);
    printf("\nResult (A x B):\n");
    printMat(c, n);

    freeMat(a, n); freeMat(b, n); freeMat(c, n);
    return 0;
}
