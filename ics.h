
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// Find the longest common subsequence of two strings.
string lcs(const std::string& first, const std::string& second);
string lcs_simpl( std::string& first,  std::string& second);
int** make_matrix(int N, int M);

