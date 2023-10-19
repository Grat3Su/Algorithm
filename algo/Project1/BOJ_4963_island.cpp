#include <iostream>
#include <conio.h>

using namespace std;

int W, H;

int dx[] = { 1,-1,0,0, 1, -1, -1,  1};
int dy[] = { 0,0,1,-1, 1, -1 , 1, -1};

int map[50][50];
bool visit[50][50];

void reset() {
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			visit[i][j] = false;
		}
	}
}

void makeIsland(int x, int y, int cnt) {
	map[x][y] = cnt;
	visit[x][y] = true;

	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx >= W || nx < 0 || ny >= H || ny < 0 || visit[nx][ny]||map[nx][ny]==0) continue;

		makeIsland(nx, ny, cnt);
	}
}

int island() {

	while (1) {
		cin >> W >> H;

		if (W == 0 && H == 0)	break;

		reset();
		for (int j = 0; j < H; j++) {
		for (int i = 0; i < W; i++) {
				int island;
				cin >> island;
				map[i][j] = island;
			}
		}

		int cnt = 1;

		for (int i = 0; i < W; i++) {
			for (int j = 0; j < H; j++) {
				if (visit[i][j] || map[i][j] == 0)	continue;
				
				makeIsland(i, j, cnt);
				cnt++;
			}
		}

			cout << cnt-1 << "\n";
	}

	return 0;
}