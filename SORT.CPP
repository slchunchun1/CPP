#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, c, n, t, i, j, k;
    long long x[1005][1005];
    long long y[1005], z[1005];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> x[i][j];
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a;
                if (x[i][j] == a)
                    x[i][j] = 0;
                else
                    x[i][j] = 1;
            }
        }
        y[0] = 0;
        long long d = 0;
        for (i = 0; i < n; i++)
        {
            if (x[0][i] == 0)
                z[i] = 0;
            else
                z[i] = 1;
        }
        for (i = 1; i < n; i++)
        {
            if (x[i][0] == 0)
                y[i] = z[0];
            else
                y[i] = 1 - (z[0]);
            for (j = 0; j < n; j++)
            {
                if (x[i][j] == 0)
                {
                    if (y[i] != z[j])
                        d = 1;
                    else
                    {
                        if (y[i] == z[j])
                            d = 1;
                    }
                }
            }
            if (d == 1)
            {
                cout << "-1\n";
            }
            else
            {
                long long zr, on;
                zr = on = 0;
                for (i = 0; i < n; i++)
                {
                    if (y[i] == 0)
                        zr++;
                    else
                        on++;
                    if (z[i] == 0)
                        zr++;
                    else
                        on++;
                }
                if (zr == 0 || on == 0)
                {
                    cout << "0\n";
                    continue;
                }
                if (zr < on)
                    c = 0;
                else
                    c = 1;
                vector<long long> v;
                v.clear();
                for (i = 0; i < n; i++)
                {
                    if (y[i] == c)
                        v.push_back(i);
                }
                cout << v.size() << " ";
                for (i = 0; i < v.size(); i++)
                {
                    cout << v[i] << " ";
                }
                v.clear();
                for (i = 0; i < n; i++)
                {
                    if (z[i] == c)
                        v.push_back(i);
                }
                cout << v.size() << " ";
                for (i = 0; i < v.size(); i++)
                    cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}
