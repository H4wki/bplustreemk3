#include "bplustreemk3.h"
#include <fstream>
#include <iostream>
using namespace std;
bplustreemk3::bplustreemk3(int blockSize) {
	this->headerSize = 0;
	this->blockSize = blockSize;
	this->totalNumRecords = 0;
	this->blockSize = 3;
	this->totalBlocks = 1;
	this->numAvalBlocks = 5;
	this->numOfLevels = 6;
	this->rbnRoot = 7; // RBN of root is first item after header then it is avail list seqence 
	this->rbnLevels = 8;
	this->rbnAvailList = 9;
	this->sizeofRecords = 10;
	this->numFieldsPerRecord = 11;
	this->root = block(this->blockSize, NULL);
}
bplustreemk3::bplustreemk3()
{

	this->headerSize = 0;
	this->blockSize = 1;
	this->totalNumRecords = 2;
	this->blockSize = 4;
	this->totalBlocks = 1;
	this->numAvalBlocks = 5;
	this->numOfLevels = 6;
	this->rbnRoot = 7; // RBN of root is first item after header then it is avail list seqence 
	this->rbnLevels = 8;
	this->rbnAvailList = 9;
	this->sizeofRecords = 10;
	this->numFieldsPerRecord = 11;
	this->root = block(this->blockSize, NULL);
	block::blockList.push_back(root);
	//this->pToRoot = &root;

}
int bplustreemk3::size() {
	return this->totalNumRecords;
}
block bplustreemk3::recursivSearch(vector<block> searchE, int item, int num) {
	if ((searchE.at(num).items.size() + 1) < this->blockSize){
		return searchE.at(num);
	}
	else {
		return this->recursivSearch(searchE.at(num).children, item, num);
	}
	return  block(3,NULL);
}
bool bplustreemk3::insert(int insertE) {
	for (int i = 0; i < this->blockList.size; i++) {
		if ((this->blockList.at(i).items.size()+1)<this->blockSize) {
			if (this->blockList.at(i).items.front > this->blockList.at(i).getParent()->items.back && insertE > this->blockList.at(i).getParent()->items.back) {
				this->blockList.at(i).add(insertE);
				return true;
			}
			if (this->blockList.at(i).items.back < this->blockList.at(i).getParent()->items.front && insertE < this->blockList.at(i).getParent()->items.front) {
				this->blockList.at(i).add(insertE);
				return true;
			}
			
		}
		else {
			if (this->blockList.at(i).items.front > this->blockList.at(i).getParent()->items.back && insertE > this->blockList.at(i).getParent()->items.back) {
				vector<int> orignal=this->blockList.at(i).items.;
				vector<int> newStuff;
				while (true) {
					
				}
			}
			if (this->blockList.at(i).items.back < this->blockList.at(i).getParent()->items.front && insertE < this->blockList.at(i).getParent()->items.front) {
				
			}
		}
	}
	
	/*if ((root.items.size()+1)<this->blockSize) {
		root.add(insertE);
		return true;
	}
	else {
		for (int i = 0; i < this->blockList.size(); i++) {
			if()
		}
	}
	this->totalNumRecords++;*/
	return false;
}
bool bplustreemk3::remove() {
	return false;
}
bool bplustreemk3::checkEmpty() {
	return false;
}
bool bplustreemk3::isPresent() {
	return false;
}
bool bplustreemk3::headerToFile() {
	ofstream myfile;
	myfile.open("test.txt");
	myfile << this->headerSize << "|" << this->blockSize << "|" << this->totalBlocks << "|" << this->numAvalBlocks << "|" << this->numOfLevels << "|" << this->rbnAvailList << "|" << this->rbnLevels << "|" << this->rbnRoot << "|";
	myfile.close();
	return true;
}
int bplustreemk3::getBlockSize() {
	return this->blockSize;
}
void bplustreemk3::toString() {
	for (int i = 0; i < this->blockSize;i++) {
		cout << root.items.at(i) << endl;
	}
	
}