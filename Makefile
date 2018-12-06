FLAGS= -std=c++17 -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override
CXX= g++-8
MAIN= main.cpp
OUT= main.out

all: $(OUT)

$(OUT): BST.hpp Node.hpp Info.hpp Vector.hpp SparseVector.hpp $(MAIN)
	$(CXX) $(FLAGS) $(MAIN) -o $(OUT) -lquadmath

.PHONY : clean

clean:
	rm *.o *.out;
