package problems;

/**
 * User: chengcheng.liu
 * Date: 16/11/11
 */
public class Q171ESCN {
    public static void main(String[] args) {
        char a = 'Z';
        System.out.println(a-64);
        System.out.println(titleToNumber("AB"));
    }

    public static int titleToNumber(String s) {
        int weight = 1;
        int result = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            char curChar = s.charAt(i);
            if (curChar < 'A' || curChar > 'Z') {
                return -1;
            }
            result = result + (curChar - 64) * weight;
            weight = weight * 26;
        }
        return result;
    }
}
