# OpenJazz makefile
prefix=/usr/local

include openjazz.mk

CXXFLAGS += -g -Wall -O2 -DSCALE
CXXFLAGS += -DUSE_SOCKETS

# SDL flags
CXXFLAGS+=`sdl-config --cflags`
LDFLAGS+=`sdl-config --libs`

# Enable modplug music
#CXXFLAGS += -DUSE_MODPLUG `pkg-config --cflags libmodplug`
#LDFLAGS += `pkg-config --libs libmodplug`

# Enable XMP music
CXXFLAGS += -DUSE_XMP `pkg-config --cflags libxmp`
LDFLAGS += `pkg-config --libs libxmp`

# Add for network support on windows
LDFLAGS += -lws2_32

OpenJazz: $(OBJS)
	g++ $(CXXFLAGS) -o OpenJazz $(OBJS) $(LDFLAGS) -lz

%.o: %.cpp
	g++ $(CXXFLAGS) -Isrc -c $< -o $@

clean:
	rm -f OpenJazz $(OBJS)

install: OpenJazz
	install -m 0755 OpenJazz $(prefix)/bin
	install -m 0644 openjazz.000 $(prefix)/bin

.PHONY: install
