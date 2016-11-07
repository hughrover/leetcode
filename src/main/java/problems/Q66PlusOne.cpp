#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
    	if (digits.size() == 0)
    		return digits;

    	int carry = 1;

    	for (int ix = digits.size() - 1; ix >= 0; --ix) {
    		int cur_val = digits[ix] + carry;

    		if (cur_val == 10) {
    			digits[ix] = 0;
    			carry = 1;
    		} else {
    			digits[ix] = cur_val;
    			carry = 0;
    			break;
    		}
    	}

    	if (carry == 1) {
    		digits.resize(digits.size() + 1);
    		for (int ix = digits.size() - 1; ix >= 0; --ix) {
    			digits[ix] = digits[ix - 1];
    		}
    		digits[0] = carry;
    	}

    	return digits;
    }
};

int main() {
	int ia[6] = {9, 9, 9, 9, 9, 9};
	std::vector<int> ivec(ia, ia + 6);
	Solution* solution = new Solution();
	solution->plusOne(ivec);

	for (int ix = 0; ix != ivec.size(); ++ix) {
		std::cout << ivec[ix] << std::endl;
    }
}