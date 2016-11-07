package problems;

import java.util.ArrayList;
import java.util.List;

/**
 * User: chengcheng.liu
 * Date: 16/9/12
 */
public class Q8StringToInteger {
    public static void main(String[] args) {
        System.out.println(myAtoi("9223372036854775809"));
    }

    public static int myAtoi(String str) {
        String localStr = str.trim();

        boolean negative = false;
        if (localStr.length() != 0) {
            char first = localStr.charAt(0);
            if (first == '-') {
                negative = true;
                localStr = localStr.substring(1, localStr.length());
            } else if (first == '+') {
                localStr = localStr.substring(1, localStr.length());
            }
        }

        List<Integer> arrayList = new ArrayList<Integer>();
        for (int i = 0; i < localStr.length(); i++) {
            Character curChar = localStr.charAt(i);
            if (Character.isDigit(curChar)) {
                arrayList.add(curChar - 48);
            } else {
                break;
            }
        }

        double result = 0.0;
        for (Integer value : arrayList) {
            result = result * 10 + value;
        }

        result = negative ? -result : result;
        result = result > 2147483647 ? 2147483647 : result;
        result = result < -2147483648 ? -2147483648 : result;

        return (int) result;
    }
}
