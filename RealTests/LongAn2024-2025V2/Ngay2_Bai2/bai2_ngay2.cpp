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

long long n, m;
double x, y;
map<pair<double, double>, bool> way;

// Build KD-Tree for fast find minimum distance point to current point
// Create a vector of Point datatype: vector<Point> points;
//  Init by: KDTree tree(points);
struct Point
{
    double x, y;
    long long id;
    bool visited;
};

vector<Point> villagesCoor;

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

bool compareDist(const pair<double, Point> &a, const pair<double, Point> &b)
{
    return a.first < b.first;
}
class KDTree
{
public:
    Node *root;
    unordered_map<long long, Node *> nodeMap;
    KDTree(const vector<Point> &points)
    {
        root = buildKDTree(points, 0);
    }
    Point findNearestPoint(const Point &target)
    {
        return findNearestPoint(root, target, 0, {numeric_limits<double>::max(), numeric_limits<double>::max()});
    }

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
        nodeMap[node->point.id] = node; // Store node in the map
        vector<Point> leftPoints(points.begin(), points.begin() + median);
        vector<Point> rightPoints(points.begin() + median + 1, points.end());
        node->left = buildKDTree(leftPoints, depth + 1);
        node->right = buildKDTree(rightPoints, depth + 1);
        return node;
    }
    // Distance return 0 if there is an old way from a to b, else return sqrt((a.x - b.x)^2 + (a.y - b.y)^2)
    // if there must be a new way to be created from a to b
    double distance(const Point &a, const Point &b)
    {
        return (way[{a.id, b.id}] ? 0 : sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
    }
    // Return a closest point to the given target point, if there is an old way from target to a point that
    // is not visited then distance will be 0 and this point will be returned
    Point findNearestPoint(Node *node, const Point &target, int depth, Point best)
    {
        if (!node)
            return best;
        double d = (way[{node->point.id, target.id}] ? 0 : distance(node->point, target));
        double bestDist = (way[{best.id, target.id}] ? 0 : distance(best, target));
        if (d < bestDist && !node->point.visited && node->point.id != target.id)
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

    void markNodeVisited(long long id)
    {
        if (nodeMap.find(id) != nodeMap.end())
        {
            nodeMap[id]->point.visited = true;
        }
    }

    // Print all node
    void printVisitedNodes(Node *node)
    {
        if (!node)
            return;
        printVisitedNodes(node->left);
        std::cout << "Node ID: " << node->point.id << ", Visited: " << (node->point.visited ? "true" : "false") << std::endl;
        printVisitedNodes(node->right);
    }

    void printAllVisitedNodes()
    {
        printVisitedNodes(root);
    }
};

// End of KD Tree

// Start Prim Algorithm for minimum span tree
void PrimMST(KDTree &tree)
{
    double resDistance = 0;
    Point tempt;
    vector<Point> mst;
    vector<pair<double, Point>> minEdge;

    mst.push_back(tree.root->point);
    tree.markNodeVisited(mst[0].id);

    while (mst.size() < n)
    {
        minEdge.clear();

        for (long long i = 0; i < mst.size(); i++)
        {
            tempt = tree.findNearestPoint(mst[i]);
            minEdge.push_back({tree.distance(mst[i], tempt), tempt});
        }

        sort(minEdge.begin(), minEdge.end(), compareDist);

        mst.push_back(minEdge[0].second);
        tree.markNodeVisited(minEdge[0].second.id);

        resDistance += minEdge[0].first;
    }
    printf("%.3f\n", resDistance);
}
// End Prim Algorithm

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

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        villagesCoor[i] = {x, y, i + 1, false};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        way[{x, y}] = way[{y, x}] = true;
    }

    // Init Tree and test Tree
    KDTree tree(villagesCoor);

    // Prim
    PrimMST(tree);

    // getchar();
}