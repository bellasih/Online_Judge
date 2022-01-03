#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair

using namespace std;

bool sortAscending(pii &p1, pii &p2){
    return tie(p1.se, p1.fi) < tie(p2.se, p2.fi);
}

bool isEqual(pii& element, int num){
    return element.se ==  num;
}

int main(){
    int T,t, j=1;
    while(1){
        scanf("%d",&T);
        if(!T) break;
        if(j>1 && T) printf("\n");
        
        int people, consume, mean, total_consume = 0, total_people = 0;
        vector<pii> pair_mean;
        while(T--){
            scanf("%d%d",&people,&consume);
            total_consume+=consume;
            total_people+=people;
            mean = consume/people;
            auto it = find_if(pair_mean.begin(),
                              pair_mean.end(),
                              [&mean](const pii &p)
                              {return p.se == mean;});
            if(it != pair_mean.end()){
                it->fi+=people;
            }
            else{
                pair_mean.push_back(mp(people,mean));
            }
        }
        
        sort(pair_mean.begin(), pair_mean.end(), sortAscending);
        printf("Cidade# %d:\n",j++);
        for(int i=0; i<pair_mean.size();i++){
            (i!=pair_mean.size()-1)? printf("%d-%d ",pair_mean[i].fi, pair_mean[i].se):printf("%d-%d\n",pair_mean[i].fi, pair_mean[i].se);
        }
        float all_mean = (float)(total_consume)/total_people;
        
        //precision 
        int int_num = (int)all_mean;
        int mod_num = (int)(all_mean * 100)% 100;
        
        if(mod_num >= 10){
            printf("Consumo medio: %d.%d m3.\n",int_num,mod_num);
        }
        else{
            printf("Consumo medio: %d.0%d m3.\n",int_num,mod_num);
        }
    }
}