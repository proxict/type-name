add_executable(typename-unittests
    main.cpp
)

target_link_libraries(typename-unittests
    PRIVATE type-name
)
