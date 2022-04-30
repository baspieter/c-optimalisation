#pragma once

namespace Tmpl8
{
    class Cell
    {
    public:
        Cell();
        Cell(vec2 min, vec2 max, Sprite* cell_sprite);

        void draw(Surface* screen);

        vec2 min_position;
        vec2 max_position;

        Rectangle2D rectangle;

        int sprite_frame;

        Sprite* cell_sprite;
    };
} // namespace Tmpl8