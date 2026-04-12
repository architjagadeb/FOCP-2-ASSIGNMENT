#include<iostream>
#include<string>
using namespace std;

class BulbSolver {
    private:
        int n, k;
        string bulbs;

        int canDo(int l) {
            int ops = 0;
            int i = 0;
            while(i < n) {
                if(bulbs[i] == '1') {
                    ops++;
                    if(ops > k) return 0;
                    i = i + l;  
                } else {
                    i++;
                }
            }
            return 1;
        }

    public:
        void input() {
            cin >> n >> k;
            cin >> bulbs;
        }

        int solve() {
            int lo = 1, hi = n, ans = n;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(canDo(mid)) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return ans;
        }

        void output() {
            cout << solve() << endl;
        }
};

int main() {
    BulbSolver solver;
    solver.input();
    solver.output();
    return 0;
}