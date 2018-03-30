project(test_SerializeToOstream)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-O0 -g -std=c++11")

find_package(Protobuf REQUIRED)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS msg.proto)

add_executable(test_SerializeToString
    main.cpp
    ${PROTO_SRCS}
)

target_include_directories(test_SerializeToString PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(test_SerializeToString ${PROTOBUF_LIBRARIES})