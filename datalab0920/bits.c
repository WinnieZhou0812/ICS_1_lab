/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return (~(~x & ~y))&(~(x & y));
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    
    if (!(x&&y)){
        if ((!x)&&(!y)){
            return 1;
        }
        else{
            return 0;
        }
    }
    return (!((x>>31) ^ (y>>31)));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int b16=((v>>16)>0)<<4;
    v>>=b16;
    int b8=((v>>8)>0)<<3;
    v>>=b8;
    int b4=((v>>4)>0)<<2;
    v>>=b4;
    int b2=((v>>2)>0)<<1;
    v>>=b2;
    int b1=((v>>1)>0);
    v>>=b1;
    return b16|b8|b4|b2|b1;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int nstep=(n<<3);
    int mstep=(m<<3);
    int n1=(0xFF<<nstep);
    int m1=(0xFF<<mstep);
    int stay=((x&(~(n1|m1))));
    int n_shft=(((x&n1)>>nstep)<<mstep)&m1;
    int m_shft=(((x&m1)>>mstep)<<nstep)&n1;
    return (stay|n_shft|m_shft);
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    int time=16;
    unsigned mask=0x1;
    while(time){
        time=time-1;
        int step1=time;
        int step2=31-time;
        unsigned t1=(mask<<step1);
        unsigned t2=(mask<<step2);
        unsigned right=(((v&t1)>>step1)<<step2);
        unsigned left=(((v&t2)>>step2)<<step1);
        v=((v&~(t1|t2))|right|left);
    }
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask=~(((1<<31)>>n)<<1);
    return (x>>n)&mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int count=0;
    int b16=!((x&0xffff0000)^0xffff0000)<<4;
    x<<=b16;
    int b8=!((x&0xff000000)^0xff000000)<<3;
    x<<=b8;
    int b4=!((x&0xf0000000)^0xf0000000)<<2;
    x<<=b4;
    int b2=!((x&0xc0000000)^0xc0000000)<<1;
    x<<=b2;
    int b1=!((x&0x80000000)^0x80000000);
    x<<=b1;
    int b0=!((x&0x80000000)^0x80000000);
    count=b16+b8+b4+b2+b1+b0;
    return count;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned sign=x&0x80000000;//1
    unsigned ux=x;
    if (sign==0x80000000){//3
        ux=~(ux-1);//5
    }
    unsigned exp=0;
    if(ux==0){//7-1
        return 0;
    }
    while((ux&0x80000000)==0){ // 找第一个出现的1前面的位数. 10
        ux<<=1;//11
        exp=exp+1;//12
    }
    ux<<=1;//13
    unsigned tail=ux&0x000001ff;//14
    if((tail>0x00000100)+((tail==0x00000100)&((ux&0x00000200)>>9))){//21 两种进位情况
        if((ux&0xfffffe00)==0xfffffe00){//24
            exp=exp-1;//25
        }
        ux=ux+0x00000200;//26
    }
    ux=(ux>>9);//27
    exp=158-exp;//28
    ux=(sign|(exp<<23)|ux);//31-1
    return ux;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign=uf&0x80000000;//符号
    unsigned exp=(uf>>23)&0xff;//初始指数+bias
    unsigned frac=uf&0x7fffff;//尾数
    if(exp==0xff){//NaN或者INF
        return uf;
    }
    if(exp==0){//非规格化数：挪尾数+处理上界
        frac=frac<<1;
        if(frac&0x800000){//上界变成规格化数
            exp=exp+1;
            frac=frac&0x7fffff;
        }
    }
    else{//规格化数：加指数+处理上界
        exp=exp+1;
        if(exp==0xff){//变成INF，对应上下无穷
            frac=0;
        }
    }
    uf=(sign|(exp<<23)|frac);
    return uf;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign=uf2>>31;
    unsigned exp=((uf2>>20)&0x7ff);
    if (exp<1023){
        return 0;
    }
    exp=exp-1023;
    unsigned tail=0x80000000|(uf2&0xfffff)<<11|(uf1>>21);
    if (exp>30){
        if (exp>31){
            return 0x80000000;
        }
        else{
            if (!sign){
            return 0x80000000;
            }
            else{
            if(tail>0x80000000){//重点还是在 -min!=max
                return 0x80000000;
            }
            }
        }
    }
    unsigned result=tail>>(31-exp);
    if (sign){
        result=~result+1;
    }
    return result;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    int bias=127;
    if(x>127){
            return 0x7f800000;
    }
    if(x>=-126){
        return (x+bias)<<23;
    }
    if(x<-149){
        return 0;
    }
    return (0x00800000>>(-126-x));
}
