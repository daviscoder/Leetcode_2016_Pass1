class Solution {
public:
    void dfs (vector<string>& result, vector<string>& current, long prevValue, char prevSign, long sum, int start, string& num, int target) {
        if (start == num.size()) {
            if (sum == target) {
                string sb = "";
                for (int i = 0; i < current.size(); i++) {
                    sb += current[i];
                }
                result.push_back(sb);
            }
            return;
        }
        
        for (int i = start; i < num.size(); i++) {
            long cur = stol(num.substr(start, i - start + 1));
            if (i != start && cur == stol(num.substr(start + 1, i -start))) break; // skip when multiple leading '0' exist.
            
            string curStr = "+" + num.substr(start, i - start + 1);
            current.push_back(curStr);
            dfs (result, current, cur, '+', sum + cur, i + 1, num, target); // plus
            current.pop_back();
            
            curStr = "-" + num.substr(start, i - start + 1);
            current.push_back(curStr);
            dfs (result, current, cur, '-', sum - cur, i + 1, num, target); // plus
            current.pop_back();
            
            // '*'
            curStr = "*" + num.substr(start, i - start + 1);
            current.push_back(curStr);
            if (prevSign == '+') {
                dfs (result, current, cur * prevValue, '+', sum - prevValue + prevValue * cur, i + 1, num, target);
            }
            else if (prevSign == '-') {
                dfs (result, current, cur * prevValue, '-', sum + prevValue - prevValue * cur, i + 1, num, target);
            }
            else {
                dfs (result, current, cur * prevValue, prevSign, cur * prevValue, i + 1, num, target);
            }
            current.pop_back();
            
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        vector<string> current;
        
        for (int i = 0; i < num.size(); i++) {
            long cur = stol(num.substr(0, i + 1));
            if (i != 0 && cur == stol(num.substr(1, i))) break; // skip when multiple leading '0' exist.
            current.push_back(num.substr(0, i + 1));
            dfs (result, current, cur, '#', cur, i + 1, num, target);
            current.pop_back();
        }
        return result;
    }
};
