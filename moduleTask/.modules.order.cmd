cmd_/home/ubuntu/task/moduleTask/modules.order := {   echo /home/ubuntu/task/moduleTask/moduleTask.ko; :; } | awk '!x[$$0]++' - > /home/ubuntu/task/moduleTask/modules.order
