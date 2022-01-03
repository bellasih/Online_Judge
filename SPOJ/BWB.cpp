#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;
 
ll dp[10001][101];
 
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--){
		ll N,K,sum=1;
		scanf("%lld%lld",&N,&K);
		dp[1][K]=1; dp[0][K]=0;
		for(i=1;i<K;i++){
			dp[i+1][K]=(2*dp[i][K])%MOD;
			sum+=dp[i+1][K];
		} 
		if(N>K){
			ll j=0;
			for(i=K+1;i<=N;i++){
				if(i-1!=K) sum+=dp[i-1][K];
				sum-=dp[j][K];
				dp[i][K]=sum%MOD;
				j++;
			}
		}
		printf("%lld\n",dp[N][K]);
	}
} 