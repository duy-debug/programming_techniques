#include <stdio.h>
#define MAX 100
int a[MAX]; // Mang chua cac phan tu
int n;      // So luong phan tu
int L[MAX]; // Mang luu do dai day con tang tai moi phan tu
int t[MAX]; // Mang luu chi so phan tu truoc do trong day con tang
int lmax;   // Do dai lon nhat tam thoi
// Ham khoi tao du lieu
void init(){
    printf("Nhap so luong phan tu cua day: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu cua day:\n");
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    // Khoi tao mang L va t
    for (int i=0; i<n; i++){
        L[i]=0;  // Dat gia tri ban dau cua L[i] la 0
        t[i]=-1; // Khong co phan tu truoc
    }
}
// Ham tinh do dai day con tang dai nhat
void Dynamic() {
    for (int i=0; i<n; i++){
        lmax=0; // Dat gia tri lon nhat tam thoi la 0
        for (int j=0; j<i; j++){
            // Neu phan tu truoc nho hon va do dai day con tang truoc do lon nhat
            if (a[j]<a[i] && lmax<L[j]){
                lmax=L[j];
                t[i]=j; // Luu chi so phan tu truoc do
            }
        }
        L[i]=lmax+1; // Cap nhat do dai day con tang tai phan tu i
    }
}
// Ham truy vet va in ket qua
void Track(){
    int max=L[0], p=-1;
    // Tim phan tu ket thuc cua day con tang dai nhat
    for (int i=0; i<n; i++){
        if (max<L[i]){
            max=L[i];
            p=i;
        }
    }
    printf("\nDo dai day tang dai nhat la: %d", max);
    // Truy vet cac phan tu trong day con tang
    printf("\nDay con tang dai nhat: ");
    int result[max]; // Mang luu cac phan tu trong day con tang
    int index=max-1;
    while (p>=0){
        result[index--]=a[p];
        p=t[p];
    }
    // In day con tang
    for (int i=0; i<max; i++){
        printf("%d ", result[i]);
    }
}
int main(){
    init();    // Khoi tao du lieu
    Dynamic(); // Tim do dai day con tang dai nhat
    Track();   // Truy vet va in ket qua
    return 0;
}

