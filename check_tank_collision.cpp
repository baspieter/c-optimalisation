#include "precomp.h" // include (only) this in every .cpp file

void check_tank_collision(Tank& current_tank, vector<Tank>& tanks, vector<Cell>& cells) {
    vector<Cell> surrounding_cells = find_surrounding_cells(current_tank, cells);

    for (Cell& cell : surrounding_cells)
    {
        for (int tank_index : cell.tank_indices)
        {
            Tank& tank = tanks.at(tank_index);
            if (!tank.active || &current_tank == &tank) continue;

            vec2 dir = current_tank.get_position() - tank.get_position();
            float dir_squared_len = dir.sqr_length();

            float col_squared_len = (current_tank.get_collision_radius() + tank.get_collision_radius());
            col_squared_len *= col_squared_len;

            if (dir_squared_len < col_squared_len)
            {
                current_tank.push(dir.normalized(), 1.f);
            }
        }
    }
}

vector<Cell> find_surrounding_cells(Tank tank, vector<Cell> &cells)
{
    vector<Cell> surrounding_cells;
    Cell& tank_cell = cells.at(tank.cell_index);

    // Tank original position.
    int tank_col_or = tank_cell.column;
    int tank_row_or = tank_cell.row;

    // Tank most left top cell.
    int tank_col = tank_col_or - 1;
    int tank_row = tank_row_or - 1;

    for (int j = 0;j < 9;++j) {
        if (j == 3 || j == 6) {
            ++tank_row;
            tank_col = tank_col_or - 1;
        }

        if (tank_row < 0 || tank_col < 0) continue;

        vector<Cell>::iterator cell_iterator;
        cell_iterator = std::find_if(cells.begin(), cells.end(), [&tank_col, &tank_row](Cell &cell) { return cell.column == tank_col && cell.row == tank_row; });
        if (cell_iterator != cells.end()) {
            surrounding_cells.push_back((*cell_iterator));
        }

        tank_col++;
    }

    return surrounding_cells;
}
