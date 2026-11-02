#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu phai lon hon 0\n");
        return 1;
    }

    int a[n];

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }


    int max = a[0];


    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    // In ket qua
    printf("So lon nhat trong mang la: %d\n", max);

    return 0;
}