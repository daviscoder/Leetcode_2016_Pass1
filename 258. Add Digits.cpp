class Solution {
public:
    int addDigits(int num) {
        if (num && num % 9 == 0)
            return 9;
        else
            return num % 9;
    }
};

/*
number                   result
   0                     0  // 0 % 9 = 0, 0 == 0
   1                     1 // 1 % 9 = 1
   2                     2
   3                     3
   4                     4
   5                     5
   6                     6
   7                     7
   8                     8
   9                     9 // 9 % 9 = 0, 9 != 0
   10                   1 // 10 % 9 = 1
   11                    2
   12                    3
   13                    4
   14                    5
   15                    6
   16                    7
   17                    8
   18                    9
   19                    1 //19 % 9 = 1
*/
