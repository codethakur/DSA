 static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);

        int count = 1;
        int EndAns = v[0].second;

        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= EndAns) // Corrected the condition
            {
                count++;
                EndAns = v[i].second;
            }
        }
        return count;
    }
