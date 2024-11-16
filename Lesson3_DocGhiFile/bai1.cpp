#include <stdio.h>
int main(){
    int n;
    FILE* f= fopen("dulieu.txt","wt");
    if(f!=NULL){
        printf("Nhap 1 so nguyen: ");
        scanf("%d", &n); // ghi so vao file
        fprintf(f,"%d",n);
        fclose(f);
    }
    else 
        printf("Loi mo file");
}