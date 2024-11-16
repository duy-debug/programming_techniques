#include <stdio.h>
#include <stdlib.h>
#define p 50
void readfile(char *s, float a[], int &n){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=0; i<n; i++){
			fscanf(f,"%f",&a[i]);
		}
		fclose(f);
	}
}
void xuat(float a[], int n){
	for(int i=0; i<n; i++){
		printf("%.2f ", a[i]);
	}
}
float max(float a[], int n){
	if(n==1) return a[0];
	float MAX=max(a,n-1);
	return (MAX<a[n-1])?MAX:a[n-1];
}
float tong(float a[], int n){
	if(n==1) return a[0];
	else return tong(a,n-1)+a[n-1];
}
void writefile(float a[], int n){
	FILE *f=fopen("output.txt", "w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fprintf(f,"So nho nhat: %.2f\nTong: %.2f",max(a,n),tong(a,n));
		fclose(f);
	}
}
int main(){
	float a[p];
	int n;
	char *s="input.txt";
	readfile(s,a,n);
	xuat(a,n);
	max(a,n);
	writefile(a,n);
}
