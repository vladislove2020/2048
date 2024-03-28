#include "2048.h"

/*
Функции, описывающие ходы (свайпы, если проводить аналогию с игрой на смартфоне)
W - вверх, A - влево, S - вниз, D - вправо
*/

void A(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count) {
	bool action = false;
	std::deque<int> cash;
	for (int i = 0; i < field.size(); i++) {
		for (int el : field[i]) {
			cash.push_back(el);
		}
		int tmp = -1;
		std::vector<int> new_row;
		while (cash.begin() != cash.end()) {
			int current = *(cash.begin());
			cash.pop_front();
			if (current == tmp) {
				new_row.push_back(current + tmp);
				tmp = -1;
			}
			else if (current != 0) {
				if (tmp != -1) {
					new_row.push_back(tmp);
				}
				tmp = current;
			}
		}
		if (tmp != -1) {
			new_row.push_back(tmp);
		}
		while (new_row.size() < 4) {
			new_row.push_back(0);
			action = true;
		}
		field[i] = new_row;
	}
	if (action) {
		random_fill(field, zero_count);
	}
	if (!action && zero_count) {
		game_out = true;
	}
}

void D(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count) {
	bool action = false;
	std::deque<int> cash;
	for (int i = 0; i < field.size(); i++) {
		for (int el : field[i]) {
			cash.push_front(el);
		}
		int tmp = -1;
		std::vector<int> new_row(4);
		auto iter = new_row.end();
		while (cash.begin() != cash.end()) {
			int current = *(cash.begin());
			cash.pop_front();
			if (current == tmp) {
				iter--;
				*iter = (current + tmp);
				tmp = -1;
			}
			else if (current != 0) {
				if (tmp != -1) {
					iter--;
					*iter = tmp;
				}
				tmp = current;
			}
		}
		if (tmp != -1) {
			iter--;
			*iter = tmp;
		}
		while (iter != new_row.begin()) {
			iter--;
			*iter = 0;
			action = true;
		}
		field[i] = new_row;
	}
	if (action) {
		random_fill(field, zero_count);
	}
	if (!action && zero_count) {
		game_out = true;
	}
}

void W(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count) {
	bool action = false;
	std::deque<int> cash;
	for (int j = 0; j < field[0].size(); j++) {
		for (int i = 0; i < field.size(); i++) {
			cash.push_back(field[i][j]);
		}
		int i = 0;
		int tmp = -1;
		while (cash.begin() != cash.end()) {
			int current = *(cash.begin());
			cash.pop_front();
			//std::cout << "current " << current << " tmp " << tmp << std::endl;
			if (current == tmp) {
				field[i][j] = (current + tmp);
				i++;
				tmp = -1;
			}
			else if (current != 0) {
				if (tmp != -1) {
					field[i][j] = tmp;
					i++;
				}
				tmp = current;
			}
		}
		if (tmp != -1) {
			field[i][j] = tmp;
			i++;
		}
		while (i < 4) {
			field[i][j] = 0;
			i++;
			action = true;
		}
	}
	if (action) {
		random_fill(field, zero_count);
	}
	if (!action && zero_count) {
		game_out = true;
	}
}

void S(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count) {
	bool action = false;
	std::deque<int> cash;
	for (int j = 0; j < field[0].size(); j++) {
		for (int i = 0; i < field.size(); i++) {
			cash.push_front(field[i][j]);
		}
		int i = field.size();
		int tmp = -1;
		while (cash.begin() != cash.end()) {
			int current = *(cash.begin());
			cash.pop_front();
			//std::cout << "current " << current << " tmp " << tmp << std::endl;
			if (current == tmp) {
				i--;
				field[i][j] = (current + tmp);
				tmp = -1;
			}
			else if (current != 0) {
				if (tmp != -1) {
					i--;
					field[i][j] = tmp;
				}
				tmp = current;
			}
		}
		if (tmp != -1) {
			i--;
			field[i][j] = tmp;
		}
		while (i > 0) {
			i--;
			field[i][j] = 0;
			action = true;
		}
	}
	if (action) {
		random_fill(field, zero_count);
	}
	if (!action && zero_count) {
		game_out = true;
	}
}
