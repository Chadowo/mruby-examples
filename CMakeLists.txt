cmake_minimum_required(VERSION 3.7)

project(mruby-examples)

# For all targets
add_compile_options(-std=c99 -pedantic -Wall -Wshadow -Wpointer-arith
                    -Wcast-qual -Wstrict-prototypes -O2)

set(EXAMPLES
  hello-world
  hello-file
  objects
  pushing-variables
  checking-for-methods
  call-methods
  using-cdata)

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
