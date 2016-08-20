// http://www.voidcn.com/blog/bsbcarter/article/p-4658547.html
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++)
            if (knows (i, candidate) == false)
                candidate = i;
        for (int i = 0; i < n; i++)
            if (i != candidate)
                if (knows (i, candidate) == false || knows (candidate, i))
                    return -1;
        return candidate;
    }
};
