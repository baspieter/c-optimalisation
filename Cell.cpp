#include "precomp.h"
#include "cell.h"

namespace Tmpl8
{

    Cell::Cell(int column, int row, vector<Tank> tanks = {})
    {
    }

    void Cell::add_tank(Tank tank, vector<Cell> cells)
    {
        int cell_col = tank.position.x / CELL_WIDTH;
        int cell_row = tank.position.y / CELL_HEIGHT;
        bool finished = false;

        for (Cell& cell : cells) {
            if (cell.column == cell_col && cell.row == cell_row)
            {
                cell.tanks.push_back(tank);
                finished = true;
            }
        }

        if (finished == false)
        {
            cells.push_back(Cell(cell_col, cell_row, { tank }));
        }  
    }

    void Cell::check_cells(vector<Cell> cells)
    {
        cout << "Tick" << endl;
        int count = 1;
        for (Cell& cell : cells) {
            cout << "Cell: " << count << " got: " << cell.tanks.size() << " tanks" << endl;
        }
    }

} // namespace Tmpl8