#pragma once

namespace Tmpl8
{
    class Tank; //forward declare

class Cell
{
    public:
        Cell(int column, int row, vector<Tank>tanks);
        int column = 0;
        int row = 0;
        vector<Tank> tanks = {};

        static void add_tank(Tank tank, vector<Cell> cells);
        static void check_cells(vector<Cell> cells);
};
} // namespace Tmpl8
