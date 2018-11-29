#include<bits/stdc++.h>

using namespace std;

typedef long long llng;
typedef map<int,int> MPI;
typedef map<int,int> :: iterator MIT;
typedef vector<int> VECI;
typedef priority_queue<int> PQI;

#define PI acos(-1.0)
#define F first
#define S second
#define forip(a,n) for(int i = (int)a; i<=(int)n; i++)
#define forin(a,n) for(int i = (int)n; i>=(int)a; i--)
#define forjp(a,n) for(int j = (int)a; j<=(int)n; j++)
#define _ << " " <<

struct node
{
    int a,b;
}nod[10000];

int cost[10000][10000],costn[10000];
VECI vec[10000];
bool visited[10000];

void bfs(int x,int y)
{
    int tmp;
    queue<int> q;
    q.push(x);
    costn[x]=0;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        forip(0,vec[tmp].size()-1)
        {
            if(visited[vec[tmp][i]]==false)
            {
                visited[vec[tmp][i]] = true ;
                costn[vec[tmp][i]]=costn[tmp]+cost[tmp][vec[tmp][i]];
                if(vec[tmp][i]==y)
                    return ;
                q.push(vec[tmp][i]);
            }
        }
    }
}
int main()
{
    int n,t,a,b,c,sum;
    cin >> t ;
    while(t--)
    {
        cin >> n;
        forip(1,n-1)
        {
            scanf("%d%d%d",&a,&b,&c);
            vec[a].push_back(b);
            vec[b].push_back(a);
            cost[a][b] = c ;
            nod[i].a = a;
            nod[i].b = b;
        }
        char str[50],ins[20];
        getchar();
        while(scanf("%s",str))
        {
            if(strcmp(str,"DONE")==0)
                break;
            scanf("%d%d",&a,&b);
            if(strcmp(str,"CHANGE")==0)
            {
                 cost[nod[a].a][nod[a].b] = b;
            }
            else
            {
                memset(visited,false,sizeof(visited));
                bfs(a,b);
                printf("%d\n",costn[b]);
            }
        }
        forip(0,9999)
            vec[i].clear();
    }
    return 0;
}
