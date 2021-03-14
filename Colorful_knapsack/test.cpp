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
void solve() {
    int n,m,w;
    cin>>n>>m>>w;
    vector<int>weight(n+1),color(n+1);
    for(int i(1);i<=n;++i){
        cin>>weight[i];
    }
     for(int i(1);i<=n;++i)
    cin>>color.at(i);
    vector<int>adj[m+2];
    for(int i(1);i<=n;++i){
        adj[color[i]].emplace_back(weight[i]);
    }
   
    vector<vector<int>>dp(n+2,vector<int>(w+2,-1));
    for(int j(1);j<=w;++j){
        for(auto ojon: adj[1]){
            if(ojon<=j)
            dp[1][j]=max(dp[1][j],ojon);
        }
    }
    // for(int j(1);j<=w;++j)
    // cout<<dp[1][j]<<" ";
    // cout<<endl;
    for(int i(2);i<=m;++i){
        //
        for(int j(1);j<=w;++j){
             if(i>w)break;
            for(auto ojon: adj[i]){
                if(j>ojon and dp[i-1][j-ojon]>0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-ojon]+ojon);
                }
            }
        }
    }
    if(dp[m][w]==-1)
    cout<<-1<<endl;
    else 
   cout<<w-dp[m][w]<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // int t;
    // cin>>t;
    // for (int i(1); i <= t; ++i) {
    //     printf("Case %d:\n", i);
        solve();
    //}
    return 0;
}