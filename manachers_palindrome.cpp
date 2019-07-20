
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
#define MXN 100001
#define sq(a) ((a)*(a))

using namespace std;

int d1[MXN];
int d2[MXN];

void manachers_table(string& s){
    int n = s.size();
    // calc for odd length palindromes
    for(int i=0, l=0, r=-1; i<n; i++){
        int k = (i>r) ? 1 : min(r-i+1, d1[l+r-i]);
        while((i+k)<n && (i-k)>=0 && s[i-k] == s[i+k]) k++;
        d1[i] = k--; // if k==1 r should be compared with i+0 
        if((i+k) > r)
            r = i+k, l=i-k;
    }
    // calc for even length palindromes....
    for(int i=0, l=0, r=-1; i<n; i++){
        int k = (i>r) ? 0 : min(r-i, d2[l+r-i]);
        while((i+k+1)<n && (i-k)>=0 && s[i-k] == s[i+k+1]) k+=2;
        d2[i] = k; // if k==1 r should be compared with i+0 
        if((i+k) > r)
            r = i+k+1, l=i-k;
    }
}
void longest_palindrome_len(string s){
    int n = s.size();
    manachers_table(s);
    int len =  max(*max_element(d1, d1+n)*2-1, *max_element(d2, d2+n)*2);
    cout << len << '\n';
    
    for(int i=0; i<n; i++){
        if(d1[i]*2-1 == len){
            cout << s.substr(i-d1[i]+1, len) << '\n';
            break;
        }
        if(d2[i]*2 == len){
            cout << s.substr(i-d2[i]+1, len) << '\n';
            break;
        }
    }
}
int main(){
    string s;
    cin>>s;
    longest_palindrome_len(s);
}