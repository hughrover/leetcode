package problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * User: chengcheng.liu
 * Date: 16/10/12
 */
public class Q118PascalsTriangle {
    public static void main(String[] args) {
        System.out.println(generate(5));
    }

    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (numRows == 0)
            return result;
        if (numRows == 1) {
            result.add(new ArrayList<Integer>(Arrays.asList(1)));
            return result;
        }

        if (numRows == 2) {
            result.add(new ArrayList<Integer>(Arrays.asList(1)));
            result.add(new ArrayList<Integer>(Arrays.asList(1, 1)));
            return result;
        }

        result.add(new ArrayList<Integer>(Arrays.asList(1)));
        result.add(new ArrayList<Integer>(Arrays.asList(1, 1)));
        for (int i = 2; i < numRows; i++) {
            List<Integer> newRow = new ArrayList<Integer>();
            newRow.add(1);
            List<Integer> lastRow = result.get(i - 1);
            for (int j = 0; j < lastRow.size() - 1; j++) {
                newRow.add(lastRow.get(j) + lastRow.get(j + 1));
            }
            newRow.add(1);
            result.add(newRow);
        }

        return result;
    }
}
