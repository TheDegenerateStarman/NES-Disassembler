#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>
#include <fstream>

typedef unsigned char byte;
typedef unsigned short word;

extern const char* OP_FILE;
extern const char* HEX;
extern const byte NIBBLE_MASK;
extern const byte BYTE_MASK;

enum : char {accu, imme, impl, rela, abso, zero, indi, aIndX, aIndY, zIndX, zIndY, indXI, indYI, iIndX, iIndY};

template <int bitno, typename T = byte>
struct Bit{
    byte data;
    enum {mask = 1u << bitno};
    bool operator () () const {
    	return !!(data & mask);
    }
};

union FlagByte{
    byte data;
    
    Bit<0> b0;
    Bit<1> b1;
    Bit<2> b2;
    Bit<3> b3;
    Bit<4> b4;
    Bit<5> b5;
    Bit<6> b6;
    Bit<7> b7;
};

inline void addHexNibble(byte c, std::string& s){
    s += HEX[c & NIBBLE_MASK];
}

inline void addHexByte(byte c, std::string& s){
    s += HEX[c >> 4];
    s += HEX[c & NIBBLE_MASK];
}

inline void addHexWord(word c, std::string& s){
    s += HEX[c >> 12];
    s += HEX[(c >> 8) & NIBBLE_MASK];
    s += HEX[(c >> 4) & NIBBLE_MASK];
    s += HEX[c & NIBBLE_MASK];
}

#endif
