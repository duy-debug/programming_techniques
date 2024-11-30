#include<stdio.h>
#include<stdlib.h>
struct HocPhan{
	char ma[255], ten[255];
	int sotc;
};
HocPhan *ds;
int n;

void DocFile(){
	FILE* f = fopen("HocPhan.txt","r");
	if(f != NULL)
	{
		fscanf(f,"%d\n",&n);
		char temp[255];
		ds= (HocPhan *)malloc(n*sizeof(HocPhan));
		for(int i = 0; i < n; i++){
			fgets(ds[i].ma, 255, f);
			fgets(ds[i].ten, 255, f);
			fgets(temp,255,f);
			ds[i].sotc = atoi(temp);
		}
		fclose(f);
	}else
		printf("Err.");
}
void Show_List()
{
	printf("So hoc phan: %d\n", n);
	printf("Danh sach cac hoc phan: \n");
	for(int i = 0; i < n; i++){
		printf("%s", ds[i].ma);
		printf("%s", ds[i].ten);
		printf("%d\n", ds[i].sotc);
	}
}
int main()
{
	DocFile();
	Show_List();
	return 0;
}
