#include<stdio.h>
#include<string.h>

int x, y, q;
int p;
int n, m;
int vis[111] = { 0 }, dis[111];
int a[111][111];

void prim() {
	int temp = 111, c = 1;
	vis[1] = 1;
	printf("%d ", 1);
	for (int i = 2; i <= n; i++) {
		dis[i] = a[1][i];
		if (dis[i] < temp) {
			temp = dis[i];
			p = i;
		}
	}
	vis[p] = 1;
	dis[p] = 111;
	c++;
	printf("%d ", p);
	while (c < n) {
		temp = 111;
		for (int i = 2; i <= n; i++) {
			if (dis[i] > a[p][i] && vis[i] == 0) {
				dis[i] = a[p][i];
			}
		}
		for (int j = 2; j <= n; j++) {
			if (dis[j] < temp) {
				temp = dis[j];
				p = j;
			}
		}
		vis[p] = 1;
		dis[p] = 111;
		c++;
		printf("%d ", p);
	}
}

int main() {
	for (int i = 1; i <= 111; i++) {
		dis[i]=111;
		for (int j = 1; j <= 111; j++) {
			a[i][j] = 111;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &q);
		a[x][y] = a[y][x] = q;
	}
	prim();
	return 0;
}