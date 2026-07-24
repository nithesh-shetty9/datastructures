#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    string ans;

    for (int i = s.size() / 2; i < s.size(); i++) {
        ans += s[i];
        if (i != s.size() - 1)
            ans += '+';
    }

    cout << ans;

    return 0;
}