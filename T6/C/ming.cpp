#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M, ans;
char c[205][205];
int s[205][205], h[2][205][205];

int get(int l, int r, int v) {
    return s[r][v] - s[l-1][v];
}

int calc(int dir, int row, int l, int r) {
    int res = -100000000;
    stack <int> st; st.push(l - 1);
    int left = h[dir][row][l - 1], right = h[dir][row][r + 1];
    h[dir][row][l - 1] = h[dir][row][r + 1] = 0;
    ff(i, l, r + 1) {
        while (h[dir][row][i] < h[dir][row][st.top()]) {
            int x = st.top(); st.pop();
            res = max(res, h[dir][row][x] * (i - st.top() - 1));
        }
        st.push(i);
    }
    h[dir][row][l - 1] = left; h[dir][row][r + 1] = right;
    return res;
}

int main(void) {
    cin >> N >> M;
    ff(i, 1, N) cin >> (c[i] + 1);
    ff(i, 1, N) ff(j, 1, M) s[i][j] = s[i-1][j] + c[i][j] - '0';
    ff(i, 1, N) ff(j, 1, M) h[0][i][j] = (c[i][j] - '0') * (h[0][i-1][j] + 1);
    fb(i, N, 1) ff(j, 1, M) h[1][i][j] = (c[i][j] - '0') * (h[1][i+1][j] + 1);
    ff(l, 1, N) ff(r, l, N) {
        int prev = 1;
        ff(j, 1, M + 1) {
            if (j <= M && get(l, r, j) == r - l + 1) continue;
            if (j - prev >= 3) ans = max(ans, (j - prev) * (r - l + 1) + calc(0, l - 1, prev + 1, j - 2) + calc(1, r + 1, prev + 1, j - 2));
            prev = j + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
