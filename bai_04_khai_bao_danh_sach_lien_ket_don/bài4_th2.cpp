#include <stdio.h>
#include <string.h>
typedef struct SinhVien {
    char HoTen[50];
    char MaSV[20];
    float Diem1;
    float Diem2;
    float Diem3;
} SinhVien;
typedef struct Node {
    SinhVien data;
    struct Node *next;
} Node;
typedef struct {
    Node *head;
    Node *tail;
} List;
void KhoiTao(List *l) {
    l->head = NULL;
    l->tail = NULL;
}
Node *TaoNode(SinhVien sv) {
    Node *p = new Node;
    p->data = sv;
    p->next = NULL;
    return p;
}
void ThemCuoi(List *l, SinhVien sv) {
    Node *p = TaoNode(sv);

    if (l->head == NULL) {
        l->head = p;
        l->tail = p;
    } else {
        l->tail->next = p;
        l->tail = p;
    }
}
void Nhap(List *l) {
    int n;
    SinhVien sv;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);

        printf("Ho ten: ");
        fgets(sv.HoTen, 50, stdin);
        sv.HoTen[strcspn(sv.HoTen, "\n")] = '\0';

        printf("Ma sinh vien: ");
        fgets(sv.MaSV, 20, stdin);
        sv.MaSV[strcspn(sv.MaSV, "\n")] = '\0';

        printf("Diem 1: ");
        scanf("%f", &sv.Diem1);

        printf("Diem 2: ");
        scanf("%f", &sv.Diem2);

        printf("Diem 3: ");
        scanf("%f", &sv.Diem3);
        getchar();

        ThemCuoi(l, sv);
    }
}
void Xuat(List l) {
    Node *p = l.head;

    printf("\n===== DANH SACH SINH VIEN =====\n");
    printf("%-20s %-15s %-10s %-10s %-10s\n",
           "Ho ten", "Ma SV", "Diem 1", "Diem 2", "Diem 3");

    while (p != NULL) {
        printf("%-20s %-15s %-10.2f %-10.2f %-10.2f\n",
               p->data.HoTen,
               p->data.MaSV,
               p->data.Diem1,
               p->data.Diem2,
               p->data.Diem3);

        p = p->next;
    }
}
void GiaiPhong(List *l) {
    Node *p;

    while (l->head != NULL) {
        p = l->head;
        l->head = l->head->next;
        delete p;
    }

    l->tail = NULL;
}
int main() {
    List l;

    KhoiTao(&l);

    Nhap(&l);

    Xuat(l);

    GiaiPhong(&l);

    return 0;
}

