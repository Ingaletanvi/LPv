#include <iostream>
#include<vector>
#include<omp.h>
#include<climits>

using namespace std;

void min_reduction(vector<int>& arr){
    int min_value = INT_MAX;
    #pragma omp parallel for reduction (min:min_value)
        for (int i = 0;i<arr.size();i++){
            if(arr[i]<min_value){
                min_value=arr[i];
            }
        }
        cout<<"Minimum value is "<<min_value<<endl;
}

void max_reduction(vector<int>&arr){
    int max_value = INT_MIN;
    #pragma omp parallel for reduction(max:max_value)
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max_value){
            max_value=arr[i];
        }
    }
    cout<< "Maximum value is "<<max_value<<endl;
}

void sum_reduction(vector<int>&arr){
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    cout<< "Sum is "<<sum<<endl;
}

void avg_reduction(vector<int>&arr){
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    cout<< "Sum is "<<(double)sum/arr.size()<<endl;
}
int main() {
    vector<int> arr;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr.push_back(value);
    }

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);

    return 0;
}
