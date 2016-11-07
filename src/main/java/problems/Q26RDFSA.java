package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/18
 */
public class Q26RDFSA {

    public static void main(String[] args) {
        int[] nums = new int[]{1, 2, 3, 3, 4};
        for (int i = 0; i < removeDuplicates(nums); i++) {
            System.out.println(nums[i]);
        }
    }

    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        } else {
            int validIndex = 1;
            int curValue = nums[0];
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] != curValue) {
                    nums[validIndex++] = nums[i];
                    curValue = nums[i];
                }
            }
            return validIndex;
        }
    }
}
