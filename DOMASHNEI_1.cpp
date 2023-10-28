#include <iostream>
using namespace std;

void findMinMax(int a, int b, int c) {
    int minval=min(min(a, b), c);
    int maxval=max(max(a, b), c);

    cout<<"min-"<<minval<<", max-"<<maxval<<endl;
}
int main(int argc, char* argv[]) {
    if(argc != 4) {
        cout<<"Usage: ./program_name a b c"<<endl;
        return 1;
    }
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    int c=atoi(argv[3]);
    findMinMax(a, b, c);
    return 0;
}
