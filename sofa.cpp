// s is the placement of sofa - curr
// S is the final placement of sofa
// H : placement of household items
// 0 is empty space
#include <bits/stdc++.h>
using namespace std;

struct SofaState {
    int row, col;      // base cell: left (if horizontal) or top (if vertical)
    int orientation;   // 0 = horizontal, 1 = vertical
};

int rows, columns;
vector<vector<char>> house;
int min_moves_so_far = INT_MAX;

bool isInside(int r, int c) {
    return (r >= 0 && r < rows && c >= 0 && c < columns);
}
bool isFreeCell(int r, int c) {
    return isInside(r, c) && house[r][c] != 'H';
}
bool isValidPlacement(const SofaState& st) {
    if (st.orientation == 0) { // horizontal
        return isFreeCell(st.row, st.col) && isFreeCell(st.row, st.col + 1);
    } else { // vertical
        return isFreeCell(st.row, st.col) && isFreeCell(st.row + 1, st.col);
    }
}
bool isGoal(const SofaState& st, const SofaState& goal) {
    return st.row == goal.row && st.col == goal.col && st.orientation == goal.orientation;
}
bool canRotateAt(int r, int c) {
    // needs full 2x2 free block with top-left at (r,c)
    return isFreeCell(r, c) && isFreeCell(r, c+1) &&
           isFreeCell(r+1, c) && isFreeCell(r+1, c+1);
}

void reachTheEnd(SofaState current, const SofaState& goal,
                 vector<vector<array<int,2>>>& visited, int moves) {

    if (moves >= min_moves_so_far) return;                 // prune if already worse
    if (isGoal(current, goal)) {                    // reached
        min_moves_so_far = min(min_moves_so_far, moves);
        return;
    }
    if (visited[current.row][current.col][current.orientation] <= moves) return;
    visited[current.row][current.col][current.orientation] = moves;

    if (current.orientation == 0) { // horizontal sofa occupies (r,c) and (r,c+1)
        int r = current.row, c = current.col;

        // slides
        if (isFreeCell(r, c-1))                reachTheEnd({r, c-1, 0}, goal, visited, moves+1);      // left
        if (isFreeCell(r, c+2))                reachTheEnd({r, c+1, 0}, goal, visited, moves+1);      // right
        if (isFreeCell(r-1, c) && isFreeCell(r-1, c+1))
                                               reachTheEnd({r-1, c, 0}, goal, visited, moves+1);      // up
        if (isFreeCell(r+1, c) && isFreeCell(r+1, c+1))
                                               reachTheEnd({r+1, c, 0}, goal, visited, moves+1);      // down

        // rotations (need 2x2 block above or below)
        if (canRotateAt(r-1, c)) {
            reachTheEnd({r-1, c,   1}, goal, visited, moves+1); // vertical, base at top-left
            reachTheEnd({r-1, c+1, 1}, goal, visited, moves+1); // vertical, base at top-right
        }
        if (canRotateAt(r, c)) {
            reachTheEnd({r,   c,   1}, goal, visited, moves+1); // vertical, base at top-left
            reachTheEnd({r,   c+1, 1}, goal, visited, moves+1); // vertical, base at top-right
        }

    } else { // vertical sofa occupies (r,c) and (r+1,c)
        int r = current.row, c = current.col;

        // slides
        if (isFreeCell(r-1, c))                reachTheEnd({r-1, c, 1}, goal, visited, moves+1);      // up
        if (isFreeCell(r+2, c))                reachTheEnd({r+1, c, 1}, goal, visited, moves+1);      // down
        if (isFreeCell(r, c-1) && isFreeCell(r+1, c-1))
                                               reachTheEnd({r, c-1, 1}, goal, visited, moves+1);      // left
        if (isFreeCell(r, c+1) && isFreeCell(r+1, c+1))
                                               reachTheEnd({r, c+1, 1}, goal, visited, moves+1);      // right

        // rotations (need 2x2 block left or right)
        if (canRotateAt(r, c-1)) {
            reachTheEnd({r,   c-1, 0}, goal, visited, moves+1); // horizontal, base at top-left
            reachTheEnd({r+1, c-1, 0}, goal, visited, moves+1); // horizontal, base at bottom-left
        }
        if (canRotateAt(r, c)) {
            reachTheEnd({r,   c,   0}, goal, visited, moves+1);
            reachTheEnd({r+1, c,   0}, goal, visited, moves+1); 
        }
    }
}

int main() {

    cin >> rows >> columns;
    house.assign(rows, vector<char>(columns));
    vector<pair<int,int>> startCells, goalCells;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            string token; cin >> token;
            house[i][j] = token[0];
            if (house[i][j] == 's') startCells.push_back({i,j});
            if (house[i][j] == 'S') goalCells.push_back({i,j});
        }
    }

    // Must have exactly two s's and two S's
    if (startCells.size() != 2 || goalCells.size() != 2) {
        cout << "Impossible\n";
        return 0;
    }

    // Ensure each pair is adjacent (Manhattan distance = 1)
    auto adjacent = [&](pair<int,int> a, pair<int,int> b){
        return abs(a.first - b.first) + abs(a.second - b.second) == 1;
    };
    if (!adjacent(startCells[0], startCells[1]) || !adjacent(goalCells[0], goalCells[1])) {
        cout << "Impossible\n";
        return 0;
    }

    SofaState start, goal;

    // Build start state (normalize base to left/top)
    if (startCells[0].first == startCells[1].first) { // horizontal
        int r = startCells[0].first;
        int c = min(startCells[0].second, startCells[1].second);
        start = {r, c, 0};
    } else { // vertical
        int c = startCells[0].second;
        int r = min(startCells[0].first, startCells[1].first);
        start = {r, c, 1};
    }

    // Build goal state (normalize base to left/top)
    if (goalCells[0].first == goalCells[1].first) { // horizontal
        int r = goalCells[0].first;
        int c = min(goalCells[0].second, goalCells[1].second);
        goal = {r, c, 0};
    } else { // vertical
        int c = goalCells[0].second;
        int r = min(goalCells[0].first, goalCells[1].first);
        goal = {r, c, 1};
    }

    // Quick early exit if already at goal
    if (start.row == goal.row && start.col == goal.col && start.orientation == goal.orientation) {
        cout << 0 << "\n";
        return 0;
    }

    // visited[row][col][orientation] = min steps seen so far
    vector<vector<array<int,2>>> visited(rows, vector<array<int,2>>(columns, {INT_MAX, INT_MAX}));

    if (!isValidPlacement(start) || !isValidPlacement(goal)) {
        cout << "Impossible\n";
        return 0;
    }

    reachTheEnd(start, goal, visited, 0);

    if (min_moves_so_far == INT_MAX) cout << "Impossible\n";
    else cout << min_moves_so_far << "\n";
    return 0;
}
