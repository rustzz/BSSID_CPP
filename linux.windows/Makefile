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

ifeq ($(DEBUG), true)
	GDB		=		-g3 -ggdb
endif
CC			=		g++
CPPFLAGS	=		-O3 -Wall -Wextra -pedantic -Wctor-dtor-privacy\
					-Wold-style-cast -Winit-self -Wunreachable-code\
					-Wno-unused-command-line-argument -Wno-unused-parameter\
					$(GDB) $(CFLAGS)
LDFLAGS		=		-lcurl -lrt -lpthread

NAME		=		fbb

all: clean prepare $(TARGETOUT)/$(NAME) postcompile

postcompile:
	$(shell if [ -f $(TARGETOUT)/$(NAME) ] && [ $(DEBUG) ]; then cp $(TARGETOUT)/$(NAME) $(TARGETDIR)/debug; fi)
	$(shell if [ -f $(TARGETOUT)/$(NAME) ]; then cp $(TARGETOUT)/$(NAME) $(TARGETDIR)/release; fi)

prepare:
	if [ ! -f $(TARGETOUT) ] || [ ! -f $(BUILDOUT) ] || [ ! -f $(SBUILDOUT) ]; then mkdir $(SBUILDOUT) $(BUILDOUT) $(TARGETOUT) -p; fi

clean:
	rm -rf $(BUILDOUT) $(TARGETOUT)

cleanall: clean
	rm -rf $(BUILDDIR) $(TARGETDIR)

$(TARGETOUT)/$(NAME):\
$(BUILDOUT)/Main.o $(BUILDOUT)/Parser.o\
$(BUILDOUT)/Requests.o $(BUILDOUT)/Shared.o\
$(BUILDOUT)/History.o\
$(SBUILDOUT)/pugixml.o
	$(CC) $(CPPFLAGS) $(LDFLAGS) $? -o $@

$(BUILDOUT)/Main.o: $(CPPDIR)/Main.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(BUILDOUT)/Parser.o: $(CPPDIR)/Parser.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(BUILDOUT)/Requests.o: $(CPPDIR)/Requests.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(BUILDOUT)/Shared.o: $(CPPDIR)/Shared.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(BUILDOUT)/History.o: $(CPPDIR)/History.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c $? -o $@

$(SBUILDOUT)/pugixml.o: $(PUBLICDIR)/pugixml/pugixml.cpp
	$(CC) $(CPPFLAGS) -c $? -o $@
