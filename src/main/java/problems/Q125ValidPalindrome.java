package problems;

/**
 * User: chengcheng.liu
 * Date: 16/10/13
 */
public class Q125ValidPalindrome {
    public static void main(String[] args) {
        String test = "race a car";
        System.out.println(isPalindrome(test));
    }

    public static boolean isPalindrome(String s) {
        if (s.length() == 0)
            return false;

        boolean flag = true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            int left = s.charAt(i);
            int right = s.charAt(j);
            if (isLetter(left) && isLetter(right)) {
                left = left < 97 ? left : (left - 32);
                right = right < 97 ? right : (right - 32);
                if (left == right) {
                    i++;
                    j--;
                } else {
                    flag = false;
                    break;
                }
            } else {
                if (!isLetter(left)) {
                    i++;
                }
                if (!isLetter(right)) {
                    j--;
                }
            }
        }

        return flag;
    }

    public static boolean isLetter(int c) {
        return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57);
    }
}
