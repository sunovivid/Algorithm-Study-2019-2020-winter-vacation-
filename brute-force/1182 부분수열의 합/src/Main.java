import java.util.Scanner;

import static java.lang.Math.pow;

public class Main {
    public static void main(String[] args) {
        ////////////////////input/////////////////////
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), s = input.nextInt();
        int[] arr = new int[n];
        for (int i=0;i<n;i++)
            arr[i] = input.nextInt();

        ///////////////////calculate//////////////////////
        int count = 0;
        int c= 3;
        c++;
        for (int i=0;i<pow(2,n);i++) {
            int sum = 0;
            int digitNow = 0;
            boolean hasNumberToAdd = false;
            int k = i;
            while (k > 0) {
                if (k%2 == 1) {
                    hasNumberToAdd = true;
                    sum += arr[digitNow];
                }
                k /= 2;
                digitNow++;
            }
            if (sum == s && !(s == 0 && !hasNumberToAdd))
                count++;
        }
        ////////////////////output/////////////////////
        System.out.print(count);
    }
}
