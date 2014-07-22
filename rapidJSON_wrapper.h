/******************************************************************************
 * Objective: Wrapper over parse function that rapidJSON implements in C++ (H)
 * Author:    Kenneth Nierenhausen
 * Date:      July 11, 2014
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

/* A collection of function pointers needed by BaseReader in rapidJSON */
typedef struct tm_json {
  void (*Default)(void);
  void (*Null)(void);
  void (*Bool)(bool);
  void (*Int)(int);
  void (*Uint)(unsigned);
  void (*Int64)(int64_t);
  void (*Uint64)(uint64_t);
  void (*Double)(double);
  void (*String)(const char*,size_t,bool);
  void (*StartObject)();
  void (*EndObject)(size_t);
  void (*StartArray)(void);
  void (*EndArray)(size_t);
} tm_json_t;

/* Prototypes */
static int to_value(tm_json_t*, const char*);
void cb_default(void);
void cb_null(void);
void cb_bool(bool);
void cb_int(int);
void cb_uint(unsigned);
void cb_int64(int64_t);
void cb_uint64(uint64_t);
void cb_double(double);
void cb_string(const char*,size_t,bool);
void cb_startObject(void);
void cb_endObject(size_t);
void cb_startArray(void);
void cb_endArray(size_t);
