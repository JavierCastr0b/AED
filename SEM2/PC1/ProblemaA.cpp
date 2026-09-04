#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;

    vector<int>A;
    
    
    for(int i = 0; i < q; i++){
        string op;
        cin >> op;
        if(op == "INS"){
            int pos, val;
            cin >> pos >> val;
            A.insert(A.begin() + pos, val);
        }
        else{
            int pos;
            cin >>pos;
            A.erase(A.begin()+ pos);
        }

    }
    for(int i = 0; i<A.size(); i++){
        cout<<A[i];
    }
    cout << "\n";
    return 0;
}