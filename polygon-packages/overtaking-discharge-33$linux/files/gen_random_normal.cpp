#define IS_RUNTIME_POLYGON true
#define YEAR_AVAILABLE_MIN 1900
#define YEAR_AVAILABLE_MAX 3000
#define P_RANGE_INIT 0
#define P_RANGE_FIN 10'000
#define N_RANGE_INIT 0
#define N_RANGE_FIN 100
#define C_RANGE_INIT P_RANGE_INIT
#define C_RANGE_FIN P_RANGE_FIN
#define D_REST_RANGE_INIT 1
#define D_REST_RANGE_FIN 30
#define D_GULAG_RANGE_INIT 1
#define D_GULAG_RANGE_FIN 15
#define M_RANGE_INIT 6
#define M_RANGE_FIN 48
#define Y_MIN 1990
#define Y_MAX 3000
#define M_MIN 1
#define M_MAX 12
#define D_MIN 1
 
#include <bits/stdc++.h>
#if IS_RUNTIME_POLYGON
#include "testlib.h"
#endif
 
using namespace std;
 
void validate_arg(int p, int n) {
  if (p < P_RANGE_INIT || p > P_RANGE_FIN) exit(1);
  if (n < N_RANGE_INIT || n > N_RANGE_FIN) exit(1);
}

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

inline int get_last_day(int year, int month) {
  switch (month)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
    break;
  case 2:
    if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
      return 29;
    return 28;
    break;
  default:
    return -1;
    break;
  }
}
 
inline int gen_random(int init, int fin) {
  #if IS_RUNTIME_POLYGON
  return rnd.next(init, fin);
  #else
  random_device rnd;
  mt19937 gen(rnd());
  uniform_int_distribution<> dist(init, fin);
  return dist(gen);
  #endif
}
 
tm get_random_date() {
  int y = gen_random(YEAR_AVAILABLE_MIN, YEAR_AVAILABLE_MAX), m = gen_random(1, 12), d = gen_random(1, get_last_day(y, m));
  tm result = {0, 0, 0, d, m, y};
  return result;
}
 
int main(int argc, char* argv[]) {
  // Init
  #if IS_RUNTIME_POLYGON
  registerGen(argc, argv, 1);
  #endif
 
  // (input line 1~2) Generate Enrollment Date of Jonghyeon and Yeongdo.
  int y1 = gen_random(Y_MIN, Y_MAX), y2 = gen_random(Y_MIN, Y_MAX);
  int m1 = gen_random(M_MIN, M_MAX), m2 = gen_random(M_MIN, M_MAX);
  int d1 = gen_random(D_MIN, get_last_day(y1, m1)), d2 = gen_random(D_MIN, get_last_day(y2, m2));

  int jonghyeon = dtoi(y1, m1, d1), yeongdo = dtoi(y2, m2, d2);
  if (jonghyeon > yeongdo) {
    swap(y1, y2);
    swap(m1, m2);
    swap(d1, d2);
  }
  cout.fill('0');
  cout << y1 << ' ';
  cout.width(2);
  cout << m1 << ' ';
  cout.width(2);
  cout << d1 << '\n';

  cout << y2 << ' ';
  cout.width(2);
  cout << m2 << ' ';
  cout.width(2);
  cout << d2 << '\n';
 
  // (input line 3) Validate and Print Parameter P and N.
  int p = stoi(argv[1]), n = stoi(argv[2]);
  validate_arg(p, n);
  cout << p << ' ' << n << '\n';
 
  // (input 4~3+n) Generate Operating Query.
  int oper, c, d, m;
  for (int _i = 0; _i < n; _i++) {
    oper = gen_random(1, 3);
    switch (oper)
    {
    case 1:
      c = gen_random(C_RANGE_INIT, min(p, C_RANGE_FIN));
      d = gen_random(D_REST_RANGE_INIT, D_REST_RANGE_FIN);
      cout << 1 << ' ' << c << ' ' << d << '\n';
      break;
    case 2:
      c = gen_random(C_RANGE_INIT, min(p, C_RANGE_FIN));
      d = gen_random(D_GULAG_RANGE_INIT, D_GULAG_RANGE_FIN);
      cout << 2 << ' ' << c << ' ' << d << '\n';
      break;
    case 3:
      c = gen_random(C_RANGE_INIT, min(p, C_RANGE_FIN));
      m = gen_random(M_RANGE_INIT, M_RANGE_FIN);
      cout << 3 << ' ' << c << ' ' << m << '\n';
      break;
    }
  }
 
  return 0;
}
