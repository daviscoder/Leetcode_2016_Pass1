class Solution {
public:
    string intToRoman(int num) {
        vector <int> index = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        unordered_map <int, string> myMap = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        string str;
        for (int i = index.size() - 1; i >= 0 && num != 0; i--) {
            for (int j = 0; j < num / index[i]; j++)
                str += myMap[index[i]];
            num = num - num / index[i] * index[i];
        }
        return str;
    }
};
