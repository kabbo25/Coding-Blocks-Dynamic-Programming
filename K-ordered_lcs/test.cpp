/*
* @Author: kabbo
* @Date:   2020-06-24 08:40:07
* @Last Modified by:   kabbo
* @Last Modified time: 2020-06-24 08:49:58
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define endl '\n'
#define ull unsigned long long
#define ll int64_t
#define ar array
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
const int mod = 1e9 + 7;
using u64 = uint64_t;
using u128 = __uint128_t;
#define sc1(x) scanf("%lld",&(x));
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
/*Well, probably you won't understand anything,
because you didn't try to understand anything in your life,
you expect all hard work to be done for you by someone else. 
Let's start*/
int n,m,k;
const int mx=2000;
int dp[mx+5][mx+5][6];
int a[mx+5],b[mx+5];
int rec(int i,int j,int k){
     if(i==0 or j==0)return 0;
     int &res=dp[i][j][k];
     if(res!=-1)return res;
     if(a[i]==b[j]){
         res=1+rec(i-1,j-1,k);
     }
     else{
         int op1=rec(i-1,j,k);
         int op2=rec(i,j-1,k);
         int op3=0;
         if(k>0)
          op3=1+rec(i-1,j-1,k-1);
         res=max({op1,op2,op3});
     }
     return res;
}
void solve() {
  cin>>n>>m>>k;
  for(int i(1);i<=n;++i)
  cin>>a[i];
  memset(dp,-1,sizeof(dp));
  for(int i(1);i<=m;++i)
  cin>>b[i];   
  cout<<rec(n,m,k)<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    int t;
  //  cin>>t;
    //for (int i(1); i <= t; ++i) {
     //   printf("Case %d:\n", i);
        solve();
    //}
    return 0;
}