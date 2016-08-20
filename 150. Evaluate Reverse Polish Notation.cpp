class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        int res;
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            string cur = tokens[i];
            if (cur == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push (num2 / num1);
            }
            else if (cur == "+") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push (num2 + num1);
            }
            else if (cur == "-") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push (num2 - num1);
            }
            else if (cur == "*") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push (num2 * num1);
            }
            else {
                s.push (stoi (cur));
            }
        }
        return s.top();
    }
};
