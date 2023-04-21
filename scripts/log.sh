#!/bin/bash

RCol='\e[0m'    # Text Reset

# Regular           Bold                Underline           High Intensity      BoldHigh Intens     Background          High Intensity Backgrounds

Bla='\e[0;30m';     BBla='\e[1;30m';    UBla='\e[4;30m';    IBla='\e[0;90m';    BIBla='\e[1;90m';   On_Bla='\e[40m';    On_IBla='\e[0;100m';
Red='\e[0;31m';     BRed='\e[1;31m';    URed='\e[4;31m';    IRed='\e[0;91m';    BIRed='\e[1;91m';   On_Red='\e[41m';    On_IRed='\e[0;101m';
Gre='\e[0;32m';     BGre='\e[1;32m';    UGre='\e[4;32m';    IGre='\e[0;92m';    BIGre='\e[1;92m';   On_Gre='\e[42m';    On_IGre='\e[0;102m';
Yel='\e[0;33m';     BYel='\e[1;33m';    UYel='\e[4;33m';    IYel='\e[0;93m';    BIYel='\e[1;93m';   On_Yel='\e[43m';    On_IYel='\e[0;103m';
Blu='\e[0;34m';     BBlu='\e[1;34m';    UBlu='\e[4;34m';    IBlu='\e[0;94m';    BIBlu='\e[1;94m';   On_Blu='\e[44m';    On_IBlu='\e[0;104m';
Pur='\e[0;35m';     BPur='\e[1;35m';    UPur='\e[4;35m';    IPur='\e[0;95m';    BIPur='\e[1;95m';   On_Pur='\e[45m';    On_IPur='\e[0;105m';
Cya='\e[0;36m';     BCya='\e[1;36m';    UCya='\e[4;36m';    ICya='\e[0;96m';    BICya='\e[1;96m';   On_Cya='\e[46m';    On_ICya='\e[0;106m';
Whi='\e[0;37m';     BWhi='\e[1;37m';    UWhi='\e[4;37m';    IWhi='\e[0;97m';    BIWhi='\e[1;97m';   On_Whi='\e[47m';    On_IWhi='\e[0;107m';

DEBUG=0
INFO=0
WARN=0
ERROR=0

POSITIONAL_ARGS=()
handleArguments () {
  # if no arguments are passed, print usage
  if [ $# -eq 0 ]; then
    echo -e "${BRed}No arguments passed. Please pass arguments.${RCol}"
    exit 1
  fi

  if [ $# -eq 1 ]; then
    DEBUG=1
    INFO=1
    WARN=1
    ERROR=1
  fi

  while [[ $# -gt 0 ]]; do
    case $1 in
    -h | --help)
      exit 1
      ;;

    -d | --debug)
      DEBUG=1
      shift # past argument
      ;;

    -i | --info)
      INFO=1
      shift # past argument
      ;;

    -w | --warn)
      WARN=1
      shift # past argument
      ;;

    -e | --error)
      ERROR=1
      shift # past argument
      ;;

    -*)
      echo -e "${BRed}+ ERROR:${RCol} Unknown option: ${BRed}$1:         ${RCol}"
      echo -e "${Red}+-----------------------------------------------+   ${RCol}"
      exit 1
      ;;
    *)
      # last argument
      POSITIONAL_ARGS+=("$1") # save positional arguments
      shift                   # past argument
      ;;
    esac
  done
}

handleArguments "$@"

tail -f $POSITIONAL_ARGS | awk -v debug=$DEBUG -v info=$INFO -v warn=$WARN -v error=$ERROR '
  {
    if(index($1, "[DEBUG]") !=0 && debug == 1) {
      printf "\033[1;34m" $1 "\033[0m" " "
      printf "\033[1;36m" $2 " " $3 " \033[4;33m" $4 "\033[1;0m "; for (i=5; i<=NF; i++) printf $i " "; print "";
    }
    if(index($1, "[INFO]") !=0 && info == 1) {
      printf "\033[1;38m" $1 "\033[0m" "  "
      printf "\033[1;36m" $2 " " $3 " \033[4;33m" $4 "\033[1;0m "; for (i=5; i<=NF; i++) printf $i " "; print "";
    }
    if(index($1, "[WARN]") !=0 && warn == 1) {
      printf "\033[1;33m" $1 "\033[0m" "  "
      printf "\033[1;36m" $2 " " $3 " \033[4;33m" $4 "\033[1;0m "; for (i=5; i<=NF; i++) printf $i " "; print "";
    }
    if(index($1, "[ERROR]") !=0 && error == 1) {
      printf "\033[1;31m" $1 "\033[0m" " "
      printf "\033[1;36m" $2 " " $3 " \033[4;33m" $4 "\033[1;0m "; for (i=5; i<=NF; i++) printf $i " "; print "";
    }
    printf "\033[0m"
  }
'