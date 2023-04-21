LOG_FILE="/root/Logs/discBots.log"
NODE_PATH="/root/workers/discord_bots/node-v12.10.0/bin/node"
DISC_BOT_FOLDER="/root/workers/discord_bots"

echo "Starting faustobot.."
$NODE_PATH $DISC_BOT_FOLDER/fausto_bot/index.js >> $LOG_FILE 2>&1 &
echo "Faustobot Started.."
