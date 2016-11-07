package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/22
 */
public class Q67AddBinary {
    public static void main(String[] args) {
        String a = "1";
        String b = "0";
        System.out.println(addBinary(a, b));
    }

    public static String addBinary(String a, String b) {
        int lenA = a.length() - 1;
        int lenB = b.length() - 1;

        int carry = 0;
        String result = "";
        while (lenA >= 0 || lenB >= 0) {
            int one = lenA >= 0 ? a.charAt(lenA--) - 48 : 0;
            int two = lenB >= 0 ? b.charAt(lenB--) - 48 : 0;
            int curValue = one + two + carry;
            if (curValue == 0 || curValue == 1) {
                result += String.valueOf(curValue);
                carry = 0;
            } else if (curValue == 2) {
                result += "0";
                carry = 1;
            } else if (curValue == 3) {
                result += "1";
                carry = 1;
            }
        }
        result = carry == 1 ? result + "1" : result;
        return new StringBuilder(result).reverse().toString();
    }
}
