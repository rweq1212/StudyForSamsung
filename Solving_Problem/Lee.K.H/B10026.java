import java.util.*;
public class Main {
	static int cnt = 0;
	public static void dfs(char arr[][], boolean visited[][], int a, int b, char color) {
		Stack<int[]> s = new Stack<>();
		int start[] = {a,b}; // y, x
		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,-1,1};
		// 상하좌우 탐색을 위한
		s.push(start);
		while(!s.isEmpty()) {
			int now[] = s.pop();
			int y = now[0];
			int x = now[1];
			for(int i=0; i<4; i++) {
				int ny = y+dy[i];
				int nx = x+dx[i];
				if(ny<0 || ny>arr.length-1 || nx<0 || nx>arr.length-1) continue;
				if(arr[ny][nx]==color && !visited[ny][nx]) { // 같은 색깔의 구역을 형성
					int pair[] = {ny, nx};
					s.push(pair);
					visited[ny][nx] = true;
				}
			}
		}
		
	} // 구역 탐색

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int n = Integer.parseInt(scn.nextLine());
		char arr[][] = new char[n][n];
		boolean normal[][] = new boolean[n][n];
		boolean redgreen[][] = new boolean[n][n];
		//scn.nextLine();
		for(int i=0; i<n; i++) {
			String str = scn.next();
			for(int j=0; j<n; j++) {
				arr[i][j] = str.charAt(j);
			}
		} // 입력부
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!normal[i][j]) {
					normal[i][j] = true;
					dfs(arr, normal, i, j, arr[i][j]);
					cnt++;
				}
			}
		}
		System.out.print(cnt+" "); 
		// 정상인의 색 구분

		cnt = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(arr[i][j] == 'G') arr[i][j] = 'R';
			}
		} // 적록색약은 적색과 녹색을 같게 보기에 녹색을 적색으로 변경

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!redgreen[i][j]) {
					redgreen[i][j] = true;
					dfs(arr, redgreen, i, j, arr[i][j]);
					cnt++;
				}
			}
		}
		System.out.print(cnt);
		// 적록색약을 갖고 있는 사람의 색 구분
	}

}