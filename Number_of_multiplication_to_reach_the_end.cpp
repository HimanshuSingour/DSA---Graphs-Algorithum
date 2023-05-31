#include<bits/stdc++.h>

using namespace std;

int minimumMultiplications(vector<int> arr , int start , int end){

	queue<pair<int , int>> q;
	q.push({start , 0});

	vector<int> dist(100000 , 1e9);
	dist[start] = 0;

	int mod = 100000;

	while(!q.empty()){

		int node = q.front().first;
		int steps = q.front().second;
		q.pop();

		for(auto i : arr){

			int num = (i * node) % mod;

			if(steps + 1 < dist[num]){

				dist[num] = steps + 1;
				if(num == end) return steps + 1;
				q.push({num , steps + 1});
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
  int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;

cout << minimumMultiplications(arr , start , end); 

}