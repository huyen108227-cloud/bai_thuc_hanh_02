#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char hoten[50];
    int masv;
    float d1, d2, d3;
} SinhVien;
int main() {
    int n;
    SinhVien *ds;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong khong hop le!");
        return 1;
    }
    ds = (SinhVien*)malloc(n * sizeof(SinhVien));

    if (ds == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);

        printf("Nhap ma sinh vien: ");
        scanf("%d", &(ds + i)->masv);

        printf("Nhap ho ten: ");
        scanf(" %49[^\n]", (ds + i)->hoten);

        printf("Nhap diem 1: ");
        scanf("%f", &(ds + i)->d1);

        printf("Nhap diem 2: ");
        scanf("%f", &(ds + i)->d2);

        printf("Nhap diem 3: ");
        scanf("%f", &(ds + i)->d3);
    }
    printf("\nDANH SACH SINH VIEN\n");

    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);

        printf("Ma SV: %d\n", (ds + i)->masv);
        printf("Ho ten: %s\n", (ds + i)->hoten);
        printf("Diem 1: %.2f\n", (ds + i)->d1);
        printf("Diem 2: %.2f\n", (ds + i)->d2);
        printf("Diem 3: %.2f\n", (ds + i)->d3);
    }
    free(ds);
    return 0;
}

