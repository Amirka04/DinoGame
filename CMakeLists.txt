cmake_minimum_required(VERSION 3.2)

# Создам проект
project(MyGame)

# Найду библиотеку sfml
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Добавление файлов динозаврика
set(Dino Dino/Dino.cpp Dino/Dino.h)
# Добавление файлов вектор
set(Vector Vectors/Vector2D.cpp Vectors/Vector2D.h)
# Добавление файлов для добавление и управления текстурами текстур
set(Textures Textures/Textures.cpp Textures/Textures.h)
# Добавление файлов библиотеки анимации
set(Animates Textures/Animate.hpp Textures/Animate.cpp)
# Добавление файлов библиотеки кактусов
set(Kaktuss Kaktus/Kaktus.cpp Kaktus/Kaktus.h)
# Добавление файлов библиотеки фона
set(BackGroundFiles BackGround/BackObject.cpp BackGround/BackObject.hpp)


# Добавление файлов для платформы
set(Platforma platforma/platforma.cpp platforma/platforma.h)
set(PlatformaArray platforma/platform_array.cpp platforma/platform_array.h)



# Добавление библиотек
add_library( DinoLib ${Dino} )
message("Успешное добавление библиотеки DinoLib!")

add_library( VectorLib ${Vector} )
message("Успешное добавление библиотеки VectorLib!")

add_library(texture ${Textures})
message("Успешное добавление библиотеки texture!")

add_library(Animate ${Animates})
message("Успешное добавление библиотеки Animate")

add_library(platforma ${Platforma})
add_library(platform_array ${PlatformaArray})
add_library(MainPlatform platforma/platformObject.hpp)
message("Успешное добавление библиотеки Platforma и platform_array")

add_library(Kaktus ${Kaktuss})
message("Успешное добавление библиотеки Kaktus")

add_library(BackGround ${BackGroundFiles})
message("Успешное добавление библиотеки BackGround")

add_library(MainBackGround BackGround/BackGround.hpp)
message("Успешное добавление библиотеки BackObject")


add_executable(MyGame main.cpp)


target_link_libraries(Animate PUBLIC texture)
target_link_libraries(DinoLib PRIVATE VectorLib Animate texture)
target_link_libraries(platform_array PUBLIC platforma)
target_link_libraries(MainPlatform PUBLIC texture VectorLib platforma platform_array)
target_link_libraries(MainBackGround PRIVATE BackGround VectorLib)


target_link_libraries(MyGame DinoLib Kaktus MainBackGround MainPlatform)
target_link_libraries(MyGame sfml-graphics sfml-window sfml-system GL)


message("Успешное линкование к проекту!")
