#include "precomp.h"
#include "cell.h"

namespace Tmpl8
{

    Cell::Cell(int column, int row, vector<Tank> tanks) : column(column), row(row), tanks(tanks)
    {
    }

    Cell::~Cell()
    {
    }

    void Cell::add_tank(Tank* tank, vector<Cell>& cells)
    {
        int tank_col = tank->position.x / CELL_WIDTH;
        int tank_row = tank->position.y / CELL_HEIGHT;

        for (Cell& cell : cells) {
            if (cell.column == tank_col && cell.row == tank_row)
            {
                cell.tanks.push_back(*tank);
                tank->update_cell(&cell);
                return;
                
            }
        }
        Cell new_cell = Cell(tank_col, tank_row, { *tank });
        cells.push_back(new_cell);
        tank->update_cell(&new_cell);
    }

} // namespace Tmpl8