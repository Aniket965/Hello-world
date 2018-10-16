//Code by CodeLogist

#include <bits/stdc++.h>

using namespace std;

// Complete the flippingMatrix function below.
int flippingMatrix(vector<vector<int>> matrix) {
    int sum=0;
    int n=matrix.size();
    for(int i=0;i<matrix.size()/2;i++){
        for(int j=0;j<matrix[i].size()/2;j++){
        sum += max(max(max(matrix[i][j],matrix[i][n-1-j]),matrix[n-1-i][j]),matrix[n-1-i][n-1-j]);
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> matrix(2*n);
        for (int i = 0; i < 2*n; i++) {
            matrix[i].resize(2*n);

            for (int j = 0; j < 2*n; j++) {
                cin >> matrix[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
