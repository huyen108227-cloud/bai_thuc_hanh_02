#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;
typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptyList(LList L) {
    return (L.spt == 0);
}
Node *createNode(Data x) {
    Node *pp = (Node*)malloc(sizeof(Node));

    if (pp == NULL) {
        printf("Khong du bo nho!\n");
        return NULL;
    }

    pp->infor = x;
    pp->link = NULL;

    return pp;
}
void insert_Head(LList *L, Data x) {
    Node *pp = createNode(x);

    if (pp == NULL) return;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        pp->link = L->pHead;
        L->pHead = pp;
    }

    L->spt++;
}
void insert_Tail(LList *L, Data x) {
    Node *pp = createNode(x);

    if (pp == NULL) return;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->link = pp;
        L->pTail = pp;
    }

    L->spt++;
}
void insert_After(LList *L, Data x, int ma) {
    Node *p = L->pHead;

    while (p != NULL && p->infor.masv != ma) {
        p = p->link;
    }

    if (p == NULL) {
        printf("Khong tim thay sinh vien co ma %d!\n", ma);
        return;
    }

    Node *pp = createNode(x);

    if (pp == NULL) return;

    pp->link = p->link;
    p->link = pp;

    if (p == L->pTail) {
        L->pTail = pp;
    }

    L->spt++;

    printf("Them sinh vien thanh cong!\n");
}
void delete_Node(LList *L, int ma) {
    Node *p = L->pHead;
    Node *q = NULL;

    while (p != NULL && p->infor.masv != ma) {
        q = p;
        p = p->link;
    }

    if (p == NULL) {
        printf("Khong tim thay sinh vien can xoa!\n");
        return;
    }

    if (q == NULL) {
        L->pHead = p->link;
    } else {
        q->link = p->link;
    }

    if (p == L->pTail) {
        L->pTail = q;
    }

    free(p);
    L->spt--;

    if (L->spt == 0) {
        L->pHead = NULL;
        L->pTail = NULL;
    }

    printf("Xoa sinh vien thanh cong!\n");
}
void nhap(Data *x) {
    printf("Nhap ma sinh vien (nhap 0 de huy): ");
    scanf("%d", &x->masv);
    getchar();

    if (x->masv > 0) {
        printf("Nhap ho ten: ");
        fgets(x->hoten, 30, stdin);
        x->hoten[strcspn(x->hoten, "\n")] = '\0';

        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);

        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);

        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}
void in(Data x) {
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
           x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L) {
    Node *pp = L.pHead;

    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("\n===== DANH SACH SINH VIEN =====\n");

    while (pp != NULL) {
        in(pp->infor);
        pp = pp->link;
    }

    printf("Tong so sinh vien: %d\n", L.spt);
}
void freeList(LList *L) {
    Node *p;

    while (L->pHead != NULL) {
        p = L->pHead;
        L->pHead = L->pHead->link;
        free(p);
    }

    L->pTail = NULL;
    L->spt = 0;
}
int main() {
    LList L;
    int kt = 0;
    int chon;
    int ma;
    Data x;

    initList(&L);

    do {
        printf("\n===== CHUONG TRINH DSLK DON SINH VIEN =====\n");
        printf("1: Them nut vao dau danh sach\n");
        printf("2: Them nut vao cuoi danh sach\n");
        printf("3: Them nut vao sau mot nut khac\n");
        printf("4: Xoa sinh vien theo ma\n");
        printf("9: Duyet danh sach\n");
        printf("0: Thoat\n");

        printf("Moi ban chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("\nNhap thong tin sinh vien:\n");
                nhap(&x);

                if (x.masv > 0) {
                    insert_Head(&L, x);
                    printf("Them sinh vien thanh cong!\n");
                }
                break;

            case 2:
                printf("\nNhap thong tin sinh vien:\n");
                nhap(&x);

                if (x.masv > 0) {
                    insert_Tail(&L, x);
                    printf("Them sinh vien thanh cong!\n");
                }
                break;

            case 3:
                printf("\nNhap ma sinh vien can them sau: ");
                scanf("%d", &ma);

                printf("Nhap thong tin sinh vien moi:\n");
                nhap(&x);

                if (x.masv > 0) {
                    insert_After(&L, x, ma);
                }
                break;

            case 4:
                printf("Nhap ma sinh vien can xoa: ");
                scanf("%d", &ma);

                delete_Node(&L, ma);
                break;

            case 9:
                processList(L);
                break;

            case 0:
                printf("Bye bye!\n");
                kt = 1;
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (kt == 0);

    freeList(&L);

    return 0;
}

