add_executable(pascal_triangle pascal_triangle.cpp)
add_subdirectory(../Ext/fmt fmt)
target_link_libraries(pascal_triangle fmt::fmt)
set_target_properties(pascal_triangle PROPERTIES
            CXX_STANDARD 20
            CXX_EXTENSIONS OFF)


