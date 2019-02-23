/* 14503��: �κ� û�ұ� (https://www.acmicpc.net/problem/14503) */

#include <cstdio>
using namespace std;

bool map[50][50], check[50][50];
int dx[4] = { -1, 0, 1, 0 };	// ��, ��, ��, ��
int dy[4] = { 0, 1, 0, -1 };	// ��, ��, ��, ��
int N, M, ans = 0;


void go(int x, int y, int d) {
	if (!check[x][y]) {	// û������ ���� ���
		check[x][y] = true;	// û��
		ans++;	// û���� ĭ �� ����
	}

	int nx, ny, nd = d;
	for (int i = 0; i < 4; i++) {
		nd == 0 ? nd = 3 : nd--;	// �������� ȸ��
		nx = x + dx[nd], ny = y + dy[nd];	// ȸ��
		if (!map[nx][ny] && !check[nx][ny]) {	// ���� ���� û������ ���� ���
			go(nx, ny, nd);	// �ش� ��ġ�� �̵�
			return;
		}
	}
	nd = (d + 2) % 4;	// ���� ������ �ݴ� ����
	nx = x + dx[nd], ny = y + dy[nd];	// ���� ��ġ�� �� ĭ
	if (!map[nx][ny])	// �ڿ� ���� ������
		go(nx, ny, d);	// �� ĭ �ڷ� �̵�, ������ ����
}

int main(void) {
	int r, c, d;
	// �Էº�
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	
	// ó����
	go(r, c, d);

	// ��º�
	printf("%d\n", ans);
	return 0;
}