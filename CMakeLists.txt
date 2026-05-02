cmake_minimum_required(VERSION 3.25)

project(QtPresetSample
    VERSION       1.0.0
    DESCRIPTION   "Qt6 CMake preset sample application"
    LANGUAGES     CXX
)

# ── C++ standard ────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# ── Qt6: enable automatic preprocessing ─────────────────────────────────────
set(CMAKE_AUTOMOC ON)   # run moc automatically
set(CMAKE_AUTOUIC ON)   # run uic automatically  (for .ui files)
set(CMAKE_AUTORCC ON)   # run rcc automatically  (for .qrc files)

# ── Find Qt6 ────────────────────────────────────────────────────────────────
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()   # sets sane Qt defaults (CMake >= 3.25 / Qt >= 6.3)
                               # Note: qt_standard_project_setup already handles finalization,
                               # so qt_finalize_executable is NOT called separately below.

# ── Application target ──────────────────────────────────────────────────────
qt_add_executable(${PROJECT_NAME}
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

# ── macOS bundle & Windows app metadata ─────────────────────────────────────
set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE              TRUE
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.qtpresetsample"
    MACOSX_BUNDLE_BUNDLE_VERSION       ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION}
    WIN32_EXECUTABLE           TRUE
)

# ── Install rules ────────────────────────────────────────────────────────────
install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
