#include<vector>

/*
    CHEAPEST FLIGHTS WITH K STOPS
    https://leetcode.com/problems/cheapest-flights-within-k-stops
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        for(int i=0; i<=k; i++){
            vector<int> previousDistance = distance;
            for(auto flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if(previousDistance[from] != INT_MAX && previousDistance[from] + price < distance[to]) {
                    distance[to] = previousDistance[from] + price;
                }
            }
        } 
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        pq.push({0,{src, 0}});

        vector<int>dis(n, 1e9);
        dis[src]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int stops=it.first;
            int node=it.second.first;
            int currPrice=it.second.second;
            if(stops>k) continue;

            for(auto info:adj[node]){
                int adjNode=info.first;
                int price=info.second;
                if(price+currPrice<dis[adjNode] ){
                    dis[adjNode]=price+currPrice;
                    pq.push({stops+1, {adjNode, dis[adjNode]}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};