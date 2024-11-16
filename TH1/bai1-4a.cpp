#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define swap(x,y) (x=x+y,y=x-y,x=x-y)
#define swap1(x,y) {x=x+y;y=x-y;x=x-y;}
#define check(n) (n%2==0?1:0)
int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("So lon nhat trong hai so so dau tien: %d\n", max(a,b));
	printf("So lon nhat trong trong 4 so: %d", max(max(a,b),max(c,d)));	
	printf("\n%d %d",a,b);
	swap(a,b);
	printf("Sau khi hoan vi %d %d", a,b);
	printf("\n%d %d", c, d);
	swap1(c,d);
	printf("Sau khi hoan vi %d %d", c, d);
	if(check(a)){
		printf("\n%sd la so chan", a);
	}
	else{
		printf("\n%dkhong phai la so chan", a);
	}
}
