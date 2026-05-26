/*
    COURSE SCHEDULE II
    https://leetcode.com/problems/course-schedule-ii
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private :
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& stack) {
        if(visited[node] == 1) return true;
        if(visited[node] == 2) return false;

        visited[node] =1;
        for(int adj:graph[node]) {
            if(dfs(adj, graph, visited, stack)) return true;
        }
        visited[node] = 2;
        stack.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto& preq:prerequisites) {
            graph[preq[1]].push_back(preq[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> stack;

        for(int i=0; i<numCourses; i++) {
            if(dfs(i, graph, visited, stack))
                return {};
        }
        reverse(stack.begin(), stack.end());
        return stack;
    }
};