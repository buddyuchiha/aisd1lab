project ("AISD-SET")

add_executable (AISD-SET "src/main.cpp"  "mymainset/mainset.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AISD-SET PROPERTY CXX_STANDARD 20)
endif()