#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
vector<int> prime;
vector<int> pos[15];
bool visit[N];
int n, k;
string s;

string trans(int x) {
    string ret;
    while(x) {
        ret.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void era() {
    for(int i = 2; i < N; ++i) {
        if(!visit[i]) {
            prime.push_back(i);
            for(int j = i; j < N; j += i) visit[j] = 1;
        }
    }
}

int main() {
    era();
    cin >> n >> k;
    int v = k;
    for(int i = 0; i < n; ++i) {
        string to = trans(prime[i]);
        for(int j = 0; j < to.size(); ++j) s.push_back(to[j]);
    }
    int m = s.size();
    for(int i = 0; i < m; ++i) {
        pos[s[i] - '0'].push_back(i);
    }
    int start = 0;
    for(int i = 0; i < m - k; ++i) {
        for(int j = 9; j >= 0; --j) {
            vector<int> :: iterator it;
            it = lower_bound(pos[j].begin(), pos[j].end(), start);
            if(it == pos[j].end() || *it - start > v) continue;
            v -= (*it - start);
            start = *it + 1;
            cout << j;
            break;
        }
    }
}
