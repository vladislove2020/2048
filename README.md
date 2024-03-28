# 2048

A simple implementation of 2048 game

Initially I have written it to calculate statistics of maximum reached number in some different game strategies.

This code provides simulation of random moves in 20 launches, but you can:
- change number of launches in main.cpp (to simulate more or less games)
- change game strategy in test.cpp (to research other strategies, for example, only moves up and left)
- just use it to play 2048 game in console :)  (to do it, use print_field.cpp)

What would be useful to do:
- add different game strategies (different versions of Test() function)
- pack all functions into a class GameField with attributes zero_count and game_over
