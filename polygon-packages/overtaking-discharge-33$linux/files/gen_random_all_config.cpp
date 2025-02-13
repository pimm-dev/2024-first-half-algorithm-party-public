/*
  gen_random_all_config (year_min) (year_max) (p) (n) (enable_query)
    (query_1_c_min) (query_1_c_max) (query_1_d_min) (query_1_d_max) (query_1_ratio)
    (query_2_c_min) (query_2_c_max) (query_2_d_min) (query_2_d_max) (query_2_ratio)
    (query_3_c_min) (query_3_c_max) (query_3_m_min) (query_3_m_max) (query_3_ratio)

  * if year_min < Y_MIN or year_max > Y_MAX then y will be generated randomly.
  * if p < P_RANGE_INIT then p will be generated randomly.
  * if n < N_RANGE_INIT then n will be generated randomly.
  * enable_query: use bitmask
    bit 0: enable query 1
    bit 1: enable query 2
    bit 2: enable query 3
    if `enable_query` is 0, generator will be return with 1
*/

#define IS_RUNTIME_POLYGON true
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
 
inline int gen_query_oper(int enable_query, int q1_ratio, int q2_ratio, int q3_ratio) {
  bool q1_enabled = (enable_query & 1) == 1,
    q2_enabled = (enable_query & 2) == 2,
    q3_enabled = (enable_query & 4) == 4;
  int q_weighted = gen_random(1, 
    (q1_enabled ? q1_ratio : 0) + 
    (q2_enabled ? q2_ratio : 0) +
    (q3_enabled ? q3_ratio : 0)
  );
  if (q1_enabled && q_weighted <= q1_ratio) {
    return 1;
  }
  if (q2_enabled && q_weighted <= q1_ratio + q2_ratio) {
    return 2;
  }
  return 3;
}

tm get_random_date() {
  int y = gen_random(Y_MIN, Y_MAX), m = gen_random(1, 12), d = gen_random(1, get_last_day(y, m));
  tm result = {0, 0, 0, d, m, y};
  return result;
}
 
int main(int argc, char* argv[]) {
  // Init
  #if IS_RUNTIME_POLYGON
  registerGen(argc, argv, 1);
  #endif

  int year_min = stoi(argv[1]),
    year_max = stoi(argv[2]),
    p = stoi(argv[3]),
    n = stoi(argv[4]),
    enable_query = stoi(argv[5]),
    query_1_c_min = stoi(argv[6]), query_1_c_max = stoi(argv[7]), query_1_d_min = stoi(argv[8]), query_1_d_max = stoi(argv[9]), query_1_ratio = stoi(argv[10]),
    query_2_c_min = stoi(argv[11]), query_2_c_max = stoi(argv[12]), query_2_d_min = stoi(argv[13]), query_2_d_max = stoi(argv[14]), query_2_ratio = stoi(argv[15]),
    query_3_c_min = stoi(argv[16]), query_3_c_max = stoi(argv[17]), query_3_m_min = stoi(argv[18]), query_3_m_max = stoi(argv[19]), query_3_ratio = stoi(argv[20]);

  // validate args
  if (year_min < Y_MIN || year_max > Y_MAX) {
    year_min = Y_MIN, year_max = Y_MAX;
  }
  if (p < P_RANGE_INIT) p = gen_random(P_RANGE_INIT, P_RANGE_FIN);
  if (p > P_RANGE_FIN) exit(1);
  if (n < N_RANGE_INIT) n = gen_random(N_RANGE_INIT, N_RANGE_FIN);
  if (n > N_RANGE_FIN) exit(1);
  if (enable_query < 1 || enable_query > 7) exit(1);
  if (query_1_c_min < C_RANGE_INIT || query_1_c_max > C_RANGE_FIN) exit(1);
  if (query_1_d_min < D_REST_RANGE_INIT || query_1_d_max > D_REST_RANGE_FIN) exit(1);
  if (query_2_c_min < C_RANGE_INIT || query_1_c_max > C_RANGE_FIN) exit(1);
  if (query_2_d_min < D_GULAG_RANGE_INIT || query_2_d_max > D_GULAG_RANGE_FIN) exit(1);
  if (query_3_c_min < C_RANGE_INIT || query_3_c_max > C_RANGE_FIN) exit(1);
  if (query_3_m_min < M_RANGE_INIT || query_3_m_max > M_RANGE_FIN) exit(1);

  // (input line 1~2) Generate Enrollment Date of Jonghyeon and Yeongdo.
  int y1 = gen_random(year_min, year_max), y2 = gen_random(year_min, year_max);
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

  cout << p << ' ' << n << '\n';
 
  // (input 4~3+n) Generate Operating Query.
  int oper, c, d, m;
  for (int _i = 0; _i < n; _i++) {
    oper = gen_query_oper(enable_query, query_1_ratio, query_2_ratio, query_3_ratio);
    switch (oper)
    {
    case 1:
      c = gen_random(query_1_c_min, min(p, query_1_c_max));
      d = gen_random(query_1_d_min, query_1_d_max);
      cout << 1 << ' ' << c << ' ' << d << '\n';
      break;
    case 2:
      c = gen_random(query_2_c_min, min(p, query_2_c_max));
      d = gen_random(query_2_d_min, query_2_d_max);
      cout << 2 << ' ' << c << ' ' << d << '\n';
      break;
    case 3:
      c = gen_random(query_3_c_min, min(p, query_3_c_max));
      m = gen_random(query_3_m_min, query_3_m_max);
      cout << 3 << ' ' << c << ' ' << m << '\n';
      break;
    }
  }
 
  return 0;
}
