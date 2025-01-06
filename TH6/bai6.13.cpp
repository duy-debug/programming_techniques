#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// Ham tinh gia tri lon nhat cho bai toan cai tui
int cai_tui(int suc_chua, int trong_luong[], int gia_tri[], int so_vat) {
    int L[so_vat + 1][suc_chua + 1]; // Bang phuong an 2 chieu

    // Khoi tao bang L
    for (int i = 0; i <= so_vat; i++) {
        for (int j = 0; j <= suc_chua; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // Bai toan con nho nhat
            } else if (trong_luong[i - 1] <= j) {
                // Chon gia tri lon nhat giua chon vat i hoac khong chon vat i
                int chon_vat = gia_tri[i - 1] + L[i - 1][j - trong_luong[i - 1]];
                int khong_chon_vat = L[i - 1][j];
                L[i][j] = (chon_vat > khong_chon_vat) ? chon_vat : khong_chon_vat;
            } else {
                L[i][j] = L[i - 1][j]; // Khong the chon vat i
            }
        }
    }

    return L[so_vat][suc_chua]; // Ket qua toi uu
}

int main() {
    int so_vat; // So luong vat
    printf("Nhap so luong vat: ");
    scanf("%d", &so_vat);

    int gia_tri[so_vat], trong_luong[so_vat]; // Gia tri va trong luong cua cac vat
    printf("Nhap gia tri va trong luong cua tung vat (gia tri, trong luong):\n");
    for (int i = 0; i < so_vat; i++) {
        printf("Vat %d: ", i + 1);
        scanf("%d %d", &gia_tri[i], &trong_luong[i]);
    }

    int suc_chua; // Suc chua cua balo
    printf("Nhap suc chua cua balo: ");
    scanf("%d", &suc_chua);

    // Tinh gia tri lon nhat
    int gia_tri_lon_nhat = cai_tui(suc_chua, trong_luong, gia_tri, so_vat);
    printf("Gia tri lon nhat co the dat duoc la: %d\n", gia_tri_lon_nhat);

    return 0;
}

