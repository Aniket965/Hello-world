#!/bin/bash
echo -n "input the repetition number : "
read repeat
for((i=1;i<=repeat;i++))
do
  for((k=1;k<=(repeat-i);k++))
  do
    echo -e " \c "
  done
  for((j=1;j<=i;j++))
  do
    echo -e "* \c \c"
    # awk 'BEGIN{printf "%c ", 178}'
  done
  echo -e "\n"
done