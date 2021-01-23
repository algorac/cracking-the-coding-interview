#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono; 

// O(n^2) running time
bool isUnique1(string s){
	for (int i=0; i<s.size(); i++){
		for (int j=0; j<s.size(); j++){
			if (i == j){
				continue;
			}
			if (s[i] == s[j]){
				return false;
			}
		}
	}
	return true;
}


// Try a better algorithm
//abcdea
// to build the hash table O(n)
// to travese the hash table O(n)
// Total is O(n)
bool isUnique2(string s){
	unordered_map<char, int> ht;
	// construct the hash map
	for (int i=0; i<s.size(); i++){
		ht[s[i]]++;
	}
	
	// check if any value in the hash table is greater than 1
	// if so, this means that at least one character was duplicate
	for (int i=0; i<s.size(); i++){
		if (ht[s[i]] > 1){
			return false;
		}
	}
	return true;
}


int main() {
	
	string s;
	cout << "Enter a string: "; // Enter a loong string > 100 charaters
	cin >> s;
	// Get starting timepoint to calculate rannung time
	auto start = high_resolution_clock::now(); 
	
	// Call the function 
	bool result1 = isUnique1(s); // measure the running time
	
	// Get ending timepoint 
	auto stop = high_resolution_clock::now(); 
	
	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start); 
	
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
	
	if (result1 == true){
		cout << "The string you entered is unique" << endl;
	}
	else {
		cout << "The string you entered is NOT unique" << endl;
	}
	
	// Get starting timepoint to calculate running time
	auto start1 = high_resolution_clock::now(); 
	
	// Call the function, here sort() 
	bool result2 = isUnique2(s); // measure the running time
	
	// Get ending timepoint 
	auto stop1 = high_resolution_clock::now(); 
	
	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
	
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
	
	if (result2 == true){
		cout << "The string you entered is unique" << endl;
	}
	else {
		cout << "The string you entered is NOT unique" << endl;
	}
	
}
