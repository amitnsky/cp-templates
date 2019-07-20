
#include <bits/stdc++.h>

#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) fr(i,0,n-1)
#define fd(i,a,b) for(i=a;i>=b;i--)

#define ll long long
#define vvl vector<vector<ll>> 
#define vl vector<ll>
#define MOD (1000*1000*1000+7)

using namespace std;

ll mat_pow(ll n){
    vvl unit = {{0,0,1},{1,0,1},{0,1,1}};
    vvl res = {{1,0,0},{0,1,0},{0,0,1}};
    while(n){
        if(n&1){
            // res = res * unit
            vvl temp(3, vl(3, 0));
            rep(i, 3) rep(j, 3) rep(k, 3)
                temp[i][j] = (temp[i][j] + (res[i][k] * unit[k][j]) % MOD) %MOD;
            res = temp;
        }
        n /=2;
        //unit = unit * unit
        vvl temp(3, vl(3, 0));
        rep(i, 3) rep(j, 3) rep(k, 3)
            temp[i][j] = (temp[i][j] + (unit[i][k] * unit[k][j]) % MOD) % MOD;;
        unit = temp; 
    }
    return res[0][2];
}

int main(){
    rep(i, 10)
        cout << i << " " << mat_pow(i+1) << endl;
}
