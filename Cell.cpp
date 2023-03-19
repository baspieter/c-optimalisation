#include "precomp.h"
#include "cell.h"

namespace Tmpl8
{

    Cell::Cell(int index, int column, int row, vector<int> tank_indices) : index(index), column(column), row(row), tank_indices(tank_indices)
    {
    }

    Cell::~Cell()
    {
    }

    Cell* Cell::find_cell_for_tank(int pos_x, int pos_y, vector<Cell>& cells)
    {
        int tank_col = pos_x / CELL_WIDTH;
        int tank_row = pos_y / CELL_HEIGHT;

        vector<Cell>::iterator cell_iterator;
        cell_iterator = std::find_if(cells.begin(), cells.end(), [&tank_col, &tank_row](Cell& cell) { return cell.column == tank_col && cell.row == tank_row; });
        if (cell_iterator != cells.end()) {
            return &(*cell_iterator);
        }

        int cell_index = cells.size();
        Cell new_cell = Cell(cell_index, tank_col, tank_row, {});
        cells.push_back(new_cell);
        return &cells.back();
    }

    // Update tank cells when tanks move.
    void Cell::check_or_update_cell(Tank& tank, vector<Cell>& cells, vector<Tank>& tanks)
    {
        int tank_col = tank.position.x / CELL_WIDTH;
        int tank_row = tank.position.y / CELL_HEIGHT;

        Cell& cell = cells.at(tank.cell_index);
        
        // Return when tank is still in the same cell.
        if (cell.row == tank_row && cell.column == tank_col) return;

        cell.tank_indices.erase(remove_if(cell.tank_indices.begin(), cell.tank_indices.end(), [tank](int tank_index) { return tank.index == tank_index; }), cell.tank_indices.end());

        Cell* new_cell = Cell::find_cell_for_tank(tank_col, tank_row, cells);
        tank.cell_index = new_cell->index;
        new_cell->tank_indices.push_back(tank.index);
    }

} // namespace Tmpl8