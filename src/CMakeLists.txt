file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)

add_executable(cli_renderer ${SOURCES})
