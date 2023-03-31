cmake_minimum_required(VERSION 3.2)

project(MyGame)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(Dino Dino/Dino.cpp Dino/Dino.h)
set(Vector Vectors/Vector2D.cpp Vectors/Vector2D.h)
set(Textures Textures/Textures.cpp Textures/Textures.h)
set(Enemys Enemy/Enemy.cpp Enemy/Enemy.h)
set(Animates Textures/Animate.hpp Textures/Animate.cpp)


add_library( DinoLib ${Dino} )
message("Успешное добавление библиотеки DinoLib!")
add_library( VectorLib ${Vector} )
message("Успешное добавление библиотеки VectorLib!")
add_library(texture ${Textures})
message("Успешное добавление библиотеки texture!")
add_library(EnemyS ${Enemys})
message("Успешное добавление библиотеки DinoLib!")
add_library(Animate ${Animates})
message("Успешное добавление библиотеки Animate")


add_executable(MyGame main.cpp)


target_link_libraries(Animate PUBLIC texture)
target_link_libraries(DinoLib PUBLIC VectorLib Animate)
target_link_libraries(EnemyS PUBLIC VectorLib texture)

target_link_libraries(MyGame DinoLib EnemyS)
target_link_libraries(MyGame sfml-graphics sfml-window sfml-system GL)

message("Успешное линкование к проекту!")