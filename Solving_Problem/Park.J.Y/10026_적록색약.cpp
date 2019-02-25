#include <cstdio>
#include <cstring>
using namespace std;

int N;
int mat[102][102];
int visit[102][102];
int dX[4] = { -1, 1, 0, 0 };
int dY[4] = { 0, 0, -1, 1 };
int ans1 = 0;
int ans2 = 0;
int dfs2(int x, int y, int num)
{
	int nX, nY;
	for (int i = 0; i < 4; i++)
	{
		nX = x + dX[i]; nY = y + dY[i];
		if (nX >= 1 && nX <= N && nY >= 1 && nY <= N)
		{
			if (visit[nX][nY] == 0)
			{
				if (num == 1 && mat[nX][nY] == 1 || num == 1 && mat[nX][nY] == 2)
				{
					visit[nX][nY] = 1;
					dfs2(nX, nY, num);
				}
				if (num == 2 && mat[nX][nY] == 1 || num == 2 && mat[nX][nY] == 2)
				{
					visit[nX][nY] = 1;
					dfs2(nX, nY, num);
				}
				if (num == 3 && mat[nX][nY] == 3)
				{
					visit[nX][nY] = 1;
					dfs2(nX, nY, num);
				}
				
			}
		}
	}

	return 0;
}
int dfs(int x, int y, int num)
{
	int nX, nY;
	for (int i = 0; i < 4; i++)
	{
		nX = x + dX[i]; nY = y + dY[i];
		if (nX >= 1 && nX <= N && nY >= 1 && nY <= N)
		{
			if (visit[nX][nY] == 0 && mat[nX][nY] == num)
			{
				visit[nX][nY] = 1;
				dfs(nX, nY, num);
			}
		}
	}

	return 0;
}
int main()
{
	scanf("%d", &N);
	memset(visit, 0, sizeof(visit));
	char temp[102][102];
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", temp[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] == 'R') mat[i][j+1] = 1;
			if (temp[i][j] == 'G') mat[i][j+1] = 2;
			if (temp[i][j] == 'B') mat[i][j+1] = 3;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 0)
			{
				ans1++;
				dfs(i, j, mat[i][j]);
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 0)
			{
				ans2++;
				dfs2(i, j, mat[i][j]);
			}
		}
	}
	
	printf("%d %d\n", ans1, ans2);
	scanf("%d",&N);
	return 0;
}