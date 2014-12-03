DIRS=acs core engine ircomm ircommAcs powermgmt scheduler uart
AR=/usr/local/bin/avr-ar
ARFLAGS=-rcs
BUILD-DIRS=$(DIRS:%=build-%)
CLEAN-DIRS=$(DIRS:%=clean-%)
LIBS=$(DIRS:%=build/%.a)
EXECUTABLE=build/rp6library.a

all: $(BUILD-DIRS) $(EXECUTABLE)
$(BUILD-DIRS):
	$(MAKE) -C $(@:build-%=%)

clean:
	rm -f $(EXECUTABLE)

clean: $(CLEAN-DIRS)
$(CLEAN-DIRS):
	$(MAKE) -C $(@:clean-%=%) clean

$(EXECUTABLE): $(LIBS)
	$(AR) $(ARFLAGS) $@ $(LIBS)

.PHONY: subdirs $(BUILD-DIRS)
.PHONY: clean all