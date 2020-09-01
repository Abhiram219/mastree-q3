#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Using Dp for solving the problem.
int noOfUniqueWaysToClimb( int noOfSteps, int n, vector<int> stepArray  ) {

    int res[noOfSteps+1] = {0};
    res[0] = 1;
    
    for(int i = 0; i < noOfSteps+1 ; i++) { 
        int temp = res[i];
        for(int j=0; j<n; j++ ) {
            if( i-stepArray[j] > 0) {
                temp+= res[ i - stepArray[j] ];
            }
        }
        
        res[i] = temp;
        
        if( std::find(stepArray.begin(), stepArray.end(), i) != stepArray.end() ) {
            res[i]++;
        }
    } 
    
    return res[noOfSteps]; 
}

int main()
{
    int noOfSteps;
    cout<<"Enter the number of steps in staircase : ";
    cin>> noOfSteps;
    cout<<"Enter the size of array of steps to climb : ";
    int n;
    cin >> n;
    std::vector<int> stepArray(n);
    for(int i=0;i<n;i++){
        cin>>stepArray[i];
    }
    
    sort(stepArray.begin(), stepArray.end());
    
    
    cout<< noOfUniqueWaysToClimb(noOfSteps, n, stepArray) <<endl;
    
    return 0;
}
