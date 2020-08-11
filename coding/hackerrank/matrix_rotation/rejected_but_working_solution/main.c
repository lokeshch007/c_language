#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
void print_matrix(int matrix_rows,int matrix_columns,int **matrix);

// Complete the matrixRotation function below.
void matrixRotation(int matrix_rows, int matrix_columns, int** matrix, int r) {

				int i=0,j=0;
				int circles=0,rotate=r;
				int hor_line=0,ver_line=0,line_length=0,i_line=0,j_line=0,i_line_backup=0,j_line_backup=0;
				int row_start=0,col_start=0;
				int circle_row_end=0,circle_col_end=0;
				int temp=0;

				print_matrix(matrix_rows,matrix_columns,matrix);
				/*nxn matrix*/
				if(!(matrix_rows^matrix_columns))
				{
								circles=matrix_rows/2;
				}
				/* mxn matrix*/
				else
				{
								/* circles are calculated on least of rows and columns */
								if(matrix_rows<matrix_columns)
								{
												circles=matrix_rows/2;
								}
								else
								{
												circles=matrix_columns/2;
								}
				}


				/* line remaining 
					 x x x x x x 
					 x - - - - x
					 x x x x x x    */
				if(matrix_rows > matrix_columns)
				{
								/* Verticle line exists  */
								ver_line=1;
								line_length=matrix_rows-(circles*2);
								i_line=circles;
				}
				else if(matrix_rows < matrix_columns)
				{
								/* Horizontal line exists */
								hor_line=1;
								line_length=matrix_columns-(circles*2);
								j_line=circles;
				}

				while(circles > 0)
				{
								row_start=circles-1;
								col_start=circles-1;
								circles--;
								rotate=r;
								while(rotate > 0)
								{
												i=row_start;
												j=col_start;
												circle_row_end=matrix_rows-1-row_start;
												circle_col_end=matrix_columns-1-col_start;
												temp=matrix[i][j];
												/*left column down shift*/
												while(i<=circle_row_end)
												{
																if(!(i^(circle_row_end)))
																{
																				/* stops at down end of vertical row */
																				break;
																}
																matrix[i+1][j] += temp;
																temp = matrix[i+1][j]-temp;
																matrix[i+1][j] -= temp;
																i++;
												}
												

												/*bottom column right shift*/
												while(j<=circle_col_end)
												{
																if(!(j^(circle_col_end)))
																{
																				/* stops at end of left of bottom column */
																				break;
																}
																matrix[i][j+1] += temp;
																temp = matrix[i][j+1]-temp;
																matrix[i][j+1] -= temp;
																j++;
												}

												/* right row top shift */
												while(i>=row_start)
												{
																if(!(i^row_start))
																{
																				/* stops at top end of right row */
																				break;
																}
																matrix[i-1][j] += temp;
																temp = matrix[i-1][j]-temp;
																matrix[i-1][j] -= temp;
																i--;
												}

												/* top column left shift */
												while(j >= col_start)
												{
																if(!(j^col_start))
																{
																				/* Stops at left end of top column */
																				break;
																}
																matrix[i][j-1] += temp;
																temp = matrix[i][j-1]-temp;
																matrix[i][j-1] -= temp;
																j--;
												}
												rotate--;
								}
								
				}

				/*rotating remaining line if there */
/*				if(hor_line)
				{
								i_line=matrix_rows/2;
								j_line_backup=j_line;
								temp=matrix[i_line][j_line];
								while(j_line < (j_line_backup+line_length))
								{
												if(!(j_line^(j_line_backup+line_length-1)))
												{
																j_line=j_line_backup;
																matrix[i_line][j_line] += temp;
																temp = matrix[i_line][j_line] - temp;
																matrix[i_line][j_line] -= temp;
																break;
												}
												matrix[i_line][j_line+1] += temp;
												temp = matrix[i_line][j_line+1]-temp;
												matrix[i_line][j_line+1] -= temp;
												j_line++;
								}
				}
				else if(ver_line)
				{
								i_line_backup=i_line;
								j_line=matrix_columns/2;
								temp=matrix[i_line][j_line];
								while(i_line < (i_line_backup+line_length))
								{
												if(!(i_line^(i_line_backup+line_length-1)))
												{
																i_line=i_line_backup;
																matrix[i_line][j_line] += temp;
																temp = matrix[i_line][j_line] - temp;
																matrix[i_line][j_line] -= temp;
																break;
												}
												matrix[i_line+1][j_line] += temp;
												temp = matrix[i_line+1][j_line]-temp;
												matrix[i_line+1][j_line] -= temp;
												i_line++;
								}
				}
				else
				{*/
								/* No line exists */
			//	}
				print_matrix(matrix_rows,matrix_columns,matrix);
				return;
}

