cmake_minimum_required(VERSION 3.10)

# Set this source directory as the tree root for project.
set(ae2f_ProjRoot ${CMAKE_SOURCE_DIR} CACHE STRING "Tree root for project")
set(ae2f_BinRoot ${CMAKE_SOURCE_DIR} CACHE STRING "Tree root for project")
set(ae2f_submod  .submod CACHE STRING "Relative path to submodule (subdirectory)")
set(ae2f_Preproc_Wh ${ae2f_ProjRoot}/${ae2f_submod}/ae2f/Preproc)

# Execute git to fetch CoreScript when repository does not exist
if(NOT EXISTS ${ae2f_Preproc_Wh})
	execute_process(
		COMMAND git clone https://talkischeap.work.gd/ae2f/PreProc
		${ae2f_Preproc_Wh}
		)
endif()

# add subdirectory
if(NOT TARGET ae2f::Preproc)
	add_subdirectory(${ae2f_Preproc_Wh} ${ae2f_submod}/ae2f/Preproc)
endif()

add_custom_target(dummy ALL
	${CMAKE_COMMAND} -E copy_if_newer
	${CMAKE_SOURCE_DIR}/math_funcs.cpp.in
	${CMAKE_SOURCE_DIR}/core/math/math_funcs.cpp
	SOURCES		${CMAKE_SOURCE_DIR}/math_funcs.cpp.in
	BYPRODUCTS	${CMAKE_SOURCE_DIR}/core/math/math_funcs.cpp
	)

add_dependencies(dummy ae2f::Preproc)

