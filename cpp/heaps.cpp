#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Data structure to store a heap node

struct Node{
    int val, i, index;
};

// Comparison object to be used to order the min-heap
struct comp{
    bool operator()(const Node &lhs, const Node &rhs) const {
        return lhs.val > rhs.val;
    }
};

// Function to merge M sorted listes each of size N 
// print them in ascending order 

void printSorted(vector<vector<int>> lists){
    // create an empty min-heap
    priority_queue<Node, vector<Node>, comp> pq;
 
    // push the first element of each list into the min-heap
    // along with the list number and their index in the list
    for (int i = 0; i < lists.size(); i++) {
        pq.push({lists[i][0], i, 0});
    }
 
    // run till min-heap is empty
    while (!pq.empty())
    {
        // extract the minimum node from the min-heap
        Node min = pq.top();
        pq.pop();
 
        // print the minimum element
        cout << min.val << " ";
 
        // take the next element from the "same" list and
        // insert it into the min-heap
        if (min.index + 1 < lists[min.i].size())
        {
            min.index += 1;
            min.val = lists[min.i][min.index];
            pq.push(min);
        }
    }
}


int main(){
    // M lists of size N , each in the form of 2D-matrix
    vector<vector<int>> lists =
    {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 27, 29, 37, 48 },
        { 32, 33, 39, 50 },
        { 16, 18, 22, 28 }
    };

    printSorted(lists);

    
    return 0;


}