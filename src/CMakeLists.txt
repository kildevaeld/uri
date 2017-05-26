
set(LEG_COMMAND "leg")

ADD_CUSTOM_COMMAND(OUTPUT ${PARSER_OUTPUT}
  COMMAND ${LEG_COMMAND} -o ${PARSER_OUTPUT} ${PARSER_INPUT}
  DEPENDS ${PARSER_INPUT}
)

ADD_CUSTOM_TARGET(GenerateParser ALL
   DEPENDS ${PARSER_OUTPUT}
)

message(STATUS ${PARSER_OUTPUT})


set(SOURCES
    element.c
    uri.c
)

add_library(uri ${SOURCES} ${PARSER_OUTPUT})
add_dependencies(uri GenerateParser)
