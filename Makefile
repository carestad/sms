OBJS_SMS=\
	main.o

OBJS_PROVIDERS=\
	providers/1881.o\
	providers/eurobate.o

OBJS_ALL=\
	$(OBJS_SMS)\
	$(OBJS_PROVIDERS)

CC=g++
CFLAGS=-Wall -g
LIBS=-lcurl

all: sms
sms: $(OBJS_ALL)
	$(CC) $(CFLAGS) $(OBJS_ALL) $(LIBS) -o $@

%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJS_ALL) sms