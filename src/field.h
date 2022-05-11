#ifndef FIELD_H
#define FIELD_H

#define MIX_COUNT 5
#define MIX_MIN 3

typedef int field_sequence[max_field_value];

extern const game_field source_field;

extern const cell_pos empty_cell_begin_pos;

/* --- === --- */

void generate_game_field(game_field field);

void copy_field(const game_field source, game_field dest);

void fill_empty_pos(game_field field,
                    cell_pos* empty_cell_pos,
                    int shift_row, int shift_col);

int puzzle_solved(game_field field);

#endif