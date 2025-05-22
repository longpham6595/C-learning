#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("MAX.INP");
    ofstream out("MAX.OUT");

    int N;
    in >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i)
    {
        in >> X[i];
    }
    for (int i = 0; i < N; ++i)
    {
        in >> Y[i];
    }

    // Binary Search và so sánh thuần
    int max_dist = 0;
    for (int t = 0; t < N; ++t)
    {
        int low = t;
        int high = N - 1;
        int j_max = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (Y[mid] >= X[t])
            {
                j_max = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (j_max != -1)
        {
            int current_dist = j_max - t;
            if (current_dist > max_dist)
            {
                max_dist = current_dist;
            }
        }
    }

    out << max_dist;

    return 0;
}
