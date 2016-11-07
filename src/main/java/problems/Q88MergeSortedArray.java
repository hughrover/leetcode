package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/23
 */
public class Q88MergeSortedArray {
    public static void main(String[] args) {
        int[] num1 = new int[]{0, 0};
        int[] num2 = new int[]{1};
        merge(num1, 1, num2, 0);

        for (int num : num1)
            System.out.println(num);
    }

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos = m + n - 1;

        int p1 = m - 1, p2 = n - 1;
        while (pos >= 0) {
            if (p1 >= 0 && p2 >= 0) {
                if (nums1[p1] >= nums2[p2]) {
                    nums1[pos--] = nums1[p1];
                    p1--;
                } else {
                    nums1[pos--] = nums2[p2];
                    p2--;
                }
            } else {
                nums1[pos--] = p1 >= 0 ? nums1[p1--] : nums2[p2--];
            }
        }
    }
}
