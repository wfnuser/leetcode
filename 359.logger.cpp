class Logger {
public:
    int lastTimeStamp = 0;
    unordered_map<string, int> m;

    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (m[message] == 0 || m.size() == 0) {
            if(timestamp == 0) timestamp--;
            m[message] = timestamp;
            return true;
        }
        int lastTimeStamp = m[message];
        if (lastTimeStamp == -1) lastTimeStamp = 0;
        if (timestamp-lastTimeStamp >= 10) {
            if (timestamp == 0) timestamp = -1;
            m[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */