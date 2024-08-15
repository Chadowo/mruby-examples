cmake_minimum_required(VERSION 3.1...3.7)

project(mruby-examples
        LANGUAGES C)

set(EXAMPLES
    hello-world
    hello-file
    objects
    pushing-variables
    checking-for-methods
    call-methods
    using-cdata
    kwargs
    blocks
    compiling-bytecode)

set(CMAKE_C_STANDARD 99)
set(WARNINGS -pedantic -Wall -Wshadow -Wpointer-arith
             -Wno-missing-braces -Wcast-qual -Wstrict-prototypes)

# For all targets
add_compile_options(${WARNINGS})

foreach(EXAMPLE ${EXAMPLES})
  add_executable(${EXAMPLE} src/${EXAMPLE}/${EXAMPLE}.c)

  set_target_properties(${EXAMPLE}
                        PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${EXAMPLE}")

  # Copy ruby files (if any) to the example bin dir
  file(GLOB RUBY_FILES
       "src/${EXAMPLE}/*.rb")
  file(COPY ${RUBY_FILES}
       DESTINATION ${CMAKE_SOURCE_DIR}/bin/${EXAMPLE})

  target_link_libraries(${EXAMPLE} PUBLIC -lmruby -lm)
endforeach()

message(STATUS "Binaries will be placed on the bin/ directory relative to the project root")
