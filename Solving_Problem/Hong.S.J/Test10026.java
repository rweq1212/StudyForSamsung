package test01;

import java.util.Scanner;

public class Test10026 {
	static int N, cnt1=0, cnt2=0;
	static char[][] map;
    static int[] dx = { 0, 1, 0, -1 };
    static int[] dy = { -1, 0, 1, 0 };
    static boolean[][] visited;
	static String temp;
	
	public static void dfs(int x, int y, int kind) {//kind-적록색약, 적록색약X
		visited[x][y] = true;
		int cx, cy;
		for(int i = 0; i < 4; i++) {
			cx = x + dx[i];
			cy = y + dy[i];
			
			if(cx < 0 || cy < 0 || cx >= N || cy >= N || visited[cx][cy]) {
				continue;
			}
			
			if(kind == 1) {
				if(map[x][y] == map[cx][cy]) {
					dfs(cx,cy,1);
				}
			}
			if(kind == 2) {
				if(map[x][y] == 'R' || map[x][y] == 'G') {
					if(map[cx][cy] == 'R' || map[cx][cy] == 'G') {
						dfs(cx,cy,2);
					}
				}else {
					if(map[x][y] == map[cx][cy]) {
						dfs(cx,cy,2);
					}
				}
			}
			
			
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		map = new char[N][N];
		visited = new boolean[N][N];
		
		for(int i = 0; i < N; i++) {
			temp = sc.next();
			for(int j = 0; j < N; j++) {
				map[i][j] = temp.charAt(j);
			}
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(visited[i][j] == false) {
					cnt1++;
					dfs(i,j,1);
				}
			}
		}
		
		visited = new boolean[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(visited[i][j] == false) {
					cnt2++;
					dfs(i,j,2);
				}
			}
		}
		
		System.out.println(cnt1 + " " + cnt2);
	}

}
