#ifndef __TELEGRAM_RECEIVER__
#define __TELEGRAM_RECEIVER__

#include <Arduino.h>
#include <functional>

class TelegramReceiver
{
public:
  virtual ~TelegramReceiver(){};
  virtual void onTelegramMessageReceived(const String &chat_id, const String &message, const String &from) = 0;
};

typedef void (TelegramReceiver::*TelegramMsgCallback)(const String &chat_id, const String &message, const String &from);

#endif // __TELEGRAM_RECEIVER__
