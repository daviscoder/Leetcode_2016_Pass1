class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() == 0)
            return "";
        int i = 0;
        vector <string> str;
        while (i < path.length()) {
            // get current toten.
            i++;
            string tmp = "";
            cout << i << endl;
            while (i < path.length() && path[i] == '/') i++; // remove redundant '/'
            while (i < path.length() && path[i] != '/') {
                tmp += path[i];
                i++;
            }
            if (tmp == ".." && (int)str.size() > 0)
                str.pop_back ();
            else if (tmp == ".." || tmp == "." || tmp == "")
                continue;
            else
                str.push_back (tmp);
        }
        string res = "/";
        for (int i = 0; i < (int) str.size() - 1; i++)
            res += str[i] + '/';
        if (str.size() > 0)
            res += str[str.size() - 1];
        return res;
    }
};
