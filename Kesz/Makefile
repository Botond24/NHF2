#
# Pelda make a hazihoz.
#

PROG	= gen_array3_main
OBJ	= gen_array3_main.o memtrace.o
HEAD	= gen_array3.hpp duma_u8.h duma_latin.h cross_platform.h
TEST	= standard_input.txt
DATA	= valami_adat.dat

JPORTA_PACK = gen_array3_main.cpp $(HEAD)

CXXFLAGS= -std=c++11 -Wall -Werror -g -DCPORTA -DMEMTRACE 

all:	$(PROG)

gen_array3_main: $(OBJ)
	$(CXX) -o $(PROG) $(OBJ)

$(OBJ): $(HEAD)

test:	$(PROG) $(TEST)
	for i in $(TEST); do \
	  ./$(PROG) < $$i ; \
	done 

clean:	
	rm -f $(PROG) $(OBJ)

tar:	
	tar -czf $(PROG).tgz $(SRC) $(HEAD) $(TEST) $(DATA)

zip:	
	zip kesz.zip $(JPORTA_PACK)
