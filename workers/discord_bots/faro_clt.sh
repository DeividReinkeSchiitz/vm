LOG_FILE="/root/Logs/discBots.log"
NODE_PATH="/root/workers/discord_bots/node-v12.10.0/bin/node"
DISC_BOT_FOLDER="/root/workers/discord_bots"

echo "Starting farosounds.."
$NODE_PATH $DISC_BOT_FOLDER/faro_sounds/index.js >> $LOG_FILE 2>&1 &
echo "Farosounds Started.."