#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1024;

struct Elephant {
  int idx;
  int weight;
  int iq;
};

int n;
Elephant ele[MAX_N];
int f[MAX_N];
int pre[MAX_N];

bool cmp(const Elephant& a, const Elephant& b) {
  return a.weight < b.weight;
}

void show(int i) {
  if (i == 0) return;
  show(pre[i]);
  printf("%d\n", ele[i].idx);
}

int main() {
  for (n = 1; scanf("%d %d", &ele[n].weight, &ele[n].iq) == 2; ++n) {
    ele[n].idx = n;
  }
  --n;
  sort(ele + 1, ele + 1 + n, cmp);
  int maxlen = 1;
  int maxpos = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = 1;
    for (int j = 1; j < i && ele[j].weight < ele[i].weight; ++j)
      if (ele[j].iq > ele[i].iq && f[i] < f[j] + 1) {
        f[i] = f[j] + 1;
        pre[i] = j;
      }
    if (maxlen < f[i]) {
      maxlen = f[i];
      maxpos = i;
    }
  }
  printf("%d\n", maxlen);
  show(maxpos);
  return 0;
}

