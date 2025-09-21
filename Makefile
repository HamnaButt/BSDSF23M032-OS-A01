# Makefile (root) - recursive driver
.PHONY: all clean static dynamic install

all: static multifile

# build libraries first
static:
	$(MAKE) -C lib static
	$(MAKE) -C src static

multifile:
	$(MAKE) -C src multifile

dynamic:
	$(MAKE) -C lib dynamic
	$(MAKE) -C src dynamic

clean:
	$(MAKE) -C src clean || true
	$(MAKE) -C lib clean || true
	rm -rf bin obj lib/*.a lib/*.so

install:
	sudo mkdir -p /usr/local/bin /usr/local/share/man/man3
	sudo cp bin/client /usr/local/bin/client
	sudo cp man/man3/*.3 /usr/local/share/man/man3/
	sudo mandb || true

