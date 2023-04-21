PROCESS=$(ps -aux | grep "fausto_bot" | awk -F " " '{print $11}' | head -n -1)

# number of processes
NUM_PROCESSES=$(echo "$PROCESS" | wc -l)

# if number of processes is less than NUM_PROCESSES, then restart
if [ $NUM_PROCESSES -lt 1 ]; then
    /root/workers/discord_bots/fausto_clt.sh
fi

PROCESS=$(ps -aux | grep "faro_clt" | awk -F " " '{print $11}' | head -n -1)

# number of processes
NUM_PROCESSES=$(echo "$PROCESS" | wc -l)

# if number of processes is less than NUM_PROCESSES, then restart
if [ $NUM_PROCESSES -lt 1 ]; then
    /root/workers/discord_bots/faro_clt.sh
fi