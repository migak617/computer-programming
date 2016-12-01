#include <process.h>
#include <iostream>
#include "event.h"
#include "game.h"
#include "frame.h"
#include "exArray.h"
#include "swap.h"
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Word {
private:
	string word;
public:
	Word(string word) {
		this->word = word;
	}
	string getWord() {
		return this->word;
	}
};

void dump(list<string> &l) {
	list<string>::iterator iter = l.begin();

	while (iter != l.end()) {
		cout << *iter << endl;
		iter++;
	}
}

Game* game = new Game();

unsigned int __stdcall mythread(void*) {
	int i = 0;
	while (1) {
		game->move();
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getkey();
		if (i != -1) game->setDirection(i);
	}
	return 0;
}

int main() {
	/*
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);
	
	try
	{
		Frame *f1 = new Frame;
		Frame *f2 = new Frame[10];

		delete f1;
		delete[] f2;
	}
	catch (string msg)
	{
		cout << "Error msg : " << msg << endl;
	}
	Exarray<int> arr1(3);
	Exarray<char> arr2(4);
	Exarray<double> arr3(5);

	arr1.addData(2);
	arr2.addData('A');
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();

	int num1 = 10, num2 = 40;
	cout << "before : " << num1 << ", " << num2 << endl;
	mySwap<int>(num1, num2);
	cout << "after : " << num1 << ", " << num2 << endl;

	double num1d = 121.11, num2d = 10.5;
	cout << "before : " << num1d << ", " << num2d << endl;
	mySwap<int>(num1, num2);
	cout << "after : " << num1d << ", " << num2d << endl;

	Exarray<int> arr4(5);
	arr4.addData(10);

	mySwap<Exarray<int>>(arr1, arr4);
	arr1.printData();
	arr4.printData();
	*/
	/*	12.01 ½Ç½À
	vector <int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 50);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << "access index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);

	vector<int> ::iterator iter = v.begin();

	cout << "access index at 1 with iterator : " << iter[1] << endl;

	while (iter != v.end()) {
		cout << *iter << endl;
		iter++;
	}
	
	list<string> names;
	names.insert(names.begin(), "Konkuk");
	names.insert(names.end(), "University");
	names.insert(names.end(), "SCLAB");
	names.insert(names.end(), "CSY");
	dump(names);
	cout << "====" << endl;
	names.reverse();
	dump(names);
	
	map<string, int> m;
	m["seoul"] = 100;
	m["daegu"] = 120;
	m["busan"] = 200;

	cout << "Train to Seoul = " << m["seoul"] << "$" << endl;
	cout << "Train to Seoul = " << m["daegu"] << "$" << endl;
	cout << "Train to Seoul = " << m["busan"] << "$" << endl;
	*/
	map<char, list<Word>> m;

	list<Word> aList;
	list<Word> bList;

	aList.push_back(Word("apple"));
	aList.push_back(Word("avoid"));
	aList.push_back(Word("appear"));

	bList.push_back(Word("bread"));
	bList.push_back(Word("bring"));
	bList.push_back(Word("bow"));

	m['a'] = aList;
	m['b'] = bList;

	map<char, list<Word>>::const_iterator iter = m.begin();

	while (iter != m.end()) {
		cout << iter->first << ":" << endl;

		list<Word> temp = iter->second;
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end()) {
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}
		cout << "\n===" << endl;
		iter++;
	}
	return 0;
}