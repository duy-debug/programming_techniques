#include <stdio.h>
void hoanvi(int x, int y){
   int temp=x;
   x=y;
   y=temp;
}
int main(){
   int a, b;
   scanf("%d%d",&a,&b);
hoanvi(a,b);
   printf("sau khi hoan vi: %d %d", a, b);
   return 0;
}
