#include<iostream>
#include<queue>
using namespace std;
int M, N, H, t_cnt;
int arr[100][100][100];
bool visited[100][100][100];
int nH[6] = { 1,-1,0,0,0,0 };
int nX[6] = { 0,0,0,1,0,-1 };
int nY[6] = { 0,0,-1,0,1,0 };
struct place {
	place(int inh,int iny,int inx) {
		h = inh;
		y = iny;
		x = inx;
	}
	int h;
	int y;
	int x;

};
queue<place> q;
int grow();

int main() {
	t_cnt = 0;
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[k][i][j];
				visited[k][i][j] = false;
				if (arr[k][i][j] == 0) {
					t_cnt++;
				}
				else if (arr[k][i][j] == 1) {
					q.push(place(k,i,j));
				}
			}
		}
	}
	if (t_cnt == 0) {
		cout << 0;
	}
	else
		cout<<grow();

	return 0;
}

int grow() {
	int cen = 1;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int now_h = q.front().h;
			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();
			
			if (visited[now_h][now_y][now_x]) {
				continue;
			}

			visited[now_h][now_y][now_x] = true;

			for (int j = 0; j < 6; j++) {
				int next_h = now_h + nH[j];
				int next_y = now_y + nY[j];
				int next_x = now_x + nX[j];

				if (next_h < 0 || next_y < 0 || next_x < 0 || next_h >= H || next_y >= N || next_x >= M) {
					continue;
				}

				if (arr[next_h][next_y][next_x] == 0) {
					q.push(place(next_h, next_y, next_x));
					arr[next_h][next_y][next_x] = 1;
					t_cnt--;
				}
				if (t_cnt == 0) {
					return cen;
				}
			}
		}
		cen++;
	}
	return -1;
}