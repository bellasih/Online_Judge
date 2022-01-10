#include <bits/stdc++.h>
using namespace std;

int main(){
	char digit[5005]; int j=1;
	while(scanf("%s",digit)!=EOF){
		if(j) j=0; else printf("\n");
		int sum,pul,tmp=-1,temp=-1,flag=0;
		sum = strlen(digit);
		if(digit[sum-1]=='0' && digit[sum-2]=='0'){
			pul = (digit[sum-4]-'0')*10+(digit[sum-3]-'0');
		}
		else{
			pul = (digit[sum-2]-'0')*10+(digit[sum-1]-'0');
		}
		if(digit[sum-1]=='0' || digit[sum-1]=='5'){
			tmp=digit[0]-'0'; temp = digit[sum-1]-'0';
			for(int i=1;i<sum;i++) tmp+=(digit[i]-'0');
			for(int i=sum-2;i>=0;i--){
				if((i%2) == ((sum-1)%2)) temp+=(digit[i]-'0');
				else temp-=(digit[i]-'0');
			}
		}
		if(pul%4==0) printf("This is leap year.\n"),flag=1;
		if(tmp%3==0 && tmp!=-1) printf("This is huluculu festival year.\n"),flag=1;
		if(pul%4==0 && temp%11==0 && temp!=-1) printf("This is bulukulu festival year.\n"),flag=1;
		if(!flag) printf("This is an ordinary year.\n");
	}
	return 0;
}