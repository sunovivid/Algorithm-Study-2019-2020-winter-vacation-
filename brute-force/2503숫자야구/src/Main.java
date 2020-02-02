import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        final int MAX = 1000;
        final int DIGITS = 3;

        boolean[] isPossibleNumber = new boolean[MAX];
        for (int i=MAX/10;i<MAX;i++) {
            String s = (i + "");
            isPossibleNumber[i] = !s.contains("0") && s.charAt(0) != s.charAt(1) && s.charAt(0) != s.charAt(2) && s.charAt(1) != s.charAt(2);
        }
        //before simplifying if-else statements
//        for (int i=MAX/10;i<MAX;i++) {
//            String s = (i+"");
//            if (s.contains("0"))
//                isPossibleNumber[i] = false;
//            else if (s.charAt(0)==s.charAt(1) || s.charAt(0)==s.charAt(2) || s.charAt(1)==s.charAt(2)) //this part should be modified when you change MAX and DIGIT
//                isPossibleNumber[i] = false;
//            else
//                isPossibleNumber[i] = true;
//        }
        for (int line=0;line<n;line++) {
            int k = input.nextInt();
            int strike = input.nextInt();
            int ball = input.nextInt();
            for (int i=MAX/10;i<MAX;i++) {
                if (!isPossibleNumber[i])
                    continue;
                int strikeCount = 0, ballCount = 0;
                String si = i + "";
                String sk = k + "";
                for (int j=0;j<DIGITS;j++) {
                    if (si.charAt(j) == sk.charAt(j))
                        strikeCount++;
                    else if (si.contains(sk.charAt(j)+""))
                        ballCount++;
                }
                if (!(strikeCount == strike && ballCount == ball))
                    isPossibleNumber[i] = false;
            }
        }

        int possibleNumbers = 0;
        for (int i=MAX/10;i<MAX;i++) {
            if (isPossibleNumber[i])
                possibleNumbers++;
        }
        System.out.println(possibleNumbers);
    }

//    public static int to9BaseNum(int n) {
//        int result = 0;
//        String s = n + "";
//        for (int i=0;i<s.length();i++) {
//            result += (s.charAt(i) - '0');
//            result *= 9;
//        }
//        return result;
//    }
//
//    public static int to10BaseNum(int n) {
//
//    }
}
