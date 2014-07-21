/******************************************************************************
 * Objective: Interface between the C Parse function needed in Lua to the C++
 *            function that rapidJSON uses to parse. This acts as the actual
 *            interace that converts the stream and calls rapidJSON's Parse
 *            from GenericReader class (Reader = default flags GenericReader)
 * Author:    Kenneth Nierenhausen
 * Date:      July 11, 2014
 *****************************************************************************/
#include "rapidJSON_interface.h"
#include "lib/rapidjson/include/rapidjson/reader.h"
#include "lib/rapidjson/include/rapidjson/filereadstream.h"

#define BUF_SIZE 65536

using namespace rapidjson;

extern "C" bool Parse(const char* json_s,tm_json_t* handler) {
  
  // create an input stream from the stringified JSON input
  char readBuffer[BUF_SIZE];
  FILE* stream = fmemopen((char*)json_s,strlen(json_s),"r");
  FileReadStream is(stream, readBuffer, sizeof(readBuffer));

  // TODO: need to figure out when to close the stream
  fclose(stream);

  // pass the input stream and the actual handler to rapidJSON's Parse
  Reader reader;
  return reader.Parse(is,*handler);
}
