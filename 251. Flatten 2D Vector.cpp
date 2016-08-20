class Vector2D {
public:
    vector<vector<int>>:: iterator it, end;
    int j = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        return (*it)[j++];
    }

    bool hasNext() {
        while (it != end && j == (*it).size()) {
            it++;
            j = 0;
        }
        return it != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