int main()
{
				char** mnr = split_string(rtrim(readline()));

				char* m_endptr;
				char* m_str = mnr[0];
				int m = strtol(m_str, &m_endptr, 10);

				if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

				char* n_endptr;
				char* n_str = mnr[1];
				int n = strtol(n_str, &n_endptr, 10);

				if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

				char* r_endptr;
				char* r_str = mnr[2];
				int r = strtol(r_str, &r_endptr, 10);

				if (r_endptr == r_str || *r_endptr != '\0') { exit(EXIT_FAILURE); }

				int** matrix = malloc(m * sizeof(int*));

				for (int i = 0; i < m; i++) {
								*(matrix + i) = malloc(n * (sizeof(int)));

								char** matrix_item_temp = split_string(rtrim(readline()));

								for (int j = 0; j < n; j++) {
												char* matrix_item_endptr;
												char* matrix_item_str = *(matrix_item_temp + j);
												int matrix_item = strtol(matrix_item_str, &matrix_item_endptr, 10);

												if (matrix_item_endptr == matrix_item_str || *matrix_item_endptr != '\0') { exit(EXIT_FAILURE); }

												*(*(matrix + i) + j) = matrix_item;
								}
				}

				int matrix_rows = m;
				int matrix_columns = n;

				matrixRotation(matrix_rows, matrix_columns, matrix, r);

				return 0;
}

char* readline() {
				size_t alloc_length = 1024;
				size_t data_length = 0;
				char* data = malloc(alloc_length);

				while (true) {
								char* cursor = data + data_length;
								char* line = fgets(cursor, alloc_length - data_length, stdin);

								if (!line) {
												break;
								}

								data_length += strlen(cursor);

								if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
												break;
								}

								alloc_length <<= 1;

								data = realloc(data, alloc_length);

								if (!data) {
												data = '\0';

												break;
								}
				}

				if (data[data_length - 1] == '\n') {
								data[data_length - 1] = '\0';

								data = realloc(data, data_length);

								if (!data) {
												data = '\0';
								}
				} else {
								data = realloc(data, data_length + 1);

								if (!data) {
												data = '\0';
								} else {
												data[data_length] = '\0';
								}
				}

				return data;
}

char* ltrim(char* str) {
				if (!str) {
								return '\0';
				}

				if (!*str) {
								return str;
				}

				while (*str != '\0' && isspace(*str)) {
								str++;
				}

				return str;
}

char* rtrim(char* str) {
				if (!str) {
								return '\0';
				}

				if (!*str) {
								return str;
				}

				char* end = str + strlen(str) - 1;

				while (end >= str && isspace(*end)) {
								end--;
				}

				*(end + 1) = '\0';

				return str;
}

char** split_string(char* str) {
				char** splits = NULL;
				char* token = strtok(str, " ");

				int spaces = 0;

				while (token) {
								splits = realloc(splits, sizeof(char*) * ++spaces);

								if (!splits) {
												return splits;
								}

								splits[spaces - 1] = token;

								token = strtok(NULL, " ");
				}

				return splits;
}

void print_matrix(int matrix_rows,int matrix_columns,int **matrix)
{
				int i=0,j=0;
				printf("\n");
				for(i=0;i<matrix_rows;i++)
				{
								for(j=0;j<matrix_columns;j++)
								{
												printf("%d\t",matrix[i][j]);
								}
								printf("\n");
				}
}
