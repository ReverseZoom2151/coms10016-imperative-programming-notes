#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

enum { G1, G21, G22, G3, Fail, Invalid };

bool digit(char c) {
    return (('0' <= c) && (c <= '9'));
}

int convert(int n, const char mark[]) {
    int result;
    if (n == 1) {
        if (!digit(mark[0])) result = -1;
        else result = mark[0] - '0';
    } else if (n == 2) {
        if ((!digit(mark[0])) || (!digit(mark[1]))) result = -1;
        else if (mark[0] == '0') result = -1;
        else result = 10 * (mark[0] - '0') + (mark[1] - '0');
    } else if (n == 3) {
        if ((mark[0] != '1') || (mark[1] != '0') || (mark[2] != '0')) result = -1;
        else result = 100;
    } else result = -1;
    return result;
}

int grade(int m) {
    int result;
    if (m < 0) result = Invalid;
    else if (m < 40) result = Fail;
    else if (m < 50) result = G3;
    else if (m < 60) result = G22;
    else if (m < 70) result = G21;
    else if (m < 101) result = G1;
    else result = Invalid;
    return result;
}

void print(int grade) {
    if (grade == G1) printf("First\n");
    else if (grade == G21) printf("Upper second\n");
    else if (grade == G22) printf("Lower second\n");
    else if (grade == G3) printf("Third\n");
    else if (grade == Fail) printf("Fail\n");
    else if (grade == Invalid) printf("Invalid mark\n");
}

void checkConstants() {
    assert(G1 == 0 && G21 == 1 && G22 == 2 && G3 == 3 && Fail == 4 && Invalid == 5);
}

void testGrade() {
    assert(grade(0) == Fail);
    assert(grade(39) == Fail);
    assert(grade(40) == G3);
    assert(grade(49) == G3);
    assert(grade(50) == G22);
    assert(grade(59) == G22);
    assert(grade(60) == G21);
    assert(grade(69) == G21);
    assert(grade(70) == G1);
    assert(grade(100) == G1);
    assert(grade(-1) == Invalid);
    assert(grade(101) == Invalid);
}

void testConvert() {
    assert(convert(1, "0") == 0);
    assert(convert(1, "9") == 9);
    assert(convert(2, "10") == 10);
    assert(convert(2, "99") == 99);
    assert(convert(3, "100") == 100);
}

void testValidity() {
    assert(convert(4, "40.5") == -1);
    assert(convert(1, "x") == -1);
    assert(convert(2, "-1") == -1);
    assert(convert(4, "40x5") == -1);
    assert(convert(3, " 40") == -1);
    assert(convert(3, "101") == -1);
    assert(convert(3, "547") == -1);
    assert(convert(3, "040") == -1);
}

void test() {
    checkConstants();
    testGrade();
    testConvert();
    testValidity();
    printf("All tests pass\n");
}

int main(int n, char *args[n]) {
    setbuf(stdout, NULL);
    if (n == 1) test();
    else if (n == 2) print(grade(convert(strlen(args[1]), args[1])));
    else {
        fprintf(stderr, "Use:   ./grade   or   ./grade m\n");
        fprintf(stderr, "where m is an integer mark from 0 to 100\n");
        return 1;
    }
    return 0;
}
