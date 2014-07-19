#include "rapidJSON_wrapper.h"
#include "lib/rapidjson/include/rapidjson/reader.h"

extern "C" bool i_Parse(tm_json_t* handler,const char* is) {
  return GenericReader::Parse(is,handler);
}