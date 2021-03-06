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
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.size(),n2(s2.size());
    vector<vector<int>>dp(n1+2,vector<int>(n2+2,0));
    for(int i(1);i<=n1;++i){
        for(int j(1);j<=n2;++j){
            if(s1.at(i-1)==s2.at(j-1))
              dp[i][j]=1+dp[i-1][j-1];
            else {
                 int op1=dp[i-1][j];
                 int op2=dp[i][j-1];
                 dp[i][j]=max(op1,op2);
            }
        }
    }
    int i=n1,j(n2);
    string ans;
    while(i!=0 and j!=0){
        if(dp[i][j]==dp[i-1][j])i--;
        else if(dp[i][j]==dp[i][j-1])j--;
        else {
            ans+=s1[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
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