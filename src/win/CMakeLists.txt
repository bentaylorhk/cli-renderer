# Benjamin Michael Taylor (bentaylorhk)
# April 2023

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)

target_sources(cli_renderer PRIVATE ${SOURCES})
