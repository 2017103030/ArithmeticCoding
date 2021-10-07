#include <vector>
#include <string>
#include <iostream>
class ArithmeticCoding {
private:
	//Arithmetic Codig range low
	float m_low;
	//Arithmetic Coding range high
	float m_high;
	//Arithmetic Coding range
	float range;
	//Arithmetic Coding result
	std::vector<bool> m_code;
	//vector which has every symbol
	std::vector<char> m_symbols;
	//vector which has every probability
	std::vector<float> m_probabilities;
	//vector which has every probability's ragne
	std::vector<std::vector<float>> m_ranges;
	//Method get Arithmetic Low value
	float GetLow(char) ;
	//Method get Arithmetic High value
	float GetHigh(char) ;
	//Method get decimal value from binray code
	float Value(std::vector<bool> code);
public:
	//constructor
	ArithmeticCoding(std::vector<char>& sym, std::vector<float>& p);
	//Method for calculating ranges
	void CalcRange();
	//Alogirhtm Calculation to target word
	void ArithmeticAlgorithm(std::string& word);
	//Generating Code from word
	void GenCodeWords();
	//Printing Encoded code
	void PrintCode();
};