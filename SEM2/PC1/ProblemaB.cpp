#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int>freq;    
    for(int i = 0; i<n; i++){
    int x;
    cin >> x;
    freq[x]++;
    }
    int maxFreq = 0;
    int resultado = 0;
    for(auto p : freq){
        int num = p.first;
        int count = p.second;
        
        if(count > maxFreq){
            maxFreq = count;
            resultado = num;
        }
    }


    cout<<resultado;


}