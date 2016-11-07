package problems;

import java.util.HashMap;
import java.util.Map;

/**
 * User: chengcheng.liu
 * Date: 16/9/10
 */
public class Q3LSWRC {
    public static void main(String[] args) {
        String  test = "abba";
        System.out.println(lengthOfLongestSubstring(test));
    }

    public static int lengthOfLongestSubstring(String s) {
        // hash map can be replaced with int array
        Map<Character, Integer> chaIndexMap = new HashMap<Character, Integer>();

        if (s.length() > 0) {
            String curMaxStr = "";
            int end = 0, start = 0;
            chaIndexMap.put(s.charAt(start), start);

            while (++end <= s.length() - 1) {
                Character curChar = s.charAt(end);
                if (chaIndexMap.containsKey(curChar) && chaIndexMap.get(curChar) >= start) {
                    // get the new string is redundant, direct compare the index diff
                    String newStr = s.substring(start, end);
                    if (newStr.length() > curMaxStr.length()) {
                        curMaxStr = newStr;
                    }
                    start = chaIndexMap.get(curChar) + 1;
                }
                chaIndexMap.put(curChar, end);
            }

            String finalStr = s.substring(start, end);
            curMaxStr = finalStr.length() > curMaxStr.length() ? finalStr : curMaxStr;
            return  curMaxStr.length();
        }
        return 0;
    }

    public static int lengthOfLongestSubstring_Answer(String s) {
        int n = s.length(), ans = 0;
        int[] index = new int[128]; // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            i = Math.max(index[s.charAt(j)], i);
            ans = Math.max(ans, j - i + 1);
            index[s.charAt(j)] = j + 1;
        }
        return ans;
    }
}
