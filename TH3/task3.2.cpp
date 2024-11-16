#include <stdio.h>
// tinh a^n (1<n<30)
// dung de quy
long long luy_Thua(int a, int n){
	if(n==0) return 1;
	else return luy_Thua(a,n-1)*a;
}
// dung vong lap
long long luy_Thua1(int a, int n){
	long long tich=1;
	for(int i=0; i<n; i++){
		tich*=a;
	}
	return tich;
}
// Tim so fibonacci thu n (3<n<20)
// dung de quy
int Fibo(int n){
	if(n==0 || n==1) return n;
	else return Fibo(n-2)+Fibo(n-1);
}
// Vong lap
int f[100];
int Fibo1(int n){
	f[0]=0, f[1]=1;
	for(int i=2; i<=n; i++){
		f[i]=f[i-2]+f[i-1];
	}
	return f[n];
}
// Bai toan thap Ha Noi
void Thap_Hanoi(int n, char nguon, char trunggian, char dich){
    if (n==1){
        printf("%c -> %c\n", nguon, dich); 
    }
	else{
        Thap_Hanoi(n - 1, nguon, dich, trunggian); 
        printf("%c -> %c\n", nguon, dich); 
        Thap_Hanoi(n - 1, trunggian, nguon, dich); 
    }
}
int main(){
	int a, n;
	printf("Nhap a: "); scanf("%d", &a);
	do{
		printf("Nhap n (1<n<30): ");
		scanf("%d", &n);
	}while(n<=1 || n>=30);
	printf("%d^%d = %lld (de quy)\n", a, n, luy_Thua(a,n));
	printf("%d^%d = %lld (vong lap)\n", a, n, luy_Thua1(a,n));
	do{
		printf("Nhap n (3<n<20): ");
		scanf("%d", &n);
	}while(n<=3 || n>=20);
	printf("So fibonacci thu %d la: %d (de quy)\n", n, Fibo(n));
	printf("So fibonacci thu %d la: %d (vong lap)\n", n, Fibo1(n));
	int m;
	printf("Nhap n so dia: ");
	scanf("%d", &m);
	Thap_Hanoi(m,'A','B','C');
}
