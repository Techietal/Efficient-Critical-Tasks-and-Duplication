#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {50,100,200,300,400,500,600,700,800,900,1000};
    int x = 0;
    int y = 1;
    int z = 1;
    while(x < 11){
        ifstream i;
        i.open(to_string(v[x]) + " (" + to_string(y) + ").txt");
        ofstream f;
        f.open(to_string(z) + ".txt");
        int n,p;
        i >> n >> p;
        f << n << " " << p << endl;
        for(int j = 0;j < 6;j++){
            for(int k = 0;k < p;k++){
                double u;
                i >> u;
            }
        }
        vector<vector<int>> compc(n, vector<int> (p)), commc(n, vector<int> (n));
        for(int j = 0;j < n;j++){
            for(int k = 0;k < p;k++) i >> compc[j][k];
        }
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++) i >> commc[j][k];
        }
        for(int j = 0;j < n;j++){
            for(int k = 0;k < p;k++) f << compc[j][k] <<  " ";
            f << endl; 
        }
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++) f << commc[j][k] <<  " ";
            f << endl; 
        }
        if(y == 3){
            y = 1;
            x += 1;
        }
        else y++;
        z++;
    }
}