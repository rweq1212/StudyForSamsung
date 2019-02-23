import java.util.*;
public class B14503{
	static int round = 0;
	public static void clean(int arr[][], int visited[][], int r, int c, int d) {
		boolean second = true; // 2번 조건으로 돌아간다.
		while(true) {
			if(!second)
				visited[r][c] = 1; // 조건 1.현재 위치를 청소한다.
			second = true;
			//조건 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 검색한다.
			if(second) {
				if(d == 0) {
					//북쪽일 경우
					if(round == 4) {
						if(arr[r+1][c] == 1) break; 
							// 조건 2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
						else {
							r = r+1; // 한칸 후진
							round = 0;
						} // 조건 2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
					}
					if((c-1>=0 || c-1<arr.length) && arr[r][c-1] != 1 && visited[r][c-1]==0) {
						// 청소가 가능한 경우
						d = 3;
						c = c-1;
						second = false; // 1번 조건으로 전환
						round = 0;
					} // 조건 2-1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
					else {
						d = 3;
						round++;
						// 조건 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
					}
				}
				else if(d == 1) {
					//동쪽일 경우
					if(round == 4) {
						if(arr[r][c-1] == 1) break; 
							// 조건 2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
						else {
							c = c-1; // 한칸 후진
							round = 0;
						} // 조건 2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
					}
					if((r-1>=0 || r-1<arr.length) && arr[r-1][c] != 1 && visited[r-1][c] == 0) {
						// 청소가 가능한 경우
						d = 0;
						r = r-1;
						second = false; // 1번 조건으로 전환
						round = 0;
					} // 조건 2-1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
					else {
						d = 0;
						round++;
						// 조건 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
					}
				}
				else if(d == 2) {
					//남쪽일 경우
					if(round == 4) {
						if(arr[r-1][c] == 1) break; 
							// 조건 2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
						else {
							r = r-1; // 한칸 후진
							round = 0;
						} // 조건 2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
					}
					if((c+1>=0 || c+1<arr.length) && arr[r][c+1] != 1 && visited[r][c+1]==0) {
						// 청소가 가능한 경우
						d = 1;
						c = c+1;
						second = false; // 1번 조건으로 전환
						round = 0;
					} // 조건 2-1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
					else {
						d = 1;
						round++;
						// 조건 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
					}
				}
				else if(d == 3) {
					//서쪽일 경우
					if(round == 4) {
						if(arr[r][c+1] == 1) break; 
							// 조건 2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
						else {
							c = c+1; // 한칸 후진
							round = 0;
						} // 조건 2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
					}
					if((r+1>=0 || r+1<arr.length) && arr[r+1][c] != 1 && visited[r+1][c] == 0) {
						// 청소가 가능한 경우
						d = 2;
						r = r+1;
						second = false; // 1번 조건으로 전환
						round = 0;
					} // 조건 2-1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
					else {
						d = 2;
						round++;
						// 조건 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
					}
				}
			
			}
				} // 로봇청소기의 작동조건
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt(); // 세로 크기
		int m = scn.nextInt(); // 가로 크기
		
		int r = scn.nextInt(); // 시작 x
		int c = scn.nextInt(); // 시작 y
		int d = scn.nextInt(); // 0:북   1:동  2:남  3:서
		int arr[][] = new int[n][m]; // 청소할 맵
		int visited[][] = new int[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				arr[i][j] = scn.nextInt();
			}
		} // 맵을 채움
		visited[r][c] = 1;
		clean(arr, visited, r,c, d);
		int cnt = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(visited[i][j] == 1) cnt++;
			}
		}
		System.out.println(cnt);
		
	}
}