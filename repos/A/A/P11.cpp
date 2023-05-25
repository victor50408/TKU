#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>

#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P11IN.txt"
#define OUT "P11OUT.txt"
using namespace std;

int T[8][256] = {0};


bool MKT() {
    string s;
    int counter = 0;

    while (getline(cin, s) && s.empty());
    if (cin.eof() || cin.fail()) return false;
    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < (1 << i) - 1;j++) {
            T[i][j] = s[counter++];
            if (counter >= s.size()) return true;
        }
    }
}

int BinToDec(int len) {
    char c;
    int sum = 0;
    for (int i = len-1;i >= 0;i--) {
        while (cin.get(c) && c == '\n');
        sum = sum + (1 << i) * (c - '0');
    }
    return sum;
}


int main11() {
    freopen(IN, "r", stdin);
    //freopen(OUT, "w", stdout);
    while (MKT()) {
        int len,num;
        char c;
        while ((len = BinToDec(3)) !=0) {
            while ((num = BinToDec(len)) != (1<<len)-1) {
                //cout << num;
                c = T[len][num];
                cout << c;
            }
        }
        cout << endl;
    }

    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0;
}