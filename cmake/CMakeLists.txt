CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT (Mensa_2_0)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_BINARY_DIR}
	../include
)

ADD_SUBDIRECTORY(main)
ENABLE_TESTING()
ADD_SUBDIRECTORY(test)