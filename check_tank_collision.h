#pragma once

#ifndef CHECK_TANK_COLLISION_H
#define CHECK_TANK_COLLISION_H

bool check_tank_collision(vector<Tank> tanks);
int* find_surrounding_cells(int col, int row, int index);

#endif
