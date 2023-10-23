#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool isLess(const vector<uint32_t>& left, const vector<uint32_t>& right){
	if (left.size() != right.size()) return left.size()<right.size(); 
	for(int i=0; i<left.size(); i++){
		if (left[i]!=right[i]) return left[i]<right[i]; 
	}
	return false; 
}

bool eval(const uint32_t N, const vector<uint32_t>& vals, 
	vector<uint32_t>& answer, vector<uint32_t> current){
	if (N==1){
		sort(current.begin(), current.end()); 
		if (answer.empty()) answer = current; 
		else if (isLess(current, answer)) answer.swap(current); 
		return true; 
	}
	if (answer.size()>0 && current.size()>=answer.size()) return false; 
	bool retval = false; 
	for(int i=vals.size()-1; i>=0; i--){
		if (vals[i]<=N && (N%vals[i])==0){
			current.push_back(vals[i]); 
			retval |= eval(N/vals[i], vals, answer, current); 
		}
	}
	return retval; 
}

int main(void){
	uint32_t N; 
	cin >> N; 	// 1 - 1,000,000,000
	int K; 
	cin >> K; // 1 - 20
	vector<uint32_t> vals(K); 
	for(int i=0; i<K; i++) cin >> vals[i]; // each 2 - 20 and distinct
	sort(vals.begin(), vals.end()); 

	vector<uint32_t> answer, temp; 
	if (eval(N, vals, answer, temp)){
		uint32_t v = 1; 
		cout << v << " "; 
		for(int i=0; i<answer.size(); i++){
			v *= answer[i]; 
			cout << v << " "; 
		}
		cout << endl; 
	} else {
		cout << -1 << endl; 
	}
	return 0; 
}
