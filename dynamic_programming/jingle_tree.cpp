#include <iostream>
using namespace std;

void draw_tree(int n) {
    // Calculate the height of the pyramid part (foliage)
    int height = 2 * n + 1;

    // Draw the pyramid part (foliage)
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= height * 2 - 1; ++j) {
            if (j >= height - i + 1 && j <= height + i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Draw the trunk part
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= height * 2 - 1; ++j) {
            if (j >= height - (n - 1) && j <= height + (n - 1)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Sample Input 0
    cout << "Sample Output 0" << endl;
    n = 1;
    draw_tree(n);

    // Sample Input 1
    cout << "Sample Output 1" << endl;
    n = 3;
    draw_tree(n);

    // Sample Input 2
    cout << "Sample Output 2" << endl;
    n = 5;
    draw_tree(n);

    // Additional Sample for n=2
    cout << "Additional Sample for n=2" << endl;
    n = 2;
    draw_tree(n);

    return 0;
}
