#include<bits/stdc++.h>
using namespace std;

int StepsCalculate(vector<string> & wordList , string startWord , string targetWord){

queue<pair<string , int>> q;
q.push({startWord , 1});

unordered_set<string> st(wordList.begin() , wordList.end());

st.erase(startWord);

while(!q.empty()){

 string word = q.front().first;
 int steps = q.front().second;
 q.pop();

 if(word == targetWord) {

 	return steps;
 }

// Matching of every character in a work that was poped from the queue
 for(int i = 0; i < word.size(); i++){

 	char o = word[i];

 	for(char ch = 'a'; ch <= 'z'; ch++){

 		word[i] = ch;

 		if(st.find(word) != st.end()){

        st.erase(word);
 		q.push({word , steps + 1});
 	}

 	 
 	}

 	word[i] = o;

 	
 }

}
  return 0;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in" , "r" , stdin);

	freopen("outputf.in" , "w" , stdout);
	#endif

// taking input
int n;
cin >> n;

vector<string> wordList(n);

for(int i = 0; i < n; i++){
   
   cin >> wordList[i];

}

string startWord;
string targetWord;

cin >> startWord >> targetWord;


cout << StepsCalculate(wordList , startWord , targetWord);
     return 0;
}
