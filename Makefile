CFLAGS=-MMD -MP -Wall -g -fsanitize=address

PROGRAMS=programm
OBJECTS=person.o personlist.o bloodrelatives.o id.o

ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

programm: $(OBJECTS)

clean:
	-rm -f $(ALLOBJECTS) $(ALLOBJECTS:%.o=%.d) $(PROGRAMS)

-include $(ALLOBJECTS:%.o=%.d)
