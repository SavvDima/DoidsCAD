find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Core)

add_executable(tst_projectmodel
    tst_projectmodel.cpp
    ../projectmodel.cpp
    ../projectmodel.h
    ../projecttypes.h
)

target_include_directories(tst_projectmodel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(tst_projectmodel PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Test)

add_test(NAME projectmodel COMMAND tst_projectmodel)
