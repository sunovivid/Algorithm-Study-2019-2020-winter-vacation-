import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[][] arr = new int[n][n];
        for (int i=0;i<n;i++) {
            String s = input.next();
            for (int j=0;j<n;j++) {
                switch (s.charAt(j)) {
                    case 'C':
                        arr[i][j] = 0;
                        break;
                    case 'P':
                        arr[i][j] = 1;
                        break;
                    case 'Z':
                        arr[i][j] = 2;
                        break;
                    case 'Y':
                        arr[i][j] = 3;
                        break;
                    default:
                        throw new InputMismatchException();
                }
            }
        }

        int maxCount = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                maxCount = getMaxCountAt(i,j,arr,n,maxCount);
            }
        }

        for (int i=0;i<n-1;i++) {
            for (int j=0;j<n;j++) {
                int temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;

                maxCount = getMaxCountAt(i,j,arr,n,maxCount);
                maxCount = getMaxCountAt(i+1,j,arr,n,maxCount);

                temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
            }
        }

        for (int i=0;i<n;i++) {
            for (int j = 0; j < n-1; j++) {
                int temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;

                maxCount = getMaxCountAt(i,j,arr,n,maxCount);
                maxCount = getMaxCountAt(i,j+1,arr,n,maxCount);

                temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
            }
        }

        System.out.println(maxCount);
    }

    private static int getMaxCountAt(int i, int j, int[][] arr, int n, int maxCount) {
        int upCount, downCount;

        for (upCount=1; j+upCount<n && arr[i][j+upCount] == arr[i][j]; upCount++);
        for (downCount=1; j-downCount>=0 && arr[i][j-downCount] == arr[i][j]; downCount++);
        if (upCount + downCount - 1> maxCount)   maxCount = upCount + downCount - 1;

        for (upCount=1; i+upCount<n && arr[i+upCount][j] == arr[i][j]; upCount++);
        for (downCount=1; i-downCount>=0 && arr[i-downCount][j] == arr[i][j]; downCount++);
        if (upCount + downCount - 1 > maxCount)   maxCount = upCount + downCount - 1;
        return maxCount;
    }
}
