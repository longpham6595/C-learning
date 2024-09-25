#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
// Define local for input and output files
// #define LOCAL
//============================================================================
// START PROGRAM
//============================================================================

long long n, m, x, y;

// Build KD-Tree for fast find minimum distance point to current point
// Create a vector of Point datatype: vector<Point> points;
//  Init by: KDTree tree(points);
struct Point
{
    double x, y;
};

struct Node
{
    Point point;
    Node *left;
    Node *right;
};

bool compareX(const Point &a, const Point &b)
{
    return a.x < b.x;
}

bool compareY(const Point &a, const Point &b)
{
    return a.y < b.y;
}

class KDTree
{
public:
    KDTree(const vector<Point> &points)
    {
        root = buildKDTree(points, 0);
    }

    Point findNearestPoint(const Point &target)
    {
        return findNearestPoint(root, target, 0, {numeric_limits<double>::max(), numeric_limits<double>::max()});
    }

    Node *root;

    Node *buildKDTree(vector<Point> points, int depth)
    {
        if (points.empty())
            return nullptr;

        int axis = depth % 2;
        if (axis == 0)
            sort(points.begin(), points.end(), compareX);
        else
            sort(points.begin(), points.end(), compareY);

        int median = points.size() / 2;
        Node *node = new Node{points[median], nullptr, nullptr};
        vector<Point> leftPoints(points.begin(), points.begin() + median);
        vector<Point> rightPoints(points.begin() + median + 1, points.end());

        node->left = buildKDTree(leftPoints, depth + 1);
        node->right = buildKDTree(rightPoints, depth + 1);

        return node;
    }

    double distance(const Point &a, const Point &b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    Point findNearestPoint(Node *node, const Point &target, int depth, Point best)
    {
        if (!node)
            return best;

        double d = distance(node->point, target);
        double bestDist = distance(best, target);

        if (d < bestDist)
        {
            best = node->point;
        }

        int axis = depth % 2;

        Node *nextBranch = nullptr;
        Node *otherBranch = nullptr;

        if ((axis == 0 && target.x < node->point.x) || (axis == 1 && target.y < node->point.y))
        {
            nextBranch = node->left;
            otherBranch = node->right;
        }
        else
        {
            nextBranch = node->right;
            otherBranch = node->left;
        }

        best = findNearestPoint(nextBranch, target, depth + 1, best);

        if ((axis == 0 && abs(target.x - node->point.x) < bestDist) || (axis == 1 && abs(target.y - node->point.y) < bestDist))
            best = findNearestPoint(otherBranch, target, depth + 1, best);

        return best;
    }
};
// End of KD Tree

vector<Point> villagesCoor, path;

int main()
{
    fast_io;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // MAIN PROGRAM
    // Input
    cin >> n >> m;
    villagesCoor.resize(n);
    path.resize(2 * m);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        villagesCoor[i] = {x, y};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        path[i] = {x, y}, path[i + m] = {y, x};
    }

    // Init Tree
    KDTree tree(villagesCoor);
    Point target = {2, 3}, ans;
    ans = tree.findNearestPoint(target);
    cout << ans.x << " " << ans.y << endl;
    cout << tree.distance(target, ans) << endl;
    // getchar();
}