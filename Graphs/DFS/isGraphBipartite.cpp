
/*
    IS GRAPH BIPARTITE
    https://leetcode.com/problems/is-graph-bipartite
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for(int i=0; i<n; i++) {
            if(colors[i] == -1) {
                queue<int> qt;
                qt.push(i);
                colors[i] = 0;

                while(!qt.empty()) {
                    int curr = qt.front();
                    qt.pop();

                    for(int ngh : graph[curr]) {
                        if(colors[ngh] == -1) {
                            colors[ngh] = 1 - colors[curr];
                            qt.push(ngh);
                        }else if(colors[ngh] == colors[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
