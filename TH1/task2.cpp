#include <stdio.h>
#include <string.h>
struct Sinhvien{
	char maHP[50];
	char tenHP[50];
	int sotinchi;
};
HocPhan *ds;
int n;
void ReadFile(){
	FILE *file=fopen("hocphan.txt", "r");
	if(file!=NULL){
		fscanf(file,"%d\n",&n); // doc so luong HocPhan
		char tem[255];
		 ds=(HocPhan*)malloc(n*sizeof(HocPhan));
		 for(int i=0; i<n; i++){
		 	fgets(ds[i],ma,255,file); // doc ca dong du lieu
		 	fgets(ds[i],ten,file);
		 	fgets(tem,255,file);
		 	ds[i].sotinchi=atoi(tem); // doc dong dl va sang so
		}
		fclose(file);
	}
	else{
		printf("Loi");
	}
}
void ShowList(){
		printf("So hoc phan: %d\n");
		printf("Danh sach cac hoc phan: \n");
		for(int i=0; i<n; i++){
			printf("%s", ds[i].maHP);
			printf("%s", ds[i].tenHP);
			printf("%d", ds[i].sotinchi);
	}
}
int main(){
	ReadFile();
	ShowList();
}
