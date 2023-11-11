#include <iostream>
#include<queue>
#include<conio.h>

using namespace std;
#define MAX_VALUE	1001
	int N, M, V;
	int node[MAX_VALUE][MAX_VALUE];
	bool visit[MAX_VALUE];

	void dfs(int idx) {
		visit[idx] = true;
			cout << idx << " ";
		for (int i = 1; i <= N; i++) {
			if (!visit[i]&&node[idx][i]==1)//방문했거나 연결되어있지 않으면 continue
			dfs(i);
		}
	}

	void bfs(int idx) {
		queue<int>q;
		q.push(idx);
		visit[idx] = true;
		cout << idx << " ";
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 1; i <= N; i++) {
				if (!visit[i] && node[cur][i] == 1){				
				cout << i << " ";
				q.push(i);
				visit[i] = true;
				}
			}
		}
	}

int main() {
	cin >> N >> M >> V;


	for (int i = 0; i < M; i++) {
		int to;
		int from;

		cin >> to >> from;
		node[to][from] = 1;
		node[from][to] = 1;
	}
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
	dfs(V);
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
	bfs(V);
	return 0;
}