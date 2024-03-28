#include "2048.h"

void random_fill(std::vector<std::vector<int>>& field, int& zero_count) {
	/*
	Функция, которая заполняет случайным образом одну из пустых клеток на поле двойкой
	*/
	std::random_device rd;
	std::mt19937 gen(rd());
	int cnt = 0;
	for (const std::vector<int>& row : field) {
		for (int el : row) {
			if (el == 0) {
				cnt++;
			}
		}
	}
	zero_count = cnt;
	if (!cnt) {
		return;
	}
	int replace_pos = gen() % cnt;
	int cnt_other = 0;
	for (std::vector<int>& row : field) {
		for (int i = 0; i < row.size(); i++) {
			if (row[i] == 0) {
				if (cnt_other == replace_pos) {
					row[i] = 2;
				}
				cnt_other++;
			}
		}
	}
}