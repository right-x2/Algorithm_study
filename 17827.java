
import java.io.IOException;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		int []arr = new int[200001];
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int v = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			int s = sc.nextInt();
			arr[i] = s;
		}
		for(int i = 0; i < m; i++) {
			int q = sc.nextInt();
			if(q>=n) {
				q = q - (v-1);
				int roop = n-(v-1);
				q = q%roop;
				q = q + (v-1);
			}
			System.out.println(arr[q]);
		}
	}
}
