#pragma once

namespace Tmpl8
{
    class Tank; //forward declare

class Cell
{
    public:
        Cell(int index, int column, int row, vector<int> tank_indices);

        ~Cell();

        static Cell* find_cell_for_tank(int pos_x, int pos_y, vector<Cell>& cells);
        static void check_or_update_cell(Tank& tank, vector<Cell>& cells, vector<Tank>& tanks);

        int index;
        int row;
        int column;
        vector<int>tank_indices;
};
} // namespace Tmpl8
