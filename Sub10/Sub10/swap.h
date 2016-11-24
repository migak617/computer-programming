#pragma once
template<typename S>
void mySwap(S& num1, S& num2) {
	S temp = num1;
	num1 = num2;
	num2 = temp;
}
