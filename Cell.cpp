#include "precomp.h"
#include "cell.h"

namespace Tmpl8
{

    Cell::Cell() : min_position(), max_position(), cell_sprite(nullptr), sprite_frame(0), rectangle()
    {
    }

    Cell::Cell(vec2 min, vec2 max, Sprite* cell_sprite) : cell_sprite(cell_sprite), sprite_frame(0)
    {
        min_position = min;
        max_position = min + max;

        rectangle = Rectangle2D(min_position, max_position);
    }

    void Cell::draw(Surface* screen)
    {
        vec2 position = rectangle.min;

        const int offset_x = 23;
        const int offset_y = 137;

        cell_sprite->set_frame(sprite_frame / 10);
        cell_sprite->draw(screen, (int)(position.x - offset_x + HEALTHBAR_OFFSET), (int)(position.y - offset_y));
    }

} // namespace Tmpl8