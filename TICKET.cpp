#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct request
{
    int x, y, pos;
};

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

bool compare(request a, request b)
{
    if(a.x == b.x)
        return a.y < b.y;

    return a.x < b.x;
}

struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};

void showpq(
    priority_queue<ii, vector<ii>, myComp> g)
{
    // Loop to print the elements
    // of the priority queue
    while (!g.empty()) {
        cout << g.top().first
             << " " << g.top().second
             << endl;
        g.pop();
    }
    // cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("TICKET.inp", "r", stdin);
    // freopen("TICKET.out", "w", stdout);

    int n, k, m;
    cin >> n >> k >> m;

    // vector<ii> a;
    request a[n + 8];    
    int res[m + 8] = {0};

    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].pos = i;
    }

    // sort(a.begin(), a.end(), sortbysec);

    sort(a, a + m, compare);

    // for(int i = 0; i < m; i++)
    //     cout << a[i].x << " " << a[i].y << " " << a[i].pos << "\n";

    priority_queue<ii, vector<ii>, myComp> pq;

    int checking_pos = 0; 

    for(int i = 0; i < n; i++)
    {
        int t = pq.size();
        
        // cout << i << "\n";


        while(t--)
        {
            if(pq.top().second == i)
            {
                // cout << i << " " << pq.top().first << " " << pq.top().second << "\n";
                // cout << "pop please";
                pq.pop();
            }
        }


        while(pq.size() < k && a[checking_pos].x == i)
        {
            // cout << pq.size() << " ";
            pq.push(make_pair(a[checking_pos].x, a[checking_pos].y));
            
            // cout << 1 << "\n";

            res[a[checking_pos].pos] = 1;
            // cout << a[checking_pos].pos << "\n";
            checking_pos++;
        }
        
        while(a[checking_pos].x == i)
        {
            checking_pos++;
        } 

        // checking_pos++;

        // showpq(pq);

        
    }

    for(int i = 0; i < m; i++)
        cout << res[i] << "\n";

    // cout << checking_pos;
    // for(int i = )

    return 0;
}