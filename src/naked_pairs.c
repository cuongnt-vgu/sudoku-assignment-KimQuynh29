#include "naked_pairs.h"

int naked_pairs(SudokuBoard* p_board) {return 0;}

// int naked_pairs(SudokuBoard *p_board)
// {
//     int counter = 0;

//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         for (int j = 0; j < BOARD_SIZE; j++)
//         {
//             // find cells with two candidates
//             if (p_board->data[i][j].num_candidates == 2)
//             {
//                 // check if other cells in the same row, column, or box have the same two candidates
//                 int candidates[2] = {p_board->data[i][j].candidates[0], p_board->data[i][j].candidates[1]};
//                 int other_cells[2] = {-1, -1};
//                 for (int k = 0; k < BOARD_SIZE; k++)
//                 {
//                     if (k != j && p_board->data[i][k].num_candidates == 2 &&
//                         p_board->data[i][k].candidates[0] == candidates[0] &&
//                         p_board->data[i][k].candidates[1] == candidates[1])
//                     {
//                         other_cells[0] = k;
//                         break;
//                     }
//                 }
//                 for (int k = 0; k < BOARD_SIZE; k++)
//                 {
//                     if (k != i && p_board->data[k][j].num_candidates == 2 &&
//                         p_board->data[k][j].candidates[0] == candidates[0] &&
//                         p_board->data[k][j].candidates[1] == candidates[1])
//                     {
//                         other_cells[1] = k;
//                         break;
//                     }
//                 }
//                 for (int k = 0; k < 3; k++)
//                 {
//                     for (int l = 0; l < 3; l++)
//                     {
//                         if (i / 3 == k && j / 3 == l && p_board->p_boxes[k][l][0].num_candidates == 2 &&
//                             p_board->p_boxes[k][l][0].candidates[0] == candidates[0] &&
//                             p_board->p_boxes[k][l][0].candidates[1] == candidates[1])
//                         {
//                             other_cells[0] = p_board->p_boxes[k][l][1]->index;
//                             other_cells[1] = p_board->p_boxes[k][l][2].index;
//                             break;
//                         }
//                     }
//                     if (other_cells[0] != -1 && other_cells[1] != -1)
//                         break;
//                 }

//                 // if two cells are found, set the candidates to 0 for all other cells in the same row, column, or box
//                 if (other_cells[0] != -1 && other_cells[1] != -1)
//                 {
//                     for (int k = 0; k < BOARD_SIZE; k++)
//                     {
//                         if (k != other_cells[0] && k != other_cells[1])
//                         {
//                             for (int l = 0; l < 2; l++)
//                             {
//                                 unset_candidate(&p_board->data[i][k], candidates[l]);
//                                 unset_candidate(&p_board->data[k][j], candidates[l]);
//                                 unset_candidate(&p_board->p_boxes[i / 3][j / 3][k], candidates[l]);
//                             }
//                         }
//                     }
//                     counter += 2;
//                 }
//             }
//         }
//     }

//     return counter;
// }