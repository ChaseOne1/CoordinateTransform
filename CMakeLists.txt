cmake_minimum_required(VERSION 3.0.0)
project(CoordTransform VERSION 0.1.0 LANGUAGES C CXX)

aux_source_directory(src sourceFile)
aux_source_directory(src/CoordTransform sourceFile)
aux_source_directory(src/MathHelper sourceFile)

#add_definitions(-_DEBUG)

add_executable(CoordTransform ${sourceFile})
