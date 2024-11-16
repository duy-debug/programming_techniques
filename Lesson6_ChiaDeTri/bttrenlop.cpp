// a^n
#include <stdio.h>
long long luythua(int a, int l, int n){
	if(n==0)
		return 1;
    if(l==n)
    	return a;
    int m=(l+n)/2;
    return luythua(a,l,m)*luythua(a,m+1,n);
}
int main(){
    int a, n;
    scanf("%d%d", &a, &n);
    printf("%d^%d= %lld", a,n,luythua(a, 1, n));
}
