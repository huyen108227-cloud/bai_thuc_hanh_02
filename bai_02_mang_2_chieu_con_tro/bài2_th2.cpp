#include <stdio.h>
#include <stdlib.h>
int main() {
    int h, c;
    float **a;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &h, &c);
    if (h <= 0 || c <= 0) {
        printf("Kich thuoc khong hop le!");
        return 1;
    }
    a = (float**)malloc(h * sizeof(float*));

    if (a == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }
    for (int i = 0; i < h; i++) {
        a[i] = (float*)malloc(c * sizeof(float));

        if (a[i] == NULL) {
            printf("Khong du bo nho!");

            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return 1;
        }
    }
    printf("Nhap cac phan tu:\n");

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Ma tran vua nhap:\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < h; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}

