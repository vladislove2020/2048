#include "2048.h"

int Test() {
	/*
	���� ������ ����
	���� ����������� ��������, ���� �������� ������
	���� ��������� ��� �� ���������� �������, ���� ���������� ��� 4 ��������� ����
	���� � ��� �� �������, ����������� � ����� ���������� ������� �� ����
	*/
	std::vector<std::vector<int>> field(4, std::vector<int>(4));
	bool game_out = false;
	int zero_count = 16;

	while (!game_out) {
		std::random_device rd;
		std::mt19937 gen(rd());
		int choice = gen() % 4;
		switch (choice) {
		case 0:
			W(field, game_out, zero_count);
			break;
		case 1:
			A(field, game_out, zero_count);
			break;
		case 2:
			S(field, game_out, zero_count);
			break;
		case 3:
			D(field, game_out, zero_count);
			break;
		}
		if (game_out) {
			W(field, game_out, zero_count);
			A(field, game_out, zero_count);
			S(field, game_out, zero_count);
			D(field, game_out, zero_count);
		}
	}

	int max_el = 0;
	for (const std::vector<int>& row : field) {
		for (int el : row) {
			if (el > max_el) {
				max_el = el;
			}
		}
	}

	return max_el;
}