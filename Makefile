ARCH		=		$(shell uname -m)
SOURCEDIR	=		src
PUBLICDIR	=		$(SOURCEDIR)/public
CPPDIR		=		$(SOURCEDIR)/cpp
TARGETDIR	=		target
BUILDDIR	=		build
SBUILDDIR	=		build/static
TARGETOUT	=		$(TARGETDIR)/$(ARCH)
BUILDOUT	=		$(BUILDDIR)/$(ARCH)
SBUILDOUT	=		$(SBUILDDIR)/$(ARCH)
OS			=		linux

ifeq ($(DEBUG), true)
	GDB		=		-g3 -ggdb
endif
ifeq ($(OS), android)
	OS		=		$(OS)
endif
CC			=		g++
CPPFLAGS	=		-O3 -Wall -Wextra -pedantic -Wctor-dtor-privacy\
					-Wold-style-cast -Winit-self -Wunreachable-code\
					-Wno-unused-command-line-argument -Wno-unused-parameter\
					$(GDB) $(CFLAGS)
LDFLAGS		=		-lcurl -lrt -lpthread

NAME		=		fbb

all: clean prepare $(OS)/$(TARGETOUT)/$(NAME) postcompile

postcompile:
	$(shell if [ -f $(OS)/$(TARGETOUT)/$(NAME) ] && [ $(DEBUG) ]; then cp $(OS)/$(TARGETOUT)/$(NAME) $(OS)/$(TARGETDIR)/debug; fi)
	$(shell if [ -f $(OS)/$(TARGETOUT)/$(NAME) ]; then cp $(OS)/$(TARGETOUT)/$(NAME) $(OS)/$(TARGETDIR)/release; fi)

prepare:
	if [ ! -f $(OS)/$(TARGETOUT) ] || [ ! -f $(OS)/$(BUILDOUT) ] || [ ! -f $(OS)/$(SBUILDOUT) ]; then mkdir $(OS)/$(SBUILDOUT) $(OS)/$(BUILDOUT) $(OS)/$(TARGETOUT) -p; fi

clean:
	rm -rf $(OS)/$(BUILDOUT) $(OS)/$(TARGETOUT)

cleanall: clean
	rm -rf $(OS)/$(BUILDDIR) $(OS)/$(TARGETDIR)

$(OS)/$(TARGETOUT)/$(NAME):\
$(OS)/$(BUILDOUT)/Main.o $(OS)/$(BUILDOUT)/Parser.o\
$(OS)/$(BUILDOUT)/Requests.o $(OS)/$(BUILDOUT)/Shared.o\
$(OS)/$(BUILDOUT)/History.o\
$(OS)/$(SBUILDOUT)/pugixml.o
	$(CC) $(CPPFLAGS) $(LDFLAGS) $? -o $@

$(OS)/$(BUILDOUT)/Main.o: $(OS)/$(CPPDIR)/Main.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(OS)/$(BUILDOUT)/Parser.o: $(OS)/$(CPPDIR)/Parser.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(OS)/$(BUILDOUT)/Requests.o: $(OS)/$(CPPDIR)/Requests.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(OS)/$(BUILDOUT)/Shared.o: $(OS)/$(CPPDIR)/Shared.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(OS)/$(BUILDOUT)/History.o: $(OS)/$(CPPDIR)/History.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(OS)/$(SBUILDOUT)/pugixml.o: $(OS)/$(PUBLICDIR)/pugixml/pugixml.cpp
	$(CC) $(CPPFLAGS) -c $? -o $@
