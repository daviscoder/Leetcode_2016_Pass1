class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        unordered_map <char, int> mp;
        for (int i = 0; i < secret.length() ; i++) {
            if (i < guess.length() && secret[i] == guess[i]) {
                bull++;
                secret.erase (i, 1);
                guess.erase (i, 1);
                i--;
            }
            else {
                mp[secret[i]]++;
            }
        }
        for (int i = 0; i < guess.length(); i++) {
            if (mp[guess[i]] > 0) {
                cow++;
                mp[guess[i]]--;
            }
        }
        return to_string (bull) + "A" + to_string (cow) + "B";
    }
};
