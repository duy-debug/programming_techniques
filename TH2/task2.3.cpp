#include <stdio.h>
#include <stdlib.h>
#define max 30
// cau a: ham doc du lieu tu file
void ReadFile(char *s, int a2[][max], int &n){
	FILE *file=fopen(s, "r");
	if(file==NULL){
		printf("Khong the mo file\n");
	}
	else{
		// Doc ma tran A tu file
		fscanf(file,"%d",&n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
			fscanf(file,"%d", &a2[i][j]);
			}
		}
		fclose(file);
	}
}
// cau b: ham xuat ma tran ra man hinh
void PrintMaTrix(int a2[][max], int n){
	printf("Ma tran A: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%3d\t", a2[i][j]);
		}
		printf("\n");
	}
}
// cau c: ham tinh trung binh cong cac so nam tren duong cheo chinh
float Average(int a2[][max], int n){
	float sum=0;
	for(int i=0; i<n; i++){
		sum+=a2[i][i];
	}
	return sum/n;
}
// cau d: ham tim so lon nhat trong ma tran
int MaxMaTrix(int a2[][max], int n){
	int max1=a2[0][0];
	for(int i=0; i<n; i++){
		for(int j=0;	 j<n; j++){
			if(max1<a2[i][j])
			max1=a2[i][j];
		}
	}
	return max1; 
}
// Ham ghi ket qua vao file "KetQua.out"
void WriteFile(int a2[][max], int n){
	FILE *file=fopen("KetQua.out", "w");
	if(file==NULL){
		printf("Khong the mo file");
	}
	else{
	fprintf(file,"Trung binh cong: %.2f\n", Average(a2,n));
	fprintf(file,"So lon nhat: %d\n", MaxMaTrix(a2,n));
	fclose(file);
	}	
}
int main(){
	char *s="MaTran.inp";
	int a2[max][max], n;
	// Doc du lieu tu file
	ReadFile(s,a2,n);
	PrintMaTrix(a2,n);
	WriteFile(a2,n);
}
