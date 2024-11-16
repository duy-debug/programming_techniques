#include <stdio.h>
int main(){
    int n;
    FILE* f= fopen("dulieu.txt","rt");
    if(f!=NULL){
        // doc so tu file vao chuong trinh
        fscanf(f,"%d",&n);
        printf("So nguyen doc tu file la %d",n);
        fclose(f);
    }
    else 
        printf("Loi mo file! ");
}