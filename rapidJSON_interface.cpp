#include "rapidJSON_interface.h"
#include "lib/rapidjson/include/rapidjson/reader.h"
#include "lib/rapidjson/include/rapidjson/filereadstream.h"

#define BUF_SIZE 65536

using namespace rapidjson;

extern "C" bool Parse(char* json_s,tm_json_t* handler) {
  
  // create an input stream from the stringified JSON input
  char readBuffer[BUF_SIZE];
  FILE* stream = fmemopen(json_s,strlen(json_s),"r");
  FileReadStream is(stream, readBuffer, sizeof(readBuffer));

  // TODO: need to figure out when to close the stream
  // fclose(stream);

  // pass the input stream and the actual handler to rapidJSON's Parse
  Reader reader;
  return reader.Parse(is,*handler);
}
