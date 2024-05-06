#ifndef RESULT_OUTPUT_H
#define RESULT_OUTPUT_H

void print_results(int row[9], int sub[9], int col[9], int counter);
void print_row_threads_results(int row[9], int sub[9]);
void print_row_thread_results(int row[9], int sub[9], int index);
void print_col_thread_results(int col[9]);
void print_result_end(int invalidCount);

#endif
