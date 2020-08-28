#include <stdio.h>

#define OLL1 "xxxxyxxxxxyxyyyxyxyyy"
#define OLL2 "xxxxyxxxxyyyxyyxyxyyx"
#define OLL3 "yxxxyxxxxxyxyyxyyxyyx"
#define OLL4 "xxyxyxxxxxyxxyyxyyxyy"
#define OLL5 "yyxyyxxxxxxxyyxyyxyxx"
#define OLL6 "xyyxyyxxxxxxxxyxyyxyy"
#define OLL7 "xxyxyyxyxyyxxxxyxxyyx"
#define OLL8 "yxxyyxxyxxyyxyyxxyxxx"
#define OLL9 "xyxyyxxxyxxyxyxxyyxxy"
#define OLL10 "xyxxyyyxxyxxyxxyyxxyx"
#define OLL11 "xxxxyyyyxyyxyxxyxxxyx"
#define OLL12 "xxxyyxxyyxyyxyxxxyxxy"
#define OLL13 "xxxyyyyxxyyxyxxyyxxxx"
#define OLL14 "xxxyyyxxyxyyxxxxyyxxy"
#define OLL15 "xxxyyyxxyyyxyxxxyxyxx"
#define OLL16 "xxxyyyyxxxyyxxyxyxxxy"
#define OLL17 "yxxxyxxxyxyyxyxxyxyyx"
#define OLL18 "yxyxyxxxxxyxxyxyyyxyx"
#define OLL19 "xxxxyxyxyxyxyyxxyxxyy"
#define OLL20 "yxyxyxyxyxyxxyxxyxxyx"
#define OLL21 "xyxyyyxyxyxyxxxyxyxxx"
#define OLL22 "xyxyyyxyxxxyxxxyxxyxy"
#define OLL23 "yyyyyyxyxxxxxxxyxyxxx"
#define OLL24 "xyyyyyxyyyxxxxxxxyxxx"
#define OLL25 "yyxyyyxyyxxxyxxxxyxxx"
#define OLL26 "xyxyyyxyyxxyxxxxxyxxy"
#define OLL27 "xyxyyyyyxyxxyxxyxxxxx"
#define OLL28 "yxyxyyyyyxyxxxxxxxxyx"
#define OLL29 "yxyyyxxyxxyxxyyxxxyxx"
#define OLL30 "yxyxyyxyxxyxxxyxxxyyx"
#define OLL31 "xyyxyyxxyyxxxxxxyyxyx"
#define OLL32 "yyxyyxyxxxxyxyxyyxxxx"
#define OLL33 "xxyyyyxxyyyxxxxxyyxxx"
#define OLL34 "xxxyyyyxyxyxyxxxyxxxy"
#define OLL35 "yxxxyyxyyxyxyxxxxyxyx"
#define OLL36 "yxxyyxxyyxyxyyxxxyxxx"
#define OLL37 "yyxyyxxxyxxxyyxxyyxxx"
#define OLL38 "xxyxyyyyxxyxxxxyxxxyy"
#define OLL39 "xxyyyyyxxyyxxxyxyxxxx"
#define OLL40 "yxxyyyxxyxyyxxxxyxyxx"
#define OLL41 "yxyyyxxyxxyxxyxyxyxxx"
#define OLL42 "yxyxyyxyxxyxxxxyxyxyx"
#define OLL43 "xyyxyyxxyxxxxxxxyxyyy"
#define OLL44 "yyxyyxyxxxxxyyyxyxxxx"
#define OLL45 "xxyyyyxxyxyxxxxxyxyxy"
#define OLL46 "yyxxyxyyxxxxyyyxxxxyx"
#define OLL47 "xyxxyyxxxyxxyxyxyyxyx"
#define OLL48 "xyxyyxxxxxxyxyxyyxyxy"
#define OLL49 "xxxyyxxyxyyxyyyxxyxxx"
#define OLL50 "xxxxyyxyxxyyxxxyxxyyy"
#define OLL51 "xxxyyyxxxyyxyxyxyyxxx"
#define OLL52 "xyxxyxxyxyxxyyyxxyxyx"
#define OLL53 "xxxyyxxyxyyyxyxyxyxxx"
#define OLL54 "xxxxyyxyxyyyxxxyxyxyx"
#define OLL55 "xyxxyxxyxxxxyyyxxxyyy"
#define OLL56 "xxxyyyxxxxyxyxyxyxyxy"
#define OLL57 "yxyyyyyxyxyxxxxxyxxxx"

#define is_yellow(colour) (((colour) == 'y') ? 1 : 0)

char OLL_case[57][22] = {OLL1, OLL2, OLL3, OLL4, OLL5, OLL6, OLL7, OLL8, OLL9, OLL10, OLL11, OLL12, OLL13, OLL14, OLL15, OLL16, OLL17, OLL18, OLL19, OLL20, OLL21, OLL22, OLL23, OLL24, OLL25, OLL26, OLL27, OLL28, OLL29, OLL30, OLL31, OLL32, OLL33, OLL34, OLL35, OLL36, OLL37, OLL38, OLL39, OLL40, OLL41, OLL42, OLL43, OLL44, OLL45, OLL46, OLL47, OLL48, OLL49, OLL50, OLL51, OLL52, OLL53, OLL54, OLL55, OLL56, OLL57};

