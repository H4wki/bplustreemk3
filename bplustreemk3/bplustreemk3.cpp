
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
	this->root = block(this->blockSize, NULL, 7);
}
bplustreemk3::bplustreemk3()
{

	this->headerSize = 0;
	this->totalNumRecords = 0;
	this->blockSize = 3;
	this->totalBlocks = 0;
	this->numAvalBlocks = 0;
	this->numOfLevels = 0;
	this->rbnRoot = 7; // RBN of root is first item after header then it is avail list seqence 
	this->rbnLevels = 8;
	this->rbnAvailList = 9;
	this->sizeofRecords = 10;
	this->numFieldsPerRecord = 11;
	this->root = block(this->blockSize, NULL, 0);
	this->blockList.push_back(root);
	//this->pToRoot = &root;
}
int bplustreemk3::size() {
	return this->totalNumRecords;
}
bool bplustreemk3::insert(int insertE) {
	cout << "ROOT SIZE " << this->root.items.size() << endl;
	for (int i =this->blockList.size(); i >0; i--) {
		if (this->blockList.at(i-1).items.size() + 1 < this->blockSize) {
			if (this->blockList.at(i-1).largestV > insertE) {
				this->blockList.at(i-1).add(insertE);
				totalNumRecords++;
				return true;
			}
			else {
				this->blockList.at(i-1).add(insertE);
				totalNumRecords++;
				return true;
			}
			
		}
		else {
			//look up the tree back wards via levels
			if (this->blockList.at(i-1).level == 0) {
				this->blockList.at(i - 1).add(insertE);
				block temp1=block(this->blockSize,&root, this->blockList.at(i - 1).items.at(0),root.level+1);
				block temp2=block(this->blockSize,&root, this->blockList.at(i - 1).items.at(1),root.level+1);
				temp2.add(this->blockList.at(i - 1).items.at(2));
				this->blockList.push_back(temp1);
				this->blockList.push_back(temp2);
				this->blockList.at(i - 1).remove(temp1.largestV);
				this->blockList.at(i - 1).remove(temp2.largestV);
				totalNumRecords++;
				return true;
			}
			/*if (this->blockList.at(i-1).largestV > insertE) {
				
				this->blockList.at(i-1).add(insertE);
			}
			else {
				this->blockList.at(i-1).add(insertE);
			}*/
		}
	}
	return false;
}
bool bplustreemk3::remove(int item) {
	return false;
}
bool bplustreemk3::checkEmpty() {
	if (this->totalNumRecords == 0) { return true; }
	return false;
}
bool bplustreemk3::isPresent(int lookup) {
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
	cout << "Number of Items  | " << this->totalNumRecords << endl;
	cout << "Number of Blocks | " << this->blockList.size() << endl;
	for (int i = 0; i < this->blockList.size(); i++) {
		cout << "Changing Level to " << this->blockList.at(i).getLevel() << endl;
		for (int x = 0; x < this->blockList.at(i).size(); x++) {
			cout << this->blockList.at(i).items.at(x) << endl;
		}

	}

}