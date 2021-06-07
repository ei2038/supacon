#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<vector<int>> x(3,vector<int>(2,0));
    x[0][0]=2;
    x[0][1]=3;
    x[1][0]=3;
    x[1][1]=1;
    x[2][0]=1;
    x[2][1]=2;
        for(int i=0;i<3;i++){
        cout<<i+1<<':'<<x[i][0]<<' '<<x[i][1]<<'\n';
    }
    sort(x.begin(),x.end());
    for(int i=0;i<3;i++){
        cout<<i+1<<':'<<x[i][0]<<' '<<x[i][1]<<'\n';
    }
    return 0;
}