cmd_/home/ubuntu/task/moduleTask/moduleTask.mod := printf '%s\n'   moduleTask.o | awk '!x[$$0]++ { print("/home/ubuntu/task/moduleTask/"$$0) }' > /home/ubuntu/task/moduleTask/moduleTask.mod
