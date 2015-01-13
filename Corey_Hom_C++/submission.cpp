#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <list>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	string line;
	//use list, map, and vector to sort the values and write the values to file
	list<int> numberList;
	map<int, map<int,int>> numCheck;
	list<vector<int>> toWrite;
	string file = argv[1];
	string writeStrFile = argv[2];
	ifstream myfile(file);
	ofstream writeFile(writeStrFile);
	//open file
	if(myfile.is_open()){
		while(getline(myfile,line)){
			stringstream ss;
			ss << line;
			int num;
			ss >> num;
			numberList.push_back(num);
		}
		//sort numbers
		numberList.sort();
		myfile.close();
		list<int>::iterator it = numberList.begin();
		it++;
		//2 nested for loops and search
		//subtract
		//use binary search
		//push it on the vector
		for(it; it != numberList.end(); it++){
			list<int>::iterator it2 = numberList.begin();
			for(it2; it2 != numberList.end(); it2++){
				if(((*it - *it2) != 0) && ((*it - *it2) != *it) && ((*it - *it2) != *it2)){
					int toFind = (*it - *it2);
					if(binary_search(numberList.begin(), numberList.end(), toFind)){
						if((numCheck[*it2][*it] != toFind) && (numCheck[*it][*it2] != toFind)){
							vector<int> toPush;
							toPush.push_back(*it2);
							toPush.push_back(*it);
							toPush.push_back(toFind);
							toWrite.push_back(toPush);
							(numCheck[*it2])[*it] = toFind;
						}
					}
				}
				//check for order
				//check for duplicates
				//make sure that the output is in an increasing order
				//find the number if it's before the two numbers
				else if((*it - *it2) != *it){
					int toFind = (*it - *it2);
					if(*it2 == *(numberList.begin())){
						list<int>::iterator temp = numberList.begin();
						temp++;
						if(binary_search(temp, numberList.end(), toFind)){
							if((numCheck[*it2][*it] != toFind) && (numCheck[*it][*it2] != toFind)){
								vector<int> toPush;
								toPush.push_back(*it2);
								toPush.push_back(*it);
								toPush.push_back(toFind);
								toWrite.push_back(toPush);
								(numCheck[*it2])[*it] = toFind;
							}
						}
					}
					else{
						if(binary_search(numberList.begin(), it2, toFind)){
							if((numCheck[*it2][*it] != toFind) && (numCheck[*it][*it2] != toFind)){
								vector<int> toPush;
								toPush.push_back(*it2);
								toPush.push_back(*it);
								toPush.push_back(toFind);
								toWrite.push_back(toPush);
								(numCheck[*it2])[*it] = toFind;
							}
						}
						if(binary_search(it2, numberList.end(), toFind)){
							if((numCheck[*it2][*it] != toFind) && (numCheck[*it][*it2] != toFind)){
								vector<int> toPush;
								toPush.push_back(*it2);
								toPush.push_back(*it);
								toPush.push_back(toFind);
								toWrite.push_back(toPush);
								(numCheck[*it2])[*it] = toFind;
							}
						}
					}
				}
			}
		}
		//write to file, sort
		toWrite.sort();
		for(list<vector<int>>::iterator iter = toWrite.begin(); iter != toWrite.end(); iter++){
			if(writeFile.is_open()){
				writeFile << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << "\n";
			}
		}
	}
}