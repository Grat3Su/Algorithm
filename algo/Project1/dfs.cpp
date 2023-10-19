#include<iostream>
using namespace std;

int map[3][3];
bool visit[3][3];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void dfs(int x, int y) {
	visit[x][y] = true;
	
	cout << map[x][y]<<" -> ";

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx >= 3 || nx < 0 || ny >= 3 || ny < 0 || visit[nx][ny]) continue;
		dfs(nx, ny);
	}
}

void main() {
	int cnt = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[i][j] = cnt;
			cout << cnt << " ";
			cnt++;
		}
		cout << "\n";
	}

	dfs(0, 0);	


	int a, b;
	cin >> a >> b;
	int newArr[a][b];
}