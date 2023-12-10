# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WuZiQi_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WuZiQi_autogen.dir\\ParseCache.txt"
  "WuZiQi_autogen"
  )
endif()
