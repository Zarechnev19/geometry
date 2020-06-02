OBJ_CATALOG=build/src
OBJ_CATALOG_TEST=build/test

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.c get_count_strokes.c get_data.c print_rezult.c get_sum.c check_data_strokes.c get_area.c get_perimeter.c find_intersections.c
SOURCES_TEST=main-test.c get_sum.c get_sum_test.c get_perimeter_test.c get_perimeter.c get_area.c get_area_test.c check_data_strokes.c check_data_strokes_test.c find_intersections.c find_intersectons_test.c
VPATH=src test

.PHONY: all clean

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
OBJECTS_TEST=$(addprefix $(OBJ_CATALOG_TEST)/, $(SOURCES_TEST:.c=.o))
EXECUTABLE=geometry

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(LDFLAGS) $(OBJECTS_TEST) -o bin/main-test
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main
	./bin/main-test

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_CATALOG_TEST)/%.o: %.c
	$(CC) -I thirdparty -I src $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_CATALOG)/*.o $(OBJ_CATALOG_TEST)/*.o bin/*.exe
