#include "Arithmetic.h"

ArithmeticCoding::ArithmeticCoding(std::vector<char> &sym, std::vector<float> &p):m_symbols(sym),m_probabilities(p),m_low(0),m_high(1),range(1){}

void ArithmeticCoding::CalcRange() {
	float low = 0;
	for (int i = 0; i < m_probabilities.size(); i++) {
		std::vector<float> tmp;
		tmp.push_back(low);
		low += m_probabilities[i];
		tmp.push_back(low);
		m_ranges.push_back(tmp);
	}

}

float ArithmeticCoding::GetLow(char symbol) {
	std::vector<char>::iterator itr = std::find(m_symbols.begin(), m_symbols.end(), symbol);
	int idx = itr - m_symbols.begin();
	return m_ranges[idx][0];
}

float ArithmeticCoding::GetHigh(char symbol) {
	std::vector<char>::iterator itr = std::find(m_symbols.begin(), m_symbols.end(), symbol);
	int idx = itr - m_symbols.begin();
	return m_ranges[idx][1];
}

void ArithmeticCoding::ArithmeticAlgorithm(std::string &word) {
	for (int i = 0; i < word.length(); i++) {
		char sym = word[i];
		float low = m_low;
		m_low = low + range * GetLow(sym);
		m_high = low + range * GetHigh(sym);
		range = m_high - m_low;
	}
}

float ArithmeticCoding::Value(std::vector<bool> code) {
	float rcode = 0;
	for(int i = 0; i < code.size(); i++){
		if (code[i] == true) rcode += pow(2, -(i + 1));
	}
	return rcode;
}

float ArithmeticCoding::GetDecimal() const
{
	float decimal = 0.0;
	for (int i = 0; i < m_code.size(); i++) {
		decimal += m_code[i] * pow(2, -(i + 1));
	}

	return decimal;
}

void ArithmeticCoding::GenCodeWords() {
	std::vector<bool> code;
	int k = 0;
	while (Value(code) < m_low) {
		code.push_back(true);
		if (Value(code) > m_high) {
			code[k] = false;
		}
		k++;
	}
	m_code = code;
}

void ArithmeticCoding::PrintCode() {
	std::cout << "0.";
	for (int i = 0; i < m_code.size(); i++) {
		if (m_code[i] == false) std::cout << "0";
		else std::cout << "1";
	}
}

std::string ArithmeticCoding::Decode()
{
	//get binary cod and convert to decimal
	float decimal = GetDecimal();
	//std::vector<std::string>::iterator itr = ;
	char symbol;
	std::string out = "";
	do {
		for (int i = 0; i < m_ranges.size(); i++) {
			symbol = m_symbols[i];
			if (GetLow(symbol) <= decimal && decimal < GetHigh(symbol)) break;
		}
		out += symbol;
		float low = GetLow(symbol);
		float high = GetHigh(symbol);
		float range = high - low;
		decimal = (decimal - low) / range;
	} while (symbol != '$');

	return out;
}
