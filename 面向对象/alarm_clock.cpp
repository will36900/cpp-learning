#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>   // system() 用来调用系统命令播放声音
using namespace std;

// 闹钟类
class AlarmClock {
private:
    int alarmHour;      // 闹钟小时
    int alarmMinute;    // 闹钟分钟
    bool isSet;         // 闹钟是否已设置

public:
    // 构造函数
    AlarmClock() {
        alarmHour = 0;
        alarmMinute = 0;
        isSet = false;
    }

    // 设置闹钟时间
    void setAlarm(int hour, int minute) {
        if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
            alarmHour = hour;
            alarmMinute = minute;
            isSet = true;
            cout << "闹钟已设置为: " << setw(2) << setfill('0') << alarmHour
                 << ":" << setw(2) << setfill('0') << alarmMinute << endl;
        } else {
            cout << "时间格式错误！请输入正确的时间（小时0-23，分钟0-59）" << endl;
        }
    }

    // 取消闹钟
    void cancelAlarm() {
        isSet = false;
        cout << "闹钟已取消" << endl;
    }

    // 获取当前系统时间
    void getCurrentTime(int &hour, int &minute, int &second) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        second = ltm->tm_sec;
    }

    // 检查闹钟是否响铃
    bool checkAlarm() {
        if (!isSet) {
            return false;
        }

        int currentHour, currentMinute, currentSecond;
        getCurrentTime(currentHour, currentMinute, currentSecond);

        // 当前时间与闹钟时间匹配
        if (currentHour == alarmHour && currentMinute == alarmMinute) {
            return true;
        }
        return false;
    }

    // 蜂鸣器：响 seconds 秒，每秒响一声
    void beep(int seconds) {
        for (int i = 0; i < seconds; i++) {
            cout << "\a" << "嘀！" << flush;   // \a 是终端响铃字符（部分终端可能静音）

            // 调用 macOS 自带的 afplay 播放系统提示音
            // 末尾的 & 表示后台播放，不会卡住程序
            system("afplay /System/Library/Sounds/Ping.aiff &");

            this_thread::sleep_for(chrono::seconds(1));  // 等 1 秒再响下一声
        }
        cout << endl;
    }

    // 响铃
    void ring() {
        cout << "\n🔔🔔🔔 闹钟响了！时间到了！🔔🔔🔔\n" << endl;
        cout << "当前时间: " << setw(2) << setfill('0') << alarmHour
             << ":" << setw(2) << setfill('0') << alarmMinute << endl;
        beep(3);        // 蜂鸣器响 3 秒
        isSet = false;  // 响铃后自动取消闹钟
    }

    // 显示当前时间（持续显示）
    void displayTime() {
        int hour, minute, second;
        getCurrentTime(hour, minute, second);
        cout << "\r当前时间: " << setw(2) << setfill('0') << hour
             << ":" << setw(2) << setfill('0') << minute
             << ":" << setw(2) << setfill('0') << second << flush;
    }

    // 查看闹钟状态
    void showStatus() {
        if (isSet) {
            cout << "闹钟已设置为: " << setw(2) << setfill('0') << alarmHour
                 << ":" << setw(2) << setfill('0') << alarmMinute << endl;
        } else {
            cout << "当前没有设置闹钟" << endl;
        }
    }

    // 倒计时：等待 seconds 秒后响铃
    void countdown(int seconds) {
        if (seconds <= 0) {
            cout << "秒数必须大于 0" << endl;
            return;
        }

        // 从 seconds 往下数到 1，每秒刷新一次显示
        for (int left = seconds; left > 0; left--) {
            cout << "\r剩余时间: " << setw(3) << setfill(' ') << left << " 秒" << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }

        cout << "\n\n⏰⏰⏰ 倒计时结束！时间到了！⏰⏰⏰\n" << endl;
        beep(3);  // 蜂鸣器响 3 秒
    }
};

int main() {
    AlarmClock clock;
    int choice;
    int hour, minute;

    cout << "=== 简易闹钟程序 ===" << endl;

    while (true) {
        cout << "\n请选择操作：" << endl;
        cout << "1. 设置闹钟" << endl;
        cout << "2. 查看闹钟状态" << endl;
        cout << "3. 取消闹钟" << endl;
        cout << "4. 开始计时（按Ctrl+C退出）" << endl;
        cout << "5. 退出程序" << endl;
        cout << "请输入选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "请输入闹钟时间（小时 分钟，如 7 30）: ";
                cin >> hour >> minute;
                clock.setAlarm(hour, minute);
                break;

            case 2:
                clock.showStatus();
                break;

            case 3:
                clock.cancelAlarm();
                break;

            case 4:
                cout << "开始计时，等待闹钟响铃...\n" << endl;
                cout << "（提示：可以按Ctrl+C停止）\n" << endl;

                // 持续检查时间和闹钟
                while (true) {
                    clock.displayTime();

                    if (clock.checkAlarm()) {
                        clock.ring();
                        break;  // 响铃后退出循环
                    }

                    // 每秒检查一次
                    this_thread::sleep_for(chrono::seconds(1));
                }
                break;

            case 5:
                cout << "程序已退出" << endl;
                return 0;

            default:
                cout << "无效的选择，请重新输入" << endl;
        }
    }

    return 0;
}
