#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define MOD 1000000007
 
const int base = 1e9;
typedef vector<int> BigInt;
 
void Set(BigInt &a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}
 
BigInt Integer(string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) {ans.pb(0); return ans;}
    while (s.size()%9 != 0) s = '0'+s;
    for (int i=0;i<s.size();i+=9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}
 
BigInt Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}
 
BigInt operator - (BigInt a, BigInt b) {
    Set(a); Set(b);
    BigInt ans; int carry = 0;
    FOR(i,0,a.size()-1) {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0) ans.pb(carry+base), carry = -1;
        else ans.pb(carry), carry = 0;
    }
    Set(ans);
    return ans;
}
 
BigInt operator - (BigInt a, int b) { return a - Integer(b); }
void operator -- (BigInt &a) { a = a - 1; }
 
ll operator % (BigInt a, ll b) {
    Set(a);
    if (b == 0) return -1;
    int ans = 0;
    FORD(i,a.size()-1,0)
        ans = (ans*(base%b) + a[i]%b)%b;
    return ans;
}
 
ll modexp(ll b, ll e){
	ll r=1;
	while(e>0) {
		if(e&1){
			r=(r*b)%MOD;
		}
		e>>=1;
		b=(b*b)%MOD;
	}
	return(ll)r;
}
 
int main() {
	char n[1001], k[1001]; ll tc, res, ex, tmp; 
	BigInt N, K;
	scanf("%lld",&tc);
	while(tc--){
		scanf("%s%s",n,k);
		N=Integer(n); K=Integer(k);
		operator -- (K);
		tmp = operator % (K,MOD);
		ex = operator % (N,(MOD-1));
		if(N%2) res=(modexp(tmp,ex))%MOD - (tmp);
		else res=(modexp(tmp,ex))%MOD + (tmp);
		printf("%lld\n",(res+MOD)%MOD);
	}
} 