#include <bits/stdc++.h>
#include "testlib.h"

#define Y_SYM "Y"
#define Y_MIN 1990
#define Y_MAX 3000
#define M_SYM "M"
#define M_MIN 1
#define M_MAX 12
#define D_SYM "D"
#define D_MIN 1
#define T_SYM "T"
#define T_MIN 0
#define T_MAX 10'000
#define N_SYM "N"
#define N_MIN 0
#define N_MAX 100
#define Q_OPER_SYM "Q_OPER"
#define Q_OPER_MIN 1
#define Q_OPER_MAX 3
#define Q_1_CODE 1
#define Q_1_C_SYM "Q_1_C"
#define Q_1_C_MIN 0
#define Q_1_C_MAX 10'000
#define Q_1_D_SYM "Q_1_D"
#define Q_1_D_MIN 1
#define Q_1_D_MAX 30
#define Q_2_CODE 2
#define Q_2_C_SYM "Q_2_C"
#define Q_2_C_MIN 0
#define Q_2_C_MAX 10'000
#define Q_2_D_SYM "Q_2_D"
#define Q_2_D_MIN 1
#define Q_2_D_MAX 15
#define Q_3_CODE 3
#define Q_3_C_SYM "Q_3_C"
#define Q_3_C_MIN 0
#define Q_3_C_MAX 10'000
#define Q_3_M_SYM "Q_3_M"
#define Q_3_M_MIN 6
#define Q_3_M_MAX 48
#define ERR_COMMENT_DATE1_MUST_FAST_THEN_DATE2 "First date must be fast than second date."
#define ERR_COMMENT_NOT_RANGE "Some parameter is out of range."

using namespace std;

int dtoi(int y, int m, int d) {
  int result = 0;
  for (int i = Y_MIN; i < y; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) result += 366;
    else result += 365;
  }
  for (int i = M_MIN; i < m; i++) {
    switch (i) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        result += 31;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        result += 30;
        break;
      case 2:
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) result += 29;
        else result += 28;
        break;
    }
  }
  result += d;
  return result;
}

void validate_date(int y, int m, int d) {
  switch (m) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      ensuref(D_MIN <= d && d <= 31, ERR_COMMENT_NOT_RANGE);
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      ensuref(D_MIN <= d && d <= 30, ERR_COMMENT_NOT_RANGE);
      break;
    case 2:
      if (y % 4 == 0 && y % 100 != 0 || (y % 400 == 0))
        ensuref(D_MIN <= d && d <= 29, ERR_COMMENT_NOT_RANGE);
      else
        ensuref(D_MIN <= d && d <= 28, ERR_COMMENT_NOT_RANGE);
      break;
    default:
      ensuref(false, ERR_COMMENT_NOT_RANGE);
      break;
  }
}

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int y1 = inf.readInt(Y_MIN, Y_MAX, Y_SYM);
  inf.readSpace();
  // int m1 = inf.readInt(M_MIN, M_MAX, M_SYM);
  string m1_raw = inf.readToken("[0-9]{2}", M_SYM);
  int m1_int = stoi(m1_raw);
  ensuref(M_MIN <= m1_int && m1_int <= M_MAX, ERR_COMMENT_NOT_RANGE);
  inf.readSpace();
  // int d1 = inf.readInt(D_MIN, D_MAX, D_SYM);
  string d1_raw = inf.readToken("[0-9]{2}", D_SYM);
  int d1_int = stoi(d1_raw);
  validate_date(y1, m1_int, d1_int);
  inf.readEoln();

  int y2 = inf.readInt(Y_MIN, Y_MAX, Y_SYM);
  inf.readSpace();
  // int m2 = inf.readInt(M_MIN, M_MAX, M_SYM);
  string m2_raw = inf.readToken("[0-9]{2}", M_SYM);
  int m2_int = stoi(m2_raw);
  ensuref(M_MIN <= m2_int && m2_int <= M_MAX, ERR_COMMENT_NOT_RANGE);
  inf.readSpace();
  // int d2 = inf.readInt(D_MIN, D_MAX, D_SYM);
  string d2_raw = inf.readToken("[0-9]{2}", D_SYM);
  int d2_int = stoi(d2_raw);
  validate_date(y2, m2_int, d2_int);
  inf.readEoln();

  ensuref(dtoi(y1, m1_int, d1_int) < dtoi(y2, m2_int, d2_int), ERR_COMMENT_DATE1_MUST_FAST_THEN_DATE2);
  
  int t = inf.readInt(T_MIN, T_MAX, T_SYM);
  inf.readSpace();
  int n = inf.readInt(N_MIN, N_MAX, N_SYM);
  inf.readEoln();

  int c, d, m;
  for (int i = 0; i < n; i++) {
    int q_oper = inf.readInt(Q_OPER_MIN, Q_OPER_MAX, Q_OPER_SYM);
    inf.readSpace();
    switch (q_oper) {
      case Q_1_CODE:
        c = inf.readInt(Q_1_C_MIN, Q_1_C_MAX, Q_1_C_SYM);
        inf.readSpace();
        d = inf.readInt(Q_1_D_MIN, Q_1_D_MAX, Q_1_D_SYM);
        inf.readEoln();
        break;
      case Q_2_CODE:
        c = inf.readInt(Q_2_C_MIN, Q_2_C_MAX, Q_2_C_SYM);
        inf.readSpace();
        d = inf.readInt(Q_2_D_MIN, Q_2_D_MAX, Q_2_D_SYM);
        inf.readEoln();
        break;
      case Q_3_CODE:
        c = inf.readInt(Q_3_C_MIN, Q_3_C_MAX, Q_3_C_SYM);
        inf.readSpace();
        m = inf.readInt(Q_3_M_MIN, Q_3_M_MAX, Q_3_M_SYM);
        inf.readEoln();
        break;
    }
  }

  inf.readEof();

  return 0;
}
