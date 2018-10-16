echo -e "\e[44m ########## Check Running CRONS ########## \e[0m"
	IFS=$'\n'

    old_process=$(ps -eo command)

	while true; do

  		new_process=$(ps -eo command)
  		diff <(echo "$old_process") <(echo "$new_process")
  		sleep 1
  		old_process=$new_process
done
