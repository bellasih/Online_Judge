#include<bits/stdc++.h>

using namespace std;

int main(){
    int game[5] = {0};
    for(int i=0;i<4;i++){
        scanf("%d",&game[i]);
    }
    
    if(game[3]<game[1]){
        game[3] = 60 + game[3] - game[1];
        game[2]--;
    }
    else{
        game[3]-=game[1];
    }
    game[2]<game[0]? game[2]+=(24-game[0]) : game[2]-=game[0];
    if(!game[3] & !game[2]) game[2] = 24;

    
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",game[2],game[3]);
}