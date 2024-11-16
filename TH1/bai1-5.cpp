#include <stdio.h>
inline int tich(int a, int b){
	return a*b;
}
int TinhTien(int x, int y){
	int giadien=4, gianuoc=10;
	return x*4+y*10;
}
int power(int a, int b=2){
	long luythua=1;
	for(int i=1; i<=b; i++){
		luythua*=a;
	}
	return luythua;
}
float TinhDT(float dai, float rong){
	return dai*rong; // hinh chu nhat
}
float TinhDT(float rong){
	return 3.14*rong*rong; // hinh tron
}
int main(){
	int a, b;
	printf("Nhap 2 so nguyen: ");
	scanf("%d%d", &a, &b);
	printf("Tich: %d\n", tich(a,b));
	int x, y;
	printf("Nhap so kw va m3: ");
	scanf("%d%d", &x, &y);
	printf("So tien dien va nuoc: %d\n", TinhTien(x,y));
	printf("Nhap so a va b: ");
	scanf("%d%d", &a, &b);
	printf("\nLuy thua cua a mu b: %d\n", power(a,b));
	float dai, rong;
	printf("Nhap chieu dai va chieu rong: ");
	scanf("%f%f", &dai, &rong);
	printf("Tinh dien tinh hcn: %.2f\n", TinhDT(dai,rong));
	printf("Tinh dien tich hinh tron: %.2f\n", TinhDT(dai,rong));
}
