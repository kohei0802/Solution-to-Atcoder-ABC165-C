#include <iostream>
#include <vector> 
using namespace std;

//calculate score of an array A instance
int scr(const vector<int>&, const vector<vector<int>>&);

//iterates permutation of array A 
// rec(current vector A, lower limit of A's element, upper limit of A's element, length limit of A, array of the queries input); 
int rec(vector<int>&, const int, const int, const int, 
const vector<vector<int>>&);

int main()
{
    int N, M, Q; cin>>N>>M>>Q;
    
    //qs stores queries
    vector<vector<int>> qs(Q, vector<int>(4, 0));
    for (int i=0; i<Q; i++) {
        cin>>qs[i][0];
        cin>>qs[i][1];
        cin>>qs[i][2];
        cin>>qs[i][3];
    }
    
    vector<int> A;
    cout << rec(A, 1, M, N, qs) << endl;

    return 0;
}

//when main() calls rec(), uplim is M
int rec(vector<int>& A, const int lowlim, const int uplim, const int N, 
    const vector<vector<int>>& qs) {
    
    static int mx_scr = -1;
    
    if (N == 0) {
        mx_scr = max(mx_scr, scr(A, qs));
        return 0;
    }
    
    for (int i=lowlim; i<=uplim; i++) {
        A.push_back(i);
        rec(A, i, uplim, N-1, qs);
        A.pop_back();
    }
    
    return mx_scr;
}

int scr(const vector<int>& A, const vector<vector<int>>& qs) {
    int score = 0;
    for (int i=0; i<qs.size(); i++) {
        int a = qs[i][0], b = qs[i][1], c = qs[i][2], d = qs[i][3];
        score = (A[b-1] - A[a-1] == c) ? score+d : score;
    }
    
    return score;
}
