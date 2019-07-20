#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for(int i=0, l=0, r=0; i<n; i++){
        if(i<=r)
            z[i] = min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]] == s[i+z[i]]) 
            z[i]++;
        if(i+z[i]-1 > r)
            l=i, r=i+z[i]-1;
    }
    return z;
}

void z_match(string& pat, string& text){
    vector<int> z_table = z_function(pat + "$" + text);
    int res = 0;
    for(int x: z_table)
        res += (x == pat.size());
    cout << res << '\n';
}
int main(){
    string p,t;
    cin>>p>>t;
    z_match(p, t);
}