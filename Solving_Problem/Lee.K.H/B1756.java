package test;
import java.util.*;
public class B1756 {
	//static boolean check[] = new boolean[26];
	static String mo[] = {"a", "e", "i", "o", "u"};
	static int cntmo = 0;
	static int cntja = 0;
	public static boolean checking(String str) {
		boolean result = false;
		for(int j=0; j<mo.length; j++) {
			if(str.equals(mo[j])) {
				result = true; 
			}
		}
		return result;
	}
	public static void printPassword(String arr[], String output[], boolean visited[], int c, int depth, int tmp) {
		if(depth == c) {
			// 모음 1개이상 , 자음 2개이상 인지 체크하기
			for(int i=0; i<c; i++) {
				if(checking(output[i])) {
					cntmo++;
				}
				else {
					cntja++;
				}
			}
			
			if(cntmo>=1 && cntja>=2) {
				for(int i=0; i<c; i++) {
					System.out.print(output[i]);
				}
				System.out.println();
			}
			cntmo = 0;
			cntja = 0;
			return;
			// 탈출 조건
		}
		
		for(int i=tmp; i<visited.length; i++) {
			
				output[depth] = arr[i];
				tmp++;
				printPassword(arr, output, visited, c, depth+1, tmp);
				
			
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int c = scn.nextInt();
		int l = scn.nextInt();
		String arr [] = new String[l];
		String output[] = new String[c];
		boolean visited[] = new boolean[l];
		//boolean check[] = new boolean[l];
		scn.nextLine();
		for(int i=0; i<l; i++) {
			arr[i] = scn.next();
		}
		
		Arrays.sort(arr);
		printPassword(arr, output, visited, c, 0, 0);
	}

}
