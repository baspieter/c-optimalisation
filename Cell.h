#pragma once

namespace Tmpl8
{
    class Tank; //forward declare

class Cell
{
    public:
        Cell(int column, int row, vector<Tank*> tanks);

        ~Cell();

        static Cell* find_cell_for_tank(int pos_x, int pos_y, vector<Cell>& cells);
        void update_cell_for_tank(Tank tank, vector<Cell>& cells);

        int row;
        int column;
        vector<Tank*>tanks;
};
} // namespace Tmpl8
