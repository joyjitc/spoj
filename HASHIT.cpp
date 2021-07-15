#include <iostream>
#include <string.h>
using namespace std;
int hash_(string key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i] * (i + 1);
    }
    hash *= 19;
    hash %= 101;
    return hash;
}

int open_address(int hash, int j)
{
    return (hash + (j * j) + (23 * j)) % 101;
}

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string tab[101];
        bool del[101];
        bool exist[101];
        fill(del, del + 101, 0);
        fill(exist, exist + 101, 0);
        fill(tab, tab + 101, "");
        string ins;
        bool action; //0 ADD 1 DEL
        string key;

        for (int i = 0; i < n; i++)
        {
            //
            // int keys = 0;
            // for (int i = 0; i < 101; i++)
            // {
            //     if (exist[i] == 1)
            //     {
            //         keys++;
            //     }
            // }
            // cout << keys << "\n";

            // for (int i = 0; i < 101; i++)
            // {
            //     if (exist[i] == 1)
            //     {
            //         cout << i << ":" << tab[i] << "\n";
            //     }
            // }
            //
            cin >> ins;
            if (ins[0] == 'A')
            {
                action = 0;
            }
            else
            {
                action = 1;
            }
            key = ins.substr(4, ins.length() - 4);
            if (action == 0)
            {
                int index = hash_(key);
                if ((exist[index] == 0 || tab[index] == key) && del[index] == 0)
                {
                    tab[index] = key;
                    exist[index] = 1;
                    continue;
                }
                int new_index;
                for (int j = 1; j <= 19; j++)
                {
                    new_index = open_address(index, j);
                    if ((exist[new_index] == 0 || tab[new_index] == key) && del[new_index] == 0)
                    {
                        tab[new_index] = key;
                        exist[new_index] = 1;
                        break;
                    }
                }
            }
            else
            {
                int index = hash_(key);
                if (exist[index] == 1 && tab[index] == key)
                {
                    tab[index] = "";
                    exist[index] = 0;
                    del[index] = 1;
                    continue;
                }

                int new_index;
                for (int j = 1; j <= 19; j++)
                {
                    new_index = open_address(index, j);
                    if (exist[new_index] == 1 && tab[new_index] == key)
                    {
                        tab[new_index] = "";
                        exist[new_index] = 0;
                        del[new_index] = 1;
                        break;
                    }
                    if (del[new_index] == 0)
                        break;
                }
            }
        }

        int keys = 0;
        for (int i = 0; i < 101; i++)
        {
            if (exist[i] == 1)
            {
                keys++;
            }
        }
        cout << keys << "\n";

        for (int i = 0; i < 101; i++)
        {
            if (exist[i] == 1)
            {
                cout << i << ":" << tab[i] << "\n";
            }
        }
    }
}