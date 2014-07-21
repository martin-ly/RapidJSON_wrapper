/******************************************************************************
 * Objective: Interface between the C Parse function needed in Lua to the C++
 *            function that rapidJSON uses to parse. This headed is included
 *            in the C wrapper to allow access to the parse function in C++
 * Author:    Kenneth Nierenhausen
 * Date:      July 11, 2014
 *****************************************************************************/
#include "rapidJSON_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

bool Parse(const char* json_s,tm_json_t* handler);

#ifdef __cplusplus
}
#endif
