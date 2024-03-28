#ifndef _2048_h
#define _2048_h

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <random>

void PrintField(const std::vector<std::vector<int>>& field);
void random_fill(std::vector<std::vector<int>>& field, int& zero_count);
int Test();

void A(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count);
void D(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count);
void W(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count);
void S(std::vector<std::vector<int>>& field, bool& game_out, int& zero_count);

#endif