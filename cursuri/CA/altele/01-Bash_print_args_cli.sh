# Copyright 2024 Darius Neatu (neatudarius@gmail.com)

# TODO: Dorim să transmitem parametri în linie de comandă acestui script Bash:
# $ ./01-Bash_print_args_cli
# Received 0 arguments!
# $ ./01-Bash_print_args_cli Merry Christmas! Ho Ho Ho!
# Received 5 arguments!
# Merry Christmas! Ho Ho Ho!
# argv[1] = Merry
# argv[2] = Christmas!
# argv[3] = Ho
# argv[4] = Ho
# argv[5] = Ho!

# # Print number of arguments.
# echo "Received $# arguments!"
# # Print all arguments.
# echo $@
# # Print arguments one by one with syntax argv[%d] = %s.
# for i in $(seq 1 $#); do
#     echo "argv[$i] = ${!i}"
# done

# Same as above, but using printf.
# Print number of arguments.
printf "Received %d arguments!\n" $#
# Print all arguments.
printf "%s\n" $@
# Print arguments one by one with syntax argv[%d] = %s.
for i in $(seq 1 $#); do
    printf "argv[%d] = %s\n" $i ${!i}
done
