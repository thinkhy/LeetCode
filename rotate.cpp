#include <iostream>
#include <vector>
#include <string>
using namespace std;

    class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
           int dim = matrix.size(); 
           int m,n,tmp,next;
           for(int i = 0; i < dim; i++) {
               for(int j = i; j < dim-1-i; j++) {
                   m = i;
                   n = j;
                   tmp;
                   next = matrix[m][n];

                   for(int k = 0; k < 4; k++) {
                       tmp = matrix[n][dim-1-m];
                       matrix[n][dim-1-m] = next;
                       next = tmp; 

                       tmp=m;
                       m = n;
                       n = dim - 1 - tmp;
                   }
               }
           }
        }
    };

int main() {
    Solution s;
    vector< vector<int> > matrix;
    int dim=2;
    int cnt=0;
    matrix.resize(dim);
    for(int i=0; i<dim; i++) {
        matrix[i].resize(dim);
        for(int j=0; j<dim; j++) {
            matrix[i][j] = cnt++;
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    s.rotate(matrix);

    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) 
            cout << matrix[i][j] << "  ";
        cout << endl;
    }

    dim=1;
    cnt=0;
    matrix.resize(dim);
    for(int i=0; i<dim; i++) {
        matrix[i].resize(dim);
        for(int j=0; j<dim; j++) {
            matrix[i][j] = cnt++;
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    s.rotate(matrix);

    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) 
            cout << matrix[i][j] << "  ";
        cout << endl;
    }

    dim=3;
    cnt=0;
    matrix.resize(dim);
    for(int i=0; i<dim; i++) {
        matrix[i].resize(dim);
        for(int j=0; j<dim; j++) {
            matrix[i][j] = cnt++;
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    s.rotate(matrix);

    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) 
            cout << matrix[i][j] << "  ";
        cout << endl;
    }

    dim=4;
    cnt=0;
    matrix.resize(dim);
    for(int i=0; i<dim; i++) {
        matrix[i].resize(dim);
        for(int j=0; j<dim; j++) {
            matrix[i][j] = cnt++;
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    s.rotate(matrix);

    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) 
            cout << matrix[i][j] << "  ";
        cout << endl;
    }





    return 0;
}
