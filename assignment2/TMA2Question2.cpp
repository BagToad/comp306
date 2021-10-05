/* 
 Title: TMA2Question2.cpp
 Description:
    Create a char array, a float array, a single int, and a single long using "new".
    Print the types and memory addresses of all variables.
    Delete the variables using "delete".
 Date: October 4, 2021
 Author: Kynan Ware
 Student ID: 3431123 
 Compile: g++ TMA2Question2.cpp -o TMA2Question2.exe
 Execution: ./TMA2Question2.exe
 
 Classes: none

 Variables:
 number - int - a number stored as int.
 long_number - long - a number stored as long.
 chars - char - an array of chars.
 floats - float - an array of floats.

 Constants:
 ARRAY_NUM - int - the number of items in either array. 
 input_alphabet - char - a char array of the alphabet repeated in alternating case. 
*/

/*
 TEST PLAN
 
 Normal case:
	int @ 0x7fff2f96ec30 = 1
	long @ 0x7fff2f96ec38 = 10000
	char @ 0x5565bd9d8eb0 = a
	char @ 0x5565bd9d8eb1 = b
	char @ 0x5565bd9d8eb2 = c
	char @ 0x5565bd9d8eb3 = d
	char @ 0x5565bd9d8eb4 = e
	char @ 0x5565bd9d8eb5 = f
	char @ 0x5565bd9d8eb6 = g
	char @ 0x5565bd9d8eb7 = h
	char @ 0x5565bd9d8eb8 = i
	char @ 0x5565bd9d8eb9 = j
	char @ 0x5565bd9d8eba = k
	char @ 0x5565bd9d8ebb = l
	char @ 0x5565bd9d8ebc = m
	char @ 0x5565bd9d8ebd = n
	char @ 0x5565bd9d8ebe = o
	char @ 0x5565bd9d8ebf = p
	char @ 0x5565bd9d8ec0 = q
	char @ 0x5565bd9d8ec1 = r
	char @ 0x5565bd9d8ec2 = s
	char @ 0x5565bd9d8ec3 = t
	char @ 0x5565bd9d8ec4 = u
	char @ 0x5565bd9d8ec5 = v
	char @ 0x5565bd9d8ec6 = w
	char @ 0x5565bd9d8ec7 = x
	char @ 0x5565bd9d8ec8 = y
	char @ 0x5565bd9d8ec9 = z
	char @ 0x5565bd9d8eca = A
	char @ 0x5565bd9d8ecb = B
	char @ 0x5565bd9d8ecc = C
	char @ 0x5565bd9d8ecd = D
	char @ 0x5565bd9d8ece = E
	char @ 0x5565bd9d8ecf = F
	char @ 0x5565bd9d8ed0 = G
	char @ 0x5565bd9d8ed1 = H
	char @ 0x5565bd9d8ed2 = I
	char @ 0x5565bd9d8ed3 = J
	char @ 0x5565bd9d8ed4 = K
	char @ 0x5565bd9d8ed5 = L
	char @ 0x5565bd9d8ed6 = M
	char @ 0x5565bd9d8ed7 = N
	char @ 0x5565bd9d8ed8 = O
	char @ 0x5565bd9d8ed9 = P
	char @ 0x5565bd9d8eda = Q
	char @ 0x5565bd9d8edb = R
	char @ 0x5565bd9d8edc = S
	char @ 0x5565bd9d8edd = T
	char @ 0x5565bd9d8ede = U
	char @ 0x5565bd9d8edf = V
	char @ 0x5565bd9d8ee0 = W
	char @ 0x5565bd9d8ee1 = X
	char @ 0x5565bd9d8ee2 = Y
	char @ 0x5565bd9d8ee3 = Z
	char @ 0x5565bd9d8ee4 = a
	char @ 0x5565bd9d8ee5 = b
	char @ 0x5565bd9d8ee6 = c
	char @ 0x5565bd9d8ee7 = d
	char @ 0x5565bd9d8ee8 = e
	char @ 0x5565bd9d8ee9 = f
	char @ 0x5565bd9d8eea = g
	char @ 0x5565bd9d8eeb = h
	char @ 0x5565bd9d8eec = i
	char @ 0x5565bd9d8eed = j
	char @ 0x5565bd9d8eee = k
	char @ 0x5565bd9d8eef = l
	char @ 0x5565bd9d8ef0 = m
	char @ 0x5565bd9d8ef1 = n
	char @ 0x5565bd9d8ef2 = o
	char @ 0x5565bd9d8ef3 = p
	char @ 0x5565bd9d8ef4 = q
	char @ 0x5565bd9d8ef5 = r
	char @ 0x5565bd9d8ef6 = s
	char @ 0x5565bd9d8ef7 = t
	char @ 0x5565bd9d8ef8 = u
	char @ 0x5565bd9d8ef9 = v
	char @ 0x5565bd9d8efa = w
	char @ 0x5565bd9d8efb = x
	char @ 0x5565bd9d8efc = y
	char @ 0x5565bd9d8efd = z
	char @ 0x5565bd9d8efe = A
	char @ 0x5565bd9d8eff = B
	char @ 0x5565bd9d8f00 = C
	char @ 0x5565bd9d8f01 = D
	char @ 0x5565bd9d8f02 = E
	char @ 0x5565bd9d8f03 = F
	char @ 0x5565bd9d8f04 = G
	char @ 0x5565bd9d8f05 = H
	char @ 0x5565bd9d8f06 = I
	char @ 0x5565bd9d8f07 = J
	char @ 0x5565bd9d8f08 = K
	char @ 0x5565bd9d8f09 = L
	char @ 0x5565bd9d8f0a = M
	char @ 0x5565bd9d8f0b = N
	char @ 0x5565bd9d8f0c = O
	char @ 0x5565bd9d8f0d = P
	char @ 0x5565bd9d8f0e = Q
	char @ 0x5565bd9d8f0f = R
	char @ 0x5565bd9d8f10 = S
	char @ 0x5565bd9d8f11 = T
	char @ 0x5565bd9d8f12 = U
	char @ 0x5565bd9d8f13 = V
	float @ 0x5565bd9d90b4 = 101
	float @ 0x5565bd9d90b8 = 102
	float @ 0x5565bd9d90bc = 103
	float @ 0x5565bd9d90c0 = 104
	float @ 0x5565bd9d90c4 = 105
	float @ 0x5565bd9d90c8 = 106
	float @ 0x5565bd9d90cc = 107
	float @ 0x5565bd9d90d0 = 108
	float @ 0x5565bd9d90d4 = 109
	float @ 0x5565bd9d90d8 = 110
	float @ 0x5565bd9d90dc = 111
	float @ 0x5565bd9d90e0 = 112
	float @ 0x5565bd9d90e4 = 113
	float @ 0x5565bd9d90e8 = 114
	float @ 0x5565bd9d90ec = 115
	float @ 0x5565bd9d90f0 = 116
	float @ 0x5565bd9d90f4 = 117
	float @ 0x5565bd9d90f8 = 118
	float @ 0x5565bd9d90fc = 119
	float @ 0x5565bd9d9100 = 120
	float @ 0x5565bd9d9104 = 121
	float @ 0x5565bd9d9108 = 122
	float @ 0x5565bd9d910c = 123
	float @ 0x5565bd9d9110 = 124
	float @ 0x5565bd9d9114 = 125
	float @ 0x5565bd9d9118 = 126
	float @ 0x5565bd9d911c = 127
	float @ 0x5565bd9d9120 = 128
	float @ 0x5565bd9d9124 = 129
	float @ 0x5565bd9d9128 = 130
	float @ 0x5565bd9d912c = 131
	float @ 0x5565bd9d9130 = 132
	float @ 0x5565bd9d9134 = 133
	float @ 0x5565bd9d9138 = 134
	float @ 0x5565bd9d913c = 135
	float @ 0x5565bd9d9140 = 136
	float @ 0x5565bd9d9144 = 137
	float @ 0x5565bd9d9148 = 138
	float @ 0x5565bd9d914c = 139
	float @ 0x5565bd9d9150 = 140
	float @ 0x5565bd9d9154 = 141
	float @ 0x5565bd9d9158 = 142
	float @ 0x5565bd9d915c = 143
	float @ 0x5565bd9d9160 = 144
	float @ 0x5565bd9d9164 = 145
	float @ 0x5565bd9d9168 = 146
	float @ 0x5565bd9d916c = 147
	float @ 0x5565bd9d9170 = 148
	float @ 0x5565bd9d9174 = 149
	float @ 0x5565bd9d9178 = 150
	float @ 0x5565bd9d917c = 151
	float @ 0x5565bd9d9180 = 152
	float @ 0x5565bd9d9184 = 153
	float @ 0x5565bd9d9188 = 154
	float @ 0x5565bd9d918c = 155
	float @ 0x5565bd9d9190 = 156
	float @ 0x5565bd9d9194 = 157
	float @ 0x5565bd9d9198 = 158
	float @ 0x5565bd9d919c = 159
	float @ 0x5565bd9d91a0 = 160
	float @ 0x5565bd9d91a4 = 161
	float @ 0x5565bd9d91a8 = 162
	float @ 0x5565bd9d91ac = 163
	float @ 0x5565bd9d91b0 = 164
	float @ 0x5565bd9d91b4 = 165
	float @ 0x5565bd9d91b8 = 166
	float @ 0x5565bd9d91bc = 167
	float @ 0x5565bd9d91c0 = 168
	float @ 0x5565bd9d91c4 = 169
	float @ 0x5565bd9d91c8 = 170
	float @ 0x5565bd9d91cc = 171
	float @ 0x5565bd9d91d0 = 172
	float @ 0x5565bd9d91d4 = 173
	float @ 0x5565bd9d91d8 = 174
	float @ 0x5565bd9d91dc = 175
	float @ 0x5565bd9d91e0 = 176
	float @ 0x5565bd9d91e4 = 177
	float @ 0x5565bd9d91e8 = 178
	float @ 0x5565bd9d91ec = 179
	float @ 0x5565bd9d91f0 = 180
	float @ 0x5565bd9d91f4 = 181
	float @ 0x5565bd9d91f8 = 182
	float @ 0x5565bd9d91fc = 183
	float @ 0x5565bd9d9200 = 184
	float @ 0x5565bd9d9204 = 185
	float @ 0x5565bd9d9208 = 186
	float @ 0x5565bd9d920c = 187
	float @ 0x5565bd9d9210 = 188
	float @ 0x5565bd9d9214 = 189
	float @ 0x5565bd9d9218 = 190
	float @ 0x5565bd9d921c = 191
	float @ 0x5565bd9d9220 = 192
	float @ 0x5565bd9d9224 = 193
	float @ 0x5565bd9d9228 = 194
	float @ 0x5565bd9d922c = 195
	float @ 0x5565bd9d9230 = 196
	float @ 0x5565bd9d9234 = 197
	float @ 0x5565bd9d9238 = 198
	float @ 0x5565bd9d923c = 199
	float @ 0x5565bd9d9240 = 200
	float @ 0x5565bd9d9244 = 201
 
 Discussion:
	The program doesn't take any input, and so test plans are limited. The program should execute the same every time.
	The program will load an int, a long, an array of chars, and an array of floats with data. Next, it will print the types
	alongside the memory address and values.
	
	To retrieve the memory address of an element within a char array, a static cast to a void* is required to prevent the << operator
	from treating the char* as a string. 
	Derived from: https://www.codeproject.com/Questions/823804/How-Do-I-Find-The-Memory-Address-Of-A-Character-In

    The program returns an int as per the C++ standard.

    All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream>

using namespace std;

int main(void) {
	const int ARRAY_NUM = 100;
	const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV";

	int* number = new int(1);
	long* long_number = new long(10000);

	char* chars = new char[ARRAY_NUM]();
	float* floats = new float[ARRAY_NUM]();

	//Fill char array with alphabet
	for (int i = 0; i < ARRAY_NUM; i++) {
		chars[i] = ALPHABET[i];
	}

	//Fill float array with values between 101 and 201.
	for (int i = 101; i <= 201; i++) {
		floats[i - 101] = (float) i;
	}

	//Print variables.
	cout << "int @ " << &number << " = " << *number << endl;
	cout << "long @ " << &long_number << " = " << *long_number << endl;

	//Print arrays.
	for (int i = 0; i < ARRAY_NUM; i++) {
		/*	Static cast to void* required to prevent << from treating char* as a string and printing it. 
		  	Derived from:
			https://www.codeproject.com/Questions/823804/How-Do-I-Find-The-Memory-Address-Of-A-Character-In
		*/
		cout << "char @ " << static_cast<void*>(&chars[i]) << " = " << chars[i] << endl;
	}

	for (int i = 101; i <= 201; i++) {
		cout << "float @ " << &floats[i] << " = " << floats[i - 101] << endl;
	}

	//Delete everything.
	delete number;
	delete long_number;
	delete[] chars;
	delete[] floats;

    return 0;
}

