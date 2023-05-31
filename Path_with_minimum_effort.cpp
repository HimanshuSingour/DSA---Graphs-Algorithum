#include<bits/stdc++.h>

using namespace std;
 
int MinimumEfforts(vector<vector<int>> & heights){


int n = heights.size();
int m = heights[0].size();

//{effeorts , {row , col}}
priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
pq.push({0 , {0 , 0}});

vector<vector<int>> dist(n , vector<int>(m , 1e9));
dist[0][0] = 0;

int arr1[] = {-1 , 0 , 1 , 0};
int arr2[] = {0 , 1 , 0 , -1};

while(!pq.empty()){

	int diff = pq.top().first;
	int row = pq.top().second.first;
	int col = pq.top().second.second;
	pq.pop();

	if(row == n - 1 && col == m - 1) return diff;

     for(int i = 0; i < 4; i++){

     	int Nrow = row + arr1[i];
     	int Ncol = col + arr2[i];

     	if(Nrow >= 0 && Nrow < n && Ncol >= 0 & Ncol < m){

     		int effrot = max(abs(heights[row][col] - heights[Nrow][Ncol]) , diff);

     		if(effrot < dist[Nrow][Ncol]){
     			dist[Nrow][Ncol] = effrot;
     			pq.push({effrot , {Nrow , Ncol}});
     		}
     	}
     }


}

return -1;



}
 
int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input

int n,m; 
cin>>n>>m;

vector<vector<int>> heights;
       
for(int i=0; i<n; ++i){

    vector<int> temp;

    for(int j=0; j<m; ++j){

        int x; 
        cin>>x;
        temp.push_back(x);
    }
            heights.push_back(temp);
}


cout << MinimumEfforts(heights);
       

 

}