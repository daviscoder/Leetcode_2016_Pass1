class Solution {
public:
    bool validateIPv4Token (string& token) {
        if (token.size() > 3 || token.size() == 0)
            return false;
        int num = 0;
        for (int i = 0; i < token.size(); i++) {
            if (isdigit(token[i]) == false || (num == 0 && token[i] == '0' && token.size() > 1)) {
                return false;
            }
            num = num * 10 + token[i] - '0';
        }
        return num < 256;
    }
    
    bool validateIPv6Token (string& token) {
        if (token.size() > 4 || token.size() == 0)
            return false;

        for (int i = 0; i < token.size(); i++) {
            if (isdigit(token[i]) == false && !(token[i] >= 'a' && token[i] <= 'f') && !(token[i] >= 'A' && token[i] <= 'F')) {
                return false;
            }
        }
        return true;
    }

    bool validateV4 (const string& IP) {
        stringstream ss (IP);
        string token;
        for (int i = 0; i < 4; i++) { // only 4 segments.
            if (!getline(ss, token, '.') || !validateIPv4Token(token)) {
    	   	    return false;
            }
        }
        return ss.eof();
    }

    bool validateV6 (const string& IP) {
        stringstream ss (IP);
        string token;
        for (int i = 0; i < 8; i++) {
            if (!getline(ss, token, ':') || !validateIPv6Token(token)) {
    	   	    return false;
            }
        }
        return ss.eof();
    }

    string validIPAddress(string IP) {
        if (validateV4(IP)) {
            return "IPv4";
        }
        else if (validateV6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
};
