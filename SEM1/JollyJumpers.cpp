#include <iostream>

void jollyJumpers(int n, int arr[] ) {
    for(int i = 1; i < n-1; i++ ){
        for(int j = i + 2; j < n; j++ ){
            if(arr[i] == arr[j]){
                std::cout << "NO" << std::endl;
                return;
            }
        }
    }

}

int main(){
    



}