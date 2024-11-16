#include <stdio.h>
float TinhLaiSuat(int sotien, int n){
    if(n==0) return sotien;
    else return 1.06*TinhLaiSuat(sotien,n-1);
}
int main(){
    int n;
    float sotien;
    printf("Nhap so tien gui: ");
    scanf("%f", &sotien);
    printf("Nhap so nam: "); 
    scanf("%d", &n);
    printf("So tien sau khi gui la : %.3f", TinhLaiSuat(sotien,n));
}
