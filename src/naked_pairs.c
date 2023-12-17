#include "naked_pairs.h"
#include "sudoku.h"
#include <stddef.h>

bool is_candidate(Cell *cell, int value)
{
    return cell->candidates[value - 1] == 1;
}
bool apply_constraint(Cell **p_cells, int value)
{
    bool ret = false;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (p_cells[i]->num_candidates > 1)
        {
            if (is_candidate(p_cells[i], value))
            {
                unset_candidate(p_cells[i], value);
                ret = true;
            }
        }
    }
    return ret;
}
void unset_candidate(Cell *cell, int value)
{
    cell->candidates[value - 1] = 0;
    cell->num_candidates -= 1;
}

int naked_pairs(SudokuBoard *p_board) {
  // Counter for changes made using Naked Pairs
  int changes_made = 0;

  // Loop through each row, column, and box
  for (int unit_type = 0; unit_type < 3; unit_type++) {
    for (int unit_index = 0; unit_index < BOARD_SIZE; unit_index++) {
      Cell **cells;
      // Access the current unit (row, column, or box)
      if (unit_type == 0) {
        cells = p_board->p_rows[unit_index];
      } else if (unit_type == 1) {
        cells = p_board->p_cols[unit_index];
      } else {
        cells = p_board->p_boxes[unit_index];
      }

      // Track potential Naked Pairs
      int pair_value1 = 0;
      int pair_value2 = 0;
      int pair_count1 = 0;
      int pair_count2 = 0;

      // Loop through each cell in the unit
      for (int i = 0; i < BOARD_SIZE; i++) {
        Cell *cell = cells[i];

        // If the cell is already solved, skip it
        if (cell->value) continue;

        // Find potential pair candidates
        for (int value = 1; value <= BOARD_SIZE; value++) {
          if (is_candidate(cell, value)) {
            if (value == pair_value1) {
              pair_count1++;
            } else if (value == pair_value2) {
              pair_count2++;
            } else {
              // New potential pair candidate
              pair_value1 = value;
              pair_count1 = 1;
              pair_value2 = 0;
              pair_count2 = 0;
            }
          }
        }

        // Check if a Naked Pair is found
        if (pair_count1 == 2 && pair_count2 == 0) {
          // Remove the pair candidates from other cells in the unit
          for (int j = 0; j < BOARD_SIZE; j++) {
            if (i != j && is_candidate(cells[j], pair_value1)) {
              changes_made += apply_constraint(cells, pair_value1);
            }
          }
        } else if (pair_count1 == 0 && pair_count2 == 2) {
          changes_made += apply_constraint(cells, pair_value2);
        }
      }
    }
  }

  return changes_made;
}