#pragma once

#ifndef CHECK_TANK_COLLISION_H
#define CHECK_TANK_COLLISION_H

void check_tank_collision(Tank& tank, vector<Tank>& tanks, vector<Cell>& cells);
vector<Cell> find_surrounding_cells(Tank tank, vector<Cell>& cells);

#endif
