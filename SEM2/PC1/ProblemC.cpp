#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    int minimo = A[0];
    int Maxdif = -1;
    
    for(int i = 1; i < n; i++){
        if(A[i] > minimo){
            Maxdif = max(Maxdif, A[i] - minimo);
        }
        
        minimo = min(minimo, A[i]);
    }
    
    cout << Maxdif;
    
    return 0;
}
