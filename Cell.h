#pragma once

namespace Tmpl8
{
    class Tank; //forward declare

class Cell
{
    public:
        Cell(int column, int row, vector<Tank>tanks);
        int column;
        int row;
        vector<Tank> tanks = {};

        void add_tank(Tank tank);
};
} // namespace Tmpl8
