#include <bits/stdc++.h>

using namespace std;

int n,e,s; //n个起点，e条边，s是起点

const int inf = 0x7fffff;

int dis[101]; // dis[i],起点到i点的最短距离。

int check[101];  //标记是否找到了到点i最短路径

int graph[101][101];

int main(){

    memset(dis,inf, sizeof(dis));
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
    }

    cin>>s;
    dis[s] = 0;//起点到他本身的距离不用算，最短，为0

    for(int i=1;i<=n;i++){
        int minn = inf,minx;
        for(int j=1;j<=n;j++){
            if(dis[j] < minn&&check[j]==0){
                minn = dis[j];
                minx = j;
            }
        }
        check[minx] = 1; //标记已到达的最小点
        for(int j=1;j<=n;++j){//更新以最小距离点为中转的最小距离
            if(graph[minx][j]>0){
                if(minn+graph[minx][j]<dis[j]){
                    dis[j] = minn+graph[minx][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}