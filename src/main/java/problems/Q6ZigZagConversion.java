package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/12
 */
public class Q6ZigZagConversion {
    public static void main(String[] args) {
        System.out.println(convert("0123456789", 2));
    }

    public static String convert(String s, int numRows) {
        if (numRows == 1)
            return s;

        StringBuilder[] stringBuilderArray = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            stringBuilderArray[i] = new StringBuilder();
        }

        int index = 0;
        int flag = 1;
        for (int i = 0; i < s.length(); i++) {
            if (flag == 1) {
                stringBuilderArray[index++].append(s.charAt(i));
                if (index == numRows) {
                    index -= 2;
                    flag = 0;
                }
            } else {
                stringBuilderArray[index--].append(s.charAt(i));
                if (index == -1) {
                    index += 2;
                    flag = 1;
                }
            }
        }

        String result = "";
        for (int i = 0; i < numRows; i++) {
            result += stringBuilderArray[i].toString();
        }

        return result;
    }
}
