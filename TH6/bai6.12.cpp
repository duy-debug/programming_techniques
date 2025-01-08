#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int n, S;
int A[MAX];
bool L[MAX][MAX];
int Trace[MAX];   
void Init(){
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    printf("Nhap tong S: ");
    scanf("%d", &S);
    printf("Nhap cac phan tu cua day: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i <= n; i++)
        L[i][0] = true; 
    for (int j = 1; j <= S; j++)
        L[0][j] = false;
}
void Dynamic(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= S; j++){
            if (j < A[i])
                L[i][j] = L[i - 1][j];
            else 
                L[i][j] = L[i - 1][j] || L[i - 1][j - A[i]];
        }
    }
}
void TraceBack(){
    if (!L[n][S]){
        printf("Khong co day con co tong bang S!\n");
        return;
    }
    int count = 0;
    int i = n, j = S;
    while (j > 0 && i > 0){
        if (L[i][j] && !L[i - 1][j]){
            Trace[count++] = A[i]; 
            j -= A[i]; 
        }
        i--;
    }
    printf("Day con co tong bang S: ");
    for (int k = count - 1; k >= 0; k--) 
        printf("%d ", Trace[k]);
    printf("\n");
}
int main(){
    Init();
    Dynamic();
    TraceBack();
    return 0;
}

