package problems;

/**
 * User: chengcheng.liu
 * Date: 16/10/27
 */
public class Q165CVN {
    public static void main(String[] args) {
        String s1 = "1";
        String s2 = "1";
        System.out.println(compareVersion(s1, s2));
    }

    public static int compareVersion(String version1, String version2) {
        String[] n1 = version1.split("\\.");
        String[] n2 = version2.split("\\.");

        int len = n1.length <= n2.length ? n1.length - 1 : n2.length - 1;
        for (int i = 0; i <= len; i++) {
            int curV1 = Integer.parseInt(n1[i]);
            int curV2 = Integer.parseInt(n2[i]);
            if (curV1 != curV2) {
                return curV1 > curV2 ? 1 : -1;
            }
        }
        if (n1.length == n2.length) {
            return 0;
        } else if (n1.length < n2.length) {
            for (int i = n1.length; i < n2.length; i++) {
                if (Integer.parseInt(n2[i]) > 0) {
                    return -1;
                }
            }
        } else {
            for (int i = n2.length; i < n1.length; i++) {
                if (Integer.parseInt(n1[i]) > 0) {
                    return 1;
                }
            }
        }

        return 0;
    }
}
