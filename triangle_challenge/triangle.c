#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

enum { Equilateral, Isosceles, Right, Scalene, Flat, Impossible, Illegal };

bool checkDigit(char c) {
    return (('0' <= c) && (c <= '9'));
}

int convert(const char length[]) {
    long digitMultiplier = 1;
    long result = 0;
    bool valid = 1;

    for(int i = strlen(length) - 1; i >= 0; i--) {
        if (valid && (!checkDigit(length[i]))) {
            valid = 0;
            result = -1;
        } else if (valid) {
            int digit = length[i] - '0';
            result +=  digit * digitMultiplier;
            digitMultiplier = digitMultiplier * 10;
            if (length[0] == '0') result = -1;
            if (result > INT_MAX) result = -1;
        }
    }

    return result;
}

int checkImpossible(long a, long b, long c) {
    return ((b + c) < a) ? Impossible : -1;
}

int checkFlat(long a, long b, long c) {
    return ((b + c) == a) ? Flat : -1;
}

int checkEquilateral(long a, long b, long c) {
    return (a == b) && (a == c) && (b == c) ? Equilateral : -1;
}

int checkIsosceles(long a, long b, long c) {
    return (a == b) || (a == c) || (b == c) ? Isosceles : -1;
}

int checkRightAngle(long a, long b, long c) {
    return ((b * b) + (c * c)) == a * a ? Right : -1;
}

int checkScalene(long a, long b, long c) {
    return (a != b) && (a != c) && (b != c) ? Scalene : -1;
}

int checkIllegal(long a, long b, long c) {
    return (a < 0) || (b < 0) || (c < 0) ? Illegal : -1;
}

int triangle(int a, int b, int c) {
    long totalLengths = (long)a + (long)b + (long)c;
    long longestSide = a > b ? (a > c ? a : c) : (b > c ? b : c);
    long shortestSide = a < b ? (a < c ? a : c) : (b < c ? b : c);
    long middleSide = totalLengths - (longestSide + shortestSide);

    int triangleType = Illegal;

    if (checkIllegal(longestSide, shortestSide, middleSide) == Illegal) triangleType = Illegal;
    else if (checkImpossible(longestSide, shortestSide, middleSide) == Impossible) triangleType = Impossible;
    else if (checkFlat(longestSide, shortestSide, middleSide) == Flat) triangleType = Flat;
    else if (checkEquilateral(longestSide, shortestSide, middleSide) == Equilateral) triangleType = Equilateral;
    else if (checkIsosceles(longestSide, shortestSide, middleSide) == Isosceles) triangleType = Isosceles;
    else if (checkRightAngle(longestSide, shortestSide, middleSide) == Right) triangleType = Right;
    else if (checkScalene(longestSide, shortestSide, middleSide) == Scalene) triangleType = Scalene;
    return triangleType;
}

void print(int type) {
    switch (type) {
        case Equilateral: printf("Equilateral"); break;
        case Isosceles: printf("Isosceles"); break;
        case Right: printf("Right"); break;
        case Scalene: printf("Scalene"); break;
        case Flat: printf("Flat"); break;
        case Impossible: printf("Impossible"); break;
        case Illegal: printf("Illegal"); break;
    }
    printf("\n");
}

void assert(int line, bool b) {
    if (b) return;
    printf("The test on line %d fails.\n", line);
    exit(1);
}

void checkConstants() {
    assert(__LINE__, Equilateral==0 && Isosceles==1 && Right==2 && Scalene==3);
    assert(__LINE__, Flat==4 && Impossible==5 && Illegal==6);
}

void testEquilateral() {
    assert(__LINE__, triangle(8, 8, 8) == Equilateral);
    assert(__LINE__, triangle(1073, 1073, 1073) == Equilateral);
}

void testIsosceles() {
    assert(__LINE__, triangle(25, 25, 27) == Isosceles);
    assert(__LINE__, triangle(25, 27, 25) == Isosceles);
    assert(__LINE__, triangle(27, 25, 25) == Isosceles);
}

