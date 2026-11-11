#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    float *a;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So phan tu khong hop le!");
        return 1;
    }
    a = (float*)malloc(n * sizeof(float));

    if (a == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", a + i);
    }
    printf("Mang vua nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", *(a + i));
    }
    free(a);
    return 0;
}

