/* 
 Title: TMA1Question5.cpp
 Description: 
 	Create 100 string objects and fill them with lines from a text file.
 	Print the lines to the terminal prefixed by the line number.
 Date: August 15, 2021
 Author: Kynan Ware
 Student ID: 3431123
 Compile: g++ TMA1Question5.cpp -o TMA1Question5.exe
 Execution: ./TMA1Question5.exe
 
 Classes: none

 Variables:
 

*/

/*
 TEST PLAN

 All test plans, unless noted, require the creation of an input file. 

 Normal case (file has less than 100 lines):
    Input file (input1.txt) contents:
        This is line 1
        This is line 2
        This is line 3

    >Filename to open: input1.txt
    >line 1: This is line 1
    >line 2: This is line 2
    >line 3: This is line 3


 Normal case 2 (file with newlines and special characters)
    Input file (input3.txt) contents:
        This is line 1
        This is line 2
        This is line 3 followed by blank lines
        
        
        
        This is line 7 with !?@$%^+=&*();

    >Filename to open: input3.txt
    >line 1: This is line 1
    >line 2: This is line 2
    >line 3: This is line 3 followed by blank lines
    >line 4: 
    >line 5: 
    >line 6: 
    >line 7: This is line 7 with !?@$%^+=&*();

 Normal case 3 (file contains exactly 100 lines)
 	Input file (input4.txt) contents:
   this is line # 1
   this is line # 2
   this is line # 3
   this is line # 4
   this is line # 5
   this is line # 6
   this is line # 7
   this is line # 8
   this is line # 9
   this is line # 10
   this is line # 11
   this is line # 12
   this is line # 13
   this is line # 14
   this is line # 15
   this is line # 16
   this is line # 17
   this is line # 18
   this is line # 19
   this is line # 20
   this is line # 21
   this is line # 22
   this is line # 23
   this is line # 24
   this is line # 25
   this is line # 26
   this is line # 27
   this is line # 28
   this is line # 29
   this is line # 30
   this is line # 31
   this is line # 32
   this is line # 33
   this is line # 34
   this is line # 35
   this is line # 36
   this is line # 37
   this is line # 38
   this is line # 39
   this is line # 40
   this is line # 41
   this is line # 42
   this is line # 43
   this is line # 44
   this is line # 45
   this is line # 46
   this is line # 47
   this is line # 48
   this is line # 49
   this is line # 50
   this is line # 51
   this is line # 52
   this is line # 53
   this is line # 54
   this is line # 55
   this is line # 56
   this is line # 57
   this is line # 58
   this is line # 59
   this is line # 60
   this is line # 61
   this is line # 62
   this is line # 63
   this is line # 64
   this is line # 65
   this is line # 66
   this is line # 67
   this is line # 68
   this is line # 69
   this is line # 70
   this is line # 71
   this is line # 72
   this is line # 73
   this is line # 74
   this is line # 75
   this is line # 76
   this is line # 77
   this is line # 78
   this is line # 79
   this is line # 80
   this is line # 81
   this is line # 82
   this is line # 83
   this is line # 84
   this is line # 85
   this is line # 86
   this is line # 87
   this is line # 88
   this is line # 89
   this is line # 90
   this is line # 91
   this is line # 92
   this is line # 93
   this is line # 94
   this is line # 95
   this is line # 96
   this is line # 97
   this is line # 98
   this is line # 99
   this is line # 100

    >Filename to open: input4.txt
    >line 1: this is line # 1
    >line 2: this is line # 2
    >line 3: this is line # 3
    >line 4: this is line # 4
    >line 5: this is line # 5
    >line 6: this is line # 6
    >line 7: this is line # 7
    >line 8: this is line # 8
    >line 9: this is line # 9
    >line 10: this is line # 10
    >line 11: this is line # 11
    >line 12: this is line # 12
    >line 13: this is line # 13
    >line 14: this is line # 14
    >line 15: this is line # 15
    >line 16: this is line # 16
    >line 17: this is line # 17
    >line 18: this is line # 18
    >line 19: this is line # 19
    >line 20: this is line # 20
    >line 21: this is line # 21
    >line 22: this is line # 22
    >line 23: this is line # 23
    >line 24: this is line # 24
    >line 25: this is line # 25
    >line 26: this is line # 26
    >line 27: this is line # 27
    >line 28: this is line # 28
    >line 29: this is line # 29
    >line 30: this is line # 30
    >line 31: this is line # 31
    >line 32: this is line # 32
    >line 33: this is line # 33
    >line 34: this is line # 34
    >line 35: this is line # 35
    >line 36: this is line # 36
    >line 37: this is line # 37
    >line 38: this is line # 38
    >line 39: this is line # 39
    >line 40: this is line # 40
    >line 41: this is line # 41
    >line 42: this is line # 42
    >line 43: this is line # 43
    >line 44: this is line # 44
    >line 45: this is line # 45
    >line 46: this is line # 46
    >line 47: this is line # 47
    >line 48: this is line # 48
    >line 49: this is line # 49
    >line 50: this is line # 50
    >line 51: this is line # 51
    >line 52: this is line # 52
    >line 53: this is line # 53
    >line 54: this is line # 54
    >line 55: this is line # 55
    >line 56: this is line # 56
    >line 57: this is line # 57
    >line 58: this is line # 58
    >line 59: this is line # 59
    >line 60: this is line # 60
    >line 61: this is line # 61
    >line 62: this is line # 62
    >line 63: this is line # 63
    >line 64: this is line # 64
    >line 65: this is line # 65
    >line 66: this is line # 66
    >line 67: this is line # 67
    >line 68: this is line # 68
    >line 69: this is line # 69
    >line 70: this is line # 70
    >line 71: this is line # 71
    >line 72: this is line # 72
    >line 73: this is line # 73
    >line 74: this is line # 74
    >line 75: this is line # 75
    >line 76: this is line # 76
    >line 77: this is line # 77
    >line 78: this is line # 78
    >line 79: this is line # 79
    >line 80: this is line # 80
    >line 81: this is line # 81
    >line 82: this is line # 82
    >line 83: this is line # 83
    >line 84: this is line # 84
    >line 85: this is line # 85
    >line 86: this is line # 86
    >line 87: this is line # 87
    >line 88: this is line # 88
    >line 89: this is line # 89
    >line 90: this is line # 90
    >line 91: this is line # 91
    >line 92: this is line # 92
    >line 93: this is line # 93
    >line 94: this is line # 94
    >line 95: this is line # 95
    >line 96: this is line # 96
    >line 97: this is line # 97
    >line 98: this is line # 98
    >line 99: this is line # 99
    >line 100: this is line # 100

 Normal case 4 (file contains more than 100 lines)
  Input file (input5.txt) contents:
   this is line # 1
   this is line # 2
   this is line # 3
   this is line # 4
   this is line # 5
   this is line # 6
   this is line # 7
   this is line # 8
   this is line # 9
   this is line # 10
   this is line # 11
   this is line # 12
   this is line # 13
   this is line # 14
   this is line # 15
   this is line # 16
   this is line # 17
   this is line # 18
   this is line # 19
   this is line # 20
   this is line # 21
   this is line # 22
   this is line # 23
   this is line # 24
   this is line # 25
   this is line # 26
   this is line # 27
   this is line # 28
   this is line # 29
   this is line # 30
   this is line # 31
   this is line # 32
   this is line # 33
   this is line # 34
   this is line # 35
   this is line # 36
   this is line # 37
   this is line # 38
   this is line # 39
   this is line # 40
   this is line # 41
   this is line # 42
   this is line # 43
   this is line # 44
   this is line # 45
   this is line # 46
   this is line # 47
   this is line # 48
   this is line # 49
   this is line # 50
   this is line # 51
   this is line # 52
   this is line # 53
   this is line # 54
   this is line # 55
   this is line # 56
   this is line # 57
   this is line # 58
   this is line # 59
   this is line # 60
   this is line # 61
   this is line # 62
   this is line # 63
   this is line # 64
   this is line # 65
   this is line # 66
   this is line # 67
   this is line # 68
   this is line # 69
   this is line # 70
   this is line # 71
   this is line # 72
   this is line # 73
   this is line # 74
   this is line # 75
   this is line # 76
   this is line # 77
   this is line # 78
   this is line # 79
   this is line # 80
   this is line # 81
   this is line # 82
   this is line # 83
   this is line # 84
   this is line # 85
   this is line # 86
   this is line # 87
   this is line # 88
   this is line # 89
   this is line # 90
   this is line # 91
   this is line # 92
   this is line # 93
   this is line # 94
   this is line # 95
   this is line # 96
   this is line # 97
   this is line # 98
   this is line # 99
   this is line # 100
   this is line # 101
   this is line # 102
   this is line # 103
   this is line # 104
   this is line # 105
   this is line # 106
   this is line # 107
   this is line # 108
   this is line # 109
   this is line # 110
   this is line # 111
   this is line # 112
   this is line # 113
   this is line # 114
   this is line # 115
   this is line # 116
   this is line # 117
   this is line # 118
   this is line # 119
   this is line # 120
   this is line # 121
   this is line # 122
   this is line # 123
   this is line # 124
   this is line # 125
   this is line # 126
   this is line # 127
   this is line # 128
   this is line # 129
   this is line # 130
   this is line # 131
   this is line # 132
   this is line # 133
   this is line # 134
   this is line # 135
   this is line # 136
   this is line # 137
   this is line # 138
   this is line # 139
   this is line # 140
   this is line # 141
   this is line # 142
   this is line # 143
   this is line # 144
   this is line # 145
   this is line # 146
   this is line # 147
   this is line # 148
   this is line # 149
   this is line # 150
   this is line # 151
   this is line # 152
   this is line # 153
   this is line # 154
   this is line # 155
   this is line # 156
   this is line # 157
   this is line # 158
   this is line # 159
   this is line # 160
   this is line # 161
   this is line # 162
   this is line # 163
   this is line # 164
   this is line # 165
   this is line # 166
   this is line # 167
   this is line # 168
   this is line # 169
   this is line # 170
   this is line # 171
   this is line # 172
   this is line # 173
   this is line # 174
   this is line # 175
   this is line # 176
   this is line # 177
   this is line # 178
   this is line # 179
   this is line # 180
   this is line # 181
   this is line # 182
   this is line # 183
   this is line # 184
   this is line # 185
   this is line # 186
   this is line # 187
   this is line # 188
   this is line # 189
   this is line # 190
   this is line # 191
   this is line # 192
   this is line # 193
   this is line # 194
   this is line # 195
   this is line # 196
   this is line # 197
   this is line # 198
   this is line # 199
   this is line # 200

    >Filename to open: input5.txt
    >line 1: this is line # 1
    >line 2: this is line # 2
    >line 3: this is line # 3
    >line 4: this is line # 4
    >line 5: this is line # 5
    >line 6: this is line # 6
    >line 7: this is line # 7
    >line 8: this is line # 8
    >line 9: this is line # 9
    >line 10: this is line # 10
    >line 11: this is line # 11
    >line 12: this is line # 12
    >line 13: this is line # 13
    >line 14: this is line # 14
    >line 15: this is line # 15
    >line 16: this is line # 16
    >line 17: this is line # 17
    >line 18: this is line # 18
    >line 19: this is line # 19
    >line 20: this is line # 20
    >line 21: this is line # 21
    >line 22: this is line # 22
    >line 23: this is line # 23
    >line 24: this is line # 24
    >line 25: this is line # 25
    >line 26: this is line # 26
    >line 27: this is line # 27
    >line 28: this is line # 28
    >line 29: this is line # 29
    >line 30: this is line # 30
    >line 31: this is line # 31
    >line 32: this is line # 32
    >line 33: this is line # 33
    >line 34: this is line # 34
    >line 35: this is line # 35
    >line 36: this is line # 36
    >line 37: this is line # 37
    >line 38: this is line # 38
    >line 39: this is line # 39
    >line 40: this is line # 40
    >line 41: this is line # 41
    >line 42: this is line # 42
    >line 43: this is line # 43
    >line 44: this is line # 44
    >line 45: this is line # 45
    >line 46: this is line # 46
    >line 47: this is line # 47
    >line 48: this is line # 48
    >line 49: this is line # 49
    >line 50: this is line # 50
    >line 51: this is line # 51
    >line 52: this is line # 52
    >line 53: this is line # 53
    >line 54: this is line # 54
    >line 55: this is line # 55
    >line 56: this is line # 56
    >line 57: this is line # 57
    >line 58: this is line # 58
    >line 59: this is line # 59
    >line 60: this is line # 60
    >line 61: this is line # 61
    >line 62: this is line # 62
    >line 63: this is line # 63
    >line 64: this is line # 64
    >line 65: this is line # 65
    >line 66: this is line # 66
    >line 67: this is line # 67
    >line 68: this is line # 68
    >line 69: this is line # 69
    >line 70: this is line # 70
    >line 71: this is line # 71
    >line 72: this is line # 72
    >line 73: this is line # 73
    >line 74: this is line # 74
    >line 75: this is line # 75
    >line 76: this is line # 76
    >line 77: this is line # 77
    >line 78: this is line # 78
    >line 79: this is line # 79
    >line 80: this is line # 80
    >line 81: this is line # 81
    >line 82: this is line # 82
    >line 83: this is line # 83
    >line 84: this is line # 84
    >line 85: this is line # 85
    >line 86: this is line # 86
    >line 87: this is line # 87
    >line 88: this is line # 88
    >line 89: this is line # 89
    >line 90: this is line # 90
    >line 91: this is line # 91
    >line 92: this is line # 92
    >line 93: this is line # 93
    >line 94: this is line # 94
    >line 95: this is line # 95
    >line 96: this is line # 96
    >line 97: this is line # 97
    >line 98: this is line # 98
    >line 99: this is line # 99
    >line 100: this is line # 100


 Bad Data case 1 (no file exists):
    Input file does not exist.

    >Filename to open: input1000.txt
    >File does not exist!
 
 Bad Data case 2 (illegal characters in filename input)
    Input file does not exist because it is an illegal filename.

    >Filename to open: !?@$%^+=&*();
    >File does not exist!
 
 Bad Data case 3 (empty file)
    Input file (input2.txt) contents should be none. In unix, execute "> input2.txt" without quotations. 
    
    >Filename to open: input2.txt
    (No output)

 Discussion:
 	The program will load 100 lines from the input file into an array of 100 string objects. If the input file exceeds 100 lines, the rest 
 	are ignored; only the first 100 are read. If the input file contains less than 100 lines, all available lines are read. 

 	The test input files input4.txt and input5.txt were generated with unix command lines:

 	input4.txt:
 	i=0; while [ $i -lt 100 ]; do i=$(($i + 1)); echo "this is line # $i" >> input4.txt; done

	input5.txt
	i=0; while [ $i -lt 200 ]; do i=$(($i + 1)); echo "this is line # $i" >> input5.txt; done
 
   The program returns an int as per the C++ standard. The retun value is 0 unless the input file cannot be opened. 

   All testing performed in a Linux environment with g++ version 7.5.0.
*/

#include <iostream> // Stream declarations
#include <fstream> // I/O stream declarations
using namespace std;

int main(void) {
	string string_store[100];
	fstream in;
	string line;
	string filename;

	//Get filename to open from user.
	cout << "Filename to open: ";
	cin >> filename;
	in.open(filename);

    //Check if input file exists.
    if (! in) {
    	cout << "File does not exist!" << endl;
    	return 1;
    }

    for (int i = 0; i <= 99; i++) {

    	//If at eof, then break.
    	if (! getline(in, line)) {
    		break;
    	}

    	//Store the line text. 
    	string_store[i] = line;

    	//Print the line text prefixed by the line number (loop counter + 1).
    	cout << "line " << i + 1 << ": " << string_store[i] << endl;
    }

    return 0;
}

