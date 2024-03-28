#include "2048.h"

void PrintField(const std::vector<std::vector<int>>& field) {
	/*
	�������, ������� �������� ������� ���� � �������
	����� �������������� ��� �������, ��� ���� ���-�� ����� ������� �������� � 2048 � ���������
	*/
	std::cout << std::endl;
	for (const std::vector<int>& row : field) {
		for (int val : row) {
			std::cout << val << "\t";
		}
		std::cout << std::endl;
	}
}