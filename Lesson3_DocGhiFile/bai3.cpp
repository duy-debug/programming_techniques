#include <stdio.h>
	int n;
	void ghifile(FILE)
int main(){
    int a[100];
    FILE* f= fopen("dulieu.txt","wt");
    if(f!=NULL){
        printf("Nhap 1 so nguyen: ");
        scanf("%d", &n); // ghi so vao file
        fprintf(f,"%d",n);
        // nhap n so nguyen
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            fprintf(f,"%3d",a[i]);
        }
        fclose(f);
    }
}
