class ZigzagIterator {
private:
    vector<int> my_vector;
    int pos = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v1.size() || i < v2.size(); i++) {
            if (i < v1.size()) {
                my_vector.push_back (v1[i]);
            }
            if (i < v2.size()) {
                my_vector.push_back (v2[i]);
            }
        }
    }

    int next() {
        return my_vector[pos++];
    }

    bool hasNext() {
        return pos < my_vector.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
