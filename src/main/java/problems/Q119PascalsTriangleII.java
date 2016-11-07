package problems;

import java.util.ArrayList;
import java.util.List;

/**
 * User: chengcheng.liu
 * Date: 16/10/12
 */
public class Q119PascalsTriangleII {
    public static void main(String[] args) {
        System.out.println(getRow(0));
    }

    public static List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < rowIndex + 1; i++) {
            result.add(1);
        }

        if (rowIndex == 0 || rowIndex == 1) {
            return result;
        }

        for (int i = 3; i <= rowIndex + 1; i++) {
            for (int j = i - 2; j >= 1; j--) {
                result.set(j, result.get(j) + result.get(j - 1));
            }
        }
        return result;
    }
}
