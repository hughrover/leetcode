package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/20
 */
public class Q28ImplementStrStr {
    public static void main(String[] args) {
        String s1 = "abcdefgef";
        String s2 = "cde";
        System.out.println(strStr(s1, s2));
    }

    public static int strStr(String haystack, String needle) {
        int hl = haystack.length();
        int nl = needle.length();
        if (nl == 0) {
            return 0;
        }
        char first = needle.charAt(0);
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.charAt(i) == first) {
                int j = i;
                int k = 0;

                while (j < hl && k < nl) {
                    if (haystack.charAt(j) == needle.charAt(k)) {
                        j++; k++;
                    } else {
                        break;
                    }
                }
                if (k == nl) {
                    return i;
                }
            }
        }
        return -1;
    }
}
