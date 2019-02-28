#include<iostream>
#include<queue>
using namespace std;

int nX[4] = {-1,0,1,0};
int nY[4] = {0,1,0,-1};
int n, m;

struct place {
	place() {}
	place(int inX, int inY, int inD) {
		x = inX;
		y = inY;
		direction = inD;
	}
	int x;
	int y;
	int direction;
};

void clean(int**,int,int,int);

int main() {
	int **map;
	n = 0, m = 0;
	int r = 0, c = 0, d = 0;
	cin >> n >> m;
	cin >> r >> c >> d;
	map = new int*[n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	clean(map, r, c, d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<< map[i][j]<<" ";
		}
		cout << endl;
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2)
				cnt++;
		}
	}

	cout << cnt;
	delete[] map;
	system("pause");
	return 0;
}

void clean(int**map,int r,int c, int d) {
	queue<place> q;
	map[r][c] = 2;
	q.push(place(r,c,d));
	while (!q.empty()) {
		int now_x = q.front().x;
		int now_y = q.front().y;
		int now_d = q.front().direction;
		q.pop();
		bool check = false;
		int next_x;
		int next_y;
		int next_d;
		for (int i = 0; i < 4; i++) {
			now_d = (now_d + 3) % 4;
			next_x = now_x + nX[now_d];
			next_y = now_y + nY[now_d];
			if (next_x < 0 || next_x >= n || next_y<0 || next_y >= m) {
				continue;
			}
			if (map[next_x][next_y] == 0) {
				q.push(place(next_x,next_y,now_d));
				map[next_x][next_y] = 2;
				check = true;
				break;
			}
		}
		if (!check) {
			next_d = (now_d + 2) % 4;
			next_x = now_x + nX[next_d];
			next_y = now_y + nY[next_d];

			if (map[next_x][next_y] != 1) {
				map[next_x][next_y] = 2;
				q.push(place(next_x,next_y,now_d));
			}
		}
	}
}