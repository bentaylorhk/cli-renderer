file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)

add_executable(cli_renderer ${SOURCES})

target_include_directories(cli_renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
