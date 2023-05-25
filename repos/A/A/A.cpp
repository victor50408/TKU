#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>

#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P10IN.txt"
#define OUT "P10OUT.txt"
using namespace std;

void rollcall(int &Begin,int step,int total_step,int last,vector <int> N) {
    int index = Begin;
    for (int i = 0;i < total_step;i++) {
        do {
            index = index + step;
            if (index > last) index = 1;
            if (index < 1) index = last;
        } while (N[index] == -1);
    }
    Begin = index;

}


int mainC() {
    freopen(IN, "r", stdin);
    //freopen(OUT, "w", stdout);
    int all,Astep,Bstep;
    cin >> all;

    vector <int> N(all + 1);
    for (int i = 0;i <= all;i++) N[i] = i;
    cin >> Astep >> Bstep;

    int kicks = 0;
    int Aloca = all, Bloca = 1;
    while (1) {
        rollcall(Aloca, 1, Astep, all, N);
        rollcall(Bloca, -1, Bstep, all, N);
        if (Aloca != Bloca) {
            printf("%3d%3d", Aloca, Bloca);
            kicks += 2;
        }
        else {
            printf("%3d", Aloca);
            kicks += 1;
        }
        N[Aloca] = -1;
        N[Bloca] = -1;
        if (kicks == all) return 0;
        cout << ",";
    }


    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0;
}