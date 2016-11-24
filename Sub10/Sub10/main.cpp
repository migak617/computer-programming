#include <process.h>
#include <iostream>
#include "event.h"
#include "game.h"
#include "frame.h"
#include "exArray.h"
#include "swap.h"

using namespace std;


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
	*/
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
	return 0;
}