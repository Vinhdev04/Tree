#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 12
#define MAX_SACH 100

struct Sach {
    char maSach[MAX_LENGTH];
    char tenSach[71];
    char tenTacGia[51];
    char loaiSach[11];
    int namXuatBan;
    float giaTien;
    int soLuong;
};

void nhapDanhSachSach(struct Sach danhSach[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", danhSach[i].maSach);
        getchar();

        scanf("%70[^\n]", danhSach[i].tenSach);
        getchar();

        scanf("%50[^\n]", danhSach[i].tenTacGia);
        getchar();

        scanf("%10[^\n]", danhSach[i].loaiSach);
        getchar();

        scanf("%d", &danhSach[i].namXuatBan);
        getchar();

        scanf("%f", &danhSach[i].giaTien);
        getchar();

        scanf("%d", &danhSach[i].soLuong);
        getchar();

        printf("\n");
    }
}

void xuatDanhSachSach(const struct Sach danhSach[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - ", danhSach[i].maSach);
        printf("%s - ", danhSach[i].tenSach);
        printf("%s - ", danhSach[i].tenTacGia);
        printf("%s - ", danhSach[i].loaiSach);
        printf("%d - ", danhSach[i].namXuatBan);
        printf("%.3f - ", danhSach[i].giaTien);
        printf("%d\n", danhSach[i].soLuong);
    }
}

float tinhTongCuonSach(const struct Sach danhSach[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        float giaTienCuonSach = danhSach[i].giaTien * danhSach[i].soLuong;
        tong += giaTienCuonSach;
    }
    return tong;
}

int main() {
    int n;

    scanf("%d", &n);
    getchar();

    struct Sach danhSach[MAX_SACH];

    nhapDanhSachSach(danhSach, n);
   // xuatDanhSachSach(danhSach, n);

    float tong = tinhTongCuonSach(danhSach, n);
    printf("%.3f\n", tong);

    return 0;
}
