cmake_minimum_required(VERSION 3.7)

project(mruby-examples)

set(EXAMPLES
  hello-world
  hello-file
  objects
  pushing-variables
  checking-for-methods
  using-data)

foreach(EXAMPLE ${EXAMPLES})
  add_executable(${EXAMPLE} src/${EXAMPLE}/${EXAMPLE}.c)

  set_target_properties(${EXAMPLE}
                        PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${EXAMPLE}")

  # Copy ruby files (if any) to the example bin dir
  file(GLOB RUBY_FILES
       "src/${EXAMPLE}/*.rb")
  file(COPY ${RUBY_FILES}
       DESTINATION ${CMAKE_SOURCE_DIR}/bin/${EXAMPLE})

  # MRuby specific TODO: This is hardcoded for my pc
  target_include_directories(${EXAMPLE} PUBLIC /home/chadow/.asdf/installs/ruby/mruby-3.2.0/include/)
  target_link_directories(${EXAMPLE} PUBLIC /home/chadow/.asdf/installs/ruby/mruby-3.2.0/lib)

  target_link_libraries(${EXAMPLE} PUBLIC -lmruby -lm)
endforeach()

message(STATUS "Binaries will be placed on the bin/ directory relative to the project root")
