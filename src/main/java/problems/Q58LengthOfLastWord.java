package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/21
 */
public class Q58LengthOfLastWord {
    public static void main(String[] args) {
        String tmp = "hello world";
        System.out.println(lengthOfLastWord(tmp));
    }

    public static int lengthOfLastWord(String s) {
        int length = 0;

        s = s.trim();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                length = 0;
            } else {
                length++;
            }
        }

        return length;
    }
}
