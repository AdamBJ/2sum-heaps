#include <unordered_map>
#include <fstream>
#include <iostream>

const std::string FILE_NAME = "2sum.txt";

int main(){
	std::unordered_map < long long, long long> hashTable;
	hashTable.reserve(1000000);//reserve creates a number of buckets in the hashtable most appropriate for "argument" number of elements.

	std::ifstream integersToBeRead(FILE_NAME);

	if (integersToBeRead.is_open()){
		long long i;
		while (integersToBeRead >> i){
			hashTable[i] = i;
		}
	}
	else {
		std::cout << "Coudn't open file.";
		return 0;
	}

	int t = -10000,x,y,hitCount=0;
	std::vector<std::string> u;

	while (t <= 10000){
		for (auto it = hashTable.begin(); it != hashTable.end(); ++it){
			x = it->second; //get the key stored at the current position
			y = t - x; //because x+y=t, t-x =y;
			if (hashTable.find(y) != hashTable.end() && x!=y){//find returns hashTable.end if the key doesn't exist.
				hitCount++;
				break;
			}
		}
		t++;
	}
	std::cout << hitCount;
	return 0;
}