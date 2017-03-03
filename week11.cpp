#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes(100000);
int visit[100000];
int path_longest = -1;

void check(int longest, int longer){
    if(longest + longer > path_longest)
        path_longest = longest + longer;
}

int dfs(int i){
    visit[i] = 1;
    int longest, longer;
    if(nodes[i].size()==1 && visit[nodes[i][0]] == 1)  // if the node is a leaf, return 0;
        return 0;
    if(nodes[i].size()==1){ // if it has only one child, then longest and longer are both child length
        longest = dfs(nodes[i][0]) + 1;
        longer = 0;
        check(longest, longer);
        return longest;
    }

    longer = -1;
    if(visit[*(nodes[i].begin())]){ // if it is its parent node, pass
        longest = dfs(*(nodes[i].begin()+1)) + 1; // initial longest with the second child.
    }
    else{ // it is an unvisited child
        longest = dfs(*(nodes[i].begin())) + 1;
    }

    // get the longer and longest child_path and test with the pat_longest.
    for(auto itr = nodes[i].begin(); itr!= nodes[i].end(); ++itr){ // if it has multiple children, set longest to be the one longest.
        if(visit[*itr] == 1)
            continue;
        int temp = dfs(*itr) + 1;
        if(temp > longest){
            longer = longest;
            longest = temp;
        }
        else if(temp > longer)
            longer = temp;
    }
    check(longest, longer);
    return longest;
}

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }
    dfs(0);
    cout << path_longest << endl;
}
