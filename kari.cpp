#include <bits/stdc++.h>
using namespace std;
int n,m;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<bool>> check(250,vector<bool>(250,false));
vector<vector<char>> ma(250,vector<char>(250,' '));
vector<string> s(2000);
void dfs(int y,int x);
void sdfs(int y,int x);
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<int> y(n),x(n);
    for(int i=0;i<n;i++){
        cin>>y[i]>>x[i];
        y[i]--;
        x[i]--;
        ma[y[i]][x[i]]='#';
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    dfs(0,0);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<ma[i][j];
    //     }
    //     cout<<'\n';
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(check[i][j]==true){
    //             cout<<1;
    //         }
    //         else{
    //             cout<<0;
    //         }
    //     }
    //     cout<<'\n';
    // }
    sdfs(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==true){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    cout<<m<<'\n';
    cout<<1;
    for(int i=2;i<=m;i++){
        cout<<' '<<i;
    }
    cout<<'\n';
    return 0;
}
void dfs(int y,int x){
    check[y][x]=true;
    for(int i=0;i<4;i++){
        int ny=y+dy[i],nx=x+dx[i];
        if(0<=ny&&ny<n&&0<=nx&&nx<n&&check[ny][nx]==false&&ma[ny][nx]!='#'){
            dfs(ny,nx);
        }
    }
    return;
}
void sdfs(int y,int x){
    check[y][x]=false;
    for(int i=0;i<m;i++){
        int ny=y,nx=x,j;
        for(j=0;j<s[i].size()&&0<=ny&&ny<n&&0<=nx&&nx<n&&ma[ny][nx]!='#';j++){
            if(s[i][j]=='U'){
                ny--;
            }else if(s[i][j]=='D'){
                ny++;
            }else if(s[i][j]=='L'){
                nx--;
            }else if(s[i][j]=='R'){
                nx++;
            }
        }
        if(j==s[i].size()&&0<=ny&&ny<n&&0<=nx&&nx<n&&check[ny][nx]==true){
            sdfs(ny,nx);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<check[i][j];
    //     }
    //     cout<<endl;
    // }
    return;
}