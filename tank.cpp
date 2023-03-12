#include "precomp.h"
#include "tank.h"


namespace Tmpl8
{
Tank::Tank(
    float pos_x,
    float pos_y,
    allignments allignment,
    Cell* cell,
    Sprite* tank_sprite,
    Sprite* smoke_sprite,
    float tar_x,
    float tar_y,
    float collision_radius,
    int health,
    float max_speed)
    : position(pos_x, pos_y),
      allignment(allignment),
      target(tar_x, tar_y),
      health(health),
      collision_radius(collision_radius),
      max_speed(max_speed),
      force(0, 0),
      reload_time(1),
      reloaded(false),
      speed(0),
      active(true),
      current_frame(0),
      cell(cell),
      tank_sprite(tank_sprite),
      smoke_sprite(smoke_sprite)
{
}

Tank::~Tank()
{
}

void Tank::tick(Terrain& terrain)
{
    vec2 direction = vec2(0, 0);

    if (target != position)
    {
        direction = (target - position).normalized();
    }

    //Update using accumulated force
    speed = direction + force;
    position += speed * max_speed * 0.5f;

    //Update reload time
    if (--reload_time <= 0.0f)
    {
        reloaded = true;
    }

    force = vec2(0.f, 0.f);

    if (++current_frame > 8) current_frame = 0;

    //Target reached?
    if (current_route.size() > 0)
    {
        if (std::abs(position.x - target.x) < 8.f && std::abs(position.y - target.y) < 8.f)
        {
            target = current_route.at(0);
            current_route.erase(current_route.begin());
        }
    }
}

void Tank::set_route(const std::vector<vec2>& route)
{
    if (route.size() > 0)
    {
        current_route = route;
        target = current_route.at(0);
        current_route.erase(current_route.begin());
    }
    else
    {
        target = position;
    }
}

void Tank::check_or_update_cell(vector<Cell>& cells)
{
    int tank_col = position.x / CELL_WIDTH;
    int tank_row = position.y / CELL_HEIGHT;

    if (tank_col != cell->column || tank_row != cell->row)
    {
        Cell* new_cell = Cell::find_cell_for_tank(position.x, position.y, cells);
        cout << "Old cell: " << cell->column << cell->row;
        cout << " New cell: " << new_cell->column << new_cell->row << endl;
    }
}

//Start reloading timer
void Tank::reload_rocket()
{
    reloaded = false;
    reload_time = 200.0f;
}

void Tank::deactivate()
{
    active = false;
}

//Remove health
bool Tank::hit(int hit_value)
{
    health -= hit_value;

    if (health <= 0)
    {
        this->deactivate();
        return true;
    }

    return false;
}

//Draw the sprite with the facing based on this tanks movement direction
void Tank::draw(Surface* screen)
{
    vec2 direction = (target - position).normalized();
    tank_sprite->set_frame(((abs(direction.x) > abs(direction.y)) ? ((direction.x < 0) ? 3 : 0) : ((direction.y < 0) ? 9 : 6)) + (current_frame / 3));
    tank_sprite->draw(screen, (int)position.x - 7 + HEALTHBAR_OFFSET, (int)position.y - 9);
}

//Add some force in a given direction
void Tank::push(vec2 direction, float magnitude)
{
    force += direction * magnitude;
}

} // namespace Tmpl8