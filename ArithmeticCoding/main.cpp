#include "Arithmetic.h"

int main() {
	std::vector<char> symbols = {'A','B','C'};
	std::vector<float> p = {0.5,0.4,0.1};
	std::string word = "BBB";
	ArithmeticCoding x_Coding(symbols, p);
	x_Coding.CalcRange();
	x_Coding.ArithmeticAlgorithm(word);
	x_Coding.GenCodeWords();
	x_Coding.PrintCode();
}