char cube[3][3] = {{'g', 'g', 'r'}, {'o', 'y', 'y'}, {'g', 'y', 'o'}};
char cube_back[3] = {'o', 'y', 'b'};
char cube_right[3] = {'y', 'r', 'y'};
char cube_front[3] = {'b', 'b', 'r'};
char cube_left[3] = {'y', 'y', 'y'};

void swap(char *val1, char *val2)
{
	char temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void rotate_clockwise(void)
{
	/* Transpose */
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			swap(&cube[i][j], &cube[j][i]);
		}
	}

	/* Reverse rows elements */
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0, k = 3 - 1; (j < k); j++, k--)
			swap(&cube[i][j], &cube[i][k]);
	}

	char temp[3] = {cube_back[0], cube_back[1], cube_back[2]};
	cube_back[0] = cube_left[0];
	cube_back[1] = cube_left[1];
	cube_back[2] = cube_left[2];

	cube_left[0] = cube_front[0];
	cube_left[1] = cube_front[1];
	cube_left[2] = cube_front[2];

	cube_front[0] = cube_right[0];
	cube_front[1] = cube_right[1];
	cube_front[2] = cube_right[2];

	cube_right[0] = temp[0];
	cube_right[1] = temp[1];
	cube_right[2] = temp[2];
}

void print_matrix(void)
{
	printf("\n  ");
	for (int i = 0; i < 3; i++)
		printf("%c ", cube_back[i]);

	printf("\n%c ", cube_left[0]);
	for (int i = 0; i < 3; i++)
		printf("%c ", cube[0][i]);
	printf("%c\n", cube_right[2]);

	printf("\n%c ", cube_left[1]);
	for (int i = 0; i < 3; i++)
		printf("%c ", cube[1][i]);
	printf("%c\n", cube_right[1]);

	printf("\n%c ", cube_left[2]);
	for (int i = 0; i < 3; i++)
		printf("%c ", cube[2][i]);
	printf("%c\n", cube_right[0]);

	printf("  ");
	for (int i = 0; i < 3; i++)
		printf("%c ", cube_front[i]);
}

int main(void)
{
	int case_pass = -1;
	int break_case = 0;
	int three_check = 0;
	rotate_clockwise();
	rotate_clockwise();
	rotate_clockwise();

	while (three_check < 3)
	{
		printf("__%d__\n", three_check + 1);
		print_matrix();
		case_pass = -1;
		for (int i = 0; (i < 57) && (case_pass == -1); i++)
		{
			break_case = 0;
			int side_x = 0, side_y = 0, OLL_trav = 0;
			/* Checking up */
			for (side_x = 0; (side_x < 3) && (!break_case); side_x++)
			{
				for (side_y = 0; (side_y < 3) && (!break_case); side_y++, OLL_trav++)
				{
					switch (OLL_case[i][OLL_trav])
					{
					case 'x':
						if (is_yellow(cube[side_x][side_y]))
							break_case = 1;
						break;

					case 'y':
						if (!is_yellow(cube[side_x][side_y]))
							break_case = 1;
						break;
					}
				}
			}
			if (break_case)
				continue;

			/* Checking back */
			side_x = 0;
			for (int j = 9; (j <= 11) && (!break_case); j++, side_x++)
			{
				switch (OLL_case[i][j])
				{
				case 'x':
					if (is_yellow(cube_back[side_x]))
					{
						break_case = 1;
					}
					break;
				case 'y':
					if (!is_yellow(cube_back[side_x]))
					{
						break_case = 1;
					}
					break;
				}
			}
			if (break_case)
				continue;

			/* Checking right */
			side_x = 0;
			for (int j = 12; (j <= 14) && (!break_case); j++, side_x++)
			{
				switch (OLL_case[i][j])
				{
				case 'x':
					if (is_yellow(cube_right[side_x]))
					{
						break_case = 1;
					}
					break;
				case 'y':
					if (!is_yellow(cube_right[side_x]))
					{
						break_case = 1;
					}
					break;
				}
			}
			if (break_case)
				continue;

			/* Checking front */
			side_x = 0;
			for (int j = 15; (j <= 17) && (!break_case); j++, side_x++)
			{
				switch (OLL_case[i][j])
				{
				case 'x':
					if (is_yellow(cube_front[side_x]))
					{
						break_case = 1;
					}
					break;
				case 'y':
					if (!is_yellow(cube_front[side_x]))
					{
						break_case = 1;
					}
					break;
				}
			}
			if (break_case)
				continue;

			/* Checking left */
			side_x = 0;
			for (int j = 18; (j <= 20) && (!break_case); j++, side_x++)
			{
				switch (OLL_case[i][j])
				{
				case 'x':
					if (is_yellow(cube_left[side_x]))
					{
						break_case = 1;
					}
					break;
				case 'y':
					if (!is_yellow(cube_left[side_x]))
					{
						break_case = 1;
					}
					break;
				}
			}
			if (break_case)
				continue;
			else
				case_pass = i;
		}
		if (case_pass == -1)
		{
			printf("\nrotate %d\n", three_check);
			getchar();
			rotate_clockwise();
			three_check++;
		}
		else
		{
			break;
		}
	}
	printf("\ncase %d\n", case_pass);
	return 0;
}