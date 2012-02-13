CXXFLAGS = -ansi -pedantic -Wall -Wextra -g
CPPFLAGS = -Iinclude
LDFLAGS = -Llib
ARFLAGS = rsv

AIRLANG_CLASSES = 									\
			Airlang/AirportId						\
			Airlang/ChorochronicCheckpoint			\
			Airlang/Date							\
			Airlang/Invalidity						\
			Airlang/Route							\
			Airlang/Time							\
			Airlang/Validatable						\
			Airlang/DateBuilder						\
			Airlang/ChorochronicCheckpointBuilder	\
			Airlang/RouteBuilder					\
			Airlang/RouteListBuilder				\
			Airlang/PassengerBuilder				\

AIRLANG_OBJS = $(foreach CLASS,$(AIRLANG_CLASSES),_build/$(CLASS).o)
AIRLANG_DEPS = $(AIRLANG_OBJS:.o=.d)

_build/%.o : src/%.cpp
	mkdir -p -v $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MD -MF _build/$*.d -MT '$@ _build/$*.d' -c -o $@ $<

main: lib/libairlang.a main.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -MD -MF _build/main.d -MT '_build/main.d' -o $@ main.cpp -lairlang

lib/libairlang.a: $(AIRLANG_OBJS)
	mkdir -p -v lib
	ar $(ARFLAGS) $@ $^

all: main
#	@printf 'DEPS = %s\nOBJS = %s\n' '$(AIRLANG_DEPS)' '$(AIRLANG_OBJS)'

.PHONY: all clean

clean:
	rm -rfv _build main lib

-include $(AIRLANG_DEPS)
-include _build/main.d

