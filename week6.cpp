#include <iostream>
#include <algorithm>
using namespace std;
int need[501];
int value[501];
int gain[100001];

int main(){
    int N,M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> need[i] >> value[i];
    }

    /* for the Kth item, we need to decide whether to buy it or not 
        how to decide? suppose we now have t ticket, v value, k;
        then if we buy item k, 
            we will be in state of t-need[k] ticket, v+value[k] value, k+1;
        if we do not buy it
            we will be in state of t ticket. v value, k+1
    */  

    for(int i=1; i<=N; i++){
        for(int j=M; j>=1; j--){
            if(j>=need[i])
                gain[j] = max(gain[j], gain[j-need[i]]+ value[i]); 
        }
    }

    cout << gain[M] << endl;
    return 0;
}