#include <iostream>
#include <vector>
 
using namespace std;
 
int GetDamerauLevenshteinDistance(char* A, char* B) 
{
    int n = strlen(A);
    int m = strlen(B);
    vector<vector<int>> F(n+1, vector<int>(m+1));
  
    for (int i = 0; i < n + 1; ++i) {
        F[i][0] = i;
    }
 
    for (int j = 0; j < n + 1; ++j) {
        F[0][j] = j;
    }
 
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            F[i][j] = min(F[i - 1][j], F[i][j - 1]) + 1;
            F[i][j] = min(F[i][j], F[i - 1][j - 1] + (A[i - 1] != B[j - 1]));
 
            if (i >= 2 && j >= 2 && ((A[i - 2] + A[i - 1]) == (B[j - 1] + B[j - 2]))) {
                F[i][j] = min(F[i][j], F[i - 2][j - 2] + 1);
            }
        }
    }
    return F[n][m];
}

int main() {
    char* word = "google";
    char* str = "searchtheworldsinformationincludingwebpagesimagesvideosandmorpgoogolehasmanyspecialfeaturestohelpyoufindexactlywhatyourelookinss";

    int strsize = strlen(str);
    int length = strlen(word);
    char* strword = new char[length];
    string data(str);

    unsigned int start_time = clock();
    for (int i = 0; i < length; i++)
    {
        for (int k = 0; k < strsize; k++)
        {
            if (str[k] == word[i])
            {
                if ((k - i) < 0 || (k - i + length) > strsize) continue;
                string strword = data.substr(k - i, length);
                int dist = GetDamerauLevenshteinDistance(word, &strword[0]);
                cout << strword << "[" << dist << "]" << endl;
            }
        }
    }

    cout << "Time: " << (clock() - start_time) << " ms" << endl;

    return 0;
}
