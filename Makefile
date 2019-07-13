CPPFLAGS=-Wall

TARGETS=main

# Since build is the first clause, it will be the standard clause run by make.
# The rules for compiling the targets are automatically created using the target
# name as a stem.
build: $(TARGETS)

# The arguments of .PHONY will not be treated as files.
.PHONY: clean

# The dash at the beginning ignores a failure of the command
clean:
	-rm -v $(TARGETS)
