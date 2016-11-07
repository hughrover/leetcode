package problems;

import java.util.Arrays;

/**
 * User: chengcheng.liu
 * Date: 16/9/14
 */
public class Q14LongestCommonPrefix {
    public static void main(String[] args) {
        String[] strings = new String[]{"123456", "123789", "1234666"};
        System.out.println(longestCommonPrefix(strings));
    }

    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        if (strs.length == 1)
            return strs[0];
        if (strs.length == 2) {
            int index = 0;
            while (index < strs[0].length() && index < strs[1].length()) {
                if (strs[0].charAt(index) == strs[1].charAt(index)) {
                    index++;
                } else {
                    break;
                }
            }
            return strs[0].substring(0, index);
        }

        int middle = strs.length / 2;

        String common1 = longestCommonPrefix(Arrays.copyOfRange(strs, 0, middle));
        String common2 = longestCommonPrefix(Arrays.copyOfRange(strs, middle, strs.length));
        return longestCommonPrefix(new String[]{common1, common2});
    }
}
