import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        //배열 길이
		int N = sc.nextInt();
		int roof = sc.nextInt();
		int[][] arr = new int[N+1][N+1];
		
		for(int i = 1; i<N+1; i++)
		{
			for(int j = 1; j<N+1; j++)
			{			
				arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1]+sc.nextInt();					
			}
			//System.out.println(Arrays.toString(arr[i]));
		}
		
		for(int i = 0; i<roof; i++)
		{
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			
			//전체 - x축 - y축 + 대각선
			int result = arr[x2][y2] - arr[x1-1][y2] -arr[x2][y1-1]+arr[x1-1][y1-1];

			System.out.println(result);
		}	
	}
}
