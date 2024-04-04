//Write your code here
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000000;

// Structure representing the minimum and second minimum elements
struct MinPair {
    pair<long long, int> min1, min2;
    MinPair(long long x = INF, int idx = -1): min1({x, idx}), min2({INF, idx}) {}
};

// Function to perform operations on two MinPair structures
MinPair operate(MinPair a, MinPair b) {
    MinPair ans;
    ans.min1 = min(a.min1, b.min1);
    if (a.min1.first < b.min1.first) {
        ans.min2 = min(a.min2, b.min1);
    } else if (a.min1.first > b.min1.first) {
        ans.min2 = min(a.min1, b.min2);
    } else {
        ans.min2 = min(a.min2, b.min2);
    }
    return ans;
}

// Function to modify the elements of MinPair structure by adding a value
MinPair modify(long long x, MinPair a) {
    a.min1.first += x;
    a.min2.first += x;
    return a;
}

// Lazy Segment Tree data structure
struct LazySegmentTree {
    int size;
    vector<MinPair> tree;
    vector<long long> lazy;

    // Constructor
    LazySegmentTree(vector<MinPair> &elements) {
        int n = elements.size();
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree = vector<MinPair>(size * 2 - 1);
        for (int i = 0; i < n; i++) {
            tree[size - 1 + i] = elements[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            tree[i] = operate(tree[i * 2 + 1], tree[i * 2 + 2]);
        }
        lazy = vector<long long>(size * 2 - 1, 0);
    }

    // Push lazy updates down the tree
    void propagate(int i) {
        if (i < size - 1) {
            lazy[i * 2 + 1] += lazy[i];
            lazy[i * 2 + 2] += lazy[i];
        }
        tree[i] = modify(lazy[i], tree[i]);
        lazy[i] = 0;
    }

    // Apply range updates
    void updateRange(int left, int right, long long value, int index, int start, int end) {
        propagate(index);
        if (end <= left || right <= start) {
            return;
        } else if (left <= start && end <= right) {
            lazy[index] = value;
            propagate(index);
        } else {
            int mid = (start + end) / 2;
            updateRange(left, right, value, index * 2 + 1, start, mid);
            updateRange(left, right, value, index * 2 + 2, mid, end);
            tree[index] = operate(tree[index * 2 + 1], tree[index * 2 + 2]);
        }
    }

    // Wrapper function for applying range updates
    void updateRange(int left, int right, long long value) {
        updateRange(left, right, value, 0, 0, size);
    }

    // Get the result of all operations
    MinPair queryAll() {
        propagate(0);
        return tree[0];
    }
};

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; t++) {
        int elementsCount;
        cin >> elementsCount;
        vector<int> elements(elementsCount);
        for (int i = 0; i < elementsCount; i++) {
            cin >> elements[i];
        }

        int queriesCount;
        cin >> queriesCount;

        vector<int> leftIndices(queriesCount), rightIndices(queriesCount), values(queriesCount);
        for (int i = 0; i < queriesCount; i++) {
            cin >> leftIndices[i] >> rightIndices[i] >> values[i];
            leftIndices[i]--;
        }

        // Store queries for each update index
        vector<vector<int>> leftQueries(elementsCount + 1), rightQueries(elementsCount + 1);
        for (int i = 0; i < queriesCount; i++) {
            leftQueries[leftIndices[i]].push_back(i);
            rightQueries[rightIndices[i]].push_back(i);
        }

        // Initialize segment tree nodes
        vector<MinPair> segmentTreeNodes(queriesCount + 1);
        for (int i = 0; i <= queriesCount; i++) {
            segmentTreeNodes[i] = MinPair(0, i);
        }

        // Construct lazy segment tree
        LazySegmentTree segmentTree(segmentTreeNodes);

        // Store answers for each element
        vector<long long> answers(elementsCount);
        for (int i = 0; i < elementsCount; i++) {
            segmentTree.updateRange(0, queriesCount + 1, elements[i]);
            for (int queryIndex : leftQueries[i]) {
                segmentTree.updateRange(queryIndex + 1, queriesCount + 1, values[queryIndex]);
            }
            for (int queryIndex : rightQueries[i]) {
                segmentTree.updateRange(queryIndex + 1, queriesCount + 1, -values[queryIndex]);
            }
            answers[i] = segmentTree.queryAll().min1.first;
            
            // Remove the used queries
            while (true) {
                MinPair result = segmentTree.queryAll();
                if (result.min2.first >= INF / 2) {
                    break;
                }
                int index = result.min2.second;
                segmentTree.updateRange(index, index + 1, INF);
            }
            segmentTree.updateRange(0, queriesCount + 1, -elements[i]);
        }

        // Print answers
        for (int i = 0; i < elementsCount; i++) {
            cout << answers[i];
            if (i < elementsCount - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
