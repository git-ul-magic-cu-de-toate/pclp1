CC=gcc
CFLAGS=-Wall -Wextra -std=c99


TARGETS=jocuri_societate forme circuits segment_display

build: $(TARGETS)

jocuri_societate: jocuri_societate.c
	$(CC) $(CFLAGS) jocuri_societate.c -o jocuri_societate joc_soc_functions.c

forme: forme.c
	$(CC) $(CFLAGS) forme.c -o forme forme_functions.c

circuits: circuits.c
	$(CC) $(CFLAGS) circuits.c -o circuits circuits_functions.c

segment_display: segment_display.c
	$(CC) $(CFLAGS) segment_display.c -o segment_display segment_display_functions.c

pack:
	zip -FSr 311CA_VictorSava_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
