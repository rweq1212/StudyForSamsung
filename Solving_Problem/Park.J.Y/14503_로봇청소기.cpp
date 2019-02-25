#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int mat[52][52];
int visit[52][52];
int Vx, Vy, Vd;
int dX[4] = { -1, 0, 1, 0 };
int dY[4] = { 0, 1, 0, -1, };
int cnt;
struct Vc
{
	int x, y, d;
};
queue <Vc> q;
int nextD(int curr)
{
	return (curr + 3) % 4;
}
void Init()
{
	memset(visit,0,sizeof(visit));
	cnt = 0;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &Vx, &Vy, &Vd);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
}
int main()
{
	Init();
	
	visit[Vx][Vy] = 1;
	cnt++;
	q.push({ Vx, Vy, Vd });
	while (!q.empty())
	{
		Vc curr = q.front(); q.pop();
		int nX = 0, nY = 0, nD = curr.d;
		int x = curr.x; int y = curr.y;
		bool turn = false;
		for (int i = 0; i < 4; i++)
		{
			nD = nextD(nD);
			nX = x + dX[nD];
			nY = y + dY[nD];
			if (nX >= 0 && nX < N && nY >= 0 && nY < M)
			{
				if (visit[nX][nY] == 0 && mat[nX][nY] == 0)
				{
					visit[nX][nY] = 1;
					cnt++;
					q.push({ nX, nY, nD });
					turn = true;
					break;
				}
			}
		}
		if (turn == false)
		{
			nX = x + dX[(curr.d + 2) % 4];
			nY = y + dY[(curr.d + 2) % 4];
			if (nX >= 0 && nX < N && nY >= 0 && nY < M)
			{
				if (mat[nX][nY] == 0)
				{
					q.push({ nX, nY, curr.d });
				}
			}
		}
	}
	printf("%d\n",cnt);
	scanf("%d",&N);
	return 0;
}