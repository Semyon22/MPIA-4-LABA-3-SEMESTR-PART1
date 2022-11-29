#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <chrono>
#include "ics.h"

string generateRandomString(size_t length)
{
    const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t charmapLength = strlen(charmap);
    auto generator = [&]() { return charmap[rand() % charmapLength]; };
    string result;
    result.reserve(length);
    generate_n(back_inserter(result), length, generator);
    return result;
}
void measure_time(string first,string second) {
    
    auto t3 = chrono::high_resolution_clock::now();
    lcs(first, second);
    auto t4 = chrono::high_resolution_clock::now();
    double time1 = std::chrono::duration<double>(t4 - t3).count();
    cout << time1<< endl;
    /*auto t1 = chrono::high_resolution_clock::now();
    lcs_simpl(first, second);
    auto t2 = chrono::high_resolution_clock::now();
    double time = std::chrono::duration<double>(t2 - t1).count();
    cout << time << endl;*/

}

int main(int argc, char* argv[]) {
    int M = 19000 * 2;
    int N = 19000 * 2;
    
    string first = generateRandomString(N);
    string second = generateRandomString(M);
    measure_time(first, second);
	int result = Catch::Session().run(argc, argv);
	return result;
    
   
}