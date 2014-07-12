/******************************************************************************
 * Objective: Wrapper over the C++ fucntions RapidJSON needs in order to parse
 * Author:    Kenneth Nierenhausen
 * Date:      July 11, 2014
 *****************************************************************************/
#include <stdio.h>

/* A collection of callback functions implemented by a BaseReader RapidJSON */
typedef struct {
  //TODO: get all the callback function pointers in the structure
} tm_json_t;

/* Parses the JSON string and calls those functions when it hits each token */
int parse(tm_json_t* handler, const char* jsonObj) {
  printf(" %s\n",jsonObj);
  //TODO: main chunk of parsing work
}

/* Tests out whether the wrapper works and can parse correctly */
int main(int argc, char* argv[]) {
  tm_json_t* handler;
  parse(handler,"{'id':1,'name':'test','price':12.50,'tags':['home','green']}");
  //TODO: run more tests
  return 0;
}
