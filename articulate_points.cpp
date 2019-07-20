#include <bits/stdc++.h>

#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) fr(i,0,n-1)
#define fd(i,a,b) for(i=a;i>=b;i--)

#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) (a).size()
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define ALL(x) (x).begin(), (x).end()

#define vi vector< int >
#define vl vector< ll >
#define vpii vector<pii>
#define vpll vector<pll>

#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endl '\n'

#define MOD (1000*1000*1000+7)
#define MXN 50
#define sq(a) ((a)*(a))

using namespace std;

vi g[MXN];
int tin[MXN];
int low[MXN];
int vis[MXN];

vi ap;
vpii br;

int timer;

int m,n,p,q,t,u,v,a,b;

void ap_dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            ap_dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1) 
            // a-b-c and a-d-e, a is articulate point, 
            // also note that we have ap but no bridge.
                ap.pb(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        ap.pb(v);
}

void init(){
    timer = 0;
    fill(tin, tin+MXN, 0);
    fill(vis, vis+MXN, 0);
    fill(low, low+MXN, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin>>n>>m;
    rep(i, m){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    init();
    ap_dfs(0);
    
    if(ap.size()){
        cout << ap.size() << '\n';
        sort(ap.begin(), ap.end());
        for(int x: ap)
            cout<<x<<' ';
        cout << '\n';
    }
}

