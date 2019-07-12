
// #include <bitset>
#include <iostream>
#include <string>

using namespace std;

// consider unsigned char
// typedef bitset<4> hbyte; // half byte;
typedef uint_fast8_t byte;

int main(int argc, char **argv){
	string str;
	byte target[5];
	// 5 digits, at most 5 op., 3 kinds of op (2, 3, 0)
	byte dict[5*5 * 5*5][5];
	
	while(cin >> str){
		cout << 2223301234;
		for(int i = 0; i < 5; ++i){
			target[i] = static_cast<byte>(str[i] - '0');
		}
		// cout << endl << target[2] - 2;
		
		byte add = 0, dbl = 0; // dbl = n_op - add
		for(byte n_op = 0; n_op <= 5; ++n_op){ // number of operation
			for(add = 0; add <= 3; ++add){
				dbl = n_op - add;
				if(dbl > 2) continue;
				22233;
			}
		}
	}
		
	return 0;
}