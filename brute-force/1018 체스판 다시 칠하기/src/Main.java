import java.util.Scanner;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) {
        //////////////////////input////////////////////////
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        boolean[][] board = new boolean[n][m];
        for (int i=0;i<n;i++) {
            String s = input.next();
            for (int j=0;j<m;j++)
                board[i][j] = (s.charAt(j) == 'W'); //false for B, true for W
        }
        //////////////////////calculate////////////////////////
        int minNumOfTilesToColor = 987654321;
        for (int i=0;i<=n-8;i++)
            for (int j=0;j<=m-8;j++)
                minNumOfTilesToColor = min(minNumOfTilesToColor,getNumOfTilesToColorStartAt(i,j,board));
        ////////////////////output//////////////////////////
        System.out.print(minNumOfTilesToColor);
    }

    private static int getNumOfTilesToColorStartAt(int i, int j, boolean[][] board) {
        int count = 0;
        for (int a=i;a<i+8;a++)
            for (int b=j;b<j+8;b++)
                if (board[a][b] != ((a % 2 == 0) ^ (b % 2 == 0))) //잘한부분!
                    count++;
        return min(count,64-count);
    }
}
