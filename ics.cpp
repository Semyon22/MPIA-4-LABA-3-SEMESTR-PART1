#include "ics.h"
int** make_matrix(int N, int M) {
    int** matrix;
    /* Allocate memory for the matrix */
/* Allocate memory for an array of matrix rows */
    matrix = new int* [M];
    for (int i = 0; i < M; i++)//allocate memory for a new row of the matrix
    {
        matrix[i] = new int[N];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;

        }
    }
    return matrix;
}

string lcs(const string& first, const string& second) {
    // Return the longest common subsequence (LCS) of the two given strings.

    // Your implementation here.
    int M = first.length() + 1;//строки
    int N = second.length() + 1;//столбцы
    if (M == 1 or N == 1) { return ""; }
    int** matrix = make_matrix(N, M);


    for (int i = 1; i < first.length() + 1; i++) {
        for (int j = 1; j < second.length() + 1; j++) {

            if (first[i - 1] == second[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;

            }
            else {
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
    }
    int** matrix1 = make_matrix(N, M);;
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            matrix1[i][j] = matrix[i + 1][j + 1];

        }
    }
    /* Deleting the matrix */
   /* Deleting each row of the matrix */
    for (size_t i = 0; i < M; ++i){
        delete[] matrix[i];
     }
    
    /* Удаление массива строк матрицы */
    delete[] matrix;
    int i = first.length()-1;
    int j = second.length()-1;
    string result="";
    while (i > 0 && j > 0) {
        if (first[i] == second[j]) {
            result += first[i];
            i = i - 1;
            j = j - 1;
        }
        else {
                
                if (matrix1[i - 1][j] > matrix1[i][j - 1]) {

                    i--;
                 }
                else {
                    j--;
                
            }
        }

    }
    for (size_t i = 0; i < M; ++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    for (int k = 0; k <= i; k++) {
        int flag = 0;
        for (int m = 0; m <= j; m++) {
            if (first[k] == second[m]) {
                result += first[k];
                flag = 1;
                break;
            }

        }
        if (flag == 1) {
            break;
        }
    }
    reverse(result.begin(), result.end());
    return result;
    
}

string lcs_simpl(string& first, string& second) {//an algorithm implemented using recursion principles
    if (first.length() == 0 or second.length() == 0) {
        return " ";   

    }
    if (first[first.length() - 1] == second[second.length() - 1]) {
        string buf, buf2;
        buf = first.substr(0, first.length() - 1);
        buf2 = second.substr(0, second.length() - 1);
      
        return lcs_simpl(buf, buf2)+first[first.length() - 1] ;
    }
    else {
        string buf, buf2;
        buf = first.substr(0, first.length() - 1);
        buf2 = second.substr(0, second.length() - 1);
        string left = lcs_simpl(buf, second);
        string right = lcs_simpl(first, buf2);
        if (left.length() > right.length()) {
            return left;
        }
        else
        {
            return right;
        }
    }

}
string lcs_naiv(const string& first, const string& second) {//the algorithm implemented using a full search

    string result = "", str;
    int last_position = -1;
    for (int i = 0; i < first.length(); i++) {
        for (int j = i; j < first.length(); j++) {
            for (int k = 0; k < second.length(); k++) {
                if (first[j] == second[k] && k > last_position) {
                    str += first[j];
                    last_position = k;
                    break;
                }
            }
        }
        if (str.length() > result.length())
            result = str;
        str = "";
        last_position = -1;
    }
    return result;
}