void testRight() {
    assert(__LINE__, triangle(3, 4, 5) == Right);
    assert(__LINE__, triangle(3, 5, 4) == Right);
    assert(__LINE__, triangle(5, 3, 4) == Right);
    assert(__LINE__, triangle(5, 12, 13) == Right);
    assert(__LINE__, triangle(5, 13, 12) == Right);
    assert(__LINE__, triangle(12, 5, 13) == Right);
    assert(__LINE__, triangle(12, 13, 5) == Right);
    assert(__LINE__, triangle(13, 5, 12) == Right);
    assert(__LINE__, triangle(13, 12, 5) == Right);
}

void testScalene() {
    assert(__LINE__, triangle(12, 14, 15) == Scalene);
    assert(__LINE__, triangle(12, 15, 14) == Scalene);
    assert(__LINE__, triangle(14, 12, 15) == Scalene);
    assert(__LINE__, triangle(14, 15, 12) == Scalene);
    assert(__LINE__, triangle(15, 12, 14) == Scalene);
    assert(__LINE__, triangle(15, 14, 12) == Scalene);
}

void testFlat() {
    assert(__LINE__, triangle(7, 9, 16) == Flat);
    assert(__LINE__, triangle(7, 16, 9) == Flat);
    assert(__LINE__, triangle(9, 16, 7) == Flat);
    assert(__LINE__, triangle(16, 7, 9) == Flat);
    assert(__LINE__, triangle(16, 9, 7) == Flat);
}

void testImpossible() {
    assert(__LINE__, triangle(2, 3, 13) == Impossible);
    assert(__LINE__, triangle(2, 13, 3) == Impossible);
    assert(__LINE__, triangle(3, 2, 13) == Impossible);
    assert(__LINE__, triangle(3, 13, 2) == Impossible);
    assert(__LINE__, triangle(13, 2, 3) == Impossible);
    assert(__LINE__, triangle(13, 3, 2) == Impossible);
}

void testConvert() {
    assert(__LINE__, convert("1") == 1);
    assert(__LINE__, convert("12345678") == 12345678);
    assert(__LINE__, convert("2147483647") == 2147483647);
    assert(__LINE__, convert("2147483648") == -1);
    assert(__LINE__, convert("2147483649") == -1);
    assert(__LINE__, convert("0") == -1);
    assert(__LINE__, convert("-1") == -1);
    assert(__LINE__, convert("-2") == -1);
    assert(__LINE__, convert("-2147483648") == -1);
    assert(__LINE__, convert("x") == -1);
    assert(__LINE__, convert("4y") == -1);
    assert(__LINE__, convert("13.4") == -1);
    assert(__LINE__, convert("03") == -1);
}

void testOverflow() {
    assert(__LINE__, triangle(2147483647,2147483647,2147483646) == Isosceles);
    assert(__LINE__, triangle(2147483645,2147483646,2147483647) == Scalene);
    assert(__LINE__, triangle(2147483647,2147483647,2147483647) == Equilateral);
    assert(__LINE__, triangle(1100000000,1705032704,1805032704) == Scalene);
    assert(__LINE__, triangle(2000000001,2000000002,2000000003) == Scalene);
    assert(__LINE__, triangle(150000002,666666671,683333338) == Scalene);
}

void test() {
    checkConstants();
    testEquilateral();
    testIsosceles();
    testRight();
    testScalene();
    testFlat();
    testImpossible();
    testConvert();
    testOverflow();
    printf("All tests passed\n");
}

int main(int n, char *args[n]) {
    setbuf(stdout, NULL);
    if (n == 1) {
        test();
    } else if (n == 4) {
        int a = convert(args[1]), b = convert(args[2]), c = convert(args[3]);
        int result = triangle(a, b, c);
        print(result);
    } else {
        fprintf(stderr, "Use e.g.: ./triangle 3 4 5\n");
        exit(1);
    }
    return 0;
}
