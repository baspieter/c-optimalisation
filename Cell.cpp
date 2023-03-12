#include "precomp.h"
#include "cell.h"

namespace Tmpl8
{

    Cell::Cell(int column, int row, vector<Tank*> tanks) : column(column), row(row), tanks(tanks)
    {
    }

    Cell::~Cell()
    {
    }

    Cell* Cell::find_cell_for_tank(int pos_x, int pos_y, vector<Cell>& cells)
    {
        int tank_col = pos_x / CELL_WIDTH;
        int tank_row = pos_y / CELL_HEIGHT;
        
        for (int i = 0; i < cells.size(); i++) {
            if (cells[i].column == tank_col && cells[i].row == tank_row)
            {
                return &cells[i];
            }
        }

        Cell new_cell = Cell(tank_col, tank_row, {});
        cells.push_back(new_cell);
        return &cells.back();
    }

} // namespace Tmpl8