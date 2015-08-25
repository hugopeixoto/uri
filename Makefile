LD=clang
CXX=clang++

CXXFLAGS += -Wall -std=c++1y -stdlib=libc++
LDFLAGS += -lc++

CXXFLAGS += -Isrc/
LDFLAGS +=

SRC=src/hugopeixoto/uri/uri.cc
LIB=libhugopeixoto-uri.a

OBJ=$(SRC:.cc=.o)
all: test $(LIB)

$(LIB): $(OBJ)
	$(AR) rcs $@ $^

test: main.o $(LIB)
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf test main.o $(OBJ) $(LIB)
