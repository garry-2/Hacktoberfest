#include<bits/stdc++.h>
using namespace std;


//TC < O(2^n) and SC = O(1)
int knapsack(int i,int W,vector<int> weights,vector<int> values,vector<vector<int>> &dp){

    if(i == weights.size()){
        return 0;
    }
    
    if(dp[i][W] != -1){
        return dp[i][W];
    }
    
    if(weights[i] <= W){
        return dp[i][W] = max(values[i]+ knapsack(i+1,W-weights[i],weights,values,dp),knapsack(i+1,W,weights,values,dp));
    }
    else{
        return dp[i][W] = knapsack(i+1,W,weights,values,dp);
    }

}


int main()
{
    vector<int> weights = {4,5,1};
    vector<int> values = {1,2,3};

    int W = 4;

    //memorization
    vector<vector<int>> dp(weights.size()+1,vector<int> (W+1,-1));

    cout << knapsack(0,W,weights,values,dp);
    



 return 0;
}
