#include "precomp.h" // include (only) this in every .cpp file

bool check_tank_collision(vector<Tank> tanks) {

    //Check tank collision and nudge tanks away from each other
    for (Tank& tank : tanks)
    {
        if (tank.active)
        {
            // Intialize 9 arrays with 2 options.
            int cells[9][2];

            // Tank original position
            int tank_col_or = tank.cell->column;
            int tank_row_or = tank.cell->row;

            //cout << tank.position.x << " " << tank.position.y << endl;

            // Tank starting position
            int tank_col = tank_col_or - 1;
            int tank_row = tank_row_or - 1;

            for (int j = 0;j < 9;++j) {
                if (j == 3 || j == 6) {
                    ++tank_row;
                    tank_col = tank_col_or - 1;
                }

                cells[j][0] = tank_col;
                cells[j][1] = tank_row;
                tank_col++;
            }
        }
    }

    return true;
}

//for (int j = 0;j < 8;++j) {
//
//}

//for (Tank& other_tank : tanks)
//{
//    if (&tank == &other_tank || !other_tank.active) continue;
//
//    vec2 dir = tank.get_position() - other_tank.get_position();
//    float dir_squared_len = dir.sqr_length();
//
//    float col_squared_len = (tank.get_collision_radius() + other_tank.get_collision_radius());
//    col_squared_len *= col_squared_len;
//
//    if (dir_squared_len < col_squared_len)
//    {
//        tank.push(dir.normalized(), 1.f);
//    }
//}