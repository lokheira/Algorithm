#include <iostream>
#include <vector>
using namespace std;
int m,n;
int aim;
vector<int> vv;
int min(vector<int> vv)
{
    int minus = vv[1];
    if(!vv.empty())
        for(int i = 1;i < vv.size();i++)
            if(vv.at(i) < minus)
                minus = vv.at(i);

    return minus;
}
void solve(int** arr, int** state,int x, int y,int sum,int num)
{
    if(sum == aim) {
        vv.push_back(num);
        return ;
    }


    state[x][y] = -1;

    if(x + 1 < n && state[x+1][y] == 0)
        solve(arr, state, x + 1, y, sum + arr[x][y], num + 1);

    if(x - 1 >= 0 && state[x-1][y] == 0)
        solve(arr, state, x -1, y, sum + arr[x][y], num + 1);

    if(y + 1 < m && state[x][y+1] == 0)
        solve(arr, state, x , y + 1, sum + arr[x][y], num + 1);

    if(y - 1 >= 0 && state[x][y-1] == 0)
        solve(arr, state, x , y-1, sum + arr[x][y], num + 1);

    state[x][y] = 0;
}
int main() {
    cin >> m >> n;
    int **arr = new int*[n];
    int **state =new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
        state[i] = new int[m]();
    }
    int sum = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }

    aim = sum / 2;
    solve(arr,state,0,0,0,0);

    int ans;
    if(vv.empty())
        ans = 0;
    else ans = min(vv);

    cout << ans;

    return 0;
}
