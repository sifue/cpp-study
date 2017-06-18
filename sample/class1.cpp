#include <iostream>
#include <string>

using namespace std;

class Member {
  std::string full_member;
  int no;
  int rank;

public:
  Member(std::string name, int number, int grade) {
    full_member = name;
    no = number;
    rank = grade;
  }
  int get_rank() { return rank; }
  int set_rank(int grade) { rank = grade; }
  void print() {
    cout << "No. " << no << " : " << full_member << "[ランク : " << rank << "]"
         << endl;
  }
};

void print(Member *p) { p->print(); }

int main() {
  Member soichiro("吉村総一郎", 34, 1);
  soichiro.set_rank(soichiro.get_rank() + 1);
  print(&soichiro);
}
