cmake_minimum_required(VERSION 3.19)
project(lab_03 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # OFF = чистый C++, без расширений
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
qt_standard_project_setup()

qt_add_executable(lab_03
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(lab_03 PRIVATE mylib)
target_link_libraries(lab_03 PRIVATE Qt::Core Qt::Widgets)

include(GNUInstallDirs)

install(TARGETS lab_03
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET lab_03
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
