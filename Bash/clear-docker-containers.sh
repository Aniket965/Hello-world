docker ps -a --format={{.ID}} | tr '\n' ' ' | xargs docker rm
