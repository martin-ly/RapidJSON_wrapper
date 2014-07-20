#include "rapidJSON_inerface.h"

extern "C" bool Parse(tm_json_t* handler,const char* is) {
  return GenericReader::Parse(is,handler);
}
