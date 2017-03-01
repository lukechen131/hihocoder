#include <iostream>
#include <algorithm>
using namespace std;

int reward[101][101];
int best[101][101];

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=i; j++)
            cin >> reward[i][j];
    
    if(N==1){
        cout << reward[1][1] << endl;
        return 0;
    }

    best[1][1] = reward[1][1];
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(j==1)
                best[i][j] = best[i-1][j] +reward[i][j];
            else if(j==i)
                best[i][j] = best[i-1][j-1] +reward[i][j];
            else
                best[i][j] = max(best[i-1][j-1], best[i-1][j]) + reward[i][j];
        }
    }

    int max = -1;
    for(int i=1; i<=N; i++)
        if(best[N][i] > max)
            max = best[N][i];
    cout << max << endl;
    return 0;
}