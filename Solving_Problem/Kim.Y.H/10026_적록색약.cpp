#include<iostream>
using namespace std;

int nX[4] = { 0,1,0,-1 };
int nY[4] = { -1,0,1,0 };

void dfs(char**, bool**, int, int, int);
void dfs2(char**, bool**, int, int, int);
int main() {

	int n = 0;
	cin >> n;
	char**map = new char*[n];
	bool**visited = new bool*[n];

	for (int i = 0; i < n; i++) {
		map[i] = new char[n];
		visited[i] = new bool[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(map, visited, n, i, j);
				count++;
			}
		}
	}
	cout << count << " ";
	count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			if (map[i][j] == 'R')
				map[i][j] = 'G';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(map, visited, n, i, j);
				count++;
			}
		}
	}
	cout << count;


	delete[] map;
	delete[] visited;
	//system("pause");
	return 0;
}

void dfs(char**map, bool**visited, int n, int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (i + nY[k] < 0 || i + nY[k] >= n || j + nX[k] < 0 || j + nX[k] >= n) {
			continue;
		}
		if (map[i][j] == map[i + nY[k]][j + nX[k]] && !visited[i + nY[k]][j + nX[k]]) {
			dfs(map, visited, n, i + nY[k], j + nX[k]);
		}
	}
}
