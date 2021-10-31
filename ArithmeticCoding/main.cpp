#include "Arithmetic.h"

int main() {
	std::vector<char> symbols = {'A','B','$'};
	std::vector<float> p = {0.5,0.4,0.1};
	std::string word = "BB$";
	ArithmeticCoding x_Coding(symbols, p);
	x_Coding.CalcRange();
	x_Coding.ArithmeticAlgorithm(word);
	x_Coding.GenCodeWords();
	x_Coding.PrintCode();

	std::cout << "\t Decode result : " << x_Coding.Decode() << std::endl;

	return 0;
}
