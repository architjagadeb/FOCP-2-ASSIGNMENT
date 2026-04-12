#include<iostream>
using namespace std;

const int MAXN = 10000001;
int distinctPrimes[MAXN];
int answer[MAXN];

class CountPairs {
    private:
        void buildSieve() {
            for(int i = 0; i < MAXN; i++) {
                distinctPrimes[i] = 0;
            }
            for(int p = 2; p < MAXN; p++) {
                if(distinctPrimes[p] == 0) {
                    for(int multiple = p; multiple < MAXN; multiple = multiple + p) {
                        distinctPrimes[multiple] = distinctPrimes[multiple] + 1;
                    }
                }
            }
        }

        void buildAnswers() {
            answer[1] = 1;
            for(int i = 2; i < MAXN; i++) {
                int k = distinctPrimes[i];
                int val = 1;
                for(int j = 0; j < k; j++) {
                    val = val * 2;
                }
                answer[i] = val;
            }
        }

    public:
        CountPairs() {
            buildSieve();
            buildAnswers();
        }

        int getAnswer(int n) {
            return answer[n];
        }
};

int fastRead() {
    int x = 0;
    char c = getchar_unlocked();
    while(c < '0' || c > '9') {
        c = getchar_unlocked();
    }
    while(c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return x;
}

void fastWrite(int x) {
    if(x == 0) {
        putchar_unlocked('0');
        putchar_unlocked('\n');
        return;
    }
    char buf[12];
    int len = 0;
    while(x > 0) {
        buf[len] = '0' + (x % 10);
        len = len + 1;
        x = x / 10;
    }
    for(int i = len - 1; i >= 0; i = i - 1) {
        putchar_unlocked(buf[i]);
    }
    putchar_unlocked('\n');
}

int main() {
    CountPairs cp;
    int t = fastRead();
    while(t > 0) {
        int n = fastRead();
        fastWrite(cp.getAnswer(n));
        t = t - 1;
    }
    return 0;
}