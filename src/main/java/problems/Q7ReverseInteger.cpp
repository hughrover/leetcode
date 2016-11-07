#include <iostream>
#include <vector>

class Solution {
public:
    int reverse(int x) {
        int local_x = x < 0 ? -x : x;
        std::vector<int> digital_vector;

        // test case: 10
        while (local_x >= 10) {
        	digital_vector.push_back(local_x % 10);
        	local_x = local_x / 10;
        }
        digital_vector.push_back(local_x);

        long result = 0;
        std::vector<int>::iterator it;
        for (it = digital_vector.begin(); it != digital_vector.end(); it++) {
        	result = result * 10 + *it;
        }

        result = x < 0? -result : result;
        // notice the max int, test case: 1147483648 -> 8463847411
        return result >= -2147483648 && result <= 2147483647 ? result : 0;
    }
};

int main() {
	Solution* solution = new Solution();
	std::cout << solution->reverse(10);
}