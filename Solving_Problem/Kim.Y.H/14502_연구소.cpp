#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, result;
int**tempA;
bool**tempB;
vector<int>v;
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void findWall(int**,bool**,int);
void virus(int**,bool**);
void safe(int**);

int main() {
	result = 0;
	cin >> N >> M;
	int **arr = new int*[N];
	tempA = new int*[N];
	bool **visited = new bool*[N];
	tempB = new bool*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		tempA[i] = new int[M];
		visited[i] = new bool[M];
		tempB[i] = new bool[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2 || arr[i][j] == 1)
				visited[i][j] = true;
			else
				visited[i][j] = false;
		}
	}
	findWall(arr,visited,0);
	delete[] arr;
	delete[] visited;
	delete[] tempA;
	delete[] tempB;
	cout << result;
	system("pause");
	return 0;
}

void findWall(int **arr,bool**visited,int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}
		virus(arr,visited);
		return;
	}
	//º® Ã£±â
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j] == 0) {
				arr[i][j] = 1;
				visited[i][j] = true;

				findWall(arr, visited, cnt + 1);

				arr[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}
	
}

void virus(int**arr,bool**visited) {
	tempA = arr;
	tempB = visited;
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		tempA[i][j] = arr[i][j];
	//		tempB[i][j] = visited[i][j];
	//		//cout << tempA[i][j] << " ";
	//	}
	//	//cout << endl;
	//}
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];

			if (nexty<0 || nexty>=N)
				continue;

			if (nextx<0 || nextx>=M)
				continue;

			if (!tempB[nexty][nextx] && tempB[nexty][nextx] == 0) {
				tempB[nexty][nextx] = true;
				tempA[nexty][nextx] = 2;
				q.push(make_pair(nexty,nextx));
			}
		}
	}
	safe(tempA);
}

void safe(int**tempA) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempA[i][j] == 0) {
				cnt++;
			}
		}
	}
	if (result < cnt)
		result = cnt;
}