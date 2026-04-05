#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int cnt=0;
        queue<int> q;

        for(int i=0; i<n; i++) {
            if(!visited[i]){ 
                q.push(i);
                while(!q.empty()) {
                    int city=q.front();
                    q.pop();
                    visited[city] = true;
                    for(int j=0; j<n; j++) {
                        if(isConnected[city][j] == 1 && !visited[j])
                            q.push(j);
                    }
                }
                cnt++;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    void bfs(queue<int>&q,int count,int n,vector<vector<int>>&isConnected,vector<int>&vis){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 1 ;i<=n;i++){
                if(isConnected[node-1][i-1] && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n+1,0);
        int count = 0;
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                q.push(i);
                count++;
                bfs(q,count,n,isConnected,vis);
            }
        }
        return count;
    }
};