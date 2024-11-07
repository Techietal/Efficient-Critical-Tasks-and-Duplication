#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> v = {"cpop","heft","ippts","lstd","mpeft","peft","new"};
    ifstream f;
    fstream o;
    for(int j = 0;j < 7;j++){
    string s = v[j];
    f.open(s + ".txt");
    o.open("output.txt", ios::app);
    double sum = 0;
    for(int i = 0;i < 12;i++){
        int x;
        f >> x;
        sum += x;
    }
    sum = sum/12;
    o << s << " : " << sum << endl;
    f.close();
    o.close();
    }
}