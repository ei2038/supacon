#include <bits/stdc++.h>
using namespace std;
int n,m;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<bool>> check(250,vector<bool>(250,false));
vector<vector<char>> ma(250,vector<char>(250,' '));
vector<string> s(2000);
vector<int> sn(2000,0);
vector<vector<pair<int,int>>> sr(2000,vector<pair<int,int>>(0));
vector<pair<int,int>> ss(2000);
vector<int> su(2000,0);
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
    vector<vector<bool>> er(2000,vector<bool>(500000,0));
    for(int i=0;i<m;i++){
        cin>>s[i];
        sn[i]=s[i].size();
        int ry=0,rx=0;
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='U'){
                ry--;
            }else if(s[i][j]=='D'){
                ry++;
            }else if(s[i][j]=='L'){
                rx--;
            }else if(s[i][j]=='R'){
                rx++;
            }
            for(int k=0;k<sr[i].size();k++){
                if(sr[i][k].first==ry&&sr[i][k].second==rx){
                    er[i][k]=true;
                }
            }
            sr[i].push_back(make_pair(ry,rx));
        }
        for(int j=sn[i]-1;j>=0;j--){
            if(er[i][j]==true||(sr[i][j].first==0&&sr[i][j].second==0)){
                sr[i].erase(sr[i].begin()+j,sr[i].begin()+j+1);
                sn[i]--;
            }
        }
    }
    for(int i=0;i<m;i++){
        ss[i].first=sn[i];
        ss[i].second=i;
    }
    sort(ss.begin(),ss.begin()+m);
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<sn[i];j++){
    //         cout<<sr[i][j].first<<' '<<sr[i][j].second<<'\n';
    //     }
    //     cout<<'\n';
    // }
    dfs(0,0);
    sdfs(0,0);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(check[i][j]==true){
    //             cout<<1;
    //         }else{
    //             cout<<0;
    //         }
    //     }
    //     cout<<'\n';
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==true){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    int mc=0;
    for(int i=0;i<m;i++){
        // cout<<su[i]<<" ";
        if(su[i]>0){
            mc++;
        }
    }
    cout<<mc<<'\n';
    for(int i=0;i<m;i++){
        if(su[i]>0){
            cout<<i+1<<' ';
        }
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
        int j,ny,nx,i2=ss[i].second;
        for(j=0;j<sn[i2];j++){
            ny=y;
            nx=x;
            ny+=sr[i2][j].first;
            nx+=sr[i2][j].second;
            if(ny<0||n<=ny||nx<0||n<=nx||ma[ny][nx]=='#'){
                
                break;
            }
        }
        ny=y+sr[i2][sn[i2]-1].first;
        nx=x+sr[i2][sn[i2]-1].second;
        if(j==sn[i2]&&0<=ny&&ny<n&&0<=nx&&nx<n&&check[ny][nx]==true){
            // cout<<ny<<"a"<<nx<<endl;
            su[i2]++;
            sdfs(ny,nx);
        }
    }
    return;
}