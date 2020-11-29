cmake_minimum_required(VERSION 2.8)
project(test)

FILE(GLOB children RELATIVE Containers Containers/*)
SET(dirlist "")
FOREACH(child ${children})
	IF(IS_DIRECTORY ${curdir}/${child})
		LIST(APPEND dirlist ${child})
	ENDIF()
ENDFOREACH()

FOREACH(subdir ${dirlist})
	ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
