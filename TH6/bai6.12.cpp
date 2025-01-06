#include <stdio.h>
#include <stdbool.h>
#define MAX 100
// Ham tim day con co tong bang S
bool subset_sum(int a[], int n, int S) {
    bool dp[n+1][S+1]; // Bang quy hoach dong
    // Khoi tao
    for (int i=0; i<=n; i++) {
        dp[i][0] = true; // Tong = 0 luon co the thuc hien (bo chon tat ca phan tu)
    }
    for (int j=1; j<=S; j++) {
        dp[0][j] = false; // Khong co phan tu nao thi khong the dat tong > 0
    }
    // Dien bang dp
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=S; j++) {
            if (a[i-1]<=j) {
                // Neu phan tu a[i-1] co the duoc chon
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            } else {
                // Neu khong the chon phan tu a[i-1]
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // Neu co giai phap, truy vet de in day con
    if (dp[n][S]){
        printf("Day con co tong bang %d la: ", S);
        int i=n, j=S;
        while (j>0 && i>0) {
            if (dp[i][j]!=dp[i-1][j]){
                printf("%d ", a[i-1]); // In phan tu duoc chon
                j-=a[i-1];
            }
            i--;
        }
        printf("\n");
        return true;
    } else {
        printf("Khong co day con nao co tong bang %d\n", S);
        return false;
    }
}
int main(){
    int n, S;
    int a[MAX];
    // Nhap du lieu
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu cua day:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Nhap tong S can tim: ");
    scanf("%d", &S);
    // Goi ham tinh toan
    subset_sum(a, n, S);
    return 0;
}

