#include "2048.h"

void PrintField(const std::vector<std::vector<int>>& field) {
	/*
	‘ункци€, котора€ печатает игровое поле в консоль
	ћожет использоватьс€ дл€ отладки, или если кто-то вдруг захочет поиграть в 2048 в терминале
	*/
	std::cout << std::endl;
	for (const std::vector<int>& row : field) {
		for (int val : row) {
			std::cout << val << "\t";
		}
		std::cout << std::endl;
	}
}