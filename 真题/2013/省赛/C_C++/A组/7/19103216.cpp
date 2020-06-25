#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

void s2i(string& str, int& num)
{
    stringstream ss;
    ss << str;
    ss >> num;
}
int main() {
    int m,n;
    vector<int> vv;
    int line;
    cin >> line;
    getchar();
    for(int i = 0; i < line; i++)
    {
        string str;
        getline(cin,str);
        istringstream iss(str);
        string tmp;
        while(getline(iss,tmp,' '))
        {
            int t;
            s2i(tmp,t);
            vv.push_back(t);
        }
    }
//    cout << vv.size();
    sort(vv.begin(),vv.end());
    for(int i = 0;i < vv.size(); i++ )
    {
        if(vv[i] == vv[i+1])
            n = vv[i];
        if(vv[i]+2 == vv[i+1])
            m = vv[i]+1;
    }
     cout <<  m << ' ' << n;
    return 0;

}
