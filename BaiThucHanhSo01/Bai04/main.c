#include <stdio.h>
#include <math.h>

int laSoNguyenTo(int n) {
    if (n < 2) {
        return 0; 
    }
    int gh = (int)sqrt(n);
    for (int i = 2; i <= gh; i++) {
        if (n % i == 0) {
            return 0; 
        }
    }
    
    return 1; 

int main() {
    int n;

    printf("Nhap mot so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap mot so nguyen duong (> 0)!\n");
        return 1;
    }

    if (laSoNguyenTo(n)) {
        printf("%d la so nguyen to.\n", n);
    } else {
        printf("%d khong phai la so nguyen to.\n", n);
    }

    return 0;
}
