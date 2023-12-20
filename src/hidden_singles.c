#include "hidden_singles.h"
#include "sudoku.h"
#include <stddef.h>
#include <stdlib.h>


int find_hidden_single_values(Cell **p_cells, int *hidden_single_values) {
    int counter = 0;

    for (int value = 1; value <= BOARD_SIZE; ++value) {
        int candidate_count = 0;
        Cell *hidden_single_cell = NULL;

        for (int i = 0; i <= BOARD_SIZE; ++i) {
            if (p_cells[i]->num_candidates > 1 && is_candidate(p_cells[i], value)) {
                ++candidate_count;
                hidden_single_cell = p_cells[i];
            }
        }

        if (candidate_count == 1) {
            hidden_single_values[counter++] = value;
            /*chỉ mới tìm value thôi không gán vào cell*/
            //hidden_single_cell->value = value;
            //hidden_single_cell->num_candidates = 1;
        }
    }

    return counter;
}

//find hidden single cells in a group (row, column, or box)
void find_hidden_single(Cell **p_cells, HiddenSingle *p_hidden_singles, int *p_counter) {
    int* hidden_single_values = malloc(sizeof(int)*BOARD_SIZE);
    int num_hidden_singles = find_hidden_single_values(p_cells, hidden_single_values);

    for (int i = 0; i < num_hidden_singles; ++i) {
        // find cell that contain hidden value
        Cell *p_cell;

        /*lỗi bị vòng lặp 2 lần nên in ra kq count=2 */
        //p_hidden_singles[*p_counter].p_cell->value = hidden_single_values[i];
        //p_hidden_singles[*p_counter].p_cell->num_candidates = 1;

        /*tạo 1 vòng lặp để xét từng cell, khi gặp hidden value thì 
        xác định hidden single value đó ở cell nào ở cell nào*/
        p_hidden_singles[*p_counter] = {p_cell, value};
        (*p_counter)++;
    }

    free(hidden_single_values);
}

// Function to find hidden single cells in a board, return the number of hidden single cells
int hidden_singles(SudokuBoard *p_board) {
   HiddenSingle hidden_singles[BOARD_SIZE * BOARD_SIZE];
    int counter = 0;
    
    // Check hidden singles in each cell
    for (int i = 0; i < BOARD_SIZE; ++i) {    
    // Check hidden singles in each row
        for (int k = 0; k < BOARD_SIZE; ++i) {
            find_hidden_single(p_board->p_rows[i], hidden_singles, &counter);
             // Check hidden singles in each column
                for (int e = 0; e < BOARD_SIZE; ++i) {
                    find_hidden_single(p_board->p_cols[i], hidden_singles, &counter);
            // Check hidden singles in each box
                    for (int f = 0; f < BOARD_SIZE; ++i) {
                        find_hidden_single(p_board->p_boxes[i], hidden_singles, &counter);
                                    }
                                        }
                                            }

                                                }
    return counter;
    }

