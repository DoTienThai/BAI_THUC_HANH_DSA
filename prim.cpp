#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int visited[MAX];

int main() {

    int n, m;
    int start;

    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Nhap cac canh (u v w):\n");

    for (int i = 0; i < m; i++) {

        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    visited[start] = 1;

    int totalWeight = 0;

    printf("\nCay khung nho nhat:\n");

    for (int k = 1; k <= n - 1; k++) {

        int min = INF;
        int u = -1;
        int v = -1;

        for (int i = 1; i <= n; i++) {

            if (visited[i]) {

                for (int j = 1; j <= n; j++) {

                    if (!visited[j] &&
                        graph[i][j] < min) {

                        min = graph[i][j];

                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {

            printf("%d - %d : %d\n", u, v, min);

            totalWeight += min;

            visited[v] = 1;
        }
    }

    printf("Tong trong so = %d\n", totalWeight);

    return 0;
}
