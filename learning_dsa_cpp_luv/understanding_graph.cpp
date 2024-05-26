#include <bits/stdc++.h>
using namespace std;
class graph{
    public:
    //adjacency list to store elements along with their connections
    map<int, vector<int>> adj;
    
     //function to make adjacency list out of vertices and edges
     void adjacency_list_maker(vector<int> vertices, vector<vector<int>> edges, int direction = 0){
        //v - no. of vertices, vertices - array of vertices , edges - vector of edges between vertices
        //if direction = 0, then its undirected and if it is 1 ,then its directed

        //to add all nodes in the adjacencey list , this is useful when the graph contains multiple components
        for(int i=0; i<vertices.size(); i++){
         adj[vertices[i]] = vector<int>{};
        }

        //to add edges to the adjacency list
        for(int i=0; i<edges.size(); i++){
           int u = edges[i][0];
           int v = edges[i][1];
           adj[u].push_back(v);             //adding edge from u to v.
           if(direction == 0) adj[v].push_back(u);  //if the graph is undirected , then adding back edge from v to u. 
        }
     }

     //function to find bfs traversal of the component of graph if root is given 
     //approach - here we have to traverse the graph levelwise, the root vertex is at level 0, the vertices connected to root
     //are at level 1, the vertices which are two edges away are at level 2, similarlyl going on ...
     //we will keep the root vertex at queue , then pop it and will put all the connected vertices at the queue, then again 
     //we will take the front vertex in the queue and push all neighbour vertices which are not visited(earlier level vertices are already visited)
     //similarly we will go on until the queue is empty.
     vector<int> bfs_component(int root, map<int, bool> &visited){
        queue<int> q;
        vector<int> ans_part;
        q.push(root);
        visited[root] = true;
        while(!q.empty()){
           int temp = q.front();
           q.pop();
           ans_part.push_back(temp);
           for(int i=0; i<adj[temp].size(); i++){   //to traverse all the neighbours of the current node
              if(visited[adj[temp][i]]) continue;
              q.push(adj[temp][i]);
              visited[adj[temp][i]] = true;
           }
        }
        return ans_part;
     }

     //function to print the bfs traversal of a graph even if it has multiple components
     //approach - we will traverse each vertex, if it is visited then , we will send that vertex as root to bfs_component ,
     //and if it is visited , it means it is covered in the earlier component of the graph or there is only one component.
     void bfs_graph(){
        map<int,bool> visited;
        vector<vector<int>> ans;
        vector<int> ans_part;
        //getting the bfs traversal of all the components of graph and storing them in 'ans'
        for(auto it : adj){
          if(!visited[it.first]){
             ans_part = this->bfs_component(it.first, visited);
             ans.push_back(ans_part);
          }
        }

        //printing the graph as bfs traversal 
        cout<<endl<<"printing the graph as bfs traversal"<<endl;
        for(int i=0; i<ans.size(); i++){
          for(int j=0; j<ans[i].size(); j++){
             cout<<ans[i][j]<<" ";
          }
          cout<<endl;
        }
     }

     //this function could give the dfs traversal of the component of the graph if root is given 
     //approach - here we want depth first traversal , so we will go till the depth , put it into the ans_part , then we will
     //go to the next vertex.
     //firstly we will put all the neighbour vertex of the root and mark the root as visited, then we will take the first 
     //element of the stack and if it is not visited then we will put all its neighbour vertices and mark that element as visited
     // and repeat this process until the stack is empty.
     void dfs_component(int root, map<int, bool> &visited, vector<int> &ans_part){
        stack<int> st;
        st.push(root);
        while(!st.empty()){
           int temp = st.top();
           st.pop();
           if(visited[temp]) continue;
           for(int i = adj[temp].size()-1; i>=0; i--){   //to traverse all the neighbours of the current node
              st.push(adj[temp][i]);
           }
           ans_part.push_back(temp);
           visited[temp] = true;
        }
     }
 
     //function to give the dfs traversal of the component of the graph if the root is given 
     //approach - similar to preorder traversal of binary tree
     void dfs_component1(int root, map<int,bool> &visited, vector<int> &ans_part){
        ans_part.push_back(root);
        visited[root] = true;
        for(int i=0; i<adj[root].size(); i++){      //to traverse all the neighbours of the current node
           if(!visited[adj[root][i]]) 
                dfs_component1(adj[root][i], visited, ans_part);
        }
     }

      //this function is used to print the dfs of the whole graph even if it has multiple components
      //approach - for each component it will select its root and will send it to the dfs_component function along with the visited map 
      // that will provide its dfs traversal .
      //dfs_component will also put each vertex of the component as true in visited ,so that those vertices cannot become the root for different component
      void dfs_graph(){
        map<int, bool> visited;
        vector<int> ans_part;
        vector<vector<int>> ans;
        for(auto it : adj){
           if(!visited[it.first]){
                ans_part.clear();
                this->dfs_component1(it.first, visited, ans_part);   //sending the root and visited to dfs_component 
                ans.push_back(ans_part);      //storing this component's dfs traversal in ans
           }
        }

        //printing the dfs traversal of the graph
        cout<<endl<<"printing the graph as dfs traversal"<<endl;
        for(int i=0; i<ans.size(); i++){
          for(int j=0; j<ans[i].size(); j++){
             cout<<ans[i][j]<<" ";
          }
          cout<<endl;
        }
      }

    //function to print the current graph as a adjacency list
     void printGraph(){
      cout<<endl<<"printing the graph as adjacency list"<<endl;
        for(auto it : adj){
            cout<<it.first<<" -> ";
            for(int i=0; i<it.second.size(); i++){
               cout<<adj[it.first][i]<<" ";
            }
            cout<<endl;
        }
     }
};

int main() {
graph* g = new graph();
vector<int> vertices = {0,1,2,3,4,5,6,7};
vector<vector<int>> edges = {{0,1},{0,2},{0,3},{2,3},{3,4},{5,6},{5,7},{6,7}};
g->adjacency_list_maker(vertices,edges);
g->printGraph();          //printing the graph as adjacency list
g->bfs_graph();          //printing the bfs traversal of the graph
g->dfs_graph();         //printing the dfs traversal of the graph 
return 0;
}