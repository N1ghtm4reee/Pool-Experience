ifconfig | grep -F ether  |  grep -E '[0-9a-fA-F][0-9a-fA-F]:' | awk '{print $2}'
