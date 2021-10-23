#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
const int MAXF = 1000010;
const int MAXN = 110;
int n;
int base[MAXN], len[MAXN], pos[MAXN];
char ans;
char f[MAXF];
char words[MAXN][MAXN];
 
void solve()
{
    int idx = 0;
    for (int i = 0; i < n; i++)
	{
        idx += (pos[i] - 1) * base[i];
    }
 
    bool same = true, has_one = false;
    for (int i = 1; i < n; i++) 
	{
        if (words[i][pos[i] - 1] != words[0][pos[0] - 1]) 
		{
            same = false;
            break;
        }
        if (pos[i] == 1) 
		{
            has_one = true;
        }
    }
 
    if (same) 
		{
        	if (has_one) 
			{
            	f[idx] = 1;
 			} 
			else 
			{
            int p_idx = idx;
            for (int i = 0; i < n; i++) 
				{
                p_idx -= base[i];
            	}
            f[idx] = f[p_idx] + 1;
        	}
    	} 
     else 
		{
		    for (int i = 0; i < n; i++) 
		    {
            	if (pos[i] == 1) continue;
            	f[idx] = max(f[idx], f[idx - base[i]]);
    		}
  		}
 
    ans = max(ans, f[idx]);
}
 
void dp(int p)
{
    if (p == n) 
    {
        return solve();
    }
 
    for (int i = 1; i <= len[p]; i++) 
	{
        pos[p] = i;
        dp(p + 1);
    }
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%s", words[i]);
        len[i] = strlen(words[i]);
    }
 
    base[0] = 1;
    for (int i = 1; i < n; i++) 
	{
        base[i] = base[i - 1] * len[i - 1];
    }
 
    dp(0);
    printf("%d\n", ans);
 
    return 0;
}

