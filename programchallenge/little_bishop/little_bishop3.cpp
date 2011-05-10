/*
 * =====================================================================================
 *
 *       Filename:  little_bishop3.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009-5-11 14:25:58 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  first_name last_name (fl), fl@my-company.com
 *        Company:  my-company
 *
 * =====================================================================================
 */

/*   @JUDGE_ID:   29339ZA   861   C++   "Backtracking"   */

#include <iostream>
#include <cstdlib>
// #include <ctime>
using namespace std;

#define MAXCANDIDATES   100      /* max possible next extensions */
#define NMAX            100      /* maximum solution size */

void dumpSolution(int n, int k);

typedef char* data;         /* type to pass data to backtrack */

long solution_count;         /* how many solutions are there? */

bool occupied[15][15];



void process_solution(int n, int k)
{
	solution_count++;
	// dumpSolution(n, k);
}

void dumpSolution(int n, int k) {
	cout << "n = " << n << "; k = " << k << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (occupied[i][j]) {
				cout << "X";
			}
			else {
				cout << "O";
			}
		}

		cout << endl;
	}
	cout << endl;
}

bool is_a_solution(int m, int k)
{
	return (m == k);
}

int getMaxFile(int n, int rank) {
	return n - abs(rank) - 1;
}


/*   What are possible elements of the next slot in the Little Bishops
     problem?
     */

void construct_candidates(int m, int k, int n, int c[MAXCANDIDATES][2],
		int *ncandidates, int last, bool isCorner)
{
	int i,j;         /* counters */
	bool legal_move;      /* might the move be legal? */

	bool fileIsCorner;
	if (n % 2 == 0) {
		fileIsCorner = !isCorner;
	}
	else {
		fileIsCorner = isCorner;
	}

	*ncandidates = 0;
	int maxI;
	if (isCorner) {
		maxI = n - 1;
	}
	else {
		maxI = n - 2;
	}
	for (i = last + 2; i <= maxI; i += 2) {
		int maxJ = getMaxFile(n, i);
		int minJ = -maxJ;
		for (j = minJ; j <= maxJ; j += 2) {
			legal_move = true;
			if (occupied[i + n - 1][j + n - 1]) {
				legal_move = false;

				continue;
			}
			if (legal_move) {
				int minRank;
				int maxRank;
				if (isCorner) {
					maxRank = n - 1;
					minRank = -(n - 1);
				}
				else {
					maxRank = n - 2;
					minRank = -(n - 2);
				}
				for (k = minRank; k <= maxRank; k += 2) {
					int maxFile = getMaxFile(n, k);
					int minFile = -maxFile;
					for (int l = minFile; l <= maxFile; l += 2) {
						if (occupied[k + n - 1][l + n - 1] && (i == k || j == l)) {  /* diagonal threat */
							legal_move = false;

							break;
						}
					}
					if (!legal_move) {
						break;
					}
				}
			}
			if (legal_move == true) {
				c[*ncandidates][0] = i;
				c[*ncandidates][1] = j;
				*ncandidates = *ncandidates + 1;
			}
		}
	}
}


bool finished = false;                  /* found all solutions yet? */

void backtrack(int m, int k, int n, int lastRank, bool isCorner)
{
	int c[MAXCANDIDATES][2];        /* candidates for next position */
	int ncandidates;                /* next position candidate count */
	int i;                          /* counter */

	if (is_a_solution(m, k))
		process_solution(n, k);
	else if (m < k) {
		m = m+1;
		construct_candidates(m, k, n, c, &ncandidates, lastRank, isCorner);
		for (i=0; i<ncandidates; i++) {
			occupied[c[i][0] + n - 1][c[i][1] + n - 1] = true;
			backtrack(m, k, n, c[i][0], isCorner);
			occupied[c[i][0] + n - 1][c[i][1] + n - 1] = false;
			if (finished) return;   /* terminate early */
		}
	}
}

void initializeOccupied() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			occupied[i][j] = false;
		}
	}
}


long solve(int n, int k) {
	long totalCount = 0;
	if (k <= 2 * n - 1) {
		for (int cornerK = 0; cornerK <= k; cornerK++) {
			solution_count = 0;
			initializeOccupied();
			backtrack(0, cornerK, n, -(n - 1) - 2, true);
			long cornerCount = solution_count;

			int nonCornerK = k - cornerK;
			solution_count = 0;
			initializeOccupied();
			backtrack(0, nonCornerK, n, -(n - 2) - 2, false);
			long nonCornerCount = solution_count;

			totalCount += cornerCount * nonCornerCount;
		}
	}

	return totalCount;
}

/*
   int main2 (int argc, const char * argv[]) {
   int n;
   int k;
   time_t start,end;
   double dif;
   double max = 0.0;

   printf("n, k, time, count\n");
   for (n = 1; n <= 8; n++) {
   for (k = 0; k <= n * n; k++) {
   time (&start);
   long totalCount = solve(n, k);
   time (&end);
   dif = difftime (end,start);
   if (dif > max) {
   max = dif;
   }
   printf ("%d, %d, %.2lf, %d\n", n, k, dif, totalCount);
   }
   }

   return 0;
   }
   */


int main (int argc, const char * argv[]) {
	int n;
	int k;

	while (cin >> n >> k) {
		if (n == 0 && k == 0) {
			break;
		}

		long totalCount = solve(n, k);

		cout << totalCount << endl;
	}

	return 0;
}

