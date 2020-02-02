import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        final int MAXINDEX = 45; //triangleNum[43] = 990;, triangleNum[44] = 1035;
        int[] triangleNum = new int[MAXINDEX];
        triangleNum[0] = 1;
        for (int i=1;i<MAXINDEX;i++) {
            triangleNum[i] = triangleNum[i-1] + (i+1);
        }

        for (int line=0;line<n;line++) {
            int k = input.nextInt();
            boolean isTripleSum = false;
            outLoop:
            for (int a=0;a<MAXINDEX;a++) {
                if (triangleNum[a] > k) break;
                for (int b=0;b<MAXINDEX;b++) {
                    if (triangleNum[b] > k) break;
                    for (int c=0;c<MAXINDEX;c++) {
                        int sum = triangleNum[a] + triangleNum[b] + triangleNum[c];
                        if (sum == k) {
                            isTripleSum = true;
                            break outLoop;
                        }
                        else if (sum > k) break;
                    }
                }
            }
            if (isTripleSum)
                System.out.println(1);
            else
                System.out.println(0);
        }
    }
}
