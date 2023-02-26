#pragma once

namespace Tmpl8
{
    class Tank; //forward declare

class Cell
{
    public:
        Cell(int column, int row, vector<Tank> tanks);

        ~Cell();

        static void add_tank(Tank* tank, vector<Cell>& cells);

        int row;
        int column;
        vector<Tank>tanks;
};
} // namespace Tmpl8
