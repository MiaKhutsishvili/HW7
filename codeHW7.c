#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int n, ans[1000000];
char lang[2][1000][1000], str[1000000];
bool shrt[1000000], UorL;

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%s%s", lang[0][i], lang[1][i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; lang[0][i][j] || lang[1][i][j]; j++)
        {
            if (!lang[0][i][j])
            {
                shrt[i] = 0;
                break;
            }
            if (!lang[1][i][j])
            {
                shrt[i] = 1;
                break;
            }
        }
    char x = getchar();
    fgets (str, 1000000, stdin);
    int w = 0;
    for (int i = 0; str[i + 1]; i++)
    {
        if (!i || str[i - 1] == ' ')
        {
            for (int j = 0; j < n; j++)
            {
                bool check = 1;
                for (int k = 0; lang[0][j][k] || (str[i + k] != ' ' && str[i + k + 1]); k++)
                    if (toupper (str[i + k]) != lang[0][j][k]
                        && tolower (str[i + k]) != lang[0][j][k])
                        check = 0;
                if (check)
                {
                    ans[w] = j;
                    w++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < w; i++)
        printf ("%s ", lang[shrt[ans[i]]][ans[i]]);
    return 0;
}
