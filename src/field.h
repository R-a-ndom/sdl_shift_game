#ifndef FIELD_H
#define FIELD_H

extern const game_field source_field;

extern const cell_pos empty_cell_begin_pos;

void copy_field(const game_field source, game_field dest);

void fill_empty_pos(game_field field,
                    cell_pos* empty_cell_pos,
                    int shift_row, int shift_col);

#endif