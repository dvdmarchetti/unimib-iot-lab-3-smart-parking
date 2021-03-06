#include "../include/telegram_manager.h"

TelegramManager::TelegramManager() : _bot(BOT_TOKEN, _secured_client)
{
  //
}

TelegramManager& TelegramManager::setup()
{
  _secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  configTime(0, 0, "pool.ntp.org");                     // get UTC time via NTP
  time_t now = time(nullptr);

  while (now < 24 * 3600) {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.print("\n[TELEGRAM MANAGER] ");
  Serial.println(now);

  return *this;
}

TelegramManager& TelegramManager::onMessageReceived(TelegramReceiver *object, TelegramMsgCallback callback)
{
  _callback = std::bind(callback, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
  return *this;
}

TelegramManager& TelegramManager::listen()
{
  if (millis() - _bot_lasttime < BOT_MTBS)
    return *this;

  int numNewMessages = _bot.getUpdates(_bot.last_message_received + 1);

  while (numNewMessages) {
    handle_messages(numNewMessages);
    numNewMessages = _bot.getUpdates(_bot.last_message_received + 1);
  }

  _bot_lasttime = millis();
  return *this;
}

TelegramManager &TelegramManager::sendMessage(const String &chat_id, const String &message, const String &parseMode)
{
  bool isMessageSent = _bot.sendMessage(chat_id, message, parseMode);

  if (isMessageSent) Serial.println(F("[TELEGRAM MANAGER] Message successfully sent"));
  else Serial.println(F("[TELEGRAM MANAGER] Error during message sending"));

  return *this;
}

TelegramManager& TelegramManager::sendMessageWithReplyKeyboard(const String &chat_id, const String &message, const String &parseMode, bool resize, bool oneTime, bool selective)
{
    bool isMessageSent = _bot.sendMessageWithReplyKeyboard(
        chat_id,
        message,
        parseMode,
        build_reply_keyboard(),
        resize,
        oneTime,
        selective
    );

    if (isMessageSent) Serial.println(F("[TELEGRAM MANAGER] Message successfully sent"));
    else Serial.println(F("[TELEGRAM MANAGER] Error during message sending"));

    return *this;
}

TelegramManager& TelegramManager::sendNotification(std::set<String> ids, const String &message, const String &parseMode)
{
    for (auto id : ids) {
        sendMessageWithReplyKeyboard(id, message, parseMode);
    }

    return *this;
}

void TelegramManager::handle_messages(int numMessages)
{
  for (int i = 0; i < numMessages; i++) {
    _callback(_bot.messages[i].chat_id, _bot.messages[i].text, _bot.messages[i].from_name);
  }
}

String TelegramManager::build_reply_keyboard()
{
    String keyboard = "[";
    keyboard += "[\"" + String(ALARM_ON_COMMAND) +"\", \"" + String(ALARM_OFF_COMMAND) + "\"],";
    keyboard += "[\"" + String(NOTIFICATIONS_ON_COMMAND) + "\", \"" + String(NOTIFICATIONS_OFF_COMMAND) + "\"],";
    keyboard += "[\"" + String(AVAILABILITY_COMMAND) + "\", \"" + String(PARKING_INFO_COMMAND) + "\"],";
    keyboard += "[\"" + String(HELP_COMMAND) + "\"]";
    keyboard += "]";
    return keyboard;
}
