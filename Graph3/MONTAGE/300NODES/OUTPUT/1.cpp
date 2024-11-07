#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream f;
    fstream o;
    string s = "new";
    f.open(s + ".txt");
    o.open("300.txt", ios::app);
    double sum = 0;
    for(int i = 0;i < 18;i++){
        int x;
        f >> x;
        sum += x;
    }
    sum = sum/18;
    o << s << " : " << sum << endl;
}