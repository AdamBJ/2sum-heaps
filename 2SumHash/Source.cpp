#include <unordered_map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

const std::string FILE_NAME = "test.txt";

int main(){
	std::unordered_map < long long, long long> hashTable;
	//hashTable.reserve(1000000);//reserve creates a number of buckets in the hashtable most appropriate for "argument" number of elements.

	//std::unordered_map < long long, long long> hashTable2;

	//hashTable2[1] = 2;
	//auto u = hashTable2.find(1);
	//auto p =hashTable2.find(2);

	//if (p == hashTable2.end()){
	//	std::cout<< "ppepe";
	//}

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
		for (auto it = hashTable.begin(); it != hashTable.end(); ++it){//use auto& if you want to be able to modify the values you're iterating over
			//std::cout << " " << it->first << ":" << it->second << std::endl; this is how you print out the elements of a hash table
			
			x = it->second; //get the key stored at the current position
			y = t - x; //because x+y=t, t-x =y;
			if (hashTable.find(y) != hashTable.end() && x!=y){//find returns hashTable.end if the key doesn't exist.
				hitCount++;
				std::stringstream ss;
				ss << x << " " << y << " " << t;
				u.push_back(ss.str());

				break;
			}
		}
		t++;
	}

	std::cout << hitCount;
	return 0;
}