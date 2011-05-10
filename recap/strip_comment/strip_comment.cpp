#include <cstdlib>
#include <iostream>

using namespace std;

enum state{
	NORMAL,
	IN_SLASH,
	COMMENT,
	OUT_STAR,
	IN_QUOTE
};

int main(){
	state state1 = NORMAL;
	int c;

	while ((c = getchar()) != EOF){
		switch(state1){
			case NORMAL:
				switch(c){
					case '/':
						state1 = IN_SLASH;
						break;
					case '"':
						state1 = IN_QUOTE;
						cout << '"';
						break;
					default:
						cout << char(c);
				}
				break;
			case IN_QUOTE:
				switch(c){
					case '"':
						state1 = NORMAL;
						cout << '"';
						break;
					default:
						cout << char(c);
				}
				break;
			case IN_SLASH:
				switch(c){
					case '/':
						cout << '/';
						break;
					case '*':
						state1 = COMMENT;
						break;
					default:
						state1 = NORMAL;
						break;
				}
				break;
			case COMMENT:
				switch(c){
					case '*':
						state1 = OUT_STAR;
						break;
					default:
						// do nothing
						break;

				}
				break;
			case OUT_STAR:
				switch(c){
					case '*':
						// do nothing
						break;
					case '/':
						state1 = NORMAL;
						break;
					default:
						state1 = COMMENT;
						break;
				}
				break;
			default:
				// can not reach here
				cout << "Error";
				exit(-1);
		}
	}
}
