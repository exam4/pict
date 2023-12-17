#include<iostream>
using namespace std;

class mst
{
    private:
        int v,v1,v2,e,w;
        int graph[20][20];
        bool visited[20];
        int distance[20];
        int parent [20];
        int cost = 0;
    public:
        int findMinimum(int dis[],bool vis[]);
        void prims();
        void dijikstras(int source);
        mst()
        {
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    graph[i][j]=0;
                }
            }
            cout<<"Enter the number of vertices:";
            cin>>v;
            cout<<"Enter no. of edges:";
            cin>>e;
            cout<<"Enter the edge like v1(space)v2(space)weight."<<endl;
            for(int i=0;i<e;i++){
                cin>>v1>>v2>>w;
                graph[v1][v2]=w;
                graph[v2][v1]=w;
            }
            cout<<endl;
            for(int i=0;i<20;i++){
                distance[i]=2364;
            }
            for(int i=0;i<20;i++){
                visited[i]=false;
            }
            cout<<endl<<"Adjecency matrix of graph is:"<<endl;
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int mst::findMinimum(int dis[],bool vis[]){
    int minimum=2364;
    int vertex;
    for(int i=0;i<v;i++){
        if(vis[i]==false && dis[i]<minimum){
            vertex=i;
            minimum=dis[i];
        }
    }
    return vertex;
}

/*void mst::dijikstras(int source){
    parent[source]=-1;
    distance[source]=0;
    for(int i=0;i<(v-1);i++){
        int u=findMinimum(distance,visited);
        visited[u]=true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && visited[j]==false && distance[u]!=2364 && distance[u]+graph[u][j]<distance[j]){
                distance[j]=distance[u]+graph[u][j];
                parent[j]=u;
            }
        }
    }
    for(int i=1;i<v;i++){
        cout<<parent[i]<<"->"<<i<<":"<<graph[parent[i]][i]<<endl;
    }
}*/

void mst::prims(){
    parent[0]=-1;
    distance[0]=0;
    for(int i=0;i<(v-1);i++){
        int u=findMinimum(distance,visited);
        visited[u]=true;
        // if (parent[u] != -1){
        //      cost += graph[parent[u]][u];
        // }
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && visited[j]==false && graph[u][j]<distance[j]){
                distance[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
    cout<<endl<<"The minimum spanning tree using prim's algorithm is:"<<endl;
    for(int i=1;i<v;i++){
        cout<<parent[i]<<"->"<<i<<":"<<graph[parent[i]][i]<<endl;
        cost += graph[parent[i]][i];
    }

   cout<<"Cost of mst is: "<<cost<<endl;
}

int main(){
    mst m1;
    m1.prims();
    //cout<<"Dijikstras algo:"<<endl;
    //m1.dijikstras(0);
    return 0;
}
