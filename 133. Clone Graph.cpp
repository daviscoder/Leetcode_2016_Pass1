/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
// a map mapping the original graph to new graph.
    unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> myMap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (myMap.find (node) != myMap.end())
            return myMap[node];
        myMap[node] = new UndirectedGraphNode (node->label);
        for (int i = 0; i < (int)node->neighbors.size(); i++) {
            myMap[node]->neighbors.push_back (cloneGraph (node->neighbors[i]));
        }
        return myMap[node];
    }
};
