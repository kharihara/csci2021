/* 
 * CS:APP Data Lab 
 * 
 * <Karthik Harihara>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
 return ~(x&y) & ~(~x&~y);// Through demorgan's law, statment equals (~x or ~y) and (x or y) which equates to xor. 
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
int word= 0x55|(0x55<<8);//0x55 has val of 01010101 (even bit is 1).
return word|(word<<16);//shift bit pattern through rest of bit string
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  return x & (~x+1); // (~x +1) is the negative value of x. anding with x gives the leastbitpos with 1 
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
XOR means not equal. Thus NOT XOR signifies the values are equal
 */
int isEqual(int x, int y) {
return !(x^y);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
int num= 33  +(~n);//finds the number of higher order bits
int fill= (x<<num)>>num;; // fills the higher order bits with the sign bit of x 

  return !(x^fill); // returns if the number is equal to the fill.
}
/* 

 * reverseBytes - reverse the bytes of x

 *   Example: reverseBytes(0x01020304) = 0x04030201

 *   Legal ops: ! ~ & ^ | + << >>

 *   Max ops: 25

 *   Rating: 3
each byte, which consits of 8 bits, is found through right shifting the proper amount and masking it with 255 which corresponds to 000...11111111 

 */
int reverseBytes(int x) {
 
int byte4= (x>>24) & 255 ;
int byte3= (x>>16) & 255 ;
int byte2= (x>>8) &  255;
int byte1= x & 255;

 return (byte1<<24) |( byte2<<16) | (byte3<<8) | byte4 ;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: o8
 *   Rating: 3
 */
int isPositive(int x) {
 int neg= 1<<31; //create mask with 1 as msb
int zero = !x;// check for zero
 return !(( x&neg) | zero); // check if not negative

}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
  */
int multFiveEighths(int x) {

int mul= (x<<2) + x;// multiply by 5 

int negcheck= 7 & (mul >>31); // adds 2^3 -1 to mul if mul negative
int div= (mul + negcheck) >>3;//add negcheck to mul and then divides by 8

return div;
  
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
int dif= ((x + (~y))>>31) &1;//take difference between x and y and finds it sign

int signofx= (x>>31) &1;//finds sign of x
int signofy= (y>>31) &1;//finds sign of y

int checkdif= (!(signofx^signofy)) & dif;// checks if sign of x and y are equal and sees if the sign of the difference is negative meaning x is less than y  

 
  return checkdif | ((!signofy) & (signofx)); // if checkdif true or if y is negative.

}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
x= x & (~x+1);//leastbitpos
x= ~x+1; // negative of leastbitpos
return (~(x>>31)) &1; // negate 
}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
int m= x>>31;//creates mask that gets msb
int s= (x+m)^m; //gives absolute value. 
return s | (x & (m<<31) ); // adds the sign bit. m<<31 has value of 1000...0000 

}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
int s;
int e= !(~x);//gives value of one when x is all 1's
int res= !(~(x>>16)) <<4;//check first 16 bits. Statment will yeild 1 if all 16 bits are 1. val of 0 or 16
x=x<<res;// shifts bits


s= !(~(x>>24))<<3; // examine next 8 bits. val of 0 or 8
 x=x<<s;
res= res | s;

s= !(~(x>>28))<<2;// examine next 4 bits val of 0 or 4
x= x<<s;
res =res|s;

s=!(~(x>>30)) <<1;//next 2 bits. val of 0 or 2
x= x << s;
 res= res|s;

res= res^(1&((x>>31)));//last bit is seen. val of 0 or 1

return res + e;
 
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 int NaN = 0xFF<<23 ; //nan is when all exp are set to 1. 
 int NanCheck= NaN & uf; //checks if exp is all 1.
int frac= 0x7FFFFF &uf; // frac value of uf hex value corresponds to 23 frac bits set to 1.

if( (NanCheck == NaN) && (frac))//return uf if uf has NaN value and if frac value is not all zeros showing NaN.  

return uf;
else
return uf^(1<<31);//flips sign bit to change sign of float.  
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
 

  int round = !((uf&3)^3); // rounds last two bits
  int neg = 1<<31;//sign bit
  int inf = 0xFF<<23;//infiinty mask 
  int frac = 0x7FFFFF;// mask for 23 frac bits
  int ones= 0x7FFFFFFF;// all 1's expect first bit
  int negDenorm= 0x807FFFFF; // mask for denorm value
 int  exps = uf&inf; // gets the exponent part of float
  if (exps==inf) return uf; // check for NaN and infinity
  if (exps==0x800000) //special case where with only the first bit of frac set to 1 
    return (uf&neg) | (round + ((uf & ones)>>1)) ;  
  
  
  if (exps==0) //denormalized 
    return (uf &neg) |(((uf&frac)>>1) + round);
 
  
  return (((exps>>23)-1)<<23) | (uf & negDenorm);//normalized 

}


