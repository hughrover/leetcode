#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
    	if (s.length() == 0 || s.length() % 2 == 1)
        	return false;

        std::stack<char> char_stack;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        		char_stack.push(s[i]);
        	} else {
        		if (char_stack.empty())
        			flag = false;
        		else {
        			switch (s[i]) {
        				case ')':
							if (char_stack.top() == '(')
								char_stack.pop();
							else
						    	flag = false;
						    break;
						case '}':
							if (char_stack.top() == '{')
								char_stack.pop();
							else
						    	flag = false;
						    break;
						case ']':
							if (char_stack.top() == '[')
								char_stack.pop();
							else
						    	flag = false;
						    break;
        			}
        		}
        	}
        }
        if (!char_stack.empty())
        	flag = false;
        return flag;
    }
};

int main() {
	std::string str = "(()])}[}[}[]][}}[}{})][[(]({])])}}(])){)((){";

	Solution* solution = new Solution();
    std::cout << solution->isValid(str);

    return 0;
}