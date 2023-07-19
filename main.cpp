#include<iostream>
#include<vector>

#include "./src/timer.h"
#include "./src/sort.h"
#include "./src/utils.h"
#include "./src/file.h"

using namespace std;

int main() {
    int intervals = 200;
    int limit = 20000;

    File file("./csv/quickRandom.csv", true);

    for(int i = 100; i < limit; i += intervals) {
        cout << "INPUT: " << i << " ";
        vector<int> random = Util::generate(i);
        vector<int> asc = Util::generate(i, ASC);
        vector<int> dsc = Util::generate(i, DSC);
        Timer t1;
        Timer t2;
        Timer t3;
        
        t1.begin();
        Sort::quickSort(random, 0, random.size() - 1, [](int n1, int n2) { return n1 < n2; }, true);
        t1.stop();
        
        t2.begin();
        Sort::quickSort(asc, 0, asc.size() - 1, [](int n1, int n2) { return n1 < n2; }, true);
        t2.stop();

        t3.begin();
        Sort::quickSort(dsc, 0, dsc.size() - 1, [](int n1, int n2) { return n1 < n2; }, true);
        t3.stop();
        // Adding record to the csv file
        file.addRecord(i, t1.getElapsedSeconds(), t2.getElapsedSeconds(), t3.getElapsedSeconds());

    }
    return 0;
}