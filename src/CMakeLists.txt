cmake_minimum_required(VERSION 3.10.2)
project(libro_src)

# CMAKE_CURRENT_SOURCE_DIR is just equivalent to the current directory . and just written explicitly
# here to be more descriptive than writing as <include_directories(.)>. The <include_directories(x)>
# will affect all targets in this CMakeList as well as those in all subdirectories added after the
# point of its call. So all subdirectories after this command will have the current directory . which
# is specifically ./LibroDeConocimiento/src added to their include path automatically. What it would
# mean is that if you are going to include header files from this project, you have to start with this
# directory.
# Example:
#         nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/LibroDeConocimiento/src$ pwd
#         /home/nponcian/Documents/Programs/LibroDeConocimiento/src
#         nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/LibroDeConocimiento/src$ tree
#         .
#         ├── CMakeLists.txt
#         ├── CoderByte
#         │   ├── Challenges
#         │   │   ├── ChallengesGetter.cpp
#         │   │   ├── ChallengesGetter.hpp
#         │   │   ├── EasyDifficulty
#         │   │   │   ├── FirstFactorial.cpp
#         │   │   │   ├── FirstFactorial.hpp
#         │   │   │   ├── FirstReverse.cpp
#         │   │   │   ├── FirstReverse.hpp
#         │   │   │   ├── LetterChanges.cpp
#         │   │   │   ├── LetterChanges.hpp
#         │   │   │   ├── LongestWord.cpp
#         │   │   │   ├── LongestWord.hpp
#         │   │   │   ├── SimpleAdding.cpp
#         │   │   │   └── SimpleAdding.hpp
#         │   │   └── IChallenge.hpp
#         │   ├── CMakeLists.txt
#         │   ├── CoderByteController.cpp
#         │   └── CoderByteController.hpp
#         ├── Common
#         │   ├── CMakeLists.txt
#         │   ├── Logger.hpp
#         │   └── UserInputHandler.hpp
#         ├── Dispatcher.cpp
#         ├── Dispatcher.hpp
#         ├── Help
#         │   ├── CMakeLists.txt
#         │   ├── HelpController.cpp
#         │   └── HelpController.hpp
#         ├── IController.hpp
#         └── main.cpp
#     Then if you are going to include lets say the LetterChanges.hpp, you have to do it with respect to src:
#         #include <./CoderByte/Challenges/EasyDifficulty/LetterChanges.hpp>
#     or simply
#         #include <CoderByte/Challenges/EasyDifficulty/LetterChanges.hpp>
#     but cannot be
#         #include <LetterChanges.hpp>
#     nor
#         #include <Challenges/EasyDifficulty/LetterChanges.hpp>
#     nor
#         anything not starting with src be them included as library <> nor project-then-library ""
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# In case of linking errors, try rearranging addition of subdirectories below
add_subdirectory(Algorithms)
add_subdirectory(Common)
add_subdirectory(Challenges)
add_subdirectory(Help)

# The command set is used here for reference as all other CMakeLists already uses the regex format
# set(libro_src_cpp
#     Dispatcher.cpp
#     main.cpp)
file(GLOB libro_src_cpp
    "*.cpp")

add_executable(libro_src ${libro_src_cpp})

# In case of linking errors, try rearranging addition of linking below
target_link_libraries(libro_src libro_src_algorithms)
target_link_libraries(libro_src libro_src_challenges)
target_link_libraries(libro_src libro_src_help)
target_link_libraries(libro_src libro_src_common) # For some reason, this requires to be last for the library of challenges to see
