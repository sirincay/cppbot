#include <stdio.h>
#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("1899124713:AAEjk2FGPSXxwuJDBdSBy_Mb3Y0KDD5YTc0");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Salam test edirem!");
    });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf(" %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "necesen " + message->text);
    });
    try {
        printf("Bot ad: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("uzun\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what()); //xetalar ucun
    }
    return 0;
}
