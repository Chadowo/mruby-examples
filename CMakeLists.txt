cmake_minimum_required(VERSION 3.1...3.7)

project(mruby-examples
        LANGUAGES C)

set(EXAMPLES
    hello-world
    hello-file
    objects
    pushing-variables
    method-defined
    call-methods
    using-cdata
    kwargs
    blocks
    compiling-bytecode)

set(CMAKE_C_STANDARD 99)
set(WARNINGS -pedantic -Wall -Wshadow -Wpointer-arith
             -Wno-missing-braces -Wcast-qual -Wstrict-prototypes)

foreach(EXAMPLE ${EXAMPLES})
  set(OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${EXAMPLE}")

  add_executable(${EXAMPLE} src/${EXAMPLE}/${EXAMPLE}.c)

  set_target_properties(${EXAMPLE}
                        PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

  # Copy Ruby files (if any) to the example's output directory
  file(GLOB RUBY_FILES
       "src/${EXAMPLE}/*.rb")
  file(COPY ${RUBY_FILES}
       DESTINATION ${OUTPUT_DIRECTORY})

  target_compile_options(${EXAMPLE} PRIVATE ${WARNINGS})
  target_link_libraries(${EXAMPLE} PRIVATE -lmruby -lm)
endforeach()

message(STATUS "Binaries will be placed on the bin/ directory relative to the project root")
