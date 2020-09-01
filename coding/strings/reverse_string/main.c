#include <stdio.h>
#include <string.h>

int main(void)
{
    char s_temp[100] = "Ri D Bi Li U U Fi L L F U Fi D D U Li Bi Li Ri F F U Bi L D L L R D D Fi D D B B Li B D";
    char s[100];
    int s_len;

    s_len = strlen(s_temp);
    printf("\n%s\n", s_temp);

    /* Reverse formula string */
    for (int i = 0, j = s_len - 1; (i < j) && (j > i); i++, j--)
    {
        char c_temp = s_temp[i];
        s_temp[i] = s_temp[j];
        s_temp[j] = c_temp;
    }

    printf("\n%s\n", s_temp);

    /* Reverse each step */
    int i=0,j=0;
    while (i < s_len)
    {
        switch (s_temp[i])
        {
        case ' ':
            s[j++] = ' ';
            i++;
            break;

        case 'i':
            s[j++] = s_temp[++i];
            i++;
            break;

        default:
            s[j++] = s_temp[i++];
            s[j++] = 'i';
            break;
        }
    }
    printf("\n%s\n", s);
    return 0;
}