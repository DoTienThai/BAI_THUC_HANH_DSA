#include <stdio.h>
#include <stdlib.h>
void nhap(float*a , int h,int c){
    int csh,csc;
    for(csh=0;csh<h;csh++){
        for(csc=0;csc<c;csc++){
            printf("Nhap a[%d][%d] ",csh,csc);
            scanf("%f",a+csh*c+csc);
        }
    }
}
void in(float*a,int h,int c){
    int i,j;
    for(int i=0;i<h;i++){
        for(int j=0;j<c;j++){
            printf("%.2f  ",*(a+i*c+j));
        }
        printf("\n");
    }
}

int main() {
  int h,c;
  printf("Nhap so hang va cot: ");
  scanf("%d %d",&h,&c);
  float *a = (float*)calloc(h*c,sizeof(float));
  nhap(a,h,c);
  printf("ma tran vua nhap la:\n");
  in(a,h,c);
  free(a);
}
