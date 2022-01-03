#include<bits/stdc++.h>
#define llu unsigned long long 

using namespace std;

llu arr_binA[33], arr_binB[33];

void conv_bin(llu *arr, llu n){
    int i, k; int j=0;
    for (i = 31 ; i >= 0; i--){
        k = n >> i;
        (k & 1)? arr[j++] = 1 : arr[j++] = 0;
    }
}

int main(){
    llu A,B;
    while(scanf("%llu%llu",&A,&B)!=EOF){
        llu res = 0;
        int idx=0, flag = 0, j=0;
        arr_binA[33] = {0}; arr_binB[33] = {0};
        
        conv_bin(arr_binA, A);
        conv_bin(arr_binB, B);
        
        
        for(llu i=0;i<32;i++) {
            (arr_binA[i]+arr_binB[i])>1? arr_binA[i]=0 : arr_binA[i]+=arr_binB[i];
            if(arr_binA[i] & !flag) idx = 31 - int(i), flag=1;
        }
        for(int i=31;i>=30-idx;i--){
            res+=arr_binA[i]*pow(2,j++);
        }
        printf("%llu\n",res);
    }
}