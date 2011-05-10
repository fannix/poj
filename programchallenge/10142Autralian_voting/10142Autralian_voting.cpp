#include	<cstdlib>
#include	<iostream>
#include	<string>
#include	<sstream>
using namespace std;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int nvote[20];
int pointer[1000];
string names[20];
int input[1000][20];
int n_candidate;
int n_left;
int n_line;
void read_a_case();

int eliminate(){
    int min = 10000;
    int min_id = 0;
    for(int i = 0; i < n_candidate; i++){
        if (nvote[i] == -1)
            continue;
        if (min > nvote[i]){
            min = nvote[i];
        }
    }

    for (int i = 0; i < n_candidate; i++) {
        if (nvote[i] == min) {
            n_left -= 1;
        }
    }

    if (n_left == 0){
        for (int i = 0; i < n_candidate; i++) {
            if (nvote[i] == min){
                cout << names[i] << endl;
            }
        }
        return 1;
    }
    for (int i = 0; i < n_candidate; i++) {
        if (nvote[i] == min){
            nvote[i] = -1;
        }
    }
    for (int i = 0; i < n_line; i++) {
        int col = pointer[i];
        while(nvote[input[i][col]] == -1){
            col++;
        }
        pointer[i] = col;
    }
    return 0;
}

int count_vote(){
    for (int i = 0; i < n_candidate; i++) {
        if (nvote[i] == -1)
            continue;
        nvote[i] = 0;
    }
    for(int i = 0; i < n_line; i++){
        int vote = input[i][pointer[i]];
        //cout	<< "vote" << vote << endl;
        nvote[vote] += 1;
    }

    for (int i = 0; i < n_candidate; i++) {
        if(nvote[i] > n_line / 2){
            //cout << "win";
            cout	<< names[i] << endl;
            return 1;
        }
    }
    return 0;
}

int vote(){
    for (int i = 0; i < n_line; i++){
        pointer[i] = 0;
    }
    n_left = n_candidate;
    while (count_vote() != 1){
        if (eliminate() == 1)
            break;
    }
}

int main ( int argc, char *argv[] )
{
    int times;
    cin >> times;

    for (int i= 0;i < times; i++ ){
        read_a_case();
        vote();
        if (i < times - 1) 
            cout << endl;
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

void read_a_case(){

    cin >> n_candidate;

    string skip;
    getline(cin, skip);
    for ( int j = 0; j < n_candidate; j++){
        getline(cin, names[j]);
        
        //cout	<< names[j] << endl;
    }

    int vote;
    int m = 0;
    int n = 0;
    string line;
    getline(cin, line);
    while (line.size() > 0){
        //cout << line << endl;
        //cout << vote << "  ";
        istringstream iss(line, istringstream::in);
        while (iss >> vote){
            input[n][m] = vote-1;
            m += 1;
            if (m == n_candidate){
                m = 0;
                n += 1;
            }
        }
        getline(cin, line);
    }
    n_line = n;

    int i;
    for (i = 0; i < n_candidate; i++) {
        nvote[i] = 0;
    }

    //cout	<< n_line << " " << n_candidate << endl;
}
