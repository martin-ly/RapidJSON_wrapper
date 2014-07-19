/* include all the boring stuff here so it does not waste space */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

/* A collection of function pointers needed by BaseReader in rapidJSON */
typedef struct tm_json {
  void (*fp_default)(void);
  void (*fp_null)(void);
  void (*fp_bool)(bool);
  void (*fp_int)(int);
  void (*fp_uint)(unsigned);
  void (*fp_int64)(int64_t);
  void (*fp_uint64)(uint64_t);
  void (*fp_double)(double);
  void (*fp_string)(char*);
  void (*fp_startObject)();
  void (*fp_endObject)(void/*TODO*/);
  void (*fp_startArray)(void);
  void (*fp_endArray)(void/*TODO*/);
} tm_json_t;

/* prototypes */
int to_value(tm_json_t*, const char*);
void cb_default(void);
void cb_null(void);
void cb_bool(bool);
void cb_int(int);
void cb_uint(unsigned);
void cb_int64(int64_t);
void cb_uint64(uint64_t);
void cb_double(double);
void cb_string(char*);
void cb_startObject(void);
void cb_endObject(void/*TODO*/);
void cb_startArray(void);
void cb_endArray(void/*TODO*/);