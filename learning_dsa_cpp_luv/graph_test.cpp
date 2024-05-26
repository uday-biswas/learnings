#include <bits/stdc++.h>
using namespace std;
void dfs_topological(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> adj){
	    visited[node] = 1;
	    for(auto it : adj[node]){
	        if(!visited[it])
	          dfs_topological(it, visited, st, adj);
	    }
	    st.push(node);
	}
	
	void dfs(int node, vector<int> &visited, vector<vector<int>> adj, int &count){
	    visited[node] = 1;
        int gone = 0;
	    for(auto it : adj[node]){
	        if(!visited[it]){
	          dfs(it, visited, adj, count);
	        }
	        else{
                gone++;
            }
	    }
        if(gone > 0 && adj[node].size() == gone) count++;
	    if(adj[node].size() == 0) count++;
	}

int stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
	// Write your code here.
	vector<vector<int>> adj(V, vector<int>{});
	for(int i=0; i<edges.size(); i++){
		adj[edges[i][0]].push_back(edges[i][1]);
	}
	vector<int> visited(V,0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs_topological(i, visited,st, adj);
            }
        }
        
        vector<vector<int>> adj_reverse(V, vector<int>{});
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                adj_reverse[it].push_back(i);
            }
        }

        visited.clear();
        visited = vector<int>(V,0);
        int count = 0;
        for(int i=0; i<V; i++){
            int temp = st.top();
            st.pop();
            if(!visited[temp])
               dfs(temp, visited, adj_reverse, count);
        }
        return count;
}
int main() {
   vector<vector<int>> edges{{0,1}, {1,2}, {1,4},{2,3}, {3,2}, {4,0}};
   int count = stronglyConnectedComponents(5, edges);
   cout<<count;
return 0;
}