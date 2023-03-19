#include <stdio.h>
#include <stdlib.h>

void convolution(int M, int N, int k, int image[M][N], int filter[k][k], int result[M-k+1][N-k+1]) {
    int i, j, m, n, ii, jj;
    int sum;

    for (i = 0; i < M-k+1; i++) {
        for (j = 0; j < N-k+1; j++) {
            sum = 0;
            for (m = 0; m < k; m++) {
                for (n = 0; n < k; n++) {
                    ii = i + m;
                    jj = j + n;
                    sum += image[ii][jj] * filter[m][n];
                }
            }
            result[i][j] = sum;
        }
    }
}
int main() {
    int M, N, k;
    int i, j;

    printf("Image matrisinin boyutunu girin (MxN): ");
    scanf("%d %d", &M, &N);
    int image[M][N];
    printf("Image matrisinin elemanlarını girin (MxN): \n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Filtre matrisinin boyutunu girin (kxk): ");
    scanf("%d", &k);
    int filter[k][k];
    printf("Filtre matrisinin elemanlarını girin (kxk): \n");
    int sumoffilter = 0;
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &filter[i][j]);
            sumoffilter += filter[i][j];
        }
    }

    int result[M-k+1][N-k+1];
    convolution(M, N, k, image, filter, result);

    printf("Konvolusyon işlemi sonucu: (M-k+1 x N-k+1): \n");
    for (i = 0; i < M-k+1; i++) {
        for (j = 0; j < N-k+1; j++) {
            printf("%d ", result[i][j] / sumoffilter);
        }
        printf("\n");
    }

    return 0;
}
