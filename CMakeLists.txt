cmake_minimum_required(VERSION 3.23)
project(DA2)

set(CMAKE_CXX_STANDARD 14)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(DA2
        2opt.h
        2opt.cpp
        backtracking.h
        data_structures/Graph.h
        data_structures/Graph.cpp
        data_structures/VertexEdge.h
        data_structures/VertexEdge.cpp
        data_structures/UFDS.h
        data_structures/UFDS.cpp
        NearestNeighbor.h
        NearestNeighbor.cpp
        Timer.h
        Timer.cpp
        Christofides.h
        Christofides.cpp
        main.cpp Manager.cpp)