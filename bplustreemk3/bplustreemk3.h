#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct block;
struct block {
	vector<block> children;//pointer to the children
	block* parent;
	vector<int> items;
	int maxSize;
	int level;
	int largestV;
	//static vector<block> blockList;

	block() {

	}
	block(int intSize, block* par, int level) {
		this->parent = par;
		this->maxSize = intSize;
		this->level = level;
	}
	block(int intSize, block* par, int item, int level) {
		this->parent = par;
		this->maxSize = intSize;
		this->add(item);
		this->level = level;
	}
	vector<block> getChildren() {
		return this->children;
	}
	block* getParent() {
		return this->parent;
	}
	bool add(int newItem) {
		if (items.size() == this->maxSize) { return false; }
		for (int i = 0; i < items.size(); i++) {
			if (items.at(i) < newItem) {
				continue;
			}
			items.insert(items.begin() + i, newItem);
			return true;
		}
		this->items.push_back(newItem);
		this->largestV = this->items.back();
		return true;
	}
	bool remove(int delItem) {
		if (items.size() == 0) { return false; }
		for (int i = 0; i < items.size(); i++) {
			if (items.at(i) == delItem) {
				items.erase(items.begin() + i);
				return true;
			}
		}
		return false;
	}
	void setRoot(block* newRoot) {
		this->parent = newRoot;
	}
	void addChild(block newChild) {
		this->children.push_back(newChild);
	}
	void removeChild(block removeB) {
		for (int i = 0; i < this->children.size(); i++) {
			block temp = this->children.at(i);
			for (int x = 0; x < removeB.items.size(); x++) {
				if (temp.items.at(i) == removeB.items.at(i)) {
					temp.items.erase(temp.items.begin() + i);
				}
			}
		}
	}
	int bigestV() {
		return items.back();
	}
	int size() {
		return items.size();
	}
	int getLevel() {
		return level;
	}
	void toString() {

		for (int i = 0; i < this->items.size(); i++) {
			cout << items.at(i);
		}
		cout << endl;
	}

};
//bool operator ==(block a, block b) {
//	if (a.items.size() != b.items.size()) { return false; }
//	for (int i = 0; i < a.items.size(); i++) {
//		if (a.items.at(i) != b.items.at(i)) {
//			return false;
//		}
//	}
//	return true;
//}

class bplustreemk3 {
private:
	//Header Record Variables
	int headerSize;
	int blockSize;
	int totalBlocks;
	int numAvalBlocks;//Number of open blocks
	int numOfLevels;
	int rbnRoot; //Relative offest to root node
	int rbnLevels;//Relative offset to levels
	int rbnAvailList;//Relative offset to the avial list
	int totalNumRecords;//total number of records
	int sizeofRecords;
	int numFieldsPerRecord;
	block root;
	vector<block> blockList;

	//block* pToRoot;
	//String variable
	string description;
	string time;
	string lastMod;
public:
	bplustreemk3();
	bplustreemk3(int blockSize);
	bool insert(int insertE);
	bool remove(int item);
	bool checkEmpty();
	bool isPresent(int lookup);
	int size();
	bool headerToFile();
	int getBlockSize();
	void toString();
};