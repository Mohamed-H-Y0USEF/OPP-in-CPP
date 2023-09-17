////////////////////*صل على رسول الله//*//////////////////
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


#define ll long long
#define endl  "\n"
#define Ceil(n, m)      (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define all(obj)        obj.begin(),obj.end()
#define rall(vec)       vec.rbegin(),vec.rend()
#define watch(x)        cout<<(#x)<<" = "<<x<<endl;
#define dpp(arr , val)  memset(arr , val , sizeof(arr))
#define ordered_set     tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define cin(vec)        for(auto &it:vec)cin>>it;
#define inf 1000000000
#define S second
#define F first

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero)

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll gcd(ll x,ll y)
{
    return(!y?x:gcd(y,x%y));
}
ll lcm(ll x,ll y)
{
    return x/gcd(x,y)*y;
}
ll power(ll x, ll k,ll mod = 1e9 + 7)
{
    ll ret = 1;
    while (k)
    {
        if (k & 1) ret = ((ret%mod) *(x % mod)) % mod;
        k >>= 1;
        x = ((x%mod)*(x%mod))%mod;
    }
    return ret;
}

const int N = 1e6 + 10;
const int md = 1e9 + 7;

int dx[] = { 0, 0, -1, 1, -1, 1, 1, -1};
int dy[] = {-1, 1,  0, 0,  1,-1, 1, -1};
/////////////////////////solution//////////////////////////////
struct trieTree{
    trieTree * nodes[26];
    vector<string>books;
    bool endOfWord;
    trieTree(){
        for(auto &it : nodes) it = nullptr;
        endOfWord = 0;
    }
    void insert(string &name , int idx = 0)
    {
        if(idx == name.size()) {
            endOfWord = true;
            return;
        }
        char idxChar = name[idx] - 'a';
        nodes[idxChar] = (nodes[idxChar] == nullptr ? new  trieTree : nodes[idxChar]);
        nodes[idxChar]->books.push_back(name);
        nodes[idxChar]->insert(name , idx + 1);
    }

    vector<string> getAllPrefix(string &prefix , int idx = 0)
    {
       if(idx == prefix.size()) return books;
       int cur = prefix[idx] - 'a';
       if(nodes[cur] == nullptr) return vector<string>();
        return nodes[cur]->getAllPrefix(prefix , idx + 1);
    }
};
void Solve() {
    int n;cin>>n;
    trieTree trie;
    for (int i = 0; i < n; ++i) {
        string s;cin>>s;
        trie.insert(s);
    };
    string num = "abc";
    string nd = "cd";
    vector<string> strs = trie.getAllPrefix(num);
    vector<string> s = trie.getAllPrefix(nd);

    for(auto it : strs) cout<<it<<endl;
}
///////////////////////////solution///////////////////////////
int main()
{
    FAST();File();
    int t = 1;
    //cin>>t;
    while (t--){
        Solve();
    }
}