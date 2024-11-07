#include <bits/stdc++.h>
using namespace std;

void calioct(vector<vector<int>> &ioct,vector<vector<int>> &commc, vector<vector<int>> &compc, vector<int> &fin, int &ind){
    for(int i = 0;i < compc[0].size();i++){
        int maxi = 0;
       for(int j = 0;j < commc.size();j++){
            if(commc[ind][j] != -1){
                if(fin[j] == 0){
                    calioct(ioct,commc,compc,fin,j);
                    fin[j] = 1;
                }
                int mini = INT_MAX;
                for(int k = 0;k < compc[0].size();k++){
                    if(i == k) mini = min(mini, (ioct[j][k]));
                    else mini = min(mini,(ioct[j][k] + commc[ind][j]));
                }
                maxi = max(mini,maxi);
            }
       }
       ioct[ind][i] = maxi + compc[ind][i];
    }
}

void getioct(vector<vector<int>> &ioct,vector<vector<int>> &commc,vector<vector<int>> &compc,vector<int> &fin){
    for(int i = 0;i < fin.size();i++){
        if(fin[i] == 0){
            calioct(ioct,commc,compc,fin,i);
            fin[i] = 1;
        }
    }
}

void performtask(vector<vector<int>> &task, vector<int> &seq,vector<int> &avail ,vector<vector<int>> &compc,vector<vector<int>> &commc,vector<vector<int>> &ioct){
    for(int i = 0;i < seq.size();i++){
        int ieftm = INT_MAX,eft = 0, outdeg = 0,meft = INT_MAX;
        for(int j = 0;j < commc.size();j++){
            if(commc[seq[i] - 1][j] != -1) outdeg++;
        }
        for(int j = 0;j < avail.size();j++){
            int est = 0,ieft = 0;
            for(int k = 0;k < commc.size();k++){
                if(commc[k][seq[i] - 1] != -1){
                    if(task[k][2] == j) est = max(est,task[k][1]);
                    else est = max(task[k][1] + commc[k][seq[i] - 1],est);
                }
            }
            est = max(est,avail[j]);
            eft = est + compc[seq[i] - 1][j];
            ieft = eft + ioct[seq[i] - 1][j];
            if(outdeg > compc[0].size()){
                if(eft < meft){
                    meft = eft;
                    task[seq[i] - 1][0] = est;
                    task[seq[i] - 1][1] = eft;
                    task[seq[i] - 1][2] = j;
                }
            }
            else{
                if(ieft < ieftm){
                    ieftm = ieft;
                    task[seq[i] - 1][0] = est;
                    task[seq[i] - 1][1] = eft;
                    task[seq[i] - 1][2] = j;
                }
            }
        }
        avail[task[seq[i] - 1][2]] = task[seq[i] - 1][1];
    }
}

int main(){
    int h = 1;
    ifstream f;
    ofstream o;
    o.open("aeft.txt");
    while(h <= 12){
    f.open(to_string(h) + ".txt");
    int n,p;
    f >> n >> p;
    vector<vector<int>> commc(n,vector<int> (n)), compc(n,vector<int> (p));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++) f >> compc[i][j];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) f >> commc[i][j];
    }
    vector<vector<int>> ioct(n,vector<int> (p));
    vector<int> fin(n,0);
    for(int i = 0;i < n;i++){
        if(*max_element(commc[i].begin(),commc[i].end()) == -1){
            for(int j = 0;j < p;j++){
                ioct[i][j] = compc[i][j];
            }
            fin[i] = 1;
        }
    }
    getioct(ioct,commc,compc,fin);
    vector<double> prank(n);
    for(int i = 0;i < n;i++){
        double k = 0;
        for(int j = 0;j < p;j++){
            k += ioct[i][j];
        }
        prank[i] = (k/p);
    }
    priority_queue<pair<double,int>> pq;
    for(int i = 0;i < n;i++){
        pq.push({prank[i],-(i + 1)});
    }
    vector<int> seq(n);
    for(int i = 0;i < n;i++){
        int y = -(pq.top().second);
        seq[i] = y;
        pq.pop();
    }
    vector<vector<int>> task(n,vector<int> (3));
    vector<int> avail(p,0);
    performtask(task,seq,avail,compc,commc,ioct);
    // cout << "TASKS\tST\tFT\tPRO\n";
    // for(int i = 0;i < n;i++){
    //     cout << i + 1 << "\t" << task[i][0] << "\t" << task[i][1] << "\t" << task[i][2] + 1 << endl;
    // }
    int maxi = 0;
    for(int i = 0;i < n;i++){
        maxi = max(maxi, task[i][1]);
    }
    o << maxi << endl;
    h++;
    f.close();
    }
    o.close();
}