#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stdio.h>

#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P16IN.txt"
#define OUT "P16OUT.txt"
using namespace std;

void process(string &s) {
    for (int i = 0;i < s.size();i++) s[i] = tolower(s[i]);
    sort(s.begin(),s.end());
}


int main16() {
    freopen(IN, "r", stdin);
    //freopen(OUT, "w", stdout);

    map <string, int> M;
    vector <string> ori;
    string s;
    int i = 0;
    while (cin >> s && s[0] != '#') {
        ori.push_back(s);
        process(s);
        if (M.count(s) == 0) M[s] = 1;
        else M[s]++;
    }

    vector <string> final;
    for (string t : ori) {
        string pro = t;
        process(pro);
        if (M[pro] == 1) final.push_back(t);
    }

    sort(final.begin(), final.end());
    for (string t : final) cout << t << endl;


    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0;
}