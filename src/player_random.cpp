#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
struct Point {
    int x, y;
    Point() : Point(0, 0) {}
	Point(float x, float y) : x(x), y(y) {}
	bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Point& rhs) const {
		return !operator==(rhs);
	}
	Point operator+(const Point& rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
};

class TreeNode{
public:
    TreeNode(){
        for(int i=0;i<3;i++){
            disc_count[i]=0;
        }
        done=false;
        winner=-1;
    };
    //TreeNode(const int& value):value(value){};
    int value;
    int depth;
    std::list<TreeNode> Children;

    enum SPOT_STATE {EMPTY = 0,BLACK = 1,WHITE = 2};
    static const int SIZE = 8;
    const std::array<Point, 8> directions{{Point(-1, -1), Point(-1, 0), Point(-1, 1),Point(0, -1), /*{0, 0}, */Point(0, 1),Point(1, -1), Point(1, 0), Point(1, 1)}};
    std::array<std::array<int, SIZE>, SIZE> board;
    std::vector<Point> next_valid_spots;
    std::array<int, 3> disc_count;
    int cur_player;
    bool done;
    int winner;
};

TreeNode root;
const int SIZE = 8;

void read_board(std::ifstream& fin) {
    fin >> root.cur_player;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> root.board[i][j];
            root.disc_count[root.board[i][j]]++;
        }
    }
}

void read_valid_spots(std::ifstream& fin) {
    int n_valid_spots;
    fin >> n_valid_spots;
    int x, y;
    for (int i = 0; i < n_valid_spots; i++) {
        fin >> x >> y;
        root.next_valid_spots.push_back({x, y});
    }
    root.state_value_function(){

    }
}

void write_valid_spot(std::ofstream& fout) {
    int n_valid_spots = root.next_valid_spots.size();
    /*
    srand(time(NULL));
    // Choose random spot. (Not random uniform here)
    int index = (rand() % n_valid_spots);
    */

    //create Tree
    for(Point nxt:root.next_valid_spots){
        TreeNode Node;

    }

    //search Tree(Alpha Beta Algorithm)


    //do something...

    Point p = root.next_valid_spots[index];
    // Remember to flush the output to ensure the last action is written to file.
    fout << p.x << " " << p.y << std::endl;
    fout.flush();
}

int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    read_valid_spots(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}
