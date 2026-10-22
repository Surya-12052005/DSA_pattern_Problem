//givn an array  , find the max sum of array ,such that no two elements are adjacent. 
// {5,3,3,4,2,9}

#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>&arr, int i){
    if(i>=arr.size()){
        return 0;
    }
    
    int take=arr[i]+maxSum(arr,i+2);

    int skip=maxSum(arr , i+1);
    
    return max(take,skip);

}
int main(){
    vector<int>arr={5,3,3,4,2,9};
    cout<<"maxSum="<<maxSum(arr,0);
    return 0;
}