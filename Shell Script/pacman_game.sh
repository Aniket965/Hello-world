#!/bin/bash

(( $( id -u ) )) || {
  echo 'ERROR : for security reasons do not use Pacman-G2 Wrapper as superuser'
  exit 1
}

declare -A conf
function load()
{
  local file="$1" key value
  while IFS='= ' read -r key value; do
    [[ ! "$key" || "${key:0:1}" == '#' || "$key" =~ ^\[.+\] ]] && continue
    conf["$key"]="${conf["$key"]}${conf["$key"]:+ }$value"
    [[ "$key" == 'Include' ]] && load "$value"
  done < "$file"
}

case "$1" in
  '-Wu') # list uninstalled packages whos name or description matches the expression
    command pacman-g2 -Ss "$2" | awk '$3!="[Installed:"'
  ;;
  '-Wsn') # list packages whos name matches the expression
    command pacman-g2 -Ss "$2" | awk -vq="$2" '$2~q'
  ;;
  '-Wqn') # list installed packages whos name matches the expression
    command pacman-g2 -Qs "$2" | awk -vq="$2" '$2~q'
  ;;
  '-Wun') # list uninstalled packages whos name matches the expression
    command pacman-g2 -Ss "$2" | awk -vq="$2" '$3!="[Installed:"&&$2~q'
  ;;
  '-Wc') # list changelog-like files from the packages
    command pacman-g2 -Ql "${@:2}" | \
    while read -r pack file; do
      [[ ! -f "$file" ]] && continue
      [[ "$file" =~ (ChangeLog|CHANGELOG|CHANGES|NEWS)$ ]] || continue
      [[ "$( file -b --mime-type  "$file" )" != 'text/plain' ]] && continue
      echo "$pack $file"
    done
  ;;
  '-Wcv') # view changelog-like files with $PAGER
    list=()
    while read -r file file; do
      [[ ! -f "$file" ]] && continue
      [[ "$file" =~ (ChangeLog|CHANGELOG|CHANGES|NEWS)$ ]] || continue
      [[ "$( file -b --mime-type  "$file" )" != 'text/plain' ]] && continue
      list[${#list[@]}]="$file"
    done <<< "$( command pacman-g2 -Ql "${@:2}" )"
    "${PAGER:-less}" "${list[@]}"
  ;;
  '-Wx') # list executables from the packages
    command pacman-g2 -Ql "${@:2}" | \
    while read -r pack file; do
      [[ -f "$file" && -x "$file" ]] || continue
      echo "$pack $file"
    done
  ;;
  '-Wxp') # list executables on $PATH from the packages
    declare -A path
    for dir in ${PATH//:/ }; do path[$dir]='1'; done
    command pacman-g2 -Ql "${@:2}" | \
    while read -r pack file; do
      [[ -f "$file" && -x "$file" ]] || continue
      [[ "${path[${file%/*}]}" ]] || continue
      echo "$pack $file"
    done
  ;;
  '-Wd') # list package dependencies recursively
    function dep()
    {
      local list=( $( ( command pacman-g2 -Qi "$1" || command pacman-g2 -Si "$1" ) 2> /dev/null | awk -F '\\s*:\\s*' '$1=="Depends On"{d=1;$1="";print;next}NF>1{d=0}d{print}' ) )
      local one
      [[ "$list" == 'None' ]] && return

      for one in "${list[@]%%[>=]*}"; do
        for two in "${seen[@]}"; do [[ "$two" == "$one" ]] && break 2; done
        seen[${#seen[@]}]="$one"
        echo -n " $one"
        dep "$one"
      done
    }
    for one in "${@:2}"; do
      echo -n "$one :"
      seen=()
      dep "$one"
      echo
    done
  ;;
  '-Wdt') # tree package dependencies recursively
    declare -A cache
    function dep()
    {
      local indent="$2" seen=( "${@:3}" ) list
      local one i l
      [[ "${cache[$1]}" ]] && {
        list=( ${cache[$1]} )
      } || {
        list=( $( ( command pacman-g2 -Qi "$1" || command pacman-g2 -Si "$1" ) 2> /dev/null | awk -F '\\s*:\\s*' '$1=="Depends On"{d=1;$1="";print;next}NF>1{d=0}d{print}' ) )
        list=( "${list[@]%%[>=]*}" )
        cache["$1"]="${list[*]}"
      }
      [[ "$list" == 'None' ]] && return
      for ((i=${#list[@]}-1;i>=0;i--)); do
        for one in "${seen[@]}"; do
          [[ "${list[i]}" == "$one" ]] && unset list[i]
        done
      done
      for ((i=0,l=${#list[@]};i<l;i++)); do
        if (( i<l-1 )); then
          echo "$indent|-- ${list[i]}"
          dep "${list[i]}" "$indent|   " "${seen[@]}" "$1"
        else
          echo "$indent\`-- ${list[i]}"
          dep "${list[i]}" "$indent    " "${seen[@]}" "$1"
        fi
      done
    }
    for one in "${@:2}"; do
      echo "$one"
      dep "$one"
    done
  ;;
  '-Wox') # print the owners of executable files on $PATH
    command pacman-g2 -Qo $( which ${@:2} 2> /dev/null )
  ;;
  '-Wh') # list package operation history
    load '/etc/pacman-g2.conf'
    : "${conf['LogFile']:=/var/log/pacman-g2.log}"
    [[ -f "${conf['LogFile']}" ]] || exit
    awk -vq="$2" '($3~/^(installed|upgraded|removed)$/&&$4==q)||($NF=="skipping"&&$3~"^"q"-")' "${conf['LogFile']}"
  ;;
  '-Wn') # show some statistical number
    load '/etc/pacman-g2.conf'
    echo "Total packages     : $( pacman-g2 -Ss . | wc -l )"
    echo "Installed packages : $( pacman-g2 -Q | wc -l )"
    echo "Orphan packages    : $( pacman-g2 -Qe | wc -l )"
    echo "Hold packages      : $( set - ${conf['HoldPkg']}; echo $# )"
    echo "Ignored packages   : $( set - ${conf['IgnorePkg']}; echo $# )"
    : "${conf['CacheDir']:=/var/cache/pacman-g2}"
    echo "Cached packages    : $( ls "${conf['CacheDir']}/pkg" | wc -l )"
    echo "Cache size         : $( du -h "${conf['CacheDir']}/pkg/" | cut -f1 )"
    echo "Total groups       : $( pacman-g2 -Sg | wc -l )"
    echo "Update servers     : $( set - ${conf['Server']}; echo $# )"
    mult=( '60' '60' '24' '30' '365' )
    unit=( 'second' 'minute' 'hour' 'day' 'month' 'year' )
    date="$(< "${conf['DBPath']:-/var/lib/pacman-g2}/local.lastupdate" )"
    date="${date:0:4}-${date:4:2}-${date:6:2} ${date:8:2}:${date:10:2}:${date:12:2}"
    (( time=$( date +'%s' )-$( date -d "$date" +'%s' ) ))
    str=''
    for ((i=0,l=${#mult[@]};i<l;i++)); do
      (( part=time%mult[i] )) && str="$part ${unit[i]} $str"
      (( time/=mult[i] )) || break
    done
    echo "Last update        : ${str}ago"
    echo "Upgrade only after : ${conf['UpgradeDelay']:-0} days"
    echo "No update warning  : ${conf['OldDelay']:-0} days"
  ;;
  '-Wv') # version of the wrapper
    echo 'Pacman-G2 wrapper   version 0.4   september 2011   written by Feherke'
    echo 'adds some frequently needed minor functionalities'
  ;;
  '-W?') # help for the wrapper
    echo "usage:
  ${0##*/} -Wu  regexp     - search for uninstalled package
  ${0##*/} -Wsn regexp     - search for package name
  ${0##*/} -Wqn regexp     - search for installed package name
  ${0##*/} -Wun regexp     - search for uninstalled package name
  ${0##*/} -Wc  package(s) - list changelog-like files
  ${0##*/} -Wcv package(s) - view changelog-like files with \$PAGER
  ${0##*/} -Wx  package(s) - list executable files
  ${0##*/} -Wxp package(s) - list executable files on \$PATH
  ${0##*/} -Wd  package(s) - list recursive dependencies
  ${0##*/} -Wdt package(s) - tree recursive dependencies
  ${0##*/} -Wox command(s) - print the owner of the commands on \$PATH
  ${0##*/} -Wh  package    - package operation history
  ${0##*/} -Wn             - show some statistical number
  ${0##*/} -Wv             - print wrapper version
  ${0##*/} -W?             - print ( this ) wrapper help"
  ;;
  '-W'*) # error
     echo 'error: no action specified (use -W? for help)'
  ;;
  *)
    command pacman-g2 "$@"
  ;;
esac
