package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/21
 */
public class Q38CountAndSay {
    public static void main(String[] args) {
        int n = 123455677;
        countAndSay(n);
    }

    static String countAndSayForOneString(String input) {
        char tmp = input.charAt(0);
        int  num = 1;
        StringBuffer newString = new StringBuffer("");
        for(int k = 1;k < input.length(); k++) {
            if(input.charAt(k) == tmp) {
                num++;
                continue;
            }
            newString.append(Integer.toString(num) + tmp);
            tmp = input.charAt(k);
            num = 1;
        }
        newString.append(Integer.toString(num) + tmp);
        return newString.toString();
    }

    public static String countAndSay(int n) {
        String result = "1";
        int i = 1;
        while (i < n) {
            result = countAndSayForOneString(result);
            i++;
        }
        return result;
    }
}
