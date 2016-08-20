class Solution {
public:
    vector<vector<int>> createGraph (int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int> ());
        for (int i = 0; i < prerequisites.size(); i++) {
            int first = prerequisites[i].first;
            int second = prerequisites[i].second;
            graph[first].push_back (second);
        }
        return graph;
    }

    vector<int> getInDegree (int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree (numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int second = prerequisites[i].second;
            inDegree[second]++;
        }
        return inDegree;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) return true;
        vector<vector<int>> graph = createGraph (numCourses, prerequisites);
        vector<int> inDegree = getInDegree (numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < inDegree.size(); j++) {
                if (inDegree[j] == 0)
                    break;
            }
            if (j == numCourses) return false;
            inDegree[j] = -1;
            for (int neigh : graph [j])
                inDegree[neigh]--;
        }
        return true;
    }
};
