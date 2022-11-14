#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // read the map size, rows, columns
    int r, c;
    cin >> r >> c;

    // read the snakes heads position, hr(head row), hc(head column)
    int hr, hc;
    cin >> hr >> hc;

    // to represent snake use deque
    // because it has O(1) insertion to head and it has an iterator
    // pair represents {row, column} indexes of related body part
    deque<pair<int, int>> snake;
    deque<pair<int, int>>::iterator it;
    snake.push_back({hr, hc});

    int q;
    cin >> q;

    int type;
    char direction;
    for (int i = 0; i < q; i++) {
        cin >> type >> direction;
        hr = snake.front().first;
        hc = snake.front().second;

        // Move Query
        if (type == 1) {
            int size = snake.size();

            // set iterator to tail
            it = snake.end();
            it--;

            // to move snake we need to copy previous body parts location
            for (int SIZE = 0; SIZE < size - 1; SIZE++) {
                it->first = (it - 1)->first;
                it->second = (it - 1)->second;
                it--;
            }

            // set position of head manually
            if (direction == 'u') {
                if (hr > 0) {
                    snake.front().first = hr - 1;
                } else {
                    snake.front().first = r - 1;
                }
            } else if (direction == 'd') {
                if (hr < r - 1) {
                    snake.front().first = hr + 1;
                } else {
                    snake.front().first = 0;
                }
            } else if (direction == 'l') {
                if (hc > 0) {
                    snake.front().second = hc - 1;
                } else {
                    snake.front().second = c - 1;
                }
            } else {
                if (hc < c - 1) {
                    snake.front().second = hc + 1;
                } else {
                    snake.front().second = 0;
                }
            }
        } else {
            // Grow Query
            // Just add a node to the head to given direction
            if (direction == 'u') {
                if (hr > 0) {
                    snake.push_front({hr - 1, hc});
                } else {
                    snake.push_front({r - 1, hc});
                }
            } else if (direction == 'd') {
                if (hr < r - 1) {
                    snake.push_front({hr + 1, hc});
                } else {
                    snake.push_front({0, hc});
                }
            } else if (direction == 'l') {
                if (hc > 0) {
                    snake.push_front({hr, hc - 1});
                } else {
                    snake.push_front({hr, c - 1});
                }
            } else {
                if (hc < c - 1) {
                    snake.push_front({hr, hc + 1});
                } else {
                    snake.push_front({hr, 0});
                }
            }
        }
    }

    // create a 2d table for map, each entry is 0 initially
    vector<vector<int>> grid(r, vector<int>(c, 0));

    // for each body part of the snake increment the related cell
    int size = snake.size();
    it = snake.begin();
    for (int SIZE = 0; SIZE < size; SIZE++) {
        grid[it->first][it->second]++;
        it++;
    }

    // print the 2d table
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            if (ci)
                cout << " ";
            cout << grid[ri][ci];
        }
        cout << "\n";
    }
}