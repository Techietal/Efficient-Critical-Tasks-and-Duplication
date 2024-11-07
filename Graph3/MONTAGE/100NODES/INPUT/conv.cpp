#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream f;
    ofstream o;
    int h = 1;
    while(h <= 18){
    string s = to_string(h) + ".txt";
    f.open(s);
    int n,p;
    f >> n >> p;
    cout << n << " " << p << endl;
    for(int i = 0;i < 6;i++){
        for(int j = 0;j < p;j++){
            double x;
            f >> x;
            cout << x << " ";
        }
        cout << endl;
    }
    vector<vector<int>> commc(n,vector<int> (n)), compc(n,vector<int> (p));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++){
            f >> compc[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            f >> commc[i][j];
        }
    }
    o.open(s);
    o << n << " " << p << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++){
            o << compc[i][j] << " ";
        }
        o << endl;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            o << commc[i][j] << " ";
        }
        o << endl;
    }
    h++;
    f.close();
    o.close();
    }
}