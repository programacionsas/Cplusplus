CXX = g++

INCLUDE_DIR = lib/include
SRC_DIR = lib/src
BUILD_DIR = build

OBJ_RULES = settings.o hitbox.o ball.o paddle.o pong_table.o pong_game.o
OBJECTS = $(BUILD_DIR)/*.o

INCLUDE = -I.

ALLEGRO_LIBS = -lallegro -lallegro_font -lallegro_ttf -lallegro_primitives
LIBS = $(OBJECTS) $(ALLEGRO_LIBS)

default: main

main: main.cpp $(OBJ_RULES)
	$(CXX) $(INCLUDE) $< -o $@ $(LIBS)

settings.o: settings.cpp settings.hpp
	$(CXX) $(INCLUDE) -c $< -o $(BUILD_DIR)/$@

hitbox.o: $(SRC_DIR)/hitbox.cpp $(INCLUDE_DIR)/hitbox.hpp
	$(CXX) $(INCLUDE) -c $< -o $(BUILD_DIR)/$@

ball.o: $(SRC_DIR)/ball.cpp $(INCLUDE_DIR)/ball.hpp
	$(CXX) $(INCLUDE) -c $< -o $(BUILD_DIR)/$@

paddle.o: $(SRC_DIR)/paddle.cpp $(INCLUDE_DIR)/paddle.hpp
	$(CXX) $(INCLUDE) -c $< -o $(BUILD_DIR)/$@

pong_table.o: $(SRC_DIR)/pong_table.cpp $(INCLUDE_DIR)/pong_table.hpp
	$(CXX) $(INCLUDE) -c $< -o $(BUILD_DIR)/$@

pong_game.o: $(SRC_DIR)/pong_game.cpp $(INCLUDE_DIR)/pong_game.hpp
	$(CXX) $(INCLUDE) -c $< -o $(BUILD_DIR)/$@

.PHONY:
clean:
	$(RM) $(OBJECTS) main