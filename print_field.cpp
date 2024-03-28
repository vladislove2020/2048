#include "2048.h"

void PrintField(const std::vector<std::vector<int>>& field) {
	/*
	Функция, которая печатает игровое поле в консоль
	Может использоваться для отладки, или если кто-то вдруг захочет поиграть в 2048 в терминале
	*/
	std::cout << std::endl;
	for (const std::vector<int>& row : field) {
		for (int val : row) {
			std::cout << val << "\t";
		}
		std::cout << std::endl;
	}
}
