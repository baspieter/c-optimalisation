#pragma once

#ifndef CHECK_TANK_COLLISION_H
#define CHECK_TANK_COLLISION_H

void check_tank_collision(vector<Tank>& tanks, vector<Cell>& cells);
vector<Cell> find_surrounding_cells(Tank tank, vector<Cell>& cells);
vector<Tank> get_all_tanks_in_surrounding_cells(vector<Cell>& surrounding_cells, Tank* current_tank, vector<Tank>& tanks);

#endif
