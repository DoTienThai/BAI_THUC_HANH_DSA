#include "stdio.h"
#include "stdlib.h"
void nhap(float *a,int n){
    int i;
    for(int i=0;i<n;i++){
        printf("Nhap ptu thu %d: ",i);
        scanf("%f",&a[i]);
    }
}
void in(float *a,int n){
    int i;
    for(int i=0;i<n;i++){
        printf("Phan tu thu %d la %.2f\n",i,a[i]);
    }
}
int main(){
   float *p;
   int n;
   printf("Nhap so luong cac phan tu: ");
   scanf("%d",&n);
   p = (float*)calloc(n,sizeof(float));
   nhap(p,n);
   printf("\nDu lieu ban dau: \n");
   in(p,n);
   free(p);
}

