//DAA Lab 03 - Q5: Multiply special-pattern square matrices in O(n^2)

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

Mat cut(Mat src, int n, int ro, int co) {
    Mat r = alloc(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r[i][j] = src[ro + i][co + j];
    return r;
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

void place(Mat dest, Mat blk, int n, int ro, int co) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[ro + i][co + j] = blk[i][j];
}

/* checks the array really has the M = [[M1,M2],[M2,M1]] pattern at every level */
int isSpecial(Mat m, int n, int ro, int co) {
    if (n == 1) return 1;
    int h = n / 2;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++) {
            if (m[ro + i][co + j] != m[ro + h + i][co + h + j]) return 0;
            if (m[ro + i][co + h + j] != m[ro + h + i][co + j]) return 0;
        }
    return isSpecial(m, h, ro, co) && isSpecial(m, h, ro, co + h);
}

Mat mul(Mat a, Mat b, int n) {
    if (n == 1) {
        Mat r = alloc(1);
        r[0][0] = a[0][0] * b[0][0];
        return r;
    }

    int h = n / 2;
    Mat a1 = cut(a, h, 0, 0);
    Mat a2 = cut(a, h, 0, h);
    Mat b1 = cut(b, h, 0, 0);
    Mat b2 = cut(b, h, 0, h);

    Mat pa = add(a1, a2, h);
    Mat qa = sub(a1, a2, h);
    Mat pb = add(b1, b2, h);
    Mat qb = sub(b1, b2, h);

    Mat pc = mul(pa, pb, h);
    Mat qc = mul(qa, qb, h);

    Mat c1 = alloc(h);
    Mat c2 = alloc(h);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++) {
            c1[i][j] = (pc[i][j] + qc[i][j]) / 2;
            c2[i][j] = (pc[i][j] - qc[i][j]) / 2;
        }

    Mat c = alloc(n);
    place(c, c1, h, 0, 0);
    place(c, c2, h, 0, h);
    place(c, c2, h, h, 0);
    place(c, c1, h, h, h);

    return c;
}

void printMat(Mat m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%4d ", m[i][j]);
        printf("\n");
    }
}

void readMatrix(Mat m, int n, const char *label) {
    do {
        printf("Enter matrix %s (%d x %d), must follow the [[M1,M2],[M2,M1]] pattern:\n",
               label, n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &m[i][j]);

        if (!isSpecial(m, n, 0, 0))
            printf("That doesn't follow the required pattern, try again.\n\n");
    } while (!isSpecial(m, n, 0, 0));
}

int main(void) {
    int n;
    printf("Enter n (must be a power of 2): ");
    if (scanf("%d", &n) != 1 || n <= 0 || (n & (n - 1)) != 0) {
        printf("n must be a power of 2 (1, 2, 4, 8, ...).\n");
        return 1;
    }

    Mat a = alloc(n), b = alloc(n);
    readMatrix(a, n, "A");
    readMatrix(b, n, "B");

    Mat c = mul(a, b, n);

    printf("\nResult (A x B):\n");
    printMat(c, n);

    freeMat(a, n); freeMat(b, n); freeMat(c, n);
    return 0;
}
