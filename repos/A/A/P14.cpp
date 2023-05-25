#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P14IN.txt"
#define OUT "P14OUT.txt"
using namespace std;

vector <int> v[25];

void find_location(int target,int &bottom,int &high,int len) {
    for (int i = 0;i < len;i++) {
        for (int j = 0;j < v[i].size();j++) {
            if (v[i][j] == target) {
                bottom = i;
                high = j;
                return;
            }
        }
    }
}

void clear_block(int bottom, int high) {
    for (int i = high + 1;i < v[bottom].size();i++) {
        int t = v[bottom][i];
        v[t].push_back(t);
    }
    v[bottom].resize(high + 1); //[high+1]~最後 刪掉 EX:[0,1,2,3] resize(2) = [0,1]
}

void PushA_OnTo_B(int bottom_a,int bottom_b,int ha) {
    for (int i = ha;i < v[bottom_a].size();i++) {
        int t = v[bottom_a][i];
        v[bottom_b].push_back(t);
    }
    v[bottom_a].resize(ha); //[ha]~最後 刪掉
}



int main() {
    freopen(IN, "r", stdin);
    //freopen(OUT, "w", stdout);

    int len;
    cin >> len;
    for (int i = 0;i < len;i++) v[i].push_back(i);
    string s1, s2;
    int a, b, ha, hb, bottom_a, bottom_b;
    while (cin >> s1 && s1 != "quit") {
        cin >> a >> s2 >> b;

        find_location(a, bottom_a, ha, len);
        find_location(b, bottom_b, hb, len);


        if (bottom_a != bottom_b) {
            if (s1 == "move") {
                clear_block(bottom_a,ha); //高於ha 歸位
            }
            if (s2 == "onto") {
                clear_block(bottom_b, hb); //高於hb 歸位
            } 
            PushA_OnTo_B(bottom_a,bottom_b,ha); //將[bottom_a][ha(含)以上]搬去[bottom_b]
        }
    }
    //cout << "OK" << endl;
    
    for (int i = 0;i < len;i++) {
        cout << i << ": ";
        for (int t : v[i]) cout << t << " ";
        cout << endl;
    }
    
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0;
}
