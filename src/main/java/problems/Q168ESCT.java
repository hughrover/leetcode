package problems;

/**
 * User: chengcheng.liu
 * Date: 16/10/27
 */
public class Q168ESCT {
    public static void main(String[] args) {
        System.out.println(convertToTitle(27*26));
    }

    public static String convertToTitle(int n) {
        String result = "";
        while (n > 0) {
            int cur = n % 26;
            if (cur == 0) {
                result = 'Z' + result;
                n = n - 26;
            } else {
                result = (char) (64 + cur) + result;
            }
            n = n / 26;
        }
        return result;
    }
}
