#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printPlane(vector<vector<vector<int>>> &cap){
    int n = cap.size();
    for(int i = 0;i<n;i++){
        int m = cap[i].size();
        for(int j =0;j<m;j++){
            int l = cap[i][j].size();
            for(int k = 0;k<l;k++){
                cout<<cap[i][j][k]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl<<endl;
    }
}

int fillWindow(int k,vector<vector<vector<int>>> &cap,int people){
    int n = cap.size();
    int i=0;
    bool flag = false;
    while(!flag){
        if(cap[0].size()>i){
            cap[0][i][0]=k++;
            if(k>people)break;
            flag = true;
        }
        
        if(cap[n-1].size()>i){
            int t = cap[n-1][i].size();
            cap[n-1][i][t-1]=k++;
            if(k>people)break;
            flag = true;
        }
        i++;
        if(flag){
            flag = false;
        }
        else{
            return k;
        }
    }
}

void fillmiddle(int k,vector<vector<vector<int>>> &cap,int people){
    int n = cap.size();
    int i = 0;
    bool flag = false;
    while(!flag){
        for(int j =0;j<n;j++){
            if(cap[j].size()>i){
                for(int t = 1;t<cap[j][i].size()-1;t++){
                    cap[j][i][t]=k++;
                    if(k>people)break;
                }
                flag = true;
            }
            if(k>people)break;
        }
        if(k>people)break;
        i++;
        if(flag){
            flag = false;
        }
        else{
            break ;
        }
    }
    
}

int fillaisle(int k,vector<vector<vector<int>>> &cap,int people){
    int i = 0;
    bool flag = false;
    int n = cap.size();
    while(!flag){
        if(cap[0].size()>i){
            int t = cap[0][i].size();
            cap[0][i][t-1]=k++;
            if(k>people)break;
            flag = true;
        }
        if(n>2){
            for(int j = 1;j<n-1;j++){
                if(cap[j].size()>i){
                    cap[j][i][0]=k++;
                    if(k>people)break;
                    int t = cap[j][i].size();
                    cap[j][i][t-1] = k++;
                    if(k>people)break;
                    flag = true;
                }
            }
        }
        
        if(cap[n-1].size()>i){
            cap[n-1][i][0]=k++;
            if(k>people)break;
            flag = true;
        }
        i++;
        if(flag){
            flag = false;
        }
        else{
            return k;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i =0;i<n;i++){
        int a=0,b=0;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int people ;
    cin>> people;
    vector<vector<vector<int>>> cap;
    for(int i=0;i<n;i++){
        int j = v[i].first;
        int k = v[i].second;
        vector<vector<int>> curr(j,vector<int>(k,0));
        cap.push_back(curr);
    }
    int k =1;
    k = fillWindow(k,cap,people);
    k = fillaisle(k,cap,people);
    fillmiddle(k,cap,people);
    printPlane(cap);
}

 
