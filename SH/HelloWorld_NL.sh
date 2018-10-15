#/bin/sh
line="Hallo wereld: Hacktoberfest 2018!"

# Borrowed from https://unix.stackexchange.com/questions/21347
length="${#line}"
bol=1
for (( offset = 0 ; offset < length ; offset++ )); do
    char="${line:offset:1}"
    printf '%s' "$char"
    if (( bol )) && [[ "$char" == " " ]]; then
        continue
    fi
    bol=0
    sleep 0.1
done

sleep 0.$(( RANDOM % 7 + 3 ))

printf '\n'
