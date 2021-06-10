#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
int n, m;
//          下 右  上  左
int dy[4] = {1, 0, -1,  0};
int dx[4] = {0, 1,  0, -1};
vector<vector<bool>> check(250, vector<bool>(250, false));
vector<vector<char>> ma(250, vector<char>(250, ' '));
vector<string> s(2000);
vector<int> sn(2000, 0);
vector<pair<int, int>> go(2000);
vector<vector<pair<int, int>>> sr(2000, vector<pair<int, int>>(0));
vector<pair<int, int>> ss(2000);
vector<bool> su(2000, false);
void dfs(int y, int x);
void sdfs(int y, int x);
double get_elapsed_time(struct timeval *begin, struct timeval *end);

signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    struct timeval t1, t2;
    gettimeofday(&t1, NULL);
    cin >> n;
    vector<int> y(n), x(n);
    for(int i = 0; i < n; ++i){
        cin >> y[i] >> x[i];
        y[i]--;
        x[i]--;
        ma[y[i]][x[i]] = '#';
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> s[i];
        sn[i] = s[i].size();

        int ry = 0, rx = 0;
        for(int j = 0;j < s[i].size(); ++j){
            if(s[i][j] == 'U'){
                ry--;
            }else if(s[i][j] == 'D'){
                ry++;
            }else if(s[i][j] == 'L'){
                rx--;
            }else if(s[i][j] == 'R'){
                rx++;
            }

            sr[i].push_back(make_pair(ry,rx));

            if(j == s[i].size() - 1){
                go[i].first = ry;
                go[i].second = rx;
            }
        }
        sort(sr[i].begin(), sr[i].begin() + s[i].size());
        for(int j = s[i].size() - 1; j >= 1; --j){
            if(sr[i][j].first == sr[i][j - 1].first && sr[i][j].second == sr[i][j - 1].second){
                sr[i].erase(sr[i].begin() + j - 1, sr[i].begin() + j - 1 + 1); // 分かりやすくするため（- 1 + 1）
                sn[i]--;
            }
        }
    }
    for(int i = 0; i < m; ++i){
        ss[i].first = sn[i];
        ss[i].second = i;
    }

    sort(ss.begin(), ss.begin() + m);
    // for(int i=0;i<m;++i){
    //     for(int j=0;j<sn[i];++j){
    //         cout<<sr[i][j].first<<' '<<sr[i][j].second<<'\n';
    //     }
    //     cout<<'\n';
    // }
    dfs(0, 0);
    sdfs(0, 0);
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         if(check[i][j]==true){
    //             cout<<1;
    //         }else{
    //             cout<<0;
    //         }
    //     }
    //     cout<<'\n';
    // }
    for(int i = 0;i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(check[i][j] == true){
                cout << "NO\n";
                gettimeofday(&t2, NULL);
                double t = get_elapsed_time(&t1, &t2);
                // t にプログラム (∗) の部分の実行時間（ミリ秒）が代入される
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << "YES\n";
    int mc = 0;
    for(int i = 0; i < m; ++i){
        if(su[i] == true){
            mc++;
        }
    }
    cout << mc << '\n';
    for(int i = 0; i < m; ++i){
        if(su[i] == true){
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
    gettimeofday(&t2, NULL);
    double t = get_elapsed_time(&t1, &t2);
    // t にプログラム (∗) の部分の実行時間（ミリ秒）が代入される
    cout << t << endl;
    return 0;
}
void dfs(int y, int x){
    check[y][x] = true;
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i], nx = x + dx[i];
        if(0 <= ny && ny < n && 0 <= nx && nx < n && check[ny][nx] == false && ma[ny][nx] != '#'){
            dfs(ny, nx);
        }
    }
    return;
}
void sdfs(int y, int x){
    check[y][x] = false;
    for(int i = 0; i < m; ++i){
        int j, ny, nx, i2 = ss[i].second;
        for(j = 0; j < sn[i2]; ++j){
            ny = y;
            nx = x;
            ny += sr[i2][j].first;
            nx += sr[i2][j].second;
            if(ny < 0 || n <= ny || nx < 0 || n <= nx || ma[ny][nx] == '#'){

                break;
            }
        }
        ny = y + go[i2].first;
        nx = x + go[i2].second;
        if(j == sn[i2] && 0 <= ny && ny < n && 0 <= nx && nx < n && check[ny][nx] == true){
            su[i2] = true;
            sdfs(ny, nx);
        }
    }
    return;
}

double get_elapsed_time(struct timeval *begin, struct timeval *end) {
    return (end->tv_sec - begin->tv_sec) * 1000 + (end->tv_usec - begin->tv_usec) / 1000.0;
}