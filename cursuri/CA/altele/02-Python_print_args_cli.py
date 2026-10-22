#!/usr/bin/env python3
# Copyright 2024 Darius Neatu (neatudarius@gmail.com)

# TODO: Dorim să transmitem parametri în linie de comandă acestui script Python:
# $ ./02-Python_print_args_cli.py
# Received 0 arguments!
# $ ./02-Python_print_args_cli.py Merry Christmas! Ho Ho Ho!
# Received 5 arguments!
# Merry Christmas! Ho Ho Ho!
# argv[1] = Merry
# argv[2] = Christmas!
# argv[3] = Ho
# argv[4] = Ho
# argv[5] = Ho!

import sys
print(f"Received {len(sys.argv)-1} arguments!")
print(" ".join(sys.argv[1:]))
for i, arg in enumerate(sys.argv[1:], start=1):
    print(f"argv[{i}] = {arg}")
