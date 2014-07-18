/******************************************************************************
 * Objective: Wrapper over the C++ fucntions RapidJSON needs in order to parse
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

/* Parses the JSON string and calls those functions when it hits each token */
int to_value(tm_json_t* handler, const char* json_stringified) {

  /* allocate memory for the struct */
  handler = (tm_json_t*)malloc(sizeof(tm_json_t));

  /* link the function pointers to the callbacks */
  handler->fp_default = cb_default;
  handler->fp_null = cb_null;
  handler->fp_bool = cb_bool;
  handler->fp_int = cb_int;
  handler->fp_uint = cb_uint;
  handler->fp_int64 = cb_int64;
  handler->fp_uint64 = cb_uint64;
  handler->fp_double = cb_double;
  handler->fp_string = cb_string;
  handler->fp_startObject = cb_startObject;
  handler->fp_endObject = cb_endObject;
  handler->fp_startArray = cb_startArray;
  handler->fp_endArray = cb_endArray;

  /* 88 lines of parsing code that I got rid of... what goes here? */

  /* free the handler (this may need to be updated once implemented) */
  free(handler);

  return 0;

}

/* Collection of callbacks that get invoked by rapidJSON when it parses */
void cb_default(void) { printf("DEFAULT\n"); }
void cb_null(void) { printf("NULL\n"); }
void cb_bool(bool val) { printf("BOOL: %s\n",val ? "true" : "false"); }
void cb_int(int val) { printf("INT: %d\n",val); }
void cb_uint(unsigned val) { printf("UINT: %d\n",val); }
void cb_int64(int64_t val) { printf("INT_64: %"PRId64"\n",val); }
void cb_uint64(uint64_t val) { printf("UINT_64: %"PRIu64"\n",val); }
void cb_double(double val) { printf("DOUBLE: %f\n",val); }
void cb_string(char* val) { printf("STRING: %s\n",val); }
void cb_startObject(void) { printf("START_OBJECT\n"); }
void cb_endObject(void/*TODO*/) { printf("END_OBJECT: todo\n"); }
void cb_startArray(void) { printf("START_ARRAY\n"); }
void cb_endArray(void/*TODO*/) { printf("END_ARRAY: todo\n"); }

/* Temporaorily used to test to_value */
int main(void) {
  tm_json_t* handler;
  printf("=====================================================================\n");
  to_value(handler,"{{}}");
/*  printf("=====================================================================\n");
  to_value(handler,"{\"a\":1,\"b\":{\"c\":2},\"d\":3}");
  printf("=====================================================================\n");
  to_value(handler,"{\"clientX\":39,\"clientY\":17,\"offsetX\":39,\"offsetY\":17}");
  printf("=====================================================================\n");
  to_value(handler,"{\"name\":\"Jim Cowart\",\"location\":{\"city\":{\"name\":\"Chattanooga\",\"population\":167674},\"state\":{\"name\":\"Tennessee\",\"abbreviation\":\"TN\",\"population\":6403000}},\"company\":\"appendTo\"}");
*/  return 0;
}